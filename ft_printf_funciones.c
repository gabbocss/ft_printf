#include "ft_printf.h"

/*int imprimir_decimales(int decimales)
{
    int i;
    char    *nbr;

    i = 0;
    if (decimales < 0)
        decimales = -decimales;
    while(decimales)
    {
        nbr[i] = (decimales % 10) + '0';
        decimales /= 10;
        i++;
    }
    i = 1;
    while(i >= 0)
    {
        write(1, &nbr[i], 1);
        i--;
    }
    return (2);
}*/
/*int control_decimal(double num)
{
    int entero;
    int caracteres;
    int decimales;
    double numero_control;
    
    caracteres = 0;
    entero = num;
    numero_control = num - entero;
    if(numero_control != 0.0)
        {
            num *= 100;
            decimales = num;
            caracteres += ft_putnbr(entero);
            write(1, ".", 1);
            caracteres += imprimir_decimales(decimales);
            return (caracteres);
        }
    
    caracteres += ft_putnbr(entero);
    return(caracteres);
}*/
int	numeros_dos_cifras(long long num)
{
    char	nbr[11];
	int		i;
    int caracteres;

    caracteres = 0;
	i = 0;
    while (num != 0)
	{
        nbr[i] = (num % 10) + '0';
		num = num / 10;
		i++;
	} 
    nbr[i] = '\0';
    caracteres = i;
    while (--i >= 0)
	{
		write(1, &nbr[i], 1);
	}
    return (caracteres);
}

int	ft_putnbr(long long num)
{
	char	nbr;
    int caracteres;

    caracteres = 0;
	if (num == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	if (num < 0)
	{
		write(1, "-", 1);
		num = -num;
        caracteres++;
	}
	if (num >= 0 && num < 10)
	{
		nbr = num + '0';
		write(1, &nbr, 1);
        caracteres++;
        return (caracteres);
	}
	if (num >= 10)
		caracteres += numeros_dos_cifras(num);
    return (caracteres);
}

int numero_hex(unsigned int num, char c)
{
    char base_hex[16] = "0123456789abcdef";
    char bufer[16];
    int i;
    int caracteres;

    i = 0;
    caracteres = 0;
    if (c == 'X')
    {
        while (base_hex[i])
        {
            base_hex[i] = ft_toupper(base_hex[i]);
            i++;
        }
        i = 0;
    }
    while (num)
    {
        bufer[i] = base_hex[num % 16];
        num /= 16;
        i++;
    }
    bufer[i] = '\0';
    caracteres += ft_putstr_inverso(bufer, i);
    return (caracteres);
}

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 'a' + 'A');
	return (c);
}
int	ft_putstr_inverso(char *s, int i)
{
	int caracteres;
    
	caracteres = i;
	if (s == NULL)
		return (0);
    while (i >= 0)
	{
        write(1, &s[i], 1);
		i--;
	}
	return (caracteres);
}
int	ft_putstr(char *s)
{
	int caracteres;

	caracteres = 0;
	if (s == NULL)
		return (0);
	while (*s)
	{
		write(1, s, 1);
		caracteres++;
		s++;
	}
	return (caracteres);
}

int ft_putchar(char c)
{
	write(1, &c, 1);
	return 1;
}
int ft_puthex(void *c)
{
	unsigned long direccion = (unsigned long)c;
	char base_hex[] = "0123456789ABCDEF";
	char numero_hex[16];
	int contador;
	int caracteres;

	caracteres = 2;
	contador = 0;
	while(direccion)
	{
		numero_hex[contador] = base_hex[direccion % 16];
		direccion /= 16;
		contador++;
	}
	write(1, "0x", 2);
	numero_hex[contador] = '\0';
	contador--;
	while(contador >= 0)
	{
		write(1, &numero_hex[contador], 1);
		caracteres++;
		contador--;
	}
	return (caracteres);
}