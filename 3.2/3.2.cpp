#include"Stack.h"
void main(){
	try{
	char x,b[100];    //存放输入数据的数组b和要删除的数据x
	int k=0;
	Stack<char> a;
	cout<<"要压栈的字符数:";
	cin>>k;
	cout<<"输入要删除的数据项x:";
	cin>>x;	
	cout<<"按栈底到栈顶的顺序依次输入栈中字符:";
	for(int i=0;i<k;i++)
		cin>>b[i];
	ofstream fout("input.txt");					   //将数据入到input.txt中
	fout<<x<<endl; 
	for(int i=0;i<k;i++)
		fout<<b[i]<<" ";
	fout.close();
	ifstream fin("input.txt");					   //从input.txt中输出
	fin>>x;
	for(int i=0;i<k;i++)
		fout<<b[i];
	fin.close();
	for(int i=0;i<k;i++)             //将b中元素压栈a
		a.push(b[i]);
	cout<<"----------------"<<endl;
	delete_all(a,x);                  //删除栈a中有数据量x的元素
	cout<<endl<<"----------------"<<endl;
	}
	catch(BadInitializers){
		cout<<"Bad Initializers"<<endl;}
	catch(OutOfBounds){
		cout<<"Out Of Bounds"<<endl;}
	catch(NoMem){
		cout<<"Insufficient Memory"<<endl;}
}