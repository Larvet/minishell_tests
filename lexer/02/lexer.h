/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locharve <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 16:26:20 by locharve          #+#    #+#             */
/*   Updated: 2024/03/19 17:46:03 by locharve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <sys/wait.h>

# define WHITESPACES "\t\n\v\f\r "

typedef enum    e_type
{
	__error,
    __word,
	__quoted,
	__dquoted,
    __flag,
    __var,
    __redir_l,
    __redir_ll,
    __redir_r,
    __redir_rr,
	__pipe
}   t_type;

typedef enum	e_err		// ?
{
	__no_err,
	__malloc,
	__open_quote,
	__open_dquote,
	__invalid
}	t_err;

typedef struct  s_token
{
    char            *str;
    t_type          type;
	t_err			err;
    struct s_token  *nxt;    
}   t_token;

typedef struct  s_command
{
    char                **token;
    t_err               err;
    struct s_command    *nxt;
}   t_command;

////////////////////////////////////////////////////////////////////////////////

/***/// tokenizer.c
int		is_space(char c);
// static t_token	*tokenize_one(char *line, int *i);
t_token	*tokenizer(char *line);

/***/// token_fonctions1.c
int		is_separator(char c);
void	tokenize_var(t_token *token, char *line, int *i);
void	tokenize_flag(t_token *token, char *line, int *i);
void	tokenize_redir(t_token *token, char *line, int *i);
void	tokenize_pipe(t_token *token, char *line, int *i);

/***/// token_fonctions2.c
size_t	ft_strlen(char *str);
char	*ft_strndup(char *src, int n);
void	tokenize_str(t_token *token, char *line, int *i);
void	tokenize_word(t_token *token, char *line, int *i);
void	tokenize_error(t_token *token);

/***/// lst_utils.c
void	lstadd_back(t_token **lst, t_token *new);
void	lstclear(t_token *lst);

/***/// ft_calloc.c
// static void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);

/***/// substitute_var.c
void	substitute_var(t_token *token);

// is_sep strndup 

// ft_calloc
// ft_strdup

////////////////////////////////////////////////////////////////////////////////

/***/// builtins1.c
char	*my_pwd(void);
int		my_cd(char *path);

/***/// ft_split.c
// static int	count_words(char const *str, char c);
// static char	*str_piece_cpy(const char *s, int start, int end);
// static char	*from_str_to_strs(const char *s,int *i, char c);
void	free_all(char **split);
char	**ft_split(char const *s, char c);

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

#endif
