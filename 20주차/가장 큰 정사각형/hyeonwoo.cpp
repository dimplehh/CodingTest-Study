#include <iostream>
#include<vector>
#define MAX(a,b)(((a)>(b))?(a):(b))
#define MIN(a,b)(((a)<(b))?(a):(b))

using namespace std;

int solution(vector<vector<int>> board)
{
    int answer = 0;
    int width, height;
    int x = 0, y = 0;

    for (int i = 1;i < board.size();i++) {
        for (int j = 1;j < board[i].size();j++) {
            int x = board[i - 1][j];
            int y = board[i - 1][j - 1];
            int z = board[i][j - 1];
            if (board[i][j] != 0) board[i][j] = MIN(MIN(x, y), z) + 1;
        }
    }

    for (int i = 0;i < board.size();i++)
        for (int j = 0;j < board[i].size();j++)
            answer = MAX(answer, board[i][j]);

    return answer * answer;
}
