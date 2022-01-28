/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvine <cvine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 20:07:17 by cvine             #+#    #+#             */
/*   Updated: 2022/01/28 19:45:19 by cvine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFFER_SIZE 100
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "libft.h"

char	*find_newline(const char *s);
char	*get_next_line(int fd);
char	*gnl_strjoin(char const *s1, char const *s2);

#endif