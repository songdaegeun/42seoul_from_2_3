#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <stdlib.h>
#include <string.h>

// gcc test.c -I/opt/homebrew/opt/readline/include -L/opt/homebrew/opt/readline/lib -lreadline


int main()
{
	char *str;
	
	while(1) {
		str = readline("prompt:");
		if(str)
			printf("%s\n", str);
		else
			break;
		add_history(str);
		if(strcmp(str,"clr") == 0)
			rl_clear_history();
		free(str);
	}
	return (0);
}