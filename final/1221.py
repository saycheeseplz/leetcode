class Solution:
    def balancedStringSplit(self, s: str) -> int:
        stack=[]
        balance=0
        for c in s:
            if not stack :
                stack.append(c) 
                continue
            elif (stack[-1]=='L' and c=='R') or (stack[-1]=='R'and c=='L'):
                stack.pop()
                if not stack:
                    balance+=1
            else:
                stack.append(c)
        return balance
