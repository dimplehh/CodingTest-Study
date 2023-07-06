#include <iostream>

#include <string>
#include <map>
#include <vector>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;

    map<string, int> cloth;

    for (int i = 0; i < clothes.size(); i++) //clothes�� �ؽ��� ���·� ����
    {
        if (cloth.find(clothes[i][1]) != cloth.end()) //������ count ����
        {
            cloth[clothes[i][1]]++;
        }
        else //������ �����
        {
            cloth[clothes[i][1]] = 1; 
        }
    }

    for (pair<string, int> p : cloth)
    {
        answer *= (p.second + 1); //�ش� �η��� �� �Դ� ��찡 ������ +1
    }

    return answer - 1;
}

int main()
{
    vector<vector<string>> c = { {"yellow_hat", "headgear"},{"blue_sunglasses", "eyewear"},{"green_turban", "headgear"} };

    cout << solution(c);
}