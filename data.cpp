#include<iostream>
#include<iomanip>
#include<fstream>
using namespace std;
int i = 0;
int k=0;
struct Student
{
	double number;
	char name[10];
	int sex;
	int age;
	char major[20];
}stu[30];

struct award
{
	double number;
	char Details[2000];
}awd[30];


void input()
{
	ifstream inf;
	inf.open("student.txt",fstream::in);

	while(!inf.eof())
	{
		inf>>stu[i].number;
		inf>>stu[i].name;
		inf>>stu[i].sex;
		inf>>stu[i].age;
		inf>>stu[i].major;
		++i;
	}
	inf.close();
	inf.open("award.txt",fstream::in);

	while(!inf.eof())
	{
		inf>>awd[k].number;
		inf>>awd[k].Details;
		++k;
	}
	inf.close();
	
} 

void display()
{
	cout<<"学号  姓名  性别  年龄  专业 奖励\n"<<endl;
	cout.precision(4);	
	for(int j = 0;j < i;j++){					//输出学生信息 
		cout<<setw(5)<<stu[j].number;
		cout<<setw(8)<<stu[j].name;
		if(stu[j].sex == 0)		cout<<setw(4)<<"男";
		else cout<<setw(4)<<"女";
		cout<<setw(5)<<stu[j].age
			<<setw(8)<<stu[j].major;

			for(int u = 0;u < k;u++)
			{
				if(stu[j].number == awd[u].number)
					cout<<setw(50)<<awd[u].Details;
			}
		cout<<endl;
	} 	
}

void display(int j){			 //输出指定学号的学生 
	cout<<"\n\t\t              学生数据表\n\n";
	cout<<"学号  姓名  性别  年龄  专业 奖励\n"<<endl;
	cout.precision(4);
	for(int u = 0;u < i;u++){		//找出学号是X的学生的结构体下标 
		if(stu[u].number == j){
			j = u;
			break;
		}
	}
	cout<<setw(5)<<stu[j].number;
	cout<<setw(8)<<stu[j].name;
	if(stu[j].sex == 0)		cout<<setw(4)<<"男";
	else cout<<setw(4)<<"女";
	cout<<setw(5)<<stu[j].age
		<<setw(8)<<stu[j].major;

		for(int u = 0;u < k;u++)
		{
			if(stu[j].number == awd[u].number)
				cout<<setw(50)<<awd[u].Details;
		}
	cout<<endl;
}

void add()
{
	int j = i;				//add函数增添学生信息 
m1:	cout<<"请分别输入学学号  姓名  性别  年龄  专业 奖励空格隔开"<<endl;
	char *temp;
	cin>>stu[j].number>>stu[j].name>>stu[j].age>>stu[j].major>>awd[k].Details;
	awd[k].number = stu[j].number;

	j = j + 1; 
	i = i + 1;
	k = k+1;
m2:	cout<<"是否继续录入y/s"<<endl;
	char y;
	cin>>y;
	if(y == 'y')	goto m1;
	if(y == 's')	return;
	else{
		cout<<"输入有误，请重新输入"<<endl;
		goto m2;
	}
}
void del(){				//del函数删除学生信息 
	cout<<"请输入要删除学生的学号"<<endl;
	int j;
	cin>>j;
	for(int w = 0;w < i;w++){		//找出学号是X的学生的结构体下标 
		if(stu[w].number == j){
			j = w;
			break;
		}
	}
	
	for(int q = j;q < i;q++){
		stu[q] = stu[q + 1];
	}
	i = i - 1;	
	int e = 0;
	for(int m = 0;m < k;m++)
	{
		if(stu[k].number == awd[m].number)
		{
			e = m;
			break;
		}

	}
	
	for(int q = e;q < k;q++)
	{
		awd[q] = awd[q + 1];
		
	}
	k -= 1;

}

void edi(){				//edi函数修改学生信息 
	cout<<"请输入要修改学生的学号"<<endl;
	int j,m;
	cin>>j;
	for(int k = 0;k < i;k++){		//找出学号是X的学生的结构体下标 
		if(stu[k].number == j){
			j = k;
			break;
		}
	}
	for(int k = 0;k < i;k++){		//找出学号是X的学生的结构体下标 
		if(awd[k].number == stu[j].number){
			m = k;
			break;
		}
	}
	cout<<"请分别输入学学号  姓名  性别  年龄  专业 奖励空格隔开"<<endl;
	cin>>stu[j].number>>stu[j].name>>stu[j].sex>>stu[j].age>>awd[m].Details;
	awd[m].number = stu[j].number;
}

void find(){					//查找学生信息 
	cout<<setw(45)<<"请输入学生学号"<<endl;
	int j;
	cin>>j;
	display(j);
}	


void output()
{
	ofstream onf;
	onf.open("student1.txt",fstream::out);
	for(int m = 0;m < i;m++)
	{
		onf<<stu[m].number<<" "<<stu[m].name<<" "<<stu[m].sex<<" "<<stu[m].age<<" "<<stu[m].major<<endl;	

	}
	
	onf.close();
	
	onf.open("award1.txt",fstream::out);
	
	for(int m = 0;m < k;m++)
	{
		onf<<awd[m].number<<" "<<awd[m].Details<<endl;
	} 
	onf.close();
}
void edit(){					//学生信息编辑函数 
m1:		cout<<setw(45)<<"请输入您所需的功能"<<endl;
		cout<<setw(45)<<"1.增加学生信息"<<endl;
		cout<<setw(45)<<"2.删除学生信息"<<endl;
		cout<<setw(45)<<"3.修改学生信息"<<endl;
		cout<<setw(45)<<"4.查找学生信息"<<endl;
		int m;
		cin>>m;
		switch(m){
			case 1:
				add();
				cout<<"录入完成"<<endl;
				display();
				output();
				break;
			case 2:
				del();
				cout<<"删除完成"<<endl;
				display();
				output();
				break;
			case 3:
				edi();
				cout<<"修改完成"<<endl;
				break;
				output();
			case 4:
				find();
				output();
				break;
			default:
				cout<<"输入有误，请重新输入"<<endl;
				goto m1;
				break;
		}
}
int main()
{
	input();
	display();
	edit();
	return 0;
}
