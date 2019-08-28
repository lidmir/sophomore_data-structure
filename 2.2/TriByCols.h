#include<iostream>
#include<fstream>
#include<iomanip>
#include "xcept.h"
using namespace std;

template<class T>
class TriByCols
{	
private:
	int n;        //����ά��
	T *element;   //�洢���ԽǾ����һά����
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
template<class T>                                                          //���캯��
TriByCols<T>::TriByCols(int theN)
{    
	if(theN<1) throw BadInitializers();    //����theN�Ƿ���Ч
	n=theN;
	element=new T[3*n-2];
}
template<class T>  
TriByCols<T>::TriByCols(const TriByCols<T> &a){                           //�������캯��
	n=a.n;
	element=new T[3*n-2];
	for(int i=0;i<3*n-2;i++)
		element[i]=a.element[i];
}
template<class T>
T TriByCols<T>::search(int i,int j) const                                  //����������(i,j)λ���ϵ�Ԫ��
{
	if(i<1||j<1||i>n||j>n) throw OutOfBounds();                 //����i,j��ֵ�Ƿ���Ч
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
void TriByCols<T>::store(int i,int j,const T& newValue)                    //�洢(i,j)����ֵ
{
	if(i<1||j<1||i>n||j>n) throw OutOfBounds();                //����i,j��ֵ�Ƿ���Ч
	switch(i-j){
	case(1):                               //�¶Խ���
		element[3*i-5]=newValue;
		break;
	case(0):                                //���Խ���
		element[3*i-3]=newValue;
		break;
	case(-1):                                //�϶Խ���
		element[3*i-1]=newValue;
		break;
	default:
		if(newValue !=0) throw MustBeZero();   //�����Խ�Ԫ�ص�ֵ������0
	}
}
template<class T>
istream& operator>>(istream &in,const TriByCols<T> &a)               //�������
{
	cout<<"Enter the value of term�������Խ��ϵ�Ԫ�ذ������룩:";
	for(int i=0;i<3*a.n-2;i++)                
		in>>a.element[i];
	return in;
};
template<class T>
ostream& operator<<(ostream &out,const TriByCols<T> &a)             //�������
{
	out<<endl<<"--Triagonal Matrix--"<<endl;
	for(int i=1;i<=a.n;i++){                     //��
		for(int j=1;j<=a.n;j++)                 //��
				out<<setiosflags(ios::left)<<setw(5)<<a.search(i,j);
		out<<endl;
	}
	out<<"-------------------"<<endl<<endl;
	return out;
};
template<class T>
TriByCols<T> operator+(TriByCols<T> &a,TriByCols<T> &b){              //����ļӷ�
	if(a.n!=b.n) throw SizeMismatch();                                       
	TriByCols<T> c(a.n);
	for(int i=0;i<3*a.n-2;i++)
		c.element[i]=a.element[i]+b.element[i];
	return c;
}
template<class T>
TriByCols<T> operator-(TriByCols<T> &a,TriByCols<T> &b){              //����ļ���
	if(a.n!=b.n) throw SizeMismatch();
	TriByCols<T> c(a.n);
	for(int i=0;i<3*a.n-2;i++)
		c.element[i]=a.element[i]-b.element[i];
	return c;
}
template<class T>
TriByCols<T> TriByCols<T>::transpose(){                               //�����ת��
	TriByCols<T> a=*this;
	for(int i=1;i<=a.n;i++){
		for(int j=1;j<=a.n;j++){
			switch(i-j){                                              //���¶Խ����ϵ�Ԫ�����϶Խ����ϵ�Ԫ�ضԵ�
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