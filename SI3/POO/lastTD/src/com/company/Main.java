package com.company;

import quality.Person;

public class Main {

    public static void main(String[] args) {
	// write your code here
        Person person = new Person(Person.Quality.WANNABE);
        System.out.println(person.equals(new Person(Person.Quality.WANNABE)));
    }
}
