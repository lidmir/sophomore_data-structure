#include"TriByCols.h"
void main(){
	try{
	cout<<"����������ά����";
	int n;
	cin>>n;
	cout<<"��һ������a��"<<endl;
	cout<<"������"<<3*n-2<<"��Ԫ��"<<endl;
	TriByCols<int> a(n);
	cin>>a;
	cout<<a;
	int i,j,x;
	cout<<"����������i��j�У�����i,j����";
	cin>>i>>j;
	cout<<a.search(i,j)<<endl;
	cout<<"�洢����i��j�е�ֵ��Ϊx������i,j,x����"<<endl;
	cin>>i>>j>>x;
	a.store(i,j,x);
	cout<<a;
	cout<<"�ڶ�������b��"<<endl;
	cout<<"������"<<3*n-2<<"��Ԫ��"<<endl;
	TriByCols<int> b(n);
	cin>>b;
	cout<<b;
	cout<<"a+b:"<<endl;
	cout<<a+b;
	cout<<"a-b:"<<endl;
	cout<<a-b;
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