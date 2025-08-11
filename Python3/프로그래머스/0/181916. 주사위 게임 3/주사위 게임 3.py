from collections import Counter

def solution(a, b, c, d):
    answer = 0
    arr = Counter([a,b,c,d]).most_common()
    
    if arr[0][1] == 4:
        answer = 1111 * int(arr[0][0])
        
    elif arr[0][1] == 3:
        answer = pow(10 * int(arr[0][0]) + int(arr[1][0]), 2)
        
    elif arr[0][1] == 2:
        if arr[1][1] == 2:
            answer = (int(arr[0][0]) + int(arr[1][0])) * abs(int(arr[0][0]) - int(arr[1][0]))
            
        else:
            answer = int(arr[1][0]) * int(arr[2][0])
            
    elif arr[0][1] == 1:
        answer = min(arr, key=lambda x: x[0])[0]
    
    return answer