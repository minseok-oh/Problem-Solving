import typing as List

def letterCombinations(self, digits: str) -> List[str]:
    def dfs(index: int, path: str):
        if len(path) == len(digits):
            results.append(path)
            return
            
        for i, val in enumerate(dic[digits[index]]):
            dfs(index+1, path+val)
            
    if not digits:
        return []
        
    dic = {"2": "abc", "3": "def", "4": "ghi", "5": "jkl", 
            "6": "mno", "7": "pqrs", "8": "tuv", "9": "wxyz"}
    results = []
    dfs(0, "")
    return results