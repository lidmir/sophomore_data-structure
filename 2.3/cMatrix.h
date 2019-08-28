#include<iostream>
#include<fstream>
#include<iomanip>
#include "xcept.h"
using namespace std;

template<class T>
class cMatrix
{	
private:
	int n;        //����ά��
	T *element;   //�洢C�ξ����һά����
public:
	cMatrix(int theN=20);
	cMatrix(const cMatrix<T> &a);
	~cMatrix(){delete[]element;};
	template<class T>friend istream& operator>>(istream &in,const cMatrix<T> &a);
	template<class T>friend ostream& operator<<(ostream &out,const cMatrix<T> &a);
	T Retrieve(int, int) const;
	void store(int, int, const T&);
};
template<class T>                                                          //���캯��
cMatrix<T>::cMatrix(int theN)
{    
	if(theN<1) throw BadInitializers();    //����theN�Ƿ���Ч
	n=theN;
	element=new T[3*n-2];
}
template<class T>  
cMatrix<T>::cMatrix(const cMatrix<T> &a){                           //�������캯��
	n=a.n;
	element=new T[3*n-2];
	for(int i=0;i<3*n-2;i++)
		element[i]=a.element[i];
}
template<class T>
T cMatrix<T>::Retrieve(int i,int j) const                                  //ȡ�þ�����(i,j)λ���ϵ�Ԫ��
{
	if(i<1||j<1||i>n||j>n) throw OutOfBounds();                 //����i,j��ֵ�Ƿ���Ч
	if(i==1)                                     //��һ��
		return element[j-1];
	if(i==n)                                     //���һ��
		return element[n+j-1];
	if(j==1&&i!=1&&i!=n)  return element[2*n+i-2];            //��һ�г��˵�һ��Ԫ�غ����һ��Ԫ��
	return 0;
}
template<class T>
void cMatrix<T>::store(int i,int j,const T& newValue)                    //�洢(i,j)����ֵ
{
	if(i<1||j<1||i>n||j>n) throw OutOfBounds();                //����i,j��ֵ�Ƿ���Ч
	if(i==1)                      //��һ��
		element[j-1]=newValue;
	if(i==n)                    //���һ��
		element[n+j-1]=newValue;
	if(j==1&&i!=1&&i!=n)  element[2*n+i-2]=newValue;          //��һ�г��˵�һ��Ԫ�غ����һ��Ԫ��
	if(i!=1&&i!=n&&j!=1&&newValue !=0) throw MustBeZero();   //��c��λ����Ԫ�ص�ֵ������0
}
template<class T>
istream& operator>>(istream &in,const cMatrix<T> &a)               //�������
{
	cout<<"Enter the value of term���������һ�У������һ�У�����������һ�е�ʣ��Ԫ�أ�:";
	for(int i=0;i<3*a.n-2;i++)                
		in>>a.element[i];
	return in;
};
template<class T>
ostream& operator<<(ostream &out,const cMatrix<T> &a)             //�������
{
	out<<"--cMatrix--"<<endl;
	for(int i=1;i<=a.n;i++){                  //��
		for(int j=1;j<=a.n;j++){                //��
			out<<setiosflags(ios::left)<<setw(5)<<a.Retrieve(i,j);
		}
		out<<endl;
	}
	out<<"-------------------"<<endl<<endl;
	return out;
};