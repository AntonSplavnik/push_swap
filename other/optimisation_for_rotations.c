/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimisation_for_rotations.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asplavni <asplavni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 18:59:12 by asplavni          #+#    #+#             */
/*   Updated: 2024/11/23 19:01:40 by asplavni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int compare_operations(int operations_a, int operations_b, int index_a, int pos_b, int size_a, int size_b)
{
    int result = 0;
    int same_direction = 0;

    if ((index_a <= size_a / 2 && pos_b <= size_b / 2) || (index_a > size_a / 2 && pos_b > size_b / 2))
        same_direction = 1;

    if (same_direction)
    {
        if (operations_a > operations_b)
        {
            result = operations_a;
        }
        else
        {
            result = operations_b;
        }
    }
    else
        result = operations_a + operations_b;

    return result;
}

void execute_rotations(t_stacks *stacks, int index_a, int pos_b)
{
    int operations_a = calculate_stack_operations(stacks->stack_a_len, index_a);
    int operations_b = calculate_stack_operations(stacks->stack_b_len, pos_b);

    // Determine the rotation direction for STACK_A and STACK_B
    int direction_a = (index_a <= stacks->stack_a_len / 2) ? 1 : -1; // 1 for rotate, -1 for reverse rotate
    int direction_b = (pos_b <= stacks->stack_b_len / 2) ? 1 : -1; // 1 for rotate, -1 for reverse rotate

    // Handle same-direction rotations
    if (direction_a == 1 && direction_b == 1)
    {
        // Perform simultaneous rotations (rr)
        while (operations_a > 0 && operations_b > 0)
        {
            printf("rr\n");
            rotate_a(stacks);
            rotate_b(stacks);
            operations_a--;
            operations_b--;
        }
    }
    else if (direction_a == -1 && direction_b == -1)
    {
        // Perform simultaneous reverse rotations (rrr)
        while (operations_a > 0 && operations_b > 0)
        {
            printf("rrr\n");
            reverse_rotate_a(stacks);
            reverse_rotate_b(stacks);
            operations_a--;
            operations_b--;
        }
    }

    // Handle remaining rotations for STACK_A
    if (direction_a == 1)
    {
        while (operations_a > 0)
        {
            printf("ra\n");
            rotate_a(stacks);
            operations_a--;
        }
    }
    else
    {
        while (operations_a > 0)
        {
            printf("rra\n");
            reverse_rotate_a(stacks);
            operations_a--;
        }
    }

    // Handle remaining rotations for STACK_B
    if (direction_b == 1)
    {
        while (operations_b > 0)
        {
            printf("rb\n");
            rotate_b(stacks);
            operations_b--;
        }
    }
    else
    {
        while (operations_b > 0)
        {
            printf("rrb\n");
            reverse_rotate_b(stacks);
            operations_b--;
        }
    }
}
void push_cheapest(t_stacks *stacks, int *sorted_stack)
{
    int index_a = find_cheapest(stacks); // Find the index in STACK_A
    int pos_b = find_correct_position(stacks, stacks->stack_a[index_a]); // Find target position in STACK_B

    // Execute rotations to move the number from STACK_A to STACK_B
    execute_rotations(stacks, index_a, pos_b);

    // Push the number to STACK_B
    printf("pb\n");
    push_b(stacks);
}
