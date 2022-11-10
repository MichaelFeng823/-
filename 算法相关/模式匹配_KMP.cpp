#include "string.h"
#include "stdio.h"    
#include "stdlib.h"   
#include "math.h"  
#include "time.h"

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE 100 /* 存储空间初始分配量 */

typedef int Status;		/* Status是函数的类型,其值是函数结果状态代码，如OK等 */
typedef int ElemType;	/* ElemType类型根据实际情况而定，这里假设为int */

typedef char String[MAXSIZE+1]; /*  0号单元存放串的长度 */



/*通过计算返回子串T的next数组*/
void get_next(String T,int *next)
{
	int i,j;
	i = 1;
	j = 0;
	next[1] = 0;
	while (i < T[0])                 /*此处T[0]表示串T的长度*/
	{
		if(j == 0 || T[i] == T[j])   /*T[i]表示后缀的单个字符，T[j]表示前缀单个字符*/
		{
			++i;
			++j;
			next[i] = j;
		}
		else  
			j = next[j];              /*若字符不相同，则j值回溯*/

	}
}

/*返回子串T在主串S中第pos个字符之后的位置。若不存在，则函数返回值为0*/
/*T非空，1<= pos <= StrLength(S)*/

int Index_KMP(String S,String T,int pos)
{
	int i = pos;    /*i用于住主串S当前位置下标值，若pos值不为1，则从pos值处开始匹配*/
	int j = 1;      /*j用于子串T中当前位置下标值*/
	int next[255];  /*定义一个next数组*/
	get_next(T,next);  /*对串T做分析，得到next数组*/
	while (i < S[0] && j < T[0])     /*若i小于S的长度且j小于T的长度时，循环继续*/
	{
		if(j == 0 || S[i] == T[j])   /*两字母相等则继续，与朴素算法增加了 j == 0 的判断*/
		{
			++i;
			++j;
		}
		else                         /*指针后退重新开始匹配*/
		{
			j = next[j];             /*j退回合适位置,i值不变*/
		}
		if(j > T[0])
			return i - T[0]; 
		else
			return 0;
	}
}

/*求模式串T的next函数修正值，并存入数组nextval*/
void get_nextval(String T,int *nextval)
{
	int i,j;
	i = 1;
	j = 0;
	nextval[1] = 0;

	while (i < T[0])        /*此处T[0]表示串T的长度*/
	{
		if(j == 0 || T[i] == T[j])    /*T[i]表示后缀的单个字符，T[j]表示前缀的单个字符*/
		{
			++i;
			++j;
			if(T[i] != T[j])          /*若当前字符与前缀字符不同*/
				nextval[i] = j;       /*则当前的j为nextval在i位置的值*/
			else                      /*如果与前缀字符相同，则将前缀字符的nextval值赋给nextval在i位置的值*/
				nextval[i] = nextval[j];
		}
		else
			j = nextval[j];          /*若字符不相同，则j值回溯*/
	}
}