#include <iostream> //include <stdio.h>
#include <math.h>
#define n 7
using namespace std;

int main()
{
 int i, j, aux, A[n] = {10, 99, 33, 22, 569, 139, 3};
 int menor;

 for (i=0; i< n-1; i++)
{
     menor =i;
    for (j=i + 1; j < n; j++)
    {
        if (A[menor] > A[j])

        menor = j;
    }
       aux= A[i];
       A[i]= A[menor];
       A[menor]= aux;
}
for(i=0; i<n; i++)
cout << A[i] << " ";
    
}