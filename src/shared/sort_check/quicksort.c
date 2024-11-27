/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asplavni <asplavni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 16:03:33 by asplavni          #+#    #+#             */
/*   Updated: 2024/11/27 21:47:05 by asplavni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shared.h"

// Function to swap two elements
void	quicksort_swap(int *a, int *b)
{
	int	temp = *a;
	*a = *b;
	*b = temp;
}

// Partition function
int	partition(int arr[], int low, int high)
{
	int	pivot = arr[high];	// Choosing the last element as the pivot
	int	i = low - 1;		// Index of the smaller element

	for (int j = low; j <= high - 1; j++)
	{
		// If the current element is smaller than or equal to the pivot
		if (arr[j] >= pivot)
		{
			i++;
			quicksort_swap(&arr[i], &arr[j]);
		}
	}
	quicksort_swap(&arr[i + 1], &arr[high]);
	return (i + 1);
}

// Quicksort function
void	quicksort(int arr[], int low, int high)
{
	if (low < high)
	{
		int pi = partition(arr, low, high);	// Partitioning index

		// Recursively sort elements before and after partition
		quicksort(arr, low, pi - 1);
		quicksort(arr, pi + 1, high);
	}
}
