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
class Stack {                 //栈
public:
	Stack(int MaxStackSize = 100);
    ~Stack() {delete [] stack;}
    bool IsEmpty() const {return top == -1;}          //是否为空
    bool IsFull() const {return top == MaxTop;}       //是否满
    T Top() const;                                    
    Stack<T>& Push(const T& x);                       
    T &Pop();                                         
private:
	int top;    //栈顶
    int MaxTop; // 最大栈
	T *stack;   //存放栈中元素
};

template<class T>
Stack<T>::Stack(int MaxStackSize)         //构造函数
{
	MaxTop=MaxStackSize-1;
    stack=new T[MaxStackSize];
    top=-1;
}
template<class T>
T Stack<T>::Top() const           //返回栈顶的值
{
	if (IsEmpty()) throw OutOfBounds();  //栈空
    return stack[top];
}
template<class T>
Stack<T>& Stack<T>::Push(const T& x)     //压栈
{
	if (IsFull()) throw NoMem();        //栈满
	stack[++top]=x;
	return *this;
}

template<class T>
T& Stack<T>::Pop()                //弹出栈
{
    if (IsEmpty()) throw OutOfBounds(); //栈空
    return stack[top--];
}
