#include <iostream>
using namespace std;

template<class T>
class Deque {            //双端队列
public:
	Deque(int MaxdequeSize = 10);
    ~Deque() {delete []deque;}
	void Creat(){Deque<T> a1;}
    bool IsEmpty() const{return count==0;}
    bool IsFull() const{return count==MaxSize-1;}
    T Left() const;
    T Right() const; 
    Deque<T>& AddLeft(const T& x);
	Deque<T>& AddRight(const T& x);
    Deque<T>& DeleteLeft(T& x);
	Deque<T>& DeleteRight(T& x);
	void Print();
private:
    int left;   //最左元素的下标
    int right;    // 最右元素的下标
    int MaxSize; // 队列最大值
    T *deque;    // element array
	int count;    //计算队列中元素个数
};

template<class T>
Deque<T>::Deque(int MaxdequeSize)     
{                                 //构造函数
	MaxSize=MaxdequeSize+1;
    deque=new T[MaxSize];
    left=right=count=0;
}

template<class T>                     
T Deque<T>::Left() const
{                                //返回队列最左边的值
	if (IsEmpty()) {             //判断队列是否为空
		cout<<"EMPTY";
		throw OutOfBounds();}
	return deque[(MaxSize+left+1)%MaxSize];
}

template<class T>
T Deque<T>::Right() const
{                                //返回队列最右边的值
	if (IsEmpty()) {
		cout<<"EMPTY";
	    throw OutOfBounds();}
    return deque[(right)%MaxSize];
}

template<class T>
Deque<T>& Deque<T>::AddLeft(const T& x)
{                                        //在队列左端插入数据
	if (IsFull()) throw NoMem();         //判断队列是否满
	else{ 
		left--;
		deque[(left+1+MaxSize)%MaxSize]=x;  
		count++;
	}
	return *this;
}

template<class T>
Deque<T>& Deque<T>::AddRight(const T& x)
{                                         //在队列右端插入数据
	if (IsFull()) throw NoMem();
	else{ 
		right++;
		deque[right%MaxSize]=x;  
		count++;
	}
	return *this;
}

template<class T>
Deque<T>& Deque<T>::DeleteLeft(T& x)
{                                            //在队列左端删除数据
	if (IsEmpty()) throw OutOfBounds();     //判断队列是否为空
	else{
		x=deque[(left+1+MaxSize)%MaxSize];
		left++;
		count--;
	}
	return *this;
}

template<class T>
Deque<T>& Deque<T>::DeleteRight(T& x)
{                                         //在队列右端删除数据     
	if (IsEmpty()) throw OutOfBounds();
	else{
		x=deque[right%MaxSize];
		right--;
		count--;
	}
	return *this;
}

template<class T>
void Deque<T>::Print()
{                                //打印当前队列
	int count1=count;
	for(int i=left+1;count1!=0;i++,count1--){
		cout<<deque[(i+MaxSize)%MaxSize]<<" ";
	}
	cout<<endl;
}

class OutOfBounds {
   public:
      OutOfBounds() {}
};

class NoMem {
   public:
      NoMem() {}
};
