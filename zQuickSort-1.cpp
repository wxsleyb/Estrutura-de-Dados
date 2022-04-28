#include <iostream> 
#define T 8
using namespace std;

void quickSort(int[], int, int);
void troca(int *, int *);
int particiona(int[], int, int);

int main(){
    int i, A[T] = {20, 8, 15, 30, 34, 11, 50, 2};
    quickSort(A,0,T-1);
    for (int i=0; i < T; i++){
        cout << A[i] << endl;
    }
}

void quickSort(int A[], int inicio, int fim){
    int j;
    if (fim - inicio < 2){
        if(fim - inicio ==1){
            if (A[inicio] > A[fim])
            {
                troca(&A[inicio], &A[fim]);
            }
        }
    }else {
        j= particiona(A, inicio, fim);
        troca (&A[inicio], &A[j]);
        quickSort (A, inicio, j-1);
        quickSort(A, j+1, fim);
    }
}

int particiona(int A[T], int inicio, int fim){
    int i = inicio;                             //particiona
    int j= fim;
    int chave = A[inicio];                        
    while(j > i){
        i++;
        while (A[i] < chave) i++;
        while (A[j]> chave) j--;                //particiona
        if(j>i){
            troca(&A[i], &A[j]);
        }

    }
    return 0;
}

void troca(int *x, int *y){
    int aux;
    aux= *x;
    *x= *y;
    *y = aux;
}