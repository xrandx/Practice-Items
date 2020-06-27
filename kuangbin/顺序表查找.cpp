#include<stdio.h>
#include<malloc.h>
#include<string.h>
#define EQ(a,b)  ((a.number==b.number)&&!strcmp(a.Class,b.Class))
#define LT(a,b)  ((a.number< b.number)&&strcmp(a.Class,b.Class)<0)
#define LQ(a,b)  ((a.number<=b.number)&&strcmp(a.Class,b.Class)<=0)
typedef struct
{
	char Class[10];
	int number;
} keyType;

typedef struct
{
	keyType key;   //关键字域
	char name[10];
	char sex[5];
	long tele;
} SElemType;

typedef struct
{
	SElemType * elem;
	int length;
} STable;
void  _Create(STable *L)     //建立表
{
	printf("建表的长度:\n");
	scanf("%d",&L->length);
	L->elem=(SElemType *)malloc((L->length+1)*sizeof(SElemType));
	for(int i=0; i<L->length; i++)
	{
		printf("请输入第%d个记录,依次是班级,学号,姓名,性别,电话号码:\n",i+1);
		scanf("%s", L->elem[i+1].key.Class);
		scanf("%d",&L->elem[i+1].key.number);
		scanf("%s", L->elem[i+1].name);
		scanf("%s", L->elem[i+1].sex);
		scanf("%d",&L->elem[i+1].tele);
	}
}
void _Output(STable L,int i)   //输出数据
{
	printf("查找的记录为:\n");
	printf("班级为:%s\n",L.elem[i].key.Class);
	printf("学号为:%d\n ",L.elem[i].key.number);
	printf("姓名为:%s\n",L.elem[i].name);
	printf("性别为:%s\n",L.elem[i].sex);
	printf("电话号码为:%ld\n",L.elem[i].tele);
}
void _display(STable L)
{
	for(int i=1; i<L.length+1; i++)
	{
		_Output(L,i);
	}
}
int _search(STable L,keyType Key)    //顺序查找
{
	L.elem[0].key=Key;
	int w=EQ(L.elem[L.length].key,Key);
	for(int j=L.length-1; !w; --j)
	{
		w=EQ(L.elem[j].key,Key);
		return j;
	}
}
int bin_search(STable L,keyType Key)   //折半查找
{
	int low=0,hig=L.length,mid;
	while(low<=hig)
	{
		mid=(low+hig)/2;
		if(EQ(L.elem[mid].key,Key))
			return (mid);
		else if(LQ(L.elem[mid].key,Key))
			hig=mid-1;
		else
			low=mid+1;
	}
	return 0;
}
int main()
{
	STable L;
	_Create(&L);
	printf("\n");
	_display(L);
	keyType key;
	printf("请输入你要查找的记录的关键字:\n");
	printf("学号:");
	scanf("%d",&(key.number));
	printf("次关键字班级:");
	scanf("%s",key.Class);
	printf("顺序查找:\n");
	_Output(L,_search(L,key));
	printf("\n");
	printf("折半查找:\n");
	_Output(L,bin_search(L,key));
	return 0;
}

