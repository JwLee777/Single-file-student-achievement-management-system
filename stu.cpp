#include <iostream>
#include <string>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;
const int MAX = 50;
int COUNT = 0;				

class Student
{
public:
	void Set();				
	void Add();				
	friend void Read(string no[], string name[], string sex[], string special[], double math[], double english[], double computer[], double ave[]);
	int Judge(string num);	
	void Delete();			
	void Change();			
	void Search();			
	void Display();			
	void Sum();				
	void Order();				
private:
	string m_no;
	string m_name;
	string m_sex;				
	string m_special;
	double m_math,m_english, m_computer, m_ave;
};

void Student::Set()
{
	string no, name, sex, special;
	double math,english, computer,ave;

	ofstream outfile("student.txt");		 //打开文件
	if (!outfile)
	{
		cerr << " open error" << endl;
		exit(1);		//退出程序
	}

	cout << "当学号输入为 0 时,停止输入!" << endl;
	cout << "请依次输入学生的学号,姓名,性别,专业,高数，英语，计算机成绩:" << endl;
	for (int i = 0; i < MAX; i++)
	{
		cout << "第" << COUNT + 1 << "个学生:" << endl;
		cin >> no;
		if (no == "0") break;		//当输入的学号是 0  时，停止录入
		cin >> name >> sex >> special >> math >> english >> computer;
		COUNT++;

		m_no = no;
		outfile << m_no << "\t";		//每录入一个学号，写进磁盘保存，以下同理

		m_name = name;
		outfile << m_name << "\t";

		m_sex = sex;
		outfile << m_sex << "\t";

		m_special = special;
		outfile << m_special << "\t";

		m_math = math;
		outfile << m_math << "\t";

		m_english = english;
		outfile << m_english << "\t";

		m_computer = computer;
		outfile << m_computer << "\t";

		m_ave = (math+english+computer)/3;
		outfile << setiosflags(ios::fixed) << setprecision(2)<< m_ave << endl;
		
	}
	outfile.close();
}

//添加学生信息
void Student::Add()
{
	string no, name, sex, special;
	double math, english, computer,ave;
	//以追加的方式录入信息，直接将信息追加到以前文件的末尾
	ofstream outfile("student.txt", ios::app);
	if (!outfile)
	{
		cerr << " open error" << endl;
		exit(1);
	}
	COUNT++;		//添加一个学生信息，当然 COUNT 要  +1
	cout << "请依次输入要添加的学生学号,姓名,性别,专业,高数，英语，计算机:" << endl;
	cin >> no>>name >> sex >> special >>  math >> english >> computer;

	m_no = no;
	outfile << m_no << "\t";

	m_name = name;
	outfile << m_name << "\t";

	m_sex = sex;
	outfile << m_sex << "\t";

	m_special = special;
	outfile << m_special << "\t";


	m_math = math;
	outfile << m_math << "\t";

	m_english = english;
	outfile << m_english << "\t";

	m_computer = computer;
	outfile << m_computer << "\t";

	m_ave = (math + english + computer) / 3;
	outfile << setiosflags(ios::fixed) << setprecision(2) << m_ave << endl;

	outfile.close();
	cout << "已添加成功!" << endl;
}
//从磁盘读取数据
 void Read(string no[], string name[], string sex[], string special[], double math[], double english[], double computer[], double ave[])
{
	ifstream in("student.txt");
	char str[MAX];//N是定义的常数，目的是为了读取足够长的行
	int n = 0;
	while (!in.eof())
	{
		in.getline(str, sizeof(str));
		n++;
	}
	COUNT= n-1;
	in.close();

	ifstream infile("student.txt", ios::in);
	if (!infile)
	{
		cerr << " open error" << endl;
		exit(1);
	}
	for (int i = 0; i < COUNT; i++)		
	{
		infile >> no[i] >> name[i] >> sex[i] >> special[i] >> math[i] >> english[i] >> computer[i]>>ave[i];
	}
	infile.close();
}

//判断某学号的学生是否在数据库中
int Student::Judge(string num)
{
	string no[MAX], name[MAX], sex[MAX], special[MAX];
	double math[MAX], english[MAX], computer[MAX], ave[MAX];
	Read(no, name, sex, special, math, english, computer, ave);	//调用Read()函数，获取数据，以便等下进行相关数据的判断

	for (int i = 0; i < COUNT; i++)
	{
		if (num == no[i])
		{
			return i;		//如果存在，返回其下标
			break;
		}
	}
	return -1;		//否则，返回-1
}



