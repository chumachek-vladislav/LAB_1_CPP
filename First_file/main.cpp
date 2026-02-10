#define _USE_MATH_DEFINES
#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>

using namespace std;

int menu();
void task_1();
void task_2();
void task_3();
void task_4();

int main() {
	setlocale(LC_ALL, "RU");
	cout << "Автор: Чумачек В.С.\nЛабораторная работа 1, Вариант 10" << endl;
	menu();
	return 0;
}

int menu() {
	int num;
	do {
		cout << "\n>>> МЕНЮ <<<\n" << "1. - Задание 1\n" << "2. - Задание 2\n" << "3. - Задание 3\n" << "4. - Задание 4\n" << "0. - Выход\n" << "Пункт меню: ";
		cin >> num;
		switch (num) {
		case 1: {
			task_1();
			break;
		}
		case 2: {
			task_2();
			break;
		}
		case 3: {
			task_3();
			break;
		}
		case 4: {
			task_4();
			break;
		}
		case 0: {
			cout << "Выход..." << endl;
			break;
		}
		default: cout << "Неверный пункт меню!" << endl;
		}
	} while (num != 0);

	return 0;
}

void task_1() {
	double a, b;
	cout << "\n> Задание 1\n";
	cout << "Введите значение a: ";
	cin >> a;
	cout << "Введите значение b: ";
	cin >> b;

	// Числитель: 
	double chislit = cos(M_PI * a) - 1.2 * pow(b, 2);

	// Знаменатель: 
	double znam = cos(pow(a, 2)) + pow(b, 2) * cos(13.4 * b);
	double full_znam = pow(b, 2) * znam;

	if (full_znam == 0) {
		cout << "Ошибка: Знаменатель равен нулю" << endl;
	}
	else {
		double fraction = chislit / full_znam;
		if (fraction < 0) {
			cout << "Ошибка: Подкоренное выражение меньше нуля (" << fraction << ")" << endl;
		}
		else {
			double res = sqrt(fraction);
			cout << "Для выражения при a= " << defaultfloat << a << " и b=" << b;
			cout << fixed << setprecision(5);
			cout << "\nОтвет (5 знаков): " << res << endl;
		}
	}
}

void task_2() {
	double x, eps = 0.001;
	cout << "\n> Задание 2\n";
	cout << "F(x) = cos(x) + 1/2*cos(2x) + ... + 1/n*cos(nx)" << endl;
	cout << "Введите x (0 < x <= pi): ";
	cin >> x;

	double sum = 0;
	double cur = 0; 
	double prev;   
	int n = 1;

	cout << fixed << setprecision(5);

	// Заголовок таблицы
	cout << "\n" << setw(5) << " n (шаг)"
		<< setw(17) << "Текущий член"
		<< setw(13) << "Сумма" << endl;
	cout << string(40, '-') << endl; 

	cur = (1.0 / n) * cos(n * x);
	sum += cur;

	cout << setw(5) << n
		<< setw(20) << cur
		<< setw(15) << sum << endl;

	do {
		prev = cur;          
		n++;                  
		cur = (1.0 / n) * cos(n * x); 
		sum += cur;        

		cout << setw(5) << n
			<< setw(20) << cur
			<< setw(15) << sum << endl;

	} while (abs(cur - prev) > eps);

	cout << string(40, '-') << endl;
	cout << "Итоговая сумма: " << sum << endl;
	cout << "Всего итераций: " << n << endl;
}

void task_3() {
	int num1;
	cout << "\n> Задание 3\n";
	cout << "Подзадания:\n" << "1. - Подзадача 1\n" << "2. - Подзадача 7\n";
	cout << "Выберите подзадачу: ";
	cin >> num1;

	if (num1 == 1) {
		int n;
		cout << "\nПодзадача 1\n"; 
		cout << "Введите натуральное число n: ";
		cin >> n;
		if (n <= 0) {
			cout << "\nЧисло должно быть натуральным (больше 0)!" << endl;
		}
		else {
			cout << "\nНатуральные делители числа " << n << ": ";
			for (int i = 1; i <= n; i++) {
				if (n % i == 0) {
					cout << i << " ";
				}
			}
			cout << endl;
		}
	}
	else if (num1 == 2) {
		cout << "\nПодзадача 7\n";

		double P = 1.0;
		for (int i = 1; i <= 20; i++) {
			for (int j = 1; j <= 20; j++) {
				P = P * (1.0 / (i + j * j));
			}
		}
		cout << "Результат P = " << P << endl;
	}
	else {
		cout << "Неверный выбор\n";
	}
}

void task_4() {
	cout << "\nВычислить значение 1/a\n";

	double a;
	cout << "Введите число a: ";
	cin >> a;

	if (a == 0) {
		cout << "Ошибка: Введено число 0, a != 0!" << endl;
	}
	else {
		double res = 1.0 / a;
		cout << "Результат: 1/" << defaultfloat << a;
		cout << fixed << setprecision(5);
		cout << " = " << res << endl;
	}
}