/*
 ID: soroush11
 LANG: C++
 TASK: lamps
 */
#include <fstream>
#include <vector>
#include <set>
#include <string>
#include <sstream>
#include <iostream>

using namespace std;

int N, C;

//int final[100];
//int current[100];

vector<int> final;
vector<int> current;

set<string> validStates;

void recurse(int c)
{
	//cout << c << endl;
	if (c == C)
	{
		bool valid = true;
		for (int i = 0; i < N; i++)
		{
			if (final[i] == -1)
				continue;
			if (current[i] != final[i])
			{
				valid = false;
				break;
			}
		}


		//cout << state << endl;

		if (valid)
		{
			stringstream ss("");
			for (int i = 0; i < N; i++)
				ss << current[i];

			string state = ss.str();
			if(validStates.count(state) == 0)
			{
				validStates.insert(state);
				cout << state << endl;
			}

		}

		return;
	}

	for (int i = 0; i < N; i++)
		current[i] = 1 - current[i];

	recurse(c + 1);

	for (int i = 0; i < N; i++)
		current[i] = 1 - current[i];

	for (int i = 0; i < N; i += 2)
		current[i] = 1 - current[i];

	recurse(c + 1);

	for (int i = 0; i < N; i += 2)
		current[i] = 1 - current[i];

	for (int i = 1; i < N; i += 2)
		current[i] = 1 - current[i];

	recurse(c + 1);

	for (int i = 1; i < N; i += 2)
		current[i] = 1 - current[i];

	for (int i = 0; i < N; i += 3)
		current[i] = 1 - current[i];

	recurse(c + 1);

	for (int i = 0; i < N; i += 3)
		current[i] = 1 - current[i];
}

int main()
{
	ifstream in("lamps.in");
	ofstream out("lamps.out");

	in >> N >> C;
	C = min(C, 4);
	int input;
	for (int i = 0; i < N; i++)
	{
		final.push_back(-1);
		current.push_back(1);
	}

	while (true)
	{
		in >> input;
		if (input == -1)
			break;
		final[--input] = 1;
	}

	while (true)
	{
		in >> input;
		if (input == -1)
			break;
		final[--input] = 0;
	}

	recurse(0);

	if (validStates.size() == 0)
	{
		out << "IMPOSSIBLE" << endl;
		out.close();
		return 0;
	}

	set<string>::iterator i;
	for (i = validStates.begin(); i != validStates.end(); i++)
		out << (*i) << endl;

	out.close();
	return 0;
}

