//---------------------------------------------------------------
//          Name		Candelario D. Eguia
//          Course		CMPS-455
//          Project		No.1
//          Due date	Feb. 19, 2015
//          Professor	Ray Ahmadnia
//
// This program displays:
//       Evaluate post algorithem
//------------------------------------------------------------------
#include <iostream>

using namespace std;

class STACK
{
public:
	STACK();
	~STACK();
	bool EmptyStack();
	bool FullStack();
	void PushStack(int x);
	int PopStack();

private:
	int a[20];
	int counter;
};

STACK::STACK()
{
	counter = 0;
}

bool STACK::EmptyStack()
{
	return counter == 0 ? true : false;
}

bool STACK::FullStack()
{
	return counter == 20 ? true : false;
}

void STACK::PushStack(int x)
{
	a[counter] = x;
	counter++;
}

int STACK::PopStack()
{
	--counter;
	return a[counter];
}

STACK::~STACK()
{
}

int main() {
	char cont;
	do
	{

		cout << "Continue (y/n)? "; cin >> cont; cont = toupper(cont);
		cin.ignore();
	} while (cont != 'N');

	system("pause");
	return 0;
}
/*-- OUTPUT ------------------------------------------------------------

----------------------------------------------------------------------*/