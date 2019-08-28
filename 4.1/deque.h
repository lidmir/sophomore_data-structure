#include <iostream>
using namespace std;

template<class T>
class Deque {            //˫�˶���
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
    int left;   //����Ԫ�ص��±�
    int right;    // ����Ԫ�ص��±�
    int MaxSize; // �������ֵ
    T *deque;    // element array
	int count;    //���������Ԫ�ظ���
};

template<class T>
Deque<T>::Deque(int MaxdequeSize)     
{                                 //���캯��
	MaxSize=MaxdequeSize+1;
    deque=new T[MaxSize];
    left=right=count=0;
}

template<class T>                     
T Deque<T>::Left() const
{                                //���ض�������ߵ�ֵ
	if (IsEmpty()) {             //�ж϶����Ƿ�Ϊ��
		cout<<"EMPTY";
		throw OutOfBounds();}
	return deque[(MaxSize+left+1)%MaxSize];
}

template<class T>
T Deque<T>::Right() const
{                                //���ض������ұߵ�ֵ
	if (IsEmpty()) {
		cout<<"EMPTY";
	    throw OutOfBounds();}
    return deque[(right)%MaxSize];
}

template<class T>
Deque<T>& Deque<T>::AddLeft(const T& x)
{                                        //�ڶ�����˲�������
	if (IsFull()) throw NoMem();         //�ж϶����Ƿ���
	else{ 
		left--;
		deque[(left+1+MaxSize)%MaxSize]=x;  
		count++;
	}
	return *this;
}

template<class T>
Deque<T>& Deque<T>::AddRight(const T& x)
{                                         //�ڶ����Ҷ˲�������
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
{                                            //�ڶ������ɾ������
	if (IsEmpty()) throw OutOfBounds();     //�ж϶����Ƿ�Ϊ��
	else{
		x=deque[(left+1+MaxSize)%MaxSize];
		left++;
		count--;
	}
	return *this;
}

template<class T>
Deque<T>& Deque<T>::DeleteRight(T& x)
{                                         //�ڶ����Ҷ�ɾ������     
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
{                                //��ӡ��ǰ����
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
