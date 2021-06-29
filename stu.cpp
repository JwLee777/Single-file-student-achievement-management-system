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

	ofstream outfile("student.txt");		 //���ļ�
	if (!outfile)
	{
		cerr << " open error" << endl;
		exit(1);		//�˳�����
	}

	cout << "��ѧ������Ϊ 0 ʱ,ֹͣ����!" << endl;
	cout << "����������ѧ����ѧ��,����,�Ա�,רҵ,������Ӣ�������ɼ�:" << endl;
	for (int i = 0; i < MAX; i++)
	{
		cout << "��" << COUNT + 1 << "��ѧ��:" << endl;
		cin >> no;
		if (no == "0") break;		//�������ѧ���� 0  ʱ��ֹͣ¼��
		cin >> name >> sex >> special >> math >> english >> computer;
		COUNT++;

		m_no = no;
		outfile << m_no << "\t";		//ÿ¼��һ��ѧ�ţ�д�����̱��棬����ͬ��

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

//���ѧ����Ϣ
void Student::Add()
{
	string no, name, sex, special;
	double math, english, computer,ave;
	//��׷�ӵķ�ʽ¼����Ϣ��ֱ�ӽ���Ϣ׷�ӵ���ǰ�ļ���ĩβ
	ofstream outfile("student.txt", ios::app);
	if (!outfile)
	{
		cerr << " open error" << endl;
		exit(1);
	}
	COUNT++;		//���һ��ѧ����Ϣ����Ȼ COUNT Ҫ  +1
	cout << "����������Ҫ��ӵ�ѧ��ѧ��,����,�Ա�,רҵ,������Ӣ������:" << endl;
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
	cout << "����ӳɹ�!" << endl;
}
//�Ӵ��̶�ȡ����
 void Read(string no[], string name[], string sex[], string special[], double math[], double english[], double computer[], double ave[])
{
	ifstream in("student.txt");
	char str[MAX];//N�Ƕ���ĳ�����Ŀ����Ϊ�˶�ȡ�㹻������
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

//�ж�ĳѧ�ŵ�ѧ���Ƿ������ݿ���
int Student::Judge(string num)
{
	string no[MAX], name[MAX], sex[MAX], special[MAX];
	double math[MAX], english[MAX], computer[MAX], ave[MAX];
	Read(no, name, sex, special, math, english, computer, ave);	//����Read()��������ȡ���ݣ��Ա���½���������ݵ��ж�

	for (int i = 0; i < COUNT; i++)
	{
		if (num == no[i])
		{
			return i;		//������ڣ��������±�
			break;
		}
	}
	return -1;		//���򣬷���-1
}



//ɾ��ĳѧ����Ϣ
void Student::Delete()
{
	string num, no[MAX], name[MAX], sex[MAX], special[MAX];
	double math[MAX], english[MAX], computer[MAX], ave[MAX];
	Read(no, name, sex, special,  math , english , computer,ave);	//��ȡѧ���������ݣ�

	cout << "��������Ҫɾ����ѧ��ѧ��:";
	cin >> num;
	int k = Judge(num);			//����һ��k������Judge()�ķ���ֵ�����������жϸ�num�Ƿ����		
	if (k != -1)		//���k������-1�� ��ʾҪɾ����ѧ������
	{
		ofstream outfile("student.txt");
		if (!outfile)
		{
			cerr << " open error" << endl;
			exit(1);
		}

		for (int i = 0; i < COUNT; i++)
		{
			if (i != k)		//���±겻����K��������Ҫɾ��ѧ���⣩�������������д����̱���
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
		COUNT--;		//ɾ��һ��ѧ�������� -1
		cout << "ɾ���ɹ�!" << endl;
	}
	else
	cout << "�����ݿ�û�д�ѧ��!" << endl;
}

void Student::Change()
{
	string num, no[MAX], name[MAX], sex[MAX], special[MAX];
	double math[MAX], english[MAX], computer[MAX], ave[MAX];

	cout << "��������Ҫ�޸ĵ�ѧ��ѧ��:";
	cin >> num;
	int k = Judge(num);
	double d;
	if (k != -1)
	{
		Read(no, name, sex, special, math, english, computer, ave);	//��ȡѧ���������ݣ�
		cout << "�����������޸ĺ��ѧ��ѧ��,����,�Ա�,רҵ,������Ӣ������:" << endl;
		cin >> no[k] >> name[k] >> sex[k] >> special[k] >> math[k] >> english[k] >> computer[k];	//���±���k��ѧ�������޸�
		d = (math[k] + english[k] + computer[k]) / 3;
		d = double((int)(d * 100)) / 100.0;
		ave[k]=d;
		ofstream outfile("student.txt", ios::out);
		if (!outfile)
		{
			cerr << " open error" << endl;
			exit(1);
		}
		for (int i = 0; i < COUNT; i++)		//����󣬻�д�����̱���
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
		cout << "�޸ĳɹ�!" << endl;
	}
	else
		cout << "�����ݿ�û�д�ѧ��!" << endl;
}

void Student::Search()
{
	string num, no[MAX], name[MAX], sex[MAX], special[MAX];
	double math[MAX], english[MAX], computer[MAX], ave[MAX];
	Read(no, name, sex, special, math, english, computer, ave);
	cout << "��������Ҫ���ҵ�ѧ��ѧ��";
	cin >> num;

	int k = Judge(num);
	if (k != -1)			//�ҵ���ѧ���ʹ�ӡ������Ϣ
	{
		cout << "ѧ��\t\t����\t�Ա�\tרҵ\t����\tӢ��\t�����\tƽ����" << endl;
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
		cout << "�����ݿ�û�д�ѧ��!" << endl;
}
//��ʾѧ����������Ϣ
void Student::Display()
{
	string no[MAX], name[MAX], sex[MAX], special[MAX];
	double math[MAX], english[MAX], computer[MAX], ave[MAX];
	Read(no, name, sex, special, math, english, computer, ave);

	cout << "ѧ��\t\t����\t�Ա�\tרҵ\t����\tӢ��\t�����\tƽ����" << endl;
	for (int i = 0; i < COUNT; i++)		//���ӡ
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
	cout << "��ѡ������Ҫ��ͳ�ƵĿ�Ŀ:"<<endl;
	cout << "\t\t\t|  1.�ߵ���ѧ |\n";
	cout << "\t\t\t|  2.Ӣ��     |\n";
	cout << "\t\t\t|  3.�����   |\n";
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
		cout << "A������Ϊ" << A << "\tB������Ϊ" << B << "\tC������Ϊ" << C << "\tD������Ϊ" << D << "\t����������Ϊ" << E;
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
		cout << "A������Ϊ" << A << "\tB������Ϊ" << B << "\tC������Ϊ" << C << "\tD������Ϊ" << D << "\t����������Ϊ" << E;
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
		cout << "A������Ϊ" << A << "\tB������Ϊ" << B << "\tC������Ϊ" << C << "\tD������Ϊ" << D << "\t����������Ϊ" << E;
	}
	break;
	default:
		cout << "���ѡ������!������ѡ��!" << endl;
		break;
	}
}

void Student::Order()
{
	string no[MAX], name[MAX], sex[MAX], special[MAX];
	double math[MAX], english[MAX], computer[MAX], ave[MAX];
	Read(no, name, sex, special, math, english, computer, ave);
	for (int i = 0; i < COUNT; i++) {
		        // �ҵ���i��ʼ�����һ��Ԫ������С��Ԫ��,k�洢��СԪ�ص��±�.
			        int k = i;
		         for (int j = i + 1; j < COUNT; j++) {
			            if (ave[j] < ave[k]) { k = j; }
			
		}
		
			        // ����С��Ԫ��a[k] �� ��ʼ��Ԫ��a[i] ��������.
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
	cout << "����ɹ�";
}


int main()
{
	int choice = -1;
	Student s;

	while (choice != 0)		//������ѡ���˳�������һֱѭ��
	{
		cout << "\n\t\t\t--ѧ����Ϣ����ϵͳ--\n\n";
		cout << "\t\t\t|  1.¼��ѧ����Ϣ  |\n";
		cout << "\t\t\t|  2.���һ����Ϣ  |\n";
		cout << "\t\t\t|  3.ɾ��һ����Ϣ  |\n";
		cout << "\t\t\t|  4.�޸�ѧ����Ϣ  |\n";
		cout << "\t\t\t|  5.��ѯѧ����Ϣ  |\n";
		cout << "\t\t\t|  6.��ʾѧ����Ϣ  |\n";
		cout << "\t\t\t|  7.ͳ��ѧ����Ϣ  |\n";
		cout << "\t\t\t|  8.ѧ����Ϣ����  |\n";
		cout << "\t\t\t|  0.�˳�    ϵͳ  |\n";

		cout << "��ѡ������Ҫ�Ĳ���:";
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
			cout << "���ѡ������!������ѡ��!" << endl;
			break;
		}
	}

	return 0;
}
