/*
Author : @wuan
Link :
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pi pair<ll, ll>
#define fi first
#define se second
#define endl '\n'
class Book
{
private:
    string title, author, ISBN;
    double price;
    int stock;

public:
    Book(string title, string author, string ISBN, double price, int stock) : title(title), author(author), ISBN(ISBN), price(price), stock(stock)
    {
    }
    string getTitle()
    {
        return title;
    }
    string getAuthor()
    {
        return author;
    }
    string getISBN()
    {
        return ISBN;
    }
    double getPrice()
    {
        return price;
    }
    int getStock()
    {
        return stock;
    }
    void setTitle(string title)
    {
        this->title = title;
    }
    void setAuthor(string author)
    {
        this->author = author;
    }
    void setISBN(string ISBN)
    {
        this->ISBN = ISBN;
    }
    void setPrice(double price)
    {
        this->price = price;
    }
    void setStock(int stock)
    {
        this->stock = stock;
    }
    virtual void displayDetails()
    {
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "ISBN: " << ISBN << endl;
        cout << "Price: " << price << endl;
        cout << "Stock: " << stock << endl;
    }
};
class EBook : public Book
{
private:
    double fileSize;

public:
    EBook(string title, string author, string ISBN, double price, int stock, double fileSize) : Book(title, author, ISBN, price, stock), fileSize(fileSize) {}
    void displayDetails() override
    {
        Book::displayDetails();
        cout << "FileSize: " << fileSize << endl;
    }
};
class PrintedBook : public Book
{
private:
    int pageCount;

public:
    PrintedBook(string title, string author, string ISBN, double price, int stock, int pageCount) : Book(title, author, ISBN, price, stock), pageCount(pageCount) {}
    void displayDetails() override
    {
        Book::displayDetails();
        cout << "PageCount: " << pageCount << endl;
    }
};
class Library
{
private:
    vector<Book *> books;

public:
    Library()
    {
    }
    void addBook(Book *book)
    {
        books.push_back(book);
    }
    Book *searchByTitle(string title)
    {
        for (int i = 0; i < books.size(); i++)
        {
            if (books[i]->getTitle() == title)
            {
                return books[i];
            }
        }
        return nullptr;
    }
    Book *searchByAuthor(string author)
    {
        for (int i = 0; i < books.size(); i++)
        {
            if (books[i]->getAuthor() == author)
            {
                return books[i];
            }
        }
        return nullptr;
    }
    void borrowBook(string ISBN)
    {
        for (int i = 0; i < books.size(); i++)
        {
            if (books[i]->getISBN() == ISBN)
            {
                int quantity = books[i]->getStock();
                if (quantity > 0)
                {
                    books[i]->setStock(quantity - 1);
                }
                return;
            }
        }
    }
    void displayAllBooks()
    {
        for (int i = 0; i < books.size(); i++)
        {
            books[i]->displayDetails();
            cout << endl;
        }
    }
};
int main()
{
    Library library = Library();

    library.addBook(new EBook("Java Basics", "James Gosling", "E001", 15.99, 5, 2.5));
    library.addBook(new PrintedBook("Discrete Math", "Rosen", "P001", 30.0, 3, 450));
    library.addBook(new EBook("Data Structures", "Mark Weiss", "E002", 20.0, 2, 5.0));
    library.addBook(new PrintedBook("Algorithms", "Cormen", "P002", 40.0, 1, 600));

    Book *foundTitle = library.searchByTitle("Data Structures");
    if (foundTitle != nullptr)
        foundTitle->displayDetails();
    cout << endl;

    Book *foundAuthor = library.searchByAuthor("Rosen");
    if (foundAuthor != nullptr)
        foundAuthor->displayDetails();
    cout << endl;
    library.borrowBook("E001");
    library.borrowBook("P002");
    library.borrowBook("P002");

    cout << endl;
    library.displayAllBooks();

    return 0;
}