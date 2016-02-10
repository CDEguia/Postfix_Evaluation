//------------------------------------------------------------------------------
//          Name		Candelario D. Eguia
//          Course		CMPS-455
//          Project		No.1
//          Due date	Feb. 19, 2015
//          Professor	Ray Ahmadnia
//
// This program displays:
//       Evaluate post algorithems
//------------------------------------------------------------------------------
#include <iostream>
#include <string>

#define max 10			//Maximum number of variable in the postfix experssion 

using namespace std;

struct LN{				//for storing variable and value				
	char c;
	int x;
};

template <class  T >
class  STACK
{
public:
	STACK()
	{
		counter = 0;				//stack/array location
	}
	void PushStack(int n)			//For calc and storage of postfix ints
	{
		a[counter++] = n;
	}
	void PushStack(char z, int n)	//Store for dupication checking
	{
		a[counter].c = z;
		a[counter++].x = n;
	}
	int PopStack()					//For postfix calculation
	{
		return a[--counter];
	}
	char PeekStack(int n)			//Returns previously entered variables
	{
		return a[n].c;
	}
	int GetInt(int n)				//Returns previously entered integer data
	{
		return a[n].x;
	}
	int StackItems()				//Returns the current end of stack location
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
	{						//Compare previously saved Letters to current letter
		if (letter.PeekStack(b) == postfixLetter) {	
			number.PushStack(letter.GetInt(b));		//use old int
			return true;				//if current letter is a duplicate
		}
	}
	return false;						//if current letter is new
}
bool isLetter(char a) 
{						//Check to see if current variable is a letter or symbol
	if ((a >= char('a') && a <= char('z')) || (a >= char('A') && a <= char('Z'))) return true;
	return false;		//Returns false if it is not a letter
}
int main() {
	char cont;
	
	do
	{
		string postfix;					//Stores user postfix expression
		STACK<int> numbers;				//Stores and holds final calculation
		STACK<LN> lettersNumbers;		//Stores leter and number combinations
										//get and store user input
		cout << "\tEnter a postfix expression with a $ at the end: "; cin >> postfix;
										//itterate through postfix expression
		for (int i = 0; i < postfix.length(); ++i)		
		{								//check if the user forgot the $
			if (i == postfix.length() - 1 && postfix[i] != '$') 
			{							//Add $ to string
				postfix = postfix + '$';
			}

			int value;				//Declare variable for user variable values
			if (isLetter(postfix[i]))	//Call to determin Letter or Symbol
			{							//Determin if Letter is a duplicate
				if (!isDuplicate(lettersNumbers, postfix[i], numbers)) 
				{						//Get value of postfix variable
					cout << "\t\tEnter the value of " << postfix[i] << ": "; cin >> value; 
					numbers.PushStack(value);	//Assign value to the stack
									//Assign variable and value to the stack
					lettersNumbers.PushStack(postfix[i], value);
				}
			}
			else {
				switch (postfix[i])		//Do Arrithmatic
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
		}		
		cout << "Continue (y/n)? "; cin >> cont; cont = toupper(cont);
		cout << endl;
	} while (cont != 'N');

	system("pause");
	return 0;
}
/*-- OUTPUT ------------------------------------------------------------
        Enter a postfix expression with a $ at the end: ab*c+$
                Enter the value of a: 2
                Enter the value of b: 3
                Enter the value of c: 4
                        Final value = 10
Continue (y/n)? y

        Enter a postfix expression with a $ at the end: beef*++
                Enter the value of b: 2
                Enter the value of e: 3
                Enter the value of f: 4
                        Final value = 17
Continue (y/n)? n

Press any key to continue . . .
----------------------------------------------------------------------*/

