#include <string>
#include <vector>
#include <algorithm>
#define MAX(a,b)(((a)>(b))?(a):(b))
using namespace std;

int solution(vector<int> citations) {
    int H_index = 0;
    sort(citations.begin(), citations.end()); // [3,0,6,1,5] -> [0,1,3,5,6]
    // 정렬 해주는 이유? - 특정 Index 이후 값은 크거나 같은 값을 가지기 때문

    // 논문 수만큼 index 비교
    // citations[0] (0회) 이상 인용된 논문 = 5편, 나머지 논문 = 0편 . . . 조건(0편 이상 0편 이하) 만족? - O -> H_index = 0
    // citations[1] (1회) 이상 인용된 논문 = 4편, 나머지 논문 = 1편 . . . 조건(1편 이상 1편 이하) 만족? - O -> H_index = 1
    // citations[2] (3회) 이상 인용된 논문 = 3편, 나머지 논문 = 2편 . . . 조건(3편 이상 3편 이하) 만족? - O -> H_index = 3
    // citations[3] (5회) 이상 인용된 논문 = 2편, 나머지 논문 = 3편 . . . 조건(5편 이상 5편 이하) 만족? - X
    // citations[4] (6회) 이상 인용된 논문 = 1편, 나머지 논문 = 4편 . . . 조건(6편 이상 6편 이하) 만족? - X

    // 따라서 citations[i]회 이상 인용된 논문 = (citations.size()-i) 편, 나머지 논문 = i편 . . . 
    // 조건 ( citations[i] >= citations.size()-i && citations[i] >= i )만족 여부 검사 후 최대값 갱신

    for (int i = 0;i < citations.size();i++)
        if (citations[i] >= citations.size() - i && citations[i] >= i) H_index = MAX(citations.size() - i, H_index);

    // 다른 사람 풀이 보니깐 if문 조건 간략하게 + 최대값 찾으면 바로 리턴하는 방식으로 하던데 그게 더 효율적일 것 같다
    return H_index;
}