#include"BinaryTree.h"
void main(){
	try{
	cout<<"������һ����׺���ʽ��"<<endl;
	char* str;
	str= new char;
	cin>>str;
	BinaryTree<char> x;
	x.MakeStringTree(str);
	x.Order1Output();        //�����������涨�������Ļ��
	x.Order1FileOutput();    //����������ļ�input.txt��
	}
	catch(OutOfBounds){
	cout<<"Out Of Bounds"<<endl;}
	catch(NoMem){
	cout<<"No Memory"<<endl;}
}