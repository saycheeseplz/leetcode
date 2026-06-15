class Point2:
    def __init__(self,x=0.0,y=0.0):
        self.__x=x
        self.__y=y
    def getX(self) :
        return self.__x 
    def getY(self):
        return self.__y
    def setX(self,x):
        self.__x=x
    def setY(self,y):
        self.__y=y
    def setXY(self,x,y):
        self.__x=x
        self.__y=y
    def getXY(self):
        return [self.__x,self.__y]
    def toString(self):
        return f"({self.__x},{self.__y})"


class Point3(Point2):
    def __init__(self, x=0, y=0,z=0):
        super().__init__(x, y)
        self.__z=z
    def getZ(self)   :
        return self.__z
    def setZ(self,z):
        self.__z=z
    def setXYZ(self,x,y,z) :
        super().setXY(x,y)
        self.setZ(z)
    def getXYZ(self):
        return [self.getX(),self.getY(),self.getZ()]
    def toString(self):
        return f"({self.getX()},{self.getY()},{self.getZ()})"



