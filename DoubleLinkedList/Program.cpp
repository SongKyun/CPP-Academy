#include "Program.h"

//���� �߻����� �� ����� �Լ�
void OnListError()
{
	std::cout << "������ �߻��߽��ϴ�.\n";
}

Program::Program()
{
	//����Ʈ ����
	//�Լ� ������ ����
	list = new LinkedList<std::string>(OnListError);

	////���� ����
	//list = new LinkedList<std::string>
	//	( [] () {std::cout << "����Ʈ���� ������ �߻��߽��ϴ�.\n";} );
}

Program::~Program()
{
	delete list;
}

// �Է��� �ް�, ����Ʈ�� ������ �߰��ϴ� ����
 void Program::InsertLoop()
{
	 // �Է��� �ޱ� ���� ����
	 std::string name;

	 //���� ó�� ���� ���� ����
	 while (true)
	 {
		 std::cout << "�߰��� ����ó�� �̸��� �Է��ϼ���(����� q)\n";
		 //�Է� ���� ������(���ڿ�)�� name ������ ���� / ���� ����
		 std::cin >> name;

		 // �Է� ���� ���ڰ� q �Ǵ� Q �� �� ���� ����
		 if (name == "Q" || name == "q")
		 {
			 break;
		 }

		 //�� �������� ������ �߰�
		 list->PushLast(name);

		 // ���
		 list->Print();
	 }
}

// �Է��� �ް�, ����Ʈ���� �����͸� �����ϴ� ����
void Program::DeleteLoop()
{
	// �Է��� �ޱ� ���� ����
	std::string name;

	//���� ó�� ���� ���� ����
	while (true)
	{
		std::cout << "������ ����ó�� �̸��� �Է��ϼ���(����� q)\n";
		//�Է� ���� ������(���ڿ�)�� name ������ ���� / ���� ����
		std::cin >> name;

		// �Է� ���� ���ڰ� q �Ǵ� Q �� �� ���� ����
		if (name == "Q" || name == "q")
		{
			break;
		}

		//�� �������� ������ ����
		list->Delete(name);

		// ���
		list->Print();
	}
}
