#include <iostream>
#include <conio.h>

using namespace std;
int clrscr();

struct ARVORE{
    int num, altd, alte;
    ARVORE *dir, *esq;
};

ARVORE* rotacao_esquerda(ARVORE* aux)
{
    ARVORE *aux1, *aux2;
    aux1= aux->dir;
    aux2= aux->esq;
    aux->dir=aux2;
    aux1->esq=aux;

    if (aux->dir ==NULL){
        aux->altd = 0;
    } else if (aux->dir->alte > aux->dir->altd){
        aux->altd = aux->dir->alte+1;
    } else {
        aux->altd = aux->dir->altd+1;
    }

    if (aux1->esq->alte > aux1->esq->altd){
        aux1->alte = aux1->esq->alte+1;
    } else {
        aux1->alte =  aux1->esq->altd+1;
    }
    return aux1;
}


ARVORE* rotacao_direita(ARVORE* aux)
{
    ARVORE *aux1, *aux2;
    aux1= aux->esq;
    aux2= aux->dir;
    aux->esq=aux2;
    aux1->dir=aux;

    if (aux->esq ==NULL){
        aux->alte = 0;
    } else if (aux->esq->alte > aux->esq->altd){
        aux->alte = aux->esq->alte+1;
    } else {
        aux->alte = aux->esq->altd+1;
    }

    if (aux1->dir->alte > aux1->dir->altd){
        aux1->altd = aux1->dir->alte+1;
    } else {
        aux1->altd =  aux1->dir->altd+1;
    }
    return aux1;
}

ARVORE* balanceamento(ARVORE *aux){
    int fb, df;
    df =  aux->altd - aux->alte;
    if(fb==2){
        df= aux->dir->altd - aux->dir->alte;
        if (df >= 0){
            aux = rotacao_esquerda(aux);
        } else {
            aux->dir = rotacao_direita(aux->dir);
            aux = rotacao_esquerda(aux);
        }
    }
    else if (fb == -2){
        df = aux->esq->altd - aux->esq->alte;

        if (df<=0){
            aux = rotacao_direita(aux);
        } else {
            aux->esq = rotacao_esquerda (aux->esq);
            aux= rotacao_direita(aux);
        }
    }
    return aux;
}

ARVORE* inserir(ARVORE *aux, int num){
    ARVORE *novo;
    if(aux == NULL){
        novo = new ARVORE();
        novo->num = num;
        novo->altd = 0;
        novo->alte = 0;
        novo->esq = NULL;
        novo->dir = NULL;
        aux = novo;
    } else if (num < aux->num){
        aux->esq = inserir (aux->esq, num);
        if (aux->esq->altd > aux->esq->alte){
            aux->alte = aux->esq->altd+1;
        } else {
            aux->alte = aux->esq->alte+1;
            aux = balanceamento(aux);
        }
    } else {
        aux->dir = inserir(aux->dir, num);
        if (aux->dir->altd > aux->dir->alte){
            aux->altd = aux->dir->altd+1;
        } else {
            aux->altd = aux->dir->alte+1;
            aux= balanceamento(aux);
        }
    }
    return aux;
}

int consultar(ARVORE* aux, int num, int achou){
    if (aux!=NULL && achou ==0){
        if (aux->num == num){
            achou=1;
        } else if (num < aux->num){
            achou = consultar(aux->esq, num, achou);
        } else {
            achou = consultar(aux->dir, num, achou);
        }
    }
    return achou;
}

void MostrarEmOrdem (ARVORE* aux){
    if (aux != NULL){
        MostrarEmOrdem(aux->esq);
        cout << aux->num << " ";
        MostrarEmOrdem(aux->dir);
    }
}

void MostrarPreOrdem (ARVORE* aux){
    if (aux != NULL){
        cout << aux->num << " ";
        MostrarPreOrdem(aux->esq);
        MostrarPreOrdem(aux->dir);
    }
}

void MostrarPosOrdem (ARVORE* aux){
    if (aux != NULL){
        MostrarPosOrdem(aux->esq);
        MostrarPosOrdem(aux->dir);
        cout << aux->num << " ";
    }
}

ARVORE* remover(ARVORE* aux, int num){
    ARVORE *p, *p2;
    if (aux->num == num){
        if (aux->esq == aux->dir){
            delete aux;
            return NULL;
        } else if (aux->esq== NULL){
            // o elemento a ser removido nao tem filho para a esquerda
            p= aux->dir;
            delete aux;
            return p;
        } else if (aux->dir == NULL){
            //o elemento a ser removido nao tem filho para a direita
            p= aux->esq;
            delete aux;
            return p;
        } else {
            // o elemento a ser removido tem filho para ambos os lados
            p2 = aux->dir;
            p= aux->dir;
            while(p->esq !=NULL){
                p=p->esq;
            }
            p->esq = aux->esq;
            delete aux;
            return p2;
        }
    }
    else if (aux->num < num){
        aux->dir = remover(aux->dir, num);
    } else {
        aux->esq = remover(aux->esq, num);
    }
    return aux;
}

