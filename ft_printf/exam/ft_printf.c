#include <stdarg.h>
#include <unistd.h>

int is_specifier(char *format) {
	if (format[0] != '%')
		return 0;
	if (format[1] == 's' || format[1] == 'd' || format[1] == 'x')
		return 1;
	return 0;
}

int put_string(char *str) {
	if (!str)
		str = "(null)";
	int len = 0;
	while (str[len]) {
		write(1, str + len++, 1);
	}
	return len;
}

int put_number(long long num, int base) {
	char *numbers = "0123456789abcdef";
	int len = 0;
	if (num < 0) {
		num *= -1;
		len += write(1, "-", 1);
	}
	if (num >= base) {
		len += put_number(num/base, base);
	}
	len += write(1, numbers + num%base, 1);
	return len;
}

int ft_printf(const char *format, ...) {
	va_list	ap;
	int len = 0;

	va_start(ap, format);
	while (*format) {
		if (is_specifier(format)) {
			format++;
			if (*format == 's')
				len += put_string(va_arg(ap, char *));
			else if (*format == 'd')
				len += put_number(va_arg(ap, int), 10);
			else
				len += put_number(va_arg(ap, unsigned int), 16);
		} else {
			len += write(1, format++, 1);
		}
		format++;
	}
	return (len);
}