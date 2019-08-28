#include"cMatrix.h"
void main(){
	try{
	cout<<"请输入矩阵的维数：";
	int n;
	cin>>n;
	cMatrix<int> a(n);
	cout<<"请输入"<<3*n-2<<"个元素"<<endl;
	cin>>a;
	cout<<a;
	int i,j,x;
	cout<<"存储：将i行j列的值存为x（输入i,j,x）："<<endl;
	cin>>i>>j>>x;
	a.store(i,j,x);
    cout << "After Store, New Matrix A is" << endl << a;
	cout<<"取得：取得i行j列（输入i,j）：";
	cin>>i>>j;
	cout<<"Retrieve("<<i<<","<<j<<")="<<a.Retrieve(i,j)<<endl;
	}
	catch(BadInitializers){
		cout<<"Bad Initializers"<<endl;}
	catch(OutOfBounds){
		cout<<"Out Of Bounds"<<endl;}
	catch(MustBeZero){
		cout<<"Must Be Zero"<<endl;}
}