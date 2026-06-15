import java.util.ArrayList;

public class Book1 {
    private String name;
    private double price;
    private Author[] authors;

    public Book1(String name, Author[] authors, double price) {
        this.name = name;
        this.price = price;
        this.authors = authors;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getName() {
        return name;
    }

    public void setPrice(double price) {
        this.price = price;
    }

    public double getPrice() {
        return price;
    }

    public String getAuthorNames() {
        String result = "";
        int n = authors.length;
        if (n > 0) {
            result = authors[0].getName();
        }
        for (int i = 1; i < n; i++) {
            result += (", " + authors[i].getName());
        }
        return result;
    }

}
