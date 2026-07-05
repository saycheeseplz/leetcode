import java.util.List;

public class PolyLine {
    private List<Point> points;

    public PolyLine() {
    }

    public PolyLine(List<Point> points) {
        this.points = points;
    }

    public void appendPoint(Point point) {
        points.add(point);
    }

    public void appendPoint(int x, int y) {
        points.add(new Point(x, y));
    }

    public double getLength() {
        double result = 0;
        for (int i = 1; i < points.size(); i++) {
            double distance = Math.sqrt(Math.pow(points.get(i - 1).getX() - points.get(i).getX(), 2)
                    + Math.pow(points.get(i - 1).getY() - points.get(i).getY(), 2));
            result += distance;
        }
        return result;
    }
}
