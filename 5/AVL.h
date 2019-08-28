#include"Stack.h"
#include"LinkedQueue.h"
template<class T> class AvlTree;
template <class T>
class AvlTreeNode {
	friend AvlTree<T>;
public:
	AvlTreeNode() {LeftChild=RightChild=0;balance=0;}
    AvlTreeNode(const T& e){data=e; LeftChild=RightChild=0;balance=0;}
    AvlTreeNode(const T& e, AvlTreeNode *l,AvlTreeNode *r){data=e;LeftChild=l;RightChild=r;balance=0;}
private:
    T data;
	AvlTreeNode<T> *LeftChild,*RightChild; // ��������
	int balance;        //ƽ������
};

template <class T>
class AvlTree{
public:
	AvlTree(){root=nullptr;};
	~AvlTree(){};
	bool IsEmpty() const{return ((root)?false:true);}              //�ж��Ƿ�Ϊ��
	bool Root(T& x) const{if(root){x=root->data;return 1;} return 0; }       //���ظ���ֵ
	void Insert(T x);
	int Height();
	void NearestLeaf();   
	void Order1Output() {Order1(Output, root,0);cout<<endl;};      //�������  
private:
	AvlTreeNode<T> *root;          //��
	void LeftRotate(AvlTreeNode<T> *t);           
	void RightRotate(AvlTreeNode<T> *t);
	void ChangeBalance(AvlTreeNode<T> *t,T x);                           //����ת�������¸���ƽ������   
	void TotalChangeBalance(AvlTreeNode<T> *t){PreOrder(Balance,t);}      //ȫ������ƽ������
	void PreOrder(void(*Visit)(AvlTreeNode<T> *u), AvlTreeNode<T> *t);          //�������
	static int height(AvlTreeNode<T> *t) ;       //����������ĸ߶�
	void Order1(void(*Visit)(AvlTreeNode<T> *u), AvlTreeNode<T> *t,int m);      //�������
	static void Balance(AvlTreeNode<T> *t)       //����Avl����ƽ������
	{            
		int hl1=height(t->LeftChild);
		int hr1=height(t->RightChild);
		t->balance=hl1-hr1;
	}
	static void Output(AvlTreeNode<T> *t){cout<< t->data<< '('<<t->balance<<") ";};   //����ĺ���
};
template <class T>
int AvlTree<T>::Height()                                       //����AVL���ĸ߶�
{
	if (!root) return 0;  
	int height1=0; 
    AvlTreeNode<T> *p=root;
    while(p){   
		switch(p->balance){
	    case(1):	   
			p=p->LeftChild; 
		    break;
	    default:
		    p=p->RightChild ;  
	    };
		height1++;
	}
	return height1;
}

template <class T>
void AvlTree<T>::LeftRotate(AvlTreeNode<T> *t){                                          //��ʱ����ת
	if((!t)||(t->RightChild)) return;
	AvlTreeNode<T> *p=new AvlTreeNode<T>(t->data);   //p�����滻ԭ��root
	AvlTreeNode<T> *q=t->RightChild;   //qΪԭroot������������ɾȥ��root��ԭλ��
	p->LeftChild=t->LeftChild;
	t->LeftChild=p;
	p->RightChild=q->LeftChild;
	t->data=q->data;
	t->RightChild=q->RightChild;
	delete q;
}
template <class T>
void AvlTree<T>::RightRotate(AvlTreeNode<T> *t){                                           //˳ʱ����ת
	if((!t)||(t->LeftChild)) return;
	AvlTreeNode<T> *p=new AvlTreeNode<T>(t->data);   //p�����滻ԭ��root
	AvlTreeNode<T> *q=t->LeftChild;   //qΪԭroot������������ɾȥ��root��ԭλ��
	p->RightChild=t->RightChild;
	t->RightChild=p;
	p->LeftChild=q->RightChild;
	t->data=q->data;
	t->LeftChild=q->LeftChild;
	delete q;
}

