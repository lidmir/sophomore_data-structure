#include <iomanip>
#include <iostream>
#include "xcept.h"
using namespace std;

template<class T>
class Term{
public:
	int row,col;      //����������
	T value;            //��λ��Ԫ�ص�ֵ
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
    int rows, cols;  // ������С���
    int terms;  // ��ǰ��0Ԫ�صĸ���
    Term<T> *a;   // ��Term���͵�a����
	int MaxTerms; // ����a�Ĵ�С
};

template<class T>
SparseMatrix<T>::SparseMatrix(int maxTerms)      //���캯��
{
	if (maxTerms < 1) throw BadInitializers(); 
    MaxTerms=maxTerms;
    a=new Term<T> [MaxTerms];
    terms=rows=cols=0;
}
template<class T>
SparseMatrix<T>::SparseMatrix(const SparseMatrix<T> &p)   //�������캯��
{
	MaxTerms=p.MaxTerms
	a = new Term<T> [MaxTerms];
	a=p.a;
    terms=p.terms;
    rows=p.rows;
    cols=p.cols;
}
template <class T>
ostream& operator<<(ostream& out,SparseMatrix<T>& x)       //���
{
    for (int i=1; i<=x.rows; i++){       //��
		for(int j=1;j<=x.cols;j++){       //��
			out<<setiosflags(ios::left)<<setw(5)<<x.Retrieve(i,j);
		}
		out<<endl;
	}
	for(int i=0;i<x.terms;i++)
		out<<"col:"<<x.a[i].col<<" row:"<<x.a[i].row<<" value:"<<x.a[i].value<<endl;
	return out;
}
template<class T>
istream& operator>>(istream& in, SparseMatrix<T>& x)    //����
{
    cout<<"Enter number of rows, columns, and terms"<< endl;     //���������У��кͷ�0Ԫ��
    in>>x.rows>>x.cols>>x.terms;
    if(x.terms>x.MaxTerms) throw NoMem();  //����term�Ƿ�Ϸ�
    for(int i=0; i<x.terms; i++){        //���������0Ԫ�ص��С��С�ֵ
       cout<<"Enter row,column,and value of term "<<(i + 1)<<":"<< endl;
       in>>x.a[i].row>>x.a[i].col>>x.a[i].value;
	}
	x.paixu();
    return in;
}
template<class T>
void SparseMatrix<T>::Store(int row1,int col1,T value)   //�洢��ֵ
{
	if(row1<1||col1<1||row1>rows||col1>cols) throw OutOfBounds();      //����row1,col1��ֵ�Ƿ���Ч
	for(int i=0;i<terms;i++)                         //���ԭλ�õ�Ԫ��ֵ��0
		if(a[i].row==row1&&a[i].col==col1){
			a[i].value=value;
			return;
		}
	a[terms].row=row1;                      //���ԭλ�õ�Ԫ��Ϊ0���洢��һά�������һλ
	a[terms].col=col1;
	a[terms].value=value;
	terms++;
	paixu();
}
template<class T>
T SparseMatrix<T>::Retrieve(int row1,int col1)          //ȡ��Ԫ��
{
	if(row1<1||col1<1||row1>rows||col1>cols) throw OutOfBounds();      //����row1,col1��ֵ�Ƿ���Ч
	for(int i=0;i<terms;i++)                         //��λ�õ�Ԫ�ط�0
		if(a[i].row==row1&&a[i].col==col1) return a[i].value;
	return 0;         //��λ�õ�Ԫ��Ϊ0
}

template<class T>
void SparseMatrix<T>::paixu(){    //�����鰴����������
	Term<T> b;
	for(int i=0;i<terms-1;i++)           //����
		for(int j=i+1;j<terms;j++){
			if(a[j].col<a[i].col){
				b=a[i];
				a[i]=a[j];
				a[j]=b;}
			if(a[i].col==a[j].col){     //�������ʱ
				if(a[j].row<a[i].row){
					b=a[i];
					a[i]=a[j];
					a[j]=b;}}
		}
}
