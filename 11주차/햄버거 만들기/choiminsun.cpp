#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(vector<int> ingredient) {
    int answer = 0;

    string str = ""; //�־��� ���� str�� ��ȯ
    for (int i : ingredient)
    {
        char c = i + '0'; 
        str += c; 
    }

    int start = 0; //Ž�� ������
    while (true)
    {
        //Ž��
        long pos = str.find("1231", start);

        if (pos == std::string::npos) //������ ������ ����
            break;
        else //������ ���� �����
        {
            str.erase(pos, 4);
            answer++;
        }

        //Ž�� ���� ����
        if (pos > 2) //2 ���ϸ� ó������
            start = pos - 3; //�ƴϸ� ã�� ��ġ - 3����
    }

    return answer;
}