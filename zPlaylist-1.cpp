#include <iostream>
#include <conio.h>
using namespace std;

int main(){
    struct musica{
        int info;
        musica *prox;
    };

    musica *inicio = NULL;
    musica *fim= NULL;
    musica *aux;
    musica *ant;
    int op, music, achou;

    do {
    cout <<"\n1: Incluir nova musica na Playlist" 
	     <<"\n2: Buscar musica na Playlist"			
	 	 <<"\n3: Remover musica da Playlist"
         <<"\n4: Mostrar todas as musicas da Playlist"
		 <<"\n6: Sair"
	  	 <<"\n\nDigite a opcao: ";
        cin >> op;
        if(op < 1 || op > 5){
            cout << "Opcao invalida!\n";
        }
        if (op == 1){
            cout << "Digite o numero a ser inserido no inicio da lista: ";
            musica *novo = new musica();
            cin >> novo->info;
            if (inicio == NULL){        // se a playlist estiver vazia
                inicio = novo;          // a primeira musica será o inicio e o fim da playlist
                fim = novo;
                fim->prox = inicio;
            }
            else {
                novo->prox = inicio;
                inicio = novo;
                fim->prox = inicio;
            }
            cout << "\nMusica inserida na Playlist!\n";
        }

        if (op==4){
            if (inicio==NULL){
                cout << "Lista Vazia";
            }
            else {
                cout << "\nListando todas as musicas da Playlist\n";
                aux = inicio;
                do {
                    cout << "musica: " << aux->info << "\n";
                    aux = aux->prox;
                }
                while (aux != inicio);
            }
          
        }

        if (op==3){
            
        }
        getch();
    }
   while (op!=5);
}




