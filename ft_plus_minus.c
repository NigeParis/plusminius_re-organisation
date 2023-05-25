/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_plus_minus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nigelrobinson <Nigel@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 10:20:00 by nigelrobinson     #+#    #+#             */
/*   Updated: 2023/05/25 15:01:04 by nigelrobinson    ###   ########.fr       */
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
* Headers
*/

#include <stdbool.h>
#include "ft_interface.h"
#include "ft_plus_minus.h"

/**
* DESCRIPTION : Main game engine function
* ARG : none
* RETURNS : nothing
*/

int	ft_plus_minus(void)
{
	int		guess;
	int		mistery_number;
	bool	playing;
	int level;
	int score;

	score = 0;
	guess = 1;
	playing = true;
	srand(time(NULL));
	ft_print_header();
	ft_prompt_difficulty_setting();
	level = ft_get_difficulty_level();
	printf(HIDE_LEVEL_QUESTION);
	mistery_number = ft_get_secret_random_number(level);
	while (playing)
	{
		ft_get_question_guess(level, &guess);
		ft_print_signoff(guess);
		score++;
		if (compare_answer(mistery_number, guess))
		{
			ft_print_game_over(score);
			playing = ft_play_again(&score, &mistery_number, level);
		}
	}
	ft_print_signoff(QUIT);
	return (0);
}

/**
* DESCRIPTION : Check answer to see if the same as mistery number
* ARGS : Takes the mistery number to be found and the users guess
* RETURNS : true if identical and false if not
*/

bool	compare_answer(int mistery_number, int guess)
{
	if (guess == 0)
		return (false);
	if (guess == mistery_number)
		return (true);
	if (guess > mistery_number)
			  ft_print_hint(HIGHER);
	if (guess < mistery_number)
			  ft_print_hint(LOWER);
	return (false);
}

/**
* Asks the question  play again ? and gets reply from user
*/

bool	ft_play_again(int *score, int *mistery_number, int level)
{
	char answer = '\0';

	read(1, &answer, 1);
	if (answer == 'y')
	{
		printf(DISABLE_BLINKING);
		ft_clear_screen();
		ft_print_header();
		*mistery_number = ft_get_secret_random_number(level);
		*score = 0;
		return (true);
	}
	else
	{
		printf(DISABLE_BLINKING);
		ft_clear_screen();
		return (false);	
	}
}

/**
* Check if input in a digit
*/

bool	ft_get_input_number(int *nbr)
{
	if(scanf("%d", nbr) != 1)
			  return (true);
	return (false);
}

/**
* Get difficulty level
*/

int	ft_get_difficulty_level(void)
{
	int	level_choice;
	while ((ft_get_input_number(&level_choice)) || ((level_choice > 3)))
	{
		fgetc(stdin);
		ft_clear_screen();
		ft_print_header();
		ft_prompt_difficulty_setting();
	}
	while (1)
	{
		if (level_choice == 1)
			return (EASY);
		if (level_choice == 2)
			return (NORMAL);
		if (level_choice == 3)
			return (HARD);
		if (level_choice == 0)
		{
			ft_print_signoff(QUIT);
			return (QUIT);
		}
	}
	ft_print_signoff(QUIT);
	return (QUIT);
}


/**
*	Returns : the secret number using random calculation
*	ARGS :  int level is the difficulty EASY,NORMAL or HARD chosen
*/

int	ft_get_secret_random_number(int level)
{
	int	number;
	number = (rand() % (level - MIN + 1) + MIN);
	return (number);
}

/**
*	DESCRIPTION : Function call prompt question and gets the guess
*	ARGS : takes the level of dificulty amd a pointer to the guess variable
*	RETURNS : 
*/

void	ft_get_question_guess(int level, int *guess)
{

			ft_prompt_number_guess(level);
			while (ft_get_input_number(guess))
			{
				fgetc(stdin);	
				ft_print_header();
				ft_prompt_number_guess(level);
			}

}
