package Animals;
public class Animal {
    private int age;
    private String name;
    Animal() {
        this.age = 0;
        this.name = "";
    }
    Animal(int age, String name) {
        this.age = age;
        this.name = name;
    }
    public void eatFood() {
        System.out.println("Eating food...");
    }
    public String getName() {
        return this.name;
    }
}

