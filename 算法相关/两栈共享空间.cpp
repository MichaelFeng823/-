//#include"stdio.h"
//#include"stdlib.h"
//using namespace std;
//
//
//#define MAXSIZE 10 /* �洢�ռ��ʼ������ */
//
//#define OK 1
//#define ERROR 0
//#define TRUE 1
//#define FALSE 0
//
//typedef int Status;           /* Status�Ǻ���������,��ֵ�Ǻ������״̬���룬��OK�� */
//
//typedef int SElemType;    /*SElemType���͸���ʵ������������������ΪInt*/
//typedef struct SqDoubleStack 
//{
//	SElemType data[MAXSIZE];
//	int top1;               /*ջ1ջ��ָ��*/
//	int top2;               /*ջ2ջ��ָ��*/
//
//};
//
//Status visit(SElemType c)
//{
//        printf("%d ",c);
//        return OK;
//}
//
///*  ����һ����ջS */
//Status InitStack(SqDoubleStack *S)
//{ 
//        S->top1=-1;
//        S->top2=MAXSIZE;
//        return OK;
//}
//
///* ��S��Ϊ��ջ */
//Status ClearStack(SqDoubleStack *S)
//{ 
//        S->top1=-1;
//        S->top2=MAXSIZE;
//        return OK;
//}
//
///* ��ջSΪ��ջ���򷵻�TRUE�����򷵻�FALSE */
//Status StackEmpty(SqDoubleStack S)
//{ 
//        if (S.top1==-1 && S.top2==MAXSIZE)
//                return TRUE;
//        else
//                return FALSE;
//}
//
///* ����S��Ԫ�ظ�������ջ�ĳ��� */
//int StackLength(SqDoubleStack S)
//{ 
//        return (S.top1+1)+(MAXSIZE-S.top2);
//}
//
//
///*����Ԫ��eΪ�µ�ջ��Ԫ��*/
//Status Push(SqDoubleStack * S,SElemType e,int stacknumber)
//{
//	if(S->top1+1 == S->top2)        /*ջ������������Push��Ԫ����*/
//		return ERROR;
//	if(stacknumber == 1)            /*ջ1��Ԫ�ؽ�ջ*/
//		S->data[++S->top1] = e;     /*��ջ1���ȸ�top1+1�������Ԫ�ظ�ֵ*/
//	else if(stacknumber == 2)       /*ջ2��Ԫ�ؽ�ջ*/
//
//		S->data[--S->top2] = e;     /*��ջ2���ȸ�top2-1�������Ԫ�ظ�ֵ*/
//	return OK;
//}
//
//
///*��ջ���գ���ɾ��S��ջ��Ԫ�أ���e������ֵ��������OK,���򷵻�Error*/
//Status Pop(SqDoubleStack * S, SElemType * e,int StackNumber)
//{
//	if(StackNumber == 1)
//	{
//		if(S->top1 == -1)       /*˵��ջ1�Ѿ��ǿ�ջ,���*/
//			return ERROR;
//		*e = S->data[S->top1--];  /*��ջ1��ջ��Ԫ�س�ջ*/
//	}
//	else if(StackNumber == 2)
//	{
//		if(S->top2 == -1)       /*˵��ջ2�Ѿ��ǿ�ջ,���*/
//			return ERROR;
//		*e = S->data[S->top2++];  /*��ջ2��ջ��Ԫ�س�ջ*/
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
//        printf("ջ��Ԫ������Ϊ��");
//        StackTraverse(s);
//
//        printf("��ǰջ��Ԫ���У�%d \n",StackLength(s));
//
//        Pop(&s,&e,2);
//        printf("������ջ��Ԫ�� e=%d\n",e);
//        printf("ջ�շ�%d(1:�� 0:��)\n",StackEmpty(s));
//
//        for(j=6;j<=MAXSIZE-2;j++)
//                Push(&s,j,1);
//
//        printf("ջ��Ԫ������Ϊ��");
//        StackTraverse(s);
//
//        printf("ջ����%d(1:�� 0:��)\n",Push(&s,100,1));
//
//        
//        ClearStack(&s);
//        printf("���ջ��ջ�շ�%d(1:�� 0:��)\n",StackEmpty(s));
//
//		system("pause");
//        
//        return 0;
//}
