
/**
 * File to be modified
 */

class ReadWritePriority implements ReadWrite {

   synchronized public void acquireRead() throws InterruptedException {
   }

   synchronized public void releaseRead(){}

   synchronized public void acquireWrite() throws InterruptedException {}

   synchronized public void releaseWrite(){}
 }


