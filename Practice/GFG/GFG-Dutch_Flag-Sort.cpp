void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void sort012(int a[], int n)
{
    // coode here
    int l=0, mid=0, h=n-1;
    
    while(mid<=h)
    {
        if(a[mid]==1)
            mid++;
        else if(a[mid]==0)
            swap(&a[mid++], &a[l++]);
        else if(a[mid]==2)
            swap(&a[mid], &a[h--]);
    }
    
}