#include <string>
#include <vector>

using namespace std;
//greedy
int solution(string word)
{
    const int plus[5] = { 781, 156, 31, 6, 1 };
    int answer = 0;
    for (int i = 0; i < word.length(); i++)
    {
        int current;
        switch (word[i])
        {
        case 'A':
            current = 0;
            break;
        case 'E':
            current = 1;
            break;
        case 'I':
            current = 2;
            break;
        case 'O':
            current = 3;
            break;
        case 'U':
            current = 4;
            break;
        default:
            break;
        }
        answer += current * plus[i];
    }
    answer += word.length();
    return answer;
}


// #include <string>
// #include <vector>
// #include <iostream>
// using namespace std;
// //문제 자체가 가지형태 - 완전 dfs문제임
// string target = "";
// char lst[5] = {'A', 'E', 'I', 'O', 'U'};
// int answer = 0;
// int cnt = 0;
// int temp = 0;
// void dfs(string word)
// {
//     cout << temp++ << endl;
//     if(target == word) answer = cnt; //현재까지의 count를 answer로 갱신해주는 것이 필요
//     if(word.length() > 5) return ;
//     cnt++;//result는 결국 dfs의 실행 횟수임
//     for(int i = 0; i < 5; i ++)
//         dfs(word + lst[i]);//실제로 word를 갱신해주는 것이 아닌, 매개변수로 넣어줌
// }

// int solution(string word) {
//     target = word;
//     dfs("");
//     return answer;
// }
