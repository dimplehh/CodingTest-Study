#include <cstring>
#include <vector>

using namespace std;

int solution(string s) {
    char numArr[10][6]={"zero","one","two","three","four","five","six","seven","eight","nine"};
    vector <int>temp;
    int answer = 0;
    for(int i = 0; i < s.length(); i++)
    {
        if(0 <= (s[i] - '0') && (s[i] - '0') <= 9)
            temp.push_back(s[i] - '0');
        else
        {
            for (int j = 0; j < 10; j++)
            {
                if(s[i] == numArr[j][0])
                {
                    if(s[i] == 't' || s[i] == 'f' || s[i] == 's')
                        if(s[i + 1] == numArr[j + 1][1])
                            j = j + 1;
                    temp.push_back(j);
                    i = i + strlen(numArr[j]) - 1;
                    break;
                }
            }
        }
    }
    for (int i = 0; i < temp.size(); i++)
        answer = answer * 10 + temp[i];
    return answer;
}
