/* Name frobnication for compiling argp outside of glibc
   Copyright (C) 1997 Free Software Foundation, Inc.
   This file is part of the GNU C Library.
   Written by Miles Bader <miles@gnu.ai.mit.edu>.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, write to the Free
   Software Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA
   02111-1307 USA.  */

#if !_LIBC
/* This code is written for inclusion in gnu-libc, and uses names in the
   namespace reserved for libc.  If we're not compiling in libc, define those
   names to be the normal ones instead.  */

/* argp-parse functions */
#undef __argp_parse
#define __argp_parse argp_parse
#undef __option_is_end
#define __option_is_end _option_is_end
#undef __option_is_short
#define __option_is_short _option_is_short
#undef __argp_input
#define __argp_input _argp_input

/* argp-help functions */
#undef __argp_help
#define __argp_help argp_help
#undef __argp_error
#define __argp_error argp_error
#undef __argp_failure
#define __argp_failure argp_failure
#undef __argp_state_help
#define __argp_state_help argp_state_help
#undef __argp_usage
#define __argp_usage argp_usage

/* argp-fmtstream functions */
#undef __argp_make_fmtstream
#define __argp_make_fmtstream argp_make_fmtstream
#undef __argp_fmtstream_free
#define __argp_fmtstream_free argp_fmtstream_free
#undef __argp_fmtstream_putc
#define __argp_fmtstream_putc argp_fmtstream_putc
#undef __argp_fmtstream_puts
#define __argp_fmtstream_puts argp_fmtstream_puts
#undef __argp_fmtstream_write
#define __argp_fmtstream_write argp_fmtstream_write
#undef __argp_fmtstream_printf
#define __argp_fmtstream_printf argp_fmtstream_printf
#undef __argp_fmtstream_set_lmargin
#define __argp_fmtstream_set_lmargin argp_fmtstream_set_lmargin
#undef __argp_fmtstream_set_rmargin
#define __argp_fmtstream_set_rmargin argp_fmtstream_set_rmargin
#undef __argp_fmtstream_set_wmargin
#define __argp_fmtstream_set_wmargin argp_fmtstream_set_wmargin
#undef __argp_fmtstream_point
#define __argp_fmtstream_point argp_fmtstream_point
#undef __argp_fmtstream_update
#define __argp_fmtstream_update _argp_fmtstream_update
#undef __argp_fmtstream_ensure
#define __argp_fmtstream_ensure _argp_fmtstream_ensure
#undef __argp_fmtstream_lmargin
#define __argp_fmtstream_lmargin argp_fmtstream_lmargin
#undef __argp_fmtstream_rmargin
#define __argp_fmtstream_rmargin argp_fmtstream_rmargin
#undef __argp_fmtstream_wmargin
#define __argp_fmtstream_wmargin argp_fmtstream_wmargin

/* normal libc functions we call */
#undef __sleep
#define __sleep sleep
#undef __strcasecmp
#define __strcasecmp strcasecmp
#undef __vsnprintf
#define __vsnprintf _vsnprintf

#define __strerror_r(x,y,z) strerror(x)
#define __flockfile(x)
#define __funlockfile(x)
#define __mempcpy(x,y,z) mempcpy(x,y,z)
#define __strchrnul(x,y) strchrnul(x,y)
#define __strndup(x,y) strdup(x)
/*#define alloca(x) calloc(1, x)*/
#define fputs_unlocked(x,y) fputs(x,y)
#define fwrite_unlocked(w,x,y,z) fwrite(w,x,y,z)
#define putc_unlocked(x,y) putc(x,y)
#define sleep(x)
#define strcasecmp(x,y) stricmp(x,y)

#endif /* !_LIBC */

#ifndef __set_errno
#define __set_errno(e) (errno = (e))
#endif
