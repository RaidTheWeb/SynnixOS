#pragma once
#ifndef _POLL_H_
#define _POLL_H_

/** @file
 * @brief Process polling
 * 
 */

/**
 * @brief Polling file descriptor
 * 
 */
struct pollfd {
    int fd;
    short events;
    short revents;
};

/**
 * @brief Poll operations enum
 * 
 */
enum {
    POLLIN,
};

/**
 * @brief Number file descriptors
 * 
 */
typedef int nfds_t;

/**
 * @brief Poll file descriptor
 * 
 * @param pollfds 
 * @param nfds 
 * @param timeout 
 * @return int 
 */
int poll(struct pollfd *pollfds, nfds_t nfds, int timeout);

#endif // _POLL_H_
