
#include "push_swap.h"

int	ft_isdigit(int c)
{
	return (c >= 48 && c <= 57);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	res;

	i = 0;
	res = 0;
	sign = 1;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] && ft_isdigit(str[i]))
	{
		res = res * 10 + (str[i] - 48);
		i++;
	}
	return (res * sign);
}

static int	count_word(const char *s, char c)
{
	int		counter;
	size_t	i;
	int		found;

	found = 0;
	counter = 0;
	i = 0;
	while (i <= ft_strlen(s))
	{
		if ((s[i] == c || s[i] == '\0') && found)
		{
			counter++;
			found = 0;
		}
		if (s[i] != c && !found)
			found = 1;
		i++;
	}
	return (counter);
}

static int	len(const char *s, char c)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

char	**ft_split(const char *s, char c)
{
	int		counter;
	char	**words;

	counter = 0;
	words = (char **)malloc(sizeof(char *) * (count_word(s, c) + 1));
	if (!words)
		return (NULL);
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s && *s != c)
		{
			words[counter] = ft_substr(s, 0, len(s, c));
			counter++;
			while (*s && *s != c)
				s++;
		}
	}
	words[counter] = 0;
	return (words);
}


char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	if (start + len > ft_strlen(s))
		len = ft_strlen(s) - start;
	substr = malloc(sizeof(char) * (len + 1));
	if (!substr)
		return (NULL);
	ft_memcpy(substr, s + start, len);
	substr[len] = '\0';
	return (substr);
}

char	*ft_strdup(const char *s1)
{
	char	*copy;
	int		size;
	int		i;

	i = 0;
	size = ft_strlen(s1) + 1;
	copy = malloc(sizeof(char) * size);
	if (!copy)
		return (NULL);
	while (s1[i])
	{
		copy[i] = s1[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		size;

	size = ft_strlen(s1) + ft_strlen(s2);
	str = malloc(sizeof(char) * (size + 1));
	if (!str)
		return (NULL);
	ft_memcpy(str, s1, ft_strlen(s1));
	ft_memcpy(str + ft_strlen(s1), s2, ft_strlen(s2));
	str[size] = '\0';
	return (str);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;

	if (src || dst)
	{
		i = 0;
		while (i < n)
		{
			((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
			i++;
		}
	}
	return (dst);
}


static int	char_in_set(const char *set, char c)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int	i;
	int	j;

	j = ft_strlen(s1) - 1;
	i = 0;
	while (s1[i])
	{
		if (!char_in_set(set, s1[i]))
			break ;
		i++;
	}
	while (j >= i)
	{
		if (!char_in_set(set, s1[j]))
			break ;
		j--;
	}
	return (ft_substr(s1, i, j - i + 1));
}

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (s)
	{
		while (s[i])
		{
			ft_putchar_fd(s[i], fd);
			i++;
		}
	}
}

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}