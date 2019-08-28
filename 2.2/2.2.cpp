#include"TriByCols.h"
void main(){
	try{
	cout<<"请输入矩阵的维数：";
	int n;
	cin>>n;
	cout<<"第一个矩阵a："<<endl;
	cout<<"请输入"<<3*n-2<<"个元素"<<endl;
	TriByCols<int> a(n);
	cin>>a;
	cout<<a;
	int i,j,x;
	cout<<"搜索：搜索i行j列（输入i,j）：";
	cin>>i>>j;
	cout<<a.search(i,j)<<endl;
	cout<<"存储：将i行j列的值存为x（输入i,j,x）："<<endl;
	cin>>i>>j>>x;
	a.store(i,j,x);
	cout<<a;
	cout<<"第二个矩阵b："<<endl;
	cout<<"请输入"<<3*n-2<<"个元素"<<endl;
	TriByCols<int> b(n);
	cin>>b;
	cout<<b;
	cout<<"a+b:"<<endl;
	cout<<a+b;
	cout<<"a-b:"<<endl;
	cout<<a-b;
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