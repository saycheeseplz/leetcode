class Book:
    def __init__(self,title,author,ISBN,price,stock) :
        self.__title=title
        self.__author=author
        self.__ISBN=ISBN
        self.__price=price
        self.__stock=stock
    def getTitle(self):
        return self.__title
    def getAuthor(self) :
        return self.__author
    def getISBN(self):
        return self.__ISBN
    def getPrice(self):
        return self.__price
    def getStock(self):
        return self.__stock
    def setTitle(self,title):
        self.__title=title
    def setAuthor(self,author) :
        self.__author=author
    def setISBN(self,ISBN):
        self.__ISBN=ISBN
    def setPrice(self,price):
        self.__price=price
    def setStock(self,stock):
        self.__stock=stock
    def displayDetails(self):
        print("Title: ",self.__title)
        print("Author: ",self.__author)
        print("ISBN: ",self.__ISBN)
        print("Price: ",self.__price)
        print("Stock: ",self.__stock)

class EBook(Book):
    def __init__(self, title, author, ISBN, price, stock,fileSize):
        super().__init__(title, author, ISBN, price, stock)
        self.__fileSize=fileSize
    def displayDetails(self):
        super().displayDetails()
        print("FileSize: ",self.__fileSize)

class PrintedBook(Book):
    def __init__(self, title, author, ISBN, price, stock,pageCount):
        super().__init__(title, author, ISBN, price, stock)
        self.__pageCount=pageCount
    def displayDetails(self):
        super().displayDetails()
        print("PageCount: ",self.__pageCount)
class Library:
    def __init__(self):
        self.__books=[]
    def addBook(self,book):
        self.__books.append(book)
    def searchByTitle(self,title):
        for i in range(len(self.__books)):
            if self.__books[i].getTitle()==title:
                return self.__books[i]

    def searchByAuthor(self,author):
        for i in range(len(self.__books)):
            if self.__books[i].getAuthor()==author:
                return self.__books[i]
    def borrowBook(self,ISBN):
        for i in range(len(self.__books)):
            if self.__books[i].getISBN()==ISBN:
                quantity=self.__books[i].getStock()
                if quantity >0:
                    self.__books[i].setStock(quantity-1)
    def displayAllBooks(self):
        for book in self.__books:
            book.displayDetails() 
            print()


   
library = Library()

library.addBook(EBook("Java Basics", "James Gosling", "E001", 15.99, 5, 2.5))
library.addBook(PrintedBook("Discrete Math", "Rosen", "P001", 30.0, 3, 450))
library.addBook(EBook("Data Structures", "Mark Weiss", "E002", 20.0, 2, 5.0))
library.addBook(PrintedBook("Algorithms", "Cormen", "P002", 40.0, 1, 600))

foundTitle = library.searchByTitle("Data Structures")
if foundTitle !=None:
    foundTitle.displayDetails()
print()
foundAuthor = library.searchByAuthor("Rosen")
if foundAuthor !=None:
    foundAuthor.displayDetails()

print()
library.borrowBook("E001") 
library.borrowBook("P002") 
library.borrowBook("P002") 

print()
library.displayAllBooks()