template <class T>
void AvlTree<T>::Insert(T x){                                                                   //�����½ڵ�
	AvlTreeNode<T> *r = new AvlTreeNode<T>(x);        //r��ʾҪ������½ڵ�
	if (!root) {root=r;return;}                      //���ڵ㲻����
	Stack<AvlTreeNode<T>*> stacka;      
	AvlTreeNode<T> *p=root,*pp=0;   // pp��p���ڵ�
	while(p){                       // �ҵ�xӦ�����λ��
		pp=p;
		stacka.Push(p);
	    if (x<p->data) p=p->LeftChild;
        else if(x>p->data) p=p->RightChild;
	    else return ;              // AVL�����и�Ԫ�أ�ֱ�ӷ���
	}
    //���ڵ����
	AvlTreeNode<T> *ba1=new AvlTreeNode<T>;
	bool findd=0;        //�жϷ��������Ľڵ��Ƿ����
	while(!stacka.IsEmpty()) {        //Ѱ�����һ��ƽ������Ϊ1��-1�Ľڵ�ba1
		stacka.Pop(ba1);
		if((ba1->balance==1)||(ba1->balance==-1)) {findd =1; break;}
	}
	if(!findd){                     //�����Ľڵ㲻����
		ChangeBalance(root,x);
		if (x<pp->data) pp->LeftChild=r;
		else pp->RightChild=r;		
	}
	//�����Ľڵ����
	else if(x<ba1->data){                          //L��
		if(ba1->balance==-1){       //�����ƽ��
			ChangeBalance(root,x);
			if (x<pp->data) pp->LeftChild=r;
			else pp->RightChild=r;
		}
		else if(x<ba1->LeftChild->data){     //LL
			if (x<pp->data) pp->LeftChild=r;
			else pp->RightChild=r;
			RightRotate(ba1);
			TotalChangeBalance(ba1);//�ı�ƽ������
		}
		else if(x>ba1->LeftChild->data){       //LR
			if (x<pp->data) pp->LeftChild=r;
			else pp->RightChild=r;
			LeftRotate(ba1->LeftChild);
			RightRotate(ba1);
			TotalChangeBalance(ba1);//�ı�ƽ������
		}}
	else if(x>ba1->data){        //R��	
		if(ba1->balance==1){       //�����ƽ��
			ChangeBalance(root,x);
			if (x<pp->data) pp->LeftChild=r;
			else pp->RightChild=r;		
		}
		else if(x>ba1->RightChild->data){     //RR
			if (x<pp->data) pp->LeftChild=r;
			else pp->RightChild=r;
			LeftRotate(ba1);
			TotalChangeBalance(ba1);//�ı�ƽ������
		}
		else if(x<ba1->RightChild->data){       //RL	
			if (x<pp->data) pp->LeftChild=r;
			else pp->RightChild=r;
			RightRotate(ba1->RightChild);
			LeftRotate(ba1);
			TotalChangeBalance(ba1);//�ı�ƽ������
		}}
}    
template <class T>            
void AvlTree<T>::ChangeBalance(AvlTreeNode<T> *t,T x){                                        //����ת�������¸���ƽ������
	AvlTreeNode<T> *p=root,*pp=0;   // pp is the parent of p
	while (p) {                     // examine p->data
       pp=p;
	   if (x<p->data){
		   p=p->LeftChild;
		   pp->balance+=1;
	   }
       else if(x>p->data) {
		   p=p->RightChild;
		   pp->balance-=1;
	   }
	}
}
template <class T>
int AvlTree<T>::height(AvlTreeNode<T> *t)                                                //����������ĸ߶�
{
   if (!t) return 0;              
   int hl = height(t->LeftChild);  
   int hr = height(t->RightChild); 
   if (hl > hr) return ++hl;
   else return ++hr;
}
template<class T>
void AvlTree<T>::PreOrder(void(*Visit)(AvlTreeNode<T> *u), AvlTreeNode<T> *t)               //�������
{
	if(t){
		Visit(t);
   	    PreOrder(Visit,t->LeftChild);
   	    PreOrder(Visit,t->RightChild);
	}
}
template <class T>
void AvlTree<T>::Order1(void(*Visit)(AvlTreeNode<T> *u),AvlTreeNode<T> *t,int m)            //�������
	                                                //mΪ�ڵ�ĸ߶�
{
	if (t){
        Order1(Visit,t->RightChild,m+1);
		for(int i=0;i<m;i++)
			cout<<"         ";
        Visit(t);
		cout<<endl;
		Order1(Visit,t->LeftChild,m+1);
	}
}
template <class T>
void AvlTree<T>::NearestLeaf()                                                                  //���AVL���о�����ڵ������Ҷ�ڵ��ֵ
{
	LinkedQueue<AvlTreeNode<T>*> Q;     //����
	AvlTreeNode<T> *t=root;       
	bool end1=0;      //�ж��Ƿ�����Ҷ�ڵ����һ��
	if (!t) return ;      //�ն��������Ϊ0
	int nextw=0,curw=1;         //nextwΪ��һ���ȣ�curwΪ��ǰ��Ŀ��
	while(t){               //��������ʱ           
		while(curw!=0){
			curw--;			 
			if(t->LeftChild) {		   //���������ڣ���һ���ȼ�һ		
				Q.Add(t->LeftChild);				
				nextw++;			
			}			
			if(t->RightChild) {			 //���������ڣ���һ���ȼ�һ	
				Q.Add(t->RightChild);				
				nextw++;		
			}
			if((t->LeftChild==nullptr)&&(t->RightChild==nullptr)) {  //����Ҷ�ڵ�ʱ
				cout<<t->data<<" ";
				end1=1;                //������Ҷ�ڵ���һ��
			}
			try {Q.Delete(t);}            //����
			catch (OutOfBounds) {return;}
		}
		if(end1) return;            //����ڵ��������Ҷ�ڵ����һ�������ϣ�����
		curw=nextw;
		nextw=0;
	}	
}