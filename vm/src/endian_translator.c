/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   endian_translator.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lode-spi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 00:10:18 by lode-spi          #+#    #+#             */
/*   Updated: 2020/01/10 22:28:03 by lode-spi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

unsigned int		bytes_to_uint(void *first_byte)
{
	unsigned int	v;

	v = *((unsigned int*)first_byte);
	v = ((v >> 24) & 0xff) | ((v << 8) & 0xff0000) |
		((v >> 8) & 0xff00) | ((v << 24) & 0xff000000);
	return (v);
}

int					bytes_to_int(unsigned char vm[MEM_SIZE], int index)
{
	char			v[4];
	int				index_tmp;

	if (index < 0)
	{
		index_tmp = index % MEM_SIZE;
		index = MEM_SIZE + index_tmp;
	}
	v[0] = vm[(index + 3) % MEM_SIZE];
	v[1] = vm[(index + 2) % MEM_SIZE];
	v[2] = vm[(index + 1) % MEM_SIZE];
	v[3] = vm[index % MEM_SIZE];
	return (*(int*)&v[0]);
}

short				bytes_to_short(unsigned char vm[MEM_SIZE], int index)
{
	char			v[2];
	int				index_tmp;

	if (index < 0)
	{
		index_tmp = index % MEM_SIZE;
		index = MEM_SIZE + index_tmp;
	}
	v[0] = vm[(index + 1) % MEM_SIZE];
	v[1] = vm[index % MEM_SIZE];
	return (*(short*)&v[0]);
}

void				put_int_in_vm(t_env *env, int index, int nb,\
t_process *p)
{
	int	index_tmp;

	if (index < 0)
	{
		index_tmp = index % MEM_SIZE;
		index = MEM_SIZE + index_tmp;
	}
	env->vm_ownership[index % MEM_SIZE] = p->owner;
	env->vm_ownership[(index + 1) % MEM_SIZE] = p->owner;
	env->vm_ownership[(index + 2) % MEM_SIZE] = p->owner;
	env->vm_ownership[(index + 3) % MEM_SIZE] = p->owner;
	env->vm_memory[index % MEM_SIZE] = (char)(nb >> 24 & 255);
	env->vm_memory[(index + 1) % MEM_SIZE] = (char)(nb >> 16 & 255);
	env->vm_memory[(index + 2) % MEM_SIZE] = (char)(nb >> 8 & 255);
	env->vm_memory[(index + 3) % MEM_SIZE] = (char)(nb & 255);
}

void				put_short_in_vm(t_env *env, int index, short nb,\
t_process *p)
{
	if (index < 0)
		index = MEM_SIZE + (index);
	ft_memset(&env->vm_ownership[index], p->owner, 2);
	env->vm_ownership[index % MEM_SIZE] = p->owner;
	env->vm_ownership[(index + 1) % MEM_SIZE] = p->owner;
	env->vm_memory[index % MEM_SIZE] = (char)(nb >> 8 & 255);
	env->vm_memory[(index + 1) % MEM_SIZE] = (char)(nb & 255);
}
