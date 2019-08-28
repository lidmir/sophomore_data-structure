#include"BinaryTree.h"
template<class T>
void PostTurnTree(BinaryTree<T> &t,Stack<T> post1);
template<class T>
void InChangePost(T str[],Stack<T> &post1);
void main(){
	try{
	char str[80];
	cout<<"Please input the expression:"<<endl;      
	cin>>str;           //������ʽ
	Stack<char> post1;
	Stack<char> ss;
	InChangePost(str,post1);     //����׺���ʽת���ɺ�׺��������post1ջ��
	while(!post1.IsEmpty()){       //���post1�ǿ�
		char t;
		post1.Pop(t); //����post1ջ��������t
		ss.Push(t);      //��tѹ��ssջ��    
	}         
	BinaryTree<char> B;
    PostTurnTree(B,ss);     //����׺��ɶ�����B
	B.Order1Output();        //�����������涨�������Ļ��
	cout<<"�����˳�����������(����˳��):";
	B.LevelOutput();
	cout<<"��������Ҷ�ڵ����Ŀ:";
	cout<<B.CountLeafOutput()<<endl;
	cout<<"�������Ŀ��:";
	B.WidthOutput();
	cout<<"���������������нڵ����������:"<<endl;
	B.ChangeLR();
	B.Order1Output();
	}
	catch(OutOfBounds){
		cout<<"Out Of Bounds"<<endl;}
}
//����Ϊ�����������׺���ʽ�������Ϊ��
template<class T>
void PostTurnTree(BinaryTree<T> &t,Stack<T> post1){     //��������ʽ�����
	Stack<BinaryTree<T>> BTStack;     
	T str;      
	BinaryTree<T> L,R,l,r;   //L,RΪ�����ն�����
	                          //l��r������ת
	while(!post1.IsEmpty()){    
		post1.Pop(str);      
		if((str!='+')&&(str!='-')&&(str!='/')&&(str!='*')&&(str!='(')&&(str!=')'))//�����Ƿ�������ΪҶ�ӽڵ�
		{  
			l.MakeTree(str,L,R);   
			BTStack.Push(l);   //��Ҷ�ڵ�ѹջ
		}       
		else{          
			BTStack.Pop(r);       //�ȵ���ջ��Ԫ����Ϊ������r
			BTStack.Pop(l);      //�ٵ���ջ����Ԫ����Ϊ������l
			t.MakeTree(str,l,r);    //������
			BTStack.Push(t);   //�����õ���tѹ��xջ��
		}
	}
}         

template<class T>
int priority(T x){           //�жϷ��ŵ����ȼ�
	if(x=='(') return 1;       
	if(x=='*'||x=='/') return 2;
	if(x=='+'||x=='-') return 3;
	else return 0;
}

template<class T>
void InChangePost(T str[],Stack<T> &post1){       //����׺���ʽת���ɺ�׺���ʽ
	Stack<T> curr1;      //��תջ
	T x;               
	for(int i=0;str[i]!='\0';i++){            //��������
		if((str[i]!='+')&&(str[i]!='-')&&(str[i]!='/')&&(str[i]!='*')&&(str[i]!='(')&&(str[i]!=')'))  //������Ƿ��ţ�post1ѹջ
			post1.Push(str[i]);   			
		else if(curr1.IsEmpty()||str[i]=='('||priority(str[i])>priority(curr1.Top()))  //ջ�ջ����ȼ�����ջ��	
			curr1.Push(str[i]);    				
		else if(str[i]==')')
		{   //��������    				
			while(curr1.Top()!='(')
			{   					
				curr1.Pop(x);        				
				post1.Push(x);  		
			}			
			curr1.Pop(x);     //����"("			
		}
		else
		{    //���ȼ�С��ջ��
			curr1.Pop(x);     
			post1.Push(x);   
			curr1.Push(str[i]);
		} 
	}
	while(!curr1.IsEmpty()){        //curr1ջ�ǿգ���ʣ���ջѹ��post1
		curr1.Pop(x);      
		post1.Push(x);     
	}
}	