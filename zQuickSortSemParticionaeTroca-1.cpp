#include <iostream>
#define T 8
using namespace std;

void quickSort(int A[], int inicio, int fim)
{
   int i, j, chave, aux;
	if (fim - inicio < 2) {
		if ((fim - inicio) == 1) {	
			if (A[inicio] > A[fim])
			{
				aux = A[inicio];
				A[inicio] = A[fim];
				A[fim] = aux;
			}
		}
    } else {
        i= inicio;
        j= fim;
        chave = A[inicio];
        while (j > i){
            i++;
            while (A[i] < chave) i++;
            while (A[j] > chave) j --;
            if (j > 1){
                aux = A[i];
                A[i] = A[j];
                A[j] = aux;
            }
        
        }
    aux = A[inicio];
    A[inicio] = A[j];
    A[j] = aux;
    quickSort(A, inicio, j-1);
    quickSort(A, j+1, fim);
    }
   
}

main() {
	int i, A[T] = {15, 10, 14, 30, 34, 11, 50, 27};
	quickSort(A, 0, T-1);
	for(int i = 0; i < T; i++)
		cout << A[i] << " \t ";
}
