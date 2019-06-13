#include<iostream>
#include<stdlib.h>
#include<time.h>

using namespace std;

clock_t t;

void generate(int *a,int n)
{
 int i;
 for(i=0;i<n;i++)
 {
   a[i]=rand();

 }
}

 void Merge(int *a, int low, int high, int mid)
{

	int i, j, k, temp[high-low+1];
	i = low;
	k = 0;
	j = mid + 1;


	while (i <= mid && j <= high)
	{
		if (a[i] < a[j])
		{
			temp[k] = a[i];
			k++;
			i++;
		}
		else
		{
			temp[k] = a[j];
			k++;
			j++;
		}
	}


	while (i <= mid)
	{
		temp[k] = a[i];
		k++;
		i++;
	}


	while (j <= high)
	{
		temp[k] = a[j];
		k++;
		j++;
	}



	for (i = low; i <= high; i++)
	{
		a[i] = temp[i-low];
	}
}

void MergeSort(int *a, int low, int high)
{
	int mid;
	if (low < high)
	{
		mid=(low+high)/2;

		MergeSort(a, low, mid);
		MergeSort(a, mid+1, high);


		Merge(a, low, high, mid);
	}
}

int main()
{
	int n, i,a[300000];
	cout<<"\nEnter the size of the array: ";
	cin>>n;

	generate(a,n);
	 for(i=0;i<n;i++)
     cout<<a[i]<<" ";

	   t=clock();

	MergeSort(a, 0, n-1);

	cout<<"\nSorted Data ";
	for (i = 0; i < n; i++)
        cout<<a[i]<<" ";
    t=clock()-t;
     cout<<"\ntime is :"<<t;
	return 0;
}

