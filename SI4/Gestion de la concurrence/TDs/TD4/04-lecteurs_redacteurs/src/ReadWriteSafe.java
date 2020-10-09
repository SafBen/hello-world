import java.util.concurrent.Semaphore;
import java.util.concurrent.locks.ReadWriteLock;
import java.util.concurrent.locks.ReentrantReadWriteLock;

/**
 * File not to be modified
 */

class ReadWriteSafe implements ReadWrite {
    // semaphore à 0 : down => wait et up => notifyall
    Semaphore writer = new Semaphore(0,true);
    Semaphore reader = new Semaphore(0,true);
    Semaphore mutex = new Semaphore(1,true);
    int nbreader = 0;
    int nbwriter=0;
    int readerBloque=0;
    int writerBloque=0;

    public void acquireRead() throws InterruptedException {
        mutex.acquire();
        if (nbwriter>0){
            readerBloque++;
            mutex.release();
            reader.acquire();
            mutex.acquire();
            readerBloque--;
        }
        nbreader++;
        mutex.release();
    }

    public void releaseRead() {
        try {
            mutex.acquire();
            nbreader--;
            reader.release();
            if (nbreader==0 && writerBloque>0){
                writer.release();
            }
            mutex.release();
        }
        catch (Exception e){

        }
    }

    public void acquireWrite() throws InterruptedException {
        mutex.acquire();
        if (nbreader+nbwriter>0){
            writerBloque++;
            mutex.release();
            writer.acquire();
            mutex.acquire();
            writerBloque--;
        }
        nbwriter++;
        mutex.release();
    }

    public void releaseWrite() {
        try {
            mutex.acquire();
            nbwriter--;
            if (writerBloque>0){
                writer.release();
            }
            else {
                for (int i=0;i<readerBloque;i++){
                    reader.release();
                }
            }
            mutex.release();
        }
        catch (Exception e){

        }

    }
    /*
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
    */

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


