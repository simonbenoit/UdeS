#pragma once
class nsearch
{
public:
	nsearch(){};
	~nsearch(){};
	template<class T>
	void mergesort(T a[], int min, int max);
	template<class T>
	void merge(T a[], int min, int mid, int max);

	template<class T>
	T bisectionsearch(T a[], int min, int max, T key);
};

template <class T>
void merge(T a[], int min, int mid, int max)
{
	int i, j;
	int size1 = mid - min + 1;
	int size2 = max - mid;

	T *tmpArray1 = new T[size1];
	T *tmpArray2 = new T[size2];


	for (i = 0; i<size1; i++)
	{
		tmpArray1[i] = a[min + i];
	}

	for (j = 0; j<size2; j++)
	{
		tmpArray2[j] = a[mid + 1 + j];
	}

	i = 0;
	j = i;

	for (int k = min; k <= max; k++)
	{
		if (i == size1)
		{
			a[k] = tmpArray2[j];
			j++;
		}
		else if (j == size2)
		{
			a[k] = tmpArray1[i];
			i++;
		}
		else if (tmpArray1[i] < tmpArray2[j])
		{
			a[k] = tmpArray1[i];
			i++;
		}
		else
		{
			a[k] = tmpArray2[j];
			j++;
		}
	}

	delete[] tmpArray1;
	delete[] tmpArray2;
}

template<class T>
void mergesort(T a[], int min, int max)
{
	if (max - min > 1)
	{
		int mid = (min + max) / 2;
		mergesort(a, min, mid);
		mergesort(a, mid + 1, max);
		merge(a, min, mid, max);
	}
	else
	{
		if (a[max] < a[min])
		{
			T tmp = a[max];
			a[max] = a[min];
			a[min] = tmp;
		}
	}
}

template <class T>
T bisectionsearch(T a[], int min, int max, T key)
{
	int  i = (min + max) / 2;
	while ((a[i] != key) && (min <= max))
	{
		if (a[i] > key)
		{
			max = i;
		}
		else
		{
			min = i;
		}
		i = (min + max) / 2;
	}
	return a[i];
}