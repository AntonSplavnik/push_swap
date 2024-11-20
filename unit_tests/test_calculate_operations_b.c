#include <stdio.h>

// Define the t_stacks structure
typedef struct s_stacks {
    int *stack_b;           // Array representing stack B
    int stack_b_len;        // Length of stack B
} t_stacks;

// Mock functions for find_max and find_min
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

// Your function
int calculate_operations_b(t_stacks *stacks, int num)
{
    int max = find_max(stacks);
    int min = find_min(stacks);
    int i;

    if (stacks->stack_b_len == 0 || num > max || num < min)
    {
        i = stacks->stack_b_len - 1;
        while (i >= 0)
        {
            if (stacks->stack_b[i] == max)
            {
                if (i == stacks->stack_b_len - 1)
                    return (0);
                else
                    return (i + 1);
            }
            i--;
        }
        return (stacks->stack_b_len - 1);
    }
    i = stacks->stack_b_len - 1;
    while (i > 0)
    {
        if (stacks->stack_b[i] > num && stacks->stack_b[i - 1] < num)
            return (i);
        i--;
    }
    if (num < stacks->stack_b[0] && num > stacks->stack_b[stacks->stack_b_len - 1])
        return (0);
    return (stacks->stack_b_len - 1);
}

// Main function to test your code
int main() {
    t_stacks stacks;

    // Test case 1
    int stack_b1[] = {10, 15, 20};
    stacks.stack_b = stack_b1;
    stacks.stack_b_len = 3;

    printf("Test 1: Expected 0, Got %d\n", calculate_operations_b(&stacks, 25)); // num > max
    printf("Test 2: Expected 0, Got %d\n", calculate_operations_b(&stacks, 5));  // num < min
    printf("Test 3: Expected 1, Got %d\n", calculate_operations_b(&stacks, 12)); // num between
    printf("Test 4: Expected 0, Got %d\n", calculate_operations_b(&stacks, 8));  // num fits start
    printf("Test 5: Expected 0, Got %d\n", calculate_operations_b(&stacks, 22)); // num fits end

    // Test case 2: Empty stack
    stacks.stack_b_len = 0;
    printf("Test 6: Expected -1, Got %d\n", calculate_operations_b(&stacks, 10)); // Empty stack

    return 0;
}
