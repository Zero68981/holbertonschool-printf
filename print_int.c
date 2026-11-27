#include "main.h"

/**
 * print_int - affiche un entier en base 10 (pour %d et %i)
 * @n: l'entier à afficher
 *
 * Return: nombre de caractères affichés
 */
int print_int(int n)
{
int count = 0;
/*
* On travaille avec un unsigned int pour gérer INT_MIN (-2147483648).
* Si on faisait -n directement sur INT_MIN, ça déborderait,
* car +2147483648 ne rentre pas dans un int.
*/
unsigned int num;
unsigned int diviseur = 1;

/* Si le nombre est négatif : on affiche '-' puis on travaille sur sa valeur positive */
if (n < 0)
{
count += _putchar('-');
num = -(unsigned int)n; /* conversion sûre de la valeur absolue */
}
else
num = n;

/*
* On cherche la plus grande puissance de 10 inférieure ou égale à num.
* Ex. : num = 1234 -> diviseur = 1000
* La condition num / diviseur >= 10 évite de dépasser la limite d'un unsigned int.
*/
while (num / diviseur >= 10)
diviseur *= 10;

/*
* On affiche chiffre par chiffre, du plus à gauche au plus à droite.
* Ex. : 1234 -> 1234/1000 = 1 ;
* reste 234 -> 234/100 = 2 ; etc.
*/
while (diviseur > 0)
{
/* (num / diviseur) % 10 donne le chiffre courant ;
* + '0' le convertit en caractère
*/
count += _putchar((num / diviseur) % 10 + '0');
diviseur /= 10; /* on passe au chiffre suivant */
}

return (count);
}
