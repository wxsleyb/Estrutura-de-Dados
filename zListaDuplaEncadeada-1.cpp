#include <iostream>
using namespace std;

struct no{
    int info;
    struct no *ant;
    struct no *prox;
};

typedef struct no *noPtr;
//noPtr topo = NULL;
int menu();
void inserir(noPtr *);
void retirar(noPtr *);
void listar(noPtr);
bool listaVazia(noPtr);


int main(){
    noPtr topo= NULL;
    int op;

    do{
        op=menu();
        //cin>>op;
        switch(op){
            case 1: inserir(&topo);break;
            case 2: retirar(&topo);break;
            case 3: listar(topo);break;
        }
    } while (op!=0);
}

int menu()
{
     int opcao;
     //system("cls");
	cout << "\n1: Inserir elemento na lista" 
	 	 <<"\n2: Excluir elemento da lista"			
	 	 <<"\n3: Listar elementos"
		 << "\n0: Sair"
	  	 << "\n\nDigite a opcao: ";
    cin >> opcao;
    return opcao;
}

void inserir(noPtr *i){  // *i é desreferenciar, não quer pegar o conteudo do i, 
                         //quer pegar o conteudo de onde o i aponta (ponteiro *), que é o conteudo de topo
    noPtr p = new no;

    cout <<"\nDigite o valor do elemento\n";
    cin>> p->info;

    p->ant = NULL;

    if (listaVazia(*i)){ // *i é desreferenciar, não quer pegar o conteudo do i,
        p->prox= NULL;   //quer pegar o conteudo de onde o i aponta (ponteiro *), que é o conteudo de topo     
    }else {
        p->prox = *i;     //conteudo da variavel topo
        (*i)->ant =p;
    }
    *i=p;
       
}                    


void retirar(noPtr *i){
    noPtr p = *i;
    if(!listaVazia(*i)){
        if(p->prox==NULL){
            *i=NULL;
        }else {
            *i = p->prox;
            (*i)->ant = NULL;
        }
        delete(p);
        cout << "\nO elemento foi retirado da lista!\n";
    } else {
        cout << "\n\nLista esta vazia!\n";
    }
}
bool listaVazia(noPtr topo){
    if (topo)
       return false;
    else
        return true;
}

void listar(noPtr p){
    if(!listaVazia(p)){
        cout << "\nElementos da lista: \n";
        cout << "INICIO";
        while(p!=NULL){
            cout << "-->" << p->info;
            p=p->prox;
        }
        cout << "--> NULL";
    }
    else{
        cout <<"\n\nLista esta vazia!\n";
    }
}


