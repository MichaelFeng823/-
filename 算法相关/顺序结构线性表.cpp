//#include<stdio.h>
//#include<iostream>
//using namespace std;
//#define MaxSize 20
//#define ok 1
//#define error 0
//#define true 1
//#define false 0
//
//typedef int ElemType;
//typedef struct SqList
//{
//	ElemType data[MaxSize];
//	int length;                //���Ա�ǰ����
//} ;
//
//typedef struct Node
//{
//	ElemType data;
//	struct Node * next;
//};
//
//typedef struct Node * LinkList;   //����LinkList
//
//typedef int Status;
///*Status �Ǻ��������ͣ���ֵ�Ǻ������״̬���룬��OK��*/
///*��ʼ������˳�����Ա�L�Ѵ���,1<= i <= ListLength(L)*/
///*�����������e����L�е�i������Ԫ�ص�ֵ*/
//
///* ��ʼ��˳�����Ա� */
//Status InitList(SqList *L) 
//{ 
//    L->length=0;
//    return ok;
//}
//
//Status GetItem(SqList L,int i,ElemType * e)
//{
//	if(L.length == 0 || i < 1 || i > L.length)
//		return error;
//	*e= L.data[i-1];
//	return ok;
//}
//
///*��ʼ������˳�����Ա�L�Ѵ���,1<= i <= ListLength(L)*/
///*�����������L�е�i��λ��֮ǰ�����µ�����Ԫ��e��L�ĳ��ȼ�1*/
//Status ListInsert(SqList * L,int i,ElemType e)
//{
//	int k;
//	if(L->length == MaxSize)   //˳�����Ա�����
//		return error;
//	if(i < 1 || i > L->length+1) //��i���ڷ�Χ��
//		return error;
//	if(i <= L->length)          //���������ݲ��ڱ�β
//	{
//		for(k = L->length - 1; k >= i - 1; k--)      //��Ҫ����λ�ú�����Ԫ������ƶ�һλ
//		{
//			L->data[k+1] = L->data[k];
//		}
//	}
//	L->data[i-1] = e;
//	L->length++;
//	return ok;
//}
///*��ʼ������˳�����Ա�L�Ѵ���,1<= i <= ListLength(L)*/
///*���������ɾ��L�ĵ�i������Ԫ�أ�����e������ֵ��L�ĳ��ȼ�1*/
//Status ListDelete(SqList * L, int i, ElemType * e)
//{
//	int k;
//	if(L->length == 0) //���Ա�Ϊ��
//		return error;
//	if(i < 1 || i > L->length) //ɾ��λ�ò���ȷ
//		return error;
//	*e = L->data[i-1];
//	if(i < L->length)         //���ɾ���������λ��
//	{
//		for(k = i; k < L->length; k++)      //��ɾ��λ�ú��Ԫ�ض���ǰ��
//		{
//			L->data[k-1] = L->data[k];
//		}
//	}
//	L->length--;
//	return ok;
//}
//
////int main()
////{
////	SqList sqllist;
////	InitList(&sqllist);
////	ElemType e = 823;
////	ElemType getnum = 0;
////	string res = ListInsert(&sqllist,1,e) == 0 ? "insert error ": "insert success";
////	cout << res.data() << endl;
////	cout << GetItem(sqllist,1,&getnum) << "      getnum = " << getnum << endl;
////
////	system("pause");
////	return 0;
////}
