#pragma once

class Calculator
{
public:
	double x;
	double y;

	double Add(double x, double y)
	{
		addcount += 1;
		return x + y;
	}

	double Divide(double x, double y)
	{
		dividecount += 1;
		return x / y;
	}

	double Subtract(double x, double y)
	{
		subtractcount += 1;
		return x - y;
	}

	double Muliply(double x, double y)
	{
		muliplycount += 1;
		return x * y;
	}

	int addcount=0;
	int dividecount=0;
	int subtractcount=0;
	int muliplycount=0;


	void  ShowOperationCount()
	{
		
		std::cout << "����: " << addcount << "����: " << subtractcount << "����: " << muliplycount << "������: " << dividecount << std::endl;
	}

	
};

//���� �ߴµ� ���ϰ��� ���
// Ƚ�� ����� ���� 1�� �� �߰�
// ���� 4�� ���� - ���� ī����