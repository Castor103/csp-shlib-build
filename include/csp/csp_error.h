/*
Cubesat Space Protocol - A small network-layer protocol designed for Cubesats
Copyright (C) 2012 GomSpace ApS (http://www.gomspace.com)
Copyright (C) 2012 AAUSAT3 Project (http://aausat3.space.aau.dk) 

This library is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public
License as published by the Free Software Foundation; either
version 2.1 of the License, or (at your option) any later version.

This library is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public
License along with this library; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
*/

#ifndef _CSP_ERROR_H_
#define _CSP_ERROR_H_

/**
   @file

   Error codes.
*/

#ifdef __cplusplus
extern "C" {
#endif

/**
   @defgroup CSP_ERR CSP error codes.
   @{
*/
#define CSP_ERR_NONE		 0		/**< No error */
#define CSP_ERR_NOMEM		-1		/**< Not enough memory */
#define CSP_ERR_INVAL		-2		/**< Invalid argument */
#define CSP_ERR_TIMEDOUT	-3		/**< Operation timed out */
#define CSP_ERR_USED		-4		/**< Resource already in use */
#define CSP_ERR_NOTSUP		-5		/**< Operation not supported */
#define CSP_ERR_BUSY		-6		/**< Device or resource busy */
#define CSP_ERR_ALREADY		-7		/**< Connection already in progress */
#define CSP_ERR_RESET		-8		/**< Connection reset */
#define CSP_ERR_NOBUFS		-9		/**< No more buffer space available */
#define CSP_ERR_TX		-10		/**< Transmission failed */
#define CSP_ERR_DRIVER		-11		/**< Error in driver layer */
#define CSP_ERR_AGAIN		-12		/**< Resource temporarily unavailable */
#define CSP_ERR_HMAC		-100		/**< HMAC failed */
#define CSP_ERR_XTEA		-101		/**< XTEA failed */
#define CSP_ERR_CRC32		-102		/**< CRC32 failed */
#define CSP_ERR_SFP		-103		/**< SFP protocol error or inconsistency */
/**@}*/

typedef enum csp_error_t {
   /**
    Success - ok (POSIX).
   */
   CSP_OK = 0,
   /**
    Operation not permitted (POSIX.1: EPERM).
   */
   CSP_ERROR_PERM = -1,
   /**
    Interrupted system call (or Interrupted function call) (POSIX: EINTR).
   */
   CSP_ERROR_INTR = -4,
   /**
    Input/output error (POSIX.1: EIO)
   */
   CSP_ERROR_IO = -5,
   /**
    Resource temporarily unavailable (may be the same value as EWOULDBLOCK) (POSIX.1: EAGAIN).
   */
   CSP_ERROR_AGAIN = -11,
   /**
    Cannot allocate memory (or Not enough space) (POSIX.1: ENOMEM).
   */
   CSP_ERROR_ALLOC = -12,
   /**
    Permission denied (POSIX.1: EACCES).
   */
   CSP_ERROR_ACCESS = -13,
   /**
    Reply length and expected lenth are different
   */
   CSP_ERROR_REPLY_LENGTH = -14,
   /**
    Device or resource busy (POSIX.1: EBUSY).
   */
   CSP_ERROR_BUSY = -16,
   /**
    File exists (POSIX.1-2001: EEXIST).
   */
   CSP_ERROR_EXIST = -17,
   /**
    Invalid argument (POSIX.1: EINVAL).
   */
   CSP_ERROR_ARG = -22,
   /**
    Function not implemented (POSIX.1: ENOSYS)
   */
   CSP_ERROR_NOT_IMPLEMENTED = -38,
   /**
    Value too large to be stored in data type (POSIX.1: EOVERFLOW).
   Example: trying to put 50 characters into a 10 character array.
   @see CSP_ERROR_RANGE.
   */
   CSP_ERROR_OVERFLOW = -75,
   /**
    Operation not supported (POSIX.1: ENOTSUP)
   */
   CSP_ERROR_NOT_SUPPORTED = -95,
   /**
    Address already in use (POSIX.1: EADDRINUSE).
   */
   CSP_ERROR_IN_USE = -98,
   /**
    Connection reset (POSIX.1-2001: ECONNRESET).
   */
   CSP_ERROR_CONNECTION_RESET = -104,
   /**
    No buffer space available (POSIX.1 (XSI STREAMS option): ENOBUFS).
   */
   CSP_ERROR_NO_BUFFERS = -105,
   /**
    Timeout (POSIX.1-2001: ETIMEDOUT).
   */
   CSP_ERROR_TIMEOUT = -110,
   /**
    Connection already in progress (POSIX.1-2001: EALREADY).
   */
   CSP_ERROR_ALREADY_IN_PROGRESS = -114,

   /**
    Handle error (GOMspace).
   */
   CSP_ERROR_HANDLE = -2000,    // from errno.h: #define __ELASTERROR 2000       /* Users can add values starting here */
   /**
    Not found (GOMspace).
   */
   CSP_ERROR_NOT_FOUND = -2001,
   /**
    Full (GOMspace).
   */
   CSP_ERROR_FULL = -2002,
   /**
    Range error (GOMspace).
   Example: specifying 120 hours, where only 0-23 is valid.
   @see CSP_ERROR_OVERFLOW
   */
   CSP_ERROR_RANGE = -2003,
   /**
    Data error (GOMspace).
   */
   CSP_ERROR_DATA = -2004,
   /**
    Unknown error (GOMspace).
   @note avoid use - use specific error to improve debugging/troubleshooting.
   */
   CSP_ERROR_UNKNOWN = -2005,
   /**
    No data available (GOMspace).
   */
   CSP_ERROR_NO_DATA = -2006,
   /**
    Stale data - not updated (GOMspace).
   */
   CSP_ERROR_STALE = -2007,
   /**
    Type error (GOMspace).
   */
   CSP_ERROR_TYPE = -2008,
   /**
    Ambiguous error (GOMspace).
   */
   CSP_ERROR_AMBIGUOUS = -2009,
   /**
    State error (GOMspace).
   */
   CSP_ERROR_STATE = -2010,

} csp_error_t;

#ifdef __cplusplus
}
#endif
#endif
