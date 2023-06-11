#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    sort(numbers.begin(), numbers.end());
    for(int i=0; i< numbers.size();i++)
    {
        for(int j = i + 1; j < numbers.size(); j++)
        {
            answer.push_back(numbers[i] + numbers[j]);
        }
    }
    sort(answer.begin(), answer.end());
    answer.erase(unique(answer.begin(), answer.end()), answer.end());
    return answer;
}


// #include <string>
// #include <vector>
// #include <algorithm>
// #include <set>
// using namespace std;

// vector<int> solution(vector<int> numbers) {
//     vector<int> answer;
//     set<int> st;
//     for(int i = 0;i<numbers.size();++i){
//         for(int j = i+1 ; j< numbers.size();++j){
//             st.insert(numbers[i] + numbers[j]);
//         }
//     }
//     answer.assign(st.begin(), st.end());
//     return answer;
// }
