class Solution:
    def removeDuplicates(self, s: str) -> str:
        stack=[]
        for c in s :    
            if stack and stack[-1]==c:
                stack.pop()
            else:
                stack.append(c)
        result=""
        while stack :
            result+=stack.pop()
        return result[::-1]
        
        




