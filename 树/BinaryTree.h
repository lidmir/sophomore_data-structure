#include"LinkedQueue.h"

template<class E, class K> class BSTree;
template<class T> class BinaryTree;

template <class T>
class BinaryTreeNode {
	friend BSTree<T,int>;
	friend BinaryTree<T>;
public:
	BinaryTreeNode() {LeftChild=RightChild=0;}
    BinaryTreeNode(const T& e){data=e; LeftChild=RightChild=0;}
    BinaryTreeNode(const T& e, BinaryTreeNode *l,BinaryTreeNode *r){data=e;LeftChild=l;RightChild=r;}
private:
    T data;
    BinaryTreeNode<T> *LeftChild,*RightChild; // left and right subtree
};

template<class T>
class BinaryTree {
	 friend BSTree<T,int>;
public:
	BinaryTree() {root=0;};
    ~BinaryTree(){}; 
    bool IsEmpty() const{return ((root)?false:true);}
    bool Root(T& x) const;
    void MakeTree(const T& element,BinaryTree<T>& left, BinaryTree<T>& right);
    void BreakTree(T& element, BinaryTree<T>& left,BinaryTree<T>& right);
    void PreOrder(void(*Visit)(BinaryTreeNode<T> *u)){PreOrder(Visit, root);}
    void InOrder(void(*Visit)(BinaryTreeNode<T> *u)){InOrder(Visit, root);}
    void PostOrder(void(*Visit)(BinaryTreeNode<T> *u)){PostOrder(Visit, root);}
	void LevelOrder(void(*Visit)(BinaryTreeNode<T> *u));
	void PreOutput() {PreOrder(Output, root); cout << endl;}
    void InOutput() {InOrder(Output, root); cout << endl;}
    void PostOutput() {PostOrder(Output, root); cout << endl;}
    void LevelOutput() {LevelOrder(Output); cout << endl;}
	int Height() const {return Height(root);}
private:
	BinaryTreeNode<T> *root;  // pointer to root
    void PreOrder(void(*Visit)(BinaryTreeNode<T> *u), BinaryTreeNode<T> *t);
    void InOrder(void(*Visit)(BinaryTreeNode<T> *u), BinaryTreeNode<T> *t);
    void PostOrder(void(*Visit)(BinaryTreeNode<T> *u), BinaryTreeNode<T> *t);
	static void Output(BinaryTreeNode<T> *t){cout<< t->data<< ' ';}
	int Height(BinaryTreeNode<T> *t) const;
};
template<class T>
bool BinaryTree<T>::Root(T& x) const
{
	if (root) {
		x=root->data;
		return true;} 
	else return false;  // no root
}
template<class T>
void BinaryTree<T>::MakeTree(const T& element,BinaryTree<T>& left, BinaryTree<T>& right)
{
	root = new BinaryTreeNode<T>(element, left.root, right.root);
    left.root=right.root=0;
}
template<class T>
void BinaryTree<T>::BreakTree(T& element,BinaryTree<T>& left, BinaryTree<T>& right)
{
	if (!root) throw BadInput(); // tree empty
    element=root->data;
    left.root=root->LeftChild;
    right.root=root->RightChild;
    delete root;
    root=0;
}
template<class T>
void BinaryTree<T>::PreOrder(void(*Visit)(BinaryTreeNode<T> *u), BinaryTreeNode<T> *t)
{
	if(t){
		Visit(t);
   	    PreOrder(Visit,t->LeftChild);
   	    PreOrder(Visit,t->RightChild);
	}
}
template <class T>
void BinaryTree<T>::InOrder(void(*Visit)(BinaryTreeNode<T> *u),BinaryTreeNode<T> *t)
{
	if (t) {
		InOrder(Visit,t->LeftChild);
   	    Visit(t);
   	    InOrder(Visit,t->RightChild);
	}
}
template <class T>
void BinaryTree<T>::PostOrder(void(*Visit)(BinaryTreeNode<T> *u),BinaryTreeNode<T> *t)
{
	if (t){
		PostOrder(Visit,t->LeftChild);
        PostOrder(Visit,t->RightChild);
        Visit(t);
	}
}
template <class T>
void BinaryTree<T>::LevelOrder(void(*Visit)(BinaryTreeNode<T> *t))      //Öð²ã±éÀú
{
	LinkedQueue<BinaryTreeNode<T>*> Q;
    while(t){
		Visit(t);
        if (t->LeftChild) Q.Add(t->LeftChild);
        if (t->RightChild) Q.Add(t->RightChild);
        try {Q.Delete(t);}            //³ö¶Ó
        catch (OutOfBounds) {return;}
	}
}
template <class T>
int BinaryTree<T>::Height(BinaryTreeNode<T> *t) const
{
   if (!t) return 0;              
   int hl = Height(t->LeftChild);  
   int hr = Height(t->RightChild); 
   if (hl > hr) return ++hl;
   else return ++hr;
}