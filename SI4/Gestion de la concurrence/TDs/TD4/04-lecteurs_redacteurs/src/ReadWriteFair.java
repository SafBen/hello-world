/**
 * File to be modified
 */

//************************************************************
// the interface for ReadWrite monitor implementations

class ReadWriteFair implements ReadWrite {

   synchronized public void acquireRead() throws InterruptedException {}

   synchronized public void releaseRead(){}

   synchronized public void acquireWrite() throws InterruptedException {}

   synchronized public void releaseWrite(){}
 }


