#include<iostream>
#include<fstream>
using namespace std;

class OutOfBounds {
   public:
      OutOfBounds() {}
};
class NoMem {
   public:
      NoMem() {}
};

template<class T> 
class linearlist{
public:
	linearlist(int maxlistsize=100);
	~linearlist(){delete []element;}
	bool isempty() const{return length==0;}  //�Ƿ�Ϊ��
	int Length() const{return length;}     //���Ա���
	bool find(int k,T& x) const;                //�ҵ�Ԫ��
	linearlist<T>& Delete(int k,T &x);
	linearlist<T>& Insert(int k,const T& x);
	void Output(ostream& out)const;         //����������Ա��е�Ԫ��
private:
	int length;   //���Ա���
	int maxsize;    //���Ա����
	T*element;     //���Ԫ��
};
template<class T> 
linearlist<T>::linearlist(int maxlistsize){         //���캯��
	maxsize=maxlistsize;
	element=new T[maxsize];
	length=0;
}

template<class T> 
bool linearlist<T>::find(int k,T& x)const{    //�ҵ�Ԫ��
	if(k<1||k>length) return false;
	x=element[k-1];
	return true;
}
template<class T> 
void linearlist<T>::Output(ostream &out)const{    //������������е�Ԫ��
	int i=0;
	for(;i<length-1;i++)
		out<<element[i]<<" ";
	out<<element[i]<<endl;
}
template<class T> 
ostream& operator<<(ostream &out,const linearlist<T> &x){   //����<<
	x.Output(out);
	return out;
} 
template<class T>
linearlist<T>& linearlist<T>::Delete(int k,T &x){  //ɾ��Ԫ��
	if(find(k,x)){                   //�ҵ���Ԫ��
		for(int i=k;i<length;i++)    //��Ԫ�غ��Ԫ��������ǰ
			element[i-1]=element[i];
		length--;
		return *this;
	}
	else throw OutOfBounds();
	return *this;
}
template<class T> 
linearlist<T>& linearlist<T>::Insert(int k,const T&x){   //����Ԫ��
	if(k<0||k>length) throw OutOfBounds();
	if(length==maxsize) throw NoMem();
	for(int i=length-1;i>=k;i--)
		element[i+1]=element[i];         //Ҫ�����λ��Ԫ�غ��Ԫ����������
	element[k]=x;
	length++;
	return *this;
}