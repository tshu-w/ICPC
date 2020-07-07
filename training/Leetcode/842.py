class Solution:
    def splitIntoFibonacci(self, S: str) -> list[int]:
        for i in range(1, min(10, len(S))):
            x = S[:i]
            if x != '0' and x.startswith("0"):
                break

            for j in range(i + 1, min(i + 10, len(S))):
                y = S[i:j]
                if y != '0' and y.startswith("0"):
                    break

                fib = [int(x), int(y)]

                k = j
                while k < len(S):
                    nxt = fib[-1] + fib[-2]
                    nxtS = str(nxt)
                    if nxt <= 2 ** 31 - 1 and S[k:].startswith(nxtS):
                        k += len(nxtS)
                        fib.append(nxt)
                    else:
                        break
                else:
                    return fib if len(fib) >= 3 else []

        return []