ARVORE* atualiza(ARVORE *aux){
    if(aux!=NULL){
        aux->esq = atualiza(aux->esq);
        if(aux->esq == NULL){
            aux->alte = 0;
        } else if (aux->esq->alte > aux->esq->altd){
            aux->alte = aux->esq->alte +1;
        } else {
            aux->alte = aux->esq->altd+1;
        }
        aux->dir=atualiza(aux->dir);
        if(aux->dir = NULL){
            aux->altd = 0;
        } else if(aux->dir->alte > aux->dir->altd){
            aux->altd = aux->dir->alte+1;
        } else{
            aux->altd = aux->dir->altd+1;
            aux = balanceamento(aux);
        }
    }
    return aux;
}

ARVORE* desalocar(ARVORE* aux){
    if(aux!= NULL){
        aux->esq = desalocar(aux->esq);
        aux->dir = desalocar(aux->dir);
        delete aux;
    }
    return NULL;
}

int main(){
    ARVORE *raiz = NULL;
    ARVORE *aux;
    int op, achou, numero;

    do{
        int clrscr();
        cout << "\nMENU DE OPCOES\n";
        cout << "\n1. Inserir na arvore";
        cout << "\n2. Consultar um no da arvore";
        cout << "\n3. Consultar toda a arvore em ordem";
        cout << "\n4. Consultar toda a arvore em  pre-ordem";
        cout << "\n5. Consultar toda a arvore em  pos-ordem";
        cout << "\n6. Excluir um no da arvore";
        cout << "\n7. Esvaziar a arvore";
        cout << "\n8. Sair";
        cout << "\nDigite sua opcao: ";
        cin>>op;
        if (op< 1 || op > 8){
        cout << "\nOpcao invalida!";
        } else if (op==1){
            cout << "\nDigite o numero a ser inserido: ";
            cin>>numero;
            raiz = inserir(raiz,numero);
            cout << "\nNumero inserido na arvore!";
        }
        else if(op==2){
            if(raiz==NULL){
                // arvore vazia
                cout << "\nArvore esta vazia";
            }
            else{
                // arvore contem elementos
                cout << "\nDigite o numero a ser consultado: ";
                cin>>numero;
                achou=0;
                achou= consultar(raiz,numero,achou);
                if(achou==0){
                    cout << "\nNumero nao encontrado na arvore";
                } else {
                    cout << "\nNumero encontrado na arvore";
                }
            }
         
        }
        else if(op==3){
            if(raiz==NULL){
                // arvore vazia
                cout << "\nArvore esta vazia";
            } else {
                // a arvore contem elementos
                cout << "\nListando todos os elementos da arvore em ordem: ";
                MostrarEmOrdem(raiz);
            }
        }
        else if(op==4){
            if(raiz==NULL){
                // arvore vazia
                cout << "\nArvore esta vazia";
            } else {
                // a arvore contem elementos
                cout << "\nListando todos os elementos da arvore em pre-ordem: ";
                MostrarPreOrdem(raiz);
            }
        }
        else if(op==5){
            if(raiz==NULL){
                // arvore vazia
                cout << "\nArvore esta vazia";
            } else {
                // a arvore contem elementos
                cout << "\nListando todos os elementos da arvore em pos-ordem: ";
                aux=raiz;
                MostrarPosOrdem(raiz);
            }
        }
        else if(op==6){
            if(raiz==NULL){
                cout << "\nArvore esta vazia";
            } else{
                cout << "\nDigite o numero que deseja excluir: ";
                cin>> numero;
                achou=0;
                achou = consultar(raiz,numero,achou);
                if(achou==0){
                    cout << "\nNumero nao encontrado na arvore";
                } else {
                    raiz= remover(raiz,numero);
                    raiz = atualiza(raiz);
                    cout << "\nNumero excluido da arvore!";
                }
            }
        }
        else if(op==7){
            if(raiz= NULL){
                cout << "\nArvore vazia!";
            } else {
                raiz=desalocar(raiz);
                cout <<"\nArvore esvaziada!";
            }
        }
        getch();    

    } while (op != 8);
    // desalocando a arvore
    raiz = desalocar(raiz);
}
