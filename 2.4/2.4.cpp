#include"SparseMatrix.h"
void main(void)
{
	try{
	SparseMatrix<int> A(20);
	cin >> A;
	cout << "Matrix A is" << endl << A;
	int i,j,x;
	cout<<"存储：将i行j列的值存为x（输入i,j,x）："<<endl;
	cin>>i>>j>>x;
	A.Store(i,j,x);
    cout << "After Store, New Matrix A is" << endl << A;
	cout<<"取得：取得i行j列（输入i,j）：";
	cin>>i>>j;
	cout<<"Retrieve("<<i<<","<<j<<")="<<A.Retrieve(i,j)<<endl;
	}
	catch(BadInitializers){
		cout<<"Bad Initializers"<<endl;}
	catch(OutOfBounds){
		cout<<"Out Of Bounds"<<endl;}
	catch(NoMem){
		cout<<"Insufficient Memory"<<endl;}
}