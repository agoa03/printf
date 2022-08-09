#include <stdarg.h>
#include "main.h"
#include <stdio.h>
int _printf(const char *format, ...)
{
	int i=0, count = 0;

	va_list args;

	char *p, *str;

	va_start(args, format);

	for(p = format; *p != '\0'; p++)
	{
		if(*p != '%')
		{
		 count ++;
		 continue;	
		}
		switch (*++p)
		{
		case 'c':
		
			count += 1;
			
			break;
		case 'd':

			for (i = va_arg(args, int); i > 0; count++)
			i /= 10;

		case 'i':
			for (i = va_arg(args, int); i > 0; count++)
			i /= 10;

			break;
		case 's':
			for (str = va_arg(args, char *); *str != '\0'; str++)
			count += 1;
	
			break;
		case '%':
			
			}
		}
		va_end(args);
		return (count);
}
