#include "main.h"

/** PRINT CHAR **/

/**
* print_char - Prompt  char
* @types: Ls  of args
* @buffer: Buff arr to handle print
* @flags:  Calc active -f
* @width: Wd
* @precision: Precision specification
* @size: Size specifier
* Return: Num of chars prompted
* from morocco to to ethiopia
*/
int print_char(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char l = va_arg(types, int);

	return (handle_write_char(l, buffer, flags, width, precision, size));
}
/** PRINT A STRING **/
/**
* print_string - Prompt str
* @types: Ls a of args
* @buffer: Buff arr to handle print
* @flags:  Calc active -f
* @width: get wd
* @precision: Precision specification
* @size: Size specifier
* Return: Num of chars prompted
*/
int print_string(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int len = 0, z;
	char *str = va_arg(types, char *);

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	if (str == NULL)
	{
		str = "(null)";
		if (precision >= 6)
			str = "      ";
	}

	while (str[len] != '\0')
		len++;

	if (precision >= 0 && precision < len)
		len = precision;

	if (width > len)
	{
		if (flags & F_MINUS)
		{
			write(1, &str[0], len);
			for (z = width - len; z > 0; z--)
				write(1, " ", 1);
			return (width);
		}
		else
		{
			for (z = width - len; z > 0; z--)
				write(1, " ", 1);
			write(1, &str[0], len);
			return (width);
		}
	}

	return (write(1, str, len));
}
/** PRINT PERCENT SIGN **/
/**
* print_percent - Prompts a percent sign
* @types: Ls of args
* @buffer: Buff arr to handle print
* @flags:  Calcu active -f
* @width: get wd.
* @precision: Precision specification
* @size: Size specifier
* Return: Num of chars printed
*/
int print_percent(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	UNUSED(types);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	return (write(1, "%%", 1));
}

/** PRINT INT **/
/**
* print_int - Prompt int
* @types: Ls of args
* @buffer: Buff arr to handle print
* @flags:  Calcu active -f
* @width: get wd
* @precision: Precision specification
* @size: Size specifier
* Return: Num of chars printed
*/
int print_int(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int z = BUFF_SIZE - 2;
	int is_negative = 0;
	long int x = va_arg(types, long int);
	unsigned long int num;

	x = convert_size_number(x, size);

	if (x == 0)
		buffer[z--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';
	num = (unsigned long int)x;

	if (x < 0)
	{
		num = (unsigned long int)((-1) * x);
		is_negative = 1;
	}

	while (num > 0)
	{
		buffer[z--] = (num % 10) + '0';
		num /= 10;
	}

	z++;

	return (write_number(is_negative, z, buffer, flags, width, precision, size));
}

/** PRINT BINARY **/
/**
* print_binary - Prompt an unsigned number
* @types: Ls of args
* @buffer: Buff arr to handle print
* @flags:  Calc active -f
* @width: get wd
* @precision: Precision specification
* @size: Size specifier
* Return: Num of char printed.
*/
int print_binary(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	unsigned int n, m, z, sum;
	unsigned int a[32];
	int count;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	n = va_arg(types, unsigned int);
	m = 2147483648; /* (2 ^ 31) */
	a[0] = n / m;
	for (z = 1; z < 32; z++)
	{
		m /= 2;
		a[z] = (n / m) % 2;
	}
	for (z = 0, sum = 0, count = 0; z < 32; z++)
	{
		sum += a[z];
		if (sum || z == 31)
		{
			char y = '0' + a[z];

			write(1, &y, 1);
			count++;
		}
	}
	return (count);
}
