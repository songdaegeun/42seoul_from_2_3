#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <stdlib.h>
// gcc test.c -lreadline 
int main()
{
	char *str;
	
	str = readline("prompt:");
	add_history(str);
	free(str);
	HIST_ENTRY *mylist = history_get(3);
	const char *stradd = mylist->line;
	printf("%s\n", stradd);
	
	free(mylist);
	return (0);
}