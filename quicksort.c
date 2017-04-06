void quicksort(int* vector, int vec_size)
{
	qsort(vector, 0, vec_size - 1);
}

void qsort(int* vector, int left_limit, int right_limit)
{
	if(left_limit < right_limit)
	{
		int position = partition(vector, left_limit, right_limit);
		qsort(vector, left_limit, position - 1);
		qsort(vector, position + 1, right_limit);
	}
}

int partition(int* vector, int left_limit, int right_limit)
{
	int pivot = pivot(vector, left_limit, right_limit);
	int exchange;
	int i = left_limit;
	int j = right_limit;

	exchange = vector[left_limit];
	vector[left_limit] = vector[pivot];
	vector[pivot] = exchange;

	while(i < j)
	{
		while((i <= right_limit) && (vector[i] <= vector[left_limit]))
			i++;

		while(vector[j] > vector[left_limit])
			j++;
		if(i < j)
		{
			exchange = i;
			i = j;
			j = exchange;
		}
	}
	exchange = vector[left_limit];
	vector[left_limit] = vector[j];
	vector[j] = exchange;

	return j;
}