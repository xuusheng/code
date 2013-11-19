#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <sys/socket.h>

int main(void)
{

     int sockfd;
     struct sockaddr_in dest_addr;
     sockfd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
     dest_addr.sin_family=AF_INET;
     dest_addr.sin_port = htons(0x979);
     dest_addr.sin_addr.s_addr = inet_addr("192.168.51.164");
     memset(dest_addr.sin_zero, 0, 8);
     int r = connect(sockfd, (struct sockaddr *)&dest_addr, sizeof(struct sockaddr));
     printf("%d\n", r);
     
     sendto(sockfd, "1_iptux_0#5#2:2:xuusheng-pc:288:vivik", 100, 0, (struct sockaddr *)&dest_addr, sizeof(struct sockaddr));
     
     return 0;
}
