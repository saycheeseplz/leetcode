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
