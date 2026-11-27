#include "main.h"

/**
 * _putchar - écrit un caractère sur la sortie standard
 * @c: le caractère à écrire
 *
 * Return: 1 en cas de succès, -1 en cas d'erreur
 */
int _putchar(char c)
{
	/*
	 * write(descripteur, adresse, taille)
	 * 1 = sortie standard (stdout), &c = adresse du caractère,
	 * 1 = on écrit 1 octet. write retourne le nombre d'octets écrits.
	 */
	return (write(1, &c, 1));
}