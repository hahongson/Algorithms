#include <stdio.h>
//chuyen cac dia tu A sang B thong qua C la chung gian , 
//b1 chuyen n-1 dia dau tu A sang C thong qua B;
//b2 chuyen dia to nhat sang B;
//b3 chuyen n-1 tu C sang B thong qua A;


int thutu=1;
void Thaphanoi(int n,char A,char B,char C){
    if(n==1){
        printf("#%d Move %c to %c \n",thutu++,A,B);
    }
    else{
        Thaphanoi(n-1,A,C,B);
        Thaphanoi(1,A,B,C);
        Thaphanoi(n-1,C,B,A);
    }
}

int main(){
    int n;
    printf("Nhap n: "); scanf("%d",&n);
    Thaphanoi(n,'A','B','C');
}