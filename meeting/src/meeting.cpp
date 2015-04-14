/*
 * meeting.cpp
 *
 *  Created on: Jan 19, 2015
 *      Author: Soroush
 */

#include<algorithm>
#include<iostream>
#include<fstream>
#include<set>
#include<deque>
#include<vector>

using namespace std;

class card
{
public:
	short node, bCurTime, eCurTime;

	card(short n, short b, short e)
	{
		node = n;
		bCurTime = b;
		eCurTime = e;
	}
};

int main()
{
	ifstream fin("meeting.in");
	ofstream fout("meeting.out");


	short N, M;

	fin >> N >> M;
	short b_edge[N][N];
	short e_edge[N][N];

	for(short n = 0; n < N; n++)
		for(short m = 0; m < N; m++)
		{
			b_edge[n][m] = -1;
			e_edge[n][m] = -1;
		}

	for(short m = 0; m < M; m++)
	{
		short a, b, bessie, elssie;
		fin >> a >> b >> bessie >> elssie;
		a--;
		b--;

		b_edge[a][b] = bessie;
		e_edge[a][b] = elssie;
	}

	vector<short> bessieTimes, elssieTimes;
	deque<card> Q;
	card c(0, 0, 0);
	Q.push_back(c);


	//bfs
	while(!Q.empty())
	{
		//cout << "hi" << endl;
		c = Q.front();
		Q.pop_front();
		if(c.node == N-1)
		{
			bessieTimes.push_back(c.bCurTime);
			elssieTimes.push_back(c.eCurTime);
			continue;
		}

		for(short i = c.node; i < N; i++)
			if(b_edge[c.node][i] > 0)
				Q.push_back(card(i, c.bCurTime + b_edge[c.node][i], c.eCurTime + e_edge[c.node][i]));
	}


	//dfs
	/*while(!Q.empty())
	{
		//cout << "hi" << endl;
		c = Q.back();
		Q.pop_back();
		node = c.node;
		bCurTime = c.bCurTime;
		eCurTime = c.eCurTime;
		if(node == N-1)
		{
			bessieTimes.push_back(bCurTime);
			elssieTimes.push_back(eCurTime);
		}

		for(short i = node; i < N; i++)
			if(b_edge[node][i] != -1)
				Q.push_front(card(i, bCurTime + b_edge[node][i], eCurTime + e_edge[node][i]));
	}*/

	sort(bessieTimes.begin(), bessieTimes.end());
	sort(elssieTimes.begin(), elssieTimes.end());
	vector<short>::iterator b = bessieTimes.begin(), e = elssieTimes.begin();
	while((b != bessieTimes.end())  &&  (e != elssieTimes.end()))
	{
		if(*b == *e)
		{
			fout << *b << endl;
			fin.close();
			fout.close();
			return 0;
		}

		if(*b < *e)
			b++;
		if(*e < *b)
			e++;
	}

	fout << "IMPOSSIBLE" << endl;
	fin.close();
	fout.close();
	return 0;
}




