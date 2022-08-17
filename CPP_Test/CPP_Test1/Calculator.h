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
		
		std::cout << "µ¡¼À: " << addcount << "»¬¼À: " << subtractcount << "°ö¼À: " << muliplycount << "³ª´°¼À: " << dividecount << std::endl;
	}

	
};

//¿¬»ê Çß´Âµ¥ ¸®ÅÏ°ªÀÌ ¾ø¾î¼­
// È½¼ö °á°ú°ª º¯¼ö 1°³ ´õ Ãß°¡
// º¯¼ö 4°³ ¼±¾ð - ¼ö½Ä Ä«¿îÆÃ