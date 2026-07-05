class Solution:
    def decodeString(self, s: str) -> str:
        self.i = 0

        def decode():
            result = ""
            num = 0

            while self.i < len(s) and s[self.i] != ']':
                c = s[self.i]
                if c.isdigit():
                    num = num * 10 + int(c)
                elif c == '[':
                    self.i += 1          # bỏ qua '['
                    inner = decode()
                    result += inner * num
                    num = 0
                else:
                    result += c
                self.i += 1

            return result

        result = decode()
        return result