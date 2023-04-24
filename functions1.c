#include "main.h"
/** PRINT UNSIGNED NUMBER **/
/**
* print_unsigned - Prompts an unsigned num
* @types: Ls a of args
* @buffer: Buff arr to handle prompt
* @flags:  Calc active -f
* @width: get wd
* @precision: Precision specification
* @size: Size specifier
* Return: Num of chars prompted.
*/
int print_unsigned(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int z = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[z--] = '0';
	buffer[BUFF_SIZE - 1] = '\0';
	while (num > 0)
	{
		buffer[z--] = (num % 10) + '0';
		num /= 10;
	}
	z++;
	return (write_unsgnd(0, z, buffer, flags, width, precision, size));
}
/** PRINT UNSIGNED NUMBER IN OCTAL  **/
/**
* print_octal - Prompts an unsigned num in octal notation
* @types: Ls of args
* @buffer: Buff arr to handle prompt
* @flags:  Calc active -f
* @width: get wd
* @precision: Precision specification
* @size: Size specifier
* Return: Num of chars prompted
*/
int print_octal(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int z = BUFF_SIZE - 2;

	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[z--] = '0';
	buffer[BUFF_SIZE - 1] = '\0';
	while (num > 0)
	{
		buffer[z--] = (num % 8) + '0';
		num /= 8;
	}
	if (flags & F_HASH && init_num != 0)
		buffer[z--] = '0';
	z++;
	return (write_unsgnd(0, z, buffer, flags, width, precision, size));
}
/** PRINT UNSIGNED NUMBER IN HEXADECIMAL **/
/**
* print_hexadecimal - Prompts an unsigned num in hexadecimal notation
* @types: Ls of args
* @buffer: Buff arr to handle print
* @flags:  Calc active -f
* @width: get wd
* @precision: Precision specification
* @size: Size specifier
* Return: Num of chars prompted
*/
int print_hexadecimal(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789abcdef", buffer,
		flags, 'x', width, precision, size));
}
/** PRINT UNSIGNED NUMBER IN UPPER HEXADECIMAL **/
/**
* print_hexa_upper - Prompts an unsigned num in upper hexadecimal notation
* @types: Lts of args
* @buffer: Buff arr to handle prompt
* @flags:  Calc active -f
* @width: get wd
* @precision: Precision specification
* @size: Size specifier
* Return: Num of chars prompted
*/
int print_hexa_upper(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789ABCDEF", buffer,
		flags, 'X', width, precision, size));
}
/** PRINT HEXX NUM IN LOWER OR UPPER **/
/**
* print_hexa - Prompt a hexadecimal numb in lower or upper
* @types: Ls of args
* @map_to: Arr of val to map the numb to
* @buffer: Buff arr to handle prompt
* @flags:  Calc active -f
* @flag_ch: Calcu active -f
* @width: get wd
* @precision: Precision specification
* @size: Size specifier
* @size: Size specification
* Return: Numb of chars prompted
*/
int print_hexa(va_list types, char map_to[], char buffer[],
	int flags, char flag_ch, int width, int precision, int size)
{
	int z = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[z--] = '0';
	buffer[BUFF_SIZE - 1] = '\0';
	while (num > 0)
	{
		buffer[z--] = map_to[num % 16];
		num /= 16;
	}
	if (flags & F_HASH && init_num != 0)
	{
		buffer[z--] = flag_ch;
		buffer[z--] = '0';
	}
	z++;
	return (write_unsgnd(0, z, buffer, flags, width, precision, size));
}
