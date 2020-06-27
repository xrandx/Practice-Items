#include <iostream>
//代码优点：全整形计算。
//时间复杂度：O（min(m,n-m)）
//空间复杂度：O（1）
long long cal(int n, int m)
{
    long long i, a, b, p;
    if(n < m)
    {
        i = m;
        m = n;
        n = i;
    }
    p = 1;
    a = n - m < m? n - m : m;
    b = n - m > m? n - m : m;
    for(i = 1; i <= a; i++)
        p += p * b / i;
    return p;
}

int main()
{
    std::cout << cal(25,52);
}
