#include <iostream>
#define T 7

using namespace std;

void troca(int *a, int *b){
    int aux;
    aux=*a;
    *a=*b;
    *b=aux;
}

void descer(int A[], int i, int q){
    int d =  2*i+1;       // se array iniciar com 1, d=2*1+2
    int e = 2*i;          // se array iniciar com 1, e= 2*i+1

    int maior=i;
    // verificar se tem filhos e comparar com d(direita) e e(esquerda)

    if(d<=q && A[d]>A[i]){
        maior=d;
    }
    if (e<=q && A[e]>A[maior]){
        maior=e;
    }
    if(maior!=i)
    {
        //trocar com o maior dos filhos e chamar a função novamente 
        troca(&A[i],&A[maior]);
        descer(A, maior, q);
    }
}

void subir(int A[], int i){
    int j=i/2;
    if(j>=0){
        if(A[i] > A[j]){
            troca(&A[i], &A[j]);
            subir(A, j);
        }
    }
}

void heap (int A[], int t){
    for (int i = t-1; i>=0;i--){                                        
       subir(A, i);                                       
    }
}

void heapsort(int A[], int n){
    int i;
    heap(A,T);

    for(i=n-1; i>=1; i--){
        troca(&A[0],&A[i]);
        descer(A,0,i-1);
    }
}



int main(){
    int A[T] = {35, 18, 30, 2, 27, 50, 10};
    int i;
    heap(A,T);              // professora por algum motivo só consigo ordenar direito usando duas vezes o heap
    heapsort(A,T);          // retirando esse heap do main, dois numeros no meio do vetor ficam trocados de lugar
    for(i=0; i<T; i++){
        cout << A[i] << " ";
    }
}