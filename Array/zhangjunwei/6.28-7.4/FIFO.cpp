//
// Created by 张俊伟 on 2020/7/1.
//

#include <iostream>
#include <deque>
template<typename T>
class FIFO {
public:
    FIFO(int capcity) : capcity(capcity) {
        fifo = std::deque<T>();
    }

private:
    int capcity;
    std::deque<T> fifo;

    bool is_full() {
        return fifo.size() == capcity;
    }

    bool is_empty() {
        return fifo.size() == 0;
    }

public:
    void enqueue_key(T key) {
        if (is_full()) {
            fifo.pop_front();
        }
        fifo.push_back(key);
    }
    //队列中的数据 使用过之后 就对使用的数据 重新入队
    void reset_key(T key) {
        delete_key(key);
        fifo.push_back(key);
    }

    void delete_key(T key) {
//        std::remove_if()
        auto it = fifo.begin();
        while (it != fifo.end()) {
            if (*it == key) {
                fifo.erase(it);
                return;
            }
            it++;
        }
    }

    void clear() {
        while (!fifo.empty())
            fifo.pop();
    }
    void print_fifo(){
        while (!fifo.empty()){
            std::cout << fifo.front() <<std::endl;
            fifo.pop_front();
        }
    }

    virtual ~FIFO() {
        if (!fifo.empty())
            fifo.clear();
    }


};

int main(){
    FIFO<int> queue = FIFO<int>(3);
    queue.enqueue_key(1);
    queue.enqueue_key(2);
    queue.enqueue_key(3);
    queue.enqueue_key(4);
    queue.enqueue_key(5);
    queue.reset_key(4);
    queue.print_fifo();
    return 0;
}