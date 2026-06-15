class Solution:
    def calculate(self, s: str) -> int:
        self.i = 0

        def solve_cal():
            stack = []
            op = '+'
            num = 0

            while self.i < len(s):
                ch = s[self.i]
                self.i += 1

                if ch == ' ':
                    continue

                if ch.isdigit():
                    num = num * 10 + int(ch)

                elif ch == '(':
                    num = solve_cal()  # i sẽ dừng SAU dấu ')'

                # Flush khi gặp operator, ')' hoặc hết string
                if ch in '+-*/' or self.i == len(s) or ch == ')':
                    if op == '+':
                        stack.append(num)
                    elif op == '-':
                        stack.append(-num)
                    elif op == '*':
                        stack.append(stack.pop() * num)
                    elif op == '/':
                        stack.append(int(stack.pop() / num))

                    num = 0
                    op = ch  # cập nhật operator

                    if ch == ')':
                        break  # kết thúc tầng này

            return sum(stack)

        return solve_cal()
s = "((25-5*3)+(18/(3+3))*7-(4*(6+2)))/3 + (15-(3*(2+8/4))) + 9*(7-(12/(2*3)))"
a=Solution().calculate(s)
print(a)