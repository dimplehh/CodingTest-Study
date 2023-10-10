#include <string>
#include <vector>
#include <map>

#define MIN(a,b)(((a)<(b))?(a):(b))

using namespace std;
map<string, int> fatigues;

int res = 9999;

void dfs(vector<int> picks, vector<string> minerals, int currentPick, int answer = 0) {

    // ��� �� �� ���
    if (!picks[0] && !picks[1] && !picks[2]) res = MIN(res, answer);
    // ���� �� ĵ ���
    if (minerals.size() == 0) res = MIN(res, answer);
    // ���� ��� �� ���°�� ����
    if (!picks[currentPick]) return;


    picks[currentPick]--; // ��� �� ���̳ʽ�

    // �� ��̷� �ִ�� Ķ �� �ִ� ������
    int maxCnt = 5;
    if (minerals.size() < 5) maxCnt = minerals.size();

    // �Ƿε� üũ
    for (int i = 0;i < maxCnt;i++) {
        answer += fatigues[to_string(currentPick) + minerals[i][0]];
    }

    minerals.erase(minerals.begin(), minerals.begin() + maxCnt);

    // �ٽ� dfs ������
    dfs(picks, minerals, 0, answer);
    dfs(picks, minerals, 1, answer);
    dfs(picks, minerals, 2, answer);
}

int solution(vector<int> picks, vector<string> minerals) {

    fatigues["0d"] = 1;
    fatigues["0i"] = 1;
    fatigues["0s"] = 1;
    fatigues["1d"] = 5;
    fatigues["1i"] = 1;
    fatigues["1s"] = 1;
    fatigues["2d"] = 25;
    fatigues["2i"] = 5;
    fatigues["2s"] = 1;

    dfs(picks, minerals, 0);
    dfs(picks, minerals, 1);
    dfs(picks, minerals, 2);

    return res;
}