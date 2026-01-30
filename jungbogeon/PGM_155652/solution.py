def solution(s, skip, index):
    alphabet = ["a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z"]
    
    skip_list = list(skip)
    s_list = list(s)
    for i in range(len(skip_list)):
        alphabet.remove(skip_list[i])
    
    result = []
    
    for result_count in range(len(s_list)):
        if len(alphabet) - 1 < alphabet.index(s_list[result_count]) + index:
            result.append(alphabet[(alphabet.index(s_list[result_count]) + index) % len(alphabet)])
        else:
            result.append(alphabet[(alphabet.index(s_list[result_count]) + index)])
    
    answer = ''.join(result)
    return answer