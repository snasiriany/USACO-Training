/*
 ID: soroush11
 LANG: C++
 TASK: fracdec
 */

#include <fstream>
#include <vector>
#include <iostream>

using namespace std;

int seen[100001];

int size(int num)
{
	int count = 0;
	if(num == 0)
		return 1;

	while(num != 0)
	{
		num /= 10;
		count++;
	}
	return count;
}

int main()
{
	ifstream in("fracdec.in");
	ofstream out("fracdec.out");
	int a, b;

	in >> a >> b;

	vector<int> nums;

	for(int i = 0; i < 100001; i++)
		seen[i] = -1;

	int count = 0, index = -1;

	while(true)
	{
		nums.push_back(a / b);

		a = a % b;

		if(a == 0 && nums.size() > 1)
			break;

		if(seen[a] != -1)
		{
			index = seen[a];
			break;
		}
		seen[a] = count;

		a = a * 10;
		count++;
	}

	int charCount = 0;
	for(int i = 0; i < nums.size(); i++)
	{
		if(i == 0)
			charCount += size(nums[i]);
		else
			charCount++;
		out << nums[i];
		//cout << nums[i] << endl;
		if(charCount != 0 && charCount % 76 == 0)
			out << endl;
		if(i == 0)
		{
			out << ".";
			charCount++;
			if(charCount != 0 && charCount % 76 == 0)
				out << endl;
		}

		if(i == index)
		{
			out << "(";
			charCount++;
			if(charCount != 0 && charCount % 76 == 0)
				out << endl;
		}

		if(i == nums.size() - 1 && index != -1)
		{
			out << ")";
			charCount++;
			if(charCount != 0 && charCount % 76 == 0)
				out << endl;
		}

	}
	out << endl;

	out.close();
	return 0;
}

