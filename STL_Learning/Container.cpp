#include <list>
#include <map>
#include <set>
#include <iostream>
#include <string>
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

void mapTest(){
	map<int,string> map_Int_Str;
	//add data to map_Int_Str
	pair<int,string> value(1,"first");
	map_Int_Str.insert(value);
	map_Int_Str[3]="Third";
	map_Int_Str.insert(map<int,string>::value_type(2,"Second"));
	
	map<int,string>::iterator intStr_itera=map_Int_Str.begin();
	for(;intStr_itera!=map_Int_Str.end();intStr_itera++){
		cout<<intStr_itera->first<<"  :  "<<intStr_itera->second<<endl;
	}

	string tmpStr=map_Int_Str[2];
	cout<<tmpStr<<endl;
	
	//find function
	map<int, string>::iterator intStr_Itera2 = map_Int_Str.find(3);
	if (intStr_Itera2!= map_Int_Str.end()) {
		cout << "Found it   " << intStr_Itera2->second << endl;
	}
	map<int, string>::iterator intStr_Itera3 = map_Int_Str.find(4);
	if (intStr_Itera3== map_Int_Str.end()) {
		cout << "Sorry,Not Found it!"<< endl;
	}
	
	pair<string, int> data1("bcf",2);
	pair<string, int> data2("abf", 1);
	pair<string, int> data3("cdf", 3);
	map<string, int> mapStrInt;
	mapStrInt.insert(data1);
	mapStrInt.insert(data2);
	mapStrInt.insert(data3);
	map<string, int>::iterator ite = mapStrInt.begin();
	for (; ite != mapStrInt.end();ite++) {
		cout << ite->first << "  " << ite->second << endl;
	}
}

void setTest() {
	set<string> S;
	S.insert("bad");
	S.insert("acf");
	S.insert("csd");
	set<string>::iterator ite = S.begin();
	for (; ite != S.end();ite++) {
		cout << *ite<< "  ";
	}
	
	
}