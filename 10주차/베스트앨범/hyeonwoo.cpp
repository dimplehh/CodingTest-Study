#include <string>
#include <vector>
#include <unordered_map>
#include <map>
#include <algorithm>
#include <iostream>

#define MAX(a,b)(((a)>(b))?(a):(b))

using namespace std;

bool comp(pair<int, int> a, pair<int, int> b) {
    if (a.second == b.second) return a.first > a.first;
    return (a.second < b.second);
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    string max_play_genres;
    int max_play_count = 0;

    // ���� ��ȣ�� �÷��� �� ����
    vector<pair<int, int>> genre_index;

    // �뷡 �帣�� �ִ� �÷��̼� ����
    unordered_map<string, int> songs;

    // �帣�� �÷��� �� ����
    for (int i = 0;i < genres.size();i++) {
        songs[genres[i]] += plays[i];
    }


    while (!songs.empty()) {
        // �÷��̼� ���� �����帣 üũ
        for (auto i = songs.begin();i != songs.end();i++) {
            if (i->second > max_play_count) {
                max_play_count = i->second;
                max_play_genres = i->first;
            }
        }

        // �÷��̼� ���� ���� �帣 �̸��� �帣���� �˻��ϰ�, �� �ε��� ��ȣ(������ȣ)��� �÷��̼� ����
        for (int i = 0;i < genres.size();i++) {
            if (genres[i] == max_play_genres) {
                genre_index.push_back(make_pair(i, plays[i]));
            }
        }

        // genre �ϳ��� �׳� �� ������ȣ �ϳ��� �ִ´�
        if (genre_index.size() == 1) answer.push_back(genre_index.begin()->first);
        else {
            // ���� ���� �÷��̼� ���� ������ȣ ã�Ƽ� answer �� �ֱ�
            // �ι�° ��(�÷��̼�) �������� �������� ����
            sort(genre_index.begin(), genre_index.end(), comp);

            int first_idx = genre_index.back().first;         // ù��° ������ȣ
            genre_index.pop_back();
            int second_idx = genre_index.back().first;        // �ι�° ������ȣ

            // �帣 ������ ��� Ƚ���� ���� �뷡 �� ���� ��ȣ�� ���� �뷡 ���� ����
            if (plays[first_idx] == plays[second_idx]) {
                if (first_idx > second_idx) { answer.push_back(second_idx); answer.push_back(first_idx); }
                else { answer.push_back(first_idx); answer.push_back(second_idx); }
            }
            else {
                answer.push_back(first_idx); answer.push_back(second_idx);
            }
        }


        // ���� ��ȣ�� �� ��ȣ�� �÷��� �� �����ϴ� vector �ʱ�ȭ 
        genre_index.clear();
        max_play_count = 0; // �ִ�� �÷��̵� �� üũ�ϴ� �� �ʱ�ȭ

        // �ִ�� �÷��̵� �帣 �ؽ� ����
        songs.erase(max_play_genres);
    }
    return answer;
}
