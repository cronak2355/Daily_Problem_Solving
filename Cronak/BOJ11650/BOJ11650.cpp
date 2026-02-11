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
    //입출력 속도 향상
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    // x, y 좌표를 저장할 vector 생성
    vector<pair<int, int>> points(N);

    for (int i = 0; i < N; i++) {
        cin >> points[i].first >> points[i].second;
    }

    // sort 함수 사용
    // pair는 기본적으로 first 기준 정렬 -> second 기준 정렬 순서
    sort(points.begin(), points.end());

    for (int i = 0; i < N; i++) {
        // endl 대신 '\n'이 단순 띄어쓰기용으로는 더 빠르다
        cout << points[i].first << " " << points[i].second << "\n";
    }

    return 0;
}