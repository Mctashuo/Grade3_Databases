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
	cout<<"ѧ��  ����  �Ա�  ����  רҵ ����\n"<<endl;
	cout.precision(4);	
	for(int j = 0;j < i;j++){					//���ѧ����Ϣ 
		cout<<setw(5)<<stu[j].number;
		cout<<setw(8)<<stu[j].name;
		if(stu[j].sex == 0)		cout<<setw(4)<<"��";
		else cout<<setw(4)<<"Ů";
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

void display(int j){			 //���ָ��ѧ�ŵ�ѧ�� 
	cout<<"\n\t\t              ѧ�����ݱ�\n\n";
	cout<<"ѧ��  ����  �Ա�  ����  רҵ ����\n"<<endl;
	cout.precision(4);
	for(int u = 0;u < i;u++){		//�ҳ�ѧ����X��ѧ���Ľṹ���±� 
		if(stu[u].number == j){
			j = u;
			break;
		}
	}
	cout<<setw(5)<<stu[j].number;
	cout<<setw(8)<<stu[j].name;
	if(stu[j].sex == 0)		cout<<setw(4)<<"��";
	else cout<<setw(4)<<"Ů";
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
	int j = i;				//add��������ѧ����Ϣ 
m1:	cout<<"��ֱ�����ѧѧ��  ����  �Ա�  ����  רҵ �����ո����"<<endl;
	char *temp;
	cin>>stu[j].number>>stu[j].name>>stu[j].age>>stu[j].major>>awd[k].Details;
	awd[k].number = stu[j].number;

	j = j + 1; 
	i = i + 1;
	k = k+1;
m2:	cout<<"�Ƿ����¼��y/s"<<endl;
	char y;
	cin>>y;
	if(y == 'y')	goto m1;
	if(y == 's')	return;
	else{
		cout<<"������������������"<<endl;
		goto m2;
	}
}
void del(){				//del����ɾ��ѧ����Ϣ 
	cout<<"������Ҫɾ��ѧ����ѧ��"<<endl;
	int j;
	cin>>j;
	for(int w = 0;w < i;w++){		//�ҳ�ѧ����X��ѧ���Ľṹ���±� 
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

void edi(){				//edi�����޸�ѧ����Ϣ 
	cout<<"������Ҫ�޸�ѧ����ѧ��"<<endl;
	int j,m;
	cin>>j;
	for(int k = 0;k < i;k++){		//�ҳ�ѧ����X��ѧ���Ľṹ���±� 
		if(stu[k].number == j){
			j = k;
			break;
		}
	}
	for(int k = 0;k < i;k++){		//�ҳ�ѧ����X��ѧ���Ľṹ���±� 
		if(awd[k].number == stu[j].number){
			m = k;
			break;
		}
	}
	cout<<"��ֱ�����ѧѧ��  ����  �Ա�  ����  רҵ �����ո����"<<endl;
	cin>>stu[j].number>>stu[j].name>>stu[j].sex>>stu[j].age>>awd[m].Details;
	awd[m].number = stu[j].number;
}

void find(){					//����ѧ����Ϣ 
	cout<<setw(45)<<"������ѧ��ѧ��"<<endl;
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
void edit(){					//ѧ����Ϣ�༭���� 
m1:		cout<<setw(45)<<"������������Ĺ���"<<endl;
		cout<<setw(45)<<"1.����ѧ����Ϣ"<<endl;
		cout<<setw(45)<<"2.ɾ��ѧ����Ϣ"<<endl;
		cout<<setw(45)<<"3.�޸�ѧ����Ϣ"<<endl;
		cout<<setw(45)<<"4.����ѧ����Ϣ"<<endl;
		int m;
		cin>>m;
		switch(m){
			case 1:
				add();
				cout<<"¼�����"<<endl;
				display();
				output();
				break;
			case 2:
				del();
				cout<<"ɾ�����"<<endl;
				display();
				output();
				break;
			case 3:
				edi();
				cout<<"�޸����"<<endl;
				break;
				output();
			case 4:
				find();
				output();
				break;
			default:
				cout<<"������������������"<<endl;
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
