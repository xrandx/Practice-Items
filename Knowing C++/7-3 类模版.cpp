#include <iostream>
using namespace std;

template <class T1, class T2>
class Pair{
    public:
    T1 key;
    T2 value;
    Pair(T1 k, T2 v): key(k), value(v){};
    bool operator < (const Pair<T1, T2> & p)const;
};
template <class T1, class T2>
bool Pair<T1, T2>::operator < (const Pair<T1, T2> & p) const{
    return key < p.key;
}

int main()
{
    Pair<string, int> student("Tom", 19);
// 编译器由类模板生成类的过程叫类模板的实例化
// -编译器自动用具体的数据类型
// -替换类模板中的类型参数, 生成模板类的代码
// 由类模板实例化得到的类叫模板类
// -为类型参数指定的数据类型不同, 得到的模板类不同
	Pair<string, double> score("Tim", 98.5);
    cout << student.key << " "<< student.value << endl;
    
    return 0;
}
//有更多的派生关系就不详细了解了
// 类模板与继承
// 类模板派生出类模板
// 模板类 (即类模板中类型/非类型参数实例化后的类)
// 派生出类模板
// 普通类派生出类模板
// 模板类派生出普通类