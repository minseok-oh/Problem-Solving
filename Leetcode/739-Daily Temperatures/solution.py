import typing as List

def dailyTemperatures(self, t: List[int]) -> List[int]:
    stack = []
    res = [0] * len(t)
        
    for i, val in enumerate(t):
        while stack:
            top = stack.pop()
            if t[top] < val:
                res[top] = (i - top)
            else:
                stack.append(top)
                break
        stack.append(i)
    return res