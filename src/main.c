#include "hotrace.h"

int ft_strlen(char *str)
{
    int i;

    i = 0;
    while (str[i]) {
	i++;
    }
    return (i);
}

int ft_strncmp(const char *s1, const char *s2, size_t n)
{
    size_t i;
    unsigned char *t1;
    unsigned char *t2;

    t1 = (unsigned char *)s1;
    t2 = (unsigned char *)s2;
    i = 0;
    while (i < n) {
	if (t1[i] != t2[i])
	    return (t1[i] - t2[i]);
	if (t1[i] == '\0')
	    return (0);
	i++;
    }
    return (0);
}

int main(int argc, char const **argv) { return 0; }
