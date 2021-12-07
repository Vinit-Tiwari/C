
#include <stdio.h>
#include <stdlib.h>
int max=10;
max1=20;

void create(int a[],int n)
{
    int i;
    if(n>=max-1)
       {
            exit (0);
       }
    else
        printf("Enter %d elements\n",n);
    for(i=0;i<n;i++)
    {
        a[i+1]=a[i];
        scanf("%d",&a[i]);
    }
}

void print(int a[],int n)
{
    int i;
    n=length_of_array(a);
    printf("\nArray is:");
    for(i=0;i<n;i++)
    {
        printf("  %d",a[i]);
    }
}

int length_of_array(int a[])
{
    int i=0,count=0;

    while(a[i]!=-99)
    {
        count=count+1;
        i++;
    }
    return count;
}

int insertion(int a[],int n,int val,int pos,int max)
{
    int back;
    n=length_of_array(a);
    /*if(pos>n || n>=max-1)
    {
        printf("Insertion is not possible");
    }
    else*/
    {
        back=n;
        while(back>=pos)
        {
            a[back+1]=a[back];
            back--;
        }
        a[pos]=val;
    }
    return 0;
}


int deletion(int a[],int n,int pos)
{
    int back,i;
    n=length_of_array(a);
   if(pos>n-1 || n==0)
   {

       printf("Deletion is not possible\n");
   }
   else{
    for(back=pos;back<n;back++)
    {
        a[back]=a[back+1];
    }
   }
    printf("\nArray: ");

   return 0;
}


void copy(int a[], int n,int a1[])
{
    n=length_of_array(a);
    if(n==0)
    {
        printf("Please create an array");
    }

    else
    {
        int i;
        for(i=0;i<n;i++)
        {
            a1[i]=a[i];
        }
        print(a,n);
        printf("\nCopied array:");
        for(i=0;i<n;i++)
        {
            printf(" %d ",a1[i]);
        }
    }

}


void selection_sort(int a[],int n)
{
    int i,j,temp;
    for(i=0;i<n-1;i++)
    {
        int min=i;
        for(j=i+1;j<n;j++)
        {
            if(a[min]>a[j])
            {
                min=j;
            }
        }
        temp =a[i];
        a[i]=a[min];
        a[min]=temp;
    }
    printf("\nSorted Array: ");
    for(i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
}

void bubble_sort(int a[],int n)
{
    int i,j,temp;
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(a[j]>a[j+1])
            {
                temp=a[j+1];
                a[j+1]=a[j];
                a[j]=temp;
            }
        }
    }
}

void linear_search(int a[], int n, int num)
{
    int i;
    for (i=0;i<n;i++)
    {
        if (a[i]==num)
        {
            printf("\n%d is at index: %d\n",num,i);
            break;
        }
        else if (i==n-1)
        {
            printf("\nInput number is not valid\n");
        }
    }
}

void binary_search(int a[], int n, int num)
{
    int i, first, last, mid;

    first=0;
    last=n-1;
    mid=(first+last)/2;
    while(first<=last)
    {
        if(a[mid]<num)
        {
            first=mid+1;
        }
        else if(a[mid]==num)
        {
            printf("\n%d is at index: %d\n",num,mid);
            break;
        }
        else
        {
            last=mid-1;
        }
        mid=(first+last)/2;
    }
    if(first>last)
    {
        printf("\nElement not found in the list\n");
    }
}

int is_empty(int a[])
{
    int check = length_of_array(a);
    if(check==0)
    {
        return 1;
    }
    else
        return 0;
}

