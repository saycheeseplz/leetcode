class Solution:
    def braceExpansionII(self, expression: str):
        
        def product(set1, set2):
            return {a + b for a in set1 for b in set2}
        
        def parse(i):
            res = set()
            cur = {""}
            
            while i < len(expression):
                ch = expression[i]
                
                if ch.isalpha():
                    cur = product(cur, {ch})
                
                elif ch == '{':
                    temp, i = parse(i + 1)
                    cur = product(cur, temp)
                
                elif ch == ',':
                    res |= cur
                    cur = {""}
                
                elif ch == '}':
                    res |= cur
                    return res, i
                
                i += 1
            
            res |= cur
            return res, i
        
        ans, _ = parse(0)
        return sorted(ans)