public class Main {
    public static void main(String[] args) {

        Library library = new Library();

        // Thêm sách
        library.addBook(new EBook("Java Basics", "James Gosling", "E001", 15.99, 5, 2.5));
        library.addBook(new PrintedBook("Discrete Math", "Rosen", "P001", 30.0, 3, 450));
        library.addBook(new EBook("Data Structures", "Mark Weiss", "E002", 20.0, 2, 5.0));
        library.addBook(new PrintedBook("Algorithms", "Cormen", "P002", 40.0, 1, 600));

        // Search by title
        System.out.println("=== Search by Title ===");
        Book foundTitle = library.searchByTitle("Data Structures");
        if (foundTitle != null)
            foundTitle.displayDetails();
        System.out.println();

        // Search by author
        System.out.println("=== Search by Author ===");
        Book foundAuthor = library.searchByAuthor("Rosen");
        if (foundAuthor != null)
            foundAuthor.displayDetails();
        System.out.println();

        // Borrow books
        System.out.println("=== Borrow Books ===");
        library.borrowBook("E001"); // Java Basics
        library.borrowBook("P002"); // Algorithms
        library.borrowBook("P002"); // thử mượn sách hết stock

        // Display all books
        System.out.println();
        library.displayAllBooks();
    }
}
