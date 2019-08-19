/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viduvern <viduvern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 10:54:55 by viduvern          #+#    #+#             */
/*   Updated: 2019/03/30 13:14:14 by viduvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	**ft_enter_old(char **envd)
{
	int i;

	i = 0;
	while (envd[i])
	{
		if (ft_strnequ(envd[i], "OLDPWD=", 7))
		{
			chdir(&envd[i][7]);
			return (envd);
		}
		i++;
	}
	ft_putendl("BAD ENV");
	return (envd);
}

char	**ft_put_in_old(char **envd, char *old)
{
	int i;

	i = 0;
	while (envd[i])
	{
		if (ft_strnequ(envd[i], "OLDPWD= ", 7))
		{
			ft_strdel(&envd[i]);
			envd[i] = ft_strjoin("OLDPWD=", old);
			ft_strdel(&old);
			return (envd);
		}
		i++;
	}
	ft_putendl(" Bash : environement variable not found");
	return (envd);
}

char	**ft_get_old_pwd(char **envd)
{
	int		i;
	int		x;
	char	*old;
	int		env;

	x = -7;
	i = 0;
	old = NULL;
	env = 4;
	while (envd[i])
	{
		if (ft_strnequ(envd[i], "PWD=", 4))
		{
			x = ft_strlen(envd[i]);
			old = (char*)malloc(sizeof(char) * x + 1);
			x = 0;
			while (envd[i][env])
				old[x++] = envd[i][env++];
			old[x] = 0;
		}
		i++;
	}
	(old != NULL) ? envd = ft_put_in_old(envd, old) \
		: ft_putendl(" Bash : environement variable not found");
	return (envd);
}

char	**ft_cd_home(char **envd)
{
	int		i;

	i = 0;
	while (envd[i])
	{
		if (ft_strnequ(envd[i], "HOME=", 5))
		{
			ft_get_old_pwd(envd);
			chdir(&envd[i][5]);
			return (envd);
		}
		i++;
	}
	ft_putendl("Bash : Directory access Failed");
	return (envd);
}

int		ft_cd(char *line, char **envd, char **str)
{
	if (!str[1] || ft_strequ(str[1], "~"))
		ft_cd_home(envd);
	else if (ft_strequ(str[1], "-"))
		envd = ft_enter_old(envd);
	else
		ft_find_dirlink(line, envd, str);
	return (0);
}
