
#include "ft_printf.h"

int	control(char copia, va_list args)
{
	int caracteres;

	caracteres = 0;
	if (copia == 'c')
		caracteres = ft_putchar(va_arg(args, int));
	else if (copia == 's')
		caracteres = ft_putstr(va_arg(args, char *));
	else if (copia == 'p')
		caracteres += ft_puthex(va_arg(args, void *));
		else if (copia == 'i' || copia == 'd')
		caracteres += ft_putnbr(va_arg(args, int));
	else if (copia == 'u')
		caracteres += ft_putnbr(va_arg(args, unsigned int));
	else if (copia == 'x' || copia == 'X')
		caracteres += numero_hex(va_arg(args, unsigned int), copia);
	else if (copia == '%')
		caracteres += ft_putchar('%');
	else
		caracteres += ft_putchar(copia);
	return (caracteres);
}
int ft_printf(char const *linea, ...)
{
	va_list args;
	va_start(args, linea);
	const char *copia;
	int caracteres;
	

	copia = linea;
	caracteres = 0;
	while(*copia)
	{
		if (*copia == '%')
		{
			copia++;
			caracteres +=control(*copia, args);
		}
		else
		{
			write(1, copia, 1);
			caracteres++;
		}
		copia++;	
	}
		
		
	return (caracteres);
}

/*int main()
{
	char nbr = '%';
	//char *puntero = nbr;
	int caracteres;
	int caracteres2;
	caracteres = ft_printf("hola% kola\n", nbr);
	caracteres2 = printf("hola% kola\n", nbr);
	printf("ft_printf ---> %i\nprintf---> %i", caracteres, caracteres2);
}*/