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
class BadInput {
   public:
      BadInput() {}
};

template <class T> class LinkedQueue;  //队列

template <class T>
class Node {                //节点
   friend LinkedQueue<T>;
   private:
      T data;
      Node<T> *link;
};
template<class T>
class LinkedQueue {
// FIFO objects
 public:
	 LinkedQueue() {front=rear=0;} // constructor
     ~LinkedQueue(); // destructor
     bool IsEmpty() const{return ((front) ? false : true);}
     bool IsFull() const;
     T First() const; // return first element
     T Last() const; // return last element
     LinkedQueue<T>& Add(const T& x);
     LinkedQueue<T>& Delete(T& x);
private:
	Node<T> *front;  // pointer to first node
    Node<T> *rear;   // pointer to last node
};

template<class T>
LinkedQueue<T>::~LinkedQueue()
{// Queue destructor.  Delete all nodes.
	Node<T> *next;
	next=new Node<T>;
    while (front) {
		next=front->link; 
        delete front; 
        front=next;
	}
}

template<class T>
bool LinkedQueue<T>::IsFull() const
{// Is the queue full?
	Node<T> *p;
    try {
		p=new Node<T>;
        delete p;
        return false;}
	catch (NoMem) {return true;}
}

template<class T>
T LinkedQueue<T>::First() const
{
	if (IsEmpty()) throw OutOfBounds();
	return front->data;
}

template<class T>
T LinkedQueue<T>::Last() const
{
	if (IsEmpty()) throw OutOfBounds();
    return rear->data;
}

template<class T>
LinkedQueue<T>& LinkedQueue<T>::Add(const T& x)
{
	Node<T> *p=new Node<T>;
    p->data=x;
    p->link=0;     //新建一节点并赋值
    if (front) rear->link=p;  // queue not empty
    else front=p;             // queue empty
    rear=p;
    return *this;
}

template<class T>
LinkedQueue<T>& LinkedQueue<T>::Delete(T& x)
{
	if (IsEmpty()) throw OutOfBounds();
    x = front->data;
    Node<T> *p = front;
    front=front->link;
    delete p;
	return *this;
}