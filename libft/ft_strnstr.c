#include <string.h>

char *strnstr(const char *haystack, const char *needle, size_t len)
{
	unsigned int h;
	unsigned int n;

	h = 0;
	if (*needle == '\0' && len > 0)
	    return ((char *)haystack);
	while (haystack[h] != '\0')
	{
	    n = 0;
	    while ((haystack[h + n] != '\0' && haystack[h + n] == needle[n]) && len > h + n)
	    {
		if (needle[n + 1] == '\0')
		    return ((char *)&haystack[h]);
		    n++;
	    }
	    h++;
	}
	return (NULL);
}
