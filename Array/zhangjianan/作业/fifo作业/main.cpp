#include <iostream>
#include "FIFO.cpp"
int main() {
  FIFO<int> queue= FIFO<int>(3);
    queue.enqueue_key(1);
    queue.enqueue_key(2);
    queue.enqueue_key(3);
    queue.enqueue_key(4);
    queue.enqueue_key(5);
    queue.reset_key(4);
    queue.print_fifo();
    return 0;
}
