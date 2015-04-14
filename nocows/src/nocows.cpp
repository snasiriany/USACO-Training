/*
ID: soroush11
LANG: C++
TASK: nocows
*/

#include <fstream>

using namespace std;

long DP[100][200]; //DP[highest possible height][exact number of nodes]

int main()
{
	ifstream in("nocows.in");
	ofstream out("nocows.out");
	int nodes, levels;

	in >> nodes >> levels;

	for(int i = 0; i < 100; i++)
		for(int j = 0; j < 200; j++)
			DP[i][j] = 0;

	for(int i = 1; i <= levels; i++)
		DP[i][1]= 1;

	for(int l = 1; l <= levels; l++)
		for(int n = 1; n <= nodes; n++)
			for(int m = n-1; m >= 0; m--)
			{
				if(m == 0 || n-m-1 ==0)
					continue;

				DP[l][n] += DP[l-1][m] * DP[l-1][n-m-1];
				DP[l][n] %= 9901;
			}

	if((DP[levels][nodes] - DP[levels-1][nodes]) % 9901 < 0)
		out << 9901 + ((DP[levels][nodes] - DP[levels-1][nodes]) % 9901) << endl;
	else
		out << (DP[levels][nodes] - DP[levels-1][nodes]) % 9901<< endl;
	out.close();
	return 0;
}


