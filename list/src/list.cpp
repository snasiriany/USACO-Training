/*
 * list.cpp
 *
 *  Created on: Feb 21, 2014
 *      Author: Soroush
 */

#include<iostream>
#include<list>

using namespace std;

void printList(list<int> l) {
	list<int>::const_iterator i = l.begin();
	while(i != l.end()) {
		cout << *i << " ";
		i++;
	}
	cout << "(size: " << l.size() << ")" << endl;
}

int main() {
	list<int> l;
	l.push_back(1);
	l.push_back(2);
	l.push_back(3);
	l.push_back(4);
	l.push_back(5);
	printList(l);

	l.push_front(100);
	printList(l);

	l.pop_back();
	printList(l);

	l.pop_front();
	printList(l);

	l.erase(++l.begin(), --l.end());
	printList(l);

	l.push_front(100);
	printList(l);

	l.sort();
	printList(l);

	return 0;
}



