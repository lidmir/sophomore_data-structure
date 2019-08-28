#include<iostream>
#include<fstream>
using namespace std;

template<class T> 
class chainnode{
public:
	T data;
	chainnode<T> *link;
};
template<class T> 
class chain{
public:
	chain(){first=0;};
	~chain();
	bool isempty() const{return first==0;}   //�Ƿ�Ϊ��
	int length() const;             //����
	bool find(int k,T& x) const;        //�ҵ�Ԫ�ص�λ��
	chain<T>& Delete(int k,T &x);
	chain<T>& Insert(int k,const T& x);
	void Output(ostream& out)const;        //������������е�Ԫ��
private:
	chainnode<T> *first;
};
template<class T> 
chain<T>::~chain(){          //����
	chainnode<T> *next;
	while(first){
		next=first->link;
		delete first;
		first=next;
	}
}
template<class T> 
int chain<T>::length() const{        //����
	chainnode<T>*current=first;
	int len=0;
	while(current){
		len++;
		current=current->link;
	}
	return len:
}
template<class T> 
bool chain<T>::find(int k,T& x)const{  �ҵ�
	if(k<1) return false;
	chainnode<T>*current=first;
	int index=1;      //������k�Ա�
	while(index<k&&current){
		current=current->link;
		index++;
	}
	if(current){
		x=current->data;
		return true;
	}
	return false;
}

template<class T> 
void chain<T>::Output(ostream& out)const{        //�������������Ԫ��
	chainnode<T> *current;
	for(current=first;current;current=current->link){
		out<<current->data<<" ";
	}
	cout<<endl;
}
template<class T>  
ostream& operator<<(ostream &out,const chain<T> &x){   //���������
	x.Output(out);
	return out;
} 
template<class T>
chain<T>& chain<T>::Delete(int k,T &x){        //ɾ��
	if(k<1||!first)throw OutOfBounds();
	chainnode<T> *p=first;
	if(k==1)  //ɾ����һ��Ԫ��
		first=first->link;
	else{
		chainnode<T> *q=first;           //����������Ҫɾ����Ԫ��
		for(int index=1;index<k-1&&q->link;index++)
			q=q->link;
		if(!q||!q->link) throw OutOfBounds();
		p=q->link;
		q->link=p->link;
	}
	x=p->data;
	delete p;
	return *this;
}
template<class T> 
chain<T>& chain<T>::Insert(int k,const T&x){     //����
	if(k<0) throw OutOfBounds();
	chainnode<T> *p=first;         //����������Ҫɾ����Ԫ��
	for(int index=1;index<k&&p;index++)
		p=p->link;
	if(k>0&&!p) throw OutOfBounds();
	chainnode<T> *y=new chainnode<T>;
	y->data=x;
	if(k){
		y->link=p->link;
		p->link=y;}
	else{
		y->link=first;
		first=y;
	}
	return *this;
}

