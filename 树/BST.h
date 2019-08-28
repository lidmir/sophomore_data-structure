#include"BinaryTree.h"

template<class E, class K>
class BSTree : public BinaryTree<E> {
public:      
	   bool Search(const K& k, E& e) const;      
	   BSTree<E,K>& Insert(const E& e);      
	   BSTree<E,K>& Delete(const K& k, E& e);
};

template<class E, class K>
bool BSTree<E,K>::Search(const K& k, E &e) const
{
	BinaryTreeNode<E> *p = root;
	while (p){                   // examine p->data  
		if (k<p->data) p=p->LeftChild;    		
		else if (k>p->data) p=p->RightChild;           
		else {                   // found element                 
			e=p->data;                 
			return true;
		}   
	}
	return false;
}

template<class E, class K>
BSTree<E,K>& BSTree<E,K>::Insert(const E& e)
{
	BinaryTreeNode<E> *p=root,*pp=0;   // pp is the parent of p
	while (p) {                     // examine p->data
       pp=p;
	   if (e<p->data) p=p->LeftChild;
       else if(e>p->data) p=p->RightChild;
	   else return *this;;          // 二叉搜索树中已有该元素
      }
	BinaryTreeNode<E> *r = new BinaryTreeNode<E> (e);
    if (root) {
		if (e<pp->data) pp->LeftChild=r;
        else pp->RightChild=r;}
    else 
        root = r;
    return *this;
}

template<class E, class K>
BSTree<E,K>& BSTree<E,K>::Delete(const K& k, E& e)
{
	BinaryTreeNode<E> *p=root,*pp=0;   // pp is the parent of p
	while (p && p->data != k){          // move to a child of p
		pp=p;
        if (k<p->data) p=p->LeftChild;
        else p=p->RightChild; 
	}
	if (!p) throw BadInput();
	e = p->data;           // save element to delete

	if (p->LeftChild && p->RightChild) {// two children
  		BinaryTreeNode<E> *s=p->LeftChild,*ps = p;  // parent of s 
		while(s->RightChild){
			ps=s;
            s=s->RightChild;
		}
		p->data=s->data;
		p=s;
        pp=ps;
	}
	BinaryTreeNode<E> *c;         // p has at most one child 
    if (p->LeftChild) c=p->LeftChild;
    else c=p->RightChild;
   // delete p
    if (p==root) root=c;
    else{                         // is p left or right child of pp?
		if (p==pp->LeftChild)
			pp->LeftChild=c;
		else pp->RightChild=c;}
	delete p;
    return *this;
}