#include <string>
#include <vector>
#include <queue>
#include <set>
using namespace std;
int solution(int x, int y, int n)
{
    int answer = 0;
	if (x == y)
		return 0;

	queue<pair<int,int>> queue;
	set<int> set;

	set.insert(x);
	queue.push({x,0});

	while (!queue.empty())
	{
		auto data = queue.front();
		queue.pop();

		if (data.first == y)
		{
			answer = data.second;
			break;
		}
		else if (data.first < y)
		{
			int X2 = data.first * 2;
			if (set.insert(X2).second)
			{
				queue.push({ data.first * 2,data.second + 1 });
			}

			int X3 = data.first * 3;
			if(set.insert(X3).second)
				queue.push({ data.first * 3,data.second + 1 });
			
			int AddN = data.first + n;
			if(set.insert(AddN).second)
				queue.push({ data.first + n,data.second + 1 });
		}
	}

	if (answer == 0)
		return -1;

	return answer;
}
