#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

struct sockaddr_in6 {
    __SOCKADDR_COMMON (sin6_);
    in_port_t sin6_port; // transport layer port #
    u_int32_t sin6_flowinfo; // IPv6 flow information
    struct in6_addr sin6_addr; // IPv6 address
    u_int32_t sin6_scope_id; // IPv6 scope-id
};