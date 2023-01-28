/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_export.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosa-do <lrosa-do@student.42lisboa>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 10:23:29 by lupereir          #+#    #+#             */
/*   Updated: 2023/01/18 10:45:01 by lrosa-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	sort_alpha(char **str)
{
	int		x;
	int		y;
	char	*aux;

	x = 0;
	while (str[x])
	{
		y = 0;
		while (str[y])
		{
			if (ft_strcmp(str[x], str[y]) < 0)
			{
				aux = str[x];
				str[x] = str[y];
				str[y] = aux;
			}
			y++;
		}
		x++;
	}
}

char	*put_quotes(t_ht_item *new_env)
{
	char	*exp_env;
	char	*new_key;
	char	*new_val;

	if (new_env->value)
	{
		new_key = ft_strjoin(new_env->key, "=");
		exp_env = ft_strjoin("\"", new_env->value);
		new_val = ft_strjoin(exp_env, "\"");
		free(exp_env);
		exp_env = ft_strjoin(new_key, new_val);
		free(new_key);
		free(new_val);
	}
	else
		exp_env = ft_strdup(new_env->key);
	return (exp_env);
}

char	**env_with_quotes(void)
{
	int					i;
	char				**env;
	t_ht_item			*temp;

	i = 0;
	while (g_shell.env->item[i])
		i++;
	env = (char **)ft_calloc(sizeof(char *), i + 1);
	i = 0;
	while (g_shell.env->item[i] && i <= g_shell.env->size - 1)
	{
		temp = g_shell.env->item[i];
		env[i] = put_quotes(temp);
		i++;
	}
	return (env);
}
