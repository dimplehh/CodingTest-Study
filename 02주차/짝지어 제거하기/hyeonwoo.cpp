#include <iostream>
#include <string>
#include <stack>
using namespace std;

// È¿À²¼º Å»¶ô
//int solution(string s)
//{
//    char temp;
//    bool isEraseAble;
//
//    while (s.length()!=0) {
//        isEraseAble = false;
//        for (int i = 0; i < s.length() - 1; i++) {
//            temp = s[i];
//            if (temp == s[i + 1]) {
//                s.erase(i, 2);
//                isEraseAble = true;
//                break;
//            }
//        }
//        if (isEraseAble == false) return 0;
//    }
//
//    return 1;
//}


int solution(string s)
{
    char temp;
    stack<char> st;

    for (int i = 0; i < s.size(); i++) {
        if (st.empty()) st.push(s[i]);
        else {
            if (st.top() == s[i]) st.pop();
            else st.push(s[i]);
        }
    }

    if (st.empty()) return 1;
    else return 0;

}


//int main() {
//    printf("%d", solution("qaabbccccqdd"));
//}