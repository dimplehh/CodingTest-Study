#include <string>
#include <vector>
#include <iostream>

#define ABS(x)((x>0)?(x):-(x))
#define MIN(x,y)((x<y)?(x):(y))

using namespace std;

string solution(vector<int> numbers, string hand) {

    string answer = "";
    bool isLeft = (hand == "left") ? true : false;

    // *, 0, # �� ���� 10, 11, 12�� ����
    int curLeft = 10, curRight = 12; // ���� ���� �հ��� ��ġ
    int leftLen, rightLen;
    int candidateNum; // ������ ���� ��ȣ �ĺ�

    for (int i = 0;i < numbers.size();i++) {
        switch (numbers[i])
        {
        case 1:
        case 4:
        case 7:
            answer += "L";
            curLeft = numbers[i];
            break;
        case 3:
        case 6:
        case 9:
            answer += "R";
            curRight = numbers[i];
            break;
        case 2:
        case 5:
        case 8:
        case 0:
            if (numbers[i] == 0) numbers[i] = 11;
            leftLen = ((ABS(curLeft - numbers[i])) / 3) + ((ABS(curLeft - numbers[i])) % 3);
            rightLen = ((ABS(curRight - numbers[i])) / 3) + ((ABS(curRight - numbers[i])) % 3);
            if (leftLen < rightLen || (leftLen == rightLen && isLeft)) {
                answer += "L";
                curLeft = numbers[i];
            }
            else {
                answer += "R";
                curRight = numbers[i];
            }
            break;
        }
    }
    return answer;
}