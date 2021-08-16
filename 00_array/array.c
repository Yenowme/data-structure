#define MAX 10001

typedef struct s_arr
{
	int	*arr[MAX];
	int	size;
}				t_arr;

int	*init(void)
{
	t_arr	*arr;

	arr->size = 0;
	return (arr);
}

int arr_empty(t_arr *arr)
{
	if (arr->size == 0)
		return (1);
	return (0);
}

int	arr_full(t_arr *arr)
{
	if (arr->size >= MAX)
		return (1);
	return (0);
}

int	size(t_arr *arr)
{
	return (arr->size);
}

void	arr_set(int data, t_arr *arr)
{
	for(int i=0; i < arr->size; i++)
	{
		arr->arr[i] = data;
	}
}

void	arr_add(int data, t_arr *arr, int idx)
{
	if (idx > arr->size)
		return ;
	if (!arr)
		return ;
	arr->arr[idx] = data;
}

void	push(t_arr *arr, int data)
{
	if (arr_full(arr))
		return ;
	arr->arr[arr->size] = data;
	arr->size++;
}

void	arr_delall(t_arr *arr)
{
	if (!arr)
		return ;
	free(arr->arr);
	arr->size = 0;
}
