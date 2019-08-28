#include<iostream>
#include<fstream>
#include<iomanip>
#include "xcept.h"
using namespace std;

template<class T>
class TriByCols
{	
private:
	int n;        //矩阵维数
	T *element;   //存储三对角矩阵的一维数组
public:
	TriByCols(int theN=20);
	TriByCols(const TriByCols<T> &a);
	~TriByCols(){delete[]element;};
	template<class T>friend istream& operator>>(istream &in,const TriByCols<T> &a);
	template<class T>friend ostream& operator<<(ostream &out,const TriByCols<T> &a);
	T search(int, int) const;
	void store(int, int, const T&);
	template<class T>friend TriByCols<T> operator+(TriByCols<T> &,TriByCols<T> &);
	template<class T>friend TriByCols<T> operator-(TriByCols<T> &,TriByCols<T> &);
	TriByCols transpose();
};
template<class T>                                                          //构造函数
TriByCols<T>::TriByCols(int theN)
{    
	if(theN<1) throw BadInitializers();    //检验theN是否有效
	n=theN;
	element=new T[3*n-2];
}
template<class T>  
TriByCols<T>::TriByCols(const TriByCols<T> &a){                           //拷贝构造函数
	n=a.n;
	element=new T[3*n-2];
	for(int i=0;i<3*n-2;i++)
		element[i]=a.element[i];
}
template<class T>
T TriByCols<T>::search(int i,int j) const                                  //搜索矩阵中(i,j)位置上的元素
{
	if(i<1||j<1||i>n||j>n) throw OutOfBounds();                 //检验i,j的值是否有效
	switch(i-j){
	case(1):
		return element[3*i-5];
	case(0):
		return element[3*i-3];
	case(-1):
		return element[3*i-1];
	default:
		return 0;
	}
}
template<class T>
void TriByCols<T>::store(int i,int j,const T& newValue)                    //存储(i,j)的新值
{
	if(i<1||j<1||i>n||j>n) throw OutOfBounds();                //检验i,j的值是否有效
	switch(i-j){
	case(1):                               //下对角线
		element[3*i-5]=newValue;
		break;
	case(0):                                //主对角线
		element[3*i-3]=newValue;
		break;
	case(-1):                                //上对角线
		element[3*i-1]=newValue;
		break;
	default:
		if(newValue !=0) throw MustBeZero();   //非三对角元素的值必须是0
	}
}
template<class T>
istream& operator>>(istream &in,const TriByCols<T> &a)               //输入矩阵
{
	cout<<"Enter the value of term（将三对角上的元素按列输入）:";
	for(int i=0;i<3*a.n-2;i++)                
		in>>a.element[i];
	return in;
};
template<class T>
ostream& operator<<(ostream &out,const TriByCols<T> &a)             //输出矩阵
{
	out<<endl<<"--Triagonal Matrix--"<<endl;
	for(int i=1;i<=a.n;i++){                     //行
		for(int j=1;j<=a.n;j++)                 //列
				out<<setiosflags(ios::left)<<setw(5)<<a.search(i,j);
		out<<endl;
	}
	out<<"-------------------"<<endl<<endl;
	return out;
};
template<class T>
TriByCols<T> operator+(TriByCols<T> &a,TriByCols<T> &b){              //矩阵的加法
	if(a.n!=b.n) throw SizeMismatch();                                       
	TriByCols<T> c(a.n);
	for(int i=0;i<3*a.n-2;i++)
		c.element[i]=a.element[i]+b.element[i];
	return c;
}
template<class T>
TriByCols<T> operator-(TriByCols<T> &a,TriByCols<T> &b){              //矩阵的减法
	if(a.n!=b.n) throw SizeMismatch();
	TriByCols<T> c(a.n);
	for(int i=0;i<3*a.n-2;i++)
		c.element[i]=a.element[i]-b.element[i];
	return c;
}
template<class T>
TriByCols<T> TriByCols<T>::transpose(){                               //矩阵的转置
	TriByCols<T> a=*this;
	for(int i=1;i<=a.n;i++){
		for(int j=1;j<=a.n;j++){
			switch(i-j){                                              //将下对角线上的元素与上对角线上的元素对调
			case(-1):                                               
				a.element[3*i-1]=element[3*i-2];
				break;
			case(1):
				a.element[3*i-5]=element[3*i-4];
				break;
			default:
				break;
			}
		}
	}
	return a;
}