#include<bits/stdc++.h>
using namespace std;

#define size 7

int A[size], B[size], C[size];

int cost(int i, int j, int k)
{
    return (max (  abs(A[i] - B[j]) , max(abs(B[j] - C[k]) , abs(A[i] - C[k])  ) ) );
}

int main()
{
    int a[] = {1, 2, 123 , 1253 ,124, 113 , 234};
    int b[] = {1264, 12 , 156, 614, 165, 74, 25};
    int c[] = {48, 36, 4643, 47, 241, 145, 1436};
    for(int i = 0; i < size; i++)
        A[i] = a[i];
    for(int i = 0; i < size; i++)
        B[i] = b[i];
    for(int i = 0; i < size; i++)
        C[i] = c[i];
    sort(A, A+size);sort(B, B+size);sort(C, C+size);
    int  i = 0, j = 0, k = 0;
    int _min = INT_MAX;
    while(i != size && j !=size && k!=size)
    {
        printf("%d\n", _min);
        while(A[i] < min(B[j], C[k]) && i < size)i++;
        i--;
        _min = min(_min, cost(i, j, k));
        i++;
        while(B[j] < min(A[i], C[k]) && j < size)j++;
        j--;
        _min = min(_min, cost(i, j, k) );
        j++;
        while(C[k] < min(A[i], B[j]) && k < size)k++;
        k--;
        _min = min(_min, cost(i, j, k) );
        k++;
    }

    //edge condition to be checked 
    //when one index reached size, we need to continue with other two indices

    printf("%d", _min);
    return  0;
}