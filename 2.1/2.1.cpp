#include"diagonalMatrix.h"
void main(){
	try{
	cout<<"����������ά����";
	int n;
	cin>>n;
	diagonalMatrix<int> a(n);
	cout<<"��һ������a��"<<endl;
	cout<<"������"<<n<<"��Ԫ��"<<endl;
	cin>>a;
	cout<<a;
	diagonalMatrix<int> b(n);
	cout<<"�ڶ�������b��"<<endl;
	cout<<"������"<<n<<"��Ԫ��"<<endl;
	cin>>b;
	cout<<b;
	cout<<"a+b:"<<endl;
	cout<<a+b;
	cout<<"a-b:"<<endl;
	cout<<a-b;
	cout<<"a*b:"<<endl;
	cout<<a*b;
	cout<<"a��ת�ã�"<<endl;
	cout<<a.transpose();
	}
	catch(BadInitializers e){
		cout<<"Bad Initializers"<<endl;}
	catch(OutOfBounds e){
		cout<<"Out Of Bounds"<<endl;}
	catch(MustBeZero e){
		cout<<"Must Be Zero"<<endl;}
	catch(SizeMismatch e){
		cout<<"Size Mismatch"<<endl;}
}

