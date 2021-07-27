#include "holberton.h"
#include <stdio.h>
#include <stdarg.h>
#include <limits.h>
/**
 * _printf - Modified Printf function that produces output with format.
 * @format: references to the desired format to be Printed.
 * Return: length of string.
 */

int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;

	va_start(args, format);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			if (*(format + 1) == '%')
			{
				char c = '%';

				print_char(&c, &format, &count);
			}
			if (*(format + 1) == 'c')
			{
				char st = va_arg(args, int);

				print_char(&st, &format, &count);
			}
			if (*(format + 1) == 's')
			{
				char *string;
				int i;

				string = va_arg(args, char *);

				print_string(string, &count);
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
/**
 * print_string - func that prints a string.
 * @string: declaration of string pointer with a value to be printed.
 * @counter: an int counter for the string.
 * Return: no value.
 */
void print_string(char *string, int *counter)
{
	int strcount = 0;

	if (string == NULL)
	{
		string = "(null)";
	}
	for (int i = 0; string[i] != '\0'; i++)
	{
		write(1, string + i, 1);
		strcount++;
	}
	*counter = *counter + strcount;

}
/**
 * print_char - func that prints a character.
 * @ch: the character to be printed.
 * @inc1: a value to be incremented for formatting.
 * @inc2: a value to be incremented for counting.
 * Return: no value.
 */
void print_char(char *ch, int *inc1, int *inc2)
{
	write(1, ch, 1);
	*inc1 = *inc1 + 1;
	*inc2 = *inc2 + 1;
}

		}
	}
}
