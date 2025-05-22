def solution(n):
    answer = [[0] * n for _ in range(n)]
    answer[0][0] = 1
    moving = [[0,1], [1,0], [0,-1], [-1,0]]
    x, y, k = 0, 0, 0
    
    for i in range(2, n*n+1):
        if 0 <= x + moving[k][0] < n and 0 <= y + moving[k][1] < n and answer[x+moving[k][0]][y+moving[k][1]] == 0:
            x = x + moving[k][0]
            y = y + moving[k][1]
            answer[x][y] = i
        else:
            k = (k + 1) % 4
            x = x + moving[k][0]
            y = y + moving[k][1]
            answer[x][y] = i
    return answer