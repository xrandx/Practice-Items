#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <cstdlib>
#include <sstream>
using namespace std;

const int dq = -1; 

struct player
{
	int pro;
	string name, place;
	double money;
	int RD[4];
	int NO;
};

vector<player> all;


inline void read()
{
	int n;
	cin >> n;
	int t = n;
	all.clear();
	string line;
	while(n--)
	{
		getline(cin, line);
		player add;
		add.name = line.substr(0, 20);
		add.pro = 1;
		for(int i = add.name.length(); i > 1; i++)
		{
			if(isalpha(add.name[i]))
				break;
			else if(add.name[i] == ' ')
				add.name.erase(i);
			else if(add.name[i] == '*')
				add.pro = 0;
		}
		if(line.substr(21, 2) != "DQ")
		{
			stringstream ss(line.substr(21, 2));
			ss >> add.RD[0];
		}
		else add.RD[0] = dq;
//		if(line.substr(24, 2) != "DQ")
//			add.RD[1] = stoi(line.substr(24, 2));
//		else add.RD[1] = dq;
//		if(line.substr(27, 2) != "DQ")
//			add.RD[2] = stoi(line.substr(24, 2));
//		else add.RD[2] = dq;
//		if(line.substr(30, 2) != "DQ")
//			add.RD[3] = stoi(line.substr(24, 2));
//		else add.RD[3] = dq;
//		all.push_back(add);
	}
	for(int i = 0; i < t; i++)
	{
		cout << all[i].name << " " << all[i].RD[0] << endl;
	}
}

int main()
{
	freopen("pga.txt", "r", stdin);
	read();
}
