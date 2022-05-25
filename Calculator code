#include <iostream>
#include <math.h>
#include <string>
#include <cstring>
#include <sstream>	 // to convert int and float to string
#include <algorithm> // reverse function

using namespace std;

#define pi 3.142
#define e 2.718

class Calculator
{
	private:
		string expression;

	public:
		void setexpression(string expression)
		{
			while(expression=="")
			{
				cout << "Enter a valid expression: ";
				getline(cin , expression);
			}
			this->expression = expression;
		}

		string getexpression()
		{
			return expression;
		}

		template <class T1, class T2>
		double add(T1 a, T2 b)
		{
			return a + b;
		}

		template <class T1, class T2>
		double subtract(T1 a, T2 b)
		{
			return a - b;
		}

		template <class T1, class T2>
		double multiply(T1 a, T2 b)
		{
			return a * b;
		}

		template <class T1, class T2>
		double divide(T1 a, T2 b)
		{
			return a / b;
		}

		template <class T>
		double percent(T a)
		{
			return a / 100;
		}

		template <class T>
		double root(T a)
		{
			return sqrt(a);
		}

		template <class T>
		double negate(T a)
		{
			return a * -1;
		}

		template <class T1, class T2>
		double power(T1 a, T2 b)
		{
			return pow(a, b);
		}

		int factorial(int a)
		{
			int i, ans = 1;
			if (a == 0 || a == 1)
			{
				return 1;
			}
			else if (a < 0)
			{
				for (i = a; i < 0; i++)
				{
					ans = ans * i;
				}
			}
			else if (a > 1)
			{
				for (i = a; i > 1; i--)
				{
					ans = ans * i;
				}
			}
			return ans;
		}

		template <class T>
		string stringsion(T a)
		{
			// making object of the class ostringstream
			ostringstream str1;
			// sending the integer or float as a stream in the object
			str1 << a;
			// declaring a string variable and saving the recieved string in it
			string temp = str1.str();
			// returning the value
			return temp;
		}

		void clear(string *expression)
		{
			*expression = " ";
		}

		string update(string a, int end, string answer)
		{
			string *temp = new string;
			*temp += answer;
			int len = a.length();
			for (int i = end + 1; i < len; i++)
			{
				*temp += a[i];
			}
			a = *temp;
			return a;
		}

		string epi(string a , int len)
		{
			string *temp = new string;
			for(int i=0;i<len;i++)
			{
				if(a[i]=='p')
				{
					*temp += "3.142";
				}
				else if(a[i]=='e')
				{
					*temp += "2.718";
				}
				else
				{
					*temp += a[i];
				}
			}
			a = *temp;
			return a;
		}

		string ErrorCheck(string expression, int len)
		{
			while (expression == "")
			{
				cout << "Invalid";
				clear(&expression);
			}
			int i;
			for (i = 1; i < len; i++)
			{
				if ((expression[i] == '+' || expression[i] == '-' || expression[i] == '*' || expression[i] == '/' || expression[i] == '.') && (expression[i - 1] == '+' || expression[i - 1] == '-' || expression[i - 1] == '*' || expression[i - 1] == '/' || expression[i - 1] == '.'))
				{
					cout << "Invalid";
					clear(&expression);
				}
				if (expression[i - 1] == '/' || expression[i] == '0')
				{
					cout << "Invalid";
					clear(&expression);
				}
				if(expression[i]=='r' && expression[i+1]=='-')
				{
					cout << "Imaginary answer";
					clear(&expression);
				}
			}
			if (expression[0] == '*' || expression[0] == '/' || expression[0] == '%' || expression[0] == '^')
			{
				cout << "Invalid";
				clear(&expression);
			}
			if (expression[len - 1] == '*' || expression[len - 1] == '/' || expression[len - 1] == '+' || expression[len - 1] == '-' || expression[len - 1] == '^' || expression[len - 1] == '!')
			{
				cout << "Invalid";
				clear(&expression);
			}
			return expression;
		}

		int convertor(int a)
		{
			return a - 48;
		}

