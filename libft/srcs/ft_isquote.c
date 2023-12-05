
#include "../../includes/libft.h"

int	ft_isquote(int c)
{
	if (c == 34 || c == 39)
		return (1);
	else
		return (0);
}
