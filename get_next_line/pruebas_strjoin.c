#include <stdio.h>
#include <stdlib.h>

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_free(char **buf)
{
	free (*buf);
	*buf = NULL;
	return (NULL);
}

char	*ft_strjoin(char *rest_buf, char *buf)
{
	char	*sr;
	size_t	i;
	size_t	c;

	i = -1;
	c = -1;
	if (!rest_buf)
	{
		rest_buf = (char *)malloc(1 * sizeof(char));
		if (!rest_buf)
			return (ft_free(&rest_buf));
		rest_buf[0] = '\0';
	}
	sr = (char *)malloc((ft_strlen(rest_buf) + ft_strlen(buf) + 1) \
		* sizeof(char));
	if (!sr)
		return (ft_free(&sr));
	while (rest_buf[++i])
		sr[i] = rest_buf[i];
	while (buf[++c])
		sr[i + c] = buf[c];
	sr[ft_strlen(rest_buf) + ft_strlen(buf)] = '\0';
	return (sr);
}

int	main(void)
{
	printf("%s", ft_strjoin("2409876543\n", "456"));
	return (0);
}
