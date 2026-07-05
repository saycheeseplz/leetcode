public class OopLibrary {
    public static void main(String[] args) {
        Library library = new Library();
        Book b1 = new Book(
                "Java Programming",
                "James Gosling",
                "978-0134685991",
                450000);
        Book b2 = new Book(
                "Lập trình C++ cơ bản",
                "Nguyễn Văn A",
                "VN-CPP-001",
                120000);
        Book b3 = new Book(
                "Harry Potter and the Philosopher's Stone",
                "J.K. Rowling",
                "978-0747532699",
                320000);

        library.addBook(b1);
        library.addBook(b2);
        library.addBook(b3);
        library.printBook(2);
    }
}
