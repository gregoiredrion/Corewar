/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdeltenr <wdeltenr@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 21:06:15 by wdeltenr          #+#    #+#             */
/*   Updated: 2020/01/11 21:43:00 by wdeltenr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void free_labels(t_cor *cor)
{
  t_label *labels;
  t_label *tmp;

  labels = cor->labels;
  while (labels)
  {
    tmp = labels;
    labels = labels->next;
    ft_strdel(&tmp->name);
    tmp->pos = 0;
    free(tmp);//memdel?
  }
  cor->labels = NULL;
}

void free_offsets(t_cor *cor)
{
  t_offset *offsets;
  t_offset *tmp;

  offsets = cor->offset;
  while (offsets)
  {
    tmp = offsets;
    offsets = offsets->next;
    //ft_strdel(&tmp->name);
    tmp->start = 0;
    tmp->pos = 0;
    tmp->nb_bytes = 0;
    free(tmp);//memdel?
  }
  cor->offset = NULL;

}
void free_tokens(t_cor *cor)
{
  t_token *tokens;
  t_token *tmp;


  tokens = cor->tokens;
  while (tokens)
  {
    tmp = tokens;
    tokens = tokens->next;
    if (tmp->type != T_NEW)
      ft_strdel(&tmp->str);
    tmp->type = 0;
    tmp->col = 0;
    tmp->line = 0;
    free(tmp);//memdel?
  }
  cor->tokens = NULL;

}

void   free_all(t_cor *cor)
{
  free_tokens(cor);
  free_labels(cor);
  free_offsets(cor);
  ft_strdel(&cor->prog);
  ft_strdel(&cor->file);
  ft_strdel(&cor->name);
  cor = NULL;
}
