#include <list>
#include <iostream>
#include "Container.h"

using namespace std;

void ListTest() {
	//initialize
	list<int> L1;
	list<int> L2(10,1);
	list<int> L3(L2);
	L1.push_back(2);
	L1.push_back(1);
	L1.push_back(4);
	L1.push_front(1);
	//Positive sequence traversal
	L1.sort();//Ascending in default
	L1.remove(2);//delete item by specific value
	list<int>::iterator it1 = L1.begin();
	while (it1 != L1.end()) {
		cout << *it1<< "  ";
		++it1;
	}
	cout << endl;
	//Negative sequence traversal
	list<int>::reverse_iterator it2 = L1.rbegin();
	while (it2!=L1.rend()) {
		cout << *it2<< "  ";
		it2++;
	}
	cout << endl;
	cout <<"L1.front()-->" <<L1.front()<< endl;
	cout <<"L1.back()-->"<<L1.back() << endl;
}