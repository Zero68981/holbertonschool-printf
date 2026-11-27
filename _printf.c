#include "main.h"

/**
 * _printf - version simplifiée de printf (gère %c, %s, %%, %d et %i)
 * @format: chaîne de format, ex. "Bonjour %s, tu as %d ans\n"
 *
 * Return: nombre de caractères affichés, -1 en cas d'erreur
 */
int _printf(const char *format, ...)
{
/* va_list : "boîte" qui contiendra les arguments variables (après format) */
va_list args;

/* i : position dans format | count : nb de caractères affichés | j : position dans une chaîne %s */
int i = 0, count = 0, j;
char *str;

/* Si format est NULL, on ne peut rien faire : erreur */
if (format == NULL)
return (-1);

/* Initialise args : les arguments variables commencent après "format" */
va_start(args, format);

/* On parcourt format jusqu'au caractère de fin de chaîne '\0' */
while (format[i] != '\0')
{
/* Cas 1 : caractère normal (pas un '%') -> on l'affiche tel quel */
if (format[i] != '%')
{
count += _putchar(format[i]);
}
/* Cas 2 : on a rencontré un '%', le caractère suivant dit quoi faire */
else
{
i++; /* on passe au caractère après le '%' */

/* Format qui se termine par un '%' seul : invalide */
if (format[i] == '\0')
{
va_end(args); /* toujours libérer args avant de quitter */
return (-1);
}

/* %c : on affiche UN caractère (char promu en int via "...") */
if (format[i] == 'c')
count += _putchar(va_arg(args, int));

/* %s : on affiche une chaîne de caractères */
else if (format[i] == 's')
{
str = va_arg(args, char *);

/* Comme le vrai printf : NULL s'affiche "(null)" */
if (str == NULL)
str = "(null)";

for (j = 0; str[j] != '\0'; j++)
count += _putchar(str[j]);
}

/* %% : on affiche un seul '%' */
else if (format[i] == '%')
count += _putchar('%');

/* %d ou %i : on affiche un entier signé en base 10 */
else if (format[i] == 'd' || format[i] == 'i')
/* va_arg(args, int) récupère l'argument suivant comme un int,
* print_int s'occupe du signe et des chiffres */
count += print_int(va_arg(args, int));

/* Spécificateur inconnu (ex. %z) : on l'affiche tel quel */
else
{
count += _putchar('%');
count += _putchar(format[i]);
}
}

i++; /* on avance au caractère suivant de format */
}

/* Termine proprement l'utilisation des arguments variables */
va_end(args);

/* Retourne le total de caractères affichés, comme le vrai printf */
return (count);
}
