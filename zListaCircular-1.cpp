#include <iostream>
using namespace std;

typedef struct no{
    int music;
    struct no *prox;
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
mPtr* removeMusica(noPtr *lista, int num);
mPtr* buscaMusica(noPtr *lista, int num);
void mostraMusicas(noPtr lista);

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
        case 3:
            cout << "Digite a musica a ser removida: ";
            cin >> musica;
            p = removeMusica(&lista, musica);
            if(p){
                
                cout << "Musica " << p->music << " removida ";
                delete(p);
            }
            else{
                cout << "A musica nao existe na Playlist ou a Playlist esta vazia!\n";
            }
            
            break;
        case 4:
            mostraMusicas(lista);
            break;
        case 5:
            cout << "Digite a musica a ser buscada: ";
            cin >> musica;
            p = buscaMusica(&lista, musica);
            if(p)
                cout << "musica " << p->music << " encontrada na localizacao: " << p;
            else
                cout << "musica nao encontrada!\n";
            break;

            default:
            if(op < 0 || op > 5){
                cout <<"Opcao invalida!\n";
            }
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
         <<"\n3. Remover musica da Playlist"
         <<"\n4. Mostrar todas as musicas da Playlist"
         <<"\n5. Buscar musica na Playlist"
         <<"\n\nDigite a opcao: \n\n";
        cin>>op;
        return op;
}

void criarlista(noPtr *lista){
    lista->inicio = NULL;
    lista->fim = NULL;
    lista->tam = 0;
}

void inserirInicio(noPtr *lista, int cod){
    mPtr *p = new no;

    if(p){
        p->music = cod;
        p->prox = lista->inicio;
        lista->inicio = p;
        if(lista->fim == NULL)
            lista->fim = p;
        lista->fim->prox = lista->inicio;
        lista->tam++;
        cout << "\n\nMusica inserida na Playlist!\n";
    }
    else
        cout << "Nao foi possivel inserir na Playlist!\n";
}

void inserirFim(noPtr *lista, int cod){
    mPtr *p = new no;

    if(p){
        p->music = cod;

    
        if(lista->inicio == NULL){
            lista->inicio = p;
            lista->fim = p;
            lista->fim->prox = lista->inicio;
            cout << "\n\nMusica inserida na Playlist!\n";
        }
        else{
            lista->fim->prox = p;
            lista->fim = p;
            lista->fim->prox = lista->inicio;
            
            cout << "\n\nMusica inserida na Playlist!\n";
        }
        lista->tam++;
    }
    else
        cout << "Erro ao alocar memoria!\n";
}

mPtr* removeMusica(noPtr *lista, int cod){
    mPtr *aux, *remover = NULL;

    if(lista->inicio){
        if(lista->inicio == lista->fim && lista->inicio->music == cod){
            remover = lista->inicio;
            lista->inicio = NULL;
            lista->fim = NULL;
            lista->tam--;
        }
        else if(lista->inicio->music == cod){
            remover = lista->inicio;
            lista->inicio = remover->prox;
            lista->fim->prox = lista->inicio;
            lista->tam--;
        }
        else{
            aux = lista->inicio;
            while(aux->prox != lista->inicio && aux->prox->music != cod)
                aux = aux->prox;
            if(aux->prox->music == cod){
                if(lista->fim == aux->prox){
                    remover = aux->prox;
                    aux->prox = remover->prox;
                    lista->fim = aux;
                }
                else{
                    remover = aux->prox;
                    aux->prox= remover->prox;
                }
                lista->tam--;
            }
        }
    }

    return remover;
    
}

mPtr* buscaMusica(noPtr *lista, int music){
    mPtr *aux = lista->inicio;

    if(aux){
        do{
            if(aux->music == music)
                return aux;
            aux = aux->prox;
        }while(aux != lista->inicio);
    }
    return NULL;
}

void mostraMusicas(noPtr lista){
    mPtr *no = lista.inicio;
    cout <<"\nTamanho da Playlist: " << lista.tam << " musica(s)\n";
    cout <<"--------PLAYLIST DE MUSICAS--------";
    if(no){
        do{
            
            cout <<"\nMusica: " << no->music;
            no = no->prox;
        }while(no != lista.inicio);
        cout <<"\nPrimeira Musica: " << no->music;
    }
}


