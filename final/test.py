class Solution:
    def parseTernary(self, expression: str) -> str:
        stack = []
        for i in range(len(expression) - 1, -1, -1):
            c = expression[i]
            if stack and stack[-1] == '?':
                stack.pop()        # bỏ '?'
                first  = stack.pop()  # true-branch
                stack.pop()        # bỏ ':'
                second = stack.pop()  # false-branch
                stack.append(first if c == 'T' else second)
            else:
                stack.append(c)
        return stack[0]

