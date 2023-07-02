#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
using namespace std;
string solution(string X, string Y) {
    map<char, int> mp;
    vector<char> temp;
    for (int i = 0; i < X.length(); i++)
        mp[X[i]]++;
    for(int i = 0; i < Y.length(); i++){
        if(mp[Y[i]] != 0) //이렇게 말고 기존처럼 set에서 find해서 s!=end()이런식으로 하면 시간복잡도 너무 커짐.. 그리고 지금은 중복값 많을 때까지 고려해야 하므로 set보다 map이 적합.
        {
            temp.push_back(Y[i]);
            mp[Y[i]]--; //이부분이 중요한 이유: 숫자가 여러개 겹치면 겹친 횟수마늠 넣어져야 하므로
        }
    }
    if(temp.empty())
        return "-1";
    sort(temp.begin(), temp.end(), greater<>());
    if(temp[0] == '0')
        return "0";
    string answer(temp.begin(), temp.end()); //이렇게 하면 string선언과 동시에 vector값 넣어줄 수 있음. 이때 vector는 char형이어야 함.
    return answer;
}


        // for (auto i = temp.begin(); i != temp.end(); i++){ //set,vector 참조 시 알아두기
    //     cout << *i << endl;
    // }


//배열로 절대 풀면 안되는 문제임 길이가 3000000까지 가능하기 때문.

// #include <string>
// #include <vector>
// #include <set>
// #include <string>
// #include <iostream>
// #include <algorithm>
// #include <cstdlib>
// using namespace std;

// string solution(string X, string Y) {
//     string answer = "";
//     vector<char> temp;
//     set<char> s;
//     for (int i = 0; i < X.length(); i++)
//         s.insert(X[i]);
//     for(int i = 0; i < Y.length(); i++){
//         if(s.find(Y[i]) != s.end())
//             temp.push_back(Y[i]);
//     }
//     if(temp.empty())
//         return "-1";
//     sort(temp.begin(), temp.end(), greater<>());
//     string str(temp.begin(), temp.end());//vector가 char형일 때는 string선언과 동시에 vector값으로 초기화 가능
//     answer =to_string(stoi(str));
//     return answer;
// }
