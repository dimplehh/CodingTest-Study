#include <string>
#include <vector>
#define MIN(x,y)(((x)<(y)?(x):(y)))

using namespace std;

bool isVisited[51] = { 0, };
int answer = 9999;

// ���ڿ� 2���� �Է¹ް� ���� �������� üũ�ϴ� �Լ�
bool ChangeAble(string a, string b) {
    int word_cnt = 0;
    for (int i = 0;i < a.size();i++) {
        if (a[i] != b[i]) word_cnt++;
    }
    if (word_cnt == 1) return true;
    else return false;
}

void dfs(string begin, string target, vector<string> words, int cnt = 0) {

    if (answer < cnt) return;

    // ���۰��� ���� ������ ��������
    if (begin == target) {
        answer = MIN(answer, cnt);
        return;
    }

    for (int i = 0;i < words.size();i++) {
        if (ChangeAble(begin, words[i]) && !isVisited[i]) {
            isVisited[i] = true;
            dfs(words[i], target, words, cnt + 1);
            isVisited[i] = false;
        }
    }
}

int solution(string begin, string target, vector<string> words) {
    dfs(begin, target, words);
    if (answer == 9999) return 0;
    return answer;
}