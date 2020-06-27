#include<bits/stdc++.h>
using namespace std;


const int maxn = 666;
typedef long long ll;


ll gcd(ll a, ll b)
{
    return b ? gcd(b, a % b) : a;
}

struct Fra
{
    ll p, q;
    Fra(ll _p = 0, ll _q = 1):p(_p), q(_q)
    {
        normal(p, q);
    }
    void normal(ll& p, ll& q)
    {
        ll g = gcd(p, q);
        p /= g ;
        q /= g;
    }
    Fra operator = (int x)
    {
        p = x;
        q = 1;
        return *this;
    }
    Fra operator = (ll x)
    {
        p = x;
        q = 1;
        return *this;
    }
    Fra operator - ()
    {
        return {-p, q};   //���ظ���
    }
    Fra operator + ( Fra& r)
    {
        ll m, n;
        m = p * r.q + r.p * q;
        n = q * r.q;//��ĸ���
        normal(m, n);
        return {m, n};
    }
    Fra operator += (Fra& r)
    {
        return *this = *this + r;
    }
    Fra operator - ( Fra& r)
    {
        return (-r) + *this ;   //���ﲻ��const
    }
    Fra operator -= ( Fra& r)
    {
        return *this = *this - r;
    }
    Fra operator * ( Fra& r)
    {
        ll m,n;
        m = p * r.p;
        n = q * r.q;
        normal(m, n);
        return {m, n};
    }
    Fra operator *= ( Fra& r)
    {
        return (*this) = (*this) * r;
    }
    Fra operator / ( Fra& r )
    {
        return Fra(r.q,r.p) * (*this);
    }
    Fra operator /= ( Fra& r)
    {
        return (*this) = (*this) / r;
    }
    bool operator == (const Fra& r) const
    {
        return (p * r.q == r.p * q);      //ͨ�ֱȽ�
    }
    bool operator < ( Fra& r)
    {
        return (p * r.q < r.p * q);      //ͨ�ֱȽ�
    }
    void print()
    {
        normal(p, q);
        if(q < 0)
        {
            p = -p;
            q = -q;
        }
        printf("%lld/%lld", p, q);
    }

};


struct Node
{
    bool fx;
    Node *l, *r;
    Fra f;
    char op;
    Node() {};
    Node(Fra& _f, Node* a = NULL, Node* b = NULL):f(_f), l(a), r(b) {};
} nd[maxn];

bool isOp[256];
char rev[256];



Fra cal(Fra& l, Fra& r, char op)
{
    switch(op)
    {
    case '+':
        return l + r;
    case '-':
        return l - r;
    case '*':
        return l * r;
    case '/':
        return l / r;
    }
    return {233,1};//��֪����ʲô��
}
Fra ans;
void calRev(Fra& x, char op)
{
    switch(op)
    {
//        case '+': ans -= x; return;
//        case '-': ans += x; return;
//        case '*': ans /= x; return;
//        case '/': ans *= x; return;
    case'+':
        ans-=x;
        return;
    case'*':
        ans/=x;
        return ;
    case'-':
        ans = x-ans;
        return;
    case'/':
        ans = x/ans;
        return;
    }
}

bool dfs(Node* u)
{
    if(u->l == NULL) return true; //������
    if(u->l->fx)
    {
        ans = cal(ans, u->r->f, rev[u->op]);// �൱��Ų����ʽ�ұ�
        if(!dfs(u->l)) return false; //��������������   false������
    }
    else if(u->r->fx)
    {
        calRev(u->l->f, u->op);//������Ҳ������
        if(ans.q == 0) return false; //
        if(!dfs(u->r)) return false; //��������������  false������
    }
    return true;
}

Node* read(char ch)
{
    int cnt = 0;
    stack<Node*> stk;
    do
    {
        while(ch == ' ') ch = getchar();
        Node& cur = nd[cnt];
        if(isOp[ch])
        {
            cur.op = ch;
            //cur.fx = false;��
            cur.r = stk.top();
            stk.pop();
            cur.l = stk.top();
            stk.pop();
            cur.fx = cur.r->fx || cur.l->fx;
            if(cur.fx)
            {
                if((cur.op == '*' && (cur.r->fx ? cur.l->f == 0: cur.r->f == 0))
                        || (cur.op == '/' && cur.r->fx && cur.l->f == 0) ) //xϵ��Ϊ��
                {
                    cur.fx = false;//����
                    cur.f = 0;
                    cur.l = cur.r = NULL; // ����
                }
            }
            else
            {
                cur.f = cal(cur.l->f, cur.r->f, cur.op);
                cur.l = cur.r = NULL;
            }
        }
        else
        {
            if(ch == 'X')
                cur.fx = true;
            else
            {
                cur.fx = false;
                int data = ch - '0';
                while(ch = getchar(), ch <= '9' && ch >= '0')
                {
                    data = 10 * data + ch - '0';
                }
                cur.f = data;//����
            }
            cur.l = cur.r = NULL;
        }
        ch = getchar();
        stk.push(nd + cnt);
        cnt++;
    }
    while(ch != '\n' && ~ch);
    return stk.top();
}
int main()
{
    isOp['+'] = isOp['-'] = isOp['*'] = isOp['/'] = true;
    rev['+'] = '-';
    rev['-'] = '+';
    rev['*'] = '/';
    rev['/'] = '*';
    char head;
    while(~(head = getchar()))
    {
        Node* root = read(head);
        if(!root->fx)
        {
            if(root->f == 0)
                puts("MULTIPLE");
            else
                puts("NONE");
            continue;
        }
        else
        {
            ans = 0;
            if(dfs(root))
            {
                printf("X = ");
                ans.print();
            }
            else puts("NONE");
        }
    }
    return 0;

}
