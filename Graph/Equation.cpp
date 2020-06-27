#include<bits/stdc++.h>
using namespace std;

const int maxn = 666;
typedef long long ll;

ll gcd(ll a,ll b) { return b?gcd(b,a%b):a; }

struct Fra
{
    ll p,q;
    Fra(ll x = 0,ll y = 1):p(x),q(y){ normal(p,q); }
    void normal(ll &p,ll &q) { ll g = gcd(p,q); p/=g; q/=g; }
    Fra operator = (int x) {  p = x; q = 1; return *this; }
    Fra operator = (ll x) { p = x; q = 1; return *this; }
    Fra operator - () { return {-p,q}; }
    Fra operator + (Fra &r) {
        ll m,n;
        m = p*r.q+r.p*q;
        n = q*r.q;
        normal(m,n);
        return {m,n};
    }
    Fra operator += (Fra& r) { return *this = *this+r; }
    Fra operator - (Fra &r) { return (-r) + *this; }
    Fra operator -= (Fra &r) { return *this = *this-r; }
    Fra operator * (Fra &r) {
        ll m,n;
        m = p*r.p;
        n = q*r.q;
        normal(m,n);
        return {m,n};
    }
    Fra operator *= (Fra &r) { return (*this) = (*this)*r; }
    Fra operator /(Fra &r) { return Fra(r.q,r.p) * (*this); }
    Fra operator /=(Fra &r) { return (*this) = (*this)/r; }
    bool operator == (const Fra& r) const { return p*r.q == r.p*q; }
    bool operator < (Fra& r) { return  p*r.q < r.p*q; }
    void print() { normal(p,q); if(q<0)q = -q,p = -p; printf("%lld/%lld\n",p,q); }
};


struct Node
{
    Node* l,*r;
    Fra f; char op;
    bool fx;
    Node(){};
    Node(Fra &v,Node*a = NULL, Node*b = NULL):f(v),l(a),r(b){};

}nd[maxn];

bool isOp[256];
char rev[256];

Fra cal(Fra &x,Fra &y,char op)
{
    //assert(isOp[op] == true)
    switch(op){
        case '+':return x+y;
        case '-': return x-y;
        case '*': return x*y;
        case '/': return x/y;
    }
    return {233,1};
}

Fra ans;

void calRev(Fra &x,char op)
{
    switch(op){
        case'+':ans-=x; return;
        case'*':ans/=x; return ;
        case'-':ans = x-ans; return;
        case'/':ans = x/ans; return;
    }
}

//之前要预处理
bool dfs(Node* u)
{
    //*u;
    if(u->l == NULL) return true;
    //assert(u.r)
    if(u->l->fx){
        ans = cal(ans,u->r->f,rev[u->op]); //乘以0的情况已经预处理了
        if(!dfs(u->l)) return false;
    }else if(u->r->fx) {
        calRev(u->l->f,u->op);//移项，ans本身可能会是0
        if(ans.q == 0) { return false; }
        if(!dfs(u->r)) return false;
    }
    return true;
}

Node* read(char ch)
{
    int cnt = 0;
        stack<Node*> stk;
        do{
            while(ch == ' ')ch = getchar();
            Node &cur = nd[cnt];
            if(isOp[ch]){
                cur.op = ch;
                cur.r = stk.top(); stk.pop();
                cur.l = stk.top(); stk.pop();
                cur.fx = cur.l->fx || cur.r->fx;
                if(cur.fx){ //系数为0的处理
                    if((cur.op == '*' && (cur.r->fx ? cur.l->f == 0 : cur.r->f == 0))
                    || (cur.op == '/' && cur.r->fx && cur.l->f == 0) ) {
                        cur.fx = false;
                        cur.f = 0; cur.l = cur.r = NULL;
                    }
                }else { //预处理，边读边算
                    cur.f = cal(cur.l->f,cur.r->f,cur.op);
                    cur.l = cur.r = NULL;
                }
            }else {
                if(ch == 'X'){
                    cur.fx = true;
                }else {
                    cur.fx = false;
                    int data = ch-'0';
                    while(ch = getchar(), ch>='0'&&ch<='9') data = data*10+ch-'0';
                    cur.f = data;
                }
                cur.l = cur.r = NULL;
            }
            stk.push(nd+cnt);
            ch = getchar(); cnt++;
        }while(ch != '\n'&&~ch);
    return stk.top();
}

int main()
{
    //freopen("in.txt","r",stdin);
    isOp['+'] = isOp['-'] = isOp['*'] = isOp['/'] = true;
    rev['+'] = '-'; rev['-'] = '+'; rev['*'] = '/'; rev['/'] = '*';
    char head;
    while(~(head = getchar())){
        Node* root = read(head);
        if(!root->fx) {
            if(root->f == 0) puts("MULTIPLE");
            else puts("NONE");
            continue;
        }
        ans = 0;
        if(dfs(root)){ printf("X = "); ans.print(); }
        else {puts("NONE"); continue; }
    }
    return 0;
}

/*
1 X / /
1 X 2 - / /
X /
X * 1 +
X / 1 +
9 9 9 9 9 9 9 9 9 9 9 9 X 1 * * * * * * * * * * * * * +
6 - 8 / 8 2 * / 0 3 - + 5 5 1 / + 1 X 2 + + 8 8 + + * +
8 X + * 1 8 5 7 3 + * * 7 6 6 / 3 + + 6 5 7 / - * / / +
*/
