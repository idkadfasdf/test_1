/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylau-sim <ylau-sim@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 14:16:52 by ylau-sim          #+#    #+#             */
/*   Updated: 2026/04/22 11:33:14 by ylau-sim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*new;
	int		i;

	if (s == NULL)
		return (NULL);
	i = 0;
	while (s[i])
		i++;
	new = malloc(i + 1);
	if (new == NULL)
		return (NULL);
	new[i] = '\0';
	i = 0;
	while (s[i])
	{
		new[i] = s[i];
		i++;
	}
	return (new);
}

/*#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main() {

    const char * original = "The original string.";

    // On duplique la chaîne de caractères initiale.
    char * copy = ft_strdup( original );

    // On passe chaque lettre en majuscule.
    char * ptr = copy;
    while( *ptr != '\0' ) {
        *ptr = toupper( *ptr );
        ptr++;
    }

    // On affiche la chaîne finale
    printf( "%s\n", copy );

    // Sans oublier de libérer l'espace mémoire au final.
    free( copy );

    return EXIT_SUCCESS;
}*/
