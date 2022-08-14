/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogonzale <ogonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 11:29:47 by ogonzale          #+#    #+#             */
/*   Updated: 2022/05/17 16:03:28 by ogonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * FUNCTION: ft_last()
 * -------------------
 * PARAMETERS:
 * 	s:	The string to check.
 * 	c:	The delimeter character.
 * 	i:	The starting position in the string.
 * RETURN: Nonzero if there are only c and '\0' after position i and zero
 * otherwise.
 * DESCRIPTION: The function ft_last() checks if all the characters after
 * the current position in the string are the delimiter character.
 */
static int	ft_last(char const *s, char c, unsigned int i)
{
	while (s[i] == c)
	{
		i++;
		if (s[i] == '\0')
			return (1);
	}
	return (0);
}

/*
 * FUNCTION: ft_get_num_splits()
 * -----------------------------
 * PARAMETERS:
 * 	s: The string to be split.
 * 	c: The delimeter character.
 * RETURN: The number of splits.
 * DESCRIPTION: The function ft_get_num_splits() counts the number of 
 * splits by ignoring any delimeter characters at the beggining and the
 * end and adding 1 to the counter each time it encounters a delimeter.
 */

static unsigned int	ft_get_num_splits(char const *s, char c)
{
	unsigned int	i;
	unsigned int	num_splits;

	i = 0;
	num_splits = 0;
	if (s[i] != c)
		num_splits++;
	while (s[i] != '\0')
	{
		if (s[i] == c && !ft_last(s, c, i))
			num_splits++;
		while (s[i] == c)
			i++;
		if (s[i] == '\0')
			break ;
		i++;
	}
	return (num_splits);
}

/*
 * FUNCTION: ft_free_str_split()
 * -----------------------------
 * PARAMETERS:
 * 	j:			The index of the last malloc.
 * 	str_split:	The array of strings.
 * RETURN: Zero.
 * DESCRIPTION: The function ft_free_str_split() frees the allocated memory.
 */

static int	ft_free_str_split(int j, char **str_split)
{
	while (j >= 0)
	{
		free(str_split[j]);
		j--;
	}
	free(str_split);
	return (0);
}

/*
 * FUNCTION: ft_allocate_and_split()
 * ---------------------------------
 * PARAMETERS:
 * 	str_split: 	The array of strings.
 * 	s:			The string to be split.
 * 	c:			The delimeter character.
 * RETURN: The index of the next to last filled string.
 * DESCRIPTION: The function ft_allocate_and_split() allocates the necessary
 * memory for each split, and fills it up accordingly with the appropiate
 * characters, adding '\0' to the end.
 * DEV: start_split is used to flag the start position after encountering the
 * delimeter character. It is useful to allocate memory, and to restart the
 * loop counter to start_split and fill up the allocated memory.
 */

static int	ft_allocate_and_split(char **str_split, char const *s, char c)
{
	int	i;
	int	j;
	int	start_split;

	j = 0;
	i = 0;
	while (s[i] != '\0' && !ft_last(s, c, i))
	{
		while (s[i] == c)
			i++;
		start_split = i;
		while (s[i] != c && s[i] != '\0')
			i++;
		str_split[j] = malloc(sizeof(char) * (i - start_split + 1));
		if (!str_split[j])
			return (ft_free_str_split(j, str_split));
		i = start_split - 1;
		while (s[++i] != c && s[i] != '\0')
			str_split[j][i - start_split] = s[i];
		str_split[j++][i - start_split] = '\0';
		if (s[i++] == '\0')
			break ;
	}
	return (j);
}

/*
 * FUNCTION: ft_split()
 * --------------------
 * PARAMETERS:
 * 	s:	The string to be split.
 * 	c:	The delimeter character.
 * RETURN: The array of new strings resulting from the split. NULL if the
 * allocation fails.
 * DESCRIPTION: Allocates (with malloc(3)) and returns an array of strings
 * obtained by splitting 's' using the character 'c' as a delimeter. The
 * array must end with a NULL pointer.
 * DEV: The number of necessary splits must be found using 
 * ft_get_num_splits() and allocating the result + 1 to account for the NULL
 * ending. Then, each split is filled using ft_allocate_and_split(), which 
 * returns the index of the last split, which is finally used to set the last
 * split to NULL.
 */
char	**ft_split(char const *s, char c)
{
	unsigned int	num_splits;
	char			**str_split;
	int				j;

	if (!s)
		return (0);
	if (s[0] == '\0')
		num_splits = 0;
	else
		num_splits = ft_get_num_splits(s, c);
	str_split = malloc(sizeof(char *) * (num_splits + 1));
	if (!str_split)
		return (0);
	if (num_splits == 0)
	{
		str_split[0] = NULL;
		return (str_split);
	}
	j = ft_allocate_and_split(str_split, s, c);
	if (!j)
		return (0);
	str_split[j] = NULL;
	return (str_split);
}
/*
int	main(void)
{
	char const *s = "";
	char		c = 'z';
	char		**split;
	int			i;

	split = ft_split(s, c);
	i = -1;
	while (split[++i] != NULL)
		printf("split: %s\n", split[i]);
	return (0);
}
*/
