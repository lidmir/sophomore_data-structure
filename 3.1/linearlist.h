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
	bool isempty() const{return length==0;}  //是否为空
	int Length() const{return length;}     //线性表长度
	bool find(int k,T& x) const;                //找到元素
	linearlist<T>& Delete(int k,T &x);
	linearlist<T>& Insert(int k,const T& x);
	void Output(ostream& out)const;         //依次输出线性表中的元素
private:
	int length;   //线性表长度
	int maxsize;    //线性表最大
	T*element;     //存放元素
};
template<class T> 
linearlist<T>::linearlist(int maxlistsize){         //构造函数
	maxsize=maxlistsize;
	element=new T[maxsize];
	length=0;
}

template<class T> 
bool linearlist<T>::find(int k,T& x)const{    //找到元素
	if(k<1||k>length) return false;
	x=element[k-1];
	return true;
}
template<class T> 
void linearlist<T>::Output(ostream &out)const{    //依次输出线性中的元素
	int i=0;
	for(;i<length-1;i++)
		out<<element[i]<<" ";
	out<<element[i]<<endl;
}
template<class T> 
ostream& operator<<(ostream &out,const linearlist<T> &x){   //重载<<
	x.Output(out);
	return out;
} 
template<class T>
linearlist<T>& linearlist<T>::Delete(int k,T &x){  //删除元素
	if(find(k,x)){                   //找到该元素
		for(int i=k;i<length;i++)    //该元素后的元素依次往前
			element[i-1]=element[i];
		length--;
		return *this;
	}
	else throw OutOfBounds();
	return *this;
}
template<class T> 
linearlist<T>& linearlist<T>::Insert(int k,const T&x){   //插入元素
	if(k<0||k>length) throw OutOfBounds();
	if(length==maxsize) throw NoMem();
	for(int i=length-1;i>=k;i--)
		element[i+1]=element[i];         //要插入的位置元素后的元素依次往后
	element[k]=x;
	length++;
	return *this;
}