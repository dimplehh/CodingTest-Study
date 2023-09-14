#include <string>
#include <vector>
#include <iostream>
using namespace std;

int k, l, b;//key.size, lock.size, board.size 전역변수 설정

void rotate_key(vector<vector<int>> &key) {
    vector<vector<int>> tmp(k, vector<int>(k, 0));
    for(int i=0; i<k; ++i)
        for(int j=0; j<k; ++j)
            tmp[i][j] = key[k-(j+1)][i];
    key = tmp;
}

bool check(vector<vector<int>> &board, vector<vector<int>> &key, int y, int x) {
    bool ret = true;
    for(int i=0; i<k; ++i)
        for(int j=0; j<k; ++j)
            board[i+y][j+x] += key[i][j];
    
    for(int i=0; i<l; ++i)// 가운데 lock 영역이 모두 1이면 true, 아니면 false
        for(int j=0; j<l; ++j)
            if(board[k-1 + i][k-1 + j] != 1)
            {
                ret = false;
                break;
            }
    
    for(int i=0; i<k; ++i)
        for(int j=0; j<k; ++j)
            board[i+y][j+x] -= key[i][j];
    
    return ret;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    k = key.size();
    l = lock.size();
    b = 2*(k-1) + l;//board.size
    
    vector<vector<int>> board(b, vector<int>(b, 0));
    
    for(int i=0; i<l; i++)    // 가운데에 lock 영역 두기
        for(int j=0; j<l; j++)
            board[k-1 + i][k-1 + j] = lock[i][j];
    
    for(int r=0; r<4; r++)
    {
        for(int i=0; i<=b-k; ++i)
            for(int j=0; j<=b-k; ++j)
                if(check(board, key, i, j)) return true;
        rotate_key(key);   
    }
    
    return false;
}
