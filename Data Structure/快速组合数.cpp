#include <iostream>
//�����ŵ㣺ȫ���μ��㡣
//ʱ�临�Ӷȣ�O��min(m,n-m)��
//�ռ临�Ӷȣ�O��1��
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
