from collections import deque

def solution(people, limit):
    answer = 0
    first = 0
    last = len(people)-1
    people = deque(sorted(people))
    
    while first <= last:
        if people[first] + people[last] <= limit:
            first = first + 1
            last = last - 1
            answer = answer + 1
        else:
            last = last - 1
            answer = answer + 1
            
    return answer