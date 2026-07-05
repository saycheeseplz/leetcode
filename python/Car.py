class Car:

    def __init__(self,brand="Toyota",model="Camry",year=2000):
        self.__brand=brand
        self.__model=model
        self.__year=year
    def getBrand(self):
        return self.__brand
    def setBrand(self,brand):
        self.__brand=brand
    def getModel(self):
        return self.__model
    def setModel(self,model):
        self.__model=model
    def getYear(self):
        return self.__year
    def setYear(self,year):
        self.__year=year
    
car_1=Car("Honda","Civic",2006)
car_2=Car()
print(car_1.getBrand(),car_1.getModel(),car_1.getYear())
print(car_2.getBrand(),car_2.getModel(),car_2.getYear())
