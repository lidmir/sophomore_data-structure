template<class T>
class Stack {                 //栈
public:
	Stack(int MaxStackSize=100);
	Stack(Stack&s){      //拷贝构造函数	
		MaxTop=s.MaxTop;	
		top=s.top;	
		stack=new T[MaxTop+1];          //重新new一个数组，不能直接赋指针	
		for(int i=0; i<= MaxTop; i++)   //将一维数组中的值逐个拷贝
			stack[i]=s.stack[i];
	}
    ~Stack() {delete [] stack;}
    bool IsEmpty() const {return top == -1;}          //是否为空
    bool IsFull() const {return top == MaxTop;}       //是否满
    T Top() const;                                    
    Stack<T>& Push(const T& x);                       
    Stack<T> &Pop( T& x);                                         
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
Stack<T>& Stack<T>::Pop( T& x)                //弹出栈
{
    if (IsEmpty()) throw OutOfBounds(); //栈空
	x=stack[top--];
    return *this;
}
