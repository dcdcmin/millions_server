#ifndef UTILS_H
#define UTILS_H

int co_sleep(int timeout);
int fd_set_nonblock(int fd);
int fd_pool(int fd, int timeout);
int socket_create(unsigned port, const char *ip, bool reuse);
void sockaddr_init(char *ip, const unsigned port, struct sockaddr_in &addr);

int read_n(int sock, unsigned char* buf, int len);
int write_n(int sock, unsigned char* buf, int len);

#endif//UTILS_H
