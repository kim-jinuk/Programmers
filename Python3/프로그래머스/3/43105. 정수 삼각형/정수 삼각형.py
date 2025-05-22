def solution(triangle):
    for t in range(len(triangle)-2, -1, -1):
        for i in range(t+1):
            triangle[t][i] += max(triangle[t+1][i], triangle[t+1][i+1])
    
    return triangle[0][0]