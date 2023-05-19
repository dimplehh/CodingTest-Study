#include <string>
#include <algorithm>
#include <vector>

using namespace std;

string delZero(string s, int* i);
string translateSizeToDigit(string s);

vector<int> solution(string s) {
    vector<int> answer;

    string str = s;

    int zeroCount = 0;
    int translationCount = 0;

    while (str != "1")
    {
        str = delZero(str, &zeroCount);
        str = translateSizeToDigit(str);
        translationCount++;
    }
    answer.push_back(translationCount);
    answer.push_back(zeroCount);
    return answer;
}

string delZero(string s, int* count)
{
    string result = "";

    //0Á¦°Å
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '0')
        {
            ++* count;
        }
        else if (s[i] == '1')
        {
            result += s[i];
        }
    }

    return result;
}

string translateSizeToDigit(string s)
{
    string str = "";

    for (int i = s.size(); i != 0; i /= 2)
    {
        if (i % 2 == 1)
        {
            str += '1';
        }
        else
        {
            str += '0';
        }
    }

    reverse(str.begin(), str.end());

    return str;
}