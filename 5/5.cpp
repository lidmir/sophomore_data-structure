#include"AVL.h"
void main(){
	int x;
	AvlTree<int> a;
	cout<<"����һ���ؼ������У������Է����ֱ�ʾ������:"<<endl;
	while(cin>>x){
		a.Insert(x);
		if(x=='*') break;
	}
	a.Order1Output();
	cout<<"AVL���ĸ߶�:"<<a.Height()<<endl;
	cout<<"����AVL���о�����ڵ������Ҷ�ڵ��ֵ:";
	a.NearestLeaf();
	cout<<endl;
}