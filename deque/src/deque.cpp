#include<iostream>
#include<deque>

using namespace std;

void printDeque(deque<int> l) {
	deque<int>::const_iterator i = l.begin();
	while(i != l.end()) {
		cout << *i << " ";
		i++;
	}
	cout << "(size: " << l.size() << ")" << endl;
}

int main() {
	deque<int> d;
	d.push_back(1);
	d.push_back(2);
	d.push_back(3);
	d.push_back(4);
	d.push_back(5);
	printDeque(d);

	d.push_front(100);
	printDeque(d);

	d.pop_back();
	printDeque(d);

	d.pop_front();
	printDeque(d);

	d.erase(++d.begin(), --d.end());
	printDeque(d);


	d.push_front(100);
	printDeque(d);

	return 0;
}
