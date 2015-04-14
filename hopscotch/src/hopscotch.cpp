#include<fstream>
#include<vector>
#include<queue>

using namespace std;

int R = 0, C = 0, K = 0;
int array[100][100];
vector<pair<int, int> > edges[100][100];
long long result = 0;

void dfs(int a, int b)
{
	if(a == R || b == C)
		return;

	if(a == R - 1 && b == C - 1)
	{
		result++;
		return;
	}

	for(int i = 0; i < edges[a][b].size(); i++)
		dfs(edges[a][b][i].first, edges[a][b][i].second);
}

int main()
{
	ifstream in("hopscotch.in");
	ofstream out("hopscotch.out");


	in >> R >> C >> K;
	for(int i = 0; i < R; i++)
		for(int j = 0; j < C; j++)
			in >> array[i][j];

	/*for(int i = 0; i < R; i++)
		for(int j = 0; j < C; j++)
			for(int ii = i+1; ii < R; ii++)
				for(int jj = j+1; jj < C; jj++)
					if(array[ii][jj] != array[i][j])
						edges[i][j].push_back(pair<int, int>(ii, jj));
						*/


	int dp[150][150];
	dp[0][0] = 1;
	int steps = 1;

	int totalSteps = min(R, C);

	while(steps < totalSteps)
	{
		for(int i = 0; i < steps; i++)
			for(int ii = i+1; ii < R; ii++)
				for(int jj = steps; jj < C; jj++)
					if(array[ii][jj] != array[i][steps-1])
					{
						dp[ii][jj] += dp[i][steps-1];
						dp[ii][jj] %= 1000000007;
					}
		for(int j = 0; j < steps - 1; j++)
			for(int ii = steps; ii < R; ii++)
				for(int jj = j+1; jj < C; jj++)
					if(array[ii][jj] != array[steps-1][j])
					{
						dp[ii][jj] += dp[steps-1][j];
						dp[ii][jj] %= 1000000007;
					}

		steps++;

	}

	/*for(int i = 0; i < R; i++)
			for(int j = 0; j < C; j++)
				for(int ii = i+1; ii < R; ii++)
					for(int jj = j+1; jj < C; jj++)
						if(array[ii][jj] != array[i][j])
							dp[ii][jj] += dp[i][j];
							*/
	out << dp[R-1][C-1];



	//dfs(0, 0);
	/*queue<pair<int, int> > q;
	q.push(pair<int, int>(0, 0));
	int a, b;
	while(!q.empty())
	{
		pair<int, int> p = q.front();
		a = p.first;
		b = p.second;
		q.pop();

		if(a == R - 1 && b == C - 1)
			result++;

		for(int i = 0; i < edges[a][b].size(); i++)
			q.push(pair<int, int>(edges[a][b][i].first, edges[a][b][i].second));
	}

	out << result % 1000000007;*/

	in.close();
	out.close();

}
