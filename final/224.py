class Solution:
    def calculate(self, s: str) -> int:
        
        stack = []
            
        result = 0
        number = 0
        sign = 1
        
        
        for ch in s:
            
            # build number
            if ch.isdigit():
                number = number * 10 + int(ch)
            
            
            elif ch == '+':
                
                result += sign * number
                
                number = 0
                sign = 1
            
            
            elif ch == '-':
                
                result += sign * number 
                number = 0
                sign = -1
            
            
            elif ch == '(':
                
                # save current state
                stack.append(result)
                stack.append(sign)
                
                result = 0
                sign = 1
            
            
            elif ch == ')':
                
                result += sign * number
                
                number = 0
                
                # apply previous sign
                result *= stack.pop()
                
                # add previous result
                result += stack.pop()
        
        
        result += sign * number
        
        
        return result