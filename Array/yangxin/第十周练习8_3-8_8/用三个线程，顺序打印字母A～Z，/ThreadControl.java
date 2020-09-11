package study.test.three_thread;

import java.util.concurrent.atomic.AtomicInteger;
import java.util.concurrent.locks.Condition;
import java.util.concurrent.locks.ReentrantLock;

public class ThreadControl {
    private ThreadPrintLetter printLetter1, printLetter2, printLetter3;
    private Condition condition;
    private AtomicInteger letter;
    private ReentrantLock lock;

    public ThreadControl() {
        lock = new ReentrantLock();
        letter = new AtomicInteger(0);
        condition = lock.newCondition();
        printLetter1 = new ThreadPrintLetter(lock, letter, condition, "1");
        printLetter2 = new ThreadPrintLetter(lock, letter, condition, "2");
        printLetter3 = new ThreadPrintLetter(lock, letter, condition, "3");

    }

    public void printLetter() {
        try {
            printLetter1.start();
            Thread.sleep(500);
            printLetter2.start();
            Thread.sleep(500);
            printLetter3.start();
            Thread.sleep(500);
            lock.lock();
            condition.signal();
            lock.unlock();
        } catch (Exception e) {
            e.printStackTrace();
            printLetter1.interrupt();
            printLetter2.interrupt();
            printLetter3.interrupt();
        }
    }
}
