/* 20161506146 ���轣  */ 
/* Windows 10 / Dev C++ / VScode */

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>

typedef struct StudentElem
{
	int id;
	char name[20];
	double score;
} stu;

typedef struct StudentList
{
	stu data;
	int elemF;
	struct StudentList *next;
} stul;

void LoopCLS()
{
	getchar();
	printf("\n�س��Է��ز˵���\n");
	while(getchar()!='\n');
	system("cls");
	return;
}

stul* InitList(stul *h)
{
	h = (stul*)malloc(sizeof(stul));
	h->next = NULL;
	h->elemF = 1;
	return h;
}

void Destroy(stul *h)
{
	free(h);
	h = NULL;
}

/*
stul* ClearList(stul *h)
{
	if(h)
	{
		free(h);
		h = (stul*)malloc(sizeof(stul));
		return h;
	}
	else
	{
		printf(" 0");
		return NULL;
	}
}

int ListEmpty(stul *h)
{
	if(h->next)
	{
		return 1;
	}
	else
		return 0;
}
*/

int ListLength(stul *h)
{
	stul *p;
	int i = 0;
	p = h->next;
	while(p)
	{
		i++;
		p = p->next;
	}
	return i;
}

int GetElem(stul *h, int i)
{
	stul *p = h;
	if(i<1 || i> h->elemF-1)
	{
		printf("����λ������\n");
		return 0;
	}
	while(i--)
	{
		p = p->next;
	}
	printf("\nѧ�ţ�%d\n", p->data.id);
	printf("������%s\n", p->data.name);
	printf("�ɼ���%.2lf\n", p->data.score);
	return 1;
}

int ElemFind(stul *h)
{
	int op = 2;
	stu ef;
	stul *p;
	p = h->next;
	printf("����1��ѧ�Ų��ң�����0����������:\n");
	while(op != 1 && op!= 0)
		scanf("%d", &op);
	if(op)
	{
		printf("����ѧ�ţ�");
		scanf("%d", &ef.id);
	}
	else
	{
		printf("����������");
		scanf("%s", &ef.name);
	}
	if(op)
	{
		while(p && ef.id != p->data.id)
			p = p->next;
		if(p)
		{
			printf("%d\n", p->data.id);
			printf("%s\n", p->data.name);
			printf("%.2lf\n", p->data.score);
			return 1;
		}
		else
		{
			printf("δ�ҵ�Ԫ�ء�");
			return 0;
		}
	}
	else
	{
		while(p && strcmp(ef.name,p->data.name))
		{
			p = p->next;
		}
		if(p)
		{
			printf("ѧ��: %d\n", p->data.id);
			printf("������%s\n", p->data.name);
			printf("�ɼ���%.2lf\n", p->data.score);
			return 1;
		}
		else
		{
			printf("δ�ҵ�Ԫ�ء�");
			return 0;
		}
	}
}

int CreateElem(stul *h)
{
	//����ͷ�巨
	stul *tmp;
	tmp = h->next;
	h->next = (stul*)malloc(sizeof(stul));
	printf("\n������:\n");
	printf("ѧ��: ");
	scanf("%d", &h->next->data.id);
	printf("����: ");
	scanf("%s", h->next->data.name);
	printf("�ɼ�: ");
	scanf("%lf", &h->next->data.score);
	h->next->next = tmp;
	h->elemF++;
	return 1;
}

int ViewElem(stul *h)
{
	stul *p = h->next;
	if(!p)
	{
		printf("��Ԫ�ؿɲ鿴��");
		return 0;
	}
	while(p)
	{
		printf("\nѧ�ţ�%d\n", p->data.id);
		printf("������%s\n", p->data.name);
		printf("�ɼ���%.2lf\n\n", p->data.score);
		p = p->next;
	}
	return 1;
}

