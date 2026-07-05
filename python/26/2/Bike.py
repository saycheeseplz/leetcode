from Vehicle import Vehicle
class Bike(Vehicle):
    def __init__(self, brand="Unknown", year=0,engineCapacity=0):
      super().__init__(brand, year) 
      self.__engineCapacity=engineCapacity
    def displayInfo(self):
       super().displayInfo()
       print("EngineCapacity: ",self.__engineCapacity)
    