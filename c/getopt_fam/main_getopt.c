#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define OPT_STR "h:"

int main(int argc, char *argv[])
{
	int opt;

	while ((opt = getopt(argc, argv, OPT_STR)) != -1) {
		switch (opt) {
		case 'h':
			/* print help menu/screen */
			printf("Enter into the -h command!\n");
		break;
		default: /* '?' */
			/* print error about some invalid arg */
			printf("DEFAULTED ON THE ARGUMENT...\n");
			exit(EXIT_FAILURE);
		}
	}

	printf("\nargc = %d, optind = %d\n", argc, optind);

	/*
	 * If there is a argument that is not attached to a option (ex. -x)
	 * optind will be placed at the first instance of a non option argument
	 *
	 * therefore, if we are expecting a non option argument optind would not
	 * be >= argc. If there is no option argument optind is set = argc
	 *
	 * If no non option argument is expected, then this can be asjusted to
	 * make sure optind is not pointing at something (a non option argument)
	 * or can be removed all together if it doesnt matter for
	 * implementation
	 * */
	if (optind >= argc) {
		printf("Expected argument after options. optind >= argc.");
		exit(EXIT_FAILURE);
	}

	exit(EXIT_SUCCESS);
}

