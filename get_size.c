#include "main.h"

/**
* get_size - Calc the size to cast the arg
* @format: Form str in which to prompt args
* @i: Ls of args to be prompted
* Return: Precision.
*/
int get_size(const char *format, int *i)
{
	int actu_i = *i + 1;
	int size = 0;

	if (format[actu_i] == 'l')
		size = S_LONG;
	else if (format[actu_i] == 'h')
		size = S_SHORT;
	if (size == 0)
		*i = actu_i - 1;
	else
		*i = actu_i;
	return (size);
}
