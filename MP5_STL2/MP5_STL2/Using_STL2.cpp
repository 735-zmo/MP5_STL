#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <iterator>

using namespace std;

void printL(list<int> cont, int x)
{
	cout << "Просмотр контейнера №" << x << ":";
	list <int>::iterator it;
	for (it = cont.begin(); it != cont.end(); it++) 
		cout <<*it <<" ";
	cout << endl;
}

void printV(vector<int> cont, int x)
{
	cout << "Просмотр контейнера №" << x << ":";
	vector <int>::iterator it;
	for (it = cont.begin(); it != cont.end(); it++)
		cout << *it << " ";
	cout << endl;
}

int main()
{
	setlocale(LC_ALL, "Rus");

	//1.Создание контейнера (list) и заполнение
	cout << "Пункт №1 (Cоздание контейнера и заполнение)"<<endl;
	list <int> l;
	int n, x;
	cout << "Введите размер контейнера: ";
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cout << "\tВведите элемент №"<<i<<": ";
		cin >> x;
		l.push_back(x);
	}
	cout << endl;

	//2.Сортировка контейнера по убыванию
	l.sort();
	l.reverse();

	//3.Просмтор контейнера
	cout << "Пункт №2 и №3 (Просмотр отсортированного контейнера)"<<endl;
	printL(l,1);
	cout << endl;

	//4.Поиск заданного элемента
	cout << "Пункт №4 (Поиск элемента)"<<endl;
	list<int>::iterator it;
	int a;
	cout << "Введите элемент для поиска в 1-ом контейнере: ";
	cin >> a;
	it = find(l.begin(), l.end(), a);
	if (it != l.end()) cout << "Найденый элемент: "<<*it<<endl;
	else cout << "Заданного элемента в контейнере нет!" << endl;
	cout << endl;
	
	//5.Перемещение элементов, удовлетворяющих условию, во 2-ой контейнер и создание 2-го контейнера
	cout << "Пункт №5 (Перемещение элементов, удовлетворяющих условию)"<<endl;
	vector<int> v1;
	int b;
	char c;
	cout << "Введите условие для перемещения элементов во 2-ой контейнер: ";
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

	//6.Просмотр 2-го контейнера
	cout << "Пункт №6 (Просмотр 2-го контейнера)"<<endl;
	printV(v1,2);
	cout << endl;

	//7. Сортировка контейнеров
	l.sort();
	sort(v1.begin(), v1.end());

	//8.Просмотр контейнеров
	cout << "Пункт №7 и №8 (Просмтор отсортированных контейнеров)"<<endl;
	printL(l,1);
	printV(v1,2);
	cout << endl;

	//9.Слияние контейнеров
	vector<int> v2(l.size() + v1.size());
	merge(v1.begin(), v1.end(), l.begin(), l.end(), v2.begin());

	//10. Просмотр получившегося контейнера
	cout << "Пункт №9 и №10 (Слияние и просмотр)" << endl;
	printV(v2,3);
	cout << endl;

	//11.Подсчет элементов,удовлетворяющих заданному условию
	cout << "Пункт №11 (Подсчет четных элементов)" << endl;
	vector<int>::iterator it_v;
	int N = 0;
	for (it_v = v2.begin(); it_v != v2.end(); it_v++)
	{
		if ((*it_v) % 2) N++;
	}
	cout << "Число четных элементов в 3 контейнера: " << N << endl;
	cout << endl;

	//12.Определение присутствия заданного элемента
	cout << "Пункт №12 (Определение присутствия заданного элемента)" << endl;
	int y;
	cout << "Введите элемент для определния его присутствия в контейнера:";
	cin >> y;
	it_v = find(v2.begin(), v2.end(), y);
	if (it_v != v2.end()) cout << "Заданный элемент присутствует в контейнере" << endl;
	else cout << "Заданного элмента в контейнере нет" << endl;

	system("pause");
	return 0;
}