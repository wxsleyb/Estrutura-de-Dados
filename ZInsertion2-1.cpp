#include <iostream>
#define N 16

using namespace std;

int main()
{
    int i, j, aux;
    int v[N] = {3, 15, 25 , 33, 44, 54, 95, 50, 48, 11, 14, 4, 1, 99, 55, 23};
    //  algoritmo insertionSort
    for (i=0; i<N;i++)
    {
        aux= v[i];
        j=i-1;

        while ((j>=0) && (aux<v[j]))
        {
            v[j+1]= v[j];
            j--;
        }

        v[j+1] = aux;
    }
       for (int i=0; i<N; i++)
       {
         cout << v[i] << " ";
         }
return 0;

}