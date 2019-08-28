#include <iomanip>
#include <iostream>
#include "xcept.h"
using namespace std;

template<class T>
class Term{
public:
	int row,col;      //行数，列数
	T value;            //该位置元素的值
};

template<class T>
class SparseMatrix
{

public:
	template<class T> friend ostream& operator<<(ostream&, SparseMatrix<T>&);
    template<class T> friend istream& operator>>(istream&, SparseMatrix<T>&);
	SparseMatrix(int maxTerms = 10);
	SparseMatrix(const SparseMatrix<T> &a);
    ~SparseMatrix() {delete [] a;}
	void Store(int row1,int col1,T value);
	T Retrieve(int row1,int col1);
	void paixu();
private:
    int rows, cols;  // 矩阵的行、列
    int terms;  // 当前非0元素的个数
    Term<T> *a;   // 类Term类型的a数组
	int MaxTerms; // 数组a的大小
};

template<class T>
SparseMatrix<T>::SparseMatrix(int maxTerms)      //构造函数
{
	if (maxTerms < 1) throw BadInitializers(); 
    MaxTerms=maxTerms;
    a=new Term<T> [MaxTerms];
    terms=rows=cols=0;
}
template<class T>
SparseMatrix<T>::SparseMatrix(const SparseMatrix<T> &p)   //拷贝构造函数
{
	MaxTerms=p.MaxTerms
	a = new Term<T> [MaxTerms];
	a=p.a;
    terms=p.terms;
    rows=p.rows;
    cols=p.cols;
}
template <class T>
ostream& operator<<(ostream& out,SparseMatrix<T>& x)       //输出
{
    for (int i=1; i<=x.rows; i++){       //行
		for(int j=1;j<=x.cols;j++){       //列
			out<<setiosflags(ios::left)<<setw(5)<<x.Retrieve(i,j);
		}
		out<<endl;
	}
	for(int i=0;i<x.terms;i++)
		out<<"col:"<<x.a[i].col<<" row:"<<x.a[i].row<<" value:"<<x.a[i].value<<endl;
	return out;
}
template<class T>
istream& operator>>(istream& in, SparseMatrix<T>& x)    //输入
{
    cout<<"Enter number of rows, columns, and terms"<< endl;     //输入矩阵的行，列和非0元素
    in>>x.rows>>x.cols>>x.terms;
    if(x.terms>x.MaxTerms) throw NoMem();  //检验term是否合法
    for(int i=0; i<x.terms; i++){        //依次输入非0元素的行、列、值
       cout<<"Enter row,column,and value of term "<<(i + 1)<<":"<< endl;
       in>>x.a[i].row>>x.a[i].col>>x.a[i].value;
	}
	x.paixu();
    return in;
}
template<class T>
void SparseMatrix<T>::Store(int row1,int col1,T value)   //存储新值
{
	if(row1<1||col1<1||row1>rows||col1>cols) throw OutOfBounds();      //检验row1,col1的值是否有效
	for(int i=0;i<terms;i++)                         //如果原位置的元素值非0
		if(a[i].row==row1&&a[i].col==col1){
			a[i].value=value;
			return;
		}
	a[terms].row=row1;                      //如果原位置的元素为0，存储在一维数组最后一位
	a[terms].col=col1;
	a[terms].value=value;
	terms++;
	paixu();
}
template<class T>
T SparseMatrix<T>::Retrieve(int row1,int col1)          //取得元素
{
	if(row1<1||col1<1||row1>rows||col1>cols) throw OutOfBounds();      //检验row1,col1的值是否有效
	for(int i=0;i<terms;i++)                         //该位置的元素非0
		if(a[i].row==row1&&a[i].col==col1) return a[i].value;
	return 0;         //该位置的元素为0
}

template<class T>
void SparseMatrix<T>::paixu(){    //将数组按列主次排序
	Term<T> b;
	for(int i=0;i<terms-1;i++)           //排序
		for(int j=i+1;j<terms;j++){
			if(a[j].col<a[i].col){
				b=a[i];
				a[i]=a[j];
				a[j]=b;}
			if(a[i].col==a[j].col){     //列数相等时
				if(a[j].row<a[i].row){
					b=a[i];
					a[i]=a[j];
					a[j]=b;}}
		}
}
