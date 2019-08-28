#include<string>
#include<iomanip>
#include<iostream>
using namespace std;


class NoMem {
public:
	NoMem() {}
};
class OutOfBounds {
public:
	OutOfBounds() {}
};

template<class T>
class Stack {                 //ջ
public:
	Stack(int MaxStackSize = 100);
    ~Stack() {delete [] stack;}
    bool IsEmpty() const {return top == -1;}          //�Ƿ�Ϊ��
    bool IsFull() const {return top == MaxTop;}       //�Ƿ���
    T Top() const;                                    
    Stack<T>& Push(const T& x);                       
    T &Pop();                                         
private:
	int top;    //ջ��
    int MaxTop; // ���ջ
	T *stack;   //���ջ��Ԫ��
};

template<class T>
Stack<T>::Stack(int MaxStackSize)         //���캯��
{
	MaxTop=MaxStackSize-1;
    stack=new T[MaxStackSize];
    top=-1;
}
template<class T>
T Stack<T>::Top() const           //����ջ����ֵ
{
	if (IsEmpty()) throw OutOfBounds();  //ջ��
    return stack[top];
}
template<class T>
Stack<T>& Stack<T>::Push(const T& x)     //ѹջ
{
	if (IsFull()) throw NoMem();        //ջ��
	stack[++top]=x;
	return *this;
}

template<class T>
T& Stack<T>::Pop()                //����ջ
{
    if (IsEmpty()) throw OutOfBounds(); //ջ��
    return stack[top--];
}
