#include"SparseMatrix.h"
void main(void)
{
	try{
	SparseMatrix<int> A(20);
	cin >> A;
	cout << "Matrix A is" << endl << A;
	int i,j,x;
	cout<<"�洢����i��j�е�ֵ��Ϊx������i,j,x����"<<endl;
	cin>>i>>j>>x;
	A.Store(i,j,x);
    cout << "After Store, New Matrix A is" << endl << A;
	cout<<"ȡ�ã�ȡ��i��j�У�����i,j����";
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