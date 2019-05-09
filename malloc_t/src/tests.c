/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbehra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 12:34:30 by tbehra            #+#    #+#             */
/*   Updated: 2019/05/08 18:36:48 by tbehra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MIN_TINY 1
#define MAX_TINY 991
#define MIN_SMALL 992 
#define MAX_SMALL 65512

void print_mmaps()
{
	t_zone *z;
	int i;

	i = 0;
	z = g_alloc.tiny;
	while (z)
	{
		ft_printf("z : %p\n", z);
		z = z->next;
		i++;
	}
	ft_printf("il y a %i zones mmappées dans tiny\n", i);
	i = 0;
	z = g_alloc.small;
	while (z)
	{
		ft_printf("z : %p\n", z);
		z = z->next;
		i++;
	}
	ft_printf("il y a %i zones mmappées dans small\n", i);
}

void test_small(n_malloc)
{
	int	size_malloc;
	int j;
	int i = -1;
	char **b;

	srand(time(NULL));
	b = (char**)ft_malloc(sizeof(char *) * n_malloc);
	printf("b : %p\n", b);
	if (b)
	{
		while (++i < n_malloc)
		{
//			printf("\nTest %i\n", i);
			size_malloc = rand() % (MAX_SMALL - MIN_SMALL + 1) + MIN_SMALL;
//			ft_printf("size : %d\n", size_malloc);
			b[i] = (char *)ft_malloc(sizeof(char) * size_malloc);
			ft_printf("\n");
			if (b[i]) {
				j = -1;
				while (++j < (size_malloc - 1))
					b[i][j] = rand() % ('z' - 'A') + 'A';
				b[i][j] = 0;

				if (rand() > RAND_MAX/2)
				{
//					ft_printf("Trying to free\n");
					ft_free(b[i]);
				}
			}
			else {
				printf("b couldn't be allocated\n");
			}
		}
	}
}

void test_100_max_small(void)
{
	int n_malloc = 100;
	int	size_malloc;
	int j;
	int i = -1;
	char **b;

	srand(time(NULL));
	b = (char**)ft_malloc(sizeof(char *) * n_malloc);
	printf("b : %p\n", b);
	if (b)
	{
		while (++i < n_malloc)
		{
			printf("\nTest %i\n", i);
			size_malloc = MAX_SMALL;
			ft_printf("size : %d\n", size_malloc);
			b[i] = (char *)ft_malloc(sizeof(char) * size_malloc);
			ft_printf("\n");
			if (b[i]) {
				j = -1;
				while (++j < (size_malloc - 1))
					b[i][j] = rand() % ('z' - 'A') + 'A';
				b[i][j] = 0;
			}
			else {
				printf("b couldn't be allocated\n");
			}
		}
	}
}


void test_tiny(int n_malloc)
{
	int	size_malloc;
	int j;
	int i = -1;
	char **b;

	srand(time(NULL));
	b = (char**)ft_malloc(sizeof(char *) * n_malloc);
	printf("b : %p\n", b);
	if (b)
	{
		while (++i < n_malloc)
		{
			size_malloc = rand() % (MAX_TINY - MIN_TINY + 1) + MIN_TINY;
			//printf("\nTest %i, size %i\n", i, size_malloc);
			b[i] = (char *)ft_malloc(sizeof(char) * size_malloc);
		//	printf("Adress : %p\n", &b[i]);
			if (b[i]) {
				j = -1;
				while (++j < (size_malloc - 1))
					b[i][j] = rand() % ('z' - 'A') + 'A';
				b[i][j] = 0;
				if (rand() > RAND_MAX/2)
				{
	//				ft_printf("Trying to free\n");
					ft_free(b[i]);
				}
			}
			else {
				printf("b couldn't be allocated\n");
			}
		}
	}
} 


void test_n_max_tiny(int n_malloc)
{
	int	size_malloc;
	int j;
	int i = -1;
	char **b;

	srand(time(NULL));
	b = (char**)ft_malloc(sizeof(char *) * n_malloc);
	printf("b : %p\n", b);
	if (b)
	{
		while (++i < n_malloc)
		{
			printf("\nTest %i\n", i);
			size_malloc = MAX_TINY; 
			printf("Size : %i\n", size_malloc);
			b[i] = (char *)ft_malloc(sizeof(char) * size_malloc);
			//ft_printf("print memory of assigned chunk: \n");
			print_memory((uint8_t*)&b[i] - sizeof(t_chunk), sizeof(t_chunk));
			ft_printf("\n");

			if (b[i]) {
				j = -1;
				while (++j < (size_malloc - 1))
					b[i][j] = rand() % ('z' - 'A') + 'A';
				b[i][j] = 0;
			}
			else {
				printf("b couldn't be allocated\n");
			}
		}
	}
}

void	single_large_malloc(void)
{
	const long size_malloc = 800000;
	char *big;

	if (!(big = (char *)ft_malloc(size_malloc)))
		return ;
	int i = -1;
	while (++i < size_malloc - 1)
	{
		big[i] = 'A' + (('A' + i) % 127);
	}
	big[i] = '\0';
	//printf("big : %s\n", big);
	//ft_free(big);
}

void	n_large_malloc(int n_big_malloc)
{
	const int big_size = 490120;
	char **a;
	int i;
	int j;

	a = (char **)ft_malloc(n_big_malloc * sizeof(t_chunk*));
	i = -1;
	while (++i < n_big_malloc)
	{
		a[i] = (char *)ft_malloc(big_size);
		ft_printf("mallocated a[%i] : %p, g_alloc.large : %p\n", i, a[i], g_alloc.large);
		j = -1;
		while (++j < big_size - 1)
		{
			a[i][j] = 'A' + i;
		}
		a[i][j] = '\0';
	}

	i = -1;
	while (++i < n_big_malloc)
	{
		ft_printf("address to free a[%i] : %X, g_alloc.large : %p\n",
				i, (uint64_t)a[i], g_alloc.large);
		if (i % 2 == 0)
			ft_free(a[i]);
	}
}	

void	spam_ram(void)
{
	const int big_size = 490120;
	const int n_big_malloc = 50000;
	char **a;
	int i;

	a = (char **)ft_malloc(n_big_malloc * sizeof(t_chunk*));
	i = -1;
	while (++i < n_big_malloc)
	{
		a[i] = (char *)ft_malloc(big_size);
		ft_printf("mallocated a[%i] : %p, g_alloc.large : %p\n", i, a[i], g_alloc.large);
	}
}

void	test_find_last_tiny_viable_address()
{
	int	size_malloc;
	int n_malloc = 150;
	int j;
	int i = -1;
	char **b;

	srand(time(NULL));
	b = (char**)ft_malloc(sizeof(char *) * n_malloc);
	printf("b : %p\n", b);
	if (b)
	{
		while (++i < n_malloc)
		{
			size_malloc = 991;
			b[i] = (char *)ft_malloc(sizeof(char) * size_malloc);

			if (i >= 129)
			{
				if (b[i]) {
					j = -1;
					while (++j < (size_malloc - 1))
					{
						b[i][j] = rand() % ('z' - 'A') + 'A';
						printf("Char number %i : %c, address %p, last_address: %p \n", j, b[i][j], &b[i][j], last_address(g_alloc.tiny));
					}
					b[i][j] = 0;
				}
			}
			else {
				printf("b couldn't be allocated\n");
			}
		}
	}
}

void	test_free(int n_malloc)
{
	int	size_malloc;
	int j;
	int i = -1;
	char **b;

	srand(time(NULL));
	b = (char**)ft_malloc(sizeof(char *) * n_malloc);
	if (b)
	{
		while (++i < n_malloc)
		{
			size_malloc = rand() % (MAX_TINY - MIN_TINY + 1) + MIN_TINY;
		//	printf("\nTest %i, size %i\n", i, size_malloc);
		
			b[i] = (char *)ft_malloc(sizeof(char) * size_malloc);
		//	printf("Adress : %p\n", &b[i]);
			if (b[i]) {
				j = -1;
				while (++j < (size_malloc - 1))
					b[i][j] = rand() % ('z' - 'A') + 'A';
				b[i][j] = 0;
				ft_free(b[i]);
			}
			else {
				printf("b couldn't be allocated\n");
			}
		}
		
	}
	ft_free(b);
}

void	test_n_random_size(int n_malloc)
{
	int	size_malloc;
	int j;
	int i = -1;
	char **b;

	srand(time(NULL));
	b = (char**)ft_malloc(sizeof(char *) * n_malloc);
	printf("b : %p\n", b);
	if (b)
	{
		while (++i < n_malloc)
		{
			size_malloc = rand() % ((MAX_SMALL + MAX_SMALL/20)- MIN_TINY + 1) + MIN_TINY;
			b[i] = (char *)ft_malloc(sizeof(char) * size_malloc);
			if (b[i]) {
				j = -1;
				while (++j < (size_malloc - 1))
					b[i][j] = rand() % ('z' - 'A') + 'A';
				b[i][j] = 0;
			}
			else {
				ft_printf("Couldn't be allocated\n");
			}
		}
		
		i = -1;
		ft_printf("Mmaps before we free:\n");
		print_mmaps();
		while (++i < n_malloc)
			ft_free(b[i]);
	}
	ft_free(b);
	print_mmaps();
}

void	malloc_vs_ft_malloc(int n_malloc)
{
	clock_t start;

	start = clock();
	test_n_random_size(n_malloc); //ft_malloc
	printf("ft_malloc time for %i malloc and free all : %lf\n", n_malloc, (double)(clock() - start) / CLOCKS_PER_SEC);

	int	size_malloc;
	int j;
	int i = -1;
	char **b;
	srand(time(NULL));

	start = clock();
	b = (char**)malloc(sizeof(char *) * n_malloc);
	if (b)
	{
		while (++i < n_malloc)
		{
			size_malloc = rand() % ((MAX_SMALL + MAX_SMALL/20)- MIN_TINY + 1) + MIN_TINY;
			b[i] = (char *)malloc(sizeof(char) * size_malloc);
			if (b[i]) {
				j = -1;
				while (++j < (size_malloc - 1))
					b[i][j] = rand() % ('z' - 'A') + 'A';
				b[i][j] = 0;
			}
			else {
				ft_printf("Couldn't be allocated\n");
			}
		}
		
		i = -1;
		while (++i < n_malloc)
			free(b[i]);
	}
	free(b);
	
	printf("malloc time for %i malloc and free all : %lf\n", n_malloc, (double)(clock() - start) / CLOCKS_PER_SEC);
}

int main(void)
{
//	test_free(200);
	
//	test_n_random_size(1000);


	malloc_vs_ft_malloc(50);
	
//	test_n_max_tiny(100);
//	test_tiny(2000);
//	test_find_last_tiny_viable_address();
//	test_small(30000);
//	test_100_max_small();
//	single_large_malloc();	
//	n_large_malloc(10); 
//	spam_ram();

	//TODO: realloc
//	show_alloc_mem();
	return (0);
}
