class Laptop:
    def __init__(self,brand="HP",model="victus",price=15.8):
        self.__brand=brand
        self.__model=model
        self.__price=price
    
    def getBrand(self):
        return self.__brand
    def setBrand(self,brand):
        self.__brand=brand
    def getModel(self):
        return self.__model
    def setModel(self,model):
        self.__model=model
    def getPrice(self):
        return self.__price
    def setPrice(self,price):
        self.__price=price
laptop_1=Laptop("Apple","light",20.25)
()
(laptop_1.getBrand(),laptop_1.getModel(),laptop_1.getPrice())
(laptop_2.getBrand(),laptop_2.getModel(),laptop_2.getPrice())
