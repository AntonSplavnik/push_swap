
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

void	input_to_array(int argc, char **argv)
{
	int		i;
	int		n;
	int		number_count_input_str;
	int		*unsorted_numbers;
	char	**arrs;

	i = 1;
	number_count_input_str = element_counter(argv);

	process_argument(**argv);

	// validation of a singular number: spaces, number, limits)
	while (i <= argc)
	{
		if (input_restrictions(argv[i]) == 1)
			exit (1);
		else if (limits(ft_atoi(argv[i])) == 1)
			exit (1);
		i++;
	}

	//allocation of int array
	i = 1;
	unsorted_numbers = ft_calloc(argc, sizeof(int));
	if (unsorted_numbers == NULL)
	{
		ft_putstr("Error: Memory allocation\n");
		exit (1);
	}

	//filling int array with singular number
	ft_putstr("\nUnsorted numbers:\n");
	while (i <= argc)
	{
		unsorted_numbers[i - 1] = ft_atoi(argv[i]);
		printf("\t\t\t%d\n", unsorted_numbers [i - 1]);
		i++;
	}

	//duplicate check in an array
	if (duplicate_check(unsorted_numbers, argc) == 1)
	{
		ft_putstr("Error: Duplicate found\n");
		free(unsorted_numbers);
		exit (1);
	}
	free(unsorted_numbers);
}

char	**process_argument(char *argv)
{
	int		i;
	char	**splited_numbers;

	i = 0;
	while (argv[i])
	{
		if (argv[i] == ' ')
		{
			splited_numbers = ft_split(argv, ' ');
			return (splited_numbers);
		}
		i++;
	}
	splited_numbers = ft_calloc(2, sizeof(char *));
	if (splited_numbers == NULL)
		return (NULL);
	splited_numbers[0] = ft_calloc(ft_strlen((const char *)argv), sizeof(char *));
	splited_numbers[0] = ft_strncpy(splited_numbers[0],
			(const char *)argv, (size_t)ft_strlen((const char *)argv));
	splited_numbers[1] = NULL;
	return (splited_numbers);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
