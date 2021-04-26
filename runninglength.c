#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#define MAX_RLEN 1000


/*returns the run length encodes string for the source string*/
char *compress(char *string);
char *decompress(char *string);

int main(void){
    char string[] = "aaaaaaaatttttttgygygyghhhhhhh   strr";
    char* res = compress(string);
    printf("%s \n", res);

    printf("hihiih\n");
    char* decoded = decompress(res);
    printf("blahhh %s", decoded);
    /*getchar();*/
    
    return 0;
}

char* compress(char *string){
    int rlength;
    char count[MAX_RLEN];
    int len = strlen(string);

    char* dest = (char*)malloc(sizeof(char) * (len * 2 + 1));

    int i, j = 0, k;

    /* traverse input string*/
    for (i = 0; i < len; i++) {
 
        /* Get first char */
        dest[j++] = string[i];
 
        /* count number of times char repeats*/
        rlength = 1;
        while (i + 1 < len && string[i] == string[i + 1]) {
            rlength++;
            i++;
        }
 
        /* Store count in a character array count[] */
        sprintf(count, "%d", rlength);
 
        /* Copy the count[] to dest */
        for (k = 0; *(count + k); k++, j++) {
            dest[j] = count[k];
        }
    }
 
    /*terminate destination string */
    dest[j] = '\0';
    return dest;
}



char* decompress(char *string){
    char new_string[MAX_RLEN];
    char *array_ptr = new_string;
    int length = strlen(string);

    printf("%c \n", string[0]);
    printf("%c \n", string[1]);
    printf("%c \n", string[2]);
    printf("%c \n", string[3]);
    printf("%c \n", string[4]);

    int i, j, k=0;
    for (i = 0; i < length; i++){
        if(i%2 == 0){
            printf("%d", i);
            printf("repeat num: %d", string[i+1]);

            int num_repeat = string[i + 1];
            for (j = 0; j < num_repeat; j++){
                new_string[k] = string[i];
                k++;
            }
        }
    }
    return array_ptr;
}
