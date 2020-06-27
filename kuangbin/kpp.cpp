#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<string.h>
#define OK 1
#define ERROR 0
#define OVERFLOW -2
typedef int Status; // 定义函数返回值类型
typedef struct  student
{
	char num[10]; // 学号
	char name[20]; // 姓名
	double score; // 成绩
} student;
typedef student ElemType;//线性表的单链表存储结构//
typedef struct LNode
{
	ElemType data; // 数据域
	struct LNode *next; //指针域
} LNode,*LinkList;
Status InitList_kpp(LinkList &La) // 构造空链表 La
{
	La=(struct LNode*)malloc(sizeof(struct LNode));
	La->next=NULL;
	return OK;
}
Status GetElem_kpp(LinkList L,int i,ElemType &e) // 访问链表，找到 i位置的数据域，返回给 e
{
	LinkList p;
	p=L->next;                                         //初始化，p指向第一个结点，j为计数器
	int j=1;
	while(p&&j<i)                                      //顺指针向后查找，直到p指向第i个元素或者p为空
	{
		p=p->next;
		++j;
	}
	if(!p||j>i)  return ERROR;                     //第i个元素不存在
	e=p->data;                                     //取第i个元素
	return OK;
}
Status Search_kpp(LNode L,char str[],LinkList &p) // 根据学号查找
{
	p=L.next;
	while(p)
	{
		if(strcmp(p->data.num,str)==0)
			return OK;
		p=p->next;
	}
	return ERROR;
}
Status ListInsert_kpp(LinkList L,int i,ElemType e)                      // 在 i个位置插入某个学生的信息
{
	LinkList p,s;
	p=L;
	int j=0;
	while(p&&j<i-1)
	{
		p=p->next;
		++j;
	}                                                                //寻找第i-1个结点
	if(!p||j>i-1)    return ERROR;
	s=(struct LNode*)malloc(sizeof(LNode));                          //生成新结点
	s->data=e;
	s->next=p->next;                                                       //插入L中
	p->next=s;
	return OK;
}
Status ListDelete_kpp(LinkList p,int i)                        // 删除 i位置的学生信息
{
	int j=0;
	while((p->next)&&(j<i-1))                                   //寻找第i个结点  ，并另p指向其前驱
	{
		p=p->next;
		++j;
	}
	if(!(p->next)||(j>i-1))   return ERROR;                              //删除位置不合理
	LinkList q;
	q=p->next;
	p->next=q->next;                                                        //删除并释放结点
	delete q;
	return OK;
}
Status Add_kpp(LinkList Lb) // 构造空链表 Lb
{
	Lb=(struct LNode*)malloc(sizeof(struct LNode));
	Lb->next=NULL;
	return OK;
}
Status MergeList_kpp(LinkList &La,LinkList &Lb,LinkList &Lc)
{
	LinkList pa,pb,pc;
	pa=La->next;
	pb=Lb->next;
	Lc=pc=La;
	while(pa&&pb)
	{
		if(pa->data.num<=pb->data.num)
		{
			pc->next=pa;
			pc=pa;
			pa=pa->next;
		}
		else
		{
			pc->next=pa;
			pc=pb;
			pb=pb->next;
		}
	}
	pc->next=pa?pa:pb;
	free(Lb);
	return OK;
}
void Input_kpp(ElemType *e)
{
	printf("学号:");
	scanf("%s",e->num);
	printf("姓名:");
	scanf("%s",e->name);
	printf("成绩:");
	scanf("%lf",&e->score);
	printf("输入完成\n\n");
}
void Output_kpp(ElemType *e)
{
	printf("姓名:%-20s\n学号:%-10s\n成绩:%-10.2lf\n\n",e->name,e->num,e->score);
}
int main()
{
	LNode L;
	LinkList p,La,Lb,Lc;
	ElemType a,b,c,d;
	printf("\n********************************\n\n");
	puts("1. 构造链表");
	puts("2. 录入学生信息");
	puts("3. 输入学号，查找该学生");
	puts("4. 显示某位置该学生信息");
	puts("5. 在指定位置插入学生信息");
	puts("6. 在指定位置删除学生信息");
	puts("7. 显示学生信息");
	puts("8. 新增一个链表");
	puts("9. 输入第二个链表学生的信息");
	puts("10. 将两个链表合并");
	puts("0. 退出");
	printf("\n********************************\n\n");
	int x,n=-1;
	while(n!=0)
	{
		puts("请选择:");
		scanf("%d",&n);
		switch(n)
		{
			case 1:
				if(InitList_kpp(p))
					printf("成功建立链表\n\n");
				else
					printf("链表建立失败\n\n");
				break;
			case 2:
			{
				printf("请输入要录入学生信息的人数:");
				scanf("%d",&x);
				for(int i=1; i<=x; i++)
				{
					printf("第%d个学生:\n",i);
					Input_kpp(&a);
					ListInsert_kpp(&L,i,a);
				}
			}
			break;
			case 3:
			{
				char s[20];
				printf("请输入要查找的学生学号:");
				scanf("%s",s);
				if(Search_kpp(L,s,p))
					Output_kpp(&(p->data));
				else
					puts("对不起，查无此人");
				puts("");
			}
			break;
			case 4:
			{
				printf("请输入要查询的位置:");
				int id1;
				scanf("%d",&id1);
				GetElem_kpp(&L,id1,c);
				Output_kpp(&c);
			}
			break;
			case 5:
			{
				printf ("请输入要插入的位置:");
				int id2;
				scanf("%d",&id2);
				printf("请输入学生信息:\n");
				Input_kpp(&d);
				if(ListInsert_kpp(&L,id2,d))
				{
					x++;
					printf("插入成功");
					printf("");
				}
				else
				{
					puts("插入失败");
					puts("");
				}
			}
			break;
			case 6:
			{
				printf("请输入要删除的位置:");
				int id3;
				scanf("%d",&id3);
				if(ListDelete_kpp(&L,id3))
				{
					x--;
					puts("删除成功");
					puts("");
				}
				else
				{
					puts("删除失败");
					puts("");
				}
			}
			break;
			case 7:
			{
				for(int i=1; i<=x; i++)
				{
					GetElem_kpp(&L,i,b);
					Output_kpp(&b);
				}
			}
			break;
			case 8:
			{
				printf("请输入第二个链表要录入学生信息的人数:");
				scanf("%d",&x);
				for(int i=1; i<=x; i++)
				{
					printf("第%d个学生:\n",i);
					Input_kpp(&a);
					ListInsert_kpp(&L,i,a);
				}
			}
			break;
			case 9:
			{
				if(Add_kpp(p))
					printf("成功建立链表\n\n");
				else
					printf("链表建立失败\n\n");
			}
			break;
			case 10:
			{
				//InitList_kpp(La);
				//Add_kpp(Lb);
				MergeList_kpp(La,Lb,Lc);
				printf("合并后链表为：\n");
			}
			printf("\n\n谢谢您的使用，请按任意键退出\n\n\n");
			system("pause");
			return 0;


			printf("\n\n谢谢您的使用，请按任意键退出\n\n\n");
			system("pause");
			return 0;
		}
	}
}
