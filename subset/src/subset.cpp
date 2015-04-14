/*
ID: soroush11
LANG: C++
TASK: subset
*/

#include<fstream>

using namespace std;

int DP[40][400];
int main()
{
	ifstream in("subset.in");
	ofstream out("subset.out");

	int N;
	in >> N;

	int sum = N * (N+1) / 2;

	if(sum % 2 == 1)
	{
		out << 0 << endl;
		out.close();
		return 0;
	}

	int max_total = sum / 2;
	for(int n = 1; n <= N; n++)
		DP[n][0] = 1;

	for(int n = 1; n <= N; n++)
		for(int total = 1; total <= max_total; total++)
		{
			DP[n][total] = DP[n-1][total] + DP[n-1][total-n];
			//out << n << " " << total << " " << DP[n][total] << endl;
		}

	out << DP[N][max_total] << endl;

	out.close();
	return 0;

}


