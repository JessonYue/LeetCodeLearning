package study.test.three_thread;

import java.util.concurrent.atomic.AtomicInteger;
import java.util.concurrent.locks.Condition;
import java.util.concurrent.locks.ReentrantLock;

public class ThreadPrintLetter extends Thread {
    char letter = 'A';
    private AtomicInteger mOffset;
    private Condition mCondition, mSignalCondition;
    private ReentrantLock mLock;

    public ThreadPrintLetter(ReentrantLock lock, AtomicInteger offset, Condition signCondition, String name) {
        super(name);
        mOffset = offset;
        mCondition = signCondition;
        mSignalCondition = signCondition;
        mLock = lock;
    }

    @Override
    public void run() {
        super.run();
        try {
            mLock.lock();
            while (!isInterrupted() && mOffset.get() < 26) {
                mCondition.await();
                if (mOffset.get() < 26) {
                    System.out.println(getName() + (char) ((int) letter + mOffset.getAndIncrement()));
                    mCondition.signal();
                } else {
                    mCondition.signal();
                    return;
                }
            }
        } catch (InterruptedException e) {
            e.printStackTrace();
        } finally {
            mLock.unlock();
        }
    }
}
