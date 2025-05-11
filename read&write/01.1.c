// #include<stdio.h>
// #include<inttypes.h>
// #include<stdlib.h>
// #include<errno.h>
// #include<string.h>



// int main(void) {
//     FILE* file_stream = NULL;
//     char buffer[256];

//     errno_t err = fopen_s(&file_stream, "D:\\桌面11\\1.txt", "r");

//     if (err != 0 || file_stream == NULL)
//     {
//         printf("error\n");
//         return EXIT_FAILURE;
//     }
//     while (fgets(buffer, sizeof(buffer), file_stream) != NULL) {
//         printf("%s", buffer);
//     };
    
//     memset(buffer, 0, sizeof(buffer));//clear the buffer before reusing it
//     printf("\n");

// 	rewind(file_stream);// Reset the file position indicator to the beginning of the file


//     int ch;
//     while ((ch = fgetc(file_stream)) != EOF) {
//         putchar(ch);
//     }
//     if (fclose(file_stream) != 0) {
// 		perror("Error closing file");
// 		return EXIT_FAILURE;
//     }
//     return 0;

// }



#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

int main(void) {
    FILE* file_stream = NULL;
    char buffer[256];

    errno_t err = fopen_s(&file_stream, "D:\\桌面11\\1.txt", "r");

    if (err != 0 || file_stream == NULL) {
        perror("Failed to open file111");
        return EXIT_FAILURE;
    }

    // First read: using fgets
    while (fgets(buffer, sizeof(buffer), file_stream) != NULL) {
        printf("%s", buffer);
    }
    printf("\n");

    rewind(file_stream); // Reset to beginning of file

    // Second read: using fgetc
    int ch;
    while ((ch = fgetc(file_stream)) != EOF) {
        putchar(ch);
    }

    if (fclose(file_stream) != 0) {
        perror("Error closing file");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}