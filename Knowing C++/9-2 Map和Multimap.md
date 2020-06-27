### multimap
```CPP
template<class Key, class T, class Pred = less<Key>,
class A = allocator<T> >
class multimap {
��.
typedef pair<const Key, T> value_type;
����.
}; //Key ����ؼ��ֵ�����
```
- multimap�е�Ԫ���� <�ؼ���,ֵ>��ɣ�ÿ��Ԫ����һ��pair���󣬹ؼ���
����first��Ա����,��������Key
- multimap ��������Ԫ�صĹؼ�����ͬ��Ԫ�ذ���first��Ա������С�������У�ȱʡ������� less<Key> ����ؼ��ֵġ�С�ڡ���ϵ��

```CPP
#include <iostream>
#include <map>
using namespace std;

int main()
{
	typedef multimap<int,double,less<int> > mmid;
	mmid pairs;
	cout << "1) " << pairs.count(15) << endl;
	pairs.insert(mmid::value_type(15,2.7));//typedef pair<const Key, T> value_type;
	pairs.insert(mmid::value_type(15,99.3));
	cout << "2) "<< pairs.count(15) << endl; //��ؼ���15��Ԫ�ظ����ж���
	pairs.insert(mmid::value_type(30,111.11));
	pairs.insert(mmid::value_type(10,22.22));
	pairs.insert(mmid::value_type(25,33.333));
	pairs.insert(mmid::value_type(20,9.3));
	for( mmid::const_iterator i = pairs.begin();
	        i != pairs.end() ; i ++ )
		cout << "(" << i->first << "," << i->second << ")" << ",";
	return 0;
}
// �����
// 1��0
// 2��2
// ��10,22,22������15,2.7������15,99.3������20,9.3����
// ��25,33.333������30,111.11��
```
<BR>

### Multimapʵ��Ӧ�þ�����
```
һ��ѧ���ɼ�¼��Ͳ�ѯϵͳ������һ���������룺
Add name id score
Query score
Name��һ���ַ������м�û�пո񣬴���ѧ��������id��һ������������ѧ�ţ�score��һ����������ʾ������ѧ�Ų����ظ��������������������ظ���
�������뽻����֡���һ�������ʾҪ���һ��ѧ������Ϣ�������������룬�ͼ�¼��ѧ����������id�ͷ������ڶ��������ʾҪ��ѯ�����������������������м�¼�з�����score�͵���߷ֻ���ߵ�������ѧ�š�����������ж��ѧ�������������������ѧ�������Ǹ�ѧ������Ϣ������Ҳ���������������ѧ�����������Nobody����
 
����������
Add Jack 12 78
Query 78
Query 81
Add Percy 9 81
Add Marry 8 81
Query 82
Add Tom 11 79
Query 80
Query 81
 
���������
Nobody
Jack 12 78
Percy 9 81
Tom 11 79
Tom 11 79
```

```CPP
#include <iostream>
#include <map>
#include <string>
using namespace std;

class CStudent
{
	public:
		struct CInfo
		{
			//����ڲ������Զ�����
			int id;
			string name;
		};
		int score;
		CInfo info;//ѧ����������Ϣ
};
typedef multimap<int, CStudent::CInfo>MAP_STD;

int main()
{
	MAP_STD mp;
	CStudent st;
	string cmd;
	while(cin>>cmd)
	{
		if(cmd=="Add")
		{
			cin>>st.info.name>>st.info.id>>st.score;
			mp.insert(MAP_STD::value_type(st.score,st.info));
		}
		else if(cmd=="Query")
		{
			int score;
			cin>>score;
			MAP_STD::iterator p=mp.lower_bound(score);
			//����һ������λ��it���ǵ�[begin(),it)������Ԫ�ص�first����valueС��
			if(p!=mp.begin())
			{
				--p;
				score=p->first;
				//��Ҫ��ѯ�����͵���߷�
				MAP_STD::iterator maxp=p;
				int maxId=p->second.id;
				for(; p!=mp.begin()&&p->first==score; --p)
				{
					//�������гɼ���score��ȵ�ѧ��
					if(p->second.id>maxId)
					{
						maxp=p;
						maxId=p->second.id;
					}
				}
				if(p->first==score)
				{
					//�������ѭ������Ϊp==mp.begin()
					//����ֹ����pָ���Ԫ�ػ�Ҫ����
					if(p->second.id>maxId)
					{
						maxp=p;
						maxId=p->second.id;
					}
				}
				cout<<maxp->second.name<<" "<<maxp->second.id<<" "<<maxp->first<<endl;
			}
			else
				//lower_bound�Ľ������begin��˵��û�˷����Ȳ�ѯ������
				cout<<"Nobody"<<endl;

		}
	}
	return 0;
}
```


<BR>

### map
```CPP
template<class Key, class T, class Pred = less<Key>,
class A = allocator<T> >
class map {
��.
typedef pair<const Key, T> value_type;
����.
};
```

map �е�Ԫ�ض���pairģ������󡣹ؼ���(first��Ա����)������ͬ��Ԫ
�ذ��չؼ��ִ�С�������У�ȱʡ������� less<Key>,����<�� ���塰С�ڡ���

<BR>

### map��[ ]��Ա����
��pairsΪmapģ����Ķ���
```CPP
pairs[key]
```
���ضԹؼ��ֵ���key��Ԫ�ص�ֵ(second��Ա�����������á���û�йؼ���Ϊkey��Ԫ�أ������pairs�����һ���ؼ���Ϊkey��Ԫ�أ���ֵ���޲ι��캯����ʼ����������ֵ������.

```CPP
#include <iostream>
#include <map>
using namespace std;

template <class Key,class Value>
ostream & operator <<( ostream & o, const pair<Key,Value> & p)
{
	o << "(" << p.first << "," << p.second << ")";
	return o;
}

int main()
{
	typedef map<int, double,less<int> > mmid;
	mmid pairs;
	cout << "1) " << pairs.count(15) << endl;
	pairs.insert(mmid::value_type(15,2.7));
	pairs.insert(make_pair(15,99.3)); //make_pair ����pair����
	cout << "2) " << pairs.count(15) << endl;
	pairs.insert(mmid::value_type(20,9.3));
	mmid::iterator i;
	cout << "3) ";
	for( i = pairs.begin(); i != pairs.end(); i ++ )
		cout << * i << ",";
	cout << endl;
	cout << "4) ";
	int n = pairs[40];//û��40��Ԫ�������һ�� 
	for( i = pairs.begin(); i != pairs.end(); i ++ )
		cout << * i << ",";
	cout << endl;
	cout << "5) ";
	pairs[15] = 6.28; //�ѹؼ���15��ֵ�ĳ�6.28 
	for( i = pairs.begin(); i != pairs.end(); i ++ )
		cout << * i << ",";
	return 0;
}
```