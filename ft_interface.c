/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_interface.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nigelrobinson <Nigel@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 10:20:00 by nigelrobinson     #+#    #+#             */
/*   Updated: 2023/05/24 19:39:21 by nigelrobinson    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/**
*
*  Description : GUI INTERFACE of the game plus_minus
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
#include <stdbool.h>
#include <string.h>
#include "ft_interface.h"

#define  FLASH "\033[5m\033[37m"
#define  NOFLASH "\033[33m\033[25m"

/**
**** Title header of the game - instructions and choice of level
*/

void	ft_print_header(void)
{
	ft_clear_screen();
	printf("/* ************************************************************************** */\n");
	printf("/* ************************************************************************** */\n");
	printf("/* ****                                                                  **** */\n");
	printf("/* ****                                                                  **** */\n");
	printf("/* ****               GUESSING GAME - GUESS THE NUMBER !                 **** */\n");
	printf("/* ****                                                                  **** */\n");
	printf("/* ****           EASY MODE - ADVANCED MODE - EXPERT MODE                **** */\n");
	printf("/* ****                                                                  **** */\n");
	printf("/* ****                  ENTER 0 TO QUIT THE GAME !                      **** */\n");
	printf("/* ****                                                                  **** */\n");
	printf("/* ****                       ????????????????                           **** */\n");
	printf("/* ****                                                                  **** */\n");
	printf("/* ****                                                                  **** */\n");
	printf("/* ************************************************************************** */\n");
	printf("/* ************************************************************************** */\n");
}

/**
**** clear screen and go to home-space positiom 1,1
*/

void	ft_clear_screen(void)
{
	printf("\033[2J");
	printf("\033[2H");
}

/**
**** Winners window with the score.
*/


void	ft_print_game_over(int score)
{
	char line_of_stars[75];
	char stars[5];
	char spaces[68];
	char padding[15];
	char str1[] = "WELL DONE ! You found the number :-)";
	char str2[] = "  Atemptes to find it !         ";
	char str3[] = "          Do you wish to play again ?  y / n    ";

	memset(line_of_stars, '*', 74);
	memset(stars, '*', 4);
	memset(spaces, ' ', 67);
	memset(padding, ' ', 14);

	line_of_stars[74] = 0;
	stars[4] = 0;
	spaces[64] = 0;
	padding[13] = 0;


	


	ft_clear_screen();
	printf(FLASH);
	printf("/* %s */\n", line_of_stars);
	printf("/* %s */\n", line_of_stars);
	printf("/* %s %s %s */\n", stars,spaces,stars);
	printf("/* %s %s %s */\n", stars,spaces,stars);
	printf("/* %s %s %s %s %s */\n", stars, padding, str1, padding, stars);
	printf("/* %s %s %s */\n", stars,spaces,stars);
	printf("/* %s %s "NOFLASH"  %d %s"FLASH" %s %s */\n", stars, padding, score, str2, padding, stars);
	printf("/* %s %s %s */\n", stars,spaces,stars);
	printf("/* %s      "NOFLASH"%s"FLASH"            %s */\n",stars, str3, stars);
	printf("/* %s %s %s */\n", stars,spaces,stars);
	printf("/* %s %s %s */\n", stars,spaces,stars);
	printf("/* %s */\n", line_of_stars);
	printf("/* %s */\n", line_of_stars);
}

/**
**** Prints the question on stdout
*/

void	ft_prompt_number_guess(int level)
{
	printf("\n                   Quel est le nombre entre 1 et %d ?         ", level);
	printf("\n                                                              ");
	printf("\n                                                              ");
	printf("\n                                                              ");
	printf("\n                                                              ");
	printf("\033[4A");

    



}

/**
**** Exit sentence Saying good bye
*/

void	ft_print_signoff(void)
{
	ft_clear_screen();
	printf("                         Thanks for playing !\n\n");
}

/**
**** level coice selecter
*/

void	ft_prompt_difficulty_setting()
{
	printf("\n              Which level do you want to play    (1) - EASY");
	printf("\n                                                 (2) - NORMAL");
	printf("\n                                                 (3) - HARD");
	printf("\n            PRESS THE KEY 1, 2 OR 3 TO CHOOSE ! : ");
}

/**
* DESCRIPTION : function displays a hint for the secret number. plus ou moins.
* ARGS : int hint indicates what to print to screen 
*/

void	ft_print_hint(int hint)
{
	if(hint == 1)
		printf("                                                              C'est moins ! \n");
	if(hint == 0)
		printf("                                                               C'est plus ! \n");
	  
}
