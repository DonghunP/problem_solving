#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int w, h;
int arr[100][100];
int dist[100][100];
//int vis[100][100];

const int dx[4] = { -1, 1, 0, 0 };
const int dy[4] = { 0, 0, -1, 1 };
bool flag;
/*--------------------------------------------------------------------------------------------------------------------------------------------------*/
//미로찾기 문제
//백트레킹 방식으로 풀었으나, 시간초과 가 떴다.
//최단 거리를 구할 때는 bfs가 더 적합하다. 
//"최소의 무언가를 구해야 하는데 그래프 전체(!)를 탐색해야 하는 경우 bfs를 쓰면 된다"(https://www.acmicpc.net/board/view/9924)
//"bfs는 모든 경로를 방문하지 않는다"(도달하면 종료하면 되어서??)
//"bfs를 쓰면 깊이가 곧 최단거리가 되므로 모든 칸을 방문하기만 하면 된다"(https://www.acmicpc.net/board/view/15650)

//DFS는 그럼 '도달 가능함'을 확일할 때 BFS보다 더 적합한가?
//도달 가능함을 확인할 때 BFS보다 더 빨리 확인할 수 있을 것 같다. 
//도달 가능함만 확인한다면 이후 빠르게 재귀를 종료 시킨다.
/*--------------------------------------------------------------------------------------------------------------------------------------------------*/

void bfs(int y, int x) {
	queue<pair<int, int>> q;
	q.push({ 0, 0 });
	dist[0][0] = 1;
	while (!q.empty()) {
		int cy = q.front().first;
		int cx = q.front().second;
		q.pop();
		if (cy == h - 1 && cx == w - 1) {
			cout << dist[h - 1][w - 1];
			break;
		}
		for (int i = 0; i < 4; i++) {
			int ny = cy + dy[i];
			int nx = cx + dx[i];
			if (ny<0 || ny >h || nx<0 || nx>w) continue;
			if (!arr[ny][nx] || dist[ny][nx]) continue; //길(1)이 아니거나, 이미 방문 했으면(dist)

			dist[ny][nx] = dist[cy][cx] + 1;//레벨 역할을 한다. 
			q.push({ ny, nx });
		}
	}
}

int main() {
	cin >> h >> w;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			scanf("%1d", &arr[i][j]);
		}
	}

	//3) bfs풀이
	bfs(0, 0);
	return 0;
}

