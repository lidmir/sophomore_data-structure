#include"BinaryTree.h"
template<class T>
void PostTurnTree(BinaryTree<T> &t,Stack<T> post1);
template<class T>
void InChangePost(T str[],Stack<T> &post1);
void main(){
	try{
	char str[80];
	cout<<"Please input the expression:"<<endl;      
	cin>>str;           //输入表达式
	Stack<char> post1;
	Stack<char> ss;
	InChangePost(str,post1);     //将中缀表达式转换成后缀，保存在post1栈中
	while(!post1.IsEmpty()){       //如果post1非空
		char t;
		post1.Pop(t); //弹出post1栈顶，存入t
		ss.Push(t);      //将t压入ss栈中    
	}         
	BinaryTree<char> B;
    PostTurnTree(B,ss);     //将后缀变成二叉树B
	B.Order1Output();        //将二叉树按规定输出到屏幕上
	cout<<"按层次顺序遍历二叉树(遍历顺序):";
	B.LevelOutput();
	cout<<"二叉树的叶节点的数目:";
	cout<<B.CountLeafOutput()<<endl;
	cout<<"二叉树的宽度:";
	B.WidthOutput();
	cout<<"交换二叉树中所有节点的左右子树:"<<endl;
	B.ChangeLR();
	B.Order1Output();
	}
	catch(OutOfBounds){
		cout<<"Out Of Bounds"<<endl;}
}
//以下为处理输入的中缀表达式，将其变为树
template<class T>
void PostTurnTree(BinaryTree<T> &t,Stack<T> post1){     //将后序表达式变成树
	Stack<BinaryTree<T>> BTStack;     
	T str;      
	BinaryTree<T> L,R,l,r;   //L,R为两个空二叉树
	                          //l，r用于中转
	while(!post1.IsEmpty()){    
		post1.Pop(str);      
		if((str!='+')&&(str!='-')&&(str!='/')&&(str!='*')&&(str!='(')&&(str!=')'))//若不是符号则作为叶子节点
		{  
			l.MakeTree(str,L,R);   
			BTStack.Push(l);   //将叶节点压栈
		}       
		else{          
			BTStack.Pop(r);       //先弹出栈顶元素作为右子树r
			BTStack.Pop(l);      //再弹出栈顶的元素作为左子树l
			t.MakeTree(str,l,r);    //制作树
			BTStack.Push(t);   //将做好的树t压入x栈中
		}
	}
}         

template<class T>
int priority(T x){           //判断符号的优先级
	if(x=='(') return 1;       
	if(x=='*'||x=='/') return 2;
	if(x=='+'||x=='-') return 3;
	else return 0;
}

template<class T>
void InChangePost(T str[],Stack<T> &post1){       //将中缀表达式转换成后缀表达式
	Stack<T> curr1;      //中转栈
	T x;               
	for(int i=0;str[i]!='\0';i++){            //遍历数组
		if((str[i]!='+')&&(str[i]!='-')&&(str[i]!='/')&&(str[i]!='*')&&(str[i]!='(')&&(str[i]!=')'))  //如果不是符号，post1压栈
			post1.Push(str[i]);   			
		else if(curr1.IsEmpty()||str[i]=='('||priority(str[i])>priority(curr1.Top()))  //栈空或优先级大于栈顶	
			curr1.Push(str[i]);    				
		else if(str[i]==')')
		{   //处理括号    				
			while(curr1.Top()!='(')
			{   					
				curr1.Pop(x);        				
				post1.Push(x);  		
			}			
			curr1.Pop(x);     //弹出"("			
		}
		else
		{    //优先级小于栈顶
			curr1.Pop(x);     
			post1.Push(x);   
			curr1.Push(str[i]);
		} 
	}
	while(!curr1.IsEmpty()){        //curr1栈非空，将剩余出栈压入post1
		curr1.Pop(x);      
		post1.Push(x);     
	}
}	