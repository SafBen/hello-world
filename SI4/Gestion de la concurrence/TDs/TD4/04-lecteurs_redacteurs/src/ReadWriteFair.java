/**
 * File to be modified
 */

//************************************************************
// the interface for ReadWrite monitor implementations

class ReadWriteFair implements ReadWrite {
    int waitingReaders=0;
    int writers=0;
    int waitingWriters=0;
    int readers=0;
    boolean readersTurn=false;

    synchronized public void acquireRead() throws InterruptedException {
        waitingReaders += 1;
        while (!(writers==0 && (waitingWriters==0 || readersTurn))) wait();
        waitingReaders -= 1;
        readers += 1;
    }    synchronized public void releaseRead(){
        readers -= 1;
        readersTurn = false;
        if (readers==0)
            notifyAll();
    }    synchronized public void acquireWrite() throws InterruptedException {
        waitingWriters += 1;
        while (!(readers+writers==0 && (waitingReaders==0 || !readersTurn))) wait();
        waitingWriters -= 1;
        writers += 1;
    }    synchronized public void releaseWrite(){
        writers -= 1;
        readersTurn = true;
        notifyAll();
    }
 }


