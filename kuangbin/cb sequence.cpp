/* 20161506146 16�� ���轣 */
/* Windows 10   Dev C++*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

typedef struct StudentStructure
{
	int id;
	char name[20];
	double score;
} stu;

typedef struct StudentSequenceList
{
	stu *base;
	int elemFinalNum;
} stusql;

int InitList(stusql &L)
{
	L.base = (stu *)malloc(sizeof(stu));
	if (!L.base)
	{
		printf("��ʼ������\n");
		return 0;
	}
	L.elemFinalNum = 1; //��β��һ��Ԫ�ص���� = ��
	return 1;
}

int CreateElem(stusql &L, stu e)
{
	stu *newbase;
	newbase = (stu *)realloc(L.base, (L.elemFinalNum + 1) * sizeof(stu));
	if (!newbase)
	{
		printf("�����ڴ����\n");
		return 0;
	}
	L.base = newbase;
	L.base[L.elemFinalNum] = e;
	L.elemFinalNum++;
	return 1;
}

int InsertList(stusql &L, int i)
{
	stu e;
	if (!(i >= 1 && i <= L.elemFinalNum))
	{
		printf("����λ�ò���ȷ��\n");
		return 0;
	}
	printf("ѧ��:");
	scanf("%d", &e.id);
	printf("����:");
	scanf("%s", e.name);
	printf("�ɼ�:");
	scanf("%lf", &e.score);
	stu *newbase;
	newbase = (stu *)realloc(L.base, (L.elemFinalNum + 1) * sizeof(stu));
	if (!newbase)
	{
		printf("�����ڴ����\n");
		return 0;
	}
	L.base = newbase;
	L.elemFinalNum++;

	stu *q = &(L.base[i]);
	stu *p = &(L.base[L.elemFinalNum - 1]);

	while (p >= q)
	{
		*(p + 1) = *p;
		p--;
	}
	*q = e;
	return 1;
}

int DestroyList(stusql &L)
{
	if (!L.base)
	{
		printf("��ϢΪ��.\n");
		return 0;
	}
	free(L.base);
	L.base = NULL;
}

int DispalyList(stusql &L)
{
	if (L.elemFinalNum == 1)
	{
		printf("��ǰ����Ϣ�ɲ鿴.\n");
		return 0;
	}
	stu *p = &(L.base[1]);
	stu *q = &(L.base[L.elemFinalNum - 1]);
	while (p <= q)
	{
		printf("\nѧ�ţ� %d\n", p->id);
		printf("������ %s\n", p->name);
		printf("�ɼ��� %.2lf\n\n", p->score);
		p++;
	}
	return 1;
}

int ListDelete(stusql &L)
{
	int i;
	printf("�������Ϊ��");
	scanf("%d", &i);
	if (L.elemFinalNum == 1)
	{
		printf("��ϢΪ�ա�\n");
		return 0;
	}
	if (!(i >= 1 && i < L.elemFinalNum))
	{
		printf("ɾ��λ�ò���ȷ��\n");
		return 0;
	}
	stu *p = &(L.base[i]);
	stu *q = &(L.base[L.elemFinalNum - 1]);
	while (p < q)
	{
		*p = *(p + 1);
		p++;
	}
	printf("ɾ���ɹ���\n");
	L.elemFinalNum--;
	return 1;
}

int ListLenth(stusql &L)
{
	return (L.elemFinalNum - 1);
}

int SearchList(stusql &L)
{
	system("cls");
	int i;
	printf("�������Ϊ��");
	scanf("%d", &i);
	if (i >= L.elemFinalNum || i < 1)
	{
		printf("�����������\n");
		return 0;
	}
	stu *p = &(L.base[i]);
	printf("\nѧ�ţ� %d\n", p->id);
	printf("������ %s\n", p->name);
	printf("�ɼ��� %.2lf\n\n", p->score);
	return 1;
}

stu *ListFind(stusql &L)
{
	int op = 0;
	int flag;
	stu e;
	while (!op)
	{
		printf("\n1.��ѧ�Ų��ҡ�");
		printf("\n2.���������ҡ�\n");
		scanf("%d", &op);
		if (op == 1)
		{
			printf("\n������ѧ�ţ�");
			scanf("%d", &e.id);
			break;
		}
		else if (op == 2)
		{
			printf("\n������������");
			scanf("%s", e.name);
			break;
		}
		else
		{
			op = 0;
			printf("��������");
		}
	}
	stu *p = &L.base[1];
	stu *q = &L.base[L.elemFinalNum - 1];
	flag = 0;
	if (op == 1)
	{
		while (flag == 0 && p <= q)
		{
			if (p->id == e.id)
			{
				flag = 1;
				break;
			}
			else
			{
				p++;
			}
		}
	}
	else if (op == 2)
	{
		while (flag == 0 && p <= q)
		{
			if (!strcmp(e.name, p->name))
			{
				flag = 1;
				break;
			}
			else
				p++;
		}
	}
	else
	{
		printf("��������");
	}
	if (flag)
		return p;
	else
		printf("��������");
}

void Menu()
{
	printf("\n/* 20161506146 16�� ���轣 */\n\n");
	printf("1.�½���Ϣ\n");
	printf("2.������Ϣ\n");
	printf("3.���ҽ��\n");
	printf("4.���������Ϣ����ʼ��\n");
	printf("5.�鿴������Ϣ\n");
	printf("6.��ӡ��ϢԪ�س���\n");
	printf("7.ɾ��Ԫ��\n");
	printf("8.����Ԫ��\n");
	printf("\n-1.�˳�\n");
}

