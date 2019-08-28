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
	int top;  //��ǰ��ջ��
	int maxtop;   //ջ���������
	T *stack;   //ջ��Ԫ��
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
Stack<T>& Stack<T>::push(const T& x){  //ѹջ
	if(isfull()) throw NoMem();
	stack[++top]=x;
	return *this;
}
template<class T>
Stack<T>& Stack<T>::pop(T& x){     //��ջ
	if(isempty()) throw NoMem();
	x=stack[top--];
	return *this;
}

template <class T>
void delete_all(Stack<T> &s, const T &x){ // ɾ��ջs�����е���x����������
	T element,t;
	Stack<T> A;
	if(s.isempty()) throw OutOfBounds();   //����ջΪ��
	while(!s.isempty()){
		s.pop(element);
		if(element!=x) cout<<element<<" ";   //������x�����
		A.push(element);       //ѹ����תջA
	}
	while(!A.isempty()){      //��A�е���ѹ��s
		A.pop(t);
		s.push(t); 
	}
	cout<<endl;
}
