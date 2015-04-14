/*
 * censor.cpp
 *
 *  Created on: Feb 23, 2015
 *      Author: Soroush
 */
#include<iostream>
#include<fstream>
#include<string>


using namespace std;

int main()
{
	string S, T;
	ifstream in("censor.in");
	ofstream out("censor.out");

	in >> S >> T;

	//cout << S << "  " << T;

	int T_Length = T.length();

	int found = S.find(T);
	while(found != string::npos)
	{
		S.erase(found, T_Length);
		found = S.find(T, max(0, found - T_Length));
	}

	/*int s = 0, t = 0;

	while(true)
	{
		if(t == T_Length)
		{
			//cout << s << endl;
			S.erase(s - T_Length, T_Length);
			//cout << S << endl;
			s = 0;
			if(s < 0)
				s = 0;
		}

		if(s == S.length())
			break;

		if(S[s] == T[t])
			t++;
		else if(S[s] == T[0])
			t = 1;
		else
			t = 0;

		s++;

	}*/

	out << S;
	in.close();
	out.close();
}




