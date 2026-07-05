class Solution:
    def scoreOfParentheses(self, s: str) -> int:
        self.i = 0  # ✅ sửa lỗi 1
        
        def cal_s():
            num = 0
            while self.i < len(s) and s[self.i] != ')':
                if s[self.i] == '(':
                    self.i += 1          # bỏ qua '('
                    inner = cal_s()
                    self.i += 1          # bỏ qua ')'
                    
                    if inner == 0:       # ✅ sửa lỗi 2: để đệ quy tự tính
                        num += 1
                    else:
                        num += 2 * inner
            return num
        
        return cal_s()
class Solution:
    def scoreOfParentheses(self, s: str) -> int:
        stack = [0]  # stack chứa điểm của từng cấp độ lồng nhau
        
        for c in s:
            if c == '(':
                stack.append(0)  # mở cấp mới
            else:
                v = stack.pop()  # lấy điểm cấp hiện tại
                if v == 0:
                    stack[-1] += 1       # "()" → cộng 1
                else:
                    stack[-1] += 2 * v   # "(...)" → nhân đôi
        
        return stack[0]