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
};

template <class T>
class STACK
{
public:
	STACK();
	~STACK();
	bool EmptyStack();
	bool FullStack();
	void PushStack(T x);
	int PopStack();
	char PeekStack(int i);
	void PrintStack();
	int LastItem();

private:
	T a[max];
	int counter;
};

template <class T>
STACK<T>::STACK()
{
	counter = 0;
}

template <class T>
bool STACK<T>::EmptyStack()
{
	return counter == 0 ? true : false;
}

template <class T>
bool STACK<T>::FullStack()
{
	return counter == max ? true : false;
}

template <class T>
void STACK<T>::PushStack(T x)
{
	a[counter] = x;
	counter++;
}

template <class T>
int STACK<T>::PopStack()
{
	--counter;
	return a[counter];
}

template <class T>
char STACK<T>::PeekStack(int i) {
	return a[i];
}

template <class T>
int STACK<T>::LastItem() {
	if (counter == 0) return counter;
	return (counter - 1);
}

template <class T>
void STACK<T>::PrintStack() {
	int i = 0;
	while( i < counter){
		cout << i << " " << a[i] << endl;
		i++;
	}
}

template <class T>
STACK<T>::~STACK()
{
}


bool isDuplicate(STACK<char> letter, char postfixLetter) {
	for (int i = 0; i <= letter.LastItem(); ++i) {
		if (letter.PeekStack(i) == postfixLetter) return true;
	}
	return false;
}


bool isLetter(char a) {
	if ((a >= char('a') && a <= char('z')) || (a >= char('A') && a <= char('Z'))) return true;
	return false;
}

void doArrithmatic(STACK<int> &number, char sign) {
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

int main() {
	char cont;
	do
	{
		string postfix;
		LN lettersNumbers[max];
		STACK<char> letters;
		int value;
		STACK<int> numbers;

		cout << "\tEnter a postfix expression with a $ at the end: "; cin >> postfix;
		
		int i = 0;
		
		while(i < postfix.length() && postfix[i] != '$')
		{
			if (isLetter(postfix[i])) {
				if (!isDuplicate(letters, postfix[i])) {
					cout << "\t\tEnter the value of " << postfix[i] << ": "; cin >> value; numbers.PushStack(value);
					lettersNumbers[i].a = postfix[i];
					lettersNumbers[i].x = value;
					
					letters.PushStack(postfix[i]);
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