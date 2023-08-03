#include <iostream>

using namespace std;

int solution(long long X, long long Y)
{
    int Z = (Y * 100) / X;

    //È®·üÀÌ ¹Ù²ð ¼ö ¾ø´Â °æ¿ì
    if (Z >= 99)
    {
        return -1;
    }

    int low = 0, high = 1000000000;
    int result = 0;
    while (low <= high)
    {
        int mid = (low + high) / 2;

        //ÀÌºÐÅ½»ö °á°ú È®·ü
        int tempZ = ((Y + mid) * 100) / (X + mid);

        if (Z >= tempZ) //´õ Ä¿¾ßÁö
        {
            low = mid + 1;
        }
        else //ÀÛ¾Æµµ µÊ
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