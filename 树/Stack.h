template<class T>
class Stack {                 //ջ
public:
	Stack(int MaxStackSize=100);
	Stack(Stack&s){      //�������캯��	
		MaxTop=s.MaxTop;	
		top=s.top;	
		stack=new T[MaxTop+1];          //����newһ�����飬����ֱ�Ӹ�ָ��	
		for(int i=0; i<= MaxTop; i++)   //��һά�����е�ֵ�������
			stack[i]=s.stack[i];
	}
    ~Stack() {delete [] stack;}
    bool IsEmpty() const {return top == -1;}          //�Ƿ�Ϊ��
    bool IsFull() const {return top == MaxTop;}       //�Ƿ���
    T Top() const;                                    
    Stack<T>& Push(const T& x);                       
    Stack<T> &Pop( T& x);                                         
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
Stack<T>& Stack<T>::Pop( T& x)                //����ջ
{
    if (IsEmpty()) throw OutOfBounds(); //ջ��
	x=stack[top--];
    return *this;
}
