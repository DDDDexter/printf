#include "main.h"

/**
* get_flags - Calc active -f
* @format: Form str in which to prompt the args
* @i: take a param
* Return: Flags
* from morocco to ethiopia
*/
int get_flags(const char *format, int *i)
{
	/* - + 0 # ' ' */
	/* 1 2 4 8  16 */
	int z, actu_i;
	int flags = 0;
	const char FLAGS_CH[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAGS_ARR[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

	for (actu_i = *i + 1; format[actu_i] != '\0'; actu_i++)
	{
		for (z = 0; FLAGS_CH[z] != '\0'; z++)
			if (format[actu_i] == FLAGS_CH[z])
			{
				flags |= FLAGS_ARR[z];
				break;
			}

		if (FLAGS_CH[z] == 0)
			break;
	}

	*i = actu_i - 1;

	return (flags);
}
