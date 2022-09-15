import collections
import typing as List

def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
    graph = collections.defaultdict(list)
    for u, v in prerequisites:
        graph[u].append(v)
    traced = set()
    visited = set()
        
    def dfs(here: int):
        if here in traced:
            return False
        if here in visited:
            return True
            
        traced.add(here)
        for i in graph[here]:
            if not dfs(i):
                return False
        traced.remove(here)
        visited.add(here)
            
        return True
        
    for i in list(graph):
        if not dfs(i):
            return False
    return True