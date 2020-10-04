import java.util.concurrent.locks.ReadWriteLock;
import java.util.concurrent.locks.ReentrantReadWriteLock;

/**
 * File not to be modified
 */

class ReadWriteSafe implements ReadWrite {
    int reader=0;
    boolean writer = false;

    synchronized public void acquireRead() throws InterruptedException {
        while (writer) wait();
        ++reader;
        notifyAll();
    }

    synchronized public void releaseRead() {
        --reader;
        if (reader==0) notifyAll();
    }

    synchronized public void acquireWrite() throws InterruptedException {
        while (writer || reader>0) wait();
        writer=true;
        notifyAll();
    }

    synchronized public void releaseWrite() {
        writer=false;
        notifyAll();
    }

    /*
    ReadWriteLock readWriteLock = new ReentrantReadWriteLock();

    public void acquireRead() throws InterruptedException {
       readWriteLock.readLock().lock();
   }

   public void releaseRead() {
       readWriteLock.readLock().unlock();
   }

   public void acquireWrite() throws InterruptedException {
       readWriteLock.writeLock().lock();
   }

   public void releaseWrite() {
       readWriteLock.writeLock().unlock();
   }
     */
 }


