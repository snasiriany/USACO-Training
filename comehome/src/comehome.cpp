/*
 ID: soroush11
 LANG: C++
 TASK: comehome
 */
#include<fstream>
#include <queue>
#define INF 100000000

using namespace std;

int graph[52][52];
int dist[52];
bool visited[52];

int main()
{
	ifstream in("comehome.in");
	ofstream out("comehome.out");

	int N;

	in >> N;

	for(int i = 0; i < 52; i++)
		for(int j = 0; j < 52; j++)
			graph[i][j] = INF;

	for(int i = 0; i < 52; i++)
		dist[i] = INF;

	char pst1, pst2;
	int length;
	for(int i = 0; i < N; i++)
	{
		in >> pst1 >> pst2 >> length;
		if((int) pst1 <= 90)
			pst1 -= 39;
		else
			pst1 -= 97;

		if((int) pst2 <= 90)
			pst2 -= 39;
		else
			pst2 -= 97;
		graph[(int) pst1][(int) pst2] =
				min(graph[(int) pst1][(int) pst2], length);
		graph[(int) pst2][(int) pst1] =
				min(graph[(int) pst2][(int) pst1], length);

	}

	priority_queue<pair<int, int>, std::vector<pair<int, int> >,
			std::greater<pair<int, int> > > q;

	q.push(pair<int, int>(0, 51));
	dist[51] = 0;

	while(!q.empty())
	{
		pair<int, int> p = q.top();
		q.pop();

		int length = p.first, pt = p.second;
		if(pt >= 26 && pt < 51)
		{
			char ch = 'A';
			ch += pt - 26;
			out << ch << " " << length << endl;
			out.close();
			return 0;
		}
		if(visited[pt])
			continue;

		dist[pt] = length;
		visited[pt] = true;

		for(int i = 0; i < 52; i++)
			if(dist[i] > dist[pt] + graph[pt][i])
				q.push(pair<int, int>(dist[pt] + graph[pt][i], i));
	}
	return 0;
}

