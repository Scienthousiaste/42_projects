#include <stdio.h>
#include <limits.h>
#include "ft_printf.c"
#include <locale.h>
#include <wchar.h>

int main(void)
{
	int a;
	int b;
	int c;

	setlocale(LC_ALL, "");


	a = printf("42%34.1s42", "3nl4r9e y0\/r pr1ntf");
	printf("\n\n");
	b = ft_printf("42%34.1s42", "3nl4r9e y0\/r pr1ntf");
	printf("\n\n");
	
	printf("a : %d, b : %d\n", a, b);

	
	a = printf("!%2.2s!", NULL);
	printf("\n\n");
	b = ft_printf("!%2.2s!", NULL);
	printf("\n\n");
	
	printf("a : %d, b : %d\n", a, b);
	a = printf("|%31lc|", (wchar_t)128150);
	printf("\n\n");
	b = ft_printf("|%31lc|", (wchar_t)128150);
	printf("\n\n");
	printf("a : %d, b : %d\n", a, b);

	a = printf("%54.2ls", L"(null)");
	printf("\n\n");
	b = ft_printf("%54.2ls", L"(null)");
	printf("\n\n");
	printf("a : %d, b : %d\n", a, b);

/*
	a = printf("%4.15s", "42 is the answer");
	printf("\n\n");
	b = ft_printf("%4.15s", "42 is the answer"); //SEGFAULT PARFOIS DANS MOULITEST
	printf("\n\n");
	printf("a : %d, b : %d\n", a, b);
*/
/*
 * TESTS octal
 *
	a = printf("!%#-42zo!", 0);
	printf("\n\n");
	b = ft_printf("!%#-42zo!", 0);
	printf("\n\n");
	
	printf("a : %d, b : %d\n", a, b);
	printf("\n\n");

	a = printf("42%#02o42", 0);
	printf("\n\n");
	b = ft_printf("42%#02o42", 0);
	printf("\n\n");
	printf("a : %d, b : %d\n", a, b);
		
	
	a = printf("^.^/%0#42.32jo^.^/", 0);
	printf("\n\n");
	b = ft_printf("^.^/%0#42.32jo^.^/", 0);
	printf("\n\n");
	printf("a : %d, b : %d\n", a, b);


	a = printf("^.^/%0#37jo^.^/", -1279728248);
	printf("\n\n");
	b = ft_printf("^.^/%0#37jo^.^/", -1279728248);
	printf("\n\n");
	printf("a : %d, b : %d\n", a, b);

	a = printf("\\!/%-#41.2o\\!/", -1279728248);
	printf("\n\n");
	b = ft_printf("\\!/%-#41.2o\\!/", -1279728248);
	printf("\n\n");
	printf("a : %d, b : %d\n", a, b);

	a = printf("%#019.2o", -1279728248);
	printf("\n\n");
	b = ft_printf("%#019.2o", -1279728248);
	printf("\n\n");
	printf("a : %d, b : %d\n", a, b);
	a = printf("%#.o %#.0o", 0, 0);
	printf("\n\n");
	b = ft_printf("%#.o %#.0o", 0, 0);
	printf("\n\n");
	printf("a : %d, b : %d\n", a, b);
	

	a = printf("^.^/%#o^.^/", 0, 0);
	printf("\n\n");
	b = ft_printf("^.^/%#o^.^/", 0, 0);
	printf("\n\n");
	printf("a : %d, b : %d\n", a, b);


	a = printf("\\!/%-#2.1zo\\!/", 0);
	printf("\n\n");
	b = ft_printf("\\!/%-#2.1zo\\!/", 0);
	printf("\n\n");
	printf("a : %d, b : %d\n", a, b);
*/
	/* Unicode

	ft_printf("0x10ffff in long : %lld\n\n", 0x10ffff);
	ft_printf("0x40501 in long : %lld\n\n", 0x40501);
	ft_printf("0xd7ff in long : %lld\n\n", 0xd7ff);
	ft_printf("0xe000 in long : %lld\n\n", 0xe000);

	printf("\n\n");
	a = printf("%C", 0x11ffff);
	printf("\n\n");
	b = ft_printf("%C", 0x11ffff);
	printf("a : %d, b : %d\n", a, b);


	printf("\n\n");
	printf("\n\n");
	a = printf("%lc", 0x40501);
	printf("\n\n");
	b = ft_printf("%lc", 0x40501);
	printf("a : %d, b : %d\n", a, b);


	printf("\n\n");
	a = printf("%C", 0x11111);
	printf("\n\n");
	b = ft_printf("%C", 0x11111);
	printf("a : %d, b : %d\n", a, b);


	printf("\n\n");
	b = printf("%C", 0xbffe);
	printf("\n\n");
	b = ft_printf("%C", 0xbffe);
	printf("a : %d, b : %d\n", a, b);
	*/
	
		/*
	a = printf("%s%0.10d%p%%%S%D%i%o%O%u%U%x%X%c%C","bonjour", 42, &c, L"暖炉", LONG_MAX, 42, 42, 42, 100000, ULONG_MAX, 42, 42, 'c', L'플');
	printf("\n\n");
	b = ft_printf("%s%0.10d%p%%%S%D%i%o%O%u%U%x%X%c%C","bonjour", 42, &c, L"暖炉", LONG_MAX, 42, 42, 42, 100000, ULONG_MAX, 42, 42, 'c', L'플');
	printf("a: %d, b: %d", a, b);
	printf("\n\n");
	printf("\n\n");
	printf("\n\n");
	ft_printf("%100.20b\n", 15);

a = 	printf("%15.4s", "42 is the answer");
	printf("\n");
	printf("\n");
	b = ft_printf("%15.4s", "42 is the answer");
	printf("\n");
	printf("\n");
	ft_printf("a = %d, b = %d", a, b);
	printf("\n");
a = 	printf("%d %4.15s\n", a, "42 is the answer");
	ft_printf("%.5x", 1);
a = 	printf("%d %4.15s\n", a, "42 is the answer");
	printf("\n");
	printf("\n");
	ft_printf("%.24x", 12);
	printf("\n");
	printf("\n");
	ft_printf("%d", 123);
	printf("\n");
	printf("\n");
	ft_printf("%d", 1234);
	printf("\n");
	printf("\n");
	ft_printf("%d", 12345);
	printf("\n");
	printf("\n");
	ft_printf("%d", 123456);
	printf("\n");
	printf("\n");
	ft_printf("%d %d %d %d", 123456, 123456, 123456, 123456);
	printf("\n");
	printf("\n");
	ft_printf("%s", "eAKrIREtw rpkew ropewkrpkoe rpkepowrkpeowkrtpk");
	printf("%.5C", L'A');
	printf("\n");
	printf("%5C", L'A');
	printf("\n");
	printf("%5.5C", L'A');
	printf("\n");
	ft_printf("%5C", L'A');
	printf("\n");
	ft_printf("%5C", L'A');
	printf("\n");
	ft_printf("%55C", L'A');
	printf("\n");

	a = printf("%.2C", L'我');
	printf("\n\n");
	b = ft_printf("%.2C", L'我');
	ft_printf("\na:%d\nb:%d\n",a, b);
	printf("\n\n");
	printf("\n\n");
	ft_printf("%.4S", L"我是一只猫。");
	printf("\n\n");
	ft_printf("%15.4S", L"我是一只猫。");
	printf("\n\n");
	ft_printf("%4.15S", L"我是一只猫。");
	printf("\n\n");
	ft_printf("%4.S", L"我是一只猫。");
	printf("\n\n");
	ft_printf("%4.1S", L"Jambon");
	ft_printf("%.4s", "42 is the answer");
	printf("\n\n");
	ft_printf("%15.4s", "42");
	printf("\n\n");
	ft_printf("%15.4s", "I am 42");
	printf("\n\n");
	ft_printf("%15.4s", "42 is the answer");
	printf("\n\n");
	ft_printf("%4.15s", "42");
	printf("\n\n");
	ft_printf("%4.15s", "I am 42");
	printf("\n\n");
	ft_printf("%4.15s", "42 is the answer");
	printf("\n\n");
	ft_printf("%4.s", "42");
	printf("\n\n");
	ft_printf("%.4S", L"我是一只猫。");
	printf("\n\n");
	ft_printf("%15.4S", L"我是一只猫。");
	printf("\n\n");
	ft_printf("%4.15S", L"我是一只猫。");
	printf("\n\n");
	ft_printf("%4.S", L"我是一只猫。");
	printf("\n\n");
	ft_printf("%4.1S", L"Jambon");
	printf("\n\n");
	printf("\n\n");

	printf("%.4s", "42 is the answer");
	printf("\n\n");
	printf("%15.4s", "42");
	printf("\n\n");
	printf("%15.4s", "I am 42");
	printf("\n\n");
	printf("%15.4s", "42 is the answer");
	printf("\n\n");
	printf("%4.15s", "42");
	printf("\n\n");
	printf("%4.15s", "I am 42");
	printf("\n\n");
	printf("%4.15s", "42 is the answer");
	printf("\n\n");
	printf("%4.s", "42");
	printf("\n\n");
	printf("%.4S", L"我是一只猫。");
	printf("\n\n");
	printf("%15.4S", L"我是一只猫。");
	printf("\n\n");
	printf("%4.15S", L"我是一只猫。");
	printf("\n\n");
	printf("%4.S", L"我是一只猫。");
	printf("\n\n");
	printf("%4.1S", L"Jambon");
	printf("\n\n");
*/

/*
	printf("%.0p, %.p", 0, 0);
	printf("\n\n");
	ft_printf("%.0p, %.p", 0, 0);
	printf("\n\n");
	printf("%.0x, %.x", 0, 0);
	printf("\n\n");
	ft_printf("%.0x, %.x", 0, 0);
	a = printf("%s%0.10d%p%%%S%D%i%o%O%u%U%x%X%c%C","bonjour", 42, &c, L"暖炉", LONG_MAX, 42, 42, 42, 100000, ULONG_MAX, 42, 42, 'c', L'플');
	printf("\n\n");
	b = ft_printf("%s%0.10d%p%%%S%D%i%o%O%u%U%x%X%c%C","bonjour", 42, &c, L"暖炉", LONG_MAX, 42, 42, 42, 100000, ULONG_MAX, 42, 42, 'c', L'플');

*/	
	/*
	irintf("% u", 9999);
	printf("\n\n");
	ft_printf("% u", 9999);
	a = printf("%.4s\n", "abcdefgh");
	printf("a:%d\n",a);
	a = ft_printf("%.4s\n", "abcdefgh");
	printf("a:%d\n",a);

	printf("\n\n");
	a = printf("%.4s\n", NULL);
	printf("a:%d\n",a);
	a = ft_printf("%.4s\n", NULL);
	printf("a:%d\n",a);
	
	printf("\n\n");
	a = printf("%40s\n", "abcdefgh");
	printf("a:%d\n",a);
	a = ft_printf("%40s\n", "abcdefgh");
	ft_printf("a:%d\n",a);
	
	printf("\n\n");
	a = printf("%-40shi\n", "abcdefgh");
	printf("a:%d\n",a);
	a = ft_printf("%-40shi\n", "abcdefgh");
	ft_printf("a:%d\n",a);
	
	printf("\n\n");
	a = printf("%40S\n", L"abcdefgh");
	printf("a:%d\n",a);
	a = ft_printf("%40S\n", L"abcdefgh");
	ft_printf("a:%d\n",a);

	printf("\n\n");
	a = printf("%40ls\n", L"abcdefgh");
	printf("a:%d\n",a);
	a = ft_printf("%40ls\n", L"abcdefgh");
	ft_printf("a:%d\n",a);


	printf("\n\n");
	a = printf("%10.5ls\n", L"abcdefgh");
	printf("a:%d\n",a);
	a = ft_printf("%10.5ls\n", L"abcdefgh");
	ft_printf("a:%d\n",a);
*/
}
