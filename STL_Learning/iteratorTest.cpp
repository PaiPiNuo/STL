//#include <fstream>
//#include <iterator>
//#include <vector>
//#include <iostream>
//#include <algorithm>


//using namespace std;
/*
istream_iterator<string> is(cin);
istream_iterator<string> end_of_file;
ostream_iterator<string> os(cout," ");
*/
//void istream_Iterator(){
//	ifstream ifs("E:\\C++\\STL - 副本\\STL_Learning\\test.txt");
//	istream_iterator<string> ibeg(cin);
//	istream_iterator<string> iter_end;
//	vector<string> vec(ibeg,iter_end);
//
//	copy(vec.begin(),vec.end(),ostream_iterator<string>(cout,"\n"));
//}

#include <iostream>
#include <iterator>
//#include <fstream>
#include <vector>
#include <algorithm>
#include "iteratorTest.h"

using namespace std;
 
int istream_Iterator()
{
    //ifstream ifs("test.txt");
	vector<int> vec;
    istream_iterator<int> ibeg(cin),eos;
	copy(ibeg,eos,inserter(vec,vec.begin()));
    //istream_iterator<string> iend;
    //vector<string> vec(ibeg, iend);
    // 和在一起
    // vector<string> vec((istream_iterator<string>(ifs)), istream_iterator<string>());
 
   //copy(istream_iterator<char>(cin), istream_iterator<char>(),ostream_iterator<string>(cout, "\n"));
    
   return 0;
}