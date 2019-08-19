/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dir.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viduvern <viduvern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 18:54:43 by viduvern          #+#    #+#             */
/*   Updated: 2019/03/30 13:42:12 by viduvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>

int		ft_putendl_env(char **envd, char **str)
{
	int i;

	i = 0;
	if (str[1])
		ft_error(str);
	while (envd[i])
	{
		ft_putendl(envd[i]);
		i++;
	}
	return (1);
}

char	*ft_acces(char **str)
{
	struct stat buf;

	lstat(str[1], &buf);
	if (access(str[1], F_OK) == -1)
		return ("cd: no such file or directory: ");
	else if (access(str[1], X_OK) == -1)
	{
		lstat(str[1], &buf);
		if (S_ISDIR(buf.st_mode) != 1)
			return ("cd: not a directory: ");
		return ("cd: permission denied: ");
	}
	if (S_ISDIR(buf.st_mode) != 1)
		return ("cd: not a directory: ");
	return (NULL);
}

void	ft_error(char **tepu)
{
	int i;

	i = 1;
	ft_putstr("bash: ");
	while (tepu[i])
	{
		ft_putstr(tepu[i]);
		ft_putchar(' ');
		i++;
	}
	ft_putendl(": command not found");
}

char	**ft_find_dirlink(char *line, char **envd, char **str)
{
	char *error;

	error = NULL;
	if (line[2] != ' ')
		ft_error(str);
	else if (str[2])
		ft_error(str);
	else
		error = ft_acces(str);
	(error != NULL) ? ft_putendl(error) : chdir(str[1]);
	return (envd);
}
