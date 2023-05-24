/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_interface.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nigelrobinson <Nige@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 12:10:56 by nigelrobinson     #+#    #+#             */
/*   Updated: 2023/05/24 12:12:33 by nigelrobinson    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_INTERFACE_H
# define FT_INTERFACE_H

void    ft_print_header(void);
void    ft_clear_screen(void);
void    ft_print_game_over(int score);
void    ft_prompt_number_guess(int level);
void    ft_print_signoff(void);
int     ft_get_difficulty_setting(void);
#endif
