#include "get_next_line.h"

int main() {

//	char *s1= "";
//	char s2[] = "qwerty";
//	printf("======>%s\n", ft_strjoin(s1, s2));
//	(void)argc;
//	(void)argv;
//	char **a;
//	a=NULL;
//	a = malloc(sizeof(char *) * 5000);
//	int fd = open("prueba",O_RDONLY);
//
//	char s[BUFFER_SIZE + 1];
//	int i = 0;
//	printf("---->%zi\n", read(fd, s, BUFFER_SIZE));
//	int r;
//	printf("1\n");
//	while ((r = get_next_line(fd, a)) == 1)
//	{
//		//printf("1\n");
//		//printf("ret:%i\n",r);
//		printf(" %i = %p | %s \n", i, a[i], a[i]);
//		i++;
//	}
//	printf("1\n");
//		printf("ret:%i\n",r);
//	printf(" %i = %p | %s \n", i, a[i], a[i]);
//
//	int j = 0;
//	while (a[j] != NULL)
//	{
//		free(a[j++]);
//	}
//	free(a);
	//system("leaks a.out");
	char	*line;
	int		fd;
	int		status;
	int		line_count;

		fd = open("prueba", O_RDONLY);
	line_count = 0;
	while (((status = get_next_line(fd, &line)) == 1))
	{
		printf("97\n");
		printf(" %i = %p | %s \n", line_count, line, line);
		printf("98\n");
		if(*line)
			free(line);
		printf("--------------------------------------\n");
		printf("--------------------------------------\n");
		printf("--------------------------------------\n");
		line_count++;
	}
		printf(" %i = %p | %s \n", line_count, line, line);
//	if (status == 0)
//		free(line);
	//system("leaks a.out");
	return (0);
		}
