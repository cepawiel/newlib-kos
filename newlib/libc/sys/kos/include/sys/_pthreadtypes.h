/*
 *  Written by Colton Pawielski <cepawiel@mtu.edu>.
 *
 *  COPYRIGHT (c) 2022.
 *
 *  Permission to use, copy, modify, and distribute this software for any
 *  purpose without fee is hereby granted, provided that this entire notice
 *  is included in all copies of any software which is or includes a copy
 *  or modification of this software.
 *
 *  THIS SOFTWARE IS BEING PROVIDED "AS IS", WITHOUT ANY EXPRESS OR IMPLIED
 *  WARRANTY.  IN PARTICULAR,  THE AUTHOR MAKES NO REPRESENTATION
 *  OR WARRANTY OF ANY KIND CONCERNING THE MERCHANTABILITY OF THIS
 *  SOFTWARE OR ITS FITNESS FOR ANY PARTICULAR PURPOSE.
 */

#ifndef _SYS__PTHREADTYPES_H_
#define	_SYS__PTHREADTYPES_H_

#if defined(_POSIX_THREADS)

#include <sys/sched.h>
// #include <sys/cpuset.h>
// #include <sys/lock.h>

// Missing structs we don't care about in this impl.
/** \brief  POSIX mutex attributes.

    Not implemented in KOS.

    \headerfile sys/sched.h
*/
typedef struct {
    // Empty
} pthread_mutexattr_t;

/** \brief  POSIX condition variable attributes.

    Not implemented in KOS.

    \headerfile sys/sched.h
*/
typedef struct {
    // Empty
} pthread_condattr_t;

/** \brief  POSIX thread attributes.

    Not implemented in KOS.

    \headerfile sys/sched.h
*/
typedef struct {
    // Empty
} pthread_attr_t;

// Map over KOS types. The mutex/condvar maps have to be pointers
// because we allow _INIT #defines to work.
typedef kthread_t * pthread_t;      /**< \brief POSIX thread type */
typedef mutex_t pthread_mutex_t;    /**< \brief POSIX mutex type */
typedef condvar_t pthread_cond_t;   /**< \brief POSIX condition type */

// These, on the other hand, map right over.
typedef kthread_once_t pthread_once_t;  /**< \brief POSIX once control */
typedef kthread_key_t pthread_key_t;    /**< \brief POSIX thread data key */

#define _PTHREAD_MUTEX_INITIALIZER  MUTEX_INITIALIZER
#define _PTHREAD_COND_INITIALIZER   COND_INITIALIZER
#define _PTHREAD_ONCE_INIT          { 1, 0 }  /* is initialized and not run */
// #define _PTHREAD_RWLOCK_INITIALIZER ((pthread_rwlock_t) 0xFFFFFFFF)


#endif /* defined(_POSIX_THREADS) */

#endif /* ! _SYS__PTHREADTYPES_H_ */