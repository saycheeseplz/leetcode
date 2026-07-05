from Vehicle import Vehicle
class Car (Vehicle) :
    def __init__(self,brand="Unknown",year=0,model="Unknown"):
        super().__init__(brand,year)
        self.__model=model
    def displayInfo(self):
        super().displayInfo()
        print("Model: ",self.__model)
