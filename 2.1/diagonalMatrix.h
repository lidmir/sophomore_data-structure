#include<iostream>
#include<fstream>
#include<iomanip>
#include "xcept.h"
using namespace std;

template<class T>
class diagonalMatrix
{	
private:
	int n;        //����ά��
	T *element;   //�洢�ԽǾ����һά����
public:
	diagonalMatrix(int theN=10);
	diagonalMatrix(const diagonalMatrix<T> &a);
	~diagonalMatrix(){delete[]element;};
	template<class T>friend istream& operator>>(istream &in,const diagonalMatrix<T> &a);
	template<class T>friend ostream& operator<<(ostream &out,const diagonalMatrix<T> &a);
	T get(int, int) const;
	void set(int, int, const T&);
	template<class T>friend diagonalMatrix<T> operator+(diagonalMatrix<T> &,diagonalMatrix<T> &);
	template<class T>friend diagonalMatrix<T> operator-(diagonalMatrix<T> &,diagonalMatrix<T> &);
	template<class T>friend diagonalMatrix<T> operator*(diagonalMatrix<T> &,diagonalMatrix<T> &);
	diagonalMatrix transpose();
};
template<class T>                                                              //���캯��
diagonalMatrix<T>::diagonalMatrix(int theN)
{    
	if(theN<1) throw BadInitializers();        //����theN�Ƿ���Ч
	n=theN;
	element=new T[n];
}
template<class T>  
diagonalMatrix<T>::diagonalMatrix(const diagonalMatrix<T> &a)                 //�������캯��
{

	n=a.n;
	element=new T[n];
	for(int i=0;i<n;i++)
		element[i]=a.element[i];
}
template<class T>
T diagonalMatrix<T>::get(int i,int j) const                                   //���ؾ�����(i,j)λ���ϵ�Ԫ��
{
	if(i<1||j<1||i>n||j>n) throw OutOfBounds();                    //����i,j��ֵ�Ƿ���Ч
	if(i==j) return element[i-1];
	else return 0;
}
template<class T>
void diagonalMatrix<T>::set(int i,int j,const T& newValue)                    //�洢(i,j)����ֵ
{
	if(i<1||j<1||i>n||j>n) throw OutOfBounds();                    //����i,j��ֵ�Ƿ���Ч
	if(i==j) element[i-1]=newValue;
	else if(newValue !=0) throw MustBeZero();   //�ǶԽ�Ԫ�ص�ֵ������0
}
template<class T>
istream& operator>>(istream &in,const diagonalMatrix<T> &a)                   //�������
{
	cout<<"Enter the value of term:";
	for(int i=0;i<a.n;i++)                
		in>>a.element[i];
	return in;
};
template<class T>
ostream& operator<<(ostream &out,const diagonalMatrix<T> &a)                 //�������
{
	out<<"--Diagonal Matrix--"<<endl;
	for(int i=1;i<=a.n;i++){                                      //��
		for(int j=1;j<=a.n;j++){                                   //��
			out<<setiosflags(ios::left)<<setw(5)<<a.get(i,j);
		}
		out<<endl;
	}
	out<<"-------------------"<<endl<<endl;
	return out;
};
template<class T>
diagonalMatrix<T> operator+(diagonalMatrix<T> &a,diagonalMatrix<T> &b){      //����ļӷ�
	if(a.n!=b.n) throw SizeMismatch();                                       
	diagonalMatrix<T> c(a.n);
	for(int i=0;i<a.n;i++)
		c.element[i]=a.element[i]+b.element[i];
	return c;
}
template<class T>
diagonalMatrix<T> operator-(diagonalMatrix<T> &a,diagonalMatrix<T> &b){      //����ļ���
	if(a.n!=b.n) throw SizeMismatch();
	diagonalMatrix<T> c(a.n);
	for(int i=0;i<a.n;i++)
		c.element[i]=a.element[i]-b.element[i];
	return c;
}
template<class T>
diagonalMatrix<T> operator*(diagonalMatrix<T> &a,diagonalMatrix<T> &b){       //����ĳ˷�
	if(a.n!=b.n) throw SizeMismatch();
	diagonalMatrix<T> c(a.n);
	for(int i=0;i<a.n;i++)
		c.element[i]=a.element[i]*b.element[i];
	return c;
}
template<class T>
diagonalMatrix<T> diagonalMatrix<T>::transpose(){                              //�����ת��
	return *this;
}
