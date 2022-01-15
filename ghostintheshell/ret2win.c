#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void win() {
	system("cat flag.txt");
}

void stringLength() {
	char string[100];
	printf("Give me a string: ");
	gets(string);
	printf("String length: %u\n", (unsigned int)strlen(string));
}

void compareStrings() {
	char stringA[100];
	char stringB[100];
	printf("Give me the first string: ");
	gets(stringA);
	printf("Give me the second string: ");
	gets(stringB);
	if (!strcmp(stringA, stringB)) {
		puts("The strings are equal");
	}
	else {
		puts("The strings are different");
	}
}

void findChar() {
	char string[100];
	char* s;
	char c;

	printf("Give me a string: ");
	gets(string);
	printf("Give me a char: ");
	scanf("%c", &c);
	getchar();
	s = strchr(string, c);
	if (s == NULL) {
		puts("Char not in string");
	}
	else {
		puts("Char in string");
	}
}

void menu() {
	unsigned int option;
	while (1) {
		puts("\n---- String utils ----");
		puts("1 - String length");
		puts("2 - Compare two strings");
		puts("3 - Find char in string");
		puts("4 - Exit");
		printf("\n> ");
		scanf("%d", &option);
		getchar();
		if (option == 1) {
			stringLength();
		}
		else if (option == 2) {
			compareStrings();
		}
		else if (option == 3) {
			findChar();
		}
		else if (option == 4) {
			return;
		}
		else {
			puts("> Invalid option!");
		}
	}
}

int main() {
	setvbuf(stdin, 0, 2, 0);
	setvbuf(stdout, 0, 2, 0);
	menu();
	return 0;
}
