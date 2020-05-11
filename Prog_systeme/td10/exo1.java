/*
 * Exercice 1
 */

import java.lang.ProcessHandle;

public class exo1 {

    public static void main(String args[]) {
        ProcessHandle p = ProcessHandle.current();
        System.out.println(p.pid());
    }
}