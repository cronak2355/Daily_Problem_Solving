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
using namespace std;


int main() {

    int TestCase = 0; //테스트 케이스의 수 
    int DocumentNumber = 0; //문서의 개수 
    int isWhere = 0; //문서의 위치 
    int Priority = 0; //중요도 
    int BiggestPriority = 0; //중요도가 가장 높은 문서 


    queue<int> Answer; //답을 넣어두는 곳

    cin >> TestCase;
    
    for(int i = 0; i < TestCase; i++) {
        queue<pair<int, int>> Documents; //문서들을 저장하는 곳 <입력 받은 위치, 중요도>
        priority_queue<int> SortedDocuments; //정렬된 문서들

        cin >> DocumentNumber >> isWhere;

        for(int j = 0; j < DocumentNumber; j++) {
            cin >> Priority;
            Documents.push({j, Priority});
            SortedDocuments.push(Priority);
        }

        int count = 0; 

        while(1) {
            if (Documents.front().second == SortedDocuments.top()) {
                count++; 
                
                if (Documents.front().first == isWhere) {
                    Answer.push(count);
                    break; 
                }
                
                Documents.pop();
                SortedDocuments.pop();
            }
            else {
                Documents.push(Documents.front());
                Documents.pop();
            }
        }

    }

    while(!Answer.empty()) {
        cout << Answer.front() << endl;
        Answer.pop();
    }




    return 0;
}