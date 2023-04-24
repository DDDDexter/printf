#include "main.h"

/**
* get_precision - Calc the precision for prompting
* @format: Forma str in which to prompt the args
* @i: Ls of args to be prompted.
* @list: ls of args
* Return: Precision.
* from morocco to ethiopia
*/
int get_precision(const char *format, int *i, va_list list)
{
	int actu_i = *i + 1;
	int precision = -1;

	if (format[actu_i] != '.')
		return (precision);

	precision = 0;

	for (actu_i += 1; format[actu_i] != '\0'; actu_i++)
	{
		if (is_digit(format[actu_i]))
		{
			precision *= 10;
			precision += format[actu_i] - '0';
		}
		else if (format[actu_i] == '*')
		{
			actu_i++;
			precision = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*i = actu_i - 1;

	return (precision);
}
