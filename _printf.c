#include "holberton.h"
#include <stdio.h>
#include <stdarg.h>
/**
 * _printf - Modified Printf function that produces output with format.
 * @format: references to the desired format to be Printed.
 * Return: length of string.
 */

int _printf(const char *format, ...)
{
	va_list args;

	va_start(args, format);

	int count = 0;

	while (*format != '\0')

	{
		if (*format == '%')

		{
			if (*(format + 1) == '%')
			{
				char c = '%';

				write(1, &c, 1);
				format++;
				count++;
			}

			if (*(format + 1) == 'c')
			{
				char st = va_arg(args, int);

				write(1, &st, 1);
				format++;
				count++;

			}

			if (*(format + 1) == 's')
			{

				char *string;
				int i;

				string = va_arg(args, char *);

				if (string == NULL)
				{
					string = "(null)";
				}

				for (i = 0; string[i] != '\0'; i++)
				{

					write(1, string + i, 1);
					count++;

				}

				format++;
			}
		}

		else
		{
			write(1, format, 1);
			count++;

		}

		++format;
	}

	va_end(args);

	return (count);
}


		}
	}
}
