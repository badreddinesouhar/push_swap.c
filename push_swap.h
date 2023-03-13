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

#ifdef _PUSH_SWAP_H
#define _PUSH_SWAP_H

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

struct Node {
    int data;
    struct Node *next;
};

void push_a(int value);
void push_b(int value);
void sa(void);
int display_a(void);


#endif
