/**
 * File not to be modified
 */
//@author: j.n.magee 11/11/96

//************************************************************
// the interface for ReadWrite monitor implementations

interface ReadWrite {

   public void acquireRead() throws InterruptedException;

   public void releaseRead();

   public void acquireWrite() throws InterruptedException;

   public void releaseWrite();
 }


