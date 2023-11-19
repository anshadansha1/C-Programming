#include<stdio.h>
#define MAX 5
int a[MAX];

void insert(int n){
    int i;
    printf("\nEnter %d elements to insert : ",n);
    for(i=0;i<n;i++){        
        scanf("%d",&a[i]);
    }
}
void disp(int n){
    int i;
    printf("\nDisplaying entered elements : ");
    for(i=0;i<n;i++){
        printf("\t%d",a[i]);
    }

}
void linear_search(int n){
    int i,data,found=0;
    printf("\nEnter the data to be searched : ");
    scanf("%d",&data);
    for(i=0;i<n;i++){
        if(a[i]==data){
            printf("\nElement found at index %d ",i);
            found=1;
            break;
        }
    }
    if(!found){
        printf("\nElement Not found! ");
    }
    
}

int binary_search(int n){
    int l=0,r=n-1,mid,data;
    printf("\nEnter the data to be searched : ");
    scanf("%d",&data);
    mid=(l+r)/2;
    while(l<r){
        if(data==a[mid])
            printf("\nElement found at %d ",mid);
        else if(data<a[mid]){
            r=mid-1;
        }
        else{
            l=mid+1;
        }
        return -1;
    }
}

int main(){
    int n;
    printf("\nEnter how much element to insert : " );
    scanf("%d",&n);
    insert(n);
    disp(n);
    linear_search(n);
    binary_search(n);
    return 0;
}