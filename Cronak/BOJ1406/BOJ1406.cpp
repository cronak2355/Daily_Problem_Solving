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

    string Str; //명령어들 저장하는 곳 
    list<char> CmdList; //명령어들을 연결할 리스트
    
    
    int InputNumber = 0; //입력 받는 명령어 개수
    char Cmd; //명령어 받는 곳
    char CmdInput; //P가 입력됬을 때 입력받을 문자


    cin >> Str >> InputNumber;

    for(char c : Str) {
        CmdList.push_back(c);
    }
    auto Cursor = CmdList.end(); //커서의 위치 표시 

    for(int i = 0; i < InputNumber; i++) {
        cin >> Cmd;
        if(Cmd == 'L') {
            if (Cursor != CmdList.begin()) {
                Cursor--;
            }

        }
        else if(Cmd == 'D') {
            if (Cursor != CmdList.end()) {
                Cursor++;
            }
        }
        else if(Cmd == 'B') {
            if (Cursor != CmdList.begin()) {
                Cursor--;
            }
            CmdList.erase(Cursor);
        }
        else if(Cmd == 'P') {
            cin >> CmdInput;
            CmdList.insert(Cursor, CmdInput);
        }

    }

    for(char c : CmdList) {
        cout << c;
    }

    return 0;
}