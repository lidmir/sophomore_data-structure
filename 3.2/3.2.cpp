#include"Stack.h"
void main(){
	try{
	char x,b[100];    //����������ݵ�����b��Ҫɾ��������x
	int k=0;
	Stack<char> a;
	cout<<"Ҫѹջ���ַ���:";
	cin>>k;
	cout<<"����Ҫɾ����������x:";
	cin>>x;	
	cout<<"��ջ�׵�ջ����˳����������ջ���ַ�:";
	for(int i=0;i<k;i++)
		cin>>b[i];
	ofstream fout("input.txt");					   //�������뵽input.txt��
	fout<<x<<endl; 
	for(int i=0;i<k;i++)
		fout<<b[i]<<" ";
	fout.close();
	ifstream fin("input.txt");					   //��input.txt�����
	fin>>x;
	for(int i=0;i<k;i++)
		fout<<b[i];
	fin.close();
	for(int i=0;i<k;i++)             //��b��Ԫ��ѹջa
		a.push(b[i]);
	cout<<"----------------"<<endl;
	delete_all(a,x);                  //ɾ��ջa����������x��Ԫ��
	cout<<endl<<"----------------"<<endl;
	}
	catch(BadInitializers){
		cout<<"Bad Initializers"<<endl;}
	catch(OutOfBounds){
		cout<<"Out Of Bounds"<<endl;}
	catch(NoMem){
		cout<<"Insufficient Memory"<<endl;}
}