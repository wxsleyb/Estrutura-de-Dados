#include <iostream>
#define T 22
using namespace std;

void BuscaSequencial (int A[], int x)
{
	bool achei;
    int i = 0;
    
    for (int i=0; i<21; i++)
		{
			if(A[i]== x)
			{
				achei = true;
				cout << x << " " << "Esta na posicao: " << i+1 << " ";
			} else if(achei != true ){
                cout << "Nao esta no array" << endl;
            }
                
         }
				
			    
	
	
}

int main()
{
    int num, A[T] = {5, 17, 65, 18, 2, 43, 9, 67, 54, 44, 41, 1, 59, 81, 3, 94, 35, 19, 33, 46, 68};
    cout << "Informe o numero a ser procurado: ";
    cin>> num;
    BuscaSequencial(A, num);
    
    return 0;
    
}