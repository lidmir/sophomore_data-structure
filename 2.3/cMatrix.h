#include<iostream>
#include<fstream>
#include<iomanip>
#include "xcept.h"
using namespace std;

template<class T>
class cMatrix
{	
private:
	int n;        //矩阵维数
	T *element;   //存储C形矩阵的一维数组
public:
	cMatrix(int theN=20);
	cMatrix(const cMatrix<T> &a);
	~cMatrix(){delete[]element;};
	template<class T>friend istream& operator>>(istream &in,const cMatrix<T> &a);
	template<class T>friend ostream& operator<<(ostream &out,const cMatrix<T> &a);
	T Retrieve(int, int) const;
	void store(int, int, const T&);
};
template<class T>                                                          //构造函数
cMatrix<T>::cMatrix(int theN)
{    
	if(theN<1) throw BadInitializers();    //检验theN是否有效
	n=theN;
	element=new T[3*n-2];
}
template<class T>  
cMatrix<T>::cMatrix(const cMatrix<T> &a){                           //拷贝构造函数
	n=a.n;
	element=new T[3*n-2];
	for(int i=0;i<3*n-2;i++)
		element[i]=a.element[i];
}
template<class T>
T cMatrix<T>::Retrieve(int i,int j) const                                  //取得矩阵中(i,j)位置上的元素
{
	if(i<1||j<1||i>n||j>n) throw OutOfBounds();                 //检验i,j的值是否有效
	if(i==1)                                     //第一行
		return element[j-1];
	if(i==n)                                     //最后一行
		return element[n+j-1];
	if(j==1&&i!=1&&i!=n)  return element[2*n+i-2];            //第一列除了第一个元素和最后一个元素
	return 0;
}
template<class T>
void cMatrix<T>::store(int i,int j,const T& newValue)                    //存储(i,j)的新值
{
	if(i<1||j<1||i>n||j>n) throw OutOfBounds();                //检验i,j的值是否有效
	if(i==1)                      //第一行
		element[j-1]=newValue;
	if(i==n)                    //最后一行
		element[n+j-1]=newValue;
	if(j==1&&i!=1&&i!=n)  element[2*n+i-2]=newValue;          //第一列除了第一个元素和最后一个元素
	if(i!=1&&i!=n&&j!=1&&newValue !=0) throw MustBeZero();   //非c形位置上元素的值必须是0
}
template<class T>
istream& operator>>(istream &in,const cMatrix<T> &a)               //输入矩阵
{
	cout<<"Enter the value of term（先输入第一行，再最后一行，最后输入最后一列的剩余元素）:";
	for(int i=0;i<3*a.n-2;i++)                
		in>>a.element[i];
	return in;
};
template<class T>
ostream& operator<<(ostream &out,const cMatrix<T> &a)             //输出矩阵
{
	out<<"--cMatrix--"<<endl;
	for(int i=1;i<=a.n;i++){                  //行
		for(int j=1;j<=a.n;j++){                //列
			out<<setiosflags(ios::left)<<setw(5)<<a.Retrieve(i,j);
		}
		out<<endl;
	}
	out<<"-------------------"<<endl<<endl;
	return out;
};