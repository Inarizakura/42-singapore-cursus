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
	str = get_next_line(fd);
  	while (str)
    {
       	printf("%s", str);
		str = get_next_line(fd);
    }
//	str = get_next_line(fd);
//	printf("%s", str);
	return (0);
}
