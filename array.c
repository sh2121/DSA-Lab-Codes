#include<stdio.h>
int main()
{
    int n,i,j,arr[10];
    printf("Enter the no. of elements");
    scanf("%d",&n);
    printf("Enter the array elements");
    for(i=0;i<n;i++){
    scanf("%d",&arr[i]);
    }
    for(i=0;2*i+1<=n;i++)
    {
        arr[i]=2*i+1;
    }
    for(i=n-1,j=2;j<=n;i--){
        arr[i]=j;
        j=j+2;
    }
    printf("Output is");
    for(i=1;i<n;i++){
        printf(arr[i]);
    }

}