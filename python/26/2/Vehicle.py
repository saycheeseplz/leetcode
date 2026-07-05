class Vehicle:
    def __init__(self,brand="Unknown",year=0) :
        self.__brand=brand
        self.__year=year
    def getBrand(self):
        return self.__brand
    def getYear(self):
        return self.__year
    def setBrand(self,brand):
        self.__brand=brand
    def setYear(self,year):
        self.__year=year
    def displayInfo(self):
        print("Brand: ",self.__brand)
        print("Year: ",self.__year)
