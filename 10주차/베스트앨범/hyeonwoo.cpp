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

    // 고유 번호와 플레이 수 저장
    vector<pair<int, int>> genre_index;

    // 노래 장르와 최대 플레이수 저장
    unordered_map<string, int> songs;

    // 장르별 플레이 수 저장
    for (int i = 0;i < genres.size();i++) {
        songs[genres[i]] += plays[i];
    }


    while (!songs.empty()) {
        // 플레이수 가장 많은장르 체크
        for (auto i = songs.begin();i != songs.end();i++) {
            if (i->second > max_play_count) {
                max_play_count = i->second;
                max_play_genres = i->first;
            }
        }

        // 플레이수 가장 많은 장르 이름을 장르에서 검색하고, 그 인덱스 번호(고유번호)대로 플레이수 저장
        for (int i = 0;i < genres.size();i++) {
            if (genres[i] == max_play_genres) {
                genre_index.push_back(make_pair(i, plays[i]));
            }
        }

        // genre 하나면 그냥 그 고유번호 하나만 넣는다
        if (genre_index.size() == 1) answer.push_back(genre_index.begin()->first);
        else {
            // 가장 많은 플레이수 가진 고유번호 찾아서 answer 에 넣기
            // 두번째 값(플레이수) 기준으로 내림차순 정렬
            sort(genre_index.begin(), genre_index.end(), comp);

            int first_idx = genre_index.back().first;         // 첫번째 고유번호
            genre_index.pop_back();
            int second_idx = genre_index.back().first;        // 두번째 고유번호

            // 장르 내에서 재생 횟수가 같은 노래 중 고유 번호가 낮은 노래 먼저 수록
            if (plays[first_idx] == plays[second_idx]) {
                if (first_idx > second_idx) { answer.push_back(second_idx); answer.push_back(first_idx); }
                else { answer.push_back(first_idx); answer.push_back(second_idx); }
            }
            else {
                answer.push_back(first_idx); answer.push_back(second_idx);
            }
        }


        // 고유 번호와 그 번호의 플레이 수 저장하는 vector 초기화 
        genre_index.clear();
        max_play_count = 0; // 최대로 플레이된 수 체크하는 거 초기화

        // 최대로 플레이된 장르 해시 삭제
        songs.erase(max_play_genres);
    }
    return answer;
}
