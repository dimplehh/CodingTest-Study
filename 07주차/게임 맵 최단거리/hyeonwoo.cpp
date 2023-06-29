#include<vector>
#include<iostream>
#include <queue>
#define MIN(x,y)(((x)<(y))?(x):(y))

using namespace std;

int answer = 999999;



// dfs.. 효율성 (시간) 탈락
void dfs_maze(vector<vector<int> > maps, int _cnt = 0, int _x = 0, int _y = 0) {
	if (_x == maps[0].size() - 1 && _y == maps.size() - 1) answer = MIN(answer, _cnt + 1); // 맵 끝까지 도착시 정답 갱신
	if (maps[_y][_x] != 1) return; // 길이 아닌 경우나 이미 지나온 길 아니면 실행 X
	maps[_y][_x] = -1; // 이미 지나간 길은 -1로 표시

	// 상하좌우 움직일 수 있는곳으로 ㄱㄱ
	if (_x - 1 >= 0) dfs_maze(maps, _cnt + 1, _x - 1, _y); // 왼쪽
	if (_x + 1 <= maps[0].size() - 1) dfs_maze(maps, _cnt + 1, _x + 1, _y); // 오른쪽
	if (_y - 1 >= 0) dfs_maze(maps, _cnt + 1, _x, _y - 1); // 위쪽
	if (_y + 1 <= maps.size() - 1) dfs_maze(maps, _cnt + 1, _x, _y + 1); // 아래쪽
}


typedef struct Vector2 {
	int x;
	int y;
	int cnt;
}Vector2;

void bfs_maze(vector<vector<int> > maps) {

	int dx[4] = { -1,1,0,0 };
	int dy[4] = { 0,0,-1,1 };

	queue<Vector2> q;
	Vector2 pos;
	pos.x = pos.y = pos.cnt = 0;
	q.push(pos);

	while (!q.empty()) {
		Vector2 pos = q.front();
		q.pop();
		if (pos.x == maps[0].size() - 1 && pos.y == maps.size() - 1) {
			answer = pos.cnt + 1;
			return;
		}
		for (int i = 0;i < 4;i++) {
			Vector2 v;
			v.x = pos.x + dx[i];
			v.y = pos.y + dy[i];
			v.cnt = pos.cnt + 1;

			// 맵을 벗어나는 경우
			if (v.x < 0 || v.x >= maps[0].size() || v.y < 0 || v.y >= maps.size()) continue;

			// 길이 아닌 경우 
			if (maps[v.y][v.x] != 1) continue;

			// 방문하려는 곳은 이미 간 곳으로 표시
			maps[v.y][v.x] = -1;
			q.push(v);
		}
	}
	// 방문하지 못한 경우 answer = -1
	if (maps[maps.size() - 1][maps[0].size() - 1] != -1) answer = -1;
}

int solution(vector<vector<int> > maps)
{
	bfs_maze(maps);
	return answer;
}