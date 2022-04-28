#include <iostream>
#define N 20;
using namespace std;

void ordenacao();
int verificacao(int A[], int x, int inicio, int fim);
void listar(int A[]);
void intercala();
int verificacao(int A[], int x, int inicio, int fim)                    //funçao de busca binaria
{
  int meio = (inicio + fim)/2;
  if (x== A[meio])
    return meio; 
    else if (meio == inicio && meio == fim){
      return -1;  
    } 
   else if (x< A[meio]){
      return verificacao(A, x, inicio, meio - 1);
    } else {
      return verificacao(A, x, meio + 1, fim);
    }
}

void intercala(int A[], int inicio, int fim, int meio){             //funçao que auxilia a busca binaria na troca de posiçoes no vetor
    int i, aux[20], posLivre = inicio, inicioA1 = inicio, inicioA2= meio + 1;

    while(inicioA1 <= meio && inicioA2 <= fim){
        if(A[inicioA1] < A[inicioA2]){
            aux[posLivre] = A[inicioA2];
            inicioA2++;
        } else {
            aux[posLivre] = A[inicioA1];
            inicioA1++;
        }
        posLivre++;
    }

 for (i=inicioA1; i<=meio; i++){
    aux[posLivre]= A[i];
    posLivre++;
 }

 for(i=inicioA2; i<=fim; i++){
    aux[posLivre] = A[i];
    posLivre++;
 }

 for(i=inicio; i<= fim; i++){
    A[i] = aux[i];
 }

}

void ordenacao(int A[], int inicio, int fim){                     //funçao MergeSort para ordenar o vetor
    int meio;
    if(inicio<fim){
        meio= (inicio + fim)/2;
        ordenacao(A, inicio, meio);
        ordenacao(A, meio + 1, fim);
        intercala(A, inicio, fim, meio);
    }
    
}

int main(){
    int op;
    int inicio=0;
    int fim=19;
    int i;
    int x;
    int A[] = {44, 77, 33, 3, 31, 23, 18, 16, 55, 11, 10, 4, 26, 5, 99, 7, 20, 63, 8, 6};
    int indice = -1;


    do{
        cout <<  
                 "\n-------------------MENU----------------------"
                 "\n1.Ordenacao dos elementos da lista"         
                 "\n2.Verificar existencia do elemento na lista" 
                 "\n3.Listar elementos da lista"                 
                 "\n0.Sair"
                 "\n---------------------------------------------"                                      
                 "\n\nInforme a opcao: ";                                                
                
        cin>>op;
        switch(op){
            case 1: {
                if(inicio<fim){                         
                ordenacao(A, 0, 19);
                cout << "\nA lista foi ordenada!" << endl; 
                }break;            
            }
            case 2: 
            cout << "\nDigite o numero a ser procurado o indice (apenas com a lista ordenada)" << endl;
            cin>>x;
            indice = verificacao(A, x, 0, 19);                                                     //igualando um int com a funcao verifiçao, faz ela retornar um valor pra esse int e conseguir fazer o if com mais facilidade
            if (indice < 0){
                cout << "\nNumero nao encontrado ou a lista nao esta ordenada" << endl;            // a busca binaria so funciona com o vetor ordenado
            } else{
                cout << "\nO "<< x << " esta na posicao " << (indice) << " da lista ordenada"<< endl;            //indice começando do zero
            }

            ; break;
            case 3: listar(A); break;       
         }
     }while (op != 0);
}


void listar(int A[]){                    //funçao que mostra o vetor, estando ordenado ou nao
    
    for(int i=0; i<20; i++){
    
        cout << A[i] << "\t";
    }
}



