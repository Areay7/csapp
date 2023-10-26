/* dd2hex.c */

#include <stdio.h>
#include <stdlib.h> 
#include <arpa/inet.h>
#include <sys/types.h>
#include <error.h>

void unix_error(char *msg)
{
    perror(msg);
    exit(0);
}

void app_error(char *msg)
{
    perror(msg);
    exit(0);
}

int main(int argc,char **argv)
{
    if (argc != 2)
    {
        fprintf(stderr, "usage %s <dotted-decimal> \n", argv[0]);
        exit(0);
    }

    struct in_addr inaddr;

    int rc;
    rc = inet_pton(AF_INET, argv[1], &inaddr);

    if (rc == 0)
    {
        app_error("inet_pton error: invalid dotted-decimal address .");
    }
    else if (rc < 0)
    {
        unix_error("inet_pton error");
    }
    
    printf("0x%x\n", ntohl(inaddr.s_addr));
}