package comparator;

import java.util.Comparator;

/**
 * Represents a person. Persons may be compared based either
 * on their name or their age.
 * @author Peter Sander
 */
class Person {
    final int age;  // package access for testing
    final String name;  // package access for testing
    static final Comparator<Person> AGE_COMPARATOR
            = new Comparator<Person>() {
        @Override
        public int compare(Person person, Person t1) {
            if (person.age==t1.age) return 0;
            else return person.age<t1.age ? -1:1;

        }
    };
    static final Comparator<Person> NAME_COMPARATOR
            = new Comparator<Person>() {
        @Override
        public int compare(Person person, Person t1) {
            return person.name.compareTo(t1.name);
        }
    };

    Person(String name, int age) {
        this.name = name;
        this.age = age;
    }

    /**
     * Compares this to another Person object using a
     * comparator object.
     * @param other Other person.
     * @param comparator Comparator object.
     * @return -i if this < other as determined by the comparator;
     * 0 if equal; +i if this > other.
     * @throws IllegalArgumentException If the comparator is not
     * one of those declared for Person.
     */
    int compareTo(Person other, Comparator<Person> comparator) {
        // want == and not .equals which could be overridden
        if (comparator == AGE_COMPARATOR
                || comparator == NAME_COMPARATOR) {
            return comparator.compare(this, other);
        }
        throw new IllegalArgumentException("Comparison isn't allowed");
    }
}