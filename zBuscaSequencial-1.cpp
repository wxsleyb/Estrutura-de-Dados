#include <iostream>
#define T 22
using namespace std;
//BUSCA SEQUENCIAL
void buscaSequencial(int A[], int x)
{
	int n=0;
	int aux[n];
	int p=0;
	int i=0;
	for  (i=0; i<T-1; i++)
		{
			if (A[i]== x)
			{
				aux[p] = i;
				p= p+1;
			}
		}
	if (p > 0)
	{
		for (i=0; i<=p-1; i++)
			{
				cout << x << " " << "esta na posicao " << aux[i] << " do vetor" << endl;
			} 
	}else {
		cout << "Nao foi encontrado" << endl;
	}
}

int main()
{
	int A[] = {5, 17, 65, 18, 2, 43, 9, 67, 54, 44, 41, 1, 59, 81, 3, 94, 35, 19, 33, 46, 68};
	int num;


	cout << "Digite o numero a ser procurado" << endl;
	cin >> num;

	buscaSequencial(A, num);
}
	