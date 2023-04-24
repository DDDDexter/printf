#include "main.h"

void print_buffer(char buffer[], int *buff_ind);

/**
* _printf - Printf func
* @format: fm
* Return: Prompted chars
* from morocco to ethiopia
*/
int _printf(const char *format, ...)
{
	int i, printed = 0, printed_chars = 0;
	int flags, width, precision, size, buff_ind = 0;
	va_list ls;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(ls, format);

	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			buffer[buff_ind++] = format[i];
			if (buff_ind == BUFF_SIZE)
				print_buffer(buffer, &buff_ind);
			/* write(1, &format[i], 1);*/
			printed_chars++;
		}
		else
		{
			print_buffer(buffer, &buff_ind);
			flags = get_flags(format, &i);
			width = get_width(format, &i, ls);
			precision = get_precision(format, &i, ls);
			size = get_size(format, &i);
			++i;
			printed = handle_print(format, &i, ls, buffer,
				flags, width, precision, size);
			if (printed == -1)
				return (-1);
			printed_chars += printed;
		}
	}

	print_buffer(buffer, &buff_ind);

	va_end(ls);

	return (printed_chars);
}

/**
* print_buffer - Prompts the contents of the buff if it exist
* @buffer: Arr of chars
* @buff_ind: I at which to add next char, represents the len
*/
void print_buffer(char buffer[], int *buff_ind)
{
	if (*buff_ind > 0)
		write(1, &buffer[0], *buff_ind);

	*buff_ind = 0;
}
