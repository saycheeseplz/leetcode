class Solution:
    def minOperations(self, logs: list[str]) -> int:
        stack=[]
        for s in logs:
            if s=="../":
                if stack:
                    stack.pop()
            elif s=="./":
                continue
            else:
                stack.append(s)
        return len(stack)
logs = ["d1/","d2/","./","d3/","../","d31/"]
a=Solution().minOperations(logs)
print(a)