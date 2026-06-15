class IdolGioiTre:
    def __init__(self ,name,age,appearance):
        self.__name=name
        self.__age=age
        self.__appearance=appearance
    def getAppearance(self):
        return self.__appearance
    def setAppearance(self,antifan):
        self.__appearance=antifan
class KhaBanh(IdolGioiTre):
    def liveStream (self):
        pass
    def signatureQuote(self):
        print("Ao that day!")
class TienBip(IdolGioiTre):
    def liveStream (self):
        pass
    def signatureQuote(self):
        print("Con cai nit")

kh=KhaBanh("Ngo Ba kha",30,"Dau Moi")
tb=TienBip("Tieen Biep",28,"Giao su hoa")
print(tb.signatureQuote())
print(kh.getAppearance())
kh.setAppearance("toc nhu LL")
print(kh.getAppearance())
