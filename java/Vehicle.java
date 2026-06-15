public class Vehicle {
    private String brand;
    private int year;

    public Vehicle() {
        this("Unknown", 0);
    }

    public Vehicle(String brand, int year) {
        this.brand = brand;
        this.year = year;
    }

    public String getBrand() {
        return brand;
    }

    public void setBrand(String brand) {
        this.brand = brand;
    }

    public int getYear() {
        return year;
    }

    public void setYear(int year) {
        this.year = year;
    }

    public void displayInfo() {
        System.out.println("Brand " + brand);
        System.out.println("Year " + year);
    }

}