//删除某学生信息
void Student::Delete()
{
	string num, no[MAX], name[MAX], sex[MAX], special[MAX];
	double math[MAX], english[MAX], computer[MAX], ave[MAX];
	Read(no, name, sex, special,  math , english , computer,ave);	//读取学生所有数据，

	cout << "请输入你要删除的学生学号:";
	cin >> num;
	int k = Judge(num);			//定义一个k来接收Judge()的返回值，等下用来判断该num是否存在		
	if (k != -1)		//如果k不等于-1， 表示要删除的学生存在
	{
		ofstream outfile("student.txt");
		if (!outfile)
		{
			cerr << " open error" << endl;
			exit(1);
		}

		for (int i = 0; i < COUNT; i++)
		{
			if (i != k)		//把下标不等于K（即除了要删的学生外）其余的数据重新写入磁盘保存
			{
				outfile << no[i] << "\t";
				outfile << name[i] << "\t";
				outfile << sex[i] << "\t";
				outfile << special[i] << "\t";
				outfile << math[i] << "\t";
				outfile << english[i] << "\t";
				outfile << computer[i] << "\t";
				outfile << ave[i] << endl;
			}
		}
		outfile.close();
		COUNT--;		//删除一个学生，人数 -1
		cout << "删除成功!" << endl;
	}
	else
	cout << "该数据库没有此学生!" << endl;
}

void Student::Change()
{
	string num, no[MAX], name[MAX], sex[MAX], special[MAX];
	double math[MAX], english[MAX], computer[MAX], ave[MAX];

	cout << "请输入你要修改的学生学号:";
	cin >> num;
	int k = Judge(num);
	double d;
	if (k != -1)
	{
		Read(no, name, sex, special, math, english, computer, ave);	//读取学生所有数据，
		cout << "请依次输入修改后的学生学号,姓名,性别,专业,高数，英语，计算机:" << endl;
		cin >> no[k] >> name[k] >> sex[k] >> special[k] >> math[k] >> english[k] >> computer[k];	//把下标是k的学生进行修改
		d = (math[k] + english[k] + computer[k]) / 3;
		d = double((int)(d * 100)) / 100.0;
		ave[k]=d;
		ofstream outfile("student.txt", ios::out);
		if (!outfile)
		{
			cerr << " open error" << endl;
			exit(1);
		}
		for (int i = 0; i < COUNT; i++)		//改完后，回写进磁盘保存
		{
			outfile << no[i] << "\t";
			outfile << name[i] << "\t";
			outfile << sex[i] << "\t";
			outfile << special[i] << "\t";
			outfile << math[i] << "\t";
			outfile << english[i] << "\t";
			outfile << computer[i] << "\t";
			outfile << ave[i] << endl;
		}
		outfile.close();
		cout << "修改成功!" << endl;
	}
	else
		cout << "该数据库没有此学生!" << endl;
}

void Student::Search()
{
	string num, no[MAX], name[MAX], sex[MAX], special[MAX];
	double math[MAX], english[MAX], computer[MAX], ave[MAX];
	Read(no, name, sex, special, math, english, computer, ave);
	cout << "请输入你要查找的学生学号";
	cin >> num;

	int k = Judge(num);
	if (k != -1)			//找到该学生就打印出其信息
	{
		cout << "学号\t\t姓名\t性别\t专业\t高数\t英语\t计算机\t平均分" << endl;
		cout << no[k] << "\t";
		cout << name[k] << "\t";
		cout << sex[k] << "\t";
		cout << special[k] << "\t";
		cout << math[k] << "\t";
		cout << english[k] << "\t";
		cout << computer[k] << "\t";
		cout << ave[k] << endl;
	}
	else
		cout << "该数据库没有此学生!" << endl;
}
//显示学生的所有信息
void Student::Display()
{
	string no[MAX], name[MAX], sex[MAX], special[MAX];
	double math[MAX], english[MAX], computer[MAX], ave[MAX];
	Read(no, name, sex, special, math, english, computer, ave);

	cout << "学号\t\t姓名\t性别\t专业\t高数\t英语\t计算机\t平均分" << endl;
	for (int i = 0; i < COUNT; i++)		//后打印
	{
		cout << no[i] << "\t";
		cout << name[i] << "\t";
		cout << sex[i] << "\t";
		cout << special[i] << "\t";
		cout << math[i] << "\t";
		cout << english[i] << "\t";
		cout << computer[i] << "\t";
		cout << ave[i] << endl;
	}
}

