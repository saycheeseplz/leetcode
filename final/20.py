class Solution:
    def isValid(self, s: str) -> bool:
        stack=[]
        for c in s :
            if c == '{'or c=='[' or c=='(':
                stack.append(c)
            else :
                if len(stack)==0:
                    return False
                op=stack.pop()
                if op=='(' and c==')':
                    continue
                elif op=='{' and c== '}':
                    continue
                elif op=='[' and c== ']':
                    continue
                else:
                    return False
            
        if len(stack)==0:
            return True
        return False


    # def isValid(self, s: str) -> bool:
    #     stack = []
    #     mapping = {')': '(', '}': '{', ']': '['}
        
    #     for c in s:
    #         if c not in mapping:          # là ngoặc mở
    #             stack.append(c)
    #         else:                          # là ngoặc đóng
    #             if not stack or stack[-1] != mapping[c]:
    #                 return False
    #             stack.pop()
        
    #     return not stack 