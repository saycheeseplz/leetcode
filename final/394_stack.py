class Solution:
    def decodeString(self, s: str) -> str:
        num=0
        result=""        
        stack=[]
        for c in s:
            if c.isdigit():
                num=num*10+int(c)
            elif c=='[':
                stack.append(result,num) 
                result=""
                num=0
            elif c==']':
                pre_result,pre_num=stack.pop()
                result+=pre_result+result*pre_num
            else:
                result+=c
        return result

