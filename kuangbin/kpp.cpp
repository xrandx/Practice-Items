#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<string.h>
#define OK 1
#define ERROR 0
#define OVERFLOW -2
typedef int Status; // ���庯������ֵ����
typedef struct  student
{
	char num[10]; // ѧ��
	char name[20]; // ����
	double score; // �ɼ�
} student;
typedef student ElemType;//���Ա�ĵ�����洢�ṹ//
typedef struct LNode
{
	ElemType data; // ������
	struct LNode *next; //ָ����
} LNode,*LinkList;
Status InitList_kpp(LinkList &La) // ��������� La
{
	La=(struct LNode*)malloc(sizeof(struct LNode));
	La->next=NULL;
	return OK;
}
Status GetElem_kpp(LinkList L,int i,ElemType &e) // ���������ҵ� iλ�õ������򣬷��ظ� e
{
	LinkList p;
	p=L->next;                                         //��ʼ����pָ���һ����㣬jΪ������
	int j=1;
	while(p&&j<i)                                      //˳ָ�������ң�ֱ��pָ���i��Ԫ�ػ���pΪ��
	{
		p=p->next;
		++j;
	}
	if(!p||j>i)  return ERROR;                     //��i��Ԫ�ز�����
	e=p->data;                                     //ȡ��i��Ԫ��
	return OK;
}
Status Search_kpp(LNode L,char str[],LinkList &p) // ����ѧ�Ų���
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
Status ListInsert_kpp(LinkList L,int i,ElemType e)                      // �� i��λ�ò���ĳ��ѧ������Ϣ
{
	LinkList p,s;
	p=L;
	int j=0;
	while(p&&j<i-1)
	{
		p=p->next;
		++j;
	}                                                                //Ѱ�ҵ�i-1�����
	if(!p||j>i-1)    return ERROR;
	s=(struct LNode*)malloc(sizeof(LNode));                          //�����½��
	s->data=e;
	s->next=p->next;                                                       //����L��
	p->next=s;
	return OK;
}
Status ListDelete_kpp(LinkList p,int i)                        // ɾ�� iλ�õ�ѧ����Ϣ
{
	int j=0;
	while((p->next)&&(j<i-1))                                   //Ѱ�ҵ�i�����  ������pָ����ǰ��
	{
		p=p->next;
		++j;
	}
	if(!(p->next)||(j>i-1))   return ERROR;                              //ɾ��λ�ò�����
	LinkList q;
	q=p->next;
	p->next=q->next;                                                        //ɾ�����ͷŽ��
	delete q;
	return OK;
}
Status Add_kpp(LinkList Lb) // ��������� Lb
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
	printf("ѧ��:");
	scanf("%s",e->num);
	printf("����:");
	scanf("%s",e->name);
	printf("�ɼ�:");
	scanf("%lf",&e->score);
	printf("�������\n\n");
}
void Output_kpp(ElemType *e)
{
	printf("����:%-20s\nѧ��:%-10s\n�ɼ�:%-10.2lf\n\n",e->name,e->num,e->score);
}
int main()
{
	LNode L;
	LinkList p,La,Lb,Lc;
	ElemType a,b,c,d;
	printf("\n********************************\n\n");
	puts("1. ��������");
	puts("2. ¼��ѧ����Ϣ");
	puts("3. ����ѧ�ţ����Ҹ�ѧ��");
	puts("4. ��ʾĳλ�ø�ѧ����Ϣ");
	puts("5. ��ָ��λ�ò���ѧ����Ϣ");
	puts("6. ��ָ��λ��ɾ��ѧ����Ϣ");
	puts("7. ��ʾѧ����Ϣ");
	puts("8. ����һ������");
	puts("9. ����ڶ�������ѧ������Ϣ");
	puts("10. ����������ϲ�");
	puts("0. �˳�");
	printf("\n********************************\n\n");
	int x,n=-1;
	while(n!=0)
	{
		puts("��ѡ��:");
		scanf("%d",&n);
		switch(n)
		{
			case 1:
				if(InitList_kpp(p))
					printf("�ɹ���������\n\n");
				else
					printf("������ʧ��\n\n");
				break;
			case 2:
			{
				printf("������Ҫ¼��ѧ����Ϣ������:");
				scanf("%d",&x);
				for(int i=1; i<=x; i++)
				{
					printf("��%d��ѧ��:\n",i);
					Input_kpp(&a);
					ListInsert_kpp(&L,i,a);
				}
			}
			break;
			case 3:
			{
				char s[20];
				printf("������Ҫ���ҵ�ѧ��ѧ��:");
				scanf("%s",s);
				if(Search_kpp(L,s,p))
					Output_kpp(&(p->data));
				else
					puts("�Բ��𣬲��޴���");
				puts("");
			}
			break;
			case 4:
			{
				printf("������Ҫ��ѯ��λ��:");
				int id1;
				scanf("%d",&id1);
				GetElem_kpp(&L,id1,c);
				Output_kpp(&c);
			}
			break;
			case 5:
			{
				printf ("������Ҫ�����λ��:");
				int id2;
				scanf("%d",&id2);
				printf("������ѧ����Ϣ:\n");
				Input_kpp(&d);
				if(ListInsert_kpp(&L,id2,d))
				{
					x++;
					printf("����ɹ�");
					printf("");
				}
				else
				{
					puts("����ʧ��");
					puts("");
				}
			}
			break;
			case 6:
			{
				printf("������Ҫɾ����λ��:");
				int id3;
				scanf("%d",&id3);
				if(ListDelete_kpp(&L,id3))
				{
					x--;
					puts("ɾ���ɹ�");
					puts("");
				}
				else
				{
					puts("ɾ��ʧ��");
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
				printf("������ڶ�������Ҫ¼��ѧ����Ϣ������:");
				scanf("%d",&x);
				for(int i=1; i<=x; i++)
				{
					printf("��%d��ѧ��:\n",i);
					Input_kpp(&a);
					ListInsert_kpp(&L,i,a);
				}
			}
			break;
			case 9:
			{
				if(Add_kpp(p))
					printf("�ɹ���������\n\n");
				else
					printf("������ʧ��\n\n");
			}
			break;
			case 10:
			{
				//InitList_kpp(La);
				//Add_kpp(Lb);
				MergeList_kpp(La,Lb,Lc);
				printf("�ϲ�������Ϊ��\n");
			}
			printf("\n\nлл����ʹ�ã��밴������˳�\n\n\n");
			system("pause");
			return 0;


			printf("\n\nлл����ʹ�ã��밴������˳�\n\n\n");
			system("pause");
			return 0;
		}
	}
}
