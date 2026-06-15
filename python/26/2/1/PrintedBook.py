from Book import Book
class PrintedBook(Book):
    def __init__(self, title, author, ISBN, price, stock,pageCount):
        super().__init__(title, author, ISBN, price, stock)
        self.__pageCount=pageCount
    def displayDetails(self):
        super().displayDetails()
        print("PageCount: ",self.__pageCount)
    