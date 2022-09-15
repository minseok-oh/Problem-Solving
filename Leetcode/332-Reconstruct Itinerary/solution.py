import collections
import typing as List

def findItinerary(self, tickets: List[List[str]]) -> List[str]:
    def dfs(here: str):
        while graph[here]:
            dfs(graph[here].pop(0))
        res.append(here)
        
    res = []
    graph = collections.defaultdict(list)
    for a, b in sorted(tickets):
        graph[a].append(b)
            
    dfs("JFK")
    return res[::-1]