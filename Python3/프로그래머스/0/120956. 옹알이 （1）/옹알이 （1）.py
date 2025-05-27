def solution(babbling):
    answer = 0
    for i in babbling:
        k = i.replace("aya", " ").replace("ye", " ").replace("ma", " ").replace("woo", " ").strip()
        if k == "":
            answer = answer + 1
            
    return answer