void Student::Sum() {
	string no[MAX], name[MAX], sex[MAX], special[MAX];
	double math[MAX], english[MAX], computer[MAX], ave[MAX];
	Read(no, name, sex, special, math, english, computer, ave);
	int choic;
	cout << "请选择所需要的统计的科目:"<<endl;
	cout << "\t\t\t|  1.高等数学 |\n";
	cout << "\t\t\t|  2.英语     |\n";
	cout << "\t\t\t|  3.计算机   |\n";
	cin >> choic;
	int i, A=0, B=0, C=0, D=0, E=0;


	switch (choic)
	{
	case 1:
	{
		for (i = 0;i < COUNT;i++) {
			if (math[i] > 90)
				A++;
			else if (math[i] > 80)
				B++;
			else if (math[i] > 70)
				C++;
			else if (math[i] > 60)
				D++;
			else
				E++;
		}
		cout << "A段人数为" << A << "\tB段人数为" << B << "\tC段人数为" << C << "\tD段人数为" << D << "\t不及格人数为" << E;
	}
	break;
	case 2:
	{
		for (i = 0;i < COUNT;i++) {
			if (english[i] > 90)
				A++;
			else if (english[i] > 80)
				B++;
			else if (english[i] > 70)
				C++;
			else if (english[i] > 60)
				D++;
			else
				E++;
		}
		cout << "A段人数为" << A << "\tB段人数为" << B << "\tC段人数为" << C << "\tD段人数为" << D << "\t不及格人数为" << E;
	}
	break;
	case 3:
	{
		for (i = 0;i < COUNT;i++) {
			if (computer[i] > 90)
				A++;
			else if (computer[i] > 80)
				B++;
			else if (computer[i] > 70)
				C++;
			else if (computer[i] > 60)
				D++;
			else
				E++;
		}
		cout << "A段人数为" << A << "\tB段人数为" << B << "\tC段人数为" << C << "\tD段人数为" << D << "\t不及格人数为" << E;
	}
	break;
	default:
		cout << "你的选择有误!请重新选择!" << endl;
		break;
	}
}

void Student::Order()
{
	string no[MAX], name[MAX], sex[MAX], special[MAX];
	double math[MAX], english[MAX], computer[MAX], ave[MAX];
	Read(no, name, sex, special, math, english, computer, ave);
	for (int i = 0; i < COUNT; i++) {
		        // 找到从i开始到最后一个元素中最小的元素,k存储最小元素的下标.
			        int k = i;
		         for (int j = i + 1; j < COUNT; j++) {
			            if (ave[j] < ave[k]) { k = j; }
			
		}
		
			        // 将最小的元素a[k] 和 开始的元素a[i] 交换数据.
			       if (k != i) {
					   double temp;
					   temp = ave[k];
					   ave[k] = ave[i];
					   ave[i] = temp;
					   temp = computer[k];
					   computer[k] = computer[i];
					   computer[i] = temp;
					   temp = english[k];
					   english[k] = english[i];
					   english[i] = temp;
					   temp = math[k];
					   math[k] = math[i ];
					   math[i] = temp;
					   string temp1;
					   temp1 = no[k];
					   no[k] = no[i ];
					   no[i ] = temp1;
					   temp1 = name[k];
					   name[k] = name[i ];
					   name[i ] = temp1;
					   temp1 = sex[k];
					   sex[k] = sex[i ];
					   sex[i ] = temp1;
					   temp1 = special[k];
					   special[k] = special[i ];
					   special[i ] = temp1;
		}
	}
	ofstream outfile("student.txt");
	if (!outfile)
	{
		cerr << " open error" << endl;
		exit(1);
	}

	for (int i = 0; i < COUNT; i++)
	{

			outfile << no[i] << "\t";
			outfile << name[i] << "\t";
			outfile << sex[i] << "\t";
			outfile << special[i] << "\t";
			outfile << math[i] << "\t";
			outfile << english[i] << "\t";
			outfile << computer[i] << "\t";
			outfile << ave[i] << endl;
		
	}
	outfile.close();
	cout << "排序成功";
}


int main()
{
	int choice = -1;
	Student s;

	while (choice != 0)		//除非你选择退出，否则一直循环
	{
		cout << "\n\t\t\t--学生信息管理系统--\n\n";
		cout << "\t\t\t|  1.录入学生信息  |\n";
		cout << "\t\t\t|  2.添加一个信息  |\n";
		cout << "\t\t\t|  3.删除一个信息  |\n";
		cout << "\t\t\t|  4.修改学生信息  |\n";
		cout << "\t\t\t|  5.查询学生信息  |\n";
		cout << "\t\t\t|  6.显示学生信息  |\n";
		cout << "\t\t\t|  7.统计学生信息  |\n";
		cout << "\t\t\t|  8.学生信息排序  |\n";
		cout << "\t\t\t|  0.退出    系统  |\n";

		cout << "请选择所需要的操作:";
		cin >> choice;

		switch (choice)
		{
		case 1:
			s.Set();
			break;
		case 2:
			s.Add();
			break;
		case 3:
			s.Delete();
			break;
		case 4:
			s.Change();
			break;
		case 5:
			s.Search();
			break;
		case 6:
			s.Display();
			break;
		case 7:
			s.Sum();
			break;
		case 8:
			s.Order();
			break;
		case 0:
			break;
		default:
			cout << "你的选择有误!请重新选择!" << endl;
			break;
		}
	}

	return 0;
}
