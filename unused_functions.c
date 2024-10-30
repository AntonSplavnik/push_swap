
void	fillarray_with_numbers(int *unsorted_numbers, char *number)
{
	int	i;

	i = 0;
	while (i <= number)
	{
		unsorted_numbers[i - 1] = ft_atoi(number[i]);
		printf("\t\t\t%d\n", unsorted_numbers [i - 1]);
		i++;
	}
}

int	element_counter(char **str)
{
	int	i;
	int	j;
	int	counter;

	i = 1;
	counter = 0;
	while (str[i])
	{
		while (str[i][0] == '\0')
			i++;
		j = 0;
		while (str[i][j])
		{
			while (str[i][j] == ' ')
				j++;
			if (str[i][j] == '-')
			{
				if ((str[i][j + 1] < '0' || str[i][j + 1] > '9') ||
				(j > 0 && str[i][j + 1] != ' '))
				{
					ft_putstr("Error: Invalid '-' placement" \
						"or '-' not followed by a digit\n");
					exit (1);
				}
				j++;
			}
			if (str[i][j] >= '0' && str[i][j] <= '9')
			{
				while (str[i][j] >= '0' && str[i][j] <= '9')
					j++;
				counter++;
			}
			else if (str[i][j] != ' ' && str[i][j] != '\0')
			{
				ft_putstr("Error: found non-numeric value\n");
				exit (1);
			}
		}
		i++;
	}
	return (counter);
}

void	ft_memset(void *str, int c, size_t number)
{
	size_t	i;

	i = 0;
	while (i < number)
	{
		((char *)str)[i] = (char)c;
		i++;
	}
}

int	*ft_realloc(int *input_array, int new_length, int old_length)
{
	int	i;
	int	*realocatd_array;

	i = 0;
	realocatd_array = ft_calloc(new_length, sizeof(int));
	if (realocatd_array == NULL)
	{
		ft_putstr("Memory allocation error");
		return (NULL);
	}
	while (i < old_length)
	{
		realocatd_array[i] = input_array[i];
		i++;
	}
	free(input_array);
	return (realocatd_array);
}
