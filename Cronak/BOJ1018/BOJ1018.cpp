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
    //02:40:00 시작
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    //체스판 크기
    int N = 0; 
    int M = 0;

    int Count = 0; //다시 칠해야 하는 정사각형 갯수 
    int W = 0;
    int B = 0;

    cin >> N >> M;

    vector<string> Board(N); //체스판
    vector<int> MinCount; //다시 칠해야 하는 정사각형 갯수들을 모아두는 곳 

    for(int i = 0; i < N; i++) {
        cin >> Board[i]; // 한 줄(문자열)을 통째로 입력받음
    }
 
    //검사 로직
    for(int i = 0; i < N - 7; i++) {
        for(int j = 0; j < M - 7; j++) {
            for(int x = i; x < 8 + i; x++) {
                for(int y = j; y < 8 + j; y++) {
                    if((x + y) % 2 == 0) {
                        if (Board[x][y] != 'W') Count++;
                    }
                    else {
                        if (Board[x][y] != 'B') Count++;
                    }
                }
            }
            int CurrentMin = min(Count, 64 - Count);
            MinCount.push_back(CurrentMin);
            Count = 0;
        }
    }

    int min = *min_element(MinCount.begin(), MinCount.end());

    cout <<  min << "\n";

    return 0;
}