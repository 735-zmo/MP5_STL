#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <iterator>

using namespace std;

void printL(list<int> cont, int x)
{
	cout << "�������� ���������� �" << x << ":";
	list <int>::iterator it;
	for (it = cont.begin(); it != cont.end(); it++) 
		cout <<*it <<" ";
	cout << endl;
}

void printV(vector<int> cont, int x)
{
	cout << "�������� ���������� �" << x << ":";
	vector <int>::iterator it;
	for (it = cont.begin(); it != cont.end(); it++)
		cout << *it << " ";
	cout << endl;
}

int main()
{
	setlocale(LC_ALL, "Rus");

	//1.�������� ���������� (list) � ����������
	cout << "����� �1 (C������� ���������� � ����������)"<<endl;
	list <int> l;
	int n, x;
	cout << "������� ������ ����������: ";
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cout << "\t������� ������� �"<<i<<": ";
		cin >> x;
		l.push_back(x);
	}
	cout << endl;

	//2.���������� ���������� �� ��������
	l.sort();
	l.reverse();

	//3.�������� ����������
	cout << "����� �2 � �3 (�������� ���������������� ����������)"<<endl;
	printL(l,1);
	cout << endl;

	//4.����� ��������� ��������
	cout << "����� �4 (����� ��������)"<<endl;
	list<int>::iterator it;
	int a;
	cout << "������� ������� ��� ������ � 1-�� ����������: ";
	cin >> a;
	it = find(l.begin(), l.end(), a);
	if (it != l.end()) cout << "�������� �������: "<<*it<<endl;
	else cout << "��������� �������� � ���������� ���!" << endl;
	cout << endl;
	
	//5.����������� ���������, ��������������� �������, �� 2-�� ��������� � �������� 2-�� ����������
	cout << "����� �5 (����������� ���������, ��������������� �������)"<<endl;
	vector<int> v1;
	int b;
	char c;
	cout << "������� ������� ��� ����������� ��������� �� 2-�� ���������: ";
	cin >> b;
	do
	{
		it = find(l.begin(), l.end(), b);
		if (it != l.end())
		{
			v1.push_back(*it);
			l.erase(it);
			it = l.begin();
		}
	} while (it != l.end());
	printL(l,1);
	cout << endl;

	//6.�������� 2-�� ����������
	cout << "����� �6 (�������� 2-�� ����������)"<<endl;
	printV(v1,2);
	cout << endl;

	//7. ���������� �����������
	l.sort();
	sort(v1.begin(), v1.end());

	//8.�������� �����������
	cout << "����� �7 � �8 (�������� ��������������� �����������)"<<endl;
	printL(l,1);
	printV(v1,2);
	cout << endl;

	//9.������� �����������
	vector<int> v2(l.size() + v1.size());
	merge(v1.begin(), v1.end(), l.begin(), l.end(), v2.begin());

	//10. �������� ������������� ����������
	cout << "����� �9 � �10 (������� � ��������)" << endl;
	printV(v2,3);
	cout << endl;

	//11.������� ���������,��������������� ��������� �������
	cout << "����� �11 (������� ������ ���������)" << endl;
	vector<int>::iterator it_v;
	int N = 0;
	for (it_v = v2.begin(); it_v != v2.end(); it_v++)
	{
		if ((*it_v) % 2) N++;
	}
	cout << "����� ������ ��������� � 3 ����������: " << N << endl;
	cout << endl;

	//12.����������� ����������� ��������� ��������
	cout << "����� �12 (����������� ����������� ��������� ��������)" << endl;
	int y;
	cout << "������� ������� ��� ���������� ��� ����������� � ����������:";
	cin >> y;
	it_v = find(v2.begin(), v2.end(), y);
	if (it_v != v2.end()) cout << "�������� ������� ������������ � ����������" << endl;
	else cout << "��������� ������� � ���������� ���" << endl;

	system("pause");
	return 0;
}