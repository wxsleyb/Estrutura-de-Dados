#include <iostream>
using namespace std;
#define T 10

struct conteiner{
    int cod;
    struct conteiner *prox;
};

typedef struct conteiner * cPtr;
cPtr topo = NULL;

void colocar();
void retirar();
void lista();
bool patioVazio();


int main(){
    int op;
    int conteiner;
    int qtConteiner=0;
    do{
        cout << "\n-----------MENU---------------"
                "\n1.Colocar conteiner"
                "\n2.Retirar conteiner"
                "\n3.Listar conteineres do patio"
                "\n0.Sair"
                "\n------------------------------"
                "\n\nInforme a opcao: ";
        cin >> op;
        switch(op){
            case 1: {
                  if(qtConteiner<T){                    //condiçao que verifica se a quantidade excedeu o limite de 10 de conteineres para realizar a chamada da funçao de colocar conteiner
                      colocar();
                      qtConteiner++;
                  } else {
                      cout << "\nLimite maximo de " << T << " conteineres";
                  }
            break;
            }            
            case 2:{
                if(!patioVazio()){                    //condiçao que verifica se o patio esta vazio para realizar a chamada da funçao de retirada do conteiner, caso contrario retorna patio vazio
                    retirar();
                    qtConteiner--;
                } else {
                    cout << "\nO patio esta vazio!" << endl;
                }

              break;}
            case 3: {
            if(!patioVazio()){                      //condiçao que veriffica se o patio esta vazio para mostrar a ordem da pilha, caso contrario retorna patio vazio
                lista();
            } else{
                cout << "\nO patio esta vazio!" << endl;
            }

            break;}
                                     
        }
    }while(op!=0);                                //enquanto a opçao que o usuario escolher for diferente de zero, o loop do menu aparecer vai continuar aparecendo
}
 
void colocar(){                                   //funçao push que armazena um valor na struct
    cPtr c;
    int elemento;
    c= new conteiner;
    cout <<"\nDigite o valor do elemento" << endl;
    cin>> elemento;
    c->cod= elemento;
    c->prox= topo;
    topo=c;
    cout <<"\nConteiner armazenado!" << endl;

} 

void retirar(){                                   //funçao pop que retira um valor da struct   
    cPtr c= topo;

    topo = topo->prox;
    cout << "\n O conteiner " << c->cod << " foi retirado da pilha no patio" << endl;
    
}

bool patioVazio(){                            //funçao que verifica se a struct esta vazia ou nao
    if(topo){
        return false;
    } else {
        return true;
    }
}

void lista(){                                //funçao que mostra quais elementos foram armazenados caso nao esteja sem nenhum
    cPtr c = topo;
    cout << "\nCONTEINERES NO PATIO:"<< endl;
        while (c!= NULL){
            
            cout << c->cod << "\n";
            c = c->prox;
        } 
    
}

