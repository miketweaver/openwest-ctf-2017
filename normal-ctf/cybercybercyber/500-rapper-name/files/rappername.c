#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "./whatsmyname.h"

#define INSZ	512

#define BANNER	"\
   ___            _  __                 \n\
  / _ \\___ ____  / |/ /__ ___ _  ___ ___\n\
 / , _/ _ `/ _ \\/    / _ `/  ' \\/ -_|_-<\n\
/_/|_|\\_,_/ .__/_/|_/\\_,_/_/_/_/\\__/___/\n\
         /_/                            \n\
"

#define PROMPT	"ENTER YOUR NAME:"

#define BEFORE	"From this day on"
#define AFTER	"will forevermore be referred to as:"

char global_debug;

char** name1;
char** name2;
char** name3;
unsigned char l1, l2, l3;

void init();
void cleanup();
void welcome();
void giveName();

void init() {
	int i;
	char* s;
	char* t;

	l1 = sizeof(name1stat)/sizeof(name1stat[0]);
	l2 = sizeof(name2stat)/sizeof(name2stat[0]);
	l3 = sizeof(name3stat)/sizeof(name3stat[0]);

	// we need to copy name_stat to name_, so it doesn't segfault when edited
	name1 = (char**)calloc(l1, sizeof(char*));
	for (i=0; i<l1; i++) {
		s = name1stat[i];
		t = (char*)calloc(strlen(s)+1,sizeof(char));
		memcpy(t, s, strlen(s));
		name1[i] = t;
	}
	name2 = (char**)calloc(l2, sizeof(char*));
	for (i=0; i<l2; i++) {
		s = name2stat[i];
		t = (char*)calloc(strlen(s)+1,sizeof(char));
		memcpy(t, s, strlen(s));
		name2[i] = t;
	}
	name3 = (char**)calloc(l3, sizeof(char*));
	for (i=0; i<l3; i++) {
		s = name3stat[i];
		t = (char*)calloc(strlen(s)+1,sizeof(char));
		memcpy(t, s, strlen(s));
		name3[i] = t;
	}
}

void cleanup() {
	int i;
	for (i=0; i<l1; i++) {
		free(name1[i]);
	}
	free(name1);
	for (i=0; i<l2; i++) {
		free(name2[i]);
	}
	free(name2);
	for (i=0; i<l3; i++) {
		free(name3[i]);
	}
	free(name3);
}

void welcome() {
	// bold red for header
	printf("\x1b[1m\x1b[31m\n");
	printf("%s", BANNER);
	printf("\x1b[0m\n");
	printf("%s\n\t", PROMPT);
}

void giveName() {
	int x;
	unsigned char s1;
	unsigned char s2;
	unsigned char s3;
	char* input;
	char* real_name;
	char* n1;
	char* n2;
	char* n3;
	
	input = (char*)calloc(INSZ, sizeof(char));
	real_name = (char*)calloc(INSZ, sizeof(char));
	s1 = 0;
	s2 = 0;
	s3 = 128;

	// get input
	fflush(NULL);
	if (fgets(input, INSZ-1, stdin) == NULL) {
		return;
	}
	//make the name
	for (x=0; x < strlen(input); x++) {
		s1 += input[x];
		s2 -= input[x];
		s3 += input[x];
	}
	s1 = s1 % l1;
	s2 = s2 % l2;
	s3 = s3 % l3;

	n1 = name1[s1];
	n2 = name2[s2];
	n3 = name3[s3];

	
	printf("\n\t%s, ", BEFORE);
	printf(input);
	printf("\t%s\n", AFTER);

	snprintf(real_name, INSZ-1, "%s%s %s", n1, n2, n3);

	printf("\x1b[1m\x1b[4m\x1b[31m");
	printf("\t\t%s\n\n", real_name);
	printf("\x1b[0m");

	if (global_debug) {
		printf("\nDEBUG n1:%p n2:%p n3:%p\n", n1, n2, n3);
	}

	if (strstr(real_name, "1337")) {
		printf("%s\n", FLAG); 	
	}

	free(real_name);
	free(input);
}

int main(int argc, char** argv) {
	global_debug = 1;
	init();
	welcome();
	giveName();
	cleanup();
	fflush(NULL);
	return 0;
}