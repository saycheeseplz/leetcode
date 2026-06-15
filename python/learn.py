import math
# print ("content")
print("hello")
character_age=27
character_name="quan"
# f front head is formatf = formatted string literal (chuỗi định dạng)


# Nó cho phép nhúng trực tiếp biểu thức Python bên trong chuỗi bằng {}.

# Python sẽ tự động tính giá trị biểu thức bên trong {} và chèn vào chuỗi.
# ####################################string######################
print(f"fuck you {character_name}")
print(f"ohoohohh you is bitch {character_age}")
print("ohoohohh you is bitch {character_age}")
string ="abc"
number=123
boolean=True
# \n newline 
# """ content"""  down line
print ("""hello
       fuck""")
print("bitch \nmother fucker")
# i want print " " i need \"
print("hello friend  \ni am a \"demon\"")
what ="stupid i want her "
bite="crazy"
print(what+ bite)
# upper tu Hoa
print(what.upper())
#lower tu thuong 
print(bite.lower())
print(bite.isupper())
print(bite.upper().isupper())
print(bite.islower())
print(len(bite))
print(what[0])
print(what[2])
print(what.index("i"))
print(what.index("n"))
print(what.replace("want","hate"))
print(-23)
print(5%2)
num=1
print(str(num)+" la so nguoi yeu toi tung co")
fuck=-2
print(abs(fuck))
print(pow(abs(fuck),3))
print(max(2,3))
print(min(3,1))
# round lam tron
print(round(2.3))
print(round(2.51))
print(math.floor(2.7))
print(math.ceil(2.3))
print(math.sqrt(16))
# name=input("nhap ten cua ban ")
# print("fuck you "+ name)
# print(f"good bye the bad guy {name}")
# num1=input("nhap so thu 1")
# num2 =input("nhap so thu 2 ")
# sum=num1+num2
# print(sum)
# sum=int(num1)+float(num2)
# print(sum)
my_age=18
my_cursh=19
profile="toi nam nay {1} va cursh toi nam nay{1}"
print(profile.format(my_age,my_cursh))
teams=["mia","tony","hanry"]
print(teams)
print(teams[2]+"love your hisself")
print(teams[1:])
print(teams[:1])
teams[2]="quan"
print(teams[2])
print(teams)
# function array
student_names=["hoa","thuong","tai"]
math_scores=[10,3,4]
# student_names.extend(math_scores)
student_names.append("quan")
student_names.insert(len(student_names)-1,"quynh")
print(student_names)
print(len(student_names))
student_names.remove("tai")
print(student_names)
# student_names.clear()
# print(student_names)
student_names.pop()
print(student_names)
print(student_names.index("quynh"))
student_names.append("quan")
student_names.insert(0,"quynh")
print(student_names.count("quynh"))
student_names.pop(3)
# student_names.remove("quynh")o
student_names.sort()
print(student_names)
student_names.reverse()
print(student_names)
look=student_names.copy()
look.remove("thuong")
print(look)
#tuple is not change ,structure "coordinate: tuple[Literal[123], Literal[456]]"constant

coordinate=(123,456)
print(coordinate[1])
coordinate=[(134,0),(1,2)]
print(coordinate[0])
#ham
def say_hello():
       print("fuck you ,,,,,,")
say_hello()

def tell_true(story):
       print(f"i love you ,{story}")
tell_true(2)
def add(a,b):
       return a+b
print(add(2,4))
def whooa(name ,age):
       return name+age
print(whooa("quan" ,"18"))
a=50 
b=40
if a<b :
       print("true")
elif a>b:
       print("ngu")
else:
       print("3")
# && :and
# || :or
#   !:not
########## dictionary##############
translate={
       "hello":"xin chao",
       "love you":"fuck bitch",
       "want you": "fwb"
}
print(translate["want you"])
#interesting get
am=translate.get("you","i love you")
print(am)
i=1
while i<10:
       print("meo moe")
       i=i+1

em=[1,2,3]
for t in em:
       print(t)
for i in range(len(em)):
       print(2**em[i])
matrix=[
       [1,2,4],
       [2,3,4],
       [4,52,1]
]
# name="quynh"
print(matrix[1][2])
try:
       print(text)
except:
       print("fuck pitch")
try :
       print(f"i love you {name}")
except ValueError:
       print("i hate you mother fuker")
except:
       print("me kip")

class Car:
       def __init__(self,name,brand,color):
              self.name=name
              self.brand=brand
              self.color=color
       def drive(self):
              print(f"ban dang lai chiec xe {self.name} ma{self.color}cuar hangx xe {self.brand}")
kiaMorning=Car("fuck","you","brand")
kiaMorning.drive()

question=["Cau 1. Have you a crush ? \n A.Yes  \n B.No"]



































