/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viduvern <viduvern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 16:07:35 by viduvern          #+#    #+#             */
/*   Updated: 2019/03/31 15:49:38 by viduvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	**ft_unsetloc(char **envd, char **str)
{
	char	**tab;
	int		i;
	int		l;

	i = 0;
	l = 0;
	while (envd[i])
		i++;
	tab = (char**)malloc(sizeof(char*) * i);
	i = 0;
	while (envd[i])
	{
		if (ft_strnstr(envd[i], str[1], ft_strlen(str[1])))
			i++;
		else
		{
			tab[l] = ft_strdup(envd[i]);
			i++;
			l++;
		}
	}
	tab[i] = 0;
	return (tab);
}

int		ft_parse_unset(char **envd, char **str)
{
	int i;

	i = 0;
	if (!str[1])
		return (0);
	while (envd[i])
	{
		if (ft_strnstr(envd[i], str[1], ft_strlen(str[1])))
			return (1);
		i++;
	}
	return (0);
}

char	**ft_unset_env(char **envd, char **str)
{
	if (ft_parse_unset(envd, str))
		envd = ft_unsetloc(envd, str);
	else
		ft_error(str);
	return (envd);
}
