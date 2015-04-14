/*
 ID: soroush11
 LANG: C++
 TASK: ttwo
 */

#include <fstream>
#define MAX 10

#include <iostream>

using namespace std;

char grid[MAX][MAX];
// N = 1, E = 2, S = 3, W = 4
int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};

int main()
{
	ifstream in("ttwo.in");
	ofstream out("ttwo.out");

	int fx = 0, fy = 0, cx = 0, cy = 0;
	int fd = 0, cd = 0;
	char input;
	for(int i = 0; i < MAX; i++)
		for(int j = 0; j < MAX; j++)
		{
			in >> input;
			//cout << input << endl;
			if (input == 'F')
				fy = i, fx = j;
			else if (input == 'C')
				cy = i, cx = j;
			else
				grid[i][j] = input;
		}

	int count = 0;
	//cout << fx << " " << fy << " " << cx << " " << cy << endl;
	while (cx != fx || cy != fy)
	{
		count++;
		if (fx + dx[fd] >= 0 && fx + dx[fd] < MAX && fy + dy[fd] >= 0 && fy + dy[fd] < MAX)
			if (grid[fy + dy[fd]][fx + dx[fd]] != '*')
			{
				fx += dx[fd];
				fy += dy[fd];
			}
			else
				fd = (fd + 1) % 4;
		else
			fd = (fd + 1) % 4;

		if (cx + dx[cd] >= 0 && cx + dx[cd] < MAX && cy + dy[cd] >= 0 && cy + dy[cd] < MAX)
			if (grid[cy + dy[cd]][cx + dx[cd]] != '*')
			{
				cx += dx[cd];
				cy += dy[cd];
			}
			else
				cd = (cd + 1) % 4;
		else
			cd = (cd + 1) % 4;

		//cout << fx << " " << fy << " " << cx << " " << cy << endl;
		if(count == 200000)
		{
			out << 0 << endl;
			out.close();
			return 0;
		}

	}

	out << count << endl;

	out.close();
	return 0;
}

