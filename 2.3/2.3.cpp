#include"cMatrix.h"
void main(){
	try{
	cout<<"����������ά����";
	int n;
	cin>>n;
	cMatrix<int> a(n);
	cout<<"������"<<3*n-2<<"��Ԫ��"<<endl;
	cin>>a;
	cout<<a;
	int i,j,x;
	cout<<"�洢����i��j�е�ֵ��Ϊx������i,j,x����"<<endl;
	cin>>i>>j>>x;
	a.store(i,j,x);
    cout << "After Store, New Matrix A is" << endl << a;
	cout<<"ȡ�ã�ȡ��i��j�У�����i,j����";
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