#include <stdio.h>
#include <stdlib.h>

int main() {

    printf("\n\nhelooo\n\n");

    // check python3.9 exist or not
    int status = system("which python3 > /dev/null 2>&1");

    if (status == 0) {
        // if yes, check ver and write to log
        FILE *fp = popen("python3 --version", "r");
        if (fp == NULL) {
            perror("popen failed");
            return 1;
        }

        char version[128];
        if (fgets(version, sizeof(version), fp) != NULL) {
            printf("%s", version); // print to console

            FILE *log = fopen("/tmp/python_ver.log", "w");
            if (log != NULL) {
                fputs(version, log);
                fclose(log);
            } else {
                perror("cannot write to /tmp/python_ver.log");
                pclose(fp);
                return 1;
            }
        } else {
            fprintf(stderr, "could not read version output.\n");
            pclose(fp);
            return 1;
        }

        pclose(fp);
        return 0;
    } else {
        fprintf(stderr, "Error: Python 3 not found\n");
        return 1;
    }
}
