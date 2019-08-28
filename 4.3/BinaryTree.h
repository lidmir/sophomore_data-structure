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
    BinaryTreeNode<T> *LeftChild,*RightChild;   //��������
};

template<class T>
class BinaryTree {
public:
	BinaryTree() {root=nullptr;};
    ~BinaryTree(){}; 
    bool IsEmpty() const{return ((root)?false:true);}    //�Ƿ�Ϊ��
    bool Root(T& x) const;                               //���ظ���ֵ
    void MakeTree(const T& element,BinaryTree<T>& left, BinaryTree<T>& right);  //���ɶ�����
	void LevelOrder(void(*Visit)(BinaryTreeNode<T> *u));    //�����˳�����������
    void LevelOutput() {LevelOrder(Output); cout<<endl;}    //��������˳��������������
	void ChangeLR(){PostOrder(Change,root);}                //���������������нڵ����������
	int CountLeafOutput(){return CountLeaf(root);}          //ͳ��Ҷ�ڵ����
	int CountLeaf(BinaryTreeNode<T> *t)const;   //ͳ��Ҷ�ڵ���
	void WidthOutput(){cout<<Width(root)<<endl;}               //������������
	void PostOrder(void(*Visit)(BinaryTreeNode<T> *u)){PostOrder(Visit, root);}//�������
	
	//������׺���ʽ������������������ڼ���
	void Order1(void(*Visit)(BinaryTreeNode<T> *u)){Order1(Visit, root,0);};
    void Order1Output() { Order1(Output, root,0); cout << endl;};     
private:
	BinaryTreeNode<T> *root;  // ָ���
	void PostOrder(void(*Visit)(BinaryTreeNode<T> *u), BinaryTreeNode<T> *t);  //�������
	static void Output(BinaryTreeNode<T> *t){cout<< t->data<< ' ';}   //���
	static void Change(BinaryTreeNode<T> *t);	   //���������������нڵ����������	

	int Width(BinaryTreeNode<T>* t);        //������������
	void Order1(void(*Visit)(BinaryTreeNode<T> *u), BinaryTreeNode<T> *t,int m);
};


template<class T>
bool BinaryTree<T>::Root(T& x) const       //���ظ���ֵ
{
	if (root) {
		x=root->data;
		return true;} 
	else return false;  //û�и�
}
template<class T>
void BinaryTree<T>::MakeTree(const T& element,BinaryTree<T>& left, BinaryTree<T>& right)     //���ɶ�����
{
	root = new BinaryTreeNode<T>(element, left.root, right.root);
    left.root=right.root=0;
}
template <class T>
void BinaryTree<T>::LevelOrder(void(*Visit)(BinaryTreeNode<T> *u))      //������
{
	LinkedQueue<BinaryTreeNode<T>*> Q;     //����
	BinaryTreeNode<T> *t;
	t = root;
    while(t){
		Visit(t);
        if (t->LeftChild) Q.Add(t->LeftChild);    //���ӽ���
        if (t->RightChild) Q.Add(t->RightChild);  //�Һ��ӽ���
        try {Q.Delete(t);}            //������
        catch (OutOfBounds) {return;}
	}
}
template <class T>
void BinaryTree<T>::Change(BinaryTreeNode<T> *t){	   //���������������нڵ����������	
		BinaryTreeNode<T> *current;         //������ת�������ڵ�
		current=t->LeftChild;
		t->LeftChild=t->RightChild;
		t->RightChild=current;
	}
template <class T>
int BinaryTree<T>::CountLeaf(BinaryTreeNode<T> *t)const      //ͳ��Ҷ�ڵ����
{
	if(t==0) return 0;
	else if(t->LeftChild==NULL&&t->RightChild==NULL)          //��Ҷ�ڵ㣬����1
			return 1;
	else
			return (CountLeaf(t->LeftChild)+CountLeaf(t->RightChild));
}
template <class T>
int BinaryTree<T>::Width(BinaryTreeNode<T>* t)       //�������t�������
{
	if (t==NULL) return 0;      //�ն��������Ϊ0
	else {
		int maxw=1;	               //�����
		int nextw=0,curw=1;         //nextwΪ��һ���ȣ�curwΪ��ǰ��Ŀ��
		LinkedQueue<BinaryTreeNode<T>*> Q;
		while(t){               //��������ʱ           
			while(curw!=0){
				curw--;			 
				if(t->LeftChild) {		//���������ڣ���һ���ȼ�һ		
					Q.Add(t->LeftChild);				
					nextw++;			
				}			
				if(t->RightChild) {				
					Q.Add(t->RightChild);				
					nextw++;		
				}
				try {Q.Delete(t);}            //����
				catch (OutOfBounds) {return maxw;}
			}
			curw=nextw;
			if(nextw>maxw) maxw=nextw; //�����Ĳ�������maxw
			nextw=0;
		}
		return maxw;
	}
}
template <class T>         //�������
void BinaryTree<T>::PostOrder(void(*Visit)(BinaryTreeNode<T> *u),BinaryTreeNode<T> *t)
{
	if (t){
		PostOrder(Visit,t->LeftChild);
        PostOrder(Visit,t->RightChild);
        Visit(t);
	}
}

//������׺���ʽ������������������ڼ���
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


