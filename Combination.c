/*Given a positive number n, find all combinations of 2×n elements 
such that every element from 1 to n appears exactly twice and 
the distance between its two appearances is exactly equal to the value of the element.*/


//y tuong bai a[i]=a[i+x]=x  vs  i=1,2,3,...
#include <stdio.h>

void Try(int a[],int x,int n){
    if(x>n){
        for(int i=1;i<=2*n;i++) printf("%d ",a[i]);
        printf("\n");
        return ;
    }
    for(int i=1;i<=2*n;i++){
        if(a[i]==0 && i+x+1<=2*n && a[i+x+1]==0){
            a[i]=x;
            a[i+x+1]=x;
            Try(a,x+1,n);
            a[i]=0;
            a[i+x+1]=0;
        }
    }
}



int main(){
    int a[100]={0};
    int n,x=1;
    printf("Nhap n: ");scanf("%d",&n);
    Try(a,x,n);
}