[ 프로그래머스 : 둘만의 암호 ]

# 문제 설명

두 문자열 s와 skip, 그리고 자연수 index가 주어질 때, 다음 규칙에 따라 문자열을 만들려 합니다. 암호의 규칙은 다음과 같습니다.

- 문자열 s의 각 알파벳을 index만큼 뒤의 알파벳으로 바꿔줍니다.
- index만큼의 뒤의 알파벳이 z를 넘어갈 경우 다시 a로 돌아갑니다.
- skip에 있는 알파벳은 제외하고 건너뜁니다.

예를 들어 s = "aukks", skip = "wbqd", index = 5일 때, a에서 5만큼 뒤에 있는 알파벳은 f지만 [b, c, d, e, f]에서 'b'와 'd'는 skip에 포함되므로 세지 않습니다. 따라서 'b', 'd'를 제외하고 'a'에서 5만큼 뒤에 있는 알파벳은 [c, e, f, g, h] 순서에 의해 'h'가 됩니다. 나머지 "ukks" 또한 위 규칙대로 바꾸면 "appy"가 되며 결과는 "happy"가 됩니다.

두 문자열 s와 skip, 그리고 자연수 index가 매개변수로 주어질 때 위 규칙대로 s를 변환한 결과를 return하도록 solution 함수를 완성해주세요.

# 입출력 예 설명

s: "aukks", skip: "wbqd", index: 5, result: "happy"

# 코드 설명
```
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
```

우선 인자로 받은 s와 skip 은 문자열이기 때문에
넘기기나 삭제를 편하기 하기 위해 list 변환을 해준다

```
for i in range(len(skip_list)):
        alphabet.remove(skip_list[i])
```
먼저 skip_list 는 alphabet 에서 삭제시킨다

```
result = []
    
    for result_count in range(len(s_list)):
        if len(alphabet) - 1 < alphabet.index(s_list[result_count]) + index:
            result.append(alphabet[(alphabet.index(s_list[result_count]) + index) % len(alphabet)])
        else:
            result.append(alphabet[(alphabet.index(s_list[result_count]) + index)])
```

그리고 나서, s_list 를 사용하여 하나씩 가져와서, alphabet index 번호를 찾고, +index 만큼 해주는데
만약 여기서 alphabet 의 index 를 초과했을 경우 나눗셈 연산자를 사용해서 나머지 부분만 가져오면 순환 검색이 가능해진다

```
answer = ''.join(result)
```

완료 후 저장된 배열을 다시 문자열로 바꿔준다.