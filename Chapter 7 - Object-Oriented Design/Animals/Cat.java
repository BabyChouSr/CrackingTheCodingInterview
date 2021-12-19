package Animals;
public class Cat extends Animal {
    private int age;
    private int name;
    Cat() {
        super();
    }
    Cat(int age, String name) {
        super(age, name);
    }
    public void meow() {
        System.out.println("Meow! *purrs*");
    }
}
