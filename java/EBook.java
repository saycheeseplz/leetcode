public class EBook extends Book {
    private double fileSize;

    public EBook(String title, String author, String ISBN, double price, int stock, double fileSize) {
        super(title, author, ISBN, price, stock);
        this.fileSize = fileSize;
    }

    public EBook(String title, String author, String ISBN, double price, int stock, double fileSize) {
        super(title, author, ISBN, price, stock);
        this.fileSize = fileSize;
    }

    @Override
    public void displayDetails() {
        super.displayDetails();
        System.out.println("FileSize: " + fileSize);
    }
}
