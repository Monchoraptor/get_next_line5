#include "get_next_line.h"

int main() {

//	char *s1= "";
//	char s2[] = "qwerty";
//	printf("======>%s\n", ft_strjoin(s1, s2));
//	(void)argc;
//	(void)argv;
	char **a;
	a = malloc(sizeof(char *) * 2000);
	int fd = open("prueba",O_RDONLY);

	int i = 0;
//	int r;
//	printf("1\n");
	while (get_next_line(fd, a) == 1)
	{
		printf(" %i = %p | %s \n", i, a[i], a[i]);
		i++;
	}
	printf(" %i = %p | %s \n", i, a[i], a[i]);

	int j = 0;
	while (a[j] != NULL)
	{
		free(a[j++]);
	}
	free(a);
	return (0);
}