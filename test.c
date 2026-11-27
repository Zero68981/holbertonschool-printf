#include "main.h"
#include <limits.h>

int main(void)
{
	int len;

	len = _printf("Entier : %d, negatif : %i, zero : %d\n", 1234, -56, 0);
	_printf("Longueur : %d\n", len);
	_printf("INT_MAX : %d\n", INT_MAX);
	_printf("INT_MIN : %i\n", INT_MIN);
	return (0);
}
