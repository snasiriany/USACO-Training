/*
 ID: soroush11
 LANG: C++
 TASK: maze1
 */

#include<fstream>
#include<queue>
#include<string>

using namespace std;

char graph[201][77];
bool visited[201][77];

int R, C;

struct card
{
	int r = 0, c = 0;
	int dist = 0;

	card(int a, int b, int d)
	{
		r = a;
		c = b;
		dist = d;
	}
};

int bfs(int a, int b)
{
	for(int r = 0; r < 2 * R; r++)
		for(int c = 0; c < 2 * C; c++)
			visited[r][c] = false;

	queue<card> q;

	int r = a * 2 + 1;
	int c = b * 2 + 1;
	int dist = 0;

	q.push(card(r, c, dist));
	while (!q.empty())
	{
		card cd = q.front();
		q.pop();

		r = cd.r, c = cd.c, dist = cd.dist;

		if (visited[r][c])
			continue;

		if (r - 1 == 0 && graph[r - 1][c] == ' ')
			return dist + 1;
		else if (r + 1 == 2 * R && graph[r + 1][c] == ' ')
			return dist + 1;
		else if (c - 1 == 0 && graph[r][c - 1] == ' ')
			return dist + 1;
		else if (c + 1 == 2 * C && graph[r][c + 1] == ' ')
			return dist + 1;

		visited[r][c] = true;

		if (r - 2 >= 0)
			if (graph[r - 1][c] != '-')
				q.push(card(r - 2, c, dist + 1));

		if (r + 2 < 2 * R)
			if (graph[r + 1][c] != '-')
				q.push(card(r + 2, c, dist + 1));

		if (c - 2 >= 0)
			if (graph[r][c - 1] != '|')
				q.push(card(r, c - 2, dist + 1));

		if (c + 2 < 2 * C)
			if (graph[r][c + 1] != '|')
				q.push(card(r, c + 2, dist + 1));
	}
	return 0;
}

int main()
{
	ifstream in("maze1.in");
	ofstream out("maze1.out");
	int ans = 0;
	in >> C >> R;
	string input;
	getline(in, input);
	for(int r = 0; r <= 2 * R; r++)
	{
		getline(in, input);
		for(int c = 0; c <= 2 * C; c++)
			graph[r][c] = input[c];
	}

	for(int r = 0; r < R; r++)
		for(int c = 0; c < C; c++)
			ans = max(ans, bfs(r, c));

	out << ans << endl;

	out.close();
	return 0;
}

