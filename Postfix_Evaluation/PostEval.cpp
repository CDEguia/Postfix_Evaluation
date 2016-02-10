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
bool isDuplicate(STACK<LN> letter, char postfixLetter, STACK<int> &number) 
{
	for (int b = 0; b <= letter.StackItems(); ++b) 
	{
		if (letter.PeekStack(b) == postfixLetter) {
			number.PushStack(letter.GetInt(b));
			return true;
		}
	}
	return false;
}
bool isLetter(char a) 
{
	if ((a >= char('a') && a <= char('z')) || (a >= char('A') && a <= char('Z'))) return true;
	return false;
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
				if (!isDuplicate(lettersNumbers, postfix[i], numbers)) 
				{
					cout << "\t\tEnter the value of " << postfix[i] << ": "; cin >> value; numbers.PushStack(value);
					lettersNumbers.PushStack(postfix[i], value);
				}
			}
			else {
				switch (postfix[i])
				{
					int first, second, num, den;
				case '+':
					numbers.PushStack(numbers.PopStack() + numbers.PopStack());
					break;
				case '-':
					second = numbers.PopStack(); 
					first = numbers.PopStack();
					numbers.PushStack(first - second);
					break;
				case '*':
					numbers.PushStack(numbers.PopStack() * numbers.PopStack());
					break;
				case '/':
					den = numbers.PopStack(); 
					num = numbers.PopStack();
					numbers.PushStack(num / den);
					break;
				case '$':
					cout << "\t\t\tFinal value = " << numbers.PopStack() << endl;
					break;
				default:
					cout << "Opperation not recognized\n";
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

