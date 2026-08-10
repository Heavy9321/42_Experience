#include <string.h>
#include "libft.h"
char *ft_strdup(const char *s1)
{
    	int i;
	char *str;

	str = malloc(ft_strlen(s1) + 1);
	i = 0;
	if (!str)
	    return (NULL);
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
