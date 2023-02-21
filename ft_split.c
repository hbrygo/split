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

char	*ft_strdup(char *src, int end)
{
	int		i;
	char	*dest;
	int		j;

	i = 0;
	j = 0;
	while (src[i] && i < end)
		i++;
	dest = malloc(sizeof(char) * i);
	if (!dest)
		return (0);
	while (j < i)
	{
		dest[j] = src[j];
		j++;
	}
	dest[j] = '\0';
	return (dest);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
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
		if (j == ft_strlen(charset))
			count++;
		i++;
	}
	return (count);
}

char **ft_split(char *str, char *charset)
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
		printf("%d\n", len);
		//printf("%d", i);
		len++;

	}
	return (tab);
}

#include <stdio.h>
int	main()
{	
	int i = 0;
	char *str = "beep,boop, oi,he4ll";
	char *charset = ",";
	char **tab;
	tab = ft_split(str, charset);
	while (tab[i])
	{
		printf("%s\n",tab[i]);
		i++;
	}
}