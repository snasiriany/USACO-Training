/*
ID: soroush11
LANG: C++
TASK: preface
*/
#include <fstream>
#include <math.h>


using namespace std;

int counts[4000][7];
int char_counts[7];
bool visited[4000];

int main()
{
	ifstream in("preface.in");
	ofstream out("preface.out");

	int N;

	in >> N;
	counts[1][0] = 1;
	counts[5][1] = 1;
	counts[10][2] = 1;
	counts[50][3] = 1;
	counts[100][4] = 1;
	counts[500][5] = 1;
	counts[1000][6] = 1;
	visited[1] = visited[5] = visited[10] =
			visited[50] = visited[100] = visited[500] = visited[1000] = true;

	counts[6][0] = 1; counts[6][1] = 1;
	counts[7][0] = 2; counts[7][1] = 1;
	counts[8][0] = 3; counts[8][1] = 1;
	counts[60][2] = 1; counts[60][3] = 1;
	counts[70][2] = 2; counts[70][3] = 1;
	counts[80][2] = 3; counts[80][3] = 1;
	counts[600][4] = 1; counts[600][5] = 1;
	counts[700][4] = 2; counts[700][5] = 1;
	counts[800][4] = 3; counts[800][5] = 1;
	visited[6] = visited[7] = visited[8] = visited[60] = visited[70] =
			visited[80] = visited[600] = visited[700] = visited[800] = true;


	counts[4][0] = 1; counts[4][1] = 1;
	counts[9][0] = 1; counts[9][2] = 1;
	counts[40][2] = 1; counts[40][3] = 1;
	counts[90][2] = 1; counts[90][4] = 1;
	counts[400][4] = 1; counts[400][5] = 1;
	counts[900][4] = 1; counts[900][6] = 1;
	visited[4] = visited[9] = visited[40] = visited[90] = visited[400] = visited[900] = true;

	counts[2][0] = 2;
	counts[3][0] = 3;
	counts[20][2] = 2;
	counts[30][2] = 3;
	counts[200][4] = 2;
	counts[300][4] = 3;
	counts[2000][6] = 2;
	counts[3000][6] = 3;
	visited[2] = visited[3] = visited[20] = visited[30] = visited[200] =
			visited[300] = visited[2000] = visited[3000] = true;


	for(int i = 1; i <= N; i++)
	{
		int n = i;

		for(int power = 0; n != 0; power++)
		{
			if(visited[i])
				break;

			int lower_num = (n % 10) * (int) pow(10, power);
			//out << lower_num << endl;
			for(int j = 0; j < 7; j++)
				counts[i][j] += counts[lower_num][j];
			n /= 10;
		}

		//out << endl;
		for(int j = 0; j < 7; j++)
			char_counts[j] += counts[i][j];
	}


	int max = -1;
	for(int i = 6; i >= 0; i--)
	{
		if(char_counts[i] > 0)
		{
			max = i;
			break;
		}
	}

	for(int i = 0; i < 8; i++)
	{
		if(i > max)
			break;
		if(i == 0)
			out << "I ";
		else if(i == 1)
			out << "V ";
		else if(i == 2)
			out << "X ";
		else if(i == 3)
			out << "L ";
		else if(i == 4)
			out << "C ";
		else if(i == 5)
			out << "D ";
		else if(i == 6)
			out << "M ";

		out << char_counts[i] << endl;
	}


	out.close();

	return 0;
}



