#include <string>
#include <vector>

using namespace std;

bool compareMatrix(vector<vector<int>>& key, vector<vector<int>>& sLock, int y, int x) {

    for (int i = 0; i < sLock.size(); i++) {
        for (int j = 0; j < sLock[0].size(); j++) {
            if (key[i + y][j + x] == sLock[i][j]) {
                return false;
            }
        }
    }

    return true;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    bool answer = false;
    int maxLockY = -1, maxLockX = -1, minLockY = lock.size() + 1, minLockX = lock.size() + 1;
    vector<vector<int>> temp(key.size(), vector<int>(key.size()));
    vector<vector<int>> sLock;
    int lockSizeY = 0, lockSizeX = 0;
    for (int i = 0; i < lock.size(); i++) {
        for (int j = 0; j < lock.size(); j++) {
            if (lock[i][j] == 0) {
                if (maxLockY < i) maxLockY = i;
                if (maxLockX < j) maxLockX = j;
                if (minLockY > i) minLockY = i;
                if (minLockX > j) minLockX = j;
            }
        }
    }
    if (maxLockY == -1) return true;
    lockSizeY = maxLockY - minLockY + 1;
    lockSizeX = maxLockX - minLockX + 1;
    if (key.size() < lockSizeY || key.size() < lockSizeX) return false;

    for (int i = 0; i < lockSizeY; i++) {
        sLock.push_back(vector<int>());
        for (int j = 0; j < lockSizeX; j++) {
            sLock[i].push_back(lock[minLockY + i][minLockX + j]);
        }
    }

    for (int k = 0; k < 4; k++) {
        for (int i = 0; i < key.size(); i++)
            for (int j = 0; j < key.size(); j++)
                temp[i][j] = key[key.size() - j - 1][i];
        for (int i = 0; i < key.size(); i++)
            for (int j = 0; j < key.size(); j++)
                key[i][j] = temp[i][j];

        for (int y = 0; y <= key.size() - sLock.size(); y++) {
            for (int x = 0; x <= key.size() - sLock[0].size(); x++) {
                if (compareMatrix(key, sLock, y, x)) {
                    return true;
                }
            }
        }
    }



    return answer;
}

