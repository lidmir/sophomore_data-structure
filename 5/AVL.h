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
	AvlTreeNode<T> *LeftChild,*RightChild; // 左右子树
	int balance;        //平衡因子
};

template <class T>
class AvlTree{
public:
	AvlTree(){root=nullptr;};
	~AvlTree(){};
	bool IsEmpty() const{return ((root)?false:true);}              //判断是否为空
	bool Root(T& x) const{if(root){x=root->data;return 1;} return 0; }       //返回根的值
	void Insert(T x);
	int Height();
	void NearestLeaf();   
	void Order1Output() {Order1(Output, root,0);cout<<endl;};      //纵向输出  
private:
	AvlTreeNode<T> *root;          //根
	void LeftRotate(AvlTreeNode<T> *t);           
	void RightRotate(AvlTreeNode<T> *t);
	void ChangeBalance(AvlTreeNode<T> *t,T x);                           //不旋转的条件下更改平衡因子   
	void TotalChangeBalance(AvlTreeNode<T> *t){PreOrder(Balance,t);}      //全部更改平衡因子
	void PreOrder(void(*Visit)(AvlTreeNode<T> *u), AvlTreeNode<T> *t);          //先序遍历
	static int height(AvlTreeNode<T> *t) ;       //计算二叉树的高度
	void Order1(void(*Visit)(AvlTreeNode<T> *u), AvlTreeNode<T> *t,int m);      //纵向遍历
	static void Balance(AvlTreeNode<T> *t)       //计算Avl树的平衡因子
	{            
		int hl1=height(t->LeftChild);
		int hr1=height(t->RightChild);
		t->balance=hl1-hr1;
	}
	static void Output(AvlTreeNode<T> *t){cout<< t->data<< '('<<t->balance<<") ";};   //输出的函数
};
template <class T>
int AvlTree<T>::Height()                                       //计算AVL树的高度
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
void AvlTree<T>::LeftRotate(AvlTreeNode<T> *t){                                          //逆时针旋转
	if((!t)||(t->RightChild)) return;
	AvlTreeNode<T> *p=new AvlTreeNode<T>(t->data);   //p用来替换原有root
	AvlTreeNode<T> *q=t->RightChild;   //q为原root右子树，用来删去新root的原位置
	p->LeftChild=t->LeftChild;
	t->LeftChild=p;
	p->RightChild=q->LeftChild;
	t->data=q->data;
	t->RightChild=q->RightChild;
	delete q;
}
template <class T>
void AvlTree<T>::RightRotate(AvlTreeNode<T> *t){                                           //顺时针旋转
	if((!t)||(t->LeftChild)) return;
	AvlTreeNode<T> *p=new AvlTreeNode<T>(t->data);   //p用来替换原有root
	AvlTreeNode<T> *q=t->LeftChild;   //q为原root左子树，用来删去新root的原位置
	p->RightChild=t->RightChild;
	t->RightChild=p;
	p->LeftChild=q->RightChild;
	t->data=q->data;
	t->LeftChild=q->LeftChild;
	delete q;
}

