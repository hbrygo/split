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
#include <stdio.h>
#include <stdlib.h>

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

int	num_of_sep(char *str, char *charset)
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

// char **ft_split(char *str, char *charset)
// {
// 	int i[4];
// 	char **tab;
// 	int count;

// 	count = 0;
// 	i[2] = 0;
// 	i[3] = 0;
// 	i[0] = num_of_sep(str, charset);
// 	tab = malloc(sizeof(char *) * (i[0] + 1));
// 	if (!tab)
// 		return (NULL);
// 	while (i[2] < ft_strlen(str, -1))
// 	{
// 		i[1] = i[2];
// 		i[2] = next_sep(str, charset);
// 		if (i[2] == 0)
// 			return (tab);
// 		tab[i[3]] = ft_strdup(str, i[1], i[2]);
// 		i[3]++;
// 		i[2]++;
// 	}
// 	return (tab);
// }

//a[0] = i
//a[1] = sep
//a[2] = j
//a[3] = len
//a[4] = bool
//a[5] = a
char	**ft_split(char *str, char *charset)
{
	char	**tab;
	int		a[6];

	a[0] = 0;
	a[5] = 0;
	a[4] = 0;
	a[3] = 0;
	a[1] = num_of_sep(str, charset);
	tab = malloc(sizeof(char *) * (a[1] + 2));
	if (!tab)
		return (NULL);
	while (str[a[0]])
	{
		a[2] = -1;
		while (charset[++a[2]])
			if (str[a[0]] == charset[a[2]])
				a[4] = 1;
		if (a[4])
		{
			if (a[3] <= 0)
				tab[a[5]] = ft_strdup(&str[0], 0, a[0]);
			else
				tab[a[5]] = ft_strdup(&str[a[3]], a[3], a[0]);
			a[5]++;
			a[3] = a[0] + 1;
		}
		a[0]++;
		a[4] = 0;
	}
	tab[a[5]] = ft_strdup(&str[a[3]], a[3], a[0]);
	return (tab);
}

#include <stdio.h>
int main(int argc, char **argv)
{
	int i = 0;
	char *str = "beep,boop, oi,he4ll";
	char *charset = ",";
	char **tab;
	tab = ft_split(str, charset);
	while (tab[i])
	{
		printf("%s\n", tab[i]);
		i++;
	}
}
