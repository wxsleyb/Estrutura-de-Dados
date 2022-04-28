#include <iostream>

using namespace std;

struct no {
    int info;
    struct no * esq, *dir;
};

typedef struct no *noPtr;

int menu();
int listarNos();
void inserir(noPtr *, int);
void remover(noPtr *, int);
noPtr buscar (noPtr, int);
noPtr maior(noPtr *);
void listarEmOrdem(noPtr);
void listarPreOrdem(noPtr);
void listarPosOrdem(noPtr);
bool enderecoVazio(noPtr);
noPtr somx(noPtr *);
//int folhas2(noPtr);
//int soma(noPtr *);

int main(){
    int op1, op2, x;
    bool achei;
    noPtr raiz= NULL;

    do{
        op1=menu();
        switch(op1){
            case 1: cout << " Elemento a inserir: ";
                    cin >> x;
                    inserir(&raiz,x);
                    break;
            case 2: cout << " Elemento para remover: ";
                    cin >> x;
                    remover(&raiz,x);
                   break;
            case 3: op2= listarNos();
                    if (op2==1) listarEmOrdem(raiz);
                    if (op2==2) listarPreOrdem(raiz);
                    if (op2==3) listarPosOrdem(raiz);
                    break;
            case 4: if(!enderecoVazio(raiz)){
                cout << "\nElemento para buscar: ";
                cin>> x;
                noPtr p= buscar(raiz,x);
                if(!p){
                    cout << "\nElemento nao encontrado";
                    }else{
                        cout << "\nO elemento: "  << x << " foi encontrado no endereco: " << p << "\n";          
                }
            }
            else {
                cout << "\nArvore Vazia";
            }

            case 5: cout << "O somatorio dos elementos de Grau 2 eh:"  << somx(&raiz) << endl;;
                
         };
     } while (op1!=0);
}

int menu(){
    int opcao;
    cout << "\n\n\n------Menu Principal------\n\n"
         << "\n1.Inserir no na arvore"
         << "\n2.Remover no na arvore"
         << "\n3.Listar todos os nos da arvore"
         << "\n4.Buscar no"
         << "\n5.Somatorio dos elementos de Grau 2"
         << "\n0.Sair"
         << "\nDigite uma opcao: ";
    
    cin >> opcao;
    return opcao;        
}

int listarNos(){
    int opcao;
    cout << "\n\nTipos de listagem: "
         << "\n1.Em Ordem"
         << "\n2.Pre Ordem"
         << "\n3.Pos Ordem"
         << "\n\nEscolha o tipo de listagem: ";
    cin >> opcao;
    return opcao;
}

void inserir(noPtr *p, int x){
    if(enderecoVazio(*p)){
        *p=new no;
        (*p)->info= x;
        (*p)->esq= NULL;
        (*p)->dir= NULL;
    } else {
        if(x<((*p)->info)){
            inserir(&((*p)->esq), x);
        } else {
            inserir(&((*p)->dir), x);
        }
    }
}

void remover(noPtr *p, int x){
    noPtr aux;
    if(!enderecoVazio(*p)){
        if(x== ((*p)->info)){
            aux = *p;
            if(((*p)->esq)==NULL){
                *p= (*p)->dir;
            } else if(((*p)->dir) == NULL){
                    *p= (*p)->esq;
                } else {
                    aux=maior(&((*p)->esq));
                    (*p)->info = aux->info;
                }
                delete(aux);
                cout<< "\nO elemento foi removido \n";
                
            }
            else if((x<((*p)->info))){
                    remover(&((*p)->esq),x);
                } else {
                    remover(&((*p)->dir),x);
                }
        }
}

noPtr buscar(noPtr p, int x){
   if(p==NULL){
       return NULL;
   } if (x==(p->info)){
       return p;
   } if (x<(p->info)){
       return buscar((p->esq),x);
   } else {
       return buscar((p->dir), x);
   }
}

void listarEmOrdem(noPtr p){
    if(!enderecoVazio(p)){
        listarEmOrdem(p->esq);
        cout << "\t" << p->info;
        listarEmOrdem(p->dir);
    }
}

void listarPosOrdem(noPtr p){
    if(!enderecoVazio(p)){
        listarPosOrdem(p->esq);
        listarPosOrdem(p->dir);
        cout << "\t" << p->info;
    }
}

void listarPreOrdem(noPtr p){
    if(!enderecoVazio(p)){
        cout << "\t" << p->info;
        listarPreOrdem(p->esq);
        listarPreOrdem(p->dir);        
    }
}

noPtr maior(noPtr *p){
    noPtr t;
    t=*p;
    if((t->dir) == NULL){
        *p = (*p)->esq;
        return(t);
    } else {
        return (maior(&((*p)->dir)));
    }
}

bool enderecoVazio(noPtr p){
    if (p){
        return false;
    } else {
        return true;
    }
}

noPtr soma(noPtr *p){
     noPtr aux;
     aux = *p;
     if (((*p)->esq)!=NULL){
         if((*p)->dir!=NULL){
         *p = (*p)->esq;
         aux+= (*p)->info;
         }
     } else if (((*p)->dir)!=NULL){
         if((*p)->esq!=NULL)
          *p = (*p)->dir;
           aux+= (*p)->info;
     }     
     return aux;
}

//int somx(noPtr *raiz) {
//	int soma;
//	if((*raiz) == NULL) {
//		return 0;
//	}
//
//	if(((*raiz)->esq != NULL) && ((*raiz)->dir != NULL)) {
//		return soma += (*raiz)->info;
//	}
	
//	return buscar((*raiz)->esq) + buscar((*raiz)->dir);
//}