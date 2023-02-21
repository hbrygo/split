/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hubrygo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 17:54:16 by hubrygo           #+#    #+#             */
/*   Updated: 2023/02/20 16:26:42 by hubrygo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include<stdio.h>
#include<stdlib.h>

int	next_sep(char *str, char *charset)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		j = 0;
		while (charset[j])
		{
			if (str[i] == charset[j])
				return (i);
			j++;
		}
		i++;
	}
	return (0);
}

char	*ft_strdup(char *src, int start, int end)
{
	char	*dest;
	int		j;

	j = 0;
	dest = malloc(sizeof(char) * (end - start) + 1);
	if (!dest)
		return (0);
	while (j < end - start)
	{
		dest[j] = src[j];
		j++;
	}
	dest[j] = '\0';
	return (dest);
}

int	ft_strlen(char *str, int i)
{
	while (str[++i])
		;
	return (i);
}

int num_of_sep(char *str, char *charset)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	j = 0;
	count = 0;
	while (str[i])
	{
		j = 0;
		if (str[i] == charset[j])
		{
			while (str[i + j] && str[i + j] == charset[j])
				j++;
		}
		if (j == ft_strlen(charset, -1))
			count++;
		i++;
	}
	return (count);
}
//i[0] = sep
//i[1] = i
//i[2] = j
//i[3] = len

char **ft_split(char *str, char *charset)
{
	int	i[4];
	char	**tab;
	int	count;

	count = 0;
	i[2] = 0;
	i[3] = 0;
	i[0] = num_of_sep(str, charset);
	tab = malloc(sizeof(char *) * (i[0] + 1));
	if(!tab)
		return (NULL);
	while (i[2] < ft_strlen(str, -1))
	{
		i[1] = i[2];
		i[2] = next_sep(str, charset);
		if (i[2] == 0)
			return (tab);
		tab[i[3]] = ft_strdup(str, i[1], i[2]);
		i[3]++;
		i[2]++;
	}
	return (tab);
}

/*char **ft_split(char *str, char *charset)
{
	int	sep;
	char	**tab;
	int	i;
	int	j;
	int	len;

	i = 0;
	len = 0;
	sep = num_of_sep(str, charset);
	tab = malloc(sizeof(char) * (sep + 1));
	if (!tab)
		return (NULL);
	while (str[i])
	{
		j = 0;
		while (str[len + j] == charset[j] && str[len + j] && charset[j])
			j++;
		if (j == (ft_strlen(charset)))
		{
			tab[i] = ft_strdup(&str[i], len);
			len += j;
			i +=len + 1;
		}
		//printf("%d\n", len);
		//printf("%d", i);
		len++;

	}
	return (tab);
}
*/
#include <stdio.h>
int	main()
{	
	int i = 0;
	char *str = "beep,boop, oi,he4ll";
	char *charset = " ";
	char **tab;
	tab = ft_split(str, charset);
	while (tab[i])
	{
		printf("%s\n",tab[i]);
		i++;
	}
}