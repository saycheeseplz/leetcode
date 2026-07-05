public class Car extends Vehicle {
    public void displayInfo() {
        super.displayInfo();
        System.out.println("model " + model);

    private String model;

    public String getModel() {
        return model;
    }

    public void setModel(String model) {
        this.model = model;
    }

    public Car(String brand, int year, String model) {
        super(brand, year);
        this.model = model;
    }

    public Car() {
        this("Unknown", 0, "Unknown");
    }

    @Override
    public void displayInfo() {
        super.displayInfo();
        System.out.println("model " + model);
    }

}
