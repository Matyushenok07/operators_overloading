#include <iostream> // Вариант 1 (старая методичка)
using namespace std;
//class str{};
class dek_koord
{
	int x, y;
public:
	dek_koord() {};
	dek_koord(int X, int Y) :x(X), y(Y) {}
	dek_koord operator=(const dek_koord);
	dek_koord operator+=(const dek_koord);
	void see();

};
class Dollars
{
private:
	int m_dollars;

public:
	Dollars(int dollars) { m_dollars = dollars; }

	friend bool operator> (const Dollars &d1, const Dollars &d2);
	friend bool operator<= (const Dollars &d1, const Dollars &d2);
	friend bool operator< (const Dollars &d1, const Dollars &d2);
	friend bool operator>= (const Dollars &d1, const Dollars &d2);
	friend bool operator== (const Dollars &d1, const Dollars &d2);
};

class Car
{
private:
	string m_company;
	string m_model;

public:
	Car(string company, string model) : m_company(company), m_model(model) {}
	friend bool operator== (const Car &c1, const Car &c2);// Перегрузка ==
	friend bool operator!= (const Car &c1, const Car &c2); //Перегрузка !=
};
dek_koord dek_koord::operator=(const dek_koord a)
{
	x = a.x;
	y = a.y;
	return *this;
}
dek_koord dek_koord::operator+=(const dek_koord a)
{
	x += a.x;
	y += a.y;
	return *this;
}
void dek_koord::see()
{
	cout << "Координата x= " << x << endl;
	cout << "Координата y= " << y << endl;
}
bool operator== (const Car &c1, const Car &c2)
{
	return (c1.m_company == c2.m_company &&
		c1.m_model == c2.m_model);
}

bool operator!= (const Car &c1, const Car &c2)
{
	return !(c1 == c2);
}
bool operator> (const Dollars &d1, const Dollars &d2)// Перегрузка операции>
{
	return d1.m_dollars > d2.m_dollars;
}

bool operator>= (const Dollars &d1, const Dollars &d2)// Перегрузка операции >=
{
	return d1.m_dollars >= d2.m_dollars;
}

bool operator< (const Dollars &d1, const Dollars &d2)//Перегрузка операции <
{
	return d1.m_dollars < d2.m_dollars;
}

bool operator<= (const Dollars &d1, const Dollars &d2)//Перегрузка операции <=
{
	return d1.m_dollars <= d2.m_dollars;
}
bool operator == (const Dollars &d1, const Dollars &d2)//Перегрузка операции ==
{
	return d1.m_dollars == d2.m_dollars;
}

int main()
{
	setlocale(LC_ALL, "rus");
	cout << "---------------------------ПЕРЕГРУЗКА ОПЕРАТОРОВ (==) (!=) --------------------------------------------------" << endl;
	Car mustang("Ford", "Mustang");
	Car logan("Renault", "Logan");
	if (mustang == logan)
		std::cout << "Мустанг и логан одно и то же." << endl;

	if (mustang != logan)
		std::cout << "Мустанг и логан не одно и то же." << endl;
	cout << endl << "---------------------------ПЕРЕГРУЗКА ОПЕРАТОРОВ (>)   (>=)   (<)  (<=)   (==) ------------------------------" << endl;
	Dollars ten(10);
	Dollars seven(7);
	if (ten > seven)
	{
		cout << "Десять долларов-это больше, чем семь долларов." << endl;
	}
	if (ten >= seven) {
		cout << "Десять долларов больше или равны семи долларам." << endl;
	}
	if (ten < seven) {
		cout << "Семь долларов-это больше, чем десять долларов." << endl;
	}
	if (ten <= seven) {
		cout << "Семь долларов больше или равны десяти долларам." << endl;
	}
	if (ten == seven)
	{
		cout << " Семь долларов равно десяти долларам" << endl;
	}
	cout << endl << "-----------------------------ПЕРЕГРУЗКА ОПЕРАТОРОВ (=)  (+=) ------------------------------------------------" << endl;
	dek_koord A(1, 2), B(3, 4), C;
	C = A;
	C.see();
	A += B;
	C.see();
	system("pause");
	return 0;
}