#include"AVL.h"
void main(){
	int x;
	AvlTree<int> a;
	cout<<"输入一个关键字序列（序列以非数字表示结束）:"<<endl;
	while(cin>>x){
		a.Insert(x);
		if(x=='*') break;
	}
	a.Order1Output();
	cout<<"AVL树的高度:"<<a.Height()<<endl;
	cout<<"返回AVL树中距离根节点最近的叶节点的值:";
	a.NearestLeaf();
	cout<<endl;
}