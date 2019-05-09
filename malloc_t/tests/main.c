
#include <malloc/malloc.h>
#include <sys/resource.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int	main(void)
{
	const int	rlimit_flags[9] = {RLIMIT_CORE, RLIMIT_CPU, RLIMIT_DATA, RLIMIT_FSIZE, RLIMIT_MEMLOCK, RLIMIT_NOFILE, RLIMIT_NPROC, RLIMIT_RSS, RLIMIT_STACK};
	const char *rlimit_names[9] = {"RLIMIT_CORE", "RLIMIT_CPU", "RLIMIT_DATA", "RLIMIT_FSIZE", "RLIMIT_MEMLOCK", "RLIMIT_NOFILE", "RLIMIT_NPROC", "RLIMIT_RSS", "RLIMIT_STAC"};

	int i;
	int j;
	int k;
	int l[100];
	char m[1000000];
	int *a, *b, *d;
	char *c;

	a = (int *)malloc(10);
	b = (int *)malloc(10);
	c = (char *)malloc(30);
//	d = (int *)malloc(8);

	printf("Addresses \ni : %p\nj : %p\nk : %p\nl : %p\nm : %p\na: %p\nb: %p\nc: %p\nd: %p\n", &i, &j, &k, &l, &m, a, b, c, d);
	printf("Getpagesize : %i", getpagesize());


//	bzero(d, 8);
	i = -1;
	//test : on peut mettre 36 octets dans un malloc de 30
	while (++i < 38)
		c[i] = 'f';
	printf("ici, c: %s\n", c);
	printf("et la, d: %s\n", (char*)d);
	printf("malloc_size(c): %zu\n", malloc_size(c));
	printf("getrlimit (max system resource consumption)\n");
	i = -1;
	while (++i < 9)
		printf("%s %i\n", rlimit_names[i], getrlimit(rlimit_flags[i], (struct rlimit *)m));


	return (0);
}
