#include "minishell.h"

int main(int argc, char **argv)
{
	char *str[10];

	(void ) argc;
	(void ) argv;
	str[0] = "-n";
	str[1] = "cat' sdgd '";
	str[2] = '\0';
	echo(str);

	return 0;
}
