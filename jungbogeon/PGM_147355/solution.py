def solution(t, p):
    
    arr = []
    text_arr = t
    result = []
    
    while range(len(text_arr) >= len(p)):
        arr.append(text_arr[0:len(p)])
        text_arr = text_arr[1:]
    
    for i in range(len(arr)):
        if int(arr[i]) <= int(p):
            result.append(arr[i])
    
    answer = len(result)
    return answer