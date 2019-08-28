#include"Stack.h"
#include<fstream>

template <class T>
class BinaryTreeNode {
	template <class T> friend class BinaryTree;
public: 
	BinaryTreeNode() {LeftChild=RightChild=0;};                 //构造函数
    BinaryTreeNode(const T& e){data=e; LeftChild=RightChild=0;};
    BinaryTreeNode(const T& e, BinaryTreeNode *l,BinaryTreeNode *r){data=e;LeftChild=l;RightChild=r;};
private:
    T data;
    BinaryTreeNode<T> *LeftChild,*RightChild; // 左右子树
};

template<class T>
class BinaryTree {            //二叉树
public:
	BinaryTree() {root=new BinaryTreeNode<T>;root=nullptr;};
    ~BinaryTree(){}; 
    bool IsEmpty() const{return ((root)?false:true);}         //是否空
    void Order1(void(*Visit)(BinaryTreeNode<T> *u)){Order1(Visit, root,0);};        //按先右子树，根，左子树的顺序遍历
    void Order1Output() { Order1(Output, root,0); cout << endl;};      //输出    
	void Order1File(BinaryTreeNode<T> *t,int m);          //输出到文件
	void Order1FileOutput(){Order1File(root,0);};
	void MakeStringTree(char* a);   //将输入的中缀表达式变为二叉树
private:
	BinaryTreeNode<T> *root;  // pointer to root
    void Order1(void(*Visit)(BinaryTreeNode<T> *u), BinaryTreeNode<T> *t,int m);
	static void Output(BinaryTreeNode<T> *t){cout<< t->data<< ' ';};  
};

ofstream fout("input.txt"); 
template <class T>
void BinaryTree<T>::Order1File(BinaryTreeNode<T> *t,int m)   //将操作序列存入文件input.txt
{	                                    
	if (t){
        Order1File(t->RightChild,m+1);
		for(int i=0;i<m;i++)
			fout<<"   ";
        fout<<t->data<<endl;
		Order1File(t->LeftChild,m+1);
	}
}
template <class T>
void BinaryTree<T>::Order1(void(*Visit)(BinaryTreeNode<T> *u),BinaryTreeNode<T> *t,int m)  //按先右子树，根，左子树的顺序遍历
	                                                                                       //m为节点的高度
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

template <class T>
void BinaryTree<T>::MakeStringTree(char* str)      //将输入的中缀表达式变为二叉树
{
	Stack<BinaryTreeNode<T>*> tree;
	Stack<char> op;
	BinaryTreeNode<T> *tree1;
	for (unsigned int i=0;i< strlen(str); i++)  
    {  
		
        if(str[i]!='+'&&str[i]!='-'&&str[i]!='/'&&str[i]!='*'&&str[i]!='('&&str[i]!=')')    //若不是符号则作为叶子节点  
        {  
			tree1 = new BinaryTreeNode<T>;
			tree1->data=str[i];
			tree1->LeftChild=0;
			tree1->RightChild=0;
            tree.Push(tree1);  
        }  
		else{   //是符号的时候
			if (!op.IsEmpty() && (str[i] == '+' || str[i] == '-')&&(op.Top()!='('))  //栈不空 且 遍历到的元素优先级比栈顶元素低，制作成树  
			{  
				tree1 = new BinaryTreeNode<T>;
				tree1->data = op.Top();  
				tree1->RightChild=tree.Pop();   
				tree1->LeftChild= tree.Pop(); 
				tree.Push(tree1);  
				op.Pop();  
				op.Push(str[i]);  
			}  
			else if(str[i]==')')    //处理遇到括号的情况
			{
				while(op.Top()!='('){             //直到遇到（，制作树
					tree1 = new BinaryTreeNode<T>;
					tree1->data = op.Top();  
					tree1->RightChild=tree.Pop();   
				    tree1->LeftChild= tree.Pop(); 
					tree.Push(tree1);  
					op.Pop();  }
				op.Pop();  //弹出（
			}		
			else  op.Push(str[i]);    //不是上述的情况，压栈
        } 
	}
    while(!op.IsEmpty())    //栈非空，将剩余元素出栈制作成树
    {  
		tree1 = new BinaryTreeNode<T>;
		tree1->data = op.Top();  
        op.Pop();  
        tree1->RightChild=tree.Pop();
        tree1->LeftChild= tree.Pop();          
        tree.Push(tree1); 
    }  
	root=tree1;
}