/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expender.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssteveli <ssteveli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 16:53:54 by ssteveli          #+#    #+#             */
/*   Updated: 2024/07/05 18:13:00 by ssteveli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	len_to_egal(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '=')
		i++;
	return (i);
}

char	*after_egal(char *str)
{
	int		i;
	char	*a;
	int		j;

	i = 0;
	while (str[i] != '=')
		i++;
	i++;
	a = ft_calloc(ft_strlen(str) - i + 1, sizeof(char));
	j = 0;
	while (str[i])
	{
		a[j] = str[i];
		j++;
		i++;
	}
	return (a);
}

int len_to_space(char *str, int i)
{
	int len;

	len = 0;
	while (str[i] && str[i] != ' ')
	{
		len++;
		i++;
	}
	return (len);
}

char *load_str(char *a, int i)
{
	int len;
	char *str;
	int j;

	len = len_to_space(a, i);
	str = ft_calloc(len + 1, sizeof(char));
	i++;
	j = 0;
	while (a[i] && a[i] != ' ')
	{
		str[j] = a[i];
		i++;
		j++;
	}
	str[j] = '=';
	return (str);
}

int	replace_hextend_bis(char *a, int i)
{
	int j;
	int num;

	j = i;
	num = 0;
	while (a[j])
	{
		if (a[j] == '\'')
			num++;
		j++;
	}
	if (num > 0 && num%2 == 1)
		return (1);
	else 
		return (0);
}

char *replace_hextend(char *a, int i)
{
	int j;
	int num;

	j = i;
	num = 0;
	while ( j > 0 && a[j])
	{
		if (a[j] == '\'')
			num++;
		j--;
	}
	if (replace_hextend_bis(a, i) == 1 || (num > 0 && num%2 == 1))
		return (0);
	else 
		return (load_str(a, i));
}

char *replace_a(char *a, char *str, int i, char *str3)
{
	int j;
	int k;
	int len;
	char *str2;
	

	i = 0;
	j = 0;
	k = 0;
	len = len_to_egal(str);
	str2 = ft_calloc(ft_strlen(a), sizeof(char));
	while (a[i] && a[i] != '$')
		str2[j++] = a[i++];
	while (str[k])
		str2[j++] = str[k++];
	i += ft_strlen(str3);
	while (a[i])
		str2[j++] = a[i++];
	str2[j] = '\0';
	free(str);
	free(str3);
	return (str2);
}

char *change_hextend(char *a, int i, char *str, t_data *data)
{
	int k;
	
	k = 0;
	while (data->env[k])
	{
		if (ft_strncmp(data->env[k], str, ft_strlen(str)) == 0)
		{
			a = replace_a(a, after_egal(data->env[k]), i, str);
		}
		k++;
	}
	return (a);
}

char	*hextend(char *a, t_data *data)
{
	int i;
	char *str;

	i = 0;
	while (a[i])
	{
		if (a[i] == '$')
		{
			str = replace_hextend(a, i);
			if (str)
				a = change_hextend(a, i , str, data);
		}
		i++;
	}
	return (a);
}