int InsertList(stul *h, int i)
{
	stul *p = h;
	stul *tmp;
	if(i<1 || i> h->elemF-1)
	{
		printf("����λ������\n");
		return 0;
	}
	i--;
	while(i--)
	{
		p = p->next;
	}
	tmp = p->next;
	p->next = (stul*)malloc(sizeof(stul));
	h->elemF++;
	printf("������:\n");
	printf("ѧ��:");
	scanf("%d", &p->next->data.id);
	printf("����:");
	scanf("%s", p->next->data.name);
	printf("�ɼ���");
	scanf("%lf", &p->next->data.score);
	p->next->next = tmp;
	return 1;
}

int DeleteElem(stul *h, int i)
{
	stul *p = h;
	stul *tmp;
	if(i<1 || i> h->elemF-1)
	{
		printf("ɾ��λ������\n");
		return 0;
	}
	i--;
	while(i--)
	{
		p = p->next;
	}
	tmp = p->next->next;
	free(p->next);
	p->next = tmp;
	h->elemF--;
	return 1;
}

void MergeList(stul *h, stul *h2)
{
	stul *p;
	p = h;
	while(1)
	{
		if(!p->next)
			break;
		p = p->next;
	}
	p->next = h2->next;
	return;
}

int ModifyElem(stul *h, int i)
{
	stul *p = h;
	if(i<1 || i> h->elemF-1)
	{
		printf("λ������\n");
		return 0;
	}
	while(i--)
	{
		p = p->next;
	}
	printf("���ҵ���������:\n");
	printf("ѧ�ţ�");
	scanf("%d", &p->data.id);
	printf("������");
	scanf("%s", p->data.name);
	printf("�ɼ���");
	scanf("%lf", &p->data.score);

}
void menu()
{
	printf("1.�½�����Ԫ��\n");
	printf("2.��������Ԫ��\n");
	printf("3.ɾ������Ԫ��\n");
	printf("4.����Ų�������Ԫ��\n");
	printf("5.������ѧ�Ų���Ԫ��\n");
	printf("6.�޸�����Ԫ��\n");
	printf("7.�鿴Ԫ�ظ���\n");
	printf("8.�������Ԫ��\n");
	printf("9.�½������ϲ�\n");
	printf("\n0.��������ڴ沢�˳�\n");
}

int main()
{
	stul *h;
	h = NULL;
	int i;
	int op;
	if(h = InitList(h))
		printf("��ʼ������ɹ���\n");
	while(1)
	{
		menu();
		scanf("%d", &op);
		switch(op)
		{
			case 1:
				system("cls");
				if(CreateElem(h))
					printf("������ϡ�\n");
				break;
			case 2:
				system("cls");
				printf("�������Ԫ��λ��:");
				scanf("%d",&i);
				if(InsertList(h, i))
					printf("������ϡ�");
				break;
			case 3:
				system("cls");
				printf("����ɾ��Ԫ��λ��:");
				scanf("%d",&i);
				if(DeleteElem(h, i))
					printf("ɾ����ϡ�");
				break;
			case 4:
				system("cls");
				printf("�������Ԫ��λ��:");
				scanf("%d",&i);
				if(GetElem(h, i))
					printf("��ϡ�");
				break;
			case 5:
				system("cls");
				if(ElemFind(h))
					printf("��ϡ�\n");
				break;
			case 6:
				system("cls");
				printf("����Ԫ��λ��:");
				scanf("%d",&i);
				if(ModifyElem(h, i))
					printf("��ϡ�\n");
				break;
			case 7:
				system("cls");
				printf("Ԫ�ظ���Ϊ %d ��\n", ListLength(h));
				printf("��Ϊ %d ��", h->elemF);
				break;
			case 8:
				system("cls");
				ViewElem(h);
				break;
			case 9:
				system("cls");
				stul* h2;
				int n;
				h2 = InitList(h2);
				printf("�����½�Ԫ�ظ���:");
				scanf("%d",&n);
				for(i=0; i<n; i++)
				{
					CreateElem(h2);
				}
				MergeList(h, h2);
				break;
			case 0:
				system("cls");
				Destroy(h);
				exit(1);
				break;
			default:
				system("cls");
				printf("����ʧ��");
				break;
		}
		LoopCLS();
	}


	return 0;
}


