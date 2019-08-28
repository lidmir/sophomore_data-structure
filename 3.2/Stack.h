#include<iostream>
#include<fstream>
using namespace std;

class BadInitializers {
   public:
      BadInitializers() {}
};
class OutOfBounds {
   public:
      OutOfBounds() {}
};
class NoMem {
   public:
      NoMem() {}
};

template<class T>
class Stack{
public:
	Stack(int maxstacksize=100);
	~Stack(){delete []stack;}
	bool isempty() const{return top==-1;}
	bool isfull() const{return top==maxtop;}
	T Top() const;      
	Stack<T>& push(const T&x);
	Stack<T>& pop(T&x);
private:
	int top;  //当前的栈顶
	int maxtop;   //栈的最大容量
	T *stack;   //栈的元素
};

template<class T>
Stack<T>::Stack(int maxstacksize){
	if(maxstacksize<0) throw BadInitializers();
	maxtop=maxstacksize-1;
	stack=new T[maxstacksize];
	top=-1;
}
template<class T>
T Stack<T>::Top() const{
	if(isempty()) throw OutOfBounds();
	return stack[top];
}
template<class T>
Stack<T>& Stack<T>::push(const T& x){  //压栈
	if(isfull()) throw NoMem();
	stack[++top]=x;
	return *this;
}
template<class T>
Stack<T>& Stack<T>::pop(T& x){     //出栈
	if(isempty()) throw NoMem();
	x=stack[top--];
	return *this;
}

template <class T>
void delete_all(Stack<T> &s, const T &x){ // 删除栈s中所有等于x的数据项并输出
	T element,t;
	Stack<T> A;
	if(s.isempty()) throw OutOfBounds();   //输入栈为空
	while(!s.isempty()){
		s.pop(element);
		if(element!=x) cout<<element<<" ";   //不等于x则输出
		A.push(element);       //压进中转栈A
	}
	while(!A.isempty()){      //将A中的再压回s
		A.pop(t);
		s.push(t); 
	}
	cout<<endl;
}
