#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void printHelp() {
    printf("Usage: program [options]\n");
    printf("Options:\n");
    printf("  -n <number>       Process an integer argument\n");
    printf("  -f <number>       Process a floating-point argument\n");
    printf("  -i <file1> <file2>  Process multiple input files\n");
    printf("  -v                Enable verbose mode\n");
    printf("  --help            Display this help message\n");
}

int main(int argc, char *argv[]) {
    int verbose = 0; // デフォルトではverboseモードはオフ
    long integerArg = 0; // デフォルト値
    double floatArg = 0.0; // デフォルト値

    if (argc < 2) {
        printHelp();
        return 1;
    }

    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "--help") == 0) {
            printHelp();
            return 0;
        } else if (strcmp(argv[i], "-v") == 0) {
            verbose = 1;
        } else if (strcmp(argv[i], "-n") == 0 && i + 1 < argc) {
            // 整数引数の処理
            char *endptr;
            integerArg = strtol(argv[++i], &endptr, 10);
            if (*endptr != '\0') {
                printf("Error: Invalid integer format '%s'\n", argv[i]);
                return 1;
            }
        } else if (strcmp(argv[i], "-f") == 0 && i + 1 < argc) {
            // 浮動小数点数引数の処理
            char *endptr;
            floatArg = strtod(argv[++i], &endptr);
            if (*endptr != '\0') {
                printf("Error: Invalid floating-point format '%s'\n", argv[i]);
                return 1;
            }
        } else if (strcmp(argv[i], "-i") == 0) {
            // 複数の入力ファイル引数の処理
            printf("Input files:\n");
            while (i + 1 < argc && argv[i + 1][0] != '-') {
                printf("  %s\n", argv[++i]);
            }
        } else {
            printf("Error: Unknown argument '%s'. Use --help for usage information.\n", argv[i]);
            return 1;
        }
    }

    // 引数の使用例
    if (verbose) {
        printf("Verbose mode is enabled.\n");
    }
    printf("Integer argument: %ld\n", integerArg);
    printf("Floating-point argument: %f\n", floatArg);

    return 0;
}

