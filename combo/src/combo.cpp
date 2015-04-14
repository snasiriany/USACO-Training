/*
ID: soroush11
LANG: C++
TASK: combo
*/
#include<fstream>
#include<stdlib.h>

using namespace std;
int N = 0, f1 = 0, f2 = 0, f3 = 0, m1 = 0, m2 = 0, m3 = 0;

bool works(int n1, int n2, int n3)
{
	if(abs(n1-f1) <= 2 || abs(n1-f1) >= N-2)
		if(abs(n2-f2) <= 2 || abs(n2-f2) >= N-2)
			if(abs(n3-f3) <= 2 || abs(n3-f3) >= N-2)
				return true;
	if(abs(n1-m1) <= 2 || abs(n1-m1) >= N-2)
		if(abs(n2-m2) <= 2 || abs(n2-m2) >= N-2)
			if(abs(n3-m3) <= 2 || abs(n3-m3) >= N-2)
				return true;
	return false;


}

int main()
{
	ifstream in("combo.in");
	ofstream out("combo.out");

	int answer = 0;

	in >> N >> f1 >> f2 >> f3 >> m1 >> m2 >> m3;
	for(int n1 = 1; n1 <= N; n1++)
		for(int n2 = 1; n2 <= N; n2++)
			for(int n3 = 1; n3 <= N; n3++)
				if(works(n1, n2, n3))
					answer++;

	out << answer << endl;
	out.close();
	return 0;
}



