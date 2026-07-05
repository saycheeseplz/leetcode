
public class OopCar {
    public static void main(String[] args) {
        Car car_1 = new Car("Honda", "Civic", 2006);
        Car car_2 = new Car();
        System.out.println(car_1.getBrand() + " " + car_1.getModel() + " " + car_1.getYear());
        System.out.println(car_2.getBrand() + " " + car_2.getModel() + " " + car_2.getYear());
    }
}
