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

int N = 0; //배열의 크기
int r = 0; //위치한 값의 행
int c = 0; //위치한 값의 열
int Answer = 0; //답

void Z(int Y, int X, int Size) {
    if(Y == r && X == c) {
        cout << Answer << '\n';
        return;
    }

    if(r >= Y && r < Y + Size && c >= X && c < X + Size) {
        int Half = Size/2;

        Z(Y, X, Half);
        Z(Y, X + Half, Half);
        Z(Y + Half, X, Half);
        Z(Y + Half, X + Half, Half);
    }
    else {
        Answer += Size * Size;
    }
}


int main() {
    //입출력 속도 향상
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> r >> c;

    Z(0, 0, (1 << N));

    return 0;
}