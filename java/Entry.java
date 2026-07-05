class Animal {
    public void sound() {
        System.out.println("some sound");
    }
}

class Dog extends Animal {
    @Override
    public void sound() {
        System.out.println("bow wow");
    }
}

class Cat extends Animal {
    @Override
    public void sound() {
        System.out.println("meow meow");
    }
}

class Duck extends Animal {
    @Override
    public void sound() {
        System.out.println("quack quack");
    }
}

public class Entry {
    public static void main(String[] args) {
        Animal[] animals = new Animal[4];
        animals[1] = new Dog();
        animals[2] = new Cat();
        animals[3] = new Duck();
        animals[0] = new Animal();

        for (int i = 0; i < 4; i++) {
            animals[i].sound();
        }
    }
}
