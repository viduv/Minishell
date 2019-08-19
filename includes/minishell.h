/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viduvern <viduvern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/22 14:19:43 by viduvern          #+#    #+#             */
/*   Updated: 2019/03/31 15:36:58 by viduvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "unistd.h"
# include "stdio.h"
# include "stdlib.h"
# include "../libft/includes/libft.h"

int				ft_find_env_2(char **tmp, char **str, char **envd);
int				ft_print(char *tmp, char **envd);
int				ft_print_env(char **envd, char **str);
char			**ft_free_db_tab(char **av);
int				ft_putendl_env(char **envd, char **str);
char			**ft_unset_env(char **envd, char **str);
int				ft_strchrint(const char *s, int c);
int				ft_parse(char **str);
char			**ft_set_env(char **envd, char **str);
char			*ft_acces(char **str);
void			ft_error(char **tepu);
char			**ft_find_dirlink(char *line, char **envd, char **str);
char			**ft_enter_old(char **envd);
char			**ft_cd_home(char **envd);
char			**ft_put_in_old(char **envd, char *old);
char			**ft_get_old_pwd(char **envd);
int				ft_pwd(char *line, char **envd, char **str);
int				ft_thirtytwo(char *line);
int				main(int ac, char **av, char **env);
char			**cop_env(char **env);
void			ft_whatdoyoumean(char *line, char **envd, char **tab);
int				ft_bin(char **envd, char **str);
char			**ft_checkpath(char *line, char **envd, char **str);
int				ft_echo(char *line, char **envd, char **str);
int				ft_echo_trip(char **str, char *line);
int				ft_cd(char *line, char **envd, char **str);
int				ft_exec(char **envd, char **str);
int				ft_find_env(char **envd, char **str);
#endif
