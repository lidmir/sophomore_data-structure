#include"deque.h"
#include<fstream>
#include<string>
#include<stdlib.h>

void main(){
	try{
	Deque<int> b;
	int x=0;              //用于放要存入的数值
	string a[100];        //放操作序列
	cout<<"给出一个操作序列："<<endl;   
	for(int i=0;i<100;i++){
		cin>>a[i];
		if(a[i]=="End") break;
	}
	cout<<"-------------------"<<endl;
	for(int i=0;a[i]!="End";i++){          //对操作数列处理
		if(a[i]=="AddLeft") {              //AddLeft
			if (b.IsFull()) cout<<"FULL"<<endl;     //队列已满输出FULL
			else{
				if(*a[i+1].data()<'0'||*a[i+1].data()>'9') {  //后一个字符串不是数字输出WRONG
					cout<<"WRONG"<<endl;     
					i++;                //跳到下一条操作序列
				}
				else{             //是数字则在队列左端插入
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
				if(*a[i+1].data()<'0'||*a[i+1].data()>'9'){  //后一个字符串不是数字输出WRONG
					cout<<"WRONG"<<endl;
					i++;            //跳到下一条操作序列
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
			if (b.IsEmpty()) cout<<"EMPTY"<<endl;  //队列全空输出EMPTY
			else{
				b.DeleteLeft(x);
				b.Print();
			}
			continue;
		}
		if(a[i]=="DeleteRight") {              //DeleteRight
			if (b.IsEmpty()) cout<<"EMPTY"<<endl;  //队列全空输出EMPTY
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

	ofstream fout("input.txt");     //将操作序列存入文件input.txt
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
