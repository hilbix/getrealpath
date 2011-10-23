/* $Header$
 *
 * Print the real path of files, works for nonexistent paths, too.
 *
 * Copyright (C)2006-2008 Valentin Hilbig <webmaster@scylla-charybdis.com>
 *
 * This is release early code.  Use at own risk.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of the
 * License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA
 * 02110-1301 USA.
 *
 * $Log$
 * Revision 1.4  2011-10-23 00:28:27  tino
 * Tinolib support with options, ANSI escapes now default
 *
 * Revision 1.3  2008-11-25 00:50:41  tino
 * Now uses my own version of getrealpath
 *
 * Revision 1.2  2006-10-03 20:40:21  tino
 * Version output added
 */

#include "tino/main_file.h"
#include "tino/filetool.h"

#include "getrealpath_version.h"

static void
main_realpath(const char *s, int flags)
{
  const char	*buf;

  buf	= tino_file_realpathE(s);
  if (!buf)
    {
      TINO_ERR1("ETTRP100A realpath %s", s);
      return;
    }
  tino_main_file_escape(buf, flags);
  tino_free_constO(buf);
  tino_main_file_line(flags);
}

int
main(int argc, char **argv)
{
  return tino_main_file(main_realpath, NULL,
			argc, argv,
			GETREALPATH_VERSION,
			"Prints full path of file"
			);
}
