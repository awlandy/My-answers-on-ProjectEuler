/*If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9.
The sum of these multiples is 23.
Find the sum of all the multiples of 3 or 5 below 1000.
Answer : 233168																						*/

//#include "pch.h"
#include <stdio.h>

int main()
{
	long long sum = 0;
	long long i = 0;
	while (1) {
		if ((i % 3 == 0) || (i % 5 == 0)) {
			sum += i;
		}
		if (i == 999)
			break;
		++i;
	}
	printf("%lld\n", sum);
	return 0;
}
