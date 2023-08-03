#include <iostream>

using namespace std;

int solution(long long X, long long Y)
{
    int Z = (Y * 100) / X;

    //Ȯ���� �ٲ� �� ���� ���
    if (Z >= 99)
    {
        return -1;
    }

    int low = 0, high = 1000000000;
    int result = 0;
    while (low <= high)
    {
        int mid = (low + high) / 2;

        //�̺�Ž�� ��� Ȯ��
        int tempZ = ((Y + mid) * 100) / (X + mid);

        if (Z >= tempZ) //�� Ŀ����
        {
            low = mid + 1;
        }
        else //�۾Ƶ� ��
        {
            high = mid - 1;
            result = mid;
        }
    }

    return result;
}

int main(void)
{
    long long X; long long Y;
    cin >> X;    cin >> Y;

    cout << solution(X, Y);
}