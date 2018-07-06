#include <stdlib.h>
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	print_bits(void *t)
{
	unsigned char *exp;
	int i;
	int j;
	unsigned char bit;

	exp = (unsigned char*)t;
	i = 0;
	while (i < 8)
	{
		bit = 128;
		j = 0;
		while (j < 8)
		{
			if (bit & *exp)
				ft_putchar('1');
			else
				ft_putchar('0');
			bit = bit / 2; 
			j++;
		}
		exp++;
		i++;
	}
}

void	put_in_bit(double t, int pos_bit, int val_bit)
{
	double writer;

	writer = 1;
}

#define N 12
int main(void)
{
	int pos;

	double t[N] = {0, -0, 1, -1, 2, -2, 0.5, -0.5, 64, 512, 4096, 1E25};

	pos = 0;
	while (pos < N)
	{
		print_bits((void *)&t[pos]);
		ft_putchar('\n');
		pos++;
	}
	return (0);
}
