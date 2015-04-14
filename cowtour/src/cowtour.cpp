/*
 ID: soroush11
 LANG: C++
 TASK: cowtour
 */

#include<fstream>
#include<math.h>
#include<iomanip>

#define MAX 150
#define INF (1 << 30)

using namespace std;

double dist[MAX][MAX];
int point[MAX][2];
double diam[MAX];

int N;

int main()
{
	ifstream in("cowtour.in");
	ofstream out("cowtour.out");

	for(int i = 0; i < MAX; i++)
		for(int j = 0; j < MAX; j++)
			dist[i][j] = INF;

	in >> N;

	for(int i = 0; i < N; i++)
		in >> point[i][0] >> point[i][1];

	char input;
	in.get(input);
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < N; j++)
		{
			in.get(input);
			//cout << input;
			if(input == '0')
				dist[i][j] = INF;
			else
				dist[i][j] =
						sqrt(((point[i][0] - point[j][0]) * (point[i][0] - point[j][0])) + ((point[i][1] - point[j][1]) * (point[i][1] - point[j][1])));
		}
		//cout << endl;
		in.get(input);
	}

	//initial floyd-warshall
	for(int k = 0; k < N; k++)
		for(int i = 0; i < N; i++)
			for(int j = 0; j < N; j++)
				if(dist[i][k] + dist[k][j] < dist[i][j])
					dist[i][j] = dist[i][k] + dist[k][j];

	for(int i = 0; i < N; i++)
		dist[i][i] = INF;
	double allTime = 0;
	for(int i = 0; i < N; i++)
	{
		double maxDist = 0;
		for(int j = 0; j < N; j++)
			if(dist[i][j] != INF)
				maxDist = max(maxDist, dist[i][j]);
		diam[i] = maxDist;
		allTime = max(allTime, diam[i]);
	}

	double minDiam = INF;

	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < N; j++)
		{
			if(dist[i][j] == INF && i != j)
			{
				double iToj =
						sqrt(((point[i][0] - point[j][0]) * (point[i][0] - point[j][0])) + ((point[i][1] - point[j][1]) * (point[i][1] - point[j][1])));
				//cout << diam[i] + iToj + diam[j] << endl;
				minDiam = min(minDiam, diam[i] + iToj + diam[j]);
			}
		}
	}

	if(allTime > minDiam)
		out << fixed << setprecision(6) << allTime << endl;
	else
		out << fixed << setprecision(6) << minDiam << endl;

	out.close();
	return 0;

}
