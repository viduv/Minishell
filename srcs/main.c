/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viduvern <viduvern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/22 14:18:28 by viduvern          #+#    #+#             */
/*   Updated: 2019/03/31 15:41:47 by viduvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int		ft_thirtytwo(char *line)
{
	int x;

	x = 0;
	while (line[x])
	{
		if (line[x] > 32)
			return (1);
		x++;
	}
	return (0);
}

char	*ft_splittab(char *line)
{
	int x;

	x = 0;
	while (line[x])
	{
		if (line[x] < 32)
			line[x] = 32;
		x++;
	}
	return (line);
}

char	**cop_env(char **env)
{
	int		o;
	int		x;
	char	**cp;

	o = 0;
	x = 0;
	cp = NULL;
	while (env[o])
		o++;
	if (!(cp = (char**)malloc(sizeof(char*) * (o + 1))))
		return (NULL);
	o = 0;
	while (env[o])
		cp[x++] = ft_strdup(env[o++]);
	cp[x] = 0;
	return (cp);
}

void	minishell(char **envd)
{
	char	*line;
	char	**tab;

	line = NULL;
	tab = NULL;
	while (42)
	{
		ft_putstr("$>");
		if (get_next_line(0, &line) < 1)
			break ;
		if (ft_thirtytwo(line))
		{
			line = ft_splittab(line);
			tab = ft_strsplit(line, ' ');
			if (ft_strequ(*tab, "exit"))
			{
				ft_free_db_tab(tab);
				ft_free_db_tab(envd);
				exit(0);
			}
			envd = ft_checkpath(line, envd, tab);
			ft_free_db_tab(tab);
		}
		ft_strdel(&line);
	}
}

int		main(int ac, char **av, char **env)
{
	char **envd;

	(void)ac;
	(void)av;
	envd = cop_env(env);
	minishell(envd);
	ft_free_db_tab(envd);
	return (0);
}
