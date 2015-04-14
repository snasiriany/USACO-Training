/*
 ID: soroush11
 LANG: C++
 TASK: prefix
 */
#include<fstream>
#include<string>
#include<vector>
#include<iostream>

using namespace std;

int main()
{
	ifstream in("prefix.in");
	ofstream out("prefix.out");

	vector<string> P;
	string S;


	string input;
	while(in >> input && input != ".")
		P.push_back(input);

	in >> input;
	do
	{
		S += input;
		in >> input;
	} while(!in.eof());


	bool DP[200000] = {0};

	for(int i = 0; i < P.size(); i++)
		if(S.substr(0, P[i].length()) == P[i])
			DP[P[i].length() - 1] = true;

	for(int i = 0; i < S.length(); i++)
		for(int j = 0; j < P.size(); j++)
			if(DP[i] && S.substr(i+1, P[j].length()) == P[j])
				DP[i + P[j].length()] = true;

	for(int i = S.length() - 1; i >= 0; i--)
		if(DP[i])
		{
			out << i+1 << endl;
			out.close();
			return 0;
		}

	out << 0 << endl;
	out.close();
	return 0;
}

