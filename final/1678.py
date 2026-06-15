class Solution:
    def interpret(self, command: str) -> str:
        i = 0
        result=""
        while i < len(command):
            if command[i] == 'G':
                result += 'G'
                i += 1
            elif command[i+1] == ')':
                result += 'o'
                i += 2        # ✅ nhảy đúng 2 bước
            else:
                result += 'al'
                i += 4      
        return result