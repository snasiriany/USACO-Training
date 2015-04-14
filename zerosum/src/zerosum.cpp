/*
 ID: soroush11
 LANG: C++
 TASK: zerosum
 */
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

int N;
vector<string> valid;

void check(string &s)
{
	int number = 0, sum = 0, power = 0;
	for(int i = s.length() - 1; i >= 0; i--)
	{
		if(s[i] == '+')
		{
			sum += number;
			number = 0;
			power = 0;
		}
		else if(s[i] == '-')
		{
			sum -= number;
			number = 0;
			power = 0;
		}
		else if(s[i] == ' ')
		{
			power++;
		}
		else
		{
			number += (s[i] - '0') * pow(10, power);
		}
	}
	sum += number;

	if(sum == 0)
		valid.push_back(s);

	return;
}

void dfs(string &s, int index)
{
	if(index >= 2*N-1)
		return;

	s.insert(index, "+");
	if(s.length() == 2*N -1)
		check(s);
	dfs(s, index+2);
	s.erase(index, 1);

	s.insert(index, "-");
	if(s.length() == 2*N -1)
		check(s);
	dfs(s, index+2);
	s.erase(index, 1);

	s.insert(index, " ");
	if(s.length() == 2*N -1)
		check(s);
	dfs(s, index+2);
	s.erase(index, 1);

	return;
}

int main()
{
	ifstream in("zerosum.in");
	ofstream out("zerosum.out");

	in >> N;
	string s;
	for(int i = 1; i <= N; i++)
		s += '0' + i;

	dfs(s, 1);

	sort(valid.begin(), valid.end());
	for(int i = 0; i < valid.size(); i++)
		out << valid[i] << endl;

	out.close();
	return 0;
}

