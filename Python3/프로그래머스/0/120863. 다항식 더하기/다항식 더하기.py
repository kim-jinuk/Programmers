def solution(polynomial):
    answer = ''
    arr = []
    a = 0
    b = 0
    arr = polynomial.split(" + ")
    for i in range(len(arr)):
        if arr[i][-1] == "x":
            if arr[i] == "x":
                arr[i] = "1x"
            a += int(arr[i][:-1])
        else:
            b += int(arr[i])
    
    if a == 1:
        answer = "x"
    elif a != 0:
        answer = str(a) + "x"
    if a != 0 and b != 0:
        answer += " + " + str(b)
    elif a == 0 and b != 0:
        answer = str(b)
    
    
    return answer