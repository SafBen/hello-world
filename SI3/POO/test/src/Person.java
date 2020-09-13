abstract class Person{
    final String name;
    Person(String name){
        this.name=name;
    }
    @Override
    public String toString(){
        return "Name: "+name;
    }
}