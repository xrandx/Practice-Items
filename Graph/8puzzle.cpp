#include <iostream>
#include <cstring>
#include <cstdio>
#include <string>
using namespace std;
typedef int state[9];
const int maxstate = 1000000;

state st[maxstate], goal = {1, 2, 3, 4, 5, 6, 7, 8, 0};

int bfs()
{
//    init_look_up();
    int front = 1, rear = 2;
    while(front < rear)
    {
        state& s = st[front];

    }
}


int main()
{
    char ch;
    state& s = st[1];
    for(int i = 0; i < 9; i++)
    {
        scanf("%c", &ch);
        if(ch >= 1 && ch <= 9)
            s[i] = ch - '0';
        else
            s[i] = 0;
    }

}
