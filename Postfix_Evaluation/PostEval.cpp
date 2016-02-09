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
#include <string>

#define max 10

using namespace std;

struct LN
{
	char a;
	int x;
	~LN() {};
};


class STACK
{
public:
	STACK();
	~STACK();
	void PushStack(int x);
	int PopStack();

private:
	int a[max];
	int counter;
};

bool isDuplicate(LN letter[], char postfixLetter);
bool isLetter(char a);
void doArrithmatic(STACK &number, char sign);

int main() {
	char cont;

	do
	{
		string postfix;
		STACK numbers;

		cout << "\tEnter a postfix expression with a $ at the end: "; cin >> postfix;

		int i = 0;

		while (i < postfix.length() && postfix[i] != '$')
		{
			LN lettersNumbers[max] = {};
			int value;
			
			if (isLetter(postfix[i])) {
				if (!isDuplicate(lettersNumbers, postfix[i])) {
					cout << "\t\tEnter the value of " << postfix[i] << ": "; cin >> value; numbers.PushStack(value);
					lettersNumbers[i].a = postfix[i];
					lettersNumbers[i].x = value;
				}
				else {
					for (int p = 0; p < 10; p++) {
						if (lettersNumbers[p].a == postfix[i]) {
							numbers.PushStack(lettersNumbers[p].x);
							break;
						}
					}
				}
			}
			else {
				doArrithmatic(numbers, postfix[i]);
			}
			i++;
		}
		cout << "final value = " << numbers.PopStack() << endl;

		cout << "Continue (y/n)? "; cin >> cont; cont = toupper(cont);

	} while (cont != 'N');

	system("pause");
	return 0;
}
/*-- OUTPUT ------------------------------------------------------------
----------------------------------------------------------------------*/

STACK::STACK()
{
	counter = 0;
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


bool isDuplicate(LN letter[], char postfixLetter) {
	for (int b = 0; b <= max; ++b) {
		if (letter[b].a == postfixLetter) return true;
	}
	return false;
}


bool isLetter(char a) {
	if ((a >= char('a') && a <= char('z')) || (a >= char('A') && a <= char('Z'))) return true;
	return false;
}

void doArrithmatic(STACK &number, char sign) {
	int a;
	switch (sign)
	{
	case '+':
		a = number.PopStack() + number.PopStack();
		number.PushStack(a);
		break;
	case '-':
		a = number.PopStack() - number.PopStack();
		number.PushStack(a);
		break;
	case '*':
		a = number.PopStack() * number.PopStack();
		number.PushStack(a);
		break;
	case '/':
		a = number.PopStack() / number.PopStack();
		number.PushStack(a);
		break;
	default:

		break;
	}
}