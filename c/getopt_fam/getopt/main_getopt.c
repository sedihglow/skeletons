#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define OPTSTR_
#define OPTSTR_
#define OPTSTR_
#define OPTSTR_
#define OPTSTR_
#define OPTSTR_

#define OPTSTR_DFLT " "

/* Def sent to getopt(), use this for optstr */
#define OPTSTR OPTSTR_DFLT

int main(int argc, char *argv[])
{
	int opt;
	int once = 0; /* used just to show opterr's default value for ex. */

	//opterr = 0;

	/* TODO: See what opterr behaves like before and after call to getopt.
	 *	 check its default. Google if it is set when declared globally
	 *	 or if the first call to getopt sets the default value for
	 *	 opterr.
	 *
	 *	 Test hitting all cases in the switch.
	 *
	 *	 Test all types of optstrings for testing and example/ref.
	 */
	printf("Default opterr before first call to getopt(): %d\n", opterr);

	while ((opt = getopt(argc, argv, OPTSTR)) != -1) {
		if (once == 0) {
			once = 1;
			printf("Defailt opterr: %d\n", opterr);
		}

		switch (opt) {
		case 'h':
			/* print help menu/screen */
			printf("Enter into the -h command!\n");
		break;

		case '?':
			/*
			 * optopt holds the erroneous option character that
			 * was found.
			 */
			printf("Erroneous option character found: -%c in optopt"
			       ".\n", optopt);
		break;
		case ':':

			printf("Missing option argument: TST: optopt = %c is\n"
			       "still just the option character that has the\n"
			       "missing argument i think will be the case.\n",
			       optopt);
		break;
		default:
			/* print error about some invalid arg */
			printf("DEFAULTED ON THE ARGUMENT...\n");
			printf("optopt: %c, optind: %d, argc: %d, opterr: %d,"
			       "opt (c): %c\n",
			       optopt, optind, argc, opterr, opt);
			exit(EXIT_FAILURE);
		}
	}

	printf("optopt: %c, optind: %d, argc: %d, opterr: %d,"
	       "opt (c): %c\n",
	       optopt, optind, argc, opterr, opt);
	/*
	 * If there is a argument that is not attached to a option (ex. -x)
	 * optind will be placed at the first instance of a non option argument
	 * getopt will place all non-option arguments at the
	 * end of the argv while its processing, permutating it
	 * so if there are non option arguemnts, optind will
	 * point to the first one, and incrementing optind will
	 * go to the following non option argument index since
	 * they are now stored at the end of the array.
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
		printf("Expected argument after options. optind >= argc.\n");
		exit(EXIT_FAILURE);
	}

	exit(EXIT_SUCCESS);
}
