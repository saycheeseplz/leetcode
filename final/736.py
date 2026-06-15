class Solution:
    def evaluate(self, expression: str) -> int:

        scope = {}

        def parse(expr: str) -> int:

            # số
            if expr[0] == '-' or expr[0].isdigit():
                return int(expr)

            # biến
            if expr[0] != '(':
                return scope[expr][-1]

            # bỏ '(' ')'
            expr = expr[1:-1]

            # add
            if expr.startswith("add"):
                a, b = split_two(expr[4:])
                return parse(a) + parse(b)

            # mult
            if expr.startswith("mult"):
                a, b = split_two(expr[5:])
                return parse(a) * parse(b)

            # let
            content = expr[4:]

            parts = split_all(content)

            used = []

            i = 0

            while i < len(parts) - 1:

                # expr cuối cùng
                if i == len(parts) - 1:
                    break

                # nếu đây là expression cuối
                if i + 1 == len(parts) - 1:
                    break

                var = parts[i]
                val = parse(parts[i + 1])

                if var not in scope:
                    scope[var] = []

                scope[var].append(val)
                used.append(var)

                i += 2

            ans = parse(parts[-1])

            # rollback scope
            for v in used:
                scope[v].pop()

            return ans

        # tách 2 expression
        def split_two(s):

            parts = split_all(s)

            return parts[0], parts[1]

        # tách token theo level
        def split_all(s):

            res = []

            bal = 0

            cur = []

            for c in s:

                if c == ' ' and bal == 0:

                    if cur:
                        res.append("".join(cur))
                        cur = []

                else:

                    if c == '(':
                        bal += 1

                    elif c == ')':
                        bal -= 1

                    cur.append(c)

            if cur:
                res.append("".join(cur))

            return res

        return parse(expression)