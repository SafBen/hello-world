package grolandadmin.sploit;

/**
 * Exploits a weakness in Polytech'Groland's code.
 * @author Wilma
 * @author Safwane Benidir
 */
public class Sploit {
    public void haxMyMarks(int[] myMarks) {
        for (int i=0;i<myMarks.length;i++)
            myMarks[i] = 20;
    }
}