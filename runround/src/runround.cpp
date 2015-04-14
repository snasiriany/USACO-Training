/*
ID: soroush11
LANG: C++
TASK: runround
*/

#include <fstream>
#include <cstdlib>
//#include<iostream>
#include<string>
#include<math.h>
#include<sstream>
using namespace std;

bool works(long N)
{
	//char intStr[9];
	//int size = 0;

	//while(N / (int) pow(10, size) != 0)
		//size++;

	stringstream ss;
	ss << N;
	std::string intStr = ss.str();
	//itoa(N, intStr, 10);
	int size = intStr.size();

	bool contains[10] = {0};
	for(int i = 0; i < size; i++)
	{
		if(intStr[i] - '0' == 0)
			return false;
		if(contains[intStr[i] - '0'])
			return false;
		contains[intStr[i] - '0'] = true;
	}

	int index = 0;
	index += (intStr[index] - '0');
	index %= size;

	bool seen[10] = {0};






	bool allSeen;

	int count = 1;
	while(count <= size)
	{
		allSeen = true;
		//cout << index << endl;
		index += (intStr[index] - '0');
		index %= size;
		count++;
		seen[index] = true;
		for(int i = 0; i < size; i++)
			if(!seen[i])
				allSeen = false;
	}
	return allSeen;
}

int main()
{
	ifstream in("runround.in");
	ofstream out("runround.out");
	long N;
	in >> N;
	N++;

	while(!works(N))
		N++;

	out << N << endl;

	out.close();
	return 0;
}




