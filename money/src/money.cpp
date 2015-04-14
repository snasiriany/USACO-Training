/*
 ID: soroush11
 LANG: C++
 TASK: money
 */

#include<fstream>
#include <vector>
#include <algorithm>

using namespace std;

long long DP[10001][25];
vector<int> coin;

int main()
{
	ifstream in("money.in");
	ofstream out("money.out");
	int V, N;
	in >> V >> N;

	for (int i = 0; i < 10001; i++)
		for (int j = 0; j < 25; j++)
			DP[i][j] = 0;

	int input;
	for (int i = 0; i < V; i++)
	{
		in >> input;
		if (input <= N && find(coin.begin(), coin.end(), input) == coin.end())
		{
			coin.push_back(input);
			DP[coin[coin.size() - 1]][coin.size() - 1] = 1;
		}
	}

	V = coin.size();

	for (int i = 1; i <= N; i++)
		for (int j = 0; j < V; j++)
			for (int k = j; k < V; k++)
				if (i + coin[k] <= N)
					DP[i + coin[k]][k] += DP[i][j];

	long long ans = 0;
	for (int j = 0; j < V; j++)
		ans += DP[N][j];
	out << ans << endl;

	out.close();
	return 0;
}
