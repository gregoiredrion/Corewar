/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lode-spi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 00:35:28 by lode-spi          #+#    #+#             */
/*   Updated: 2020/01/12 19:51:38 by lode-spi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static int		read_file(char *path, char *buffer, int *readbytes)
{
	int			fd;
	char		dummybuf[1];

	if ((fd = open(path, O_RDONLY)) == -1)
		return (perror_msg(path, FAILURE));
	if ((*readbytes = read(fd, buffer, CHAMP_MAX_SIZE + HEADER_SIZE)) == -1)
		return (perror_msg(path, FAILURE));
	if (read(fd, dummybuf, 1) != 0)
		return (error_msg(path, "File is too big", FAILURE));
	if (close(fd) != 0)
		return (perror_msg(path, FAILURE));
	return (SUCCESS);
}

int				handle_champ(char *path, int *index, int number, t_env *env)
{
	char		buf[HEADER_SIZE + CHAMP_MAX_SIZE];
	int			file_size;
	int			ret;

	if (*index > 3)
		return (error_msg3("Too many champion given", FAILURE));
	if ((ret = read_file(path, &buf[0], &file_size)) != SUCCESS)
		return (ret);
	if (bytes_to_uint((void*)buf) != COREWAR_EXEC_MAGIC)
		return (error_msg(path, "File has wrong magic", FAILURE));
	if ((env->champs[*index].header.prog_size = bytes_to_uint((void*)buf + 136))
			!= (unsigned int)file_size - HEADER_SIZE)
	{
		return (error_msg(path, "Actual size differs from what header says",\
				FAILURE));
	}
	ft_strncpy(&env->champs[*index].header.prog_name[0], buf + 4, 129);
	ft_strncpy(&env->champs[*index].header.comment[0], buf + 140, 2049);
	ft_memcpy(&env->champs[*index].prog[0], buf + 2192,
			env->champs[*index].header.prog_size);
	env->champs[*index].number = number;
	(*index)++;
	env->nchamps++;
	return (SUCCESS);
}

int				handle_champ_with_number(char ***argv, int *i, t_env *env)
{
	int		number;
	int		ret;

	if (parse_int(*(*argv + 1), &number) == FAILURE)
		return (error_msg2(*i + 1, "Invalid int as player number", FAILURE));
	if (number == 0)
		return (error_msg2(*i + 1, "0 as player number", FAILURE));
	if (!check_if_number_free(number, *env))
		return (error_msg2(*i + 1, "Already given player number", FAILURE));
	(*argv)++;
	if (!*(*argv + 1))
		return (error_msg2(*i + 1, "No input file", FAILURE));
	(*argv)++;
	if ((ret = handle_champ(**argv, i, number, env)) != SUCCESS)
		return (FAILURE);
	return (SUCCESS);
}

int				handle_options(char ***argv, int *i, t_env *env)
{
	int		ret;

	if (ft_strequ(**argv, "n"))
	{
		if ((ret = handle_champ_with_number(argv, i, env)) != SUCCESS)
			return (ret);
	}
	else if (ft_strequ(**argv, "dump") || ft_strequ(**argv, "d"))
	{
		if (env->dump != NO_DUMP)
			return (error_msg3("Dump set twice", FAILURE));
		if (parse_int(*(*argv + 1), &env->dump) == FAILURE)
			return (error_msg3("Given dump value is not an integer", FAILURE));
		if (env->dump <= 0)
			return (error_msg3("Dump can't be 0 or negative", FAILURE));
		(*argv)++;
	}
	else if (ft_strequ(**argv, "v") || ft_strequ(**argv, "visu"))
		env->visu_on = true;
	else if (ft_strequ(**argv, "a"))
		env->aff_live_notif_enabled = true;
	else
		return (UNKNOWN);
	return (SUCCESS);
}

int				handle_args(char **argv, t_env *env)
{
	int			i;
	int			ret;
	char		*tmp;

	i = 0;
	while (*argv)
	{
		if (**argv == '-')
		{
			tmp = *argv;
			(*argv)++;
			if ((ret = handle_options(&argv, &i, env)) != SUCCESS)
				return (error_msg4(tmp, "Unknown option", ret));
		}
		else
		{
			if ((ret = handle_champ(*argv, &i, 0, env)) != SUCCESS)
				return (ret);
		}
		argv++;
	}
	set_arbitrary_champion_number(env);
	sort_inv_by_champion_number(env);
	return (SUCCESS);
}
