#include"chain.h"
#include"linearlist.h"
template<class T>
void Josephus1(linearlist<T>& a,int n,int m);
template<class T>
void JosephusChain(chain<T> &a,int n,int m);
void main(){
	try{
	int n=0,m=0;
	cout<<"Please input n(3-100),m(1-m):";
	cin>>n>>m;
	ofstream fout("input.txt");        //输出到文件input.txt中
	fout<<n<<" "<<m;
	fout.close();
	ifstream fin("input.txt");         //从input.txt中读取m，n
	fin>>n>>m;
	fin.close();
	if(n>100||n<3||m<1)               //m,n不符合要求
		cout<<"WRONG"<<endl;
	else{                           //m,n符合要求
		linearlist<int> a;
		for(int i=0;i<n;i++)         //链表赋值
			a.Insert(i,i+1);
		chain<int> a1;
		for(int i=0;i<n;i++)         //线性表赋值
			a1.Insert(i,i+1);            
		cout<<"-----------------"<<endl;
		Josephus1(a,n,m);                
		JosephusChain(a1,n,m);
		cout<<endl<<"-----------------"<<endl;
	}
	}
	catch(OutOfBounds){
	cout<<"Out Of Bounds"<<endl;}
	catch(NoMem){
	cout<<"No Memory"<<endl;}
}
template<class T>
void Josephus1(linearlist<T>& a,int n,int m){    //线性表
	int j=0,k=1,y;           //j是b数组中元素的下标
	                         //k是在a数组中的元素的下标+1
	                         //存放数据的中转y
	                         //n为a数组的实时总数              
	linearlist<T> b(100);       //b数组用来存放被删除的数据
	for(int i=1;n>=1;i++){      //i是循环次数
		if(k>n) k=1;            //当k的数值大于剩下的总数时，将k回到第一个
		if(i%m==0){             //数到m的时候
			a.Delete(k,y);      //删除a数组被数到的元素y
			b.Insert(j++,y);     //放进b数组中
			--n;                 //总数减一
			--k;                 //a数组的下标减一
		}
		k++;
	}
	cout<<b;
}
template<class T>
void JosephusChain(chain<T> &a,int n,int m){    //链表
	int j=0,k=1,x=0;
	chain<T> b;
	for(int i=1;n>=1;i++){
		if(k>n) k=1;
		if(i%m==0){
			a.Delete(k,x);
			b.Insert(j++,x);
			--n;
			--k;
		}
		k++;
	}
	cout<<b;
}