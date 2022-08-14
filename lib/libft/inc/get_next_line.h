/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogonzale <ogonzale@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 09:27:41 by ogonzale          #+#    #+#             */
/*   Updated: 2022/06/15 09:42:57 by ogonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFFER_SIZE 100
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <time.h>
# include <string.h>

/* get_next_line.c */
char			*get_next_line(int fd);

/* get_next_line_utils.c */
char			*ft_substr_gnl(char **s, unsigned int start, unsigned int len);
void			ft_strcpy_gnl(char **dest, char **src, unsigned int n);
void			ft_strset_gnl(char **s, int c, unsigned int n);
#endif
