/*
 * stampede.cpp
 *
 *  Created on: Jan 19, 2015
 *      Author: Soroush
 */
#include<algorithm>
#include<fstream>
#include<set>
#include<map>
#include<vector>

using namespace std;
int N;

struct cow
{
	int x, y, r;


};

bool compare (const cow & a, const cow & b) { return a.y < b.y; }



int main()
{
	ifstream fin("stampede.in");
	ofstream fout("stampede.out");


	fin >> N;
	vector<cow> input;
	set<int> distinct_times;
	map<int, int> mp;

	int x, y, r;
	for(int n = 0; n < N; n++)
	{
		fin >> x >> y >> r;
		cow c;
		c.x = x;
		c.y = y;
		c.r = r;
		input.push_back(c);
		distinct_times.insert((-1)*(x+1)*(r));
		distinct_times.insert((-1)*(x)*(r));
	}

	set<int>::iterator si;
	int count = 0;
	for(si = distinct_times.begin(); si != distinct_times.end(); si++, count++)
	{
		mp.insert(pair<int, int>(*si, count));
	}

	/*map<int, int>::iterator mi;
	for(mi = mp.begin(); mi != mp.end(); mi++)
		fout << (mi->first) << ", " << (mi->second) <<  endl;*/


	vector<int> time_intervals(mp.size() - 1, 0);
	/*for(int i = 0; i < time_intervals.size(); i++)
		fout << time_intervals[i] << endl;*/


	sort(input.begin(), input.end(), compare);

	/*for(int i = 0; i < N; i++)
		fout << input[i].x << " " << input[i].y << " " << input[i].r << " " << endl;*/


	int numberSeen = 0;
	for(int n = 0; n < N; n++) //scan each cow's time interval in order of y position
	{
		int startTime = (-1) * (input[n].x + 1) * (input[n].r);
		int endTime = (-1) * (input[n].x) * (input[n].r);

		//fout << startTime << " to " << endTime << endl;
		int startIndex = mp[startTime];
		int endIndex = mp[endTime];

		//check
		int pos = startIndex;
		while(pos < endIndex)
		{
			if(time_intervals[pos] == 0)
			{
				numberSeen++;
				break;
			}
			pos++;
		}

		//update time_intervals
		pos = startIndex;
		while(pos < endIndex)
		{
			time_intervals[pos]++;
			pos++;
		}

	}


	fout << numberSeen << endl;
	fin.close();
	fout.close();
	return 0;
}



