#include <iostream>
#include <conio.h>

using namespace std;

typedef unsigned long ul;
template <class T>



class Sorting
{
	T* elementos;
	int c;
private:
	
	void _quicksort(ul i, ul d, ul p) {//Izquierda derecha pivote
	//Quicksort es una funcion recursiva (se usa una y otra ves la misma funcion) que ordena por la derecha y por la izquierda
		if (i >= d)return;
		ul indice = _ordenar(i, d, p);
		_quicksort(i, indice, i);//Ordenar por la derecfha
		_quicksort(indice + 1, d, indice + 1);//Ordenar por la izquierda
	}

	ul _ordenar(ul i, ul d, ul p) {

		while (!(i == p && d == p && i == d))
		{


			while (elementos[p] <= elementos[d] && i < d) //Si el elemento de la derecha es mayor al pivote
			{
				--d;
			}
			swap(elementos[d], elementos[p]);//Función de STD

			p = d; //actualiza la posicion del pivote

			/*ul temp = elementos[d]; //Se guarda el elemento de la derecga en temporal
			elementos[d] = elementos[p]; // El elemento de la derecha pasa a ser ahora el pivote (se intercambian)
			elementos[p] = temp;*/

			while (elementos[i] <= elementos[p] && i < d)//Si el elemento de l a izquierda es menor que el elemento pivote
			{
				++i;//La izquierda aumenta hasta que se iguale con la derecha y el pivote
			}

			swap(elementos[i], elementos[p]);//Función de STD
			p = i; //actualiza la posicion del pivote


			/*ul temp = elementos[i]; //Se guarda el elemento de la izquierda en temporal
			elementos[i] = elementos[p]; // El elemento de la izquierda pasa a ser ahora el pivote (se intercambian)
			elementos[p] = temp;*/

		}
		return p;
	}


public:
	Sorting(int c) : c(c) { 
		elementos = new T[c]; 
		generar();
	};

	void generar() {
		for (int i = 0; i < c; i++)
		{
			elementos[i] = rand() % 100;
		}
	}	
	
	void mostrar() {
		for (int i = 0; i < c; i++)
		{
			cout << elementos[i] << " ";
		}
		cout << endl;
	}



	void quicksort() {//Cuando se llama al quicksort sin parametros este usa el quicksort que mantiene dentro con parametros
		_quicksort(0, c - 1, 0);
		//llamas al metodo publico y este llama al metodo privado que es recursivo
	}
};

int main() 
{
	srand(time(0));
	Sorting<long> s(10);
	s.mostrar();
	s.quicksort();
	s.mostrar();
	_getch();
}
