#include <iostream>
using namespace std;

void subir(int, int);
void descer(int, int, int *);
void remover(int, int *);
void inserir(int, int , int *);
void listar(int A[]);
void troca(int *, int *);


int main(){
    int i;
    int *q;
    int A[8] = {90,58,83,35,12,65,79,20};

    listar(A);


}

void inserir(int A[], int valor, int * t){
    *t= *t+1;
   A[*t] = valor;
    subir(A,*t);
}

//void remover(int A[], int *q){
//    A[1]= A[*q];
//    *q=*q-1;
//    descer(A, 1, *q);
//}

void subir(int A[], int i){
    int j=i/2;
    if(j>=0){
        if(A[i] > A[j]){
            troca(&A[i], &A[j]);
            subir(A, j);
        }
    }
}

void descer(int A[], int i, int *q){
    int d =  2*i+1;       // se array iniciar com 1, d=2*1+2
    int e = 2*i;          // se array iniciar com 1, e= 2*i+1

    int maior=i;
    // verificar se tem filhos e comparar com d(direita) e e(esquerda)

    if(d<=*q && A[d]>A[i]){
        maior=d;
    }
    if (e<=*q && A[e]>A[maior]){
        maior=e;
    }
    if(maior!=i)
    {
        //trocar com o maior dos filhos e chamar a função novamente 
        troca(&A[i],&A[maior]);
        descer(A, maior, q);
    }
}

void listar(int A[]){
    for(int i=0; i<8; i++){
        cout << A[i] << endl;
    }
}

void troca(int *x, int *y){
    int aux;
    aux= *x;
    *x= *y;
    *y = aux;
}