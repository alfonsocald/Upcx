#include <iostream>
#include <conio.h>
#include <functional>

using namespace std;

typedef unsigned long long ull;

template <class T>

class Ordenamientos {

    T* arreglo;

    int c;

public:

    Ordenamientos(ull cantidad = 20) {

        c = cantidad;

        arreglo = new T[c];

    }

    void swap(T* a, T* b) {

        T c = *a;

        *a = *b;

        *b = c;

    }

    //void swap(T* a, T* b, function<bool(T, T)> compara) {

    //    if (compara(*a, *b)) {

    //        T c = *a;

    //        *a = *b;

    //        *b = c;

    //    }

    //}

    void intercambio() {

        for (ull i = 0; i < c - 1; ++i)

            for (ull j = i + 1; j < c; ++j)

                if (arreglo[i] > arreglo[j])

                    swap(&arreglo[i], &arreglo[j]);

    }

    void burbuja() {

        for (ull i = 0; i < c - 1; ++i)//cantidad de iteraciones

            for (ull j = 0; j < c - 1; ++j)

                if (arreglo[j] > arreglo[j + 1])

                    swap(&arreglo[j], &arreglo[j + 1]);

    }

    void burbujaL() {

        for (ull i = 0; i < c - 1; ++i)//cantidad de iteraciones

            for (ull j = 0; j < c - 1; ++j)

                swap(&arreglo[j], &arreglo[j + 1], [](T a, T b)->bool {return a < b; });

    }

    void burbujaMejorado() {

        for (ull i = 0; i < c - 1; ++i)//cantidad de iteraciones

            for (ull j = 0; j < c - 1 - i; ++j)

                if (arreglo[j] > arreglo[j + 1]) {

                    swap(&arreglo[j], &arreglo[j + 1]);

                    /*      T aux=arreglo[j];

                          arreglo[j]=arreglo[j+1];

                          arreglo[j+1]=aux;*/

                }

    }

    void burbuja_1() {

        bool cambio;

        int elem = c;

        do {

            cambio = false;

            for (int i = 0; i < elem - 1; ++i) {

                if (arreglo[i] > arreglo[i + 1]) {

                    swap(&arreglo[i], &arreglo[i + 1]);

                    cambio = true;

                }

            }

            elem--;

        } while (cambio);

    }

    ull division(ull i, ull d, ull p) {
        ull temp;
        while (!(i == p && p == d && i == d))
        {
            //Quick sort tiene dos condiciones, la izquierda tiene que ser menor que el pivote y la derecha tiene que ser mayor al pivote
            while (arreglo[d] >= arreglo[p] && i < d) {
                --d;
            }
            temp = arreglo[d]; //Se guarda el elemento de la derecga en temporal
            arreglo[d] = arreglo[p]; // El elemento de la derecha pasa a ser ahora el pivote (se intercambian)
            arreglo[p] = temp;
            //swap(&arreglo[d], &arreglo[p]);//Si la derecha es menor al pivote, se intercambia.
            p = d;
            while (arreglo[i] <= arreglo[p] && i < d) {//Si la izq es menor que el pivote se suma para seguir comparando otros elementos
                i++;
            }
            temp = arreglo[i]; //Se guarda el elemento de la izquierda en temporal
            arreglo[i] = arreglo[p]; // El elemento de la izquierda pasa a ser ahora el pivote (se intercambian)
            arreglo[p] = temp;
            //swap(&arreglo[i], &arreglo[p]);
            p = i;
        }
        return p;//Retorna el pivote, ese pivote que se retorna se deberia encontrar en la posicion correcta.
    }

    void quicksort(ull i, ull d, ull p)//Izquierda, Derecha y Pivote 
    {
        if (i >= d) return;
        //Se divide en 2 partes, uno que va hasta el índice (pivote)
        ull indice = division(i,d,p); //Este indice devuelve el pivote de donde se había quedado anteriormente
        //El pivote puede ser elegido en cualquier parte de la lista, en este caso por la izquierda 
        quicksort(i, indice, i);//Partición por la izquierda, la izquierda es el primer elemento, y el indice - 1 (uno anterior al índice) sería la derecha de la partición de la izquierda
        quicksort(indice + 1, d, indice + 1);//Partición por la derecha, el índice + 1 (el elemento siguiente del índice) es la izquierda o el primer elemento de la particion por la derecha
    }
    void quicksort() {
        quicksort(0, c - 1, 0);
    }
    void generar() {

        for (size_t i = 0; i < c; ++i)

            arreglo[i] = rand() % 100;

    }

    void mostrar() {

        for (size_t i = 0; i < c; ++i)

            cout << arreglo[i] << " ";

        cout << "\n";

    }

};

int main() {
    Ordenamientos<int> o;
    o.generar();
    o.mostrar();
    o.quicksort();
    o.mostrar();
    _getch();
}
