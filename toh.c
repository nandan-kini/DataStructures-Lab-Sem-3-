//toh

#include<stdio.h>

int toh(int,char,char,char);

void main(){
    int num;
    printf("Enter the number of disks\n");
    scanf("%d",&num);
    toh(num,'a','c','b');
}

int toh(int n,char source,char dest,char temp){
    if(n>=1){
        toh(n-1,source,temp,dest);
        printf("disk moved from %c to %c\n",source,dest);
        toh(n-1,temp,dest,source);
    }

}