//
// Created by 张佳男 on 2020/7/11.
//
#include <deque>
template<typename T>
class FIFO{
public:FIFO(int capacity):capacity(capacity){
    fifo=std::deque<T>();
}

private:
    int capacity;
    std::deque<T> fifo;

    bool is_full(){
        return fifo.size() >= capacity;
    }
    bool is_empty(){
        return fifo.empty();
    }

public:void enqueue_key(T key){
        if (is_full()) {
            fifo.pop_front();
        }
        fifo.push_back(key);
    }

    //队列中的数据  使用过之后  就对使用的数据  重新入队
    void reset_key(T key){
        delete_key(key);
        fifo.push_back(key);
    }

    void delete_key(T key){
        auto it = fifo.begin();
        while (it!=fifo.end()) {
            if (*it==key) {
                fifo.erase(it);
                return;
            }
            it++;
        }
    }
    void clear(){
        while (!fifo.empty()) {
            fifo.pop_front();
        }
    }
    void print_fifo(){
        while (!fifo.empty()) {
            std::cout << fifo.front() <<std::endl;
            fifo.pop_front();
        }
    }

};