template <class T>
void AvlTree<T>::Insert(T x){                                                                   //插入新节点
	AvlTreeNode<T> *r = new AvlTreeNode<T>(x);        //r表示要插入的新节点
	if (!root) {root=r;return;}                      //根节点不存在
	Stack<AvlTreeNode<T>*> stacka;      
	AvlTreeNode<T> *p=root,*pp=0;   // pp是p父节点
	while(p){                       // 找到x应插入的位置
		pp=p;
		stacka.Push(p);
	    if (x<p->data) p=p->LeftChild;
        else if(x>p->data) p=p->RightChild;
	    else return ;              // AVL中已有该元素，直接返回
	}
    //根节点存在
	AvlTreeNode<T> *ba1=new AvlTreeNode<T>;
	bool findd=0;        //判断符合条件的节点是否存在
	while(!stacka.IsEmpty()) {        //寻找最后一个平衡因子为1或-1的节点ba1
		stacka.Pop(ba1);
		if((ba1->balance==1)||(ba1->balance==-1)) {findd =1; break;}
	}
	if(!findd){                     //这样的节点不存在
		ChangeBalance(root,x);
		if (x<pp->data) pp->LeftChild=r;
		else pp->RightChild=r;		
	}
	//这样的节点存在
	else if(x<ba1->data){                          //L型
		if(ba1->balance==-1){       //插入后平衡
			ChangeBalance(root,x);
			if (x<pp->data) pp->LeftChild=r;
			else pp->RightChild=r;
		}
		else if(x<ba1->LeftChild->data){     //LL
			if (x<pp->data) pp->LeftChild=r;
			else pp->RightChild=r;
			RightRotate(ba1);
			TotalChangeBalance(ba1);//改变平衡因子
		}
		else if(x>ba1->LeftChild->data){       //LR
			if (x<pp->data) pp->LeftChild=r;
			else pp->RightChild=r;
			LeftRotate(ba1->LeftChild);
			RightRotate(ba1);
			TotalChangeBalance(ba1);//改变平衡因子
		}}
	else if(x>ba1->data){        //R型	
		if(ba1->balance==1){       //插入后平衡
			ChangeBalance(root,x);
			if (x<pp->data) pp->LeftChild=r;
			else pp->RightChild=r;		
		}
		else if(x>ba1->RightChild->data){     //RR
			if (x<pp->data) pp->LeftChild=r;
			else pp->RightChild=r;
			LeftRotate(ba1);
			TotalChangeBalance(ba1);//改变平衡因子
		}
		else if(x<ba1->RightChild->data){       //RL	
			if (x<pp->data) pp->LeftChild=r;
			else pp->RightChild=r;
			RightRotate(ba1->RightChild);
			LeftRotate(ba1);
			TotalChangeBalance(ba1);//改变平衡因子
		}}
}    
template <class T>            
void AvlTree<T>::ChangeBalance(AvlTreeNode<T> *t,T x){                                        //不旋转的条件下更改平衡因子
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
int AvlTree<T>::height(AvlTreeNode<T> *t)                                                //计算二叉树的高度
{
   if (!t) return 0;              
   int hl = height(t->LeftChild);  
   int hr = height(t->RightChild); 
   if (hl > hr) return ++hl;
   else return ++hr;
}
template<class T>
void AvlTree<T>::PreOrder(void(*Visit)(AvlTreeNode<T> *u), AvlTreeNode<T> *t)               //先序遍历
{
	if(t){
		Visit(t);
   	    PreOrder(Visit,t->LeftChild);
   	    PreOrder(Visit,t->RightChild);
	}
}
template <class T>
void AvlTree<T>::Order1(void(*Visit)(AvlTreeNode<T> *u),AvlTreeNode<T> *t,int m)            //纵向遍历
	                                                //m为节点的高度
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
void AvlTree<T>::NearestLeaf()                                                                  //输出AVL树中距离根节点最近的叶节点的值
{
	LinkedQueue<AvlTreeNode<T>*> Q;     //队列
	AvlTreeNode<T> *t=root;       
	bool end1=0;      //判断是否到了有叶节点的那一层
	if (!t) return ;      //空二叉树宽度为0
	int nextw=0,curw=1;         //nextw为下一层宽度，curw为当前层的宽度
	while(t){               //当根存在时           
		while(curw!=0){
			curw--;			 
			if(t->LeftChild) {		   //左子树存在，下一层宽度加一		
				Q.Add(t->LeftChild);				
				nextw++;			
			}			
			if(t->RightChild) {			 //右子树存在，下一层宽度加一	
				Q.Add(t->RightChild);				
				nextw++;		
			}
			if((t->LeftChild==nullptr)&&(t->RightChild==nullptr)) {  //发现叶节点时
				cout<<t->data<<" ";
				end1=1;                //到了有叶节点那一层
			}
			try {Q.Delete(t);}            //出队
			catch (OutOfBounds) {return;}
		}
		if(end1) return;            //离根节点最近的有叶节点的那一层出队完毕，返回
		curw=nextw;
		nextw=0;
	}	
}