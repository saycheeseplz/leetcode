from Book import Book
class EBook(Book):
    def __init__(self, title, author, ISBN, price, stock,fileSize):
        super().__init__(title, author, ISBN, price, stock)
        self.__fileSize=fileSize
    def displayDetails(self):
        super().displayDetails()
        print("FileSize: ",self.__fileSize)
