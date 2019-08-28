#include"LinkedQueue.h"
#include"Stack.h"
template <class T>
class BinaryTreeNode {
	template<class T>friend class BinaryTree;
public:
	BinaryTreeNode() {LeftChild=RightChild=0;}
    BinaryTreeNode(const T& e){data=e; LeftChild=RightChild=0;}
    BinaryTreeNode(const T& e, BinaryTreeNode *l,BinaryTreeNode *r){data=e;LeftChild=l;RightChild=r;}
private:
    T data;
    BinaryTreeNode<T> *LeftChild,*RightChild;   //左右子树
};

template<class T>
class BinaryTree {
public:
	BinaryTree() {root=nullptr;};
    ~BinaryTree(){}; 
    bool IsEmpty() const{return ((root)?false:true);}    //是否为空
    bool Root(T& x) const;                               //返回根的值
    void MakeTree(const T& element,BinaryTree<T>& left, BinaryTree<T>& right);  //生成二叉树
	void LevelOrder(void(*Visit)(BinaryTreeNode<T> *u));    //按层次顺序遍历二叉树
    void LevelOutput() {LevelOrder(Output); cout<<endl;}    //输出按层次顺序遍历二叉树结果
	void ChangeLR(){PostOrder(Change,root);}                //交换二叉树中所有节点的左右子树
	int CountLeafOutput(){return CountLeaf(root);}          //统计叶节点个数
	int CountLeaf(BinaryTreeNode<T> *t)const;   //统计叶节点数
	void WidthOutput(){cout<<Width(root)<<endl;}               //输出二叉树宽度
	void PostOrder(void(*Visit)(BinaryTreeNode<T> *u)){PostOrder(Visit, root);}//后序遍历
	
	//处理中缀表达式并横向输出二叉树用于检验
	void Order1(void(*Visit)(BinaryTreeNode<T> *u)){Order1(Visit, root,0);};
    void Order1Output() { Order1(Output, root,0); cout << endl;};     
private:
	BinaryTreeNode<T> *root;  // 指向根
	void PostOrder(void(*Visit)(BinaryTreeNode<T> *u), BinaryTreeNode<T> *t);  //后序遍历
	static void Output(BinaryTreeNode<T> *t){cout<< t->data<< ' ';}   //输出
	static void Change(BinaryTreeNode<T> *t);	   //交换二叉树中所有节点的左右子树	

	int Width(BinaryTreeNode<T>* t);        //计算二叉树宽度
	void Order1(void(*Visit)(BinaryTreeNode<T> *u), BinaryTreeNode<T> *t,int m);
};


template<class T>
bool BinaryTree<T>::Root(T& x) const       //返回根的值
{
	if (root) {
		x=root->data;
		return true;} 
	else return false;  //没有根
}
template<class T>
void BinaryTree<T>::MakeTree(const T& element,BinaryTree<T>& left, BinaryTree<T>& right)     //生成二叉树
{
	root = new BinaryTreeNode<T>(element, left.root, right.root);
    left.root=right.root=0;
}
template <class T>
void BinaryTree<T>::LevelOrder(void(*Visit)(BinaryTreeNode<T> *u))      //逐层遍历
{
	LinkedQueue<BinaryTreeNode<T>*> Q;     //队列
	BinaryTreeNode<T> *t;
	t = root;
    while(t){
		Visit(t);
        if (t->LeftChild) Q.Add(t->LeftChild);    //左孩子进队
        if (t->RightChild) Q.Add(t->RightChild);  //右孩子进队
        try {Q.Delete(t);}            //根出队
        catch (OutOfBounds) {return;}
	}
}
template <class T>
void BinaryTree<T>::Change(BinaryTreeNode<T> *t){	   //交换二叉树中所有节点的左右子树	
		BinaryTreeNode<T> *current;         //用于中转二叉树节点
		current=t->LeftChild;
		t->LeftChild=t->RightChild;
		t->RightChild=current;
	}
template <class T>
int BinaryTree<T>::CountLeaf(BinaryTreeNode<T> *t)const      //统计叶节点个数
{
	if(t==0) return 0;
	else if(t->LeftChild==NULL&&t->RightChild==NULL)          //是叶节点，返回1
			return 1;
	else
			return (CountLeaf(t->LeftChild)+CountLeaf(t->RightChild));
}
template <class T>
int BinaryTree<T>::Width(BinaryTreeNode<T>* t)       //求二叉树t的最大宽度
{
	if (t==NULL) return 0;      //空二叉树宽度为0
	else {
		int maxw=1;	               //最大宽度
		int nextw=0,curw=1;         //nextw为下一层宽度，curw为当前层的宽度
		LinkedQueue<BinaryTreeNode<T>*> Q;
		while(t){               //当根存在时           
			while(curw!=0){
				curw--;			 
				if(t->LeftChild) {		//左子树存在，下一层宽度加一		
					Q.Add(t->LeftChild);				
					nextw++;			
				}			
				if(t->RightChild) {				
					Q.Add(t->RightChild);				
					nextw++;		
				}
				try {Q.Delete(t);}            //出队
				catch (OutOfBounds) {return maxw;}
			}
			curw=nextw;
			if(nextw>maxw) maxw=nextw; //将最大的层数存入maxw
			nextw=0;
		}
		return maxw;
	}
}
template <class T>         //后序遍历
void BinaryTree<T>::PostOrder(void(*Visit)(BinaryTreeNode<T> *u),BinaryTreeNode<T> *t)
{
	if (t){
		PostOrder(Visit,t->LeftChild);
        PostOrder(Visit,t->RightChild);
        Visit(t);
	}
}

//处理中缀表达式并横向输出二叉树用于检验
template <class T>
void BinaryTree<T>::Order1(void(*Visit)(BinaryTreeNode<T> *u),BinaryTreeNode<T> *t,int m)
{
	if (t){
        Order1(Visit,t->RightChild,m+1);
		for(int i=0;i<m;i++)
			cout<<"   ";
        Visit(t);
		cout<<endl;
		Order1(Visit,t->LeftChild,m+1);
	}
}


