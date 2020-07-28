//
// Created by Jesson on 2020/7/25.
//

#include <iostream>
#include<algorithm>    //经查阅，使用库中 max_element(first,last)函数，函数返回值为数组最大元素的地址
using namespace std;
enum State {ready,block,done };
//模拟进程结构体的定义
struct Process {
    int ID; //进程ID
    int priority;//优先级 优先数越大的进程，其优先权越高。
    int cputime; //CPU时间 进程已占用的CPU时间CPUTIME。
    int alltime; //进程还需占用的CPU时间ALLTIME。当进程运行完毕时，ALLTIME变为0。
    int startblock; //进程的阻塞时间STARTBLOCK，表示当进程再运行STARTBLOCK个时间片后，将进入阻塞状态。
    int blocktime; //进程在就绪队列中呆一个时间片，优先数加1。 进程每运行一个时间片，优先数减3。
    State state;//进程状态

};

Process process[5];       //5个进程

int main() {

    void print();
    process[0].ID=0;
    process[0].priority=9;
    process[0].cputime=0;
    process[0].alltime=3;
    process[0].startblock=2;
    process[0].blocktime=3;
    process[0].state=ready;

    process[1].ID=1;
    process[1].priority=38;
    process[1].cputime=0;
    process[1].alltime=3;
    process[1].startblock=-1;
    process[1].blocktime=0;
    process[1].state=ready;

    process[2].ID=2;
    process[2].priority=30;
    process[2].cputime=0;
    process[2].alltime=6;
    process[2].startblock=-1;
    process[2].blocktime=0;
    process[2].state=ready;

    process[3].ID=3;
    process[3].priority=29;
    process[3].cputime=0;
    process[3].alltime=3;
    process[3].startblock=-1;
    process[3].blocktime=0;
    process[3].state=ready;

    process[4].ID=4;
    process[4].priority=0;
    process[4].cputime=0;
    process[4].alltime=4;
    process[4].startblock-1;
    process[4].blocktime=0;
    process[4].state=ready;


    int timeslice=0;                    //时间片
    int temp[5];                       // 阻塞进程优先级  缓存数组
    while(process[0].alltime||process[1].alltime||process[2].alltime||process[3].alltime||process[4].alltime) { //存在进程没有执行完成

        for(int i=0; i<5; i++) {
            int array[]= {process[0].priority,process[1].priority,process[2].priority,process[3].priority,process[4].priority};  //所有进程优先级 存储数组
            if((process[i].state==ready) && (process[i].priority==*max_element(array,array+5))) {               //进程i开始执行

                timeslice++;
                process[i].priority-=3;
                process[i].cputime+=1;
                process[i].alltime-=1;

                for(int j=0; j<5; j++) {                         //其余就绪进程优先级 加1

                    if(j==i) continue;                    //跳过当前进程的优先级+1操作
                    if(process[j].alltime>0&&process[j].state==ready) {
                        process[j].priority+=1;
                    }
                }

                if(process[i].alltime==0) {
                    process[i].state=done;
                    process[i].priority=-1;
                }


                for(int j=0; j<5; j++) {                                         //其他阻塞进程  blocktime  -1

                    if(process[j].state==block&&process[j].blocktime>0) {

                        process[j].blocktime-=1;
                        if(process[j].blocktime==0) {

                            process[j].state=ready;
                            process[j].priority=temp[j];    //阻塞进程恢复阻塞前的优先级
                        }
                    }
                }

                if(process[i].startblock>0) {

                    process[i].startblock-=1;
                    if(process[i].startblock==0) {

                        process[i].state=block;
                        temp[i]=process[i].priority;        //进程i阻塞后   将优先级保存到 temp[i]
                        process[i].priority=-1;
                    }
                }

                cout<<"时间片为:"<<timeslice<<endl;
                cout<<"执行进程:"<<process[i].ID<<endl;
                print();

            }


        }

    }



    return 0;
}
void print() {

    cout << "就绪队列:";
    for (int j = 0; j < 5; j++) {
        if (process[j].state == ready) {
            cout << "->" << process[j].ID;
        }
    }
    cout << endl;
    cout << "阻塞队列:";
    for (int j = 0; j < 5; j++) {
        if (process[j].state == block) {
            cout << "->" << process[j].ID;
        }
    }
    cout << endl;
    cout << "ID\tpriority\tcputime\talltime\tstartblock\tblocktime\tstate" << endl;
    for (int j = 0; j < 5; j++) {
        cout << process[j].ID << '\t' << process[j].priority << '\t' << '\t' << process[j].cputime << '\t'
             << process[j].alltime << '\t' << process[j].startblock << '\t' << '\t' << process[j].blocktime << '\t'
             << '\t' << process[j].state << endl;
    }
    cout << "******************************************************************************" << endl;
}