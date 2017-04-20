#include <iostream>
#include <vector>
#include <iterator>

using namespace std;

void printVector(vector <int> vect)
{
	for (int i = 0; i < vect.size(); i++)
	{
		cout << vect[i] << " ";
	}
	cout << endl;
}

int main()
{
	setlocale(LC_ALL, "Rus");

	int x1, x2;
	//1. C������� ���������� � ����������
	vector <int> vect1;
	for (int i = 0; i < 10; i++)
	{
		vect1.push_back(i);
	}

	//2. �������� ����������
	cout << "�������� �������� 1-�� ����o��: ";
	printVector(vect1);

	//3.��������� ����������, ����� �������� ��������� �� ���� � ���������� �����
	int y = vect1.size();
	for (int i = 6; i < y; i++)
	{
		vect1.pop_back();
	}

	for (int i = 1; i < 6; i++)
	{
		x1 = (-1)*i;
		vect1.insert(vect1.begin(), x1);
	}

	//4.�������� ���������� � ������� ���������
	cout << "������ 1-�� ������� � ������� ��������a:";
	vector <int>::iterator it;
	for (it = vect1.begin(); it < vect1.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;

	//5.�������� � ���������� ������� ����������
	vector <int> vect2;
	for (int i = 0; i < 10; i++)
	{
		x2 = 20 + i;
		vect2.push_back(x2);
	} 

	//6.��������� ������� ����������, ����� �������� �� ���� n ��������� ����� ��������� � ���������� ���� ��������� �� ������� ����������
	vect1.erase(vect1.begin()+5, vect1.end());
	copy(vect2.begin(), vect2.end(), back_inserter(vect1));

	//7.�������� ������� � ������� �����������
	cout << "�������� 1-�� ������� ����� ��������� ���������:";
	printVector(vect1);
	cout << "�������� 2-�� �������:";
	printVector(vect2);

	system("pause");
	return 0;
}