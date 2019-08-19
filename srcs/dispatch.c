/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lesderniersserontlespremiers.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viduvern <viduvern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/22 18:25:29 by viduvern          #+#    #+#             */
/*   Updated: 2019/03/31 15:02:44 by viduvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int		ft_exec(char **envd, char **str)
{
	pid_t father;

	father = fork();
	if (father == 0)
		execve(str[0], str, envd);
	else
		wait(&father);
	return (0);
}

int		ft_find_env_2(char **tmp, char **str, char **envd)
{
	char	*lol;
	char	*bin;
	int		x;

	x = 0;
	lol = ft_strdup(str[0]);
	bin = NULL;
	while (tmp[x])
	{
		bin = ft_strjoin3(tmp[x], "/", lol);
		free(str[0]);
		str[0] = bin;
		*str = str[0];
		if (access(str[0], F_OK) == 0)
		{
			ft_exec(envd, str);
			ft_free_db_tab(tmp);
			free(lol);
			return (1);
		}
		x++;
	}
	free(lol);
	return (0);
}

int		ft_find_env(char **envd, char **str)
{
	char	**tmp;
	int		i;

	tmp = NULL;
	i = 0;
	while (envd[i])
	{
		if (ft_strnequ(envd[i], "PATH=", 5))
			tmp = ft_strsplit(envd[i], ':');
		if (tmp)
			if (ft_find_env_2(tmp, str, envd))
				return (1);
		i++;
	}
	return (0);
}

int		ft_bin(char **envd, char **str)
{
	int i;

	i = 0;
	if (ft_check_str(*str, '/'))
	{
		if (access(str[0], F_OK) == 0)
			ft_exec(envd, str);
		else
			ft_putendl("bash: command not found");
		return (0);
	}
	else
	{
		if (ft_find_env(envd, str) == 0)
			ft_putendl("bash: command not found");
	}
	return (0);
}

char	**ft_checkpath(char *line, char **envd, char **str)
{
	if (ft_strequ(str[0], "cd"))
		ft_cd(line, envd, str);
	else if (ft_strequ(str[0], "echo"))
		ft_echo(line, envd, str);
	else if (ft_strequ(str[0], "setenv"))
	{
		envd = ft_set_env(envd, str);
		return (envd);
	}
	else if (ft_strequ(str[0], "unsetenv"))
	{
		envd = ft_unset_env(envd, str);
		return (envd);
	}
	else
		ft_bin(envd, str);
	return (envd);
}
