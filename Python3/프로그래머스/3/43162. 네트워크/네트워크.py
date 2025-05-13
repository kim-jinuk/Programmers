from collections import deque

def solution(n, computers):
    answer = 0
    visited = [0 for _ in range(n)]
    stack = deque()
    
    def dfs(graph, visited, start):
        stack.append(start)
        while stack:
            j = stack.pop()
            if visited[j] == 0:
                visited[j] = 1
                for k in range(len(graph)):
                    if graph[j][k] == 1 and visited[k] == 0:
                        stack.append(k)
    
    for i in range(len(computers)):
        if visited[i] == 0:
            dfs(computers, visited, i)
            answer += 1
            
    return answer