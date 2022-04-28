#include <iostream>
#define T 7

using namespace std;

int buscaBinariaRecursiva(int A[], int x, int inicio, int fim)
{
  int meio = (inicio + fim)/2;
  if (x== A[meio])
    return meio; 
    else if (meio == inicio || meio == fim){
      return -1;  
    } 
   else if (x< A[meio]){
      return buscaBinariaRecursiva(A, x, inicio, meio - 1);
    } else {
      return buscaBinariaRecursiva (A, x, meio + 1, fim);
    }
  }

int buscaBinariaIterativa(int inicio, int fim, int A[], int n){
  while (fim - inicio > 0){
    int meio = inicio + (fim - inicio)/2;

    if (A[meio] == n){
      return meio;
    } else if (A[meio] > n){
      fim= meio;
    } else if (A[meio] < n){
      inicio = meio + 1;
    }
  }

  if (A[fim] == n){
    return fim;
  }
  return -1;
} 


int main(){
  int referencial = -1;
  int num, A[T] = {9, 15, 25, 32, 44, 50, 90};
  for (int h=0; h<100; h++){
     cout << "Numero a ser procurado: ";
     cin>> num;
  
  //referencial = buscaBinariaRecursiva(A, num, 0, T);
  referencial = buscaBinariaIterativa(0, T-1, A, num);
  if (referencial < 0){
    cout << "Numero nao encontrado no array" << endl;
  } else {
    cout << "Numero esta na posicao: " << (referencial + 1) << endl;
  }
}
 
  
}