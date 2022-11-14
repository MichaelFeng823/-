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
//	int length;                //线性表当前长度
//} ;
//
//typedef struct Node
//{
//	ElemType data;
//	struct Node * next;
//};
//
//typedef struct Node * LinkList;   //定义LinkList
//
//typedef int Status;
///*Status 是函数的类型，其值是函数结果状态代码，如OK等*/
///*初始条件：顺序线性表L已存在,1<= i <= ListLength(L)*/
///*操作结果：用e返回L中第i个数据元素的值*/
//
///* 初始化顺序线性表 */
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
///*初始条件：顺序线性表L已存在,1<= i <= ListLength(L)*/
///*操作结果：在L中第i个位置之前插入新的数据元素e，L的长度加1*/
//Status ListInsert(SqList * L,int i,ElemType e)
//{
//	int k;
//	if(L->length == MaxSize)   //顺序线性表已满
//		return error;
//	if(i < 1 || i > L->length+1) //当i不在范围内
//		return error;
//	if(i <= L->length)          //若插入数据不在表尾
//	{
//		for(k = L->length - 1; k >= i - 1; k--)      //将要插入位置后数据元素向后移动一位
//		{
//			L->data[k+1] = L->data[k];
//		}
//	}
//	L->data[i-1] = e;
//	L->length++;
//	return ok;
//}
///*初始条件：顺序线性表L已存在,1<= i <= ListLength(L)*/
///*操作结果：删除L的第i个数据元素，并用e返回其值，L的长度减1*/
//Status ListDelete(SqList * L, int i, ElemType * e)
//{
//	int k;
//	if(L->length == 0) //线性表为空
//		return error;
//	if(i < 1 || i > L->length) //删除位置不正确
//		return error;
//	*e = L->data[i-1];
//	if(i < L->length)         //如果删除不是最后位置
//	{
//		for(k = i; k < L->length; k++)      //将删除位置后继元素都往前移
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
