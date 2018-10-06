#include <stdio.h>
#include <stdlib.h>

void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;
 
    int L[n1], R[n2];
 
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];
 
    i = 0; 
    j = 0; 
    k = l; 
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
 
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
 
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}
 
void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int m = l+(r-l)/2;
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
        merge(arr, l, m, r);
    }
}

int read(int arr[])
{
    int num;
    scanf("%d", &num);
    for (int i = 0; i<num; i++)
    {
		scanf("%d", &arr[i]);
    }
    return num;
}

int price (int size, int books [])
{
	int reset = 0, sum = 0;
	for (int i = size - 1; i > (size % 3) - 1; i--)
    {
		if (reset <=1)
		{
			sum += books[i];
			reset++;
		}
		else
		{
			reset = 0;
		}	
			
    }
    for (int i = (size % 3) - 1 ; i >= 0; i--)
    {
		sum += books[i];
    }
    return sum;
}

int main ()
{
	int books [100000];
	int size = read (books);
	mergeSort(books, 0, size-1);
    printf("%d", price(size, books));
    
}
