from Book import Book
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




