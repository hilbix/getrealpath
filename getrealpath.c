/* $Header$
 *
 * Print a real path
 *
 * Copyright (C)2006 Valentin Hilbig, webmaster@scylla-charybdis.com
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 * $Log$
 * Revision 1.2  2006-10-03 20:40:21  tino
 * Version output added
 *
 * Revision 1.1  2006/09/28 01:54:29  tino
 * Commit for dist
 *
 */

#include <stdio.h>

#include "tino/main.h"

#include "getrealpath_version.h"

static void
main_realpath(const char *s)
{
  size_t	max;
  char		*buf;

  max	= pathconf (s, _PC_PATH_MAX);
  buf	= tino_alloc(max);
  realpath(s, buf);
  printf("%s\n", buf);
  free(buf);
}

int
main(int argc, char **argv)
{
  return tino_main_file(argc, argv, 
			main_realpath,
			"file...\n"
			"\t\tVersion " GETREALPATH_VERSION " compiled " __DATE__ "\n"
			"\tPrints full path of file\n"
			"\tIf path is - the names are read from stdin"
			);
}
