import java.util.ArrayList;

public class Library {
    private ArrayList<Book> books;

    public Library() {
        books = new ArrayList<>();
    }

    public void addBook(Book book) {
        books.add(book);
    }

    public Book searchByTitle(String title) {
        for (int i = 0; i < books.size(); i++) {
            if (books.get(i).getTitle().equalsIgnoreCase(title)) {
                return books.get(i);
            }
        }
        return null;
    }

    public Book searchByAuthor(String author) {
        for (int i = 0; i < books.size(); i++) {
            if (books.get(i).getAuthor().equalsIgnoreCase(author)) {
                return books.get(i);
            }
        }
        return null;
    }

    public void borrowBook(String ISBN) {
        for (int i = 0; i < books.size(); i++) {
            if (books.get(i).getISBN().equalsIgnoreCase(ISBN)) {
                int quantity = books.get(i).getStock();
                if (quantity > 0) {
                    books.get(i).setStock(quantity - 1);
                }
                return;
            }
        }
    }

    public void displayAllBooks() {
        for (int i = 0; i < books.size(); i++) {
            books.get(i).displayDetails();
            System.out.println();
        }
    }

}