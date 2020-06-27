#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <cstdlib>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include <vector>
using namespace std;

const int dq = -1;
const int DQ = 5000000;
double prize_all, prize[140];
struct player
{
    int total2, total4;
    int pro;
    string name, place;
    double money;
    int RD[4];
    int no;
};

vector<player> all;

void read_prize()
{
    cin >> prize_all;
    for(int i = 0; i != 70; ++i)
    {
        cin >> prize[i];
        prize[i] = prize[i] / 100.0 * prize_all;
    }
}

int strtonum(const string &s)
{
    int d = 0;
    for(string::const_iterator it = s.begin(); it != s.end(); ++it) d = d * 10 + (*it - '0');
    return d;
}

void read()
{
    int n;
    cin >> n;
    int t = n;
    all.clear();
    string line;
    getline(cin, line);
    while(n--)
    {
        line.clear();
        getline(cin, line);
        player add;
        add.name = line.substr(0, 20);
        line = line.substr(20, line.length());
        add.pro = 1;
        for(int i = add.name.length() - 1; i > 0; i--)
        {
            if(isalpha(add.name[i]))
            {
                add.name.erase(i + 1);
                break;
            }
            else if(add.name[i] == '*')
            {
                add.pro = 0;
                add.name.erase(i);
            }
        }
        //cout << add.name;
        istringstream ss(line);
        for(int i = 0; i < 4; i++)
            add.RD[i] = DQ;
        for(int i = 0; i != 4; ++i)
        {
            ss >> line;
            if(line == "DQ") break;
            else add.RD[i] = strtonum(line);
        }
        for(int i = 0; i != 2; i++) add.total2 += add.RD[i];
        for(int i = 0; i != 4; i++) add.total4 += add.RD[i];
        all.push_back(add);
    }

//    for(int i = 0; i < t; i++)
//    {
//        cout << all[i].name << " " << all[i].RD[3] << endl;
//    }
}

void printans()
{
    cout << "Player Name          Place     RD1  RD2  RD3  RD4  TOTAL     Money Won" << '\n';
    cout << "-----------------------------------------------------------------------" << endl;
    for(vector<player>::iterator it = all.begin(); it != all.end(); ++it)
    {
        cout << it->name << ' ';
        cout << left << setw(9) << (it->total4 >= DQ ? " " : it->place);
        for(int i = 0; i != 4; ++i)
        {
            if(it->RD[i] != DQ) cout << ' ' << left << setw(4) << it->RD[i];
            else cout << ' ' << left << setw(4) << ' ';
        }
        if(it->total4 >= DQ) cout << ' ' << "DQ";
        else
        {
            cout.precision(2);
            cout.setf(ios::fixed);
            if(it->pro && it->no < 70 && !(it->money < 0))
            {
                cout << ' ' << left << setw(10) << it->total4 << '$' << right << setw(9) << it->money + 1e-8;
            }
            else
            {
                cout << ' ' << it->total4;
            }
        }
        cout << '\n';
    }
}

int cmp2(const player &a, const player &b)
{
    if(a.total2 != b.total2) return a.total2 < b.total2;
    else return a.name < b.name;
}

int cmp4(const player &a, const player &b)
{
    if(a.total4 != b.total4) return a.total4 < b.total4;
    else return a.name < b.name;
}

void select()
{
    int d = 0, sum = 0;
    sort(all.begin(), all.end(), cmp2);
    for(vector<player>::iterator it = all.begin(); d != 70 && it != all.end() &&
     (it->RD[0] != DQ && it->RD[1] != DQ);++it)
    {
        sum++, d++;//sum总数 d名次
        if(d == 70)
        {
            int last = it->total2;
            ++it;
            while(it != all.end() && it->total2 == last) ++sum, ++it;//最后的名次
            break;
        }
    }
    all.resize(sum);
    sort(all.begin(), all.end(), cmp4);
}

void getmoney() {
    int place = 0;
    for(vector<player>::iterator it = all.begin(); it != all.end(); ++it) it->money = -1, it->no = -1;
    for(vector<player>::iterator it = all.begin(), next; it != all.end() && (it->total4 < DQ) && place < 70; ++it)
        if(it->pro) {
        next = findnext(it);
    }
    for(vector<player>::iterator it = player.begin(), next; it != player.end() && (it->total4 < DQ) && place < 70; ++it) if(it->pro) {
        next = findnext(it);
        int d = 1; double sum = prize[place];
        it->no = place;
        while(next != player.end() && next->total4 == it->total4) {
            next = findnext(next);
            ++d, ++place;
            next->no = it->no;
            if(place < 70) sum += prize[place];
        }
        sum /= d;
        while(it != next) {
            if(it->pro) it->money = sum;
            ++it;
        }
        it = next - 1;
        ++place;
    }
}


int main()
{
    freopen("pga.txt", "r", stdin);
    read_prize();
    read();
    select();
}
