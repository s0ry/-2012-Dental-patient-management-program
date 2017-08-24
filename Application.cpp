#include "Application.h"

void Application::Try()		//���� �޴� ���
{
	StructTree tree;	//������ ���� Ʈ��
	Patient data;		//ȯ�� ������
	Patient temp;		//��¿� �ӽ� ȯ�� ������
	QueType que;		//����� ȯ�ڵ����� ���� ť
	ofstream file;		//���� ��ü ����

	int count = 0;		//��ȣ(No.)
	int year, month, day;		//��¥
	bool check = false;			//�޴� ���� �÷���			

	Input_day(year, month, day);	//��¥ �Է� �ޱ�
	file.open("Patient_data.txt");

	while (!check)		//�����Ҷ�����
	{
		cout << "�� " << count << "���� ȯ�ڸ� ġ���߽��ϴ�." << endl;
		switch (Main_menu())
		{
		case 1:		//ȯ�ڹޱ�
			data.Input_data(count, year, month, day);	//�̸��Է�
			data.Select_treat();							//ġ����
			tree.InsertItem(data, file);					//Ʈ���� ������ insert
			Sleep(500);
			system("cls");
			break;
		case 2:		//������ �˻�
			que.MakeEmpty();			//��ť�� �ʱ�ȭ
			switch (Search_menu())
			{
			case 1:		//�̸����� �˻�
				Search_for_name(tree, que);
				break;
			case 2:		//�������� �˻�
				Search_for_number(tree, que);
				break;
			case 3:		//ġ�������� �˻�
				Search_for_treat(tree, que);
				break;
			}
			Sleep(500);
			system("cls");
			if (!que.IsEmpty())		//�˻� ����� ������ ��
			{
				cout << "*******�˻����*******" << endl;
				while (!que.IsEmpty())		//�˻� ��� ���
				{
					que.Dequeue(temp);
					temp.Print_data();
				}
			}
			else					//�˻� ����� �������� ���� ��
				cout << "�������� �ʽ��ϴ�." << endl;
			cout << endl;
			system("pause");
			system("cls");
			break;
		case 3:		//��ü ȯ�� ������ ���
			que.MakeEmpty();		//��ť�� �ʱ�ȭ
			tree.PrintAll(que);	//Ʈ���� ��� ��带 ť�� ����
			if (que.IsEmpty())
				cout << "�����Ͱ� �����ϴ�." << endl;
			else
			{
				system("cls");
				cout << "*******��üȯ��*******" << endl;
				while (!que.IsEmpty())
				{
					que.Dequeue(temp);
					temp.Print_data();
				}
			}
			system("pause");
			system("cls");
			break;
		case 4:		//����
			cout << "������ ���Ḧ �����մϴ�." << endl << endl;
			check = true;
			file.close();
			break;
		}
	}
	return;
}

void Application::Input_day(int& year, int& month, int &day)	//��¥ �Է¹ޱ�
{
	cout << "������ ��¥�� �Է��Ͻʽÿ�.(****��, **��, **��)" << endl;
	cin >> year >> month >> day;
	return;
}

int Application::Main_menu()		//���� �޴�
{
	int menu;
	bool m_check = false;
	while (!m_check)
	{
		cout << "�޴��� �����Ͻÿ�." << endl;
		cout << "1. ȯ�� �ޱ�" << endl;
		cout << "2. ������ �˻�" << endl;
		cout << "3. ��ü ȯ�� ������ ���" << endl;
		cout << "4. ����" << endl;
		cin >> menu;
		if (menu > 0 && menu < 5)
			m_check = true;
		else
		{
			cout << "�߸��Է��Ͽ����ϴ�." << endl;
			Sleep(500);
			system("cls");
		}
	}
	return menu;
}

int Application::Search_menu()		//���� ���� �޴� ���
{
	int menu;
	bool check = false;
	while (!check)
	{
		cout << "������ �˻��� ����� ������ �����Ͻÿ�." << endl;
		cout << "1. ȯ�� �̸�" << endl;
		cout << "2. ����" << endl;
		cout << "3. �ü��� ġ��" << endl;
		cin >> menu;
		if (menu > 0 && menu < 4)
			check = true;
		else
		{
			cout << "�߸��Է��Ͽ����ϴ�." << endl;
			Sleep(500);
			system("cls");
		}
	}
	return menu;
}

void Application::Search_for_name(StructTree tree, QueType& que)		//�̸����� �˻�
{
	string search_str;
	cout << "�˻��ϰ����ϴ� �̸��� �Է��Ͻÿ�." << endl;
	cin >> search_str;
	tree.Search_name(search_str, que);	//�̸����� Ʈ�� �˻�
	return;
}

void Application::Search_for_number(StructTree tree, QueType& que)		//��ȣ�� �˻�
{
	int search_number;
	cout << "�˻��ϰ����ϴ� ������ �Է��Ͻÿ�." << endl;
	cin >> search_number;
	tree.Search_number(search_number, que);		//��ȣ�� Ʈ�� �˻�
	return;
}

void Application::Search_for_treat(StructTree tree, QueType& que)		//ġ������� �˻�
{
	int search_str;
	cout << "�˻��ϰ����ϴ� ġ�Ḧ �Է��Ͻÿ�." << endl;
	cout << "1. ġ������" << endl;
	cout << "2. �Ű�ġ��" << endl;
	cout << "3. ��ġ, ��öġ��" << endl;
	cout << "4. ����ġ��" << endl;

	cin >> search_str;
	tree.Search_treat(search_str, que);		//ġ������� Ʈ�� �˻�
	return;
}