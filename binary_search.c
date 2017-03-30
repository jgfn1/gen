int binary_search(int* vector, int vec_size, int x)
{
	int left = 0;
	int right = vec_size - 1;
	int index;
	do
	{
		index = floor((left + right)/2);
		if(x == vector[index])
			return index;

		else if(x < vector[index])
			right = index - 1;
		
		else
			left = index + 1;
	}while(left <= right);
	return -1;
}