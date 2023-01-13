#include <iostream>
#include <cmath>
using namespace std;

void stat(const double[],int,double[]);

int main(){
    double A[] = {1.2,3.5,6.9,7.8,12.5,0.5};
    int N = sizeof(A)/sizeof(A[0]);
    double B[6];
    stat(A,N,B);
    cout << "Arithmetic Mean = " << B[0];
    cout << "\nStandard Deviation = " << B[1];
    cout << "\nGeometric Mean = " << B[2];
    cout << "\nHarmonic Mean = " << B[3];
    cout << "\nMax = " << B[4];
    cout << "\nMin = " << B[5];
    return 0;
}

void stat(const double A[],int N,double B[])
{
    for(int i=0;i<N;i++)
    {
        B[0]+=A[i];
        if(i==N-1)
            B[0]=B[0]/N;
    }
    for(int j=0;j<N;j++)
    {
        B[1]+=pow((A[j]-B[0]),2);
        if(j==N-1)
            B[1]=sqrt(B[1]/(N));
    }
    B[2]=1;
    for(int k=0;k<N;k++)
    {
        B[2]*=A[k];
        if(k==N-1)
        {
            B[2]=pow(B[2],(1.0/N));
        }
    }
    for(int l=0;l<N;l++)
    {
        B[3]+=1/A[l];
        if(l==N-1)
            B[3]=N/(B[3]);
    }
    for(int m=0;m<N;m++)
    {
        if(A[m]>B[4])
            B[4]=A[m];
        else B[4]=B[4];
    }
    B[5]=2;
    for(int n=0;n<N;n++)
    {
        if(A[n]<B[5])
            B[5]=A[n];
        else B[5]=B[5];
    }
}