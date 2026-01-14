class BankAccount :
    def __init__(self,initBalance,pwd):
        self.__balance=initBalance
        self.__password=pwd
    def getBalance(self,pwd) :
        if pwd == self.__password:
           return self.__balance 
        else:
            return -1
    def deposit(self,amount) :
        self.__balance+=amount
    def withdraw(self,amount,pwd) :
        if pwd ==self.__password and amount<=self.__balance:
            self.__balance-=amount

x=input(input())
y=input(input())
acc = BankAccount(x, "y")

print(acc.getBalance("1234")) 