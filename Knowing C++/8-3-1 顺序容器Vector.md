- 可变长的动态数组
- 必须包含头文件 #include < vector >
- 所有STL算法 都能对vector操作

#### 支持随机访问迭代器
    * 根据下标随机访问某个元素时间为常数
    * 在尾部添加速度很快
    * 在中间插入慢
<br>
### vector的成员函数
<br>
- 构造函数初始化

| 成员函数 | 作 用 |
| :----------- | :--- |
vector(); | 无参构造函数, 将容器初始化成空的
vector(int n); |将容器初始化成有n个元素
vector(int n,const T & val);| 假定元素类型是T, 将容器初始化成有n个元素, 每个元素的值都是val
vector(iterator first, iterator last);|将容器初始化为与别的容器上区间[first, last)一致的内容

- 其他常用函数

成员函数 | 作 用
| :----------- | :--- |
void pop_back();|删除容器末尾的元素
void push_back(const T & val); |将val添加到容器末尾
int size(); |返回容器中元素的个数
T & font(); |返回容器中第一个元素的引用
T & back(); |返回容器中最后一个元素的引用

```CPP
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int a[5] = {1, 2, 3, 4, 5};
	vector<int> v(5);//每个初始化为0
	cout << v.end() - v.begin() << endl;
	vector<int> v2(5, 5);
	v2.at(4) = 6;//at有错误提示
	vector<int> v3(a, a+5);//左闭右开区间
	for(int i = 0; i < v3.size(); i++)
		cout << v3[i] << " ";
	cout << endl;
	v3.insert(v3.begin() + 2, 8);
	for(int i = 0; i < v3.size(); i++)
		cout << v3[i] << " ";
	vector< vector<int> > v4(6);
	for(int i = 0; i < v4.size(); i++)
		for(int j = 0; j < 6; j++ )
			v4[i].push_back(j);
	for(int i = 0; i < v4.size(); i++)
	{
		for(int j = 0; j < 6; j++ )
			cout << v4[i][j];
		cout << endl;
	}
	return 0;
}

```
