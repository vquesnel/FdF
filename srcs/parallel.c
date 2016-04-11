/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parallel.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vquesnel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/07 12:26:58 by vquesnel          #+#    #+#             */
/*   Updated: 2016/04/08 11:53:54 by vquesnel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_iso	*parallel(t_node *cc)
{
	t_node	*tmp;
	t_iso	*new;

	tmp = cc;
	new = NULL;
	while (cc)
	{
		new = insert_node_iso(new, cc);
		cc = cc->next;
	}
	return (new);
}
