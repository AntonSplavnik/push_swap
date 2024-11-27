/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_to_pos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonsplavnik <antonsplavnik@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 14:45:15 by antonsplavn       #+#    #+#             */
/*   Updated: 2024/11/19 16:49:53 by antonsplavn      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void move_to_correct_position(t_stacks *stacks)
{
    while (stacks->stack_a_len > 0)
    {
        int target_index = -1;

        // Find the number in STACK_A that should go next in STACK_B
        for (int i = 0; i < stacks->stack_a_len; i++)
        {
            if (stacks->stack_a[i] == stacks->stack_presort[stacks->stack_b_len])
            {
                target_index = i;
                break;
            }
        }

        if (target_index == -1)
        {
            // printf("Error: Target index not found.\n");
            exit(1); // Fail-safe in case logic breaks
        }

        // printf("Target index in STACK_A: %d\n", target_index);

        // Move the target number to the top of STACK_A
        if (target_index <= stacks->stack_a_len / 2)
        {
            // Rotate upwards until target_index reaches the top
            while (target_index < stacks->stack_a_len - 1)
            {
                // printf("Performing ra\n");
                rotate_a(stacks);
                target_index++;
            }
        }
        else
        {
            // Reverse rotate downwards until target_index reaches the top
            while (target_index != stacks->stack_a_len - 1)
            {
                // printf("Performing rra\n");
                reverse_rotate_a(stacks);
                target_index--;
                if (target_index < 0)
                {
                    target_index = stacks->stack_a_len - 1;
                }
            }
        }

        // Push the target number from STACK_A to STACK_B
        // printf("Performing pb\n");
        push_b(stacks);
    }

    // Push everything back to STACK_A in sorted order
    while (stacks->stack_b_len > 0)
    {
        // printf("Performing pa\n");
        push_a(stacks);
    }
}
