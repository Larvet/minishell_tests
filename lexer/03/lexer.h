/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locharve <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 16:26:20 by locharve          #+#    #+#             */
/*   Updated: 2024/03/28 15:59:30 by locharve         ###   ########.fr       */
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
# include <stdarg.h>

# define WHITESPACES "\t\n\v\f\r "
# define SEPARATORS "\t\n\v\f\r <>|"
# define ALL_SPECIAL "\"\'<>|"

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
	__open_quote,   // pas necessaire
	__open_dquote,  // idem
	__invalid
}	t_err;

typedef enum	e_redir
{
	__input_r,	// <
	__input_rw,	// <>
	__output,

}	t_redir;

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

/***/// lexer.c
t_command   *lexer(char *line);

/***/// token_fonctions1.c
int		is_separator(char c);
void	tokenize_var(t_token *token, char *line, int *i);
void	tokenize_flag(t_token *token, char *line, int *i);
void	tokenize_redir(t_token *token, char *line, int *i);
void	tokenize_pipe(t_token *token, char *line, int *i);

/***/// token_fonctions2.c
//size_t	ft_strlen(char *str);
//char	*ft_strndup(char *src, int n);
void	tokenize_str(t_token *token, char *line, int *i);
void	tokenize_word(t_token *token, char *line, int *i);
void	tokenize_error(t_token *token);

/***/// lst_utils.c
void	lstadd_back(t_command **lst, t_command *new);
void	lstclear(t_command *lst);

/***/// ft_calloc.c
// static void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);

/***/// ft_strndup.c
size_t	ft_strlen(char *str);
char	*ft_strndup(char *src, size_t n);

/***/// substitute_var.c
void	substitute_var(t_token *token);

/***/// is_in_str.c
int		is_digit(char c);
int     is_in_str(char *str, char c);

/***/// quotes_split.c
char    **quotes_split(char const *str, char *sep);

/***/// free_all.c
void    free_all(char **split);

/***/// print_error.c
// static char	*ft_strcat_m(char *s1, char *s2);
void	print_error(char *str);

/***/// ft_strjoin_va.c
// static ...
char    *ft_strjoin_va(char *str, ...);

/***/// ft_strchr.c
char    *ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);

/***///  handle_specials.c
int		handle_quotes(char const *str, char q);
int		handle_redirections(char const *str);
int		handle_specials(char const *str);
int		handle_fd_redir(char const *str);
int		handle_word(char const *str, char *sep, int *i);

/***/// ft_split_mish.c
void	free_strtab(char **strtab);
char	**ft_split_mish(char const *str, char *sep);

// is_sep strndup 

// ft_calloc
// ft_strdup

////////////////////////////////////////////////////////////////////////////////

/***/// builtins1.c
char	*my_pwd(void);
int		my_cd(char *path);

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

#endif
