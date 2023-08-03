#include <string>
#include <vector>
#include <sstream>
#include <map>

using namespace std;

vector<string> split(string str);

vector<string> solution(vector<string> record) {
    vector<string> answer;

    map<string, string> name;

    for (string str : record)
    {
        vector<string> sentence = split(str);

        if (sentence[0] == "Enter" || sentence[0] == "Change") //�̸� ��� Ȥ�� ����
        {
            name[sentence[1]] = sentence[2];
        }
    }

    for (string str : record)
    {
        vector<string> sentence = split(str);

        if (sentence[0] == "Enter")
        {
            answer.push_back(name[sentence[1]] + "���� ���Խ��ϴ�.");
        }
        else if (sentence[0] == "Leave")
        {
            answer.push_back(name[sentence[1]] + "���� �������ϴ�.");
        }
    }

    return answer;
}

vector<string> split(string str)
{
    vector<string> answer;
    stringstream ss(str);
    string temp;

    while (getline(ss, temp, ' '))
    {
        answer.push_back(temp);
    }

    return answer;
}