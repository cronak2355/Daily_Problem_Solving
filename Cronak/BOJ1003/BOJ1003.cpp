#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 
#include <iostream>
#include <algorithm>
#include <numeric>
#include <string>
#include <cmath>
#include <iomanip>
#include <vector>
#include <array>
#include <queue>
#include <map>
#include <stack>
#include <queue>
#include <list>
using namespace std;


int main() {

    // 0이 출력되는 횟수(zero_count)와 1이 출력되는 횟수(one_count)를 저장할 배열
    // N은 최대 40이므로 41개 선언
    int zero_count[41];
    int one_count[41];

    // 초기값 설정 (기저 사례)
    zero_count[0] = 1; // fib(0)은 0을 1번 출력
    one_count[0] = 0;  // fib(0)은 1을 0번 출력

    zero_count[1] = 0; // fib(1)은 0을 0번 출력
    one_count[1] = 1;  // fib(1)은 1을 1번 출력

    // 점화식을 이용해 미리 40까지 계산 (Bottom-Up)
    for (int i = 2; i <= 40; i++) {
        zero_count[i] = zero_count[i - 1] + zero_count[i - 2];
        one_count[i] = one_count[i - 1] + one_count[i - 2];
    }

    int t;
    cin >> t;
    
    int n;
    while (t--) {
        cin >> n;
        // 미리 구해둔 값 출력
        cout << zero_count[n] << " " << one_count[n] << "\n";
    }

    return 0;


    return 0;
}