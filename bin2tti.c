/* Convert .BIN to TTI */
/* © 2016 Chris Young <chris@unsatisfactorysoftware.co.uk> */

#include <stdio.h>
#include <malloc.h>
#include <stdint.h>

void write_line(const char *buffer, int line)
{
	int i;
	char *p = buffer;
	printf("OL,%d,", line);

	for(i=0; i<40; i++) {
		if(*p < 0x20) *p += 0x80;
		printf("%c", *p);
		p++;
	}

	printf("\n");
}

int main(int argc, char **argv)
{
	int i;
	char *buffer = malloc(42);

	printf("PN,52100\n"); // page
	printf("CT,5,T\n"); // speed
	printf("DE,bin2tti\n");
	printf("PS,8040\n");
	printf("SC,0000\n"); // subpage

	for(i = 1; i < 25; i++) {
		scanf("%40c", buffer);
		write_line(buffer, i);
//		printf("%s", buffer);
	}

	printf("FL,100,100,100,100,100,100\n"); // fastext links

	free(buffer);
	return 0;
}
