#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool sCompare(string a, string b)
{
    string c = a + b;
    string d = b + a;

    if (c > d)
        return true;

    return false;
}

string solution(vector<int> numbers) {
    string answer = "";

    vector<string> str;

    for (long i : numbers)
    {
        str.push_back(to_string(i));
    }

    sort(str.begin(), str.end(), sCompare);

    for (long long i = 0; i < str.size(); i++)
    {
        answer += str[i];
    }

    if (answer[0] == '0')
        return "0";

    return answer;
}