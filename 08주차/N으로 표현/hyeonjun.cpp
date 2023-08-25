#include <string>
#include <vector>
#include <set>

using namespace std;

int solution(int N, int number) {
    int answer = -1;
    
    //s[i] 는 i개의 N을 사용했을 때 나올 수 있는 수를 모아놓은 set
    set<int> s[8];
    
    int sum = 0;
    
    // 각 N을 i개 붙였을 때 나오는 수들을 먼저 insert함
    for(int i=0; i<8;i++)
    {
        sum = 10 * sum + N;
        s[i].insert(sum);
    }
    
    // i개의 N을 사용하는 s[i]에서 
    for(int i=1; i<8;i++)
    {
        // i보다 작은 j의 수들 중에서
        for(int j=0; j<i; j++)
        {
            // j + (i - j + 1)개를 사용하는 수를 조합할꺼다
            for(auto a : s[j])
            {
                for(auto b : s[i - j - 1])
                {
                    // 각 수들을 사칙연산을 실행해준다.
                    s[i].insert(a+b);
                    s[i].insert(a-b);
                    s[i].insert(a*b);
                    if(b!=0)
                        s[i].insert(a/b);
                }
            }
        }
    }
    for(int i=0; i<8;i++)
    {
        if(s[i].find(number) != s[i].end())
        {
            answer = i+1;
            break;
        }
    }
    return answer;
}
