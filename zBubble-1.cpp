#include <iostream> //include <stdio.h>
#include <math.h>
#define n 7



using namespace std;



main()
{
string A[n] = {"Wesley", "Grasiele", "Gisele", "Eva", "Marlene", "Trindade", "Thalya"};
string aux;
int i, j; //A[n] = {10, 99, 33, 22, 569, 139, 3};//{"Wesley", "Grasiele", "Gisele", "Eva", "Marlene", "Trindade", "Thalya"};

for (i = 0; i < n-1; i++)
for (j = i +1; j < n; j++)
if (A[i] > A[j])
{
aux = A[i];
A[i] = A[j];
A[j] = aux;
}



for (i = 0; i < n; i++)
cout << A[i] << endl;; //printf("%d", A[i]);
}