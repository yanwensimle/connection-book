#include<iostream>
using namespace std;
//������ϵ�˽ṹ�壬ȷ����ϵ����Ϣ
struct linkman
{
	string name;
	int tel;
	string address;
};
//����һ����������ʾѡ�����
void showMenu()
{
	cout << "**************************" << endl;
	cout << "*****  1.������ϵ��  *****" << endl;
	cout << "*****  2.��ʾ��ϵ��  *****" << endl;
	cout << "*****  3.ɾ����ϵ��  *****" << endl;
	cout << "*****  4.������ϵ��  *****" << endl;
	cout << "*****  5.�޸���ϵ��  *****" << endl;
	cout << "*****  6.�����ϵ��  *****" << endl;
	cout << "*****  0.�˳�ͨѶ¼  *****" << endl;
	cout << "**************************" << endl;
}
//1.������ϵ��
//����Ϊ��ϵ������ĵ�ַ* arry����ϵ�˸����ĵ�ַ* p
void case1(linkman* arry, int* p)
{
		cout << "��������ϵ��������" << endl;
		cin >> arry[*p].name;
		cout << "��������ϵ�˵绰��" << endl;
		cin >> arry[*p].tel;
		cin.get();//�������ִ�������ʱ�򣬿��ܻ���������������޷�ִ�е�����������ַ������Ա���
		cout << "��������ϵ��סַ��" << endl;
		cin >> arry[*p].address;
		(*p)++;//�ٴ�ִ�е�ʱ����һ������Ԫ�ؽ�����Ϣ
}
//2.��ʾ��ϵ��
void case2(linkman* arry, int* p)
{
	//*p��ʾͨѶ¼�е�����
	//��ͨѶ¼�е���ϵ����Ϣ����������
	for (int j = 0; j < *p; j++)
	{
		cout << "��ϵ��������" << arry[j].name << ",��ϵ�˵绰��" << arry[j].tel << ",��ϵ�˵�ַ��" << arry[j].address << endl;
	}
}
//3.ɾ����ϵ��
void case3(linkman* arry, int* p)
{
	string dname;
	cout << "��������ϵ��������" << endl;
	cin >> dname;
	//ͨ���������Ҷ�Ӧ����ϵ��
	//��ͨѶ¼�е���ϵ�˽��б������������ϵ�˵�����������Ҫ�ҵ�һ������ô�������ϵ�˵���Ϣɾ�����������ϵ��ǰ�ƣ�������ղ���
	for (int j = 0; j < *p; j++)
	{
		if (arry[j].name == dname)
		{
			for (; j < *p; j++)
			{
				arry[j].name = arry[j + 1].name;
				arry[j].tel = arry[j + 1].tel;
				arry[j].address = arry[j + 1].address;
			}
			break;
		}
		else
		{
			cout << "�Բ��𣬲��޴���" << endl;
		}
	}
	(*p)--;//ɾ��һ����ϵ�˺���ϵ������������һ��
}
//4.������ϵ��
void case4(linkman* arry, int* p)
{
	string dname;
	cout << "��������ϵ��������" << endl;
	cin >> dname;
	for (int j = 0; j < *p; j++)
	{
		if (arry[j].name == dname)
		{
			cout << "��ϵ��������" << arry[j].name << ",��ϵ�˵绰��" << arry[j].tel << ",��ϵ�˵�ַ��" << arry[j].address << endl;
			break;//���ҵ���Ӧ��ϵ�˺󣬾;ͽ�������
		}
		else
		{
			cout << "�Բ��𣬲��޴���" << endl;
		}
	}
}
//5.�޸���ϵ��
void case5(linkman* arry, int* p)
{
	string dname;
	cout << "��������ϵ��������" << endl;
	cin >> dname;
	for (int j = 0; j < *p; j++)
	{
		while (arry[j].name == dname)
		{
			cout << "������������ϵ��������" << endl;
			cin >> arry[j].name;
			cout << "������������ϵ�˵绰��" << endl;
			cin >> arry[j].tel;
			cout << "������������ϵ��סַ��" << endl;
			cin >> arry[j].address;
			break;
		}
	}
}
int main()
{
	linkman arry[1000];
	//iΪ��ϵ�˸���
	int i = 0;
	int* p1 = &i;
	//����һ��ѡ�����
	int select = 0;
	while(true)
	{
		showMenu();//��ʾѡ�����
		cout << "����������ѡ��" << endl;
		cin >> select;//��������ѡ��
		switch (select)
		{
		case 1:
			case1(arry, p1);
			break;
		case 2:
			case2(arry, p1);
			break;
		case 3:
			case3(arry, p1);
			break;
		case 4:
			case4(arry, p1);
			break;
		case 5:
			case5(arry, p1);
			break;
		case 6:
			memset(arry, NULL, sizeof(arry));
			break;
		case 0:
			cout << "��л����ʹ�ã���" << endl;
			break;
		}
	}
	system("pause");
	return 0;
}