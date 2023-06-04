#include <string>
#include <vector>
#include <stack>
#include <iostream>
#include <algorithm>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    sort(participant.begin(), participant.end());
    sort(completion.begin(), completion.end());
    answer = participant.back();
    for (int i = 0; i < completion.size(); i++)
    {
        if(participant[i] != completion[i])
        {
            answer = participant[i];
            break;
        }
    }
    return answer;
}

/*#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    unordered_map<string, int> map; //map형태를 만든다.
    for(auto player:participant) //auto:자동 형변환 (string으로 해도 상관 x)
    {
        if(map.end() == map.find(player)) //map.find는 map에서 요소를 찾는 함수인데 없으면 map.end를 반환함.
            map.insert(make_pair(player, 1)); //map.insert는 map에 새로 요소를 추가하는 함수. make_pair는 쌍을 만드는 함수
        else
            map[player]++; //player라는 map의 index 의 값을 +1한다.
    }
    for(auto player:completion)
    {
        map[player]--; //map에서 completion의 요소들을 돌며 있으면 값을 -1한다.
    }
    for(auto player:participant)
    {
        if(map[player] > 0) //요소의 값이 1 이상이면 그것이 정답이므로 answer로 뱉는다.
        {
            answer = player;
            break;
        }
    }
    return answer;
}*/

