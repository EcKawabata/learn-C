#include <stdlib.h>
#include <stdio.h>

int     ft_isspace(char c)
{
    if (c == 32)
        return (1);
    else
        return (0);
}

int     ft_wordcount(char *str)
{
    int i = 0;
    int cpt = 0;

    while (ft_isspace(str[i]) && str[i])
        str[i++];
    while (str[i])
    {
        while (ft_isspace(str[i]) && str[i])
            *str++;
        while (!ft_isspace(str[i]) && str[i])
            str[i++];
        cpt++;
    }
    return (cpt);
}

int     ft_wordsize(char *str)
{
    int i = 0;

    while (ft_isspace(str[i]) && str[i])
        str++;
    while (!ft_isspace(str[i]) && str[i])
        i++;
    return (i);
}

char    **ft_split_whitespaces(char *str)
{
    int i = 0;
    int nb_words = 0;
    int nb_words_added = 0;
    char *str_lig;
    char **str_table;

    printf("Allo1\n");
    nb_words = ft_wordcount(str);
    str_table = malloc(sizeof(char*) * (nb_words + 1));
    while (str && nb_words > nb_words_added)
    {
        printf("Allo2\n");
        str_lig = malloc(sizeof(char) * (ft_wordsize(str) + 1));
        while (ft_isspace(*str) == 1)
            str++;
        printf("Allo3\n");
        while (str && ft_isspace(*str) == 0)
            str_lig[i++] = *str++;
        str_lig[i] = '\0';
        str_table[nb_words_added++] = str_lig;
        i = 0;
    }
    if (nb_words == 0)
        str_table[nb_words_added] = 0;
    str_table[nb_words_added] = 0;
    printf("Allo4\n");
    return (str_table);
}

int     main(int argc, char **argv)
{
    if (argc != 2)
        return 0;
    
    int nb;
    nb = ft_wordsize(argv[1]);
    printf("%d\n", nb);
    char **tab = ft_split_whitespaces(argv[1]);
    int i = 0;
    while (tab)
    {
        printf("%s", tab[i]);
        i++;
    }
    return 0;
}
