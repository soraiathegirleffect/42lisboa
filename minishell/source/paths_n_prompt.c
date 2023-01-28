/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paths_n_prompt.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupereir <lupereir@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 10:23:29 by lrosa-do          #+#    #+#             */
/*   Updated: 2023/01/28 14:27:45 by lupereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

/*
Get the PATH in g_shell.env
Return pointer string values of PATH
or 
Return empty if not found
*/
char	*get_path_str(void)
{
	int	c;

	c = 0;
	while (g_shell.env->item[c] && c <= g_shell.env->size - 1)
	{
		if (!ft_strcmp(g_shell.env->item[c]->key, "PATH"))
			return (g_shell.env->item[c]->value);
		c++;
	}
	return ("");
}

/*
Get the PATH with get_path_str
Return: pointer to slipped array of paths
*/
char	**get_paths(void)
{
	char	*paths;
	char	**ret;

	paths = get_path_str();
	ret = ft_split(paths, ':');
	return (ret);
}

/*
Get the actual pwd with getcwd
Return pointer to string with actual cwd value return
*/
char	*get_prompt(void)
{
	char	cwd[2048];
	char	*prompt;

	getcwd(cwd, 2048);
	prompt = ft_strjoin(cwd, "$ ");
	if (prompt == NULL)
	{
		perror("Error: ");
		free_and_exit();
	}
	return (prompt);
}

/*
TODO: Estamos usando? Acho que posso comentar essa função
*/
int	is_path(char **cmd, char **n_env)
{
	int	c;

	c = 0;
	if (cmd[0][0] == '/')
	{
		return (1);
	}
	while (cmd[0][c])
	{
		if (cmd[0][c] == '/')
		{
			if (cmd[0][c] + 1 == '\0')
				execve(cmd[0], cmd, n_env);
		}
		c++;
	}
	return (0);
}

/*
Free env tables
and
exit with the error code
*/
void	free_and_exit(void)
{
	free_tables(g_shell.env);
	free_tables(g_shell.local);
	exit(g_shell.noerr);
}
