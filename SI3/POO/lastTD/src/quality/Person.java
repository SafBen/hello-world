package quality;

/**
 * Models a person. Persons are ordered by their quality characteristic.
 * @author Peter Sander
 * @author Safwane Benidir
 */

public class Person implements Comparable<Person> {
    public enum Quality {
        DOUCHE,HOSER,POSEUR,WANNABE,REAL_DEAL,BADASS
        }

    private Quality quality;

    public Person(Quality quality) {
        this.quality = quality;
    }

    /**
     * Orders persons by their quality.
     * @return n < 0 if this < other; n = 0 if this = other; n > 0 if this > other
     */
    @Override
    public int compareTo(Person other) {
        return other.quality.compareTo(this.quality);

    }

    @Override
    public boolean equals(Object obj){
        Person p = (Person) obj;
        return this.quality.compareTo(p.quality) < 0;
    }
}