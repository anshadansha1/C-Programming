#include <stdio.h>

void heaptree(int a[],int n,int e){ //n:position of element , e:element
    int i,t;
    i=n;
    a[i]=e; //inserting element to array.
    while(i!=0) //case :after root node.
    {
        if(a[i] < a[(i-1)/2]) //if the value inserted is less than value of the Parent node.
        {
            break;//Nothing to do,because inserted element is smallest one.
        }
        else
        {
            //Otherwise you have interchange/swap values of Parent and Currently inserted node.
            t = a[i];
            a[i] = a[(i-1)/2];
            a[(i-1)/2] = t;
        }
        i=(i-1)/2; //After swapping Reduce the value of i
    }
}
void disparr(int a[],int n){
    int i;
    for(i=0;i<=n;i++){
        printf("\t%d",a[i]);
    }
}
void heapsort(int a[],int n){
    int i,j,t,lc,rc; //lc:left child , rc:right child, t: temporary variable
    j = n;//now j have last element's index = 4.

    //We have interchange/swap the value of 0th element and the last element.
    while(j > 0)//This loop is to ensure that the first element is swapped to last element.
    {
        i=0;
        //swappig:
        t=a[i];
        a[i]=a[j];
        a[j]=t;
        j--;

        //Now we have ensure that the element swapped to the root node is the greatest.
        while(i < j) //This loop is for the fixing(heapifying)
        {
            lc =(2*i)+1;
            rc =(2*i)+2;
            if(lc <= j && rc <= j)//case 1 :when there is two children
            {
                if((a[i] > a[lc]) && (a[i] > a[rc]))//if value of root node > lc and rc
                {
                    break;//Nothing to do.
                }
                //amoung lc and rc which one is greater has to come to the root.
                else if(a[lc] > a[rc])
                {
                    t=a[i];
                    a[i]=a[lc];
                    a[lc]=t;

                    i=lc;//if left child is greatest i should become left child.
                }
                else
                {
                    t=a[i];
                    a[i]=a[rc];
                    a[rc]=t;

                    i=rc;//if right child is greatest i should become left child.
                }
            }
            //case 2 :when there is only one child.
            else if(a[lc] > a[i])
            {
                t=a[i];
                a[i]=a[lc];
                a[lc]=t;
                i=lc;
            }
            else
            {
                break;
            }
            disparr(a, 4);
            printf("\n");
        }


    }

}

int main(){
    int a[5];
    heaptree(a,0,10);
    heaptree(a,1,12);
    heaptree(a,2,15);
    heaptree(a,3,5);
    heaptree(a,4,20);
    disparr(a,4);
    printf("\n");
    heapsort(a,4);
    disparr(a,4);
    return 0;
}