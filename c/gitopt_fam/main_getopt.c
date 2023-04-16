#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define OPT_STR "h:"

int main(int argc, char *argv[])
{
	int opt;
	int did_it = 0;

	while ((opt = getopt(argc, argv, OPT_STR)) != -1) {
		switch (opt) {
		case 'h':
			/* print help menu/screen */
			printf("Enter into the -h command!\n");
			did_it = 1;
		break;

		default: /* '?' */
			/* print error about some invalid arg */
			printf("DEFAULTED ON THE ARGUMENT...\n");
			exit(EXIT_FAILURE);
		}
	}

	printf("\ndid_it = %d, argc = %d, optind = %d\n", did_it, argc, optind);

	if (optind >= argc) {
		printf("Expected argument after options? optind >= argc.");
		exit(EXIT_FAILURE);
	}


	/* If there is a argument that is not attached to a option (ex. -x) */

	exit(EXIT_SUCCESS);
}

