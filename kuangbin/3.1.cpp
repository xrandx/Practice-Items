#include <cstdio>  
#include <cstring>  
#include <algorithm>  
#include <queue>  
using namespace std;
//优先队列中的元素   
struct Item  
{  
    int Qnum, Period, Time;  
    //重要！ 优先级比较函数。优先级高的先出队   
    bool operator < (const Item& a) const   
    {       //请注意，这里的const必不可少  
        return Time > a.Time || (Time == a.Time && Qnum > a.Qnum);   
    }
};
  
int main()  
{  
    priority_queue<Item> pq;  
    char s[20];  
    while(scanf("%s", s) && s[0] != '#')  
    { 
        Item item;  
        scanf("%d %d", &item.Qnum, &item.Period);  
        item.Time = item.Period;        //初始化“下一次事件的时间”为它的周期   
        pq.push(item);  
    }  
      
    int K;  
    scanf("%d", &K);  
    while(K--)  
    {  
        Item r = pq.top();  //取下一个事件   
        pq.pop();  
        printf("%d\n", r.Qnum);   
        r.Time += r.Period;     //更新该触发器的“下一个事件”的时间   
        pq.push(r);             //重新插入优先队列   
    }  
    return 0;  
}  
