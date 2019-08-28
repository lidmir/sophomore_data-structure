#include"diagonalMatrix.h"
void main(){
	try{
	cout<<"请输入矩阵的维数：";
	int n;
	cin>>n;
	diagonalMatrix<int> a(n);
	cout<<"第一个矩阵a："<<endl;
	cout<<"请输入"<<n<<"个元素"<<endl;
	cin>>a;
	cout<<a;
	diagonalMatrix<int> b(n);
	cout<<"第二个矩阵b："<<endl;
	cout<<"请输入"<<n<<"个元素"<<endl;
	cin>>b;
	cout<<b;
	cout<<"a+b:"<<endl;
	cout<<a+b;
	cout<<"a-b:"<<endl;
	cout<<a-b;
	cout<<"a*b:"<<endl;
	cout<<a*b;
	cout<<"a的转置："<<endl;
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

