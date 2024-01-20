#include<stdio.h>
int main()
{
    int arr[10],n,i,temp;
    printf("Enter the no. of elements");
    scanf("%d",&n);
    printf("Enter the array elements",i+1);
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    for(i=0;i<n;i=i+2){
        temp=arr[i];
        arr[i]=arr[i+1];
        arr[i+1]=temp;
    }
    printf("Elements after swapping is");
        for(i=0;i<n;i++){
            printf("%d",arr[i]);
        }
        return 0;

}
