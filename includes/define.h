/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdeltenr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 16:32:07 by wdeltenr          #+#    #+#             */
/*   Updated: 2019/12/18 17:38:17 by wdeltenr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINE_H
# define DEFINE_H

# define NAME 0
# define NB_ARG 1
# define ARG_TYPE 2
# define OPCODE 3
# define CYCLE_COST 4
# define DESCRIPTION 5
# define CODE_OCTET 6
# define LABEL_SIZE 7

# define NB_ARG_ERROR 0
# define TYPE_ARG_ERROR 1

# define T_CMD 16
# define T_STR 32
# define T_INS 64
# define T_SEP 128

typedef enum
{
	false,
	true
}	t_bool;

#endif
