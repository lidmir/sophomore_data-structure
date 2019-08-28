#include"BinaryTree.h"
void main(){
	try{
	cout<<"请输入一个中缀表达式："<<endl;
	char* str;
	str= new char;
	cin>>str;
	BinaryTree<char> x;
	x.MakeStringTree(str);
	x.Order1Output();        //将二叉树按规定输出到屏幕上
	x.Order1FileOutput();    //将输出存入文件input.txt中
	}
	catch(OutOfBounds){
	cout<<"Out Of Bounds"<<endl;}
	catch(NoMem){
	cout<<"No Memory"<<endl;}
}