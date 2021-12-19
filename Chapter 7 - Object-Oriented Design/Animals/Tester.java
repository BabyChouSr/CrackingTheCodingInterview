package Animals;

public class Tester{
    public static void main(String[] args) {
        Animal animal = new Animal();
        animal.eatFood();

        Cat cat = new Cat(52, "Tom");
        cat.meow();

        System.out.println(cat.getName());

        Dog dog = new Dog();
        dog.woof();
        
    }
}
