class Solution:
    def countOfAtoms(self, formula: str) -> str:
        i = 0
        n = len(formula)

        def parse() -> dict:
            nonlocal i
            counts = {}

            while i < n and formula[i] != ')':
                if formula[i] == '(':
                    i += 1  # bỏ '('
                    inner = parse()
                    i += 1  # bỏ ')'
                    # đọc số nhân
                    mul = read_num()
                    for elem, cnt in inner.items():
                        counts[elem] = counts.get(elem, 0) + cnt * mul
                elif formula[i].isupper():
                    elem = formula[i]
                    i += 1
                    while i < n and formula[i].islower():
                        elem += formula[i]
                        i += 1
                    cnt = read_num()
                    counts[elem] = counts.get(elem, 0) + (cnt if cnt else 1)

            return counts

        def read_num() -> int:
            nonlocal i
            start = i
            while i < n and formula[i].isdigit():
                i += 1
            return int(formula[start:i]) if i > start else 1

        result = parse()
        # sắp xếp theo alphabet và build string
        return "".join(
            elem + (str(cnt) if cnt > 1 else "")
            for elem, cnt in sorted(result.items())
        )