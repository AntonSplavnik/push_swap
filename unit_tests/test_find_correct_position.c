typedef struct s_stacks
{
    int *stack_b;
    int stack_b_len;
} t_stacks;

#include <stdio.h>
#include <assert.h>

int	find_min(t_stacks *stacks)
{
	int	min;
	int	i;

	min = stacks->stack_b[stacks->stack_b_len - 1];
	i = stacks->stack_b_len - 2;
	// printf("%d. min before: %d. stack_b_len: %d\n", i, min, stacks->stack_b_len);
	while (i >= 0)
	{
		// printf("%d. min before: %d\n", i, min);
		if (stacks->stack_b[i] < min)
		{
			min = stacks->stack_b[i];
			// printf("%d. min after: %d\n", i, min);
		}
		i--;
	}
	return (min);
}

int	find_max(t_stacks *stacks)
{
	int	max;
	int	i;

	max = stacks->stack_b[stacks->stack_b_len - 1];
	i = stacks->stack_b_len - 2;
	while (i >= 0)
	{
		if (stacks->stack_b[i] > max)
			max = stacks->stack_b[i];
		i--;
	}
	// printf("max: %d\n", max);
	return (max);
}

int	find_correct_position(t_stacks *stacks, int num)
{
	int	i;
	int	max;
	int	min;

	if (stacks->stack_b_len == 0)
		return (0);
	max = find_max(stacks);
	min = find_min(stacks);
	i = stacks->stack_b_len - 1;
	if (num > max || num < min)
	{
		while (i >= 0)
		{
			if (stacks->stack_b[i] == max)
				return (i);
			i--;
		}
		return (stacks->stack_b_len - 1);
	}
	i = stacks->stack_b_len - 1;
	while (i > 0)
	{
		if (stacks->stack_b[i] > num && stacks->stack_b[i - 1] < num)
			return (i);
		i --;
	}
	if (num < stacks->stack_b[0] && num > stacks->stack_b[stacks->stack_b_len - 1])
		return (stacks->stack_b_len - 1);
	return (0);
}

void run_test_case(t_stacks *stacks, int num, int expected)
{
    int result = find_correct_position(stacks, num);
    printf("Input: num = %d, stack_b = [", num);
    for (int i = 0; i < stacks->stack_b_len; i++)
    {
        printf("%d", stacks->stack_b[i]);
        if (i < stacks->stack_b_len - 1)
            printf(", ");
    }
    printf("]\n");
    printf("Expected: %d, Result: %d\n", expected, result);
    if (result == expected)
        printf("Test passed!\n\n");
    else
        printf("Test failed!\n\n");
}

void test_find_correct_position()
{
    t_stacks stacks;

    // Test case 1: Empty stack_b
    stacks.stack_b = NULL;
    stacks.stack_b_len = 0;
    run_test_case(&stacks, 10, 0);

    // Test case 2: Single element in stack_b
    int stack_b1[] = {5};
    stacks.stack_b = stack_b1;
    stacks.stack_b_len = 1;
    run_test_case(&stacks, 10, 0); // Should return 0
    run_test_case(&stacks, 2, 0);  // Should return 0

    // Test case 3: Multiple elements, num greater than max
    int stack_b2[] = {2, 5, 8};
    stacks.stack_b = stack_b2;
    stacks.stack_b_len = 3;
    run_test_case(&stacks, 10, 2); // Should return 2 (after max)

    // Test case 4: Multiple elements, num smaller than min
    run_test_case(&stacks, 1, 2); // Should return 2 (after max in circular behavior)

    // Test case 5: Insert in between elements
    run_test_case(&stacks, 6, 2); // Should return 2 (between 5 and 8)
    run_test_case(&stacks, 4, 1); // Should return 1 (between 2 and 5)

    // Test case 6: Wrap around
    int stack_b3[] = {10, 20, 30};
    stacks.stack_b = stack_b3;
    stacks.stack_b_len = 3;
    run_test_case(&stacks, 25, 2); // Should return 2 (between 20 and 30)
    run_test_case(&stacks, 5, 2);  // Should return 2 (before 10 in circular behavior)
}

int main()
{
    test_find_correct_position();
    return 0;
}
