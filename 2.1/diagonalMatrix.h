#include<iostream>
#include<fstream>
#include<iomanip>
#include "xcept.h"
using namespace std;

template<class T>
class diagonalMatrix
{	
private:
	int n;        //矩阵维数
	T *element;   //存储对角矩阵的一维数组
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
template<class T>                                                              //构造函数
diagonalMatrix<T>::diagonalMatrix(int theN)
{    
	if(theN<1) throw BadInitializers();        //检验theN是否有效
	n=theN;
	element=new T[n];
}
template<class T>  
diagonalMatrix<T>::diagonalMatrix(const diagonalMatrix<T> &a)                 //拷贝构造函数
{

	n=a.n;
	element=new T[n];
	for(int i=0;i<n;i++)
		element[i]=a.element[i];
}
template<class T>
T diagonalMatrix<T>::get(int i,int j) const                                   //返回矩阵中(i,j)位置上的元素
{
	if(i<1||j<1||i>n||j>n) throw OutOfBounds();                    //检验i,j的值是否有效
	if(i==j) return element[i-1];
	else return 0;
}
template<class T>
void diagonalMatrix<T>::set(int i,int j,const T& newValue)                    //存储(i,j)的新值
{
	if(i<1||j<1||i>n||j>n) throw OutOfBounds();                    //检验i,j的值是否有效
	if(i==j) element[i-1]=newValue;
	else if(newValue !=0) throw MustBeZero();   //非对角元素的值必须是0
}
template<class T>
istream& operator>>(istream &in,const diagonalMatrix<T> &a)                   //输入矩阵
{
	cout<<"Enter the value of term:";
	for(int i=0;i<a.n;i++)                
		in>>a.element[i];
	return in;
};
template<class T>
ostream& operator<<(ostream &out,const diagonalMatrix<T> &a)                 //输出矩阵
{
	out<<"--Diagonal Matrix--"<<endl;
	for(int i=1;i<=a.n;i++){                                      //行
		for(int j=1;j<=a.n;j++){                                   //列
			out<<setiosflags(ios::left)<<setw(5)<<a.get(i,j);
		}
		out<<endl;
	}
	out<<"-------------------"<<endl<<endl;
	return out;
};
template<class T>
diagonalMatrix<T> operator+(diagonalMatrix<T> &a,diagonalMatrix<T> &b){      //矩阵的加法
	if(a.n!=b.n) throw SizeMismatch();                                       
	diagonalMatrix<T> c(a.n);
	for(int i=0;i<a.n;i++)
		c.element[i]=a.element[i]+b.element[i];
	return c;
}
template<class T>
diagonalMatrix<T> operator-(diagonalMatrix<T> &a,diagonalMatrix<T> &b){      //矩阵的减法
	if(a.n!=b.n) throw SizeMismatch();
	diagonalMatrix<T> c(a.n);
	for(int i=0;i<a.n;i++)
		c.element[i]=a.element[i]-b.element[i];
	return c;
}
template<class T>
diagonalMatrix<T> operator*(diagonalMatrix<T> &a,diagonalMatrix<T> &b){       //矩阵的乘法
	if(a.n!=b.n) throw SizeMismatch();
	diagonalMatrix<T> c(a.n);
	for(int i=0;i<a.n;i++)
		c.element[i]=a.element[i]*b.element[i];
	return c;
}
template<class T>
diagonalMatrix<T> diagonalMatrix<T>::transpose(){                              //矩阵的转置
	return *this;
}
