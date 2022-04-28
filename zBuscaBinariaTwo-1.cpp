#include <iostream>

using namespace std;

int buscaBinariaRecursiva(int A[], int x, int procurado)
{
    int inicio=0;
    int tam_x = x-1;
    int posicao=0;

    while(inicio<= tam_x)
    {
        posicao= (inicio+ tam_x)/2;
        if (A[posicao] == procurado)
        {
            return posicao;
        } else {

            if (A[posicao] > procurado){
                tam_x = posicao - 1;
            } else {
                inicio= posicao+1;
            }
        }
    }
    return -1;

}


int main()
{
  int num, A[16] = {1, 3, 4, 5, 11, 14, 23, 25, 33, 44, 48, 50, 54, 55, 95, 99};
  int op;


  
  cout << "Numero a ser procurado" << endl;
  cin>> num;
  int indice = buscaBinariaRecursiva(A, num, 16);

  if (indice =! -1)
  {
      cout << "Achou na posicao: " << indice << endl;
  } else {
      cout << "Nao achou no vetor" << endl;
  }

  //buscaBinariaIterativa(A, num, 16);
  
  
  return 0;

}