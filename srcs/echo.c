/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viduvern <viduvern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/24 16:58:41 by viduvern          #+#    #+#             */
/*   Updated: 2019/03/31 15:37:58 by viduvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int		ft_print(char *tmp, char **envd)
{
	int i;
	int x;

	x = 0;
	i = 0;
	while (envd[i])
	{
		if (ft_strnequ(envd[i], tmp, ft_strlen(tmp)))
		{
			while (envd[i][x - 1] != '=')
				x++;
			while (envd[i][x])
			{
				ft_putchar(envd[i][x]);
				x++;
			}
			ft_putchar('\n');
			return (1);
		}
		i++;
	}
	return (0);
}

int		ft_print_env(char **envd, char **str)
{
	char	*tmp;
	int		x;
	int		l;

	l = 0;
	x = 0;
	tmp = (char*)malloc(sizeof(char) * x);
	x = 1;
	while (str[1][x])
	{
		tmp[l] = str[1][x];
		l++;
		x++;
	}
	tmp[l + 1] = 0;
	x = 0;
	if (!ft_print(tmp, envd))
		ft_putchar('\n');
	free(tmp);
	return (1);
}

int		ft_echo(char *line, char **envd, char **str)
{
	int x;
	int index;

	index = 0;
	x = 1;
	if (!str[1])
		ft_putchar('\n');
	else if (ft_strchr(str[1], '$'))
		return (ft_print_env(envd, str));
	else if (line[4] == 32 && line[5] != '"')
	{
		while (str[x] && str[x])
		{
			ft_putstr(str[x]);
			if (str[2])
				ft_putchar(' ');
			x++;
		}
		if (index == 0)
			ft_putchar('\n');
	}
	else
		ft_putchar('\n');
	return (1);
}
