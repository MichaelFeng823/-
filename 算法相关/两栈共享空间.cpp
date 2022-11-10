//#include"stdio.h"
//#include"stdlib.h"
//using namespace std;
//
//
//#define MAXSIZE 10 /* 存储空间初始分配量 */
//
//#define OK 1
//#define ERROR 0
//#define TRUE 1
//#define FALSE 0
//
//typedef int Status;           /* Status是函数的类型,其值是函数结果状态代码，如OK等 */
//
//typedef int SElemType;    /*SElemType类型根据实际情况而定，这里假设为Int*/
//typedef struct SqDoubleStack 
//{
//	SElemType data[MAXSIZE];
//	int top1;               /*栈1栈顶指针*/
//	int top2;               /*栈2栈顶指针*/
//
//};
//
//Status visit(SElemType c)
//{
//        printf("%d ",c);
//        return OK;
//}
//
///*  构造一个空栈S */
//Status InitStack(SqDoubleStack *S)
//{ 
//        S->top1=-1;
//        S->top2=MAXSIZE;
//        return OK;
//}
//
///* 把S置为空栈 */
//Status ClearStack(SqDoubleStack *S)
//{ 
//        S->top1=-1;
//        S->top2=MAXSIZE;
//        return OK;
//}
//
///* 若栈S为空栈，则返回TRUE，否则返回FALSE */
//Status StackEmpty(SqDoubleStack S)
//{ 
//        if (S.top1==-1 && S.top2==MAXSIZE)
//                return TRUE;
//        else
//                return FALSE;
//}
//
///* 返回S的元素个数，即栈的长度 */
//int StackLength(SqDoubleStack S)
//{ 
//        return (S.top1+1)+(MAXSIZE-S.top2);
//}
//
//
///*插入元素e为新的栈顶元素*/
//Status Push(SqDoubleStack * S,SElemType e,int stacknumber)
//{
//	if(S->top1+1 == S->top2)        /*栈已满，不能再Push新元素了*/
//		return ERROR;
//	if(stacknumber == 1)            /*栈1有元素进栈*/
//		S->data[++S->top1] = e;     /*若栈1则先给top1+1后给数组元素赋值*/
//	else if(stacknumber == 2)       /*栈2有元素进栈*/
//
//		S->data[--S->top2] = e;     /*若栈2则先给top2-1后给数组元素赋值*/
//	return OK;
//}
//
//
///*若栈不空，则删除S的栈顶元素，用e返回其值，并返回OK,否则返回Error*/
//Status Pop(SqDoubleStack * S, SElemType * e,int StackNumber)
//{
//	if(StackNumber == 1)
//	{
//		if(S->top1 == -1)       /*说明栈1已经是空栈,溢出*/
//			return ERROR;
//		*e = S->data[S->top1--];  /*将栈1的栈顶元素出栈*/
//	}
//	else if(StackNumber == 2)
//	{
//		if(S->top2 == -1)       /*说明栈2已经是空栈,溢出*/
//			return ERROR;
//		*e = S->data[S->top2++];  /*将栈2的栈顶元素出栈*/
//	}
//	return OK;
//}
//
//Status StackTraverse(SqDoubleStack S)
//{
//        int i;
//        i=0;
//        while(i<=S.top1)
//        {
//                visit(S.data[i++]);
//        }
//        i=S.top2;
//        while(i<MAXSIZE)
//        {
//                visit(S.data[i++]);
//        }
//        printf("\n");
//        return OK;
//}
//
//int main()
//{
//        int j;
//        SqDoubleStack s;
//        int e;
//        if(InitStack(&s)==OK)
//        {
//                for(j=1;j<=5;j++)
//                        Push(&s,j,1);
//                for(j=MAXSIZE;j>=MAXSIZE-2;j--)
//                        Push(&s,j,2);
//        }
//
//        printf("栈中元素依次为：");
//        StackTraverse(s);
//
//        printf("当前栈中元素有：%d \n",StackLength(s));
//
//        Pop(&s,&e,2);
//        printf("弹出的栈顶元素 e=%d\n",e);
//        printf("栈空否：%d(1:空 0:否)\n",StackEmpty(s));
//
//        for(j=6;j<=MAXSIZE-2;j++)
//                Push(&s,j,1);
//
//        printf("栈中元素依次为：");
//        StackTraverse(s);
//
//        printf("栈满否：%d(1:否 0:满)\n",Push(&s,100,1));
//
//        
//        ClearStack(&s);
//        printf("清空栈后，栈空否：%d(1:空 0:否)\n",StackEmpty(s));
//
//		system("pause");
//        
//        return 0;
//}
