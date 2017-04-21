#include <iostream>
#include <conio.h>
#include <fstream>
#include "Stack1.h"
#include <string>

using namespace std;
using MyProg::Stack;

int main()
{
	setlocale(LC_ALL, "Rus");

	Stack <char> St;

	St.push('a');
	St.push('m');
	St.push('r');
	St.push('a');
	St.push('d');
	St.push('B');
	try
	{
		St.print();
		St.pop();
		St.print();
		St.pop();
		St.print();
		St.pop();
		St.print();
	}
	catch (const string& e)
	{
		cout << e << '\n';
	}
	system("pause");
	return 0;
}