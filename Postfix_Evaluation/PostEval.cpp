//---------------------------------------------------------------
//          Name		Candelario D. Eguia
//          Course		CMPS-455
//          Project		No.1
//          Due date	Feb. 19, 2015
//          Professor	Ray Ahmadnia
//
// This program displays:
//       Evaluate post algorithems
//------------------------------------------------------------------
#include <iostream>
#include <string>

#define max 20

using namespace std;

struct LN {
	char a;
	int x;
};

class LNstack {
private:
	LN set[max];
	int counter;
public:
	LNstack();
	~LNstack();
	void PushStack(char c, int x);
	char PeekStack(int x);
	int GetInt(int x);
	int StackItems();
};
class intSTACK
{
public:
	intSTACK();
	~intSTACK();
	void PushStack(int x);
	int PopStack();

private:
	int a[max];
	int counter;
};
bool isDuplicate(LNstack letter, char postfixLetter);
bool isLetter(char a);
void doArrithmatic(intSTACK &number, char sign);
LNstack::LNstack()
{
	counter = 0;
}
void LNstack::PushStack(char c, int n)
{
	set[counter].a = c;
	set[counter++].x = n;
}
char LNstack::PeekStack(int n)
{
	return set[n].a;
}
int LNstack::GetInt(int n)
{
	return set[n].x;
}
int LNstack::StackItems() 
{
	return counter - 1;
}
LNstack::~LNstack()
{
	counter = 0;
}
intSTACK::intSTACK()
{
	counter = 0;
}
void intSTACK::PushStack(int x)
{
	a[counter++] = x;
}
int intSTACK::PopStack()
{
	return a[--counter];
}
intSTACK::~intSTACK()
{
}
bool isDuplicate(LNstack letter, char postfixLetter) {
	for (int b = 0; b <= letter.StackItems(); ++b) {
		if (letter.PeekStack(b) == postfixLetter) return true;
	}
	return false;
}
bool isLetter(char a) {
	if ((a >= char('a') && a <= char('z')) || (a >= char('A') && a <= char('Z'))) return true;
	return false;
}
void doArrithmatic(intSTACK &number, char sign) {
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
	case '$':
		cout << "\t\t\tFinal value = " << number.PopStack() << endl;
		break;
	default:
		cout << "ERROR\n";
		break;
	}
}
int main() {
	char cont;
	
	do
	{
		string postfix;
		intSTACK numbers;
		LNstack lettersNumbers;

		cout << "\tEnter a postfix expression with a $ at the end: "; cin >> postfix;

		int i = 0;

		while (i < postfix.length())
		{
			if (i == postfix.length() - 1 && postfix[i] != '$') {
				postfix = postfix + '$';
			}
			int value;
			
			if (isLetter(postfix[i])) {
				if (!isDuplicate(lettersNumbers, postfix[i])) {
					cout << "\t\tEnter the value of " << postfix[i] << ": "; cin >> value; numbers.PushStack(value);
					lettersNumbers.PushStack(postfix[i], value);
				}
				else {
					for (int p = 0; p <= lettersNumbers.StackItems(); p++) {
						if (lettersNumbers.PeekStack(p) == postfix[i]) {
							numbers.PushStack(lettersNumbers.GetInt(p));
							break;
						}
					}
				}
			}
			else {
				if (postfix[i] == '/' || postfix[i] == '*' || postfix[i] == '-' || postfix[i] == '+' || postfix[i] == '$') {
					doArrithmatic(numbers, postfix[i]);
				}
				else {
					cout << "Opperation not recognized!\n";
					break;
				}
			}
			i++;
		}		

		cout << "Continue (y/n)? "; cin >> cont; cont = toupper(cont);

	} while (cont != 'N');

	system("pause");
	return 0;
}
/*-- OUTPUT ------------------------------------------------------------
----------------------------------------------------------------------*/

