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

    while (ft_isspace(str[i]))
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

    while (str)
    {
        while (ft_isspace(*str))
            *str++;
        while (!ft_isspace(*str))
        {
           *str++;
           i++;
        }
    }
    return (i);
}

//char        **ft_split_whitespaces(*str)
//{
//
//}

int     main(int argc, char **argv)
{
    if (argc != 2)
        return 0;
    
    int i = ft_wordcount(argv[1]);
    printf("il y a %d mots", i);
    return 0;
}
