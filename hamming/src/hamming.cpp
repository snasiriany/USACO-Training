/*
ID: soroush11
LANG: C++
TASK: hamming
*/

#include<fstream>
#include<bitset>
#include<vector>

using namespace std;

int main()
{
	ifstream in("hamming.in");
	ofstream out("hamming.out");

	vector<int> nums;
	nums.push_back(0);
	int N, B, D;

	in >> N >> B >> D;

	for(int i = 0; i < (1<<B); i++)
	{
		if(nums.size() == N)
			break;
		bool ok = true;
		for(int j = 0; j < nums.size() && ok; j++)
		{
			bitset<8> num(i ^ nums[j]);
			if(num.count() < D)
				ok = false;
		}
		if(ok)
			nums.push_back(i);
	}

	for(int i = 0; i < nums.size(); i++)
	{
		if(i > 0 && i % 10 == 0 && i != nums.size() - 1)
			out << endl;

		if((i%10 == 9) || i == nums.size() - 1)
			out << nums[i];
		else
			out << nums[i] << " ";
	}
	out << endl;

	return 0;
}


