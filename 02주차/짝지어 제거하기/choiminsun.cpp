#include <string>
#include <vector>

using namespace std;

int solution(string s)
{
    if (s.size() % 2 == 1)
        return 0;
    bool check = false;
    do {
        check = false;
        for (int i = 1; i < s.size(); i++)
        {
            if (s[i] == s[i - 1]) //일치하는 거 발견하면 지우고 다시 시작.
            {
                s.erase(--i, 2);
                if (s.size() == 0) //지우고 size0이 되면 1 return
                    return 1;
                check = true; //지운 게 있으니까 한 번 다시 해봐라~
            }
        }
    } while (check); //한 번 돌았는데 지울 게 없다.

    return 0; //갈 때까지 감. 안됨.
}