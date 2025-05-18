def solution(n, info):
    ryan = [0] * 11
    best_diff = 0
    answer = [-1]
    
    def get_diff(ryan, appeach):
        diff = 0
        for i in range(10):
            if ryan[i] > appeach[i]:
                diff += (10 - i)
            elif appeach[i] != 0:
                diff -= (10 - i)
        return diff
    
    def dfs(idx, used):
        nonlocal best_diff, answer
        if idx == 11 or used == n:
            ryan[10] += (n - used)
            
            diff = get_diff(ryan, info)
            if best_diff < diff:
                best_diff = diff
                answer = ryan[:]
            elif best_diff == diff and diff != 0:
                for i in range(10, -1, -1):
                    if answer[i] > ryan[i]:
                        break
                    elif answer[i] < ryan[i]:
                        answer = ryan[:]
                        break
                        
            ryan[10] -= (n - used)
            return
        
        needed = info[idx] + 1
        if (used + needed <= n):
            ryan[idx] = needed
            dfs(idx + 1, used + needed)
            ryan[idx] = 0
            
        dfs(idx + 1, used)
    
    dfs(0, 0)
    return answer