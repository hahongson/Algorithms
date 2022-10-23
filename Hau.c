#include <stdio.h>
#include <math.h>
int n, count;
int a[30]={0};

void Ghinhan(){
    printf("#%d\n",count++);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(a[j]==i) printf("1 ");
            else printf("0 ");
        }
        printf("\n");
    }
}

int UCV(int col,int row){
    for(int i=1;i<row;i++){
        if(col==a[i]||row-i==abs(col-a[i])) return 0;
    }
    return 1;
}

void Hau(int k){//rows
    for(int j=1;j<=n;j++){
        if(UCV(j,k)){
            a[k]=j;
            if(k==n) Ghinhan();
            else Hau(k+1);
        }
    }
}


int main(){
    printf("Nhap n: ");scanf("%d",&n);
    count=1;
    Hau(1);
}
