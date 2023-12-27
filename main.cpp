#include <bits/stdc++.h>
#pragma warning(disable : 4996)
using namespace std;

typedef struct restaurant_info inf;
typedef struct restaurant_info* PtrToNode;
struct restaurant_info
{
	//类别
	char dish_kinds[100];
	//菜品名
	char dish_name[10];
	//菜品属性
	char dish_attribute[1000];
	//编号
	int dish_num;
	//价格
	int dish_price;
	//判断有几道菜
	int size;
	PtrToNode next;
};

// 读取数据到链表
static PtrToNode 
ReadInfo_FromText(void)
{
	ifstream ifs;
	ifs.open("./text.txt", ios::in);
	if (!ifs.is_open())
	{
		return nullptr;
	}
	else
	{
		PtrToNode head = nullptr;
		PtrToNode rear = nullptr;
		ifstream read("text.txt", ios::in);
		if (!read)
		{
			cout << "未加载" << endl;
			return nullptr;
		}
		while (true)
		{
			PtrToNode newNode = new struct restaurant_info;
			read >> newNode->dish_kinds >> newNode->dish_name >> newNode->dish_attribute >> newNode->dish_num >> newNode->dish_price;
			if (read.eof()) // 到达文件末尾，结束循环
			{
				delete newNode; // 释放没有使用的节点内存
				break;
			}
			newNode->next = nullptr;
			if (head == nullptr) // 如果是第一个节点
			{
				head = newNode;
				rear = newNode;
			}
			else
			{
				rear->next = newNode;
				rear = newNode;
			}
		}
		read.close();
		return head;
	}
}

//输出文件的全部信息
static void
OutPut_All_Info(PtrToNode head)
{
	if (head != nullptr)
	{
		ifstream ifs;
		ifs.open("text.txt", ios::in);
		if (!ifs.is_open())
		{
			cout << "暂未添加菜" << endl;
		}
		else
		{
			string buf;
			while (getline(ifs, buf))
			{
				cout << buf << endl;
			}
		}
	}
	else
	{
		printf("暂未添加菜\n");
	}
}

//重写链表数据到文本文件
static void
Save_All_Dish_Info(PtrToNode head)
{
	if (head != nullptr)
	{
		fstream ofs;
		if (head->next != nullptr)
		{
			ofs.open("./text.txt", ios::out);
			PtrToNode current = head;
			while (current!=nullptr && current->next != nullptr)
			{
				ofs << current->dish_kinds << "\n";
				ofs << current->dish_name << "\n";
				ofs << current->dish_attribute << "\n";
				ofs << current->dish_num << "\n";
				ofs << current->dish_price << "\n";
				current = current->next;
			}
			ofs << current->dish_kinds << "\n";
			ofs << current->dish_name << "\n";
			ofs << current->dish_attribute << "\n";
			ofs << current->dish_num << "\n";
			ofs << current->dish_price << "\n";
			ofs.close();
		}
		else
		{
			ofs.open("./text.txt", ios::out);
			ofs << head->dish_kinds << "\n";
			ofs << head->dish_name << "\n";
			ofs << head->dish_attribute << "\n";
			ofs << head->dish_num << "\n";
			ofs << head->dish_price << "\n";
			ofs.close();
		}
	}
	else
	{
		cout<<"暂未添加菜"<<endl;
	}
}

//补充数据到链表
static void
Save_Dish_Info(PtrToNode head)
{
	if (head != nullptr)
	{
		fstream ofs;
		if (head->next != nullptr)
		{
			ofs.open("./text.txt", ios::app);
			PtrToNode current = head;
			while (current->next != nullptr)
			{
				ofs << current->dish_kinds << "\n";
				ofs << current->dish_name << "\n";
				ofs << current->dish_attribute << "\n";
				ofs << current->dish_num << "\n";
				ofs << current->dish_price << "\n";
				current = current->next;
			}
			ofs << current->dish_kinds << "\n";
			ofs << current->dish_name << "\n";
			ofs << current->dish_attribute << "\n";
			ofs << current->dish_num << "\n";
			ofs << current->dish_price << "\n";
			ofs.close();
		}
		else
		{
			ofs.open("./text.txt", ios::app);
			ofs << head->dish_kinds << "\n";
			ofs << head->dish_name << "\n";
			ofs << head->dish_attribute << "\n";
			ofs << head->dish_num << "\n";
			ofs << head->dish_price << "\n";
			ofs.close();
		}
	}
	else
	{
		printf("暂未添加菜\n");
	}
}

static void 
Add_Dish_Kinds(PtrToNode nr)
{
	do
	{
		char str[100];
		int times = 0;
		cout << "你是什么菜" << endl;
		scanf_s("%s", str, 99);
		if (strlen(str) != 0)
		{
			if (strcmp(str, "soup") == 0 || strcmp(str, "cuisine") == 0 || strcmp(str, "meat") == 0 || strcmp(str, "汤") == 0 || strcmp(str, "肉") == 0 || strcmp(str, "菜") == 0 || strcmp(str, "蔬菜") == 0)
			{
				strcpy_s(nr->dish_kinds, strlen(str) + 1, str);
				break;
			}
			else
			{
				times++;
				if (times >= 3)
				{
					cout<<"错误次数过多"<<endl;
					exit(102);
				}
				cout<<"不要乱输入。请从汤（soup）,蔬菜（cuisine）,肉（meat）中选择一个"<<endl;
				continue;
			}
		}
		else
		{
			times++;
			if (times >= 3)
			{
				exit(102);
			}
		}
	} while (1);

}

static void 
Add_Dish_Name(PtrToNode nr)
{
	do
	{
		char str[100];
		cout<<"请输入菜的名称"<<endl;
		scanf_s("%s", str, 98);
		if (str != "\0")
		{
			strcpy_s(nr->dish_name, strlen(str) + 1, str);
			break;
		}
		else
		{
			continue;
		}
	} while (1);
	
}

static void
Add_Dish_Num(PtrToNode nr)
{
	do
	{
		int num;
		cout<<"请输入菜品编号"<<endl;
		cin>>num;
		if (num <= 0)
		{
			int times = 0;
			do
			{
				cout<<"请重新输入"<<endl;
				cin>>num;
				times++;
				if (times >= 3)
				{
					cout<<"错误次数过多"<<endl;
					exit(102);
				}
			} while (num <= 0);
		}
		else
		{
			nr->dish_num = num;
		}
	} while (nr->dish_num == 0);
}

static void 
Add_Dish_Attribute(PtrToNode nr)
{
	do
	{
		char str[1000];
		int times = 0;
		cout << "请输入菜的属性" << endl;
		scanf_s("%s", str, 999);
		if (strlen(str) != 0)
		{
			strcpy_s(nr->dish_attribute, str);
			break;
		}
		else
		{
			times++;
			if (times >= 3)
			{
				cout << "错误次数过多" << endl;
				exit(102);
			}
		}
	} while (1);
}

static void 
Add_Dish_Price(PtrToNode nr)
{
	do
	{
		cout<<"请输入价格"<<endl;
		int num = 0;
		int times = 0;
		cin>>num;
		if (num >= 0)
		{
			nr->dish_price = num;
			break;
		}
		else
		{
			times++;
			if (times >= 3)
			{
				//输入错误
				exit(102);
			}
		}
	} while (1);

}

static PtrToNode
Add_Dish_Info(PtrToNode head)
{
	PtrToNode p = head;
	while (p != nullptr && p->next != nullptr)
	{
		p = p->next;
	}
	if (p!=nullptr && p->size >= 20)
	{
		cout << "超出数量" << endl;
		return nullptr;
	}
	else
	{
		PtrToNode nr = (PtrToNode)malloc(sizeof(inf));
		if (nr != nullptr)
		{
			Add_Dish_Kinds(nr);
			Add_Dish_Name(nr);
			Add_Dish_Attribute(nr);
			Add_Dish_Num(nr);
			Add_Dish_Price(nr);
			nr->next = nullptr;
			if (head != nullptr)
			{
				nr->size = (p->size + 1);
				p->next = nr;
				if (nr->next == nullptr)
				{
					return nr;
				}
				else
				{
					//未知错误
					exit(101);
				}
			}
			else
			{
				return nr;
			}
		}
		else
		{
			//内存不足
			exit(110);
		}
	}
}

static void
Polish_Dish(PtrToNode head, int num)
{
	if (head != nullptr)
	{
		PtrToNode nr = head;
		bool is = false;
		while (nr!=nullptr && nr->next != nullptr)
		{
			if (nr->dish_num == num)
			{
				is = true;
				break;
			}
			nr = nr->next;
		}
		if (is)
		{
			Add_Dish_Kinds(nr);
			Add_Dish_Name(nr);
			Add_Dish_Attribute(nr);
			Add_Dish_Num(nr);
			Add_Dish_Price(nr);
			cout << "修改完成" << endl;
		}
		else
		{
			if (nr->dish_num == num)
			{
				Add_Dish_Kinds(nr);
				Add_Dish_Name(nr);
				Add_Dish_Attribute(nr);
				Add_Dish_Num(nr);
				Add_Dish_Price(nr);
				cout << "修改完成" << endl;
			}
			else
			{
				exit(101);
			}
		}
	}
}

static void
Delete_Dish(PtrToNode head, int num)
{
	if (head != nullptr)
	{
		bool is = false;
		PtrToNode nr = head;
		while (nr!=nullptr && nr->next != nullptr)
		{
			if (nr->dish_num == num)
			{
				is = true;
				break;
			}
			nr = nr->next;
		}
		if (is) 
		{
			//若删除中间节点
			if (nr->next != nullptr)
			{
				PtrToNode temp = nr;
				nr = nr->next;
				free(temp);
				temp = nullptr;
				cout<<"删除成功"<<endl;
			}
			//若删除结尾节点
			else
			{
				PtrToNode temp = nr;
				nr = nullptr;
				free(temp);
				temp = nullptr;
				cout << "删除成功" << endl;
			}
		}
		else
		{
			//删除头节点
			if (nr->dish_num == num)
			{
				//只有一个头节点
				if (nr->next == nullptr)
				{
					free(nr);
					nr = nullptr;
					cout << "删除成功" << endl;
				}
				else
				{
					PtrToNode temp = head;
					head = head->next;
					free(temp);
					temp = nullptr;
					cout << "删除成功" << endl;
				}
			}
			else
			{
				exit(102);
			}
		}
	}
	else
	{
		exit(102);
	}
}

static PtrToNode
Find_Dish(PtrToNode head, int num)
{
	if (head != nullptr)
	{
		if (num > 0)
		{
			PtrToNode current = head;
			do
			{
				if (current->dish_num == num)
				{
					return current;
				}
				current = current->next;
				if (current == nullptr)
				{
					break;
				}
			} while (current->next != nullptr);
			cout<<"请检查输入是否合法"<<endl;
			return nullptr;
		}
		else
		{
			printf("请检查输入是否合法\n");
			return nullptr;
		}
	}
	else
	{
		return nullptr;
	}
}

static void
Print(PtrToNode head, int num)
{
	if (head != nullptr)
	{
		PtrToNode current = Find_Dish(head, num);
		if (current != nullptr)
		{
			cout << "你要找的菜" << endl;
			cout << current->dish_kinds << endl;
			cout << current->dish_name << endl;
			cout << current->dish_attribute << endl;
			cout << current->dish_num << endl;
			cout << current->dish_price << endl;
		}
		else
		{
			exit(102);
		}
	}
	else
	{
		cout<<"暂未添加菜"<<endl;
	}
}

//根据属性找菜
static void
Search_Kinds(PtrToNode head, char* dish_kinds)
{
	if (head != nullptr)
	{
		if (strcmp(dish_kinds, "\0") == 0)
		{
			cout << "请检查输入" << endl;
			return;
		}
		else
		{
			PtrToNode nr = head;
			while (nr != nullptr)
			{
				if (strcmp(nr->dish_kinds, dish_kinds) == 0)
				{
					Print(head, nr->dish_num);
				}
				nr = nr->next;
			}
		}
	}
	else
	{
		exit(102);
	}
}