void LoopMenu()
{
	printf("==========\n");
	printf("����س����ز˵�:");
	getchar();
	while (getchar() != '\n')
		;
	system("cls");
}

int main()
{
	stusql h;
	stu e;
	stu *fe;
	int i;
	int n;
	if (InitList(h))
		printf("\n˳����ʼ���ɹ���\n\n");
	while (1)
	{
		Menu();
		printf("\n��������Լ���:");
		scanf("%d", &n);
		switch (n)
		{
		case 1:
			system("cls");
			printf("�½���Ϣ:\n");
			printf("ѧ��:");
			scanf("%d", &e.id);
			printf("����:");
			scanf("%s", &e.name);
			printf("�ɼ�:");
			scanf("%lf", &e.score);
			if (CreateElem(h, e))
				printf("�����ɹ���\n");
			LoopMenu();
			break;
		case 2:
			system("cls");
			printf("������Ϣ:\n");
			printf("�������Ϊ:\n");
			scanf("%d", &i);
			if (InsertList(h, i))
				printf("����ɹ���\n");
			LoopMenu();
			break;
		case 3:
			system("cls");
			if (SearchList(h))
				printf("������ϡ�\n");
			LoopMenu();
			break;
		case 4:
			system("cls");
			if (DestroyList(h))
			{
				printf("������ϡ�\n�ٴγ�ʼ��...");
				if (InitList(h))
					printf("\n˳����ʼ���ɹ���\n\n");
			}

			LoopMenu();
			break;

		case 5:
			system("cls");
			if (DispalyList(h))
				printf("\n");
			LoopMenu();
			break;
		case 6:
			system("cls");
			printf("Ԫ�ظ���ΪΪ%d\n", ListLenth(h));
			LoopMenu();
			break;
		case 7:
			system("cls");
			if (ListDelete(h))
				printf("\n");
			LoopMenu();
			break;
		case 8:
			system("cls");
			fe = ListFind(h);
			printf("\nѧ�ţ� %d\n", fe->id);
			printf("������ %s\n", fe->name);
			printf("�ɼ��� %.2lf\n\n", fe->score);
			LoopMenu();
			break;
		case -1:
			exit(0);
		default:
			system("cls");
		}
	}

	free(h.base);
	return 0;
}
