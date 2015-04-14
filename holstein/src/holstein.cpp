/*
 ID: soroush11
 LANG: C++
 TASK: holstein
 */
#include<fstream>
#include<algorithm>
#include<iostream>

using namespace std;

int nVits = 0, nFeeds = 0;
int reqLevel[25];
int feed[15][25];

bool bestState[15];
bool curState[15];
int best = 15;

int countScoops()
{
	int nScoops = 0;
	for (int i = 0; i < nFeeds; i++)
		if (curState[i])
			nScoops++;
	return nScoops;
}

bool works()
{
	int curLevel[25] = { 0 };

	for (int i = 0; i < nFeeds; i++)
		if (curState[i]) {
			//cout << "hi" << endl;
			for (int j = 0; j < nVits; j++)
				curLevel[j] += feed[i][j];
		}

	//for (int i = 0; i < nVits; i++)
		//cout << curLevel[i] << " ";
	//cout << endl;

	for (int i = 0; i < nVits; i++)
		if (curLevel[i] < reqLevel[i])
			return false;

	return true;
}
void checkState()
{
	int current = countScoops();

	if (current > best)
		return;

	if (works() && current <= best)
	{
		//cout << "test: " << find(curState, curState + nFeeds, 1) - curState << endl;
		bool ok = true;

		for(int i = 0; i < nFeeds; i++)
		{
			if(bestState[i] && !curState[i])
			{
				ok = false;
				break;
			}

			if(!bestState[i] && curState[i])
			{
				ok = true;
				break;
			}
		}


		if (ok)
		{
			for (int i = 0; i < 15; i++)
				bestState[i] = curState[i];
			best = current;
		}
	}
}

void solve(int pos)
{
	if (pos == nFeeds)
		return;

	checkState();

	solve(pos + 1); //this feed is set to false

	curState[pos] = true;
	checkState();

	solve(pos + 1); //this feed is set to true

	curState[pos] = false;
}

int main()
{
	ifstream in("holstein.in");
	ofstream out("holstein.out");

	in >> nVits;
	for (int i = 0; i < nVits; i++)
		in >> reqLevel[i];

	in >> nFeeds;
	for (int i = 0; i < nFeeds; i++)
		for (int j = 0; j < nVits; j++)
			in >> feed[i][j];

	solve(0);

	int nScoops = 0;
	for (int i = 0; i < nFeeds; i++)
		if (bestState[i])
			nScoops++;

	out << nScoops << " ";
	int counter = 0;

	for (int i = 0; i < nFeeds; i++)
		if (bestState[i])
		{
			counter++;
			if(counter < nScoops)
				out << (i + 1) << " ";
			else
				out << (i + 1) << endl;
		}

	out.close();
	return 0;
}

