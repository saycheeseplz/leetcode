from Point2 import Point2

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


