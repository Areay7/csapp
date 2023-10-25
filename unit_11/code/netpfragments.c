#include <arpa/inet.h>
#include <stdint.h>

// struct in_addr
// {
//     uint_32t s_addr; /* Address in network byte order (big-endian)*/
// };


uint32_t htonl(uint32_t hostlong);
uint16_t htons(uint16_t hostshort); /* 返回:按照网络字节顺序的值。 */

uint32_t ntohl(uint32_t netlong);
uint16_t ntohs(uint16_t netshort);  /* 返回:按照网络字节顺序的值。 */

/* 返回：若成功返回1， 若src为非法点分十进制地址则为0， 若出差则为1 */
int inet_pton(AF_INET, const char *src, void *dst);

/* 返回：若成功则指向点分十进制字符串指针， 若出错则为NULL */
const char *inet_pton(AF_INET, const void *src, char *dst, socklen_t size);