int is_full(int a[])
{
    int check=length_of_array(a);
    if(check==max-1)
    {
        return 0;
    }
    else
        return 1;
}
void merge(int a[],int n,int m)
{
    printf("Enter the number of elements in array: ");
    scanf("%d",&n);
    create(a,n);
    printf("Enter the number of elements in second array: ");
    scanf("%d",&m);

    int *b;
    b=(int*)calloc(n+m+2,sizeof(int));
    b[0]=-99;
    create(b,m);
    n=length_of_array(a);
    m=length_of_array(b);
    print(a,n);
    print(b,m);
    bubble_sort(b,m);

    int i,j;
    for(i=0;i<n;i++)
    {
        m=length_of_array(b);
        for(j=0;j<m;j++)
        {
            if(a[i]<b[j])
            {
                insertion(b,m,a[i],j,n+m+2);
                break;
            }
           /* if(j==n+1)
            {
                b[j+1]=b[j];
                b[j]=a[i];
            }*/
        }
    }

    printf("\nMerged array:");
      for(i=0;i<m+1;i++)
    {
        printf("  %d",b[i]);
    }
}
/*void merge(int a[],int a1[],int a2[],int n, int m)
{
    int i,j,k;
    n=length_of_array(a);
    m=length_of_array(a1);
    bubble_sort(a,n);
    bubble_sort(a1,m);

    j=k=0;

    for(i=0;i<m+n+1;i++)
    {
        if(a[j]<=a1[k])
        {
            a2[i]=a[j];
            j++;
        }
        else
        {
            a2[i]=a1[k];
            k++;
        }
    }
    int e=length_of_array(a2);
    printf("\nMerged array: ");
    for(i=0;i<e;i++)
    {
        printf("%d ",a2[i]);
    }

}*/
int main()
{
    int n,m;
    int *a;
    a=(int*)calloc(max,sizeof(int));
    a[0]=-99;

    int x,y;
    int num;
    int val,pos;
    int *a1,i;
    a1=(int*)calloc(max,sizeof(int));
    a1[0]=-99;
    //int *a2;
    //a2=(int*)calloc(max1,sizeof(int));
    //a2[0]=99;
    while(x!=11)
    {

    printf("\n\n");
    printf("\nSelect the array operation to perform:\nPress 0 to create an array\nPress 1 for insertion\nPress 2 for deletion\nPress 3 to copy an array\nPress 4 for sorting\nPress 5 for searching\nPress 6 to print length of array\nPress 7 to check if empty\nPress 8 to check if full\nPress 9 to print an array\nPress 10 to merge an array\nPress 11 to exist\n\n");
    scanf("%d",&x);


    switch(x)
    {
    case 0:

        printf("Enter the number of elements in array: ");
        scanf("%d",&n);
        create(a,n);
        print(a,n);
        n=length_of_array(a);
        m=length_of_array(a);
        printf("\nTotal elements: %d",m);
        break;
    case 1:

        printf("Enter a value to insert: ");
        scanf("%d",&val);
        printf("Enter an index: ");
        scanf("%d",&pos);
        insertion(a,n,val,pos,max);
        print(a,n);
        break;

    case 2:
        printf("Enter an index to delete: ");
        scanf("%d",&pos);
        deletion(a,n,pos);
        print(a,n);
        break;

    case 3:
        copy(a,n,a1);
        break;

    case 4:
        printf("\nFor selection sort press 1\nFor bubble sort press 2\n\n");
        scanf("%d",&y);
        switch(y)
        {
        case 1:
            n=length_of_array(a);
            selection_sort(a,n);
            break;

        case 2:
            n=length_of_array(a);
            bubble_sort(a,n);
            printf("\nSorted Array: ");
            print(a,n);
            break;
        default:
            printf("Invalid syntax");
        }
        break;
    case 5:
        printf("Enter the number to search: ");
        scanf("%d",&num);
        printf("\nPress 1 for linear search\nPress 2 for binary search\n");
        scanf("%d",&y);
        switch(y)
        {
        case 1:
            n=length_of_array(a);
            linear_search(a,n,num);
            break;
        case 2:
            n=length_of_array(a);
            binary_search(a,n,num);
            break;
        }
        break;

    case 6:
        val=length_of_array(a);
        printf("\nLength of array is: %d",val);
        break;


    case 7:
        val=is_empty(a);
        if(val==1)
        {
            printf("\nThe array is empty");
        }
        else
            printf("\nThe array is not empty");

        break;

    case 8:
        val = is_full(a);
        if(val==0)
        {
            printf("\nThe array is full");
        }
        else
            printf("\nThe array have empty spaces");
        break;

    case 9:
        print(a,n);
        break;

   /*case 10:
        create(a,n);
        printf("2nd array:\n");
        create(a1,m);
        merge(a,a1,a2,n,m);
        break;
*/
    case 10:
        merge(a,n,m);

        break;
    case 11:
        exit (0);
        break;
    }
    }
    return 0;
}
