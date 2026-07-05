class Solution:
    def minRemoveToMakeValid(self, s: str) -> str:
        s = list(s)
        stack = []  # lưu index của '(' chưa được match

        for i, c in enumerate(s):
            if c == '(':
                stack.append(i)        # lưu index để xóa sau nếu cần
            elif c == ')':
                if stack:
                    stack.pop()        # match được → bỏ '(' khỏi stack
                else:
                    s[i] = ''          # ')' thừa → xóa luôn

        # Các '(' còn trong stack là thừa → xóa
        for i in stack:
            s[i] = ''

        return ''.join(s)
                    
    

        