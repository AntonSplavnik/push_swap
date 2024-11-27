/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asplavni <asplavni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 14:16:20 by asplavni          #+#    #+#             */
/*   Updated: 2024/11/27 22:20:18 by asplavni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_and_stash(char *stash, int fd)
{
	char	*buff;
	int		rd_bytes;

	buff = malloc(BUFFER_SIZE +1);
	if (!buff)
		return (NULL);
	rd_bytes = 1;
	while (!ft_strchr(stash, '\n') && rd_bytes != '\0')
	{
		rd_bytes = read(fd, buff, BUFFER_SIZE);
		if (rd_bytes == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[rd_bytes] = '\0';
		stash = ft_strjoin(stash, buff);
	}
	free(buff);
	return (stash);
}

char	*get_next_line(int fd)
{
	char		*line_to_show;
	static char	*stash;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (0);
	stash = read_and_stash(stash, fd);
	if (!stash)
		return (NULL);
	line_to_show = extract_line(stash);
	stash = clean_stash(stash);
	return (line_to_show);
}

// int	main(int argc, char **argv)
// {
// 	int		fd = open(argv[1], O_RDWR);
// 	char	*test_result = get_next_line(fd);
// 	printf("Result: %s\n", test_result);

// 	int		fd2 = open(argv[1], O_RDWR);
// 	printf("Result: %s\n", test_result);

// 	return (0);
// }

// #include <stdio.h>
// #include <unistd.h>
// int	main(int argc, char **argv)
// {
// 	int		file;
// 	char	*temp;
// 	int		fd;

// 	(void)argc;
// 	file = open(argv[1], O_RDWR);
// 	//fd = open(argv[2], O_RDWR);
// 	temp = get_next_line(file);
// 	printf("%s\n", temp);
// 	temp = get_next_line(file);
// 	printf("%s\n", temp);
// 	temp = get_next_line(file);
// 	printf("%s\n", temp);
// 	temp = get_next_line(fd);
// 	printf("%s\n", temp);
// 	temp = get_next_line(file);
// 	printf("%s\n", temp);
// 	temp = get_next_line(file);
// 	printf("%s\n", temp);
// 	free(temp);
// 	close(file);
// }