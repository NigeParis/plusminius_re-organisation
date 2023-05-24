/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_plus_minus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nigelrobinson <Nige@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 11:46:41 by nigelrobinson     #+#    #+#             */
/*   Updated: 2023/05/24 17:46:29 by nigelrobinson    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PLUS_MINUS_H
# define FT_PLUS_MINUS_H

# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <time.h>
# include <stdbool.h>
# include <unistd.h>
# include "ft_interface.h"

# define MIN 1
# define QUIT 0
# define EASY 10
# define NORMAL 100
# define HARD 10000

# define HIGHER 1
# define LOWER 0

bool	compare_answer(int mistery_number, int guess);
bool	ft_play_again(void);
bool	ft_is_not_digit(int *nbr);
int		ft_get_secret_random_number(int level);
int		ft_get_difficulty_level(void);
int		ft_plus_minus(void);

#endif
