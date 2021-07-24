#pragma once
#ifndef _SIGNAL_H_
#define _SIGNAL_H_

#include <basic.h>
#include <stdatomic.h>
#include <sys/types.h>

#define SIG_DFL (sighandler_t)0
#define SIG_IGN (sighandler_t)2

/** @file
 * @brief Signal operations
 * 
 */

/**
 * @brief Signal types
 * 
 */
enum signal {
    SIGABRT,
    SIGALRM,
    SIGBUS,
    SIGCHLD,
    SIGCONT,
    SIGFPE,
    SIGHUP,
    SIGILL,
    SIGINFO,
    SIGINT,
    SIGKILL,
    SIGPIPE,
    SIGPROF,
    SIGQUIT,
    SIGSEGV,
    SIGSTOP,
    SIGTSTP,
    SIGSYS,
    SIGTERM,
    SIGTRAP,
    SIGTTIN,
    SIGTTOU,
    SIGURG,
    SIGUSR1,
    SIGUSR2,
    SIGVTALRM,
    SIGXCPU,
    SIGWINCH,
};

#define SIG_BLOCK 1
#define SIG_UNBLOCK 2
#define SIG_SETMASK 3

/**
 * @brief Unsigned 32 bit sigset
 * 
 */
typedef uint32_t sigset_t;
/**
 * @brief Signal handler type
 * 
 */
typedef void (*sighandler_t)(int);
/**
 * @brief Atomic integer type
 * 
 */
typedef atomic_int sig_atomic_t;

/**
 * @brief Empty signal set
 * 
 * @param set 
 * @return int 
 */
int sigemptyset(sigset_t *set);

/**
 * @brief Full signal set
 * 
 * @param set 
 * @return int 
 */
int sigfillset(sigset_t *set);

/**
 * @brief Add signal set
 * 
 * @param set 
 * @param signum 
 * @return int 
 */
int sigaddset(sigset_t *set, int signum);

/**
 * @brief Delete signal set
 * 
 * @param set 
 * @param signum 
 * @return int 
 */
int sigdelset(sigset_t *set, int signum);

/**
 * @brief Signal is member of x
 * 
 * @param set 
 * @param signum 
 * @return int 
 */
int sigismember(const sigset_t *set, int signum);

#ifndef __kernel__

/**
 * @brief Signal process mask
 * 
 * @param op 
 * @param new 
 * @param old 
 * @return int 
 */
int sigprocmask(int op, const sigset_t *new, sigset_t *old);

/**
 * @brief Signal action
 * 
 * @param signum 
 * @param handler 
 * @param flags 
 * @return sighandler_t 
 */
sighandler_t sigaction(int signum, sighandler_t handler, int flags);

/**
 * @brief Signal
 * 
 * @param signum 
 * @param handler 
 * @return sighandler_t 
 */
sighandler_t signal(int signum, sighandler_t handler);

/**
 * @brief Kill PID
 * 
 * @param pid 
 * @param sig 
 * @return int 
 */
int kill(pid_t pid, int sig);

/**
 * @brief Raise a signal
 * 
 * @param signal 
 * @return int 
 */
int raise(int signal);

#endif // __kernel__

#endif // _SIGNAL_H_
