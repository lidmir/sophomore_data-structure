#include"Stack.h"
#include<fstream>

template <class T>
class BinaryTreeNode {
	template <class T> friend class BinaryTree;
public: 
	BinaryTreeNode() {LeftChild=RightChild=0;};                 //���캯��
    BinaryTreeNode(const T& e){data=e; LeftChild=RightChild=0;};
    BinaryTreeNode(const T& e, BinaryTreeNode *l,BinaryTreeNode *r){data=e;LeftChild=l;RightChild=r;};
private:
    T data;
    BinaryTreeNode<T> *LeftChild,*RightChild; // ��������
};

template<class T>
class BinaryTree {            //������
public:
	BinaryTree() {root=new BinaryTreeNode<T>;root=nullptr;};
    ~BinaryTree(){}; 
    bool IsEmpty() const{return ((root)?false:true);}         //�Ƿ��
    void Order1(void(*Visit)(BinaryTreeNode<T> *u)){Order1(Visit, root,0);};        //������������������������˳�����
    void Order1Output() { Order1(Output, root,0); cout << endl;};      //���    
	void Order1File(BinaryTreeNode<T> *t,int m);          //������ļ�
	void Order1FileOutput(){Order1File(root,0);};
	void MakeStringTree(char* a);   //���������׺���ʽ��Ϊ������
private:
	BinaryTreeNode<T> *root;  // pointer to root
    void Order1(void(*Visit)(BinaryTreeNode<T> *u), BinaryTreeNode<T> *t,int m);
	static void Output(BinaryTreeNode<T> *t){cout<< t->data<< ' ';};  
};

ofstream fout("input.txt"); 
template <class T>
void BinaryTree<T>::Order1File(BinaryTreeNode<T> *t,int m)   //���������д����ļ�input.txt
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
void BinaryTree<T>::Order1(void(*Visit)(BinaryTreeNode<T> *u),BinaryTreeNode<T> *t,int m)  //������������������������˳�����
	                                                                                       //mΪ�ڵ�ĸ߶�
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
void BinaryTree<T>::MakeStringTree(char* str)      //���������׺���ʽ��Ϊ������
{
	Stack<BinaryTreeNode<T>*> tree;
	Stack<char> op;
	BinaryTreeNode<T> *tree1;
	for (unsigned int i=0;i< strlen(str); i++)  
    {  
		
        if(str[i]!='+'&&str[i]!='-'&&str[i]!='/'&&str[i]!='*'&&str[i]!='('&&str[i]!=')')    //�����Ƿ�������ΪҶ�ӽڵ�  
        {  
			tree1 = new BinaryTreeNode<T>;
			tree1->data=str[i];
			tree1->LeftChild=0;
			tree1->RightChild=0;
            tree.Push(tree1);  
        }  
		else{   //�Ƿ��ŵ�ʱ��
			if (!op.IsEmpty() && (str[i] == '+' || str[i] == '-')&&(op.Top()!='('))  //ջ���� �� ��������Ԫ�����ȼ���ջ��Ԫ�صͣ���������  
			{  
				tree1 = new BinaryTreeNode<T>;
				tree1->data = op.Top();  
				tree1->RightChild=tree.Pop();   
				tree1->LeftChild= tree.Pop(); 
				tree.Push(tree1);  
				op.Pop();  
				op.Push(str[i]);  
			}  
			else if(str[i]==')')    //�����������ŵ����
			{
				while(op.Top()!='('){             //ֱ����������������
					tree1 = new BinaryTreeNode<T>;
					tree1->data = op.Top();  
					tree1->RightChild=tree.Pop();   
				    tree1->LeftChild= tree.Pop(); 
					tree.Push(tree1);  
					op.Pop();  }
				op.Pop();  //������
			}		
			else  op.Push(str[i]);    //���������������ѹջ
        } 
	}
    while(!op.IsEmpty())    //ջ�ǿգ���ʣ��Ԫ�س�ջ��������
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