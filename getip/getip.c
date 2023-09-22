#include <stdio.h>
#include <unistd.h>
#include <sys/param.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

void main () {
        char address[MAXHOSTNAMELEN];
        struct hostent *h;
        struct in_addr **a;

        gethostname(address, MAXHOSTNAMELEN);
        printf ("hostname: %s\n", address);

        h = gethostbyname(address);
        a = (struct in_addr**) h->h_addr_list;

        for (int i = 0; a[i] != NULL; i++) {
                printf("IP Address %d: %s\n", i+1, inet_ntoa(*a[i]));
        }

}

