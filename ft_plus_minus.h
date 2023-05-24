/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_plus_minus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nigelrobinson <Nige@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 11:46:41 by nigelrobinson     #+#    #+#             */
/*   Updated: 2023/05/24 11:58:41 by nigelrobinson    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PLUS_MINUS_H
# define FT_PLUS_MINUS_H

# include <stdbool.h>

# define MIN 1
# define QUIT 0

bool	compare_answer(int mistery_number, int guess);
bool	ft_play_again(void);
bool	ft_is_not_digit(int nbr);
int		ft_plus_minus(void);

#endif
