/*
 * Copyright (C) 2003 Ross Burton <ross@burtonini.com>
 *
 * Sound Juicer - sj-util.h
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
 * along with this program; if not, see <http://www.gnu.org/licenses/>.
 *
 * Authors: Ross Burton <ross@burtonini.com>
 */

#ifndef SJ_UTIL_H
#define SJ_UTIL_H

#include <sys/types.h>
#include <gio/gio.h>
#include <gtk/gtk.h>

void sj_add_default_dirs (GtkFileChooser *dialog);
GFile *sj_get_default_music_directory (void);
gboolean sj_str_is_empty (const char *s);

/* clang has -Wincompatible-pointer-types-discards-qualifiers instead
   of -Wdiscarded-qualifiers */
#if !defined __clang__ && G_GNUC_CHECK_VERSION (4, 2)
#define SJ_BEGIN_IGNORE_DISCARDED_QUANTIFIERS                                   \
  _Pragma ("GCC diagnostic push")                                               \
  _Pragma ("GCC diagnostic ignored \"-Wdiscarded-qualifiers\"")

#define SJ_END_IGNORE_DISCARDED_QUANTIFIERS                                     \
  _Pragma ("GCC diagnostic pop")
#elif defined __clang__ && G_GNUC_CHECK_VERSION (4, 2)
#define SJ_BEGIN_IGNORE_DISCARDED_QUANTIFIERS                                   \
  _Pragma ("clang diagnostic push")                                             \
  _Pragma ("clang diagnostic ignored \"-Wincompatible-pointer-types-discards-qualifiers\"")

#define SJ_END_IGNORE_DISCARDED_QUANTIFIERS                                     \
  _Pragma ("clang diagnostic pop")
#else
#define SJ_BEGIN_IGNORE_DISCARDED_QUANTIFIERS
#define SJ_END_IGNORE_DISCARDED_QUANTIFIERS
#endif

#if G_GNUC_CHECK_VERSION (4,2)
#define SJ_BEGIN_IGNORE_SWITCH_ENUM                                             \
  _Pragma ("GCC diagnostic push")                                               \
  _Pragma ("GCC diagnostic ignored \"-Wswitch-enum\"")

#define SJ_END_IGNORE_SWITCH_ENUM                                               \
  _Pragma ("GCC diagnostic pop")
#else
#define SJ_BEGIN_IGNORE_SWITCH_ENUM
#define SJ_END_IGNORE_SWITCH_ENUM
#endif

#endif /* SJ_UTIL_H */
