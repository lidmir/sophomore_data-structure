#include"deque.h"
#include<fstream>
#include<string>
#include<stdlib.h>

void main(){
	try{
	Deque<int> b;
	int x=0;              //���ڷ�Ҫ�������ֵ
	string a[100];        //�Ų�������
	cout<<"����һ���������У�"<<endl;   
	for(int i=0;i<100;i++){
		cin>>a[i];
		if(a[i]=="End") break;
	}
	cout<<"-------------------"<<endl;
	for(int i=0;a[i]!="End";i++){          //�Բ������д���
		if(a[i]=="AddLeft") {              //AddLeft
			if (b.IsFull()) cout<<"FULL"<<endl;     //�����������FULL
			else{
				if(*a[i+1].data()<'0'||*a[i+1].data()>'9') {  //��һ���ַ��������������WRONG
					cout<<"WRONG"<<endl;     
					i++;                //������һ����������
				}
				else{             //���������ڶ�����˲���
					x=atoi(a[++i].data());     
					b.AddLeft(x);
				}
				b.Print();
			}
			continue;
		}
		if(a[i]=="AddRight") {           //AddRight
			if (b.IsFull()) cout<<"FULL"<<endl;
			else{
				if(*a[i+1].data()<'0'||*a[i+1].data()>'9'){  //��һ���ַ��������������WRONG
					cout<<"WRONG"<<endl;
					i++;            //������һ����������
				}
				else{
					x=atoi(a[++i].data());
					b.AddRight(x);
				}
				b.Print();
			}
			continue;
		}
		if(a[i]=="DeleteLeft") {               //DeleteLeft
			if (b.IsEmpty()) cout<<"EMPTY"<<endl;  //����ȫ�����EMPTY
			else{
				b.DeleteLeft(x);
				b.Print();
			}
			continue;
		}
		if(a[i]=="DeleteRight") {              //DeleteRight
			if (b.IsEmpty()) cout<<"EMPTY"<<endl;  //����ȫ�����EMPTY
			else{
				b.DeleteRight(x);
				b.Print();
			}
			continue;
		}
		if(a[i]=="IsEmpty") {              //IsEmpty
			if(b.IsEmpty()) cout<<"Yes"<<endl;
			else cout<<"No"<<endl;
			continue;
		}
		if(a[i]=="IsFull") {              //IsFull
			if(b.IsFull()) cout<<"Yes"<<endl;
			else cout<<"No"<<endl;
			continue;
		}
		cout<<"WRONG"<<endl;
	}
	cout<<endl<<"---------------"<<endl;

	ofstream fout("input.txt");     //���������д����ļ�input.txt
	for(int i=0;i<100;i++){
		fout<<a[i];
		if(a[i]=="AddRight"||a[i]=="AddLeft") fout<<" ";
		else fout<<endl;
		if(a[i]=="End") break;
	}
	fout.close();
	}
	catch(OutOfBounds){
		cout<<"Out Of Bounds"<<endl;}
	catch(NoMem){
		cout<<"No Memory"<<endl;}
}
