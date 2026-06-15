public class Circle implements IShape {
    private double raidus;

    public Circle(double raidus) {
        this.raidus = raidus;
    }

    @Override
    public double getArea() {
        return 3.14 * raidus * raidus;
    }

    @Override
    public double getPerimeter() {
        return 2 * 3.14 * raidus;
    }
}
