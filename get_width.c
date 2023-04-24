#include "main.h"
/**
* get_width - Calc the wd for prompting
* @format: Form str in which to prompt the args
* @i: Ls of args to be prompted
* @list: ls of args
* Return: width.
*/
int get_width(const char *format, int *i, va_list list)
{
	int actu_i;
	int width = 0;

	for (actu_i = *i + 1; format[actu_i] != '\0'; actu_i++)
	{
		if (is_digit(format[actu_i]))
		{
			width *= 10;
			width += format[actu_i] - '0';
		}
		else if (format[actu_i] == '*')
		{
			actu_i++;
			width = va_arg(list, int);
			break;
		}
		else
			break;
	}
	*i = actu_i - 1;
	return (width);
}
