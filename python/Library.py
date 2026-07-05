class Book :
    def __init__(self,title="Unknow",author="Unknow",ISBN="Unknow",price=0.0,stock=0):
        self.__title=title
        self.__author=author
        self.__ISBN=ISBN
        self.__price=price
        self.__stock=stock
    def getTitle(self):
        return self.__title
    def getAuthor(self):
        return self.__author
    def getISBN(self):
        return self.__ISBN
    def getPrice(self):
        return self.__price
    def getStock (self):
        return self.__stock
    def setTitle(self,title):
        self.__title=title
    def setAuthor(self,author):
        self.__author=author
    def setISBN(self,ISBN):
        self.__ISBN=ISBN
    def setPrice(self,price):
        self.__price=price
    def setStock (self,stock):
        self.__stock=stock
    def borrow(self):
        if self._stock > 0:
            self._stock -= 1
            return True
        return False

    def __str__(self):
        return f"{self._title} by {self._author} | Stock: {self._stock}"

class Library:
    def __init__(self,libray[]):
        self.__libra
    
    
