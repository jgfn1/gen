void mergesort(int* vector, int vec_size)
{
	int* aux_vec = (int*) malloc(vec_size * sizeof(int));
	msort(v, aux_vec, 0, vec_size - 1);
}

void msort(int* vector, int* aux_vec, int left_limit, int right_limit)
{
	int index;
	if(right_limit != left_limit)
	{
		index  = /*floor*/(right_limit + left_limit)/2;
		msort(vector, aux_vec, left_limit, index);
		msort(vector, aux_vec, index + 1, right_limit);
		merge(vector, aux_vec, left_limit, right_limit);		
	}
}

void merge(int* vector, int* aux_vec, int left_limit, int right_limit)
{
	int i;
	for(i = left_limit; i <= right_limit; ++i)
		aux_vec[i] = vector[i];

	int index = /*floor*/ (left_limit + right_limit)/2;
	i = left_limit;
	int j = index + 1;
	int k;
	for(k = 0; k <= right_limit; ++k)
	{
		if(i = index + 1)
		{
			vector[k] = aux_vec[j];
			j++;
		}
		else if(j = right_limit + 1)
		{
			vector[k] = aux_vec[i];
			i++;
		}
		else if(aux_vec[i] <= vector[j])
		{
			vector[k] = aux_vec[i];
			i++;
		}
		else
		{
			vector[k] = aux_vec[j];
			j++;
		}
	}
}t