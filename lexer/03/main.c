#include "lexer.h"

static void print_lst(t_command *lst)
{
    int i;

    if (lst)
    {
        i = 0;
        while (lst->token && lst->token[i])
        {
            printf("|%s|\n", lst->token[i]);
            i++;
        }
    }
    return ;
}

int main(void)
{
    //s_command   *lst;
    t_command   *tmp;
    char        *str;

    tmp = NULL;
    str = readline("$> ");
    while (str)
    {
        add_history(str);	// check la string
        tmp = lexer(str);
        print_lst(tmp);
        free(tmp);
        free(str);
        str = readline("$> ");
    }
	clear_history();
    return (0);
}
