// binary search
#include <stdio.h>
int Bsearch(int A[], int start, int end, int element) 
{
   if(start>end)
   return -1;
      int mid = (start+end)/2;
   if( A[mid] == element )
   return mid;
   else 
        if( element < A[mid] )
            Bsearch(A, start, mid-1, element);
        else
            Bsearch(A, mid+1, end, element);
}
int main() {
    int a[50],n,b;
    printf("enter the size of the array\n");
    scanf("%d",&n);
    printf("enter the elements of the sorted arry\n");
    for (int i = 0; i < n; i++)
    scanf("%d",&a[i]);
    printf("enter element to be searched\n");
    scanf("%d",&b);   
    int p=Bsearch(a,0,n,b);
    if(p!=-1)
    printf("%d found at %d position",b,p+1);
    else
    printf("%d is not found",b);
}
