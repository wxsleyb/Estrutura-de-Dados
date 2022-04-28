#include <iostream>
using namespace std;

struct no{
    int info;
    struct no * prox;
};

typedef struct no * noPtr;
noPtr topo = NULL;

void push();
void pop();
void printList();
bool listaVazia();

int main(){
    int op;
    int valor;
    do{
        cout << "\n1.Empilhar"
                "\n2.Desempilhar"
                "\n3.Listar elementos da pilha"
                "\n0.Sair"
                "\n\nInforme a opcao: ";
        cin >> op;
        switch(op){
            case 1: push(); break;
            case 2: pop(); break;
            case 3: printList(); break;
        }
    } while (op!= 0);
}

void push(){
    noPtr p;
    int valor;
    p= new no;
    cout << "Digite o valor do elemento" << endl;
    cin >> valor;           //cin>> p->info;
    p->info = valor;        //
    p->prox = topo;
    topo= p;
}

void pop(){

    noPtr p =topo;
    if(!listaVazia()){
        topo = topo->prox;
        cout << "\n O espaco de alocacao " << topo << " foi retirado da pilha" << endl;
        delete(p);
    } else {
        cout << "\nLista Vazia!" << endl;
    }
}

bool listaVazia(){
    if(topo){
        return false;
    } else{
        return true;
    }
}

void printList(){
    noPtr p = topo;

    if(!listaVazia()){
        while (p!= NULL){
        
            cout << p->info << "\t";
            p= p->prox;
        }
    }else{
        cout << "\nLista vazia!" << endl;
    }
}