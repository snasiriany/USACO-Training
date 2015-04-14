/*
 ID: soroush11
 LANG: C++
 TASK: concom
 */

#include <fstream>
#include <vector>
#include <set>
#include <iostream>

#define MAX 100

using namespace std;

int N;
int graph[MAX][MAX];
bool visited[MAX];
int own[MAX];

vector<set<int> > data;

void dfs(int vertex)
{
	visited[vertex] = true;
	for (int i = 0; i < MAX; i++)
	{
		own[i] += graph[vertex][i];
	}

	for (int i = 0; i < MAX; i++)
	{
		if (own[i] > 50 && !visited[i])
			dfs(i);
	}

	return;
}

int main()
{
	ifstream in("concom.in");
	ofstream out("concom.out");

	in >> N;

	for (int i = 0; i < MAX; i++)
		for (int j = 0; j < MAX; j++)
			graph[i][j] = 0;

	int i, j, p;
	for (int count = 0; count < N; count++)
	{
		in >> i >> j >> p;
		graph[--i][--j] = p;
	}

	for (int i = 0; i < MAX; i++)
	{
		for (int j = 0; j < MAX; j++)
		{
			own[j] = 0;
			visited[j] = false;
		}

		dfs(i);

		for (int j = 0; j < MAX; j++)
		{
			if (own[j] > 50 && i != j)
				out << i + 1 << " " << j + 1 << endl;
		}
	}

	out.close();
	return 0;
}

