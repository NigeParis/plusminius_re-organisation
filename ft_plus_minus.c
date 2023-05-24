/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_plus_minus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nigelrobinson <Nigel@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 10:20:00 by nigelrobinson     #+#    #+#             */
/*   Updated: 2023/05/24 10:48:39 by nigelrobinson    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/**
*
*  Description : EXERCISE plus_minus_de_Vincent
*
*	Guess the number between 1 and 10000 ( three levels of difficulties
*
*	Computer gives you a clue if it's higher or lower
*
*	This is how it should be prototyped :  void	ft_plus_minus(void);
*
*	Files to turn in: void	ft_plus_minus.c
*
* 	Allowed libary : all 
*
*  Args: void
*
*	Returns: void
*
*/

/**
***** headers
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <unistd.h>
#include "ft_interface.h"
#include "ft_plus_minus.h"

/**
**** principal game function
*/

int	ft_plus_minus(void)
{
	int		guess;
	int		mistery_number;
	bool	try_to_find;
	int level;
	int score;

	score = 0;
	mistery_number = 0;
	guess = 1;
	try_to_find = true;
	srand(time(NULL));
	ft_print_header();
	level = 0;
	level = ft_get_difficulty_setting();
	printf("\033[5A");
	while ((try_to_find == true) && (level != QUIT))
	{
		mistery_number = (rand() % (level - MIN + 1) + MIN);
		while (try_to_find > 0)
		{
			ft_prompt_number_guess(level);
			while (scanf("%d", &guess) != 1)
			{
				fgetc(stdin);	
				ft_print_header();
				ft_prompt_number_guess(level);
			}
			if (guess == QUIT)
			{
				ft_clear_screen();
				ft_print_signoff();	
				return (0);
			}
			score++;
			if (compare_answer(mistery_number, guess))
			{
				ft_clear_screen();
				ft_print_game_over(score);
				if (ft_play_again())
				{
					try_to_find = true;
					score = 0;
					mistery_number = (rand() % (level - MIN + 1) + MIN);
				}
				else
					try_to_find = false;
			}
	 	}
	}
	return (0);
}

/**
**** check answer function returns true if the same as mistery number
*/

bool	compare_answer(int mistery_number, int guess)
{
	if (guess == 0)
		return (false);
	if (guess == mistery_number)
		return (true);
	if (guess > mistery_number)
		printf("                                                              C'est moins ! \n");
	if (guess < mistery_number)
		printf("                                                               C'est plus ! \n");
	return (false);
}

/**
**** Asks the question  play again ? and gets reply from user
*/

bool	ft_play_again(void)
{
	char answer = '\0';

	read(1, &answer, 1);
	if (answer == 'y')
	{
		printf("\033[25m");
		ft_clear_screen();
		ft_print_header();
		return (true);
	}
	else
	{
		printf("\033[25m");
		ft_clear_screen();
		return (false);	
	}
}

/**
* Check if input in a digit
*/
/**
bool	ft_is_not_digit(int nbr)
{



	return (true);

}
*/

