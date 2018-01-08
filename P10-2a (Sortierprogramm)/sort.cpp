#include "sort.h"

void sortiere(int a[], int N)
{
	for (int i = 1; i < N; i++)
	{
		int einzusortieren = a[i];
		unsigned j = i;
		while (j > 0 && a[j - 1] > einzusortieren)
		{
			a[j] = a[j - 1];
			j = j - 1;
		}
		a[j] = einzusortieren;
	}
}
