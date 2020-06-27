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
	keyType key;   //�ؼ�����
	char name[10];
	char sex[5];
	long tele;
} SElemType;

typedef struct
{
	SElemType * elem;
	int length;
} STable;
void  _Create(STable *L)     //������
{
	printf("����ĳ���:\n");
	scanf("%d",&L->length);
	L->elem=(SElemType *)malloc((L->length+1)*sizeof(SElemType));
	for(int i=0; i<L->length; i++)
	{
		printf("�������%d����¼,�����ǰ༶,ѧ��,����,�Ա�,�绰����:\n",i+1);
		scanf("%s", L->elem[i+1].key.Class);
		scanf("%d",&L->elem[i+1].key.number);
		scanf("%s", L->elem[i+1].name);
		scanf("%s", L->elem[i+1].sex);
		scanf("%d",&L->elem[i+1].tele);
	}
}
void _Output(STable L,int i)   //�������
{
	printf("���ҵļ�¼Ϊ:\n");
	printf("�༶Ϊ:%s\n",L.elem[i].key.Class);
	printf("ѧ��Ϊ:%d\n ",L.elem[i].key.number);
	printf("����Ϊ:%s\n",L.elem[i].name);
	printf("�Ա�Ϊ:%s\n",L.elem[i].sex);
	printf("�绰����Ϊ:%ld\n",L.elem[i].tele);
}
void _display(STable L)
{
	for(int i=1; i<L.length+1; i++)
	{
		_Output(L,i);
	}
}
int _search(STable L,keyType Key)    //˳�����
{
	L.elem[0].key=Key;
	int w=EQ(L.elem[L.length].key,Key);
	for(int j=L.length-1; !w; --j)
	{
		w=EQ(L.elem[j].key,Key);
		return j;
	}
}
int bin_search(STable L,keyType Key)   //�۰����
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
	printf("��������Ҫ���ҵļ�¼�Ĺؼ���:\n");
	printf("ѧ��:");
	scanf("%d",&(key.number));
	printf("�ιؼ��ְ༶:");
	scanf("%s",key.Class);
	printf("˳�����:\n");
	_Output(L,_search(L,key));
	printf("\n");
	printf("�۰����:\n");
	_Output(L,bin_search(L,key));
	return 0;
}

