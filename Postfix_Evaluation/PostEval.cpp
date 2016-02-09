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

struct LN{
	char c;
	int x;
};

template <class  T >
class  STACK
{
public:
	STACK()
	{
		counter = 0;
	}
	~STACK()
	{
		counter = 0;
	}
	void PushStack(int n)
	{
		a[counter++] = n;
	}
	void PushStack(char z, int n) 
	{
		a[counter].c = z;
		a[counter++].x = n;
	}
	int PopStack()
	{
		return a[--counter];
	}
	char PeekStack(int n)
	{
		return a[n].c;
	}
	int GetInt(int n)
	{
		return a[n].x;
	}
	int StackItems()
	{
		return counter - 1;
	}
private:
	T a[max];
	int counter;
};

bool isDuplicate(STACK<LN> letter, char postfixLetter) 
{
	for (int b = 0; b <= letter.StackItems(); ++b) 
	{
		if (letter.PeekStack(b) == postfixLetter) return true;
	}
	return false;
}
bool isLetter(char a) 
{
	if ((a >= char('a') && a <= char('z')) || (a >= char('A') && a <= char('Z'))) return true;
	return false;
}
void doArrithmatic(STACK<int> &number, char sign)
{
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
		STACK<int> numbers;
		STACK<LN> lettersNumbers;

		cout << "\tEnter a postfix expression with a $ at the end: "; cin >> postfix;

		int i = 0;

		while (i < postfix.length())
		{
			if (i == postfix.length() - 1 && postfix[i] != '$') 
			{
				postfix = postfix + '$';
			}
			int value;
			
			if (isLetter(postfix[i])) 
			{
				if (!isDuplicate(lettersNumbers, postfix[i])) 
				{
					cout << "\t\tEnter the value of " << postfix[i] << ": "; cin >> value; numbers.PushStack(value);
					lettersNumbers.PushStack(postfix[i], value);
				}
				else 
				{
					for (int p = 0; p <= lettersNumbers.StackItems(); p++)
					{
						if (lettersNumbers.PeekStack(p) == postfix[i]) 
						{
							numbers.PushStack(lettersNumbers.GetInt(p));
							break;
						}
					}
				}
			}
			else {
				if (postfix[i] == '/' || postfix[i] == '*' || postfix[i] == '-' || postfix[i] == '+' || postfix[i] == '$') 
				{
					doArrithmatic(numbers, postfix[i]);
				}
				else 
				{
					cout << "Opperator not recognized!\n";
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

