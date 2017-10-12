#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <windows.h>

const double INFINITY = 1e9;
const int MAXN = 1000;

typedef enum { num,
			   opr,
			   end
} Type;

typedef struct double_stack_node
{
	double *arrptr;
	int top;
	int maxsize;
} * doustkptr, doustk;

typedef struct char_stack_node
{
	char *arrptr;
	int top;
	int maxsize;
} * chstkptr, chstk;

doustkptr DouCreate(int maxsize)
{
	doustkptr s = (doustkptr)malloc(sizeof(doustk));
	s->arrptr = (double *)malloc(maxsize * sizeof(double));
	s->top = -1;
	s->maxsize = maxsize;
	return s;
}

chstkptr ChCreate(int maxsize)
{
	chstkptr s = (chstkptr)malloc(sizeof(chstk));
	s->arrptr = (char *)malloc(maxsize * sizeof(char));
	s->top = -1;
	s->maxsize = maxsize;
	return s;
}

bool DouIsFull(doustkptr s)
{
	return (s->top == s->maxsize - 1);
}

bool ChIsFull(chstkptr s)
{
	return (s->top == s->maxsize - 1);
}

bool DouPush(doustkptr s, double i)
{
	if (DouIsFull(s))
	{
		printf("堆栈满。");
		return false;
	}
	else
	{
		s->arrptr[++(s->top)] = i;
		return true;
	}
}

bool ChPush(chstkptr s, char i)
{
	if (ChIsFull(s))
	{
		printf("堆栈满。");
		return false;
	}
	else
	{
		s->arrptr[++(s->top)] = i;
		return true;
	}
}

bool DouIsEmpty(doustkptr s)
{
	if (s->top == -1)
		return true;
	else
		return false;
}

bool ChIsEmpty(chstkptr s)
{
	if (s->top == -1)
		return true;
	else
		return false;
}

double DouPop(doustkptr s)
{
	if (DouIsEmpty(s))
	{
		printf("堆栈空。");
		return 0;
	}
	else
		return s->arrptr[(s->top)--];
}

char ChPop(chstkptr s)
{
	if (ChIsEmpty(s))
	{
		printf("堆栈空。");
		return 0;
	}
	else
		return s->arrptr[(s->top)--];
}

char ChTop(chstkptr s)
{
	if (ChIsEmpty(s))
	{
		//printf("堆栈空。");
		return 0;
	}
	else
		return s->arrptr[(s->top)];
}

void TransformToPostfixExp(char *Input, char *Expr)
{
	char ch, tmp;
	int i = 0;
	int j = 0;
	chstkptr transtk;
	transtk = ChCreate(MAXN);
	while (1)
	{
		ch = Input[j++];
		if (ch == '\0')
		{
			while (!ChIsEmpty(transtk))
			{
				Expr[i++] = ' '; //加空格
				Expr[i++] = ChPop(transtk);
			}
			Expr[i] = '\0';
			break;
		}
		if (isdigit(ch) || ch == '.')
			Expr[i++] = ch;
		else
		{
			switch (ch)
			{
			case '(':
				ChPush(transtk, ch);
				break;
			case ')':
				while (ChTop(transtk) != '(')
				{
					Expr[i++] = ' '; //加空格
					Expr[i++] = ChPop(transtk);
				}
				if (ChTop(transtk) == '(')
					ChPop(transtk);
				break;
			case '+':
			case '-':
				while (ChTop(transtk) == '+' || ChTop(transtk) == '-' || ChTop(transtk) == '*' || ChTop(transtk) == '/')
				{
					Expr[i++] = ' '; //加空格
					Expr[i++] = ChPop(transtk);
				}
				if (ChIsEmpty(transtk) || ChTop(transtk) == '(')
				{
					Expr[i++] = ' '; //加空格
					ChPush(transtk, ch);
				}
				break;
			case '*':
			case '/':
				while (ChTop(transtk) == '*' || ChTop(transtk) == '/')
				{
					Expr[i++] = ' ';
					Expr[i++] = ChPop(transtk);
				}
				if (ChIsEmpty(transtk) || ChTop(transtk) == '(' || ChTop(transtk) == '+' || ChTop(transtk) == '-')
				{
					Expr[i++] = ' ';
					ChPush(transtk, ch);
				}
				break;
			}
		}
	}
}

Type GetOp(char *Expr, int &start, char *str)
{
	int i = 0;
	while ((str[0] = Expr[start++]) == ' ')
		;
	while (str[i] != ' ' && str[i] != '\0')
		str[++i] = Expr[start++];
	if (str[i] == '\0')
		start--;
	str[i] = '\0';

	if (i == 0)
		return end;
	else if (isdigit(str[0]) || isdigit(str[1]))
		return num;
	else
		return opr;
}

double ComputePostfixExp(char *Expr)
{
	doustkptr S;
	Type T;
	double op1, op2;
	char str[MAXN];
	int start = 0;
	S = DouCreate(MAXN);
	op1 = op2 = 0.0;
	while ((T = GetOp(Expr, start, str)) != end)
	{
		if (T == num)
			DouPush(S, atof(str));
		else
		{
			if (!DouIsEmpty(S))
				op2 = DouPop(S);
			else
				op2 = INFINITY;
			if (!DouIsEmpty(S))
				op1 = DouPop(S);
			else
				op1 = INFINITY;
			switch (str[0])
			{
			case '+':
				DouPush(S, op1 * 1.0 + op2 * 1.0);
				break;
			case '-':
				DouPush(S, op1 * 1.0 - op2 * 1.0);
				break;
			case '*':
				DouPush(S, op1 * 1.0 * op2 * 1.0);
				break;
			case '/':
				if (op2 != 0.0)
					DouPush(S, op1 * 1.0 / op2 * 1.0);
				else
				{
					printf("错误：除法分母为零\n");
					op2 = INFINITY;
				}
				break;
			default:
				printf("错误：未知运算符%s\n", str);
				op2 = INFINITY;
				break;
			}
			if (op2 >= INFINITY)
				break;
		}
	}
	if (op2 < INFINITY)
		if (!DouIsEmpty(S))
			op2 = DouPop(S);
		else
			op2 = INFINITY;
	free(S);
	return op2;
}

int main()
{
	printf("\n输入表达式 | ");
	char Input[MAXN];
	char Expr[MAXN];
	double result;
	gets(Input);
	TransformToPostfixExp(Input, Expr);
	printf("后缀表达式 | %s", Expr);
	result = ComputePostfixExp(Expr);
	if (result < INFINITY)
		printf("\n  运算结果 | %.4lf\n", result);
	else
		printf("\n表达式错误。");
	printf("\n");
	system("pause");
	return 0;
}
