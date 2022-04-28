#include <iostream>
using namespace std;


typedef struct no{
    int valor;
    struct no *proximo;
}mPtr;


typedef struct{
    mPtr *inicio;
    mPtr *fim;
    int tam=0;
}noPtr;

int menu();
void criarlista(noPtr *lista);
void inserirInicio(noPtr *lista, int num);
void inserirFim(noPtr *lista, int num);
mPtr* remover(noPtr *lista, int num);
mPtr* buscar(noPtr *lista, int num);
void imprimir(noPtr lista);

int main(){

    int op, musica;
    noPtr lista;
    mPtr *p;

    criarlista(&lista);

    do{
        op= menu();

        switch(op){
        case 1:
            cout << "Digite a musica: ";
            cin >> musica;
            inserirInicio(&lista, musica);
            break;
        case 2:
            cout << "Digite a musica: ";
            cin >> musica;
            inserirFim(&lista, musica);
            break;
        case 4:
            cout << "Digite a musica a ser removida: ";
            cin >> musica;
            p = remover(&lista, musica);
            if(p){
                
                cout << "Musica " << p->valor << " removida ";
                delete(p);
            }
            else{
                cout << "A musica nao existe na Playlist!\n";
            }
            
            break;
        case 5:
            imprimir(lista);
            break;
        case 6:
            cout << "Digite a musica a ser buscada: ";
            cin >> musica;
            p = buscar(&lista, musica);
            if(p)
                cout << "musica " << p->valor << " encontrada na localizacao: " << p;
            else
                cout << "musica nao encontrada!\n";
            break;
        default:
            if(op != 0)
                cout <<"Opcao invalida!\n";
        }

    }while(op != 0);

    return 0;
}

int menu(){
    int op;
    cout << "\n-------MENU DE OPCOES-------"
         <<"\n0. Sair"
         <<"\n1. Inserir musica no inicio da Playlist"
         <<"\n2. inserir musica no final da Playlist"
         <<"\n4. Remover musica da Playlist"
         <<"\n5. Mostrar todas as musicas da Playlist"
         <<"\n6. Buscar musica na Playlist"
         <<"\n\nDigite a opcao: \n\n";
        cin>>op;
        return op;
}

void criarlista(noPtr *lista){
    lista->inicio = NULL;
    lista->fim = NULL;
    lista->tam = 0;
}

// procedimento para inserir no início
void inserirInicio(noPtr *lista, int num){
    mPtr *p = new no;

    if(p){
        p->valor = num;
        p->proximo = lista->inicio;
        lista->inicio = p;
        if(lista->fim == NULL)
            lista->fim = p;
        lista->fim->proximo = lista->inicio;
        lista->tam++;
        cout << "\n\nMusica inserida na Playlist!";
    }
    else
        cout << "Erro ao alocar memoria!\n";
}

// procedimento para inserir no fim
void inserirFim(noPtr *lista, int mus){
    mPtr *p = new no;

    if(p){
        p->valor = mus;

        // é o primeiro?
        if(lista->inicio == NULL){
            lista->inicio = p;
            lista->fim = p;
            lista->fim->proximo = lista->inicio;
            cout << "\n\nMusica inserida na Playlist!";
        }
        else{
            lista->fim->proximo = p;
            lista->fim = p;
            // as duas linhas a seguir são sinônimas. Escolha a que achar mais fácil compreender
            //lista->fim->proximo = lista->inicio;
            lista->fim->proximo = lista->inicio;
            
            cout << "\n\nMusica inserida na Playlist!";
        }
        lista->tam++;
    }
    else
        cout << "Erro ao alocar memoria!\n";
}


// função para remover um nó
mPtr* remover(noPtr *lista, int num){
    mPtr *aux, *remover = NULL;

    if(lista->inicio){
        if(lista->inicio == lista->fim && lista->inicio->valor == num){
            remover = lista->inicio;
            lista->inicio = NULL;
            lista->fim = NULL;
            lista->tam--;
        }
        else if(lista->inicio->valor == num){
            remover = lista->inicio;
            lista->inicio = remover->proximo;
            lista->fim->proximo = lista->inicio;
            lista->tam--;
        }
        else{
            aux = lista->inicio;
            while(aux->proximo != lista->inicio && aux->proximo->valor != num)
                aux = aux->proximo;
            if(aux->proximo->valor == num){
                if(lista->fim == aux->proximo){
                    remover = aux->proximo;
                    aux->proximo = remover->proximo;
                    lista->fim = aux;
                }
                else{
                    remover = aux->proximo;
                    aux->proximo = remover->proximo;
                }
                lista->tam--;
            }
        }
    }

    return remover;
    
}

// função para buscar um valor
mPtr* buscar(noPtr *lista, int music){
    mPtr *aux = lista->inicio;

    if(aux){
        do{
            if(aux->valor == music)
                return aux;
            aux = aux->proximo;
        }while(aux != lista->inicio);
    }
    return NULL;
}

// procedimento para imprimir a lista circular

void imprimir(noPtr lista){
    mPtr *no = lista.inicio;
    cout <<"\nTamanho da Playlist: " << lista.tam << " musica(s)";
    if(no){
        do{
            cout <<"\nMusica: " << no->valor;
            no = no->proximo;
        }while(no != lista.inicio);
        cout <<"\nInicio: " << no->valor;
    }
}


//O inserir no meio é parecido com o inserir ordenado. Tomou ele como base?