/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viduvern <viduvern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 15:13:11 by viduvern          #+#    #+#             */
/*   Updated: 2019/03/30 13:06:18 by viduvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	**ft_free_db_tab(char **av)
{
	int i;

	i = 0;
	if (!av)
		return (NULL);
	while (av[i])
		ft_strdel(&av[i++]);
	free(av);
	av = NULL;
	return (av);
}

char	**ft_alloc_env(char **envd, char **str)
{
	int		i;
	char	**tab;

	i = 0;
	while (envd[i])
		i++;
	tab = (char**)malloc(sizeof(char*) * i + 2);
	tab[i + 1] = 0;
	i = 0;
	while (envd[i])
	{
		tab[i] = ft_strdup(envd[i]);
		i++;
	}
	tab[i] = ft_strdup(str[1]);
	tab[i + 1] = 0;
	ft_free_db_tab(envd);
	return (tab);
}

int		ft_strchrint(const char *s, int c)
{
	int i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return (1);
		i++;
	}
	return (0);
}

int		ft_parse(char **str)
{
	if (str[2] || !str[1])
		return (0);
	if (ft_strchrint(str[1], '=') == 0)
		return (0);
	return (1);
}

char	**ft_set_env(char **envd, char **str)
{
	if (!ft_parse(str))
		ft_error(str);
	else
		envd = ft_alloc_env(envd, str);
	return (envd);
}
