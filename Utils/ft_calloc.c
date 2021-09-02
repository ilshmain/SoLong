#include "../include/so_long.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*buf;

	buf = (void *)malloc(count * size);
	if (buf == NULL)
		return (NULL);
	ft_memset(buf, 0, count * size);
	return (buf);
}
