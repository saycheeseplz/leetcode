public class PrintedBook extends Book {
    private int pageCount;

    public PrintedBook(String title, String author, String ISBN, double price, int stock, int pageCount) {
        super(title, author, ISBN, price, stock);
        this.pageCount = pageCount;
    }

    @Override
    public void displayDetails() {
        super.displayDetails();
        System.out.println("PageCount: " + pageCount);
    }
}
