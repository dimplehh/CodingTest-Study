#include <string>
#include <vector>
#include <iostream>
#define MIN(a,b)  (((a) < (b)) ? (a) : (b))
using namespace std;

int solution(string name) {
    int answer = 0;
    vector<int> temp;
    for(int i = 0; i < name.length(); i++)
    {
        if(name[i] != 'A')
        {
            if(name[i] - 'A' < 'Z' - name[i] + 1)
                answer += name[i] - 'A';
            else
                answer += 'Z' - name[i] + 1;   
            temp.push_back(i);
        }
    }
    if(temp.size() == 0)
        return answer;
    else
    {
        int min = temp[temp.size() - 1];//case1: "ZZZAAAA"
        min = MIN(min, name.size() - temp[0]);//case2: "AAAAZZZ"
        for(int i = 0; i < temp.size() - 1; i++)//왕복이 포함된 경우
        {
            min = MIN(min, temp[i] * 2 + name.size() - temp[i + 1]);//case3: 앞에서 오른쪽으로 이동했다가 다시 뒤로 "AZAAAAZAAA"
            min = MIN(min, temp[i] + (name.size() - temp[i + 1]) * 2);//case4: 뒤에서 왼쪽으로 갔다가 앞으로
        }
        answer += min;
    }
    return answer;
}
