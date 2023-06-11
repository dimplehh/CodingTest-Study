#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    sort(phone_book.begin(), phone_book.end());
    for(int i = 0; i < phone_book.size() - 1; i++)
    {
        auto phone_num = phone_book[i];
        if(phone_num == phone_book[i + 1].substr(0, phone_num.size()))
            answer = false;//접두사이므로 앞에가 같은지만 판단하면 됨.
    }
    return answer;
}
