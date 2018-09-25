#include <stdlib.h>
#include <stdio.h>

int		ft_is_space(char str)
{
	if (str != '\0' && (str == '\t' || str == '\n' || str == 32))
		return (1);
	else
		return (0);
}

int		ft_count_words(char *str)
{
	int		i;
	int		word_nb;

	i = 0;
	word_nb = 0;
	while (ft_is_space(str[i]) == 1 && str[i] != '\0')
		i++;
	while (str[i] != '\0')
	{
		while (ft_is_space(str[i]) == 0 && str[i] != '\0')
			i++;
		while (ft_is_space(str[i]) == 1 && str[i] != '\0')
			i++;
		word_nb++;
	}
	return (word_nb);
}

int		ft_size_word(char *str)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (ft_is_space(str[i]) == 1 && str[i] != '\0')
		i++;
	while (ft_is_space(str[i + j]) == 0 && str[i + j] != '\0')
		j++;
	return (j);
}

char	**ft_split_whitespaces(char *str)
{
	int		i;
	int		word_count;
	int		words_added;
	char	**word_table;
	char	*word_to_add;

	i = 0;
	words_added = 0;
	word_count = ft_count_words(str);
	word_table = malloc(sizeof(char*) * (word_count + 1));
	while (words_added < word_count)
	{
		word_to_add = malloc(sizeof(char) * (ft_size_word(str) + 1));
		while (ft_is_space(str[0]) == 1 && str[0] != '\0')
			str++;
		while (ft_is_space(str[0]) == 0 && str[0] != '\0')
			word_to_add[i++] = *str++;
		word_to_add[i] = '\0';
		word_table[words_added++] = word_to_add;
		i = 0;
	}
	word_table[words_added] = 0;
	if (word_count == '\0')
		word_table[words_added] = 0;
	return (word_table);
}

//int     main(int argc, char **argv)
//{
//    if (argc != 2)
//        return 0;
    
//    int nb;
//    nb = ft_count_words(argv[1]);
//    printf("%d\n", nb);
 //   char **tab = ft_split_whitespaces(argv[1]);
///    int i = 0;
//    while (tab)
//   {
///        printf("%s", tab[i]);
//        i++;
///    }
//    return 0;
//}