		float getnumber(string num)
		{
			int len, i, count, multiplier, number;
			float total;
			char decimal;
			len = num.length();
			count = 0;
			multiplier = 1;
			total = 0.0;
			decimal = ' ';
			for (i = len - 1; i >= 0; i--)
			{
				if (num[i] == '.')
				{
					decimal = '.';
					continue;
				}
				number = convertor(num[i]);
				total = total + (number * multiplier);
				multiplier = multiplier * 10;
				if (decimal != '.')
				{
					count = count + 1;
				}
			}
			if (count >= 0 && decimal == '.')
			{
				total /= pow(10, count);
			}
			return total;
		}

		string singlesolve(string expression, int len)
		{
			int i, start, end, j, place = 0;
			string num;
			float number, answer;
			char sign = ' ';
			for (i = 0; i < len; i++)
			{
				start = i;
				if (expression[i] == 'r' || expression[i] == '!')
				{
					sign = expression[i];
					j = i + 1;
					while (expression[j] != '+' || expression[j] != '-' || expression[j] == '*' || expression[j] == '/' || expression[j] == 'r' || expression[j] == '!' || expression[j] == '%' || expression[j] == '^')
					{
						num += expression[j];
						j++;
					}
					number = getnumber(num);
					end = j;
					break;
				}
				else if (expression[i] == '%')
				{
					sign = expression[i];
					end = i;
					j = i - 1;
					while (expression[j] != '+' || expression[j] != '-' || expression[j] == '*' || expression[j] == '/' || expression[j] == 'r' || expression[j] == '!' || expression[j] == '%' || expression[j] == '^')
					{
						num += expression[j];
						j--;
					}
					reverse(num.begin(), num.end());
					number = getnumber(num);
					start = j;
					break;
				}
			}
			
			if(sign!=' ')
			{
				switch (sign)
				{
				case 'r':
					answer = root(number);

				case '%':
					answer = percent(number);

				case '!':
					answer = factorial(number);
				}
				string ans = stringsion(answer);
				expression = update(expression, end, ans);
				setexpression(expression);
			}
			return expression;	
		}

		string solve(string expression, int len)
		{
			int start = 0, end, i, j;
			char sign1 = ' ', sign2 = ' ';
			float number1, number2, answer;
			string num1, num2;
			for (i = 0; i < len; i++)
			{
				if (expression[i] == '+' || expression[i] == '-' || expression[i] == '*' || expression[i] == '/' || expression[i] == '^')
				{
					sign1 = expression[i];
					for (j = i + 1; j < len; j++)
					{
						if (expression[j] == '+' || expression[j] == '-' || expression[j] == '*' || expression[j] == '/' || expression[j] == '^')
						{
							sign2 = expression[j];
							end = j - 1;
							break;
						}
						if (sign2 == ' ')
						{
							num2 += expression[j];
						}
					}
				}
				if (sign1 == ' ')
				{
					num1 += expression[i];
				}
				if (sign1 != ' ' && sign2 != ' ')
				{
					break;
				}
			}

			if(sign1!=' ' && sign2!=' ')
			{
				number1 = getnumber(num1);
				number2 = getnumber(num2);
				switch (sign1)
				{
				case '+':
					answer = add(number1, number2);

				case '-':
					answer = subtract(number1, number2);

				case '*':
					answer = multiply(number1, number2);

				case '/':
					answer = divide(number1, number2);

				case '^':
					answer = power(number1, number2);
				}
				string ans = stringsion(answer);
				expression = update(expression, end, ans);
				setexpression(expression);
			}
			return expression;
		}

		string process(string expression)
		{
			int len, i, j;
			len = expression.length();
			expression = epi(expression , len);
			expression = ErrorCheck(expression, len);
			for (i = 0; i < len; i++)
			{
				if (expression[i] == 'r' || expression[i] == '!' || expression[i] == '%')
				{
					expression = singlesolve(expression , len);
				}
			}
			for (i = 1; i < len; i++)
			{
				if (expression[i] != '+' || expression[i] != '-' || expression[i] == '*' || expression[i] == '/' || expression[i] == '^')	
				{
					expression = solve(expression , len);
				}
			}
			return expression;
		}

		Calculator()
		{
			string exp;
			cout << "Enter your expression: ";
			getline(cin , exp);
			setexpression(exp);
			exp = process(exp);
			setexpression(exp);
			cout << getexpression();
		}
};

int main()
{
	Calculator expression1;
	return 0;
}
