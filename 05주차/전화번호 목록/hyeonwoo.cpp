#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;


bool solution(vector<string> phone_book) {
    bool answer = true;


    // 메모1 : sort() 길이 순서로 정렬 하고싶다면?  -  bool compare(string a, string b) { return a.size() < b.size(); } 메서드 선언 후 아래 명령어 실행
    //sort(phone_book.begin(), phone_book.end(), compare);
    // 
    // 메모2 : 문자열 벡터 ["123","abc","가나다"] sort 시 어떤 순서로 정렬되요? → ["123","abc","가나다"]


    // 오름차순(가나다) 정렬 -> ["1234","126","22"]
    sort(phone_book.begin(), phone_book.end());

    for (int i = 0; i < phone_book.size() - 1; i++) {
        if (phone_book[i + 1].find(phone_book[i]) == 0)return false;
    }

    return answer;
}
