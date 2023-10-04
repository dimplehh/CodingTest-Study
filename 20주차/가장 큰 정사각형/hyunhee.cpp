//효율성 통과 x

#include <iostream>
#include<vector>
using namespace std;

bool check(vector<vector<int>> board, int s_size)
{
    bool square_exist;
    int count = 0;
    for(int i = 0; i <= board.size() - s_size; i++)
    {
        for(int j = 0; j <= board[0].size() - s_size; j++)
        {
            square_exist = true;
            for(int k = i; k < i + s_size; k++)
            {
                for(int l = j; l < j + s_size; l++)
                {
                    if(board[k][l] == 0)
                        square_exist = false;
                }
            }
            if(square_exist == true)
            {
                count++;
                return true;   
            }
        }
    }
    if (count == 0)
        return false;
}

int solution(vector<vector<int>> board)
{
    int answer = 1;
    int min_size;
    min_size = (board.size() < board[0].size()) ? board.size() : board[0].size();
    while(min_size - answer >= 0)
    {
        if(!check(board, answer))
        {
            answer--;
            return answer * answer;
            break;
        }
        else answer++;
    }
    answer = min_size;
    return answer * answer;
}
