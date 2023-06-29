#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;


bool solution(vector<string> phone_book) {
    bool answer = true;


    // �޸�1 : sort() ���� ������ ���� �ϰ�ʹٸ�?  -  bool compare(string a, string b) { return a.size() < b.size(); } �޼��� ���� �� �Ʒ� ��ɾ� ����
    //sort(phone_book.begin(), phone_book.end(), compare);
    // 
    // �޸�2 : ���ڿ� ���� ["123","abc","������"] sort �� � ������ ���ĵǿ�? �� ["123","abc","������"]


    // ��������(������) ���� -> ["1234","126","22"]
    sort(phone_book.begin(), phone_book.end());

    for (int i = 0; i < phone_book.size() - 1; i++) {
        if (phone_book[i + 1].find(phone_book[i]) == 0)return false;
    }

    return answer;
}
