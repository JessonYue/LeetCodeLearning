#include <iostream>
#include <queue>
#include <cstdint>
#include <assert.h>

using namespace std;

typedef unsigned int uSize;

template<class T>
class FIFO {
private:
    queue<T> data;
    uSize size;

public:
    FIFO() {
        this->size = UINT32_MAX;
    }

    FIFO(uSize size) {
        this->size = size;
    }

    bool isFull() {
        return (data.size() >= this->size);
    }

    bool isEmpty() {
        return data.empty();
    }

    void freeFifo() {
        while (!data.empty()) {
            data.pop();
        }
    }

    T read(bool pop = true) {
        assert(!data.empty());
        T d = data.front();
        if (pop) {
            data.pop();
        }
        return d;
    }

    void write(T d) {
        assert(data.size() < size);
        data.push(d);
    }

    void printFifo(){
        while(!data.empty()){
            printf("fifo front is %d\n",data.front());
            data.pop();
        }
    }

    virtual ~FIFO() {
        if (!data.empty()) {
            freeFifo();
        }
    }
};


int main() {
    FIFO<int> ff = *new FIFO<int>(3);
    ff.write(1);
    ff.write(-1);
    ff.write(2);
    printf("%d\n", ff.read(false));
    printf("----content------\n");
    ff.printFifo();
    return 0;
}