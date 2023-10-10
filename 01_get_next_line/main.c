#include "get_next_line.h"
#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>

int	main(void)
{
	int	fd;
	char *str;

	fd = open("test.txt", O_RDONLY);
/*   	while (str)
    {
        str = get_next_line(fd);
       	printf("%s", str);
    }*/
    str = get_next_line(fd);
    printf("%s", str);
	return (0);
}
