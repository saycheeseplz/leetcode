class Solution:
    def evalRPN(self, tokens: list[str]) -> int:
        stack=[]
        for s in tokens:
            if s=="+":
                a=stack.pop()
                b=stack.pop()
                stack.append(b+a)
            elif s=="-":
                a=stack.pop()
                b=stack.pop()
                stack.append(b-a)
            elif s=="*":
                a=stack.pop()
                b=stack.pop()
                stack.append(a*b)
            elif s=="/":
                a=stack.pop()
                b=stack.pop()
                stack.append(int(b/a))
            else:
                stack.append(int(s))
        return stack[-1]

        
tokens = ["10","6","9","3","+","-11","*","/","*","17","+","5","+"]
a=Solution().evalRPN(tokens)
print(a)

        
# class Solution:
#     def evalRPN(self, tokens: list[str]) -> int:
#         import operator
#         ops = {
#             "+": operator.add,
#             "-": operator.sub,
#             "*": operator.mul,
#             "/": lambda a, b: int(operator.truediv(a, b))  # truncate toward zero
#         }
        
#         stack = []
#         for s in tokens:
#             if s in ops:
#                 b, a = stack.pop(), stack.pop()
#                 stack.append(ops[s](a, b))
#             else:
#                 stack.append(int(s))
        
#         return stack[-1]
        