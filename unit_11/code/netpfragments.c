#include <arpa/inet.h>
#include <stdint.h>
#include <sys/socket.h>
#include <sys/types.h>

// struct in_addr
// {
//     uint_32t s_addr; /* Address in network byte order (big-endian)*/
// };

uint32_t htonl(uint32_t hostlong);
uint16_t htons(uint16_t hostshort); /* 返回:按照网络字节顺序的值。 */

uint32_t ntohl(uint32_t netlong);
uint16_t ntohs(uint16_t netshort); /* 返回:按照网络字节顺序的值。 */

/* 返回：若成功返回1， 若src为非法点分十进制地址则为0， 若出差则为1 */
int inet_pton(AF_INET, const char *src, void *dst);

/* 返回：若成功则指向点分十进制字符串指针， 若出错则为NULL */
const char *inet_pton(AF_INET, const void *src, char *dst, socklen_t size);

/* IP socket address structure */
struct sockaddr_in
{
    uint16_t sin_family;       /* Protocol family (always AF_INET) */
    uint16_t sin_port;         /* Port number in network byte order */
    struct in_addr sin_addr;   /* IP address in network byte order */
    unsigned char sin_zero[8]; /* Pad to sizeof (struct sockaddr) */
};

/* Generic socket address stucture (for connect, bind , and accept ) */
struct sockaddr
{
    uint16_t sa_family; /* Protocol family */
    char sa_data[14]    /* Address data */
};

/* 创建套接字描述符  返回：若成功则为非负描述符，若出错则为-1 */
int socket(int domain, int type, int protocpl);

/* 想要使套接字成为连接的一个端点，用如下硬编码的参数来调用 socket 函数 */
clientfd = socket(AF_INET, SOCK_STREAM, 0);

/* 客户端调用 connect 函数来建立和服务器的链接  */
int connect(int clientfd, const struct sockaddr *addr, socklen_t addlen);

/* 返回：若成功则为0，若出错则为-1 */
int bind(int sockfd, const struct sockaddr *addr, socklen_t addrlen);

/* 返回：若成功则为0，若出错则为-1 */
int listen(int socket, int backlog);

/* 返回：若成功则为非负描述符，若出错则为-1 */
int accept(int listenfd, struct sockaddr *addr, int *addrlen);