/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsouhar <bsouhar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 09:28:29 by bsouhar           #+#    #+#             */
/*   Updated: 2023/03/13 09:28:32 by bsouhar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _PUSH_SWAP_H
# define _PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

struct				Node
{
	int				data;
	struct Node		*next;
};

extern struct Node	*top_a;
extern struct Node	*top_b;

void				push_a(int value);
void				push_b(int value);
void				sa(void);
void				display_a(void);
void				display_b(void);
void				sb(void);
void				ss(void);
void				pa(void);
void				pb(void);
void				ra(void);
void				rb(void);
void				rr(void);
void				rra(void);
void				rrb(void);
void				rrr(void);

#endif
