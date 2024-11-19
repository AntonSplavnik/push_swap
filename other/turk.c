
// int	find_correct_position(t_stacks *stacks, int num)
// {
// 	int	i;
// 	int	max;
// 	int	min;

// 	if (stacks->stack_b_len == 0)
// 		return (0);
// 	max = find_max(stacks);
// 	min = find_min(stacks);
// 	i = stacks->stack_b_len - 1;
// 	if (num > max || num < min)
// 	{
// 		while (i >= 0)
// 		{
// 			if (stacks->stack_b[i] == max)
// 				return (i);
// 			i--;
// 		}
// 		return (stacks->stack_b_len - 1);
// 	}
// 	i = stacks->stack_b_len - 1;
// 	while (i > 0)
// 	{
// 		if (stacks->stack_b[i] > num && stacks->stack_b[i - 1] < num)
// 			return (i);
// 		i --;
// 	}
// 	return (0);
// }
