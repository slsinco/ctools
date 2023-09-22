#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <pwd.h>

void main (int argc, char* argv[]) {

        if (argc < 2) {
                printf("\n***************************************\n");
                printf("* Unexpected Number of Arguments.     *\n");
                printf("* Usage: getuser <user>               *\n");
                printf("***************************************\n");
        } else {

                struct passwd *pw_data;

                //pw_data = getpwnam ("root");
                pw_data = getpwnam (argv[1]);
                if (!pw_data) {
                        printf("User Not Found\n");
                } else {
                        printf ("username: %s\n", pw_data->pw_name);
                        printf ("uid: %d\n", pw_data->pw_uid);
                        printf ("gid: %d\n", pw_data->pw_gid);
                        printf ("user info: %s\n", pw_data->pw_gecos);
                        printf ("home: %s\n", pw_data->pw_dir);
                        printf ("shell: %s\n", pw_data->pw_shell);
                }
        }

}