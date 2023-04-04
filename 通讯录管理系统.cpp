#include<iostream>
using namespace std;
//创建联系人结构体，确定联系人信息
struct linkman
{
	string name;
	int tel;
	string address;
};
//定义一个函数，显示选择界面
void showMenu()
{
	cout << "**************************" << endl;
	cout << "*****  1.增加联系人  *****" << endl;
	cout << "*****  2.显示联系人  *****" << endl;
	cout << "*****  3.删除联系人  *****" << endl;
	cout << "*****  4.查找联系人  *****" << endl;
	cout << "*****  5.修改联系人  *****" << endl;
	cout << "*****  6.清空联系人  *****" << endl;
	cout << "*****  0.退出通讯录  *****" << endl;
	cout << "**************************" << endl;
}
//1.增加联系人
//参数为联系人数组的地址* arry和联系人个数的地址* p
void case1(linkman* arry, int* p)
{
		cout << "请输入联系人姓名：" << endl;
		cin >> arry[*p].name;
		cout << "请输入联系人电话：" << endl;
		cin >> arry[*p].tel;
		cin.get();//连续多次执行输入的时候，可能会遇到后面的输入无法执行的情况，用这种方法可以避免
		cout << "请输入联系人住址：" << endl;
		cin >> arry[*p].address;
		(*p)++;//再次执行的时候，下一个数组元素接收信息
}
//2.显示联系人
void case2(linkman* arry, int* p)
{
	//*p表示通讯录中的人数
	//将通讯录中的联系人信息，遍历出来
	for (int j = 0; j < *p; j++)
	{
		cout << "联系人姓名：" << arry[j].name << ",联系人电话：" << arry[j].tel << ",联系人地址：" << arry[j].address << endl;
	}
}
//3.删除联系人
void case3(linkman* arry, int* p)
{
	string dname;
	cout << "请输入联系人姓名：" << endl;
	cin >> dname;
	//通过姓名查找对应的联系人
	//对通讯录中的联系人进行遍历，如果有联系人的姓名跟我们要找的一样，那么将这个联系人的信息删除，后面的联系人前移，将这个空补上
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
			cout << "对不起，查无此人" << endl;
		}
	}
	(*p)--;//删除一个联系人后，联系人数量将减少一个
}
//4.查找联系人
void case4(linkman* arry, int* p)
{
	string dname;
	cout << "请输入联系人姓名：" << endl;
	cin >> dname;
	for (int j = 0; j < *p; j++)
	{
		if (arry[j].name == dname)
		{
			cout << "联系人姓名：" << arry[j].name << ",联系人电话：" << arry[j].tel << ",联系人地址：" << arry[j].address << endl;
			break;//查找到对应联系人后，就就结束遍历
		}
		else
		{
			cout << "对不起，查无此人" << endl;
		}
	}
}
//5.修改联系人
void case5(linkman* arry, int* p)
{
	string dname;
	cout << "请输入联系人姓名：" << endl;
	cin >> dname;
	for (int j = 0; j < *p; j++)
	{
		while (arry[j].name == dname)
		{
			cout << "请重新输入联系人姓名：" << endl;
			cin >> arry[j].name;
			cout << "请重新输入联系人电话：" << endl;
			cin >> arry[j].tel;
			cout << "请重新输入联系人住址：" << endl;
			cin >> arry[j].address;
			break;
		}
	}
}
int main()
{
	linkman arry[1000];
	//i为联系人个数
	int i = 0;
	int* p1 = &i;
	//定义一个选择变量
	int select = 0;
	while(true)
	{
		showMenu();//显示选择界面
		cout << "请输入您的选择：" << endl;
		cin >> select;//输入您的选择
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
			cout << "感谢您的使用！！" << endl;
			break;
		}
	}
	system("pause");
	return 0;
}