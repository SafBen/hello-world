package grolandadmin;

import java.util.Arrays;
import java.util.Map;
import java.util.Set;

/**
 * Stores marks for students.
 * @author Peter Sander
 * @author Safwane Benidir
 */
@SuppressWarnings("serial")  // don't ask
class Marks {
    private final Map<String, int[]> marks;

    /**
     * Dependency injection in constructor.
     * @param marks Student marks.
     */
    Marks(Map<String, int[]> marks) {
        this.marks = marks;
    }

    /**
     * @param student A student.
     * @return The student's marks.
     */
    int[] getMarks(String student) {
        int[] tab = marks.get(student);
        int[] m = new int[tab.length];
        for (int i=0;i<m.length;i++)
            m[i] = tab[i];
        return tab;
    }

    /**
     * @return The set of all student names.
     */
    Set<String> getStudents() {
        return marks.keySet();
    }
}