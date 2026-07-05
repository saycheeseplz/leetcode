public class OopLaptop {
    public static void main(String[] args) {
        Laptop laptop_1 = new Laptop();
        Laptop laptop_2 = new Laptop("Apple", "light", 20.4);
        System.out.println(laptop_1.getBrand() + " " + laptop_1.getModel() + " " + laptop_1.getPrice());
        System.out.println(laptop_2.getBrand() + " " + laptop_2.getModel() + " " + laptop_2.getPrice());
    }
}
