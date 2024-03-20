/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locharve <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 14:09:21 by locharve          #+#    #+#             */
/*   Updated: 2024/03/13 17:15:41 by locharve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// (heredoc), command, arg
// $ -> variable. substitution par sa valeur.

#ifndef LEXER_H
# define LEXER_H

# define CHARSET "\'\"$()<>|-"
//# define SPECIAL_CHAR "\'\"$()-"
//# define SEP_CHAR "<>|"
# define BONUS_CHAR "&*" // & sep

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

////////////////////////////////////////////////////////////////////////// ENUMS

typedef enum	e_spec
{
	__none,
	__input,		// <
	__heredoc,		// << + arg ?
	__output,		// >
	__outputapp,	// >>
	__pipe,			// |
	__quote,		// '
	__dquote,		// "
	__var,			// $
	__
}	t_spec;

typedef enum	e_type
{
	__invalid,	// ? 
	__heredoc,	// ?
	__command,
	__arg,		// literal
	__special,
	__flag
}	t_type;

typedef enum	e_cmd
{
	__none,	// ?
	__echo,
	__cd,
	__pwd,
	__export,
	__unset,
	__env,
	__exit
}	t_cmd;

//////////////////////////////////////////////////////////////////////// STRUCTS

typedef struct	s_token
{
	char			*str;
	t_cmd			cmd;
	t_type			type;
	struct s_token	*nxt;
}	t_token;

////////////////////////////////////////////////////////////////////////////////

/***/// lexer.c
// static int	is_command(char *str);
// static t_token	*tokenize_alpha(char *str, int *i);
t_token	*tokenizer(char *str);

/***/// cut_token.c
// static char	*ft_strndup(char *src, int n);
// static char	*alphanum_cut(char *str, int *i);
char	*cut_token(char *str, int *i, int mode);

/***/// check_fonctions.c
int		is_alphanum_or_underscore(char c);
int		is_space(char c);
int		is_lowercase(char c);
int		is_in_str(char *str, char c);
int		ft_strcmp(char *s1, char *s2);

/***/// lst_utils.c
void	lstadd_back(t_token **lst, t_token *new);
void	lstclear(t_token *lst);

////////////////////////////////////////////////////////////////////////////////
#endif
