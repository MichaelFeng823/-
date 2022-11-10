//#include "string.h"
//#include "stdio.h"
//#include "stdlib.h"   
//#include "math.h"  
//#include "time.h"
//#define OK 1
//#define ERROR 0
//#define TRUE 1
//#define FALSE 0
//#define MAXSIZE 40 /* 存储空间初始分配量 */
//using namespace std;
//
//typedef int Status;		/* Status是函数的类型,其值是函数结果状态代码，如OK等 */
//typedef int ElemType;	/* ElemType类型根据实际情况而定，这里假设为int */
//typedef char String[MAXSIZE+1]; /*  0号单元存放串的长度 */
//
//
///*用Sub返回串S的第pos个字符起长度为length的子串*/
//Status SubString(String Sub,String S,int pos,int len)
//{
//	int i;
//	if(pos < 1|| pos > S[0] || len < 0 || len > S[0]-pos+1)
//		return ERROR;
//	for(int i = 1;i <= len;i++)
//		Sub[i] = S[pos+i-1];
//	Sub[0] = len;
//	return OK;
//}
//
///*返回字符串元素的个数*/
//int StrLength(String S)
//{
//	return S[0];
//}
//
///*初始条件：串S和串T存在*/
///*操作结果：若S>T则返回值>0,若S=T，则返回值=0；若S<T,则返回值<0,------------循环为什么要用++i?*/
//int StrCompare(String S,String T)
//{
//	int i;
//	for(i = 1; i <= S[0]&&i <= T[0];++i)
//		if(S[i] != T[i])
//			return S[i]-T[i];
//	return S[0]-T[0];
//}
//
///*T为非空串。若主串S中第pos个字符串之后存在与T相等的字符串*/
///*则返回第一个这样的字串在S中的位置，否则返回0*/
//int Index(String S,String T,int pos)
//{
//	int n,m,i;
//	String sub;
//	if(pos > 0)
//	{
//		n = StrLength(S);     /*得到主串S的长度*/
//		m = StrLength(T);     /*得到字串T的长度*/
//		i = pos;
//		while (i <= n-m+1)
//		{
//			SubString(sub,S,i,m);   /*取主串第i个位置，长度与T相等的子串给sub*/
//
//			if(StrCompare(sub,T) != 0)    /*如果两串不相等*/
//				++i;
//			else                          /*如果两串相等，则返回i的值*/
//				return i;
//		}
//	}
//	return 0;                             /*若无子串与T相等，返回0*/
//}
//
///*T为非空串。若主串S中第pos个字符串之后存在与T相等的子串*/
///*则返回第一个这样的字串在S中的位置，否则返回0*/
//
//int Index2(String S,String T,int pos)
//{
//	int n,m,i;
//	String sub;
//	if(pos > 0)
//	{
//		n =StrLength(S);    /*得到主串S的长度*/
//		m = StrLength(T);   /*得到子串T的长度*/
//		i= pos;
//		while (i <= n-m+1)
//		{
//			SubString(sub,S,i,m);     /*取主串中第i个位置长度与T相等的子串給sub*/
//			if(StrCompare(sub,T)!=0)   /*如果两串不相等*/
//				++i;
//			else                       /*如果两串相等*/
//				return i;              //则返回i的值	
//		}
//	}
//	return 0;  /*若无子串与T相等,返回0*/
//}
//
///*初始条件:串S和T都存在* 1<= pos <= StrLength(S)+1*/
///*操作结果：在串S的第pos个字符之前插入串T,完全插入返回TRUE,部分插入返回FALSE*/
//Status StrInsert(String S,int pos,String T)
//{
//	int i;
//	if(pos < 1||pos > S[0] +1)
//		return ERROR;
//	if(S[0]+T[0] <= MAXSIZE)       /*完全插入*/
//	{
//		for(i = S[0]; i >= pos; i--)
//			S[i+T[0]] = S[i];
//		for(i = pos; i <= pos +T[0]; i++)
//			S[i] = T[i-pos+1];
//		S[0] = S[0] + T[0];
//		return TRUE;
//	}
//	else                          /*部分插入*/
//	{
//		for(i = MAXSIZE;i <= pos;i--)
//			S[i] = S[i-T[0]];
//		for(i = pos;i < pos+T[0];i++)
//			S[i] = T[i-pos+1];
//		S[0] = MAXSIZE;
//		return FALSE;
//	}
//}
///*若S为空串，则返回TRUE,否则返回FALSE*/
//Status StrEmpty(String S)
//{
//	if(S[0] == 0)
//		return true;
//	else
//		return false;
//}
//
//Status ClearString(String S)
//{
//	S[0] = 0;   /*令串长为0*/
//	return OK;
//}
//
///*生成一个其值等于chars的串T*/
//Status StrAssign(String T,char *chars)
//{
//	int i;
//	if(strlen(chars) > MAXSIZE)
//		return ERROR;
//	else
//	{
//		T[0] = strlen(chars);
//		for(i = 1; i <= T[0];i++)
//			T[i] = *(chars+i-1);
//		return OK;
//	}
//}
///*由S复制得串T*/
//Status StrCopy(String S,String T)
//{
//	int i;
//	for(i = 0;i <= S[0];i++)
//		T[i] = S[i];
//	return OK;
//}
///*用T返回S1和S2联接而成的新串，若未截断则返回true,否则返回FALSE*/
//Status StrConcat(String T,String S1,String S2)
//{
//	int i;
//	if(S1[0]+S2[0] <= MAXSIZE)     /*未截断*/
//	{
//		for(i = 1; i <= S1[0]; i++)
//			T[i] = S1[i];
//		for(i = 1; i < S2[0]; i++)
//			T[S1[0]+i] = S2[i];
//		T[0] = S1[0] + S2[0];
//		return TRUE;
//	}
//	else                           /*截断S2*/
//	{
//		for(i = 1; i <= S1[0]; i++)
//			T[i] = S1[i];
//		for(i = 1; i <= MAXSIZE - S1[0];i++)
//			T[S1[0]+1] = S2[i];
//		T[0] = MAXSIZE;
//		return FALSE;
//	}
//}
//
///*输出字符串T*/
//void StrPrint(String T)
//{
//	int i;
//	for(i = 1;i < T[0]; i++)
//		printf("%c",T[i]);
//	printf("\n");
//}
///*  初始条件: 串S存在,1≤pos≤StrLength(S)-len+1 */
///*  操作结果: 从串S中删除第pos个字符起长度为len的子串 */
//Status StrDelete(String S,int pos,int len)
//{
//	int i;
//	if(pos < 1 || pos > S[0]-len+1 || len < 0)
//		return ERROR;
//	for(i = pos + len; i <= S[0]; i++)
//		S[i-len] = S[i];
//	return OK;
//}
//
///*初始条件：串S,T和V存在，T是非空串（此函数与串的存储结构无关）*/
///*操作结果：用V替换主串S中所出现的所有与T相等的不重叠的子串*/
//
//Status Replace(String S,String T,String V)
//{
//	int i = 1;    /*从串S的第一个字符起查找串T*/
//	if(StrEmpty(T))  /*T是空串*/
//		return ERROR;
//	do
//	{
//		i = Index(S,T,i);   /*结果i为从上一个i之后找到的子串T的位置*/
//		if(i)               /*串S中存在串T*/
//		{
//			StrDelete(S,i,StrLength(T));    /*删除该串T*/
//			StrInsert(S,i,V);               /*在原串T的位置插入串V*/
//			i+=StrLength(V);                /*在插入的串V后面继续查找串T*/
//		}
//	}while (i);
//	return OK;
//}
//
//int main()
//{
//	int i,j;
//	Status k;
//	char s;
//	String t,s1,s2;
//	printf("请输入串s1: ");
//	
//	k=StrAssign(s1,"abcd");
//	if(!k)
//	{
//		printf("串长超过MAXSIZE(=%d)\n",MAXSIZE);
//		exit(0);
//	}
//	printf("串长为%d 串空否？%d(1:是 0:否)\n",StrLength(s1),StrEmpty(s1));
//	StrCopy(s2,s1);
//	printf("拷贝s1生成的串为: ");
//	StrPrint(s2);
//	printf("请输入串s2: ");
//	
//	k=StrAssign(s2,"efghijk");
//	if(!k)
//	{
//		printf("串长超过MAXSIZE(%d)\n",MAXSIZE);
//		exit(0);
//	}
//	i=StrCompare(s1,s2);
//	if(i<0)
//		s='<';
//	else if(i==0)
//		s='=';
//	else
//		s='>';
//	printf("串s1%c串s2\n",s);
//	k=StrConcat(t,s1,s2);
//	printf("串s1联接串s2得到的串t为: ");
//	StrPrint(t);
//	if(k==FALSE)
//		printf("串t有截断\n");
//	ClearString(s1);
//	printf("清为空串后,串s1为: ");
//	StrPrint(s1);
//	printf("串长为%d 串空否？%d(1:是 0:否)\n",StrLength(s1),StrEmpty(s1));
//	printf("求串t的子串,请输入子串的起始位置,子串长度: ");
//
//	i=2;
//	j=3;
//	printf("%d,%d \n",i,j);
//
//	k=SubString(s2,t,i,j);
//	if(k)
//	{
//		printf("子串s2为: ");
//		StrPrint(s2);
//	}
//	printf("从串t的第pos个字符起,删除len个字符，请输入pos,len: ");
//	
//	i=4;
//	j=2;
//	printf("%d,%d \n",i,j);
//
//
//	StrDelete(t,i,j);
//	printf("删除后的串t为: ");
//	StrPrint(t);
//	i=StrLength(s2)/2;
//	StrInsert(s2,i,t);
//	printf("在串s2的第%d个字符之前插入串t后,串s2为:\n",i);
//	StrPrint(s2);
//	i=Index(s2,t,1);
//	printf("s2的第%d个字母起和t第一次匹配\n",i);
//	SubString(t,s2,1,1);
//	printf("串t为：");
//	StrPrint(t);
//	StrConcat(s1,t,t);
//	printf("串s1为：");
//	StrPrint(s1);
//	Replace(s2,t,s1);
//	printf("用串s1取代串s2中和串t相同的不重叠的串后,串s2为: ");
//	StrPrint(s2);
//
//	system("pause");
//	return 0;
//}