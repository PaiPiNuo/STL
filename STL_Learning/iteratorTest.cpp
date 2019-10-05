#include <fstream>
#include <iterator>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include "iteratorTest.h"

using namespace std;

template<class T,class InputIterator,class OutputIterator>
void mySort(InputIterator first, InputIterator last,OutputIterator result) {
	vector<T> s;
	for (; first != last;first++) {
		s.push_back(*first);
	}
	sort(s.begin(),s.end());//STL: sort()--Input parameters must be "RandomAccessIterator"
	copy(s.begin(),s.end(),result);
}

void mySortTest() {
	double arr[5] = {1.2,2.4,0.8,3.3,3.2};
	mySort<double>(arr, arr+5,ostream_iterator<double>(cout," "));
	cout << endl;

	mySort<int>(istream_iterator<int>(cin),istream_iterator<int>(),ostream_iterator<int>(cout," "));
	cout << endl;
}

/*
istream_iterator<string> is(cin);
istream_iterator<string> end_of_file;
ostream_iterator<string> os(cout," ");
*/
void istream_Iterator(){
	
	istream_iterator<string> ibeg(cin);
	istream_iterator<string> iter_end;
	//copy(istream_iterator<int>(cin), istream_iterator<int>(), ostream_iterator<int>(cout, " "));
	vector<string> vec(ibeg,iter_end);
	copy(vec.begin(),vec.end(),ostream_iterator<string>(cout,"\n"));
	
	//Read txt File
	ifstream ifs("E:\\C++Test\\STL - ¸±±¾\\STL_Learning\\test.txt");
	if(ifs.is_open())
		copy(istream_iterator<string>(ifs),istream_iterator<string>(),ostream_iterator<string>(cout, "\n"));
}


