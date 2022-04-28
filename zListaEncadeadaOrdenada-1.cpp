#include <iostream>

using namespace std;

/* Lista Encadeada já ordenada
 * Fornece duas opções: 1. Inserir em ordem crescente cada numero lido;
 * 2. Consultar um numero da lista.
 * 3. Listagem dos elementos da lista
*/

struct no {
	int info; 
	struct no *prox;
};

typedef struct no * noPtr;

noPtr topo = NULL;

// Funções Principais
void inserir(int);
void consultar(int);
void listar();
int menu();
bool listaVazia();
// void intercala();
void retirar();


main()
{
    int op;
	int item;
    int elmt=0;
    
    
	do
    {
    	op = menu();
       switch (op){
	   	 case 1:
                cout << "\nDigite um valor para ser adicionado: ";
                cin >> item;
                inserir(item); 
                break;
		 case 2: 
  				cout << "\nDigite o numero a ser procurado: ";
            	cin >> item;
            	consultar(item);
                break;
		 case 3: listar(); 
                 break;
         case 4:{
                if(!listaVazia()){                    //condiçao que verifica se o patio esta vazio para realizar a chamada da funçao de retirada do conteiner, caso contrario retorna patio vazio
                    retirar();
                    elmt--;
                } else {
                    cout << "\nO patio esta vazio!" << endl;
                break;}
         }
	}
    } while (op !=0);
}

int menu()
{
     int opcao;
     //system("cls");
	cout << "\n1: Inserir elemento na lista" 
	 	 <<"\n2: Consultar elemento da lista"			
	 	 <<"\n3: Listar elementos"
         <<"\n4: Retirar elemento da lista"
		 << "\n0: Sair"
	  	 << "\n\nDigite a opcao: ";
    cin >> opcao;
    return opcao;
}

void inserir(int valor)
{
     noPtr novo = new no, ant, aux;
     
     novo->info = valor;
     if (listaVazia())  //lista sem elementos
	 { 
		novo->prox = topo;
		topo = novo;
	 }  
	 else { 	//verificar posição para inserção 	
		aux = topo;
		while (aux != NULL && novo->info > aux->info)
		{
			ant = aux;
			aux = aux->prox;
		}
		if (aux == topo) //elemento é menor do que todos
		{	
			novo->prox = aux;  // ou p->prox = topo ;
			topo = novo;
		} else {
	 	/* elemento é maior do que todos ou está no meio
	      da lista  */
			novo->prox = aux;
			ant->prox = novo;
		}
     }
}

void retirar(){                                   //funçao pop que retira um valor da struct   
    noPtr p= topo;

    topo = topo->prox;
    cout << "\n O elemento " << p->info << " foi retirado da lista" << endl;
    
}

void consultar(int x)  
{
    noPtr p = topo; 
	bool achei = false;  
  
	if (!listaVazia())  { 
		while (p != NULL && achei == false)  {
		    if (p->info == x) {
			  cout << "\nElemento encontrado no endereco: " << p << endl;
		       achei = true;
		    }
            p = p->prox;
	      }
		if (!achei)	
			cout << "\nElemento nao encontrado\n" << endl;
	} else cout << "\nLista Vazia!\n" << endl;
}


bool listaVazia()
{
    if (topo)
       return false;
    else
        return true;
}

void listar()
{
     noPtr p = topo;
     if (listaVazia())
        cout << "\n\nA lista esta vazia!\n";
     else {
          cout << "\n\nElementos da Lista: \n";
          cout << "TOPO --> ";
          while (p != NULL) 
          {
                cout << p->info << " --> ";
                p = p->prox;
          }
          cout << "NULL\n\n";
     }
}