//
// Created by 12 on 2020/7/11.信号量 生产消费同步练习
//

#include <malloc.h>
#include <semaphore.h>

typedef struct {
    //缓冲数组
    int *buff;
    //数组大小
    int n;
    // 数组中的第一项
    int front;
    // 数组中的最后一项
    int rear;
    //信号量提供互斥的缓冲区访问
    sem_t mutex;
    //记录空槽位
    sem_t slots;
    //可用项目
    sem_t items;
} sbuf_t;

void sbuf_init(sbuf_t *sp, int n) {
    sp->buff = calloc(n, sizeof(int));
    sp->n = n;
    sp->front = sp->rear = 0;
    sem_init(sp->mutex, 0, 1);
    sem_init(sp->slots, 0, n);
    sem_init(sp->items, 0, 0);
}

void sbuf_deinit(sbuf_t *sp) {
    free(sp);
}

void sbuf_insert(sbuf_t *sp, int item) {
    //从空槽中p操作一个
    sem_wait(sp->slots);
    sem_wait(sp->mutex);
    sp->buff[(++sp->rear) % (sp->n)] = item;
    sem_post(sp->mutex);
    //当插入一个数据后通知可用项v操作
    sem_post(sp->items);
}

int sbuf_remove(sbuf_t *sp) {
    int item;
    //从可用项p操作一个
    sem_wait(sp->items);
    sem_wait(sp->mutex);
    item = sp->buff[(++sp->front) % (sp->n)];
    sem_post(sp->mutex);
    //当释放一个的时候通知空槽v操作
    sem_post(sp->slots);
    return item;
}