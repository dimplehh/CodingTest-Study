#include <iostream>

#include <string>
#include <map>
#include <vector>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;

    map<string, int> cloth;

    for (int i = 0; i < clothes.size(); i++) //clothes를 해쉬맵 형태로 변형
    {
        if (cloth.find(clothes[i][1]) != cloth.end()) //있으면 count 증가
        {
            cloth[clothes[i][1]]++;
        }
        else //없으면 만들기
        {
            cloth[clothes[i][1]] = 1; 
        }
    }

    for (pair<string, int> p : cloth)
    {
        answer *= (p.second + 1); //해당 부류를 안 입는 경우가 있으니 +1
    }

    return answer - 1;
}

int main()
{
    vector<vector<string>> c = { {"yellow_hat", "headgear"},{"blue_sunglasses", "eyewear"},{"green_turban", "headgear"} };

    cout << solution(c);
}