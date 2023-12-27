#include <bits/stdc++.h>
#pragma warning(disable : 4996)
using namespace std;

typedef struct restaurant_info inf;
typedef struct restaurant_info* PtrToNode;
struct restaurant_info
{
	//���
	char dish_kinds[100];
	//��Ʒ��
	char dish_name[10];
	//��Ʒ����
	char dish_attribute[1000];
	//���
	int dish_num;
	//�۸�
	int dish_price;
	//�ж��м�����
	int size;
	PtrToNode next;
};

// ��ȡ���ݵ�����
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
			cout << "δ����" << endl;
			return nullptr;
		}
		while (true)
		{
			PtrToNode newNode = new struct restaurant_info;
			read >> newNode->dish_kinds >> newNode->dish_name >> newNode->dish_attribute >> newNode->dish_num >> newNode->dish_price;
			if (read.eof()) // �����ļ�ĩβ������ѭ��
			{
				delete newNode; // �ͷ�û��ʹ�õĽڵ��ڴ�
				break;
			}
			newNode->next = nullptr;
			if (head == nullptr) // ����ǵ�һ���ڵ�
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

//����ļ���ȫ����Ϣ
static void
OutPut_All_Info(PtrToNode head)
{
	if (head != nullptr)
	{
		ifstream ifs;
		ifs.open("text.txt", ios::in);
		if (!ifs.is_open())
		{
			cout << "��δ��Ӳ�" << endl;
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
		printf("��δ��Ӳ�\n");
	}
}

//��д�������ݵ��ı��ļ�
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
		cout<<"��δ��Ӳ�"<<endl;
	}
}

//�������ݵ�����
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
		printf("��δ��Ӳ�\n");
	}
}

static void 
Add_Dish_Kinds(PtrToNode nr)
{
	do
	{
		char str[100];
		int times = 0;
		cout << "����ʲô��" << endl;
		scanf_s("%s", str, 99);
		if (strlen(str) != 0)
		{
			if (strcmp(str, "soup") == 0 || strcmp(str, "cuisine") == 0 || strcmp(str, "meat") == 0 || strcmp(str, "��") == 0 || strcmp(str, "��") == 0 || strcmp(str, "��") == 0 || strcmp(str, "�߲�") == 0)
			{
				strcpy_s(nr->dish_kinds, strlen(str) + 1, str);
				break;
			}
			else
			{
				times++;
				if (times >= 3)
				{
					cout<<"�����������"<<endl;
					exit(102);
				}
				cout<<"��Ҫ�����롣�������soup��,�߲ˣ�cuisine��,�⣨meat����ѡ��һ��"<<endl;
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
		cout<<"������˵�����"<<endl;
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
		cout<<"�������Ʒ���"<<endl;
		cin>>num;
		if (num <= 0)
		{
			int times = 0;
			do
			{
				cout<<"����������"<<endl;
				cin>>num;
				times++;
				if (times >= 3)
				{
					cout<<"�����������"<<endl;
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
		cout << "������˵�����" << endl;
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
				cout << "�����������" << endl;
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
		cout<<"������۸�"<<endl;
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
				//�������
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
		cout << "��������" << endl;
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
					//δ֪����
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
			//�ڴ治��
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
			cout << "�޸����" << endl;
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
				cout << "�޸����" << endl;
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
			//��ɾ���м�ڵ�
			if (nr->next != nullptr)
			{
				PtrToNode temp = nr;
				nr = nr->next;
				free(temp);
				temp = nullptr;
				cout<<"ɾ���ɹ�"<<endl;
			}
			//��ɾ����β�ڵ�
			else
			{
				PtrToNode temp = nr;
				nr = nullptr;
				free(temp);
				temp = nullptr;
				cout << "ɾ���ɹ�" << endl;
			}
		}
		else
		{
			//ɾ��ͷ�ڵ�
			if (nr->dish_num == num)
			{
				//ֻ��һ��ͷ�ڵ�
				if (nr->next == nullptr)
				{
					free(nr);
					nr = nullptr;
					cout << "ɾ���ɹ�" << endl;
				}
				else
				{
					PtrToNode temp = head;
					head = head->next;
					free(temp);
					temp = nullptr;
					cout << "ɾ���ɹ�" << endl;
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
			cout<<"���������Ƿ�Ϸ�"<<endl;
			return nullptr;
		}
		else
		{
			printf("���������Ƿ�Ϸ�\n");
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
			cout << "��Ҫ�ҵĲ�" << endl;
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
		cout<<"��δ��Ӳ�"<<endl;
	}
}

//���������Ҳ�
static void
Search_Kinds(PtrToNode head, char* dish_kinds)
{
	if (head != nullptr)
	{
		if (strcmp(dish_kinds, "\0") == 0)
		{
			cout << "��������" << endl;
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
	cout << "���" << endl;
	PtrToNode head = nullptr;
	head = ReadInfo_FromText();
	if (head == nullptr)
	{
		cout<<"���ȳ�ʼ����һ������"<<endl;
		head=Add_Dish_Info(head);
		if (head != nullptr)
		{
			Save_Dish_Info(head);
		}
		else
		{
			cout << "�ڴ治��" << endl;
		}
	}
	PtrToNode current = nullptr;
	while (1)
	{ 
		cout << "����1�Ӳˣ�����2�Ĳˣ�����3ɾ���ˣ�����4�Ҳˣ�����5��ʾ�˵�,����6�������Ҳ˵�" << endl;
		cout << "��������0" << endl;
		cin >> opearte_num;
		//�Ӳ�
		if (opearte_num == 1)
		{
			current=Add_Dish_Info(head);
			if (current != nullptr)
			{
				cout << "��ӳɹ�" << endl;
				Sort_Dish(head);
			}
			else
			{
				exit(101);
			}
			Save_All_Dish_Info(head);
			continue;
		}
		//�Ĳ�
		else if (opearte_num == 2)
		{
			int n;
			cout << "������Ҫ�޸ĵı��" << endl;
			cin >> n;
			Polish_Dish(head, n);
			Sort_Dish(head);
			Save_All_Dish_Info(head);
			continue;
		}
		//ɾ����
		else if (opearte_num == 3)
		{
			int n;
			cout << "����������Ҫɾ���Ĳ˵ı��" << endl;
			cin >> n;
			Delete_Dish(head, n);
			Save_All_Dish_Info(head);
			continue;
		}
		else if (opearte_num == 4)
		{
			int n;
			cout << "��������Ҫ�ҵĲ˵ı��" << endl;
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
			cout << "��������Ҫ���ҵ����" << endl;
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
			cout<<"��Ҫ��������������³���Բ��Ǻܺ�"<<endl;
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
* ��ʵ�ֹ��ܣ�
* 1����ɾ��Ļ�������
* 2�����ռ۸�����
* 3�����ղ�Ʒ���Խ��в���
* 4��Ϊ��������д�
*/