#include <iostream>
#include <locale.h>
using namespace std;

//функция выводит массив со сдвигом: loc_m - указатель на начало массива,
// loc_n - мощность массива, loc_k - значение сдвига 
void shift (int *loc_m, int loc_n, int loc_k) { 
	int counter = 0; //счетчик элементов массива
	loc_k = loc_k % loc_n; //проверка "сдвиг не больше мощности массива"
	while (counter < loc_n) { //проверка "пока счетчик не превышает количество элементов"
			if (counter+loc_k < loc_n) { //проверка не выходит ли элемент за границы массива
				cout << loc_m[counter+loc_k];
				}
			else { //если элемент вышел за массив, то уменьшаем номер элемента на длину массива
				cout << loc_m[counter+loc_k-loc_n];
			}
		counter++;
	}
}

int main () {
	
	setlocale(LC_ALL, "rus");
	
	int n = 0; int k = 0;
	cout << "Введите количество элементов в массиве: "; 
	cin >> n;
	int *p = new int[n]; //указатель на начало массива
	cout << "Введите элементы массива: ";
		for ( int i=0;i<n; i++) {
			cin >> p[i];
		}
	cout << "Введите значение сдвига: "; 
	cin >> k;
	shift (p, n, k); //передаём в функцию пользовательские параметры
	delete p;
	return 0;
}