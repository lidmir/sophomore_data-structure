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
	ofstream fout("input.txt");        //������ļ�input.txt��
	fout<<n<<" "<<m;
	fout.close();
	ifstream fin("input.txt");         //��input.txt�ж�ȡm��n
	fin>>n>>m;
	fin.close();
	if(n>100||n<3||m<1)               //m,n������Ҫ��
		cout<<"WRONG"<<endl;
	else{                           //m,n����Ҫ��
		linearlist<int> a;
		for(int i=0;i<n;i++)         //����ֵ
			a.Insert(i,i+1);
		chain<int> a1;
		for(int i=0;i<n;i++)         //���Ա�ֵ
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
void Josephus1(linearlist<T>& a,int n,int m){    //���Ա�
	int j=0,k=1,y;           //j��b������Ԫ�ص��±�
	                         //k����a�����е�Ԫ�ص��±�+1
	                         //������ݵ���תy
	                         //nΪa�����ʵʱ����              
	linearlist<T> b(100);       //b����������ű�ɾ��������
	for(int i=1;n>=1;i++){      //i��ѭ������
		if(k>n) k=1;            //��k����ֵ����ʣ�µ�����ʱ����k�ص���һ��
		if(i%m==0){             //����m��ʱ��
			a.Delete(k,y);      //ɾ��a���鱻������Ԫ��y
			b.Insert(j++,y);     //�Ž�b������
			--n;                 //������һ
			--k;                 //a������±��һ
		}
		k++;
	}
	cout<<b;
}
template<class T>
void JosephusChain(chain<T> &a,int n,int m){    //����
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