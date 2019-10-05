#include <list>
#include <map>
#include <set>
#include <deque>
#include <vector>
#include <iterator>
#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>
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

void list_Splice() {
	string name1[] = {"Alice","Hellen","Lucy","Susan"};
	string name2[] = {"Bob","David","Levin","Mike"};
	list<string> s1(name1, name1+ 4);
	list<string> s2(name2, name2+4);

	s2.splice(s2.end(),s1,s1.begin());
	list<string>::iterator itera1 = s1.begin();
	advance(itera1,2);
	list<string>::iterator itera2 = s2.begin();
	++itera2;
	list<string>::iterator itera3 = itera2;
	advance(itera3,2);
	s1.splice(itera1,s2,itera2,itera3);

	copy(s1.begin(),s1.end(),ostream_iterator<string>(cout," "));
	cout << endl;
	copy(s2.begin(),s2.end(),ostream_iterator<string>(cout," "));
	cout << endl;
	
}

void dequeTest() {
	istream_iterator<int> in(cin), inEnd;
	vector<int> vect(in,inEnd);
	sort(vect.begin(),vect.end());
	deque<int> deq;
	for (vector<int>::iterator itera = vect.begin(); itera != vect.end();itera++) {
		if (0 == *itera % 2)
			deq.push_back(*itera);
		else
			deq.push_front(*itera);
	}

	copy(deq.begin(),deq.end(),ostream_iterator<int>(cout," "));
	cout << endl;
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

void mapTest2() {
	map<string, int> courses;
	courses.insert(make_pair("CSAPP",3));
	courses.insert(make_pair("C++",2));
	courses.insert(make_pair("CSARCH",4));
	courses.insert(make_pair("COMPILER",4));
	courses.insert(make_pair("OS",5));
	map<string, int>::iterator iteraTemp = courses.begin();
	for (; iteraTemp!=courses.end();iteraTemp++) {
		cout << iteraTemp->first<<"   "<<iteraTemp->second << endl;
	}

	int n = 3;
	int sum = 0;
	while (n>0) {
		string name;
		cin >> name;
		map<string,int>::iterator itera=courses.find(name);
		if (itera==courses.end()) {
			cout << name<<" is not available"<< endl;
		}
		else {
			sum += itera->second;
			courses.erase(itera);
			n--;
		}
	}
	cout << "Total credit:"<<sum<< endl;
}
/*
Count the number of occurrences of each letter in a sentence
*/
void Map_charNum() {
	map<char, int> s;
	char c;
	do {
		cin >> c;
		if (isalpha(c)) {
			c = tolower(c);
			s[c]++;
		}
	} while (c!='.');

	for (map<char, int>::iterator itera = s.begin(); itera != s.end();itera++) {
		cout <<itera->first<<"  "<<itera->second << endl;
	}
}

void multimapTest() {
	multimap<string, string> courses;
	typedef multimap<string, string>::iterator CourseIteraT;
	CourseIteraT CourseItera;
	courses.insert(make_pair("C++","2-6"));
	courses.insert(make_pair("OS","1-2"));
	courses.insert(make_pair("COMPILER","3-1"));
	courses.insert(make_pair("OS","5-5"));
	courses.insert(make_pair("COMPILER","5-2"));
	courses.insert(make_pair("OS","5-1"));
	for (CourseItera = courses.begin(); CourseItera != courses.end(); CourseItera++) {
		cout << CourseItera->first << "  " << CourseItera->second << endl;
	}

	string name;
	int count=0;
	do {
		cin >> name;
		count = courses.count(name);
		if (0 == count)
			cout << "Cannot find this course!"<< endl;
	} while (count==0);
	cout << count<<" lessons per week"<< endl;
	pair<CourseIteraT, CourseIteraT> range = courses.equal_range(name);
	for (CourseIteraT itera = range.first; itera != range.second; itera++) {
		cout << itera->first <<" " << itera->second<< endl;
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

void setTest2() {
	set<double> s;
	double v;
	while (true) {
		cin >> v;
		if (0 == v)
			break;
		pair<set<double>::iterator, bool> iter = s.insert(v);
		if (!iter.second)
			cout << v << "is duplicated" << endl;
	}

	set<double>::iterator itera1 = s.begin();
	set<double>::iterator itera2 = s.end();
	double medium = (*itera1 + *(--itera2)) / 2;
	cout << "<=medium: ";
	copy(itera1,s.upper_bound(medium),ostream_iterator<double>(cout," "));
	cout << endl;
	cout << ">=medium: ";
	copy(s.lower_bound(medium),s.end(),ostream_iterator<double>(cout," "));
	cout << endl;	
	
}