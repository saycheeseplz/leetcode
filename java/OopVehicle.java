public class OopVehicle {
    public static void main(String[] args) {
        Car car = new Car("Xe tai", 2, "dm");
        car.displayInfo();
        Vehicle tran = new Vehicle();
        tran.displayInfo();
        Bike bike = new Bike("Toyota", 2, 43);
        bike.displayInfo();
    }
}
