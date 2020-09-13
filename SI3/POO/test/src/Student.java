class Student extends Person{
    int id;
    Student(String name,int id){
        super(name);
        this.id=id;
    }
    @Override
    public String toString(){
        return "Name: "+this.name+"\nID: "+id;
    }
}