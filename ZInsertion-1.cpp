#include <iostream>
#define N 6
using namespace std;

int main()
{
    int i, j, A[N] = {35, 15, 8, 28, 47, 10};
    int aux;

    for (i=0; i<N; i++)
        for (int j=i+1; j>0; j--)
            if (A[j] < A[j-1])
            {
                aux= A[j];
                A[j] = A[j-1];
                A[j-1] = aux;
            }
            else 
                break;

for (int i=0; i<N; i++)
 cout << A[i] << endl;

return 0;
}