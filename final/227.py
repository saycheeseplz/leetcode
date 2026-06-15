class Solution:
    def calculate(self, s: str) -> int:
        stack=[]
        num=0
        op='+'
        for i,c in  enumerate (s):
            if c.isdigit():
                num=num*10+int(c)
            if c in "+-*/" or c ==len(s)-i:
                if op =='+':
                    stack.append(num)
                elif op=='-':
                    stack.append(-num)
                elif op=='*':
                    a=stack.pop()
                    stack.append(num*a)
                elif op =='/':
                    a=stack.pop()
                    stack.append(int(a/num))
                num=0
                op=c
            
        return sum(stack)
        
