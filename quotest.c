#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>


int	char_check(char cmp, char to_find, char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
	{
		if (cmp == to_find)
			return (0);
	}
	else
	{
		while (str[i])
		{
			if (str[i] == to_find)
				return (i);
			i++;
		}
	}
	return (-1);
}

int	ft_is_space(char c)
{
	if (c == ' ' || c == '\n' || c == '\t'
	|| c == '\v' || c == '\f' || c == '\r')
		return (0);
	return (-1);
}

int	space_skipper(char *str, int i)
{
	while (str[i] && (ft_is_space(str[i] == 0)))
		i++;
	return (i);
}

char	*quote_handler(char *str)
{
	int		i;
	int		j;
	int		k;
	char	*s_cleaned;

	i = 0;
	k = 0;
	printf ("de but fctn = %s\n", str);
	s_cleaned = malloc(sizeof(char) * strlen(str) + 1);
	if (!s_cleaned)
		return (NULL); // FREEEEEEEEEEEEEE ICI
	while (str && str[i])
	{
		if ((char_check('a', str[i], NULL) == 0) && // dans le cas de 2 simple quote cote a cote skip puisque str null
			(char_check('a', str[i + 1], NULL) == 0))
		{
			printf ("check a ici donc on est a str[i]%c\n", str[i]);
			i = i + 2;
			printf ("puis str[i]%c\n", str[i]);
		}
		if (ft_is_space(str[i]) == 0)
		{
			i++;
			i = space_skipper(str, i);

		}
		if ((char_check('b', str[i], NULL) == 0) && // cas de 2 double quote skip puisque str null
			(char_check('b', str[i + 1], NULL) == 0))
		{
			printf ("check a ici donc on est a str[i]%c\n", str[i]);
			i = i + 2;
			printf ("puis str[i]%c\n", str[i]);
		}
		if (ft_is_space(str[i]) == 0)
		{
			i++;
			i = space_skipper(str, i);
		}
		if ((char_check('a', str[i], NULL) == 0) && // si simple quote na pas trouve son double erreur
			(char_check(0, 'a', str) == -1))
			return (NULL);
		if ((char_check('b', str[i], NULL) == 0) && // si double quote na pas trouve son double erreur
			(char_check(0, 'b', str) == -1))
			return (NULL);
		if ((char_check('a', str[i], NULL) == 0) && // si simple quote a trouve son double qq part plus loin dans la str
			(char_check(0, 'a', str) != -1))
		{
			j = (char_check(0, 'a', str));  // donner la valeur de l'occurence a j pour definir la fin de la str
			while (i < j)                    // incrementer de i a j
			{
    			s_cleaned[k] = str[i];
				i++;
				k++;
			}
			i++;
		}
		if (ft_is_space(str[i]) == 0)
		{
			i++;
			i = space_skipper(str, i);
		}
		if ((char_check('b', str[i], NULL) == 0) &&
			(char_check(0, 'b', str) != -1))
		{
			j = (char_check(0, 'b', str));  // donner la valeur de l'occurence a j pour definir la fin de la str
			while (i < j)                    // incrementer de i a j
			{
					s_cleaned[k] = str[i];
				i++;
				k++;
			}
			i++;
		}
		if (ft_is_space(str[i]) == 0)
		{
			i++;
			i = space_skipper(str, i);
		}
		s_cleaned[k] = str[i];
		k++;
		i++;
	}
	return (s_cleaned);
}

int main(int argc, char **argv)
{
	(void)argc;
	char *str = quote_handler(argv[1]);

	printf("%s\n", str);
}

