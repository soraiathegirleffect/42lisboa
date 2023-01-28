/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils_b.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosa-do <lrosa-do@student.42lisboa>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 18:23:29 by lrosa-do          #+#    #+#             */
/*   Updated: 2023/01/18 11:08:42 by lrosa-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	print_export_env(char **array, int fd)
{
	int	i;

	i = 0;
	while (array[i] != NULL)
	{
		ft_putendl_fd(array[i], fd);
		i++;
	}
}

void	printf_export_env(char **array)
{
	int	i;

	i = 0;
	while (array[i] != NULL)
	{
		ft_printf("%s\n", array[i]);
		i++;
	}
}

void	export_value_print(int pipe)
{
	char	**export_env;
	char	*temp;
	int		c;

	c = 0;
	export_env = env_with_quotes();
	sort_alpha(export_env);
	while (export_env[c])
	{
		temp = ft_strjoin("declare -x ", export_env[c]);
		free(export_env[c]);
		export_env[c] = temp;
		c++;
	}
	if (pipe == 1)
		printf_export_env(export_env);
	else
		print_export_env(export_env, STDOUT_FILENO);
	ft_free_split(export_env);
}
