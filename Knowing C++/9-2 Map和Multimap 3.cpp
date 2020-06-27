#include <iostream>
#include <map>
using namespace std;

template <class Key,class Value>
ostream & operator <<( ostream & o, const pair<Key,Value> & p)
{
	o << "(" << p.first << "," << p.second << ")";
	return o;
}

int main()
{
	typedef map<int, double,less<int> > mmid;
	mmid pairs;
	cout << "1) " << pairs.count(15) << endl;
	pairs.insert(mmid::value_type(15,2.7));
	pairs.insert(make_pair(15,99.3)); //make_pair 生成pair对象
	cout << "2) " << pairs.count(15) << endl;
	pairs.insert(mmid::value_type(20,9.3));
	mmid::iterator i;
	cout << "3) ";
	for( i = pairs.begin(); i != pairs.end(); i ++ )
		cout << * i << ",";
	cout << endl;
	cout << "4) ";
	int n = pairs[40];//没有40的元素则插入一个 
	for( i = pairs.begin(); i != pairs.end(); i ++ )
		cout << * i << ",";
	cout << endl;
	cout << "5) ";
	pairs[15] = 6.28; //把关键字15的值改成6.28 
	for( i = pairs.begin(); i != pairs.end(); i ++ )
		cout << * i << ",";
	return 0;
}
