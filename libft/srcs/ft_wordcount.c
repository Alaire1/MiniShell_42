
#include "../../includes/libft.h"

int	ft_wordcount(const char *str, char c)
{
	int	i;
	int	wordcount;

	i = 0;
	wordcount = 0;
	while (str[i])
	{
		while (str[i] && str[i] == c)
			i++;
		if (str[i])
			wordcount++;
		while (str[i] && str[i] != c)
			i++;
	}
	return (wordcount);
}
