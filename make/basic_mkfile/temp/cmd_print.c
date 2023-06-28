#include <stdio.h>
#include <stdlib.h>

typedef unsigned long long ull_t;

/*
 * $ cmd seed msg_print_cnt "msg_string" line_limit
 *
 * likely bug when written: It may go over the line limit depending on what i
 * do in the loop. Its not worth it making it exact i dont think but if its not
 * really lame ill make it happen. But before writing im not garunteeing the
 * line prints will be exect.
 *
 * obv theres no error checking or anything unless i just tangent another hard
 * tangent into the rest of the abyss.
 *
 *
 * goood nuff, it lines up when using 20 as the line limit. It ends as 22
 * because of the two lines i print at the end with final line count and shit.
 *
 * So theres work to do if i ever want to make it exact on the line limit.
 *
 *
 * would be interesting to do a program that makes blank files of any
 * particular size like the files used at that one place. Apparently theres
 * a win cli prog to do it? But also that means prolly already a linux one.
 * look into it, then write one? :D
 */
int main(int argc, char *argv[])
{
	unsigned int seed = atol(argv[1]);
	char *cli_msg = argv[3];
	ull_t line_limit = atoll(argv[4]);
	unsigned long cli_msg_cnt = strtoul(argv[2], NULL, 0);

	unsigned long i = 0;
	ull_t line_cnt = 0;

	/* if case where its less than whatever lines before the while loop */

	printf("Printing to test where this goes.\n"
               "Doing another line because yeah.\n");
	line_cnt += 2;

	srandom(seed);

	while (line_cnt < line_limit) {
		for (i=0; i < cli_msg_cnt; ++i) {
			printf("%s |\n", cli_msg);
			++line_cnt;
		}


		printf("%ld |\n", random());
		++line_cnt;
	}

	printf("--- FINAL LINE COUNT PRINTED (INCLUDING THESE) ---\n"
	       "          CNT RES: %lld\n", line_cnt += 2);

	exit(EXIT_SUCCESS);
}