static void
Swap_Dish(PtrToNode nr)
{
	if (nr != nullptr)
	{
		char temp1[100];
		char temp2[10];
		char temp3[1000];

		int temp4 = nr->dish_num;
		int temp5 = nr->dish_price;
		strcpy(temp1,nr->dish_kinds);
		strcpy(temp2, nr->dish_name);
		strcpy(temp3, nr->dish_attribute);

		strcpy(nr->dish_kinds, nr->next->dish_kinds);
		strcpy(nr->dish_name, nr->next->dish_name);
		strcpy(nr->dish_attribute, nr->next->dish_attribute);
		nr->dish_num = nr->next->dish_num;
		nr->dish_price = nr->next->dish_price;

		strcpy(nr->next->dish_kinds,temp1);
		strcpy(nr->next->dish_name,temp2);
		strcpy(nr->next->dish_attribute,temp3);
		nr->next->dish_num=temp4;
		nr->next->dish_price=temp5;
	}
	else
	{
		exit(102);
	}
}

static void
Sort_Dish(PtrToNode head)
{
	if (head != nullptr)
	{
		PtrToNode nr = head;
		while (nr!=nullptr && nr->next!=nullptr)
		{
			nr = head;
			while (nr->next != nullptr)
			{
				if (nr->dish_price > nr->next->dish_price)
				{
					Swap_Dish(nr);
				}
				nr = nr->next;
			}	
		}
	}
}

static void 
Start(void)
{
	int opearte_num;
	cout << "你好" << endl;
	PtrToNode head = nullptr;
	head = ReadInfo_FromText();
	if (head == nullptr)
	{
		cout<<"请先初始化第一个数据"<<endl;
		head=Add_Dish_Info(head);
		if (head != nullptr)
		{
			Save_Dish_Info(head);
		}
		else
		{
			cout << "内存不足" << endl;
		}
	}
	PtrToNode current = nullptr;
	while (1)
	{ 
		cout << "输入1加菜，输入2改菜，输入3删除菜，输入4找菜，输入5显示菜单,输入6按类别查找菜单" << endl;
		cout << "完事输入0" << endl;
		cin >> opearte_num;
		//加菜
		if (opearte_num == 1)
		{
			current=Add_Dish_Info(head);
			if (current != nullptr)
			{
				cout << "添加成功" << endl;
				Sort_Dish(head);
			}
			else
			{
				exit(101);
			}
			Save_All_Dish_Info(head);
			continue;
		}
		//改菜
		else if (opearte_num == 2)
		{
			int n;
			cout << "请输入要修改的编号" << endl;
			cin >> n;
			Polish_Dish(head, n);
			Sort_Dish(head);
			Save_All_Dish_Info(head);
			continue;
		}
		//删除菜
		else if (opearte_num == 3)
		{
			int n;
			cout << "请输入你想要删除的菜的编号" << endl;
			cin >> n;
			Delete_Dish(head, n);
			Save_All_Dish_Info(head);
			continue;
		}
		else if (opearte_num == 4)
		{
			int n;
			cout << "请输入你要找的菜的编号" << endl;
			cin >> n;
			Print(head, n);
			continue;
		}
		else if (opearte_num == 5)
		{
			Sort_Dish(head);
			Save_All_Dish_Info(head);
			OutPut_All_Info(head);
			continue;
		}
		else if (opearte_num == 6)
		{
			char str[20];
			cout << "请输入需要查找的类别" << endl;
			cin >> str;
			Search_Kinds(head, str);
			continue;
		}
		else if (opearte_num == 0)
		{
			Save_All_Dish_Info(head);
			break;
		}
		else
		{
			cout<<"不要乱来，这个程序的鲁棒性不是很好"<<endl;
			continue;
		}
	}
}

int main()
{
	Start();
	return 0;
}

/*
* designd by mkitsdts
* 已实现功能：
* 1、增删查改基本功能
* 2、按照价格排序
* 3、按照菜品属性进行查找
* 4、为输入进行判错
*/