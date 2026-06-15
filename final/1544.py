class Solution:
    def makeGood(self, s: str) -> str:
        stack=[]
        for c in s :
            if not stack :
                stack.append(c)
            elif stack[-1] != c and (stack[-1]==c.lower() or stack[-1]==c.upper()):
                stack.pop()
            else:
                stack.append(c)
        return "".join(stack)
s = "leEeetcode"
a=Solution().makeGood(s)
print(a)
        