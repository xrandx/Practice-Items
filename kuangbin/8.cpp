#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

map<string, int> cnt;
vector<string> words;

string repr(const string& s)
{
	string ans = s;
	for(int i = 0; i < ans.length(); i++)
		ans[i] = tolower(ans[i]);
	sort(ans.begin(), ans.end());
	return ans;
}

int main()
{
	string s;
	while(cin >> s)
	{
		if(s[0] == '#') break;
		words.push_back(s);
		string tmp = repr(s);
		if(!cnt.count(tmp))	cnt[tmp] = 0;
		cnt[tmp]++;
	}
	vector<string> ans;
	for(int i = 0; i < words.size(); i++)
		if(cnt[repr(words[i])] == 1)
			ans.push_back(words[i]);
	sort(ans.begin(), ans.end());
	for(int i =0; i < ans.size(); i++)
	{
		cout << ans[i] << endl;
	}
	return 0;
}
