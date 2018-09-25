#include<stdio.h>

char    **ft_split_whitespaces(char *str);

char    print_table(char **tab)
{
    int i = 0;
    int j = 0;

    while (tab[i])
    {
        while (tab[i][j])
        {
            printf("%c", tab[j]);
            i++;
            printf("\n");
        }
        printf("\n");
    }
}

int     main(int ac, char **av)
{
    (void)ac;
    char **tab;
    tab = ft_split_whitespaces(av[1]);
    print_table(tab);
    return 0;
}