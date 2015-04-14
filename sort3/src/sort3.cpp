/*
ID: soroush11
LANG: C++
TASK: sort3
*/
#include<fstream>

using namespace std;

int main()
{
	ifstream in("sort3.in");
	ofstream out("sort3.out");
	int N = 0, answer = 0;
	int grid[4][4];
	int numCount[4];
	int input[1001];
	in >> N;

	int num;
	for(int i = 0; i <= 3; i++)
		for(int j = 0; j <= 3; j++)
			grid[i][j] = 0;
	for(int i = 0; i <= 3; i++)
		numCount[i] = 0;

	for(int i = 1; i <= N; i++)
	{
		in >> num;
		input[i] = num;
		numCount[num]++;
	}

	for(int i = 1; i <= N; i++)
	{
		int pos = 0;
		if(i <= numCount[1])
			pos = 1;
		else if(i <= numCount[1] + numCount[2])
			pos = 2;
		else
			pos = 3;

		grid[input[i]][pos]++;
	}


	int m1 = min(grid[1][2], grid[2][1]);
	int m2 = min(grid[1][3], grid[3][1]);
	int m3 = min(grid[2][3], grid[3][2]);

	grid[1][2] -= m1;
	grid[2][1] -= m1;
	grid[1][3] -= m2;
	grid[3][1] -= m2;
	grid[2][3] -= m3;
	grid[3][2] -= m3;

	answer += (grid[1][2] + grid[2][1] + grid[2][3] + grid[3][2] + grid[1][3] + grid[3][1]);
	answer = answer * 2/3;
	answer += (m1 + m2 + m3);

	out << answer << endl;
	out.close();
	return 0;
}



