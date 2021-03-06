/*
 * sj-metadata.h
 * Copyright (C) 2003 Ross Burton <ross@burtonini.com>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public
 * License along with this library; if not, see <http://www.gnu.org/licenses/>.
 */

#ifndef SJ_METADATA_H
#define SJ_METADATA_H

#include <gio/gio.h>
#include <glib.h>

G_BEGIN_DECLS

#define SJ_TYPE_METADATA            (sj_metadata_get_type ())
#define SJ_METADATA(obj)            (G_TYPE_CHECK_INSTANCE_CAST ((obj), SJ_TYPE_METADATA, SjMetadata))
#define SJ_METADATA_CLASS(vtable)    (G_TYPE_CHECK_CLASS_CAST ((vtable), SJ_TYPE_METADATA, SjMetadataClass))
#define SJ_IS_METADATA(obj)         (G_TYPE_CHECK_INSTANCE_TYPE ((obj), SJ_TYPE_METADATA))
#define SJ_IS_METADATA_CLASS(vtable) (G_TYPE_CHECK_CLASS_TYPE ((vtable), SJ_TYPE_METADATA))
#define SJ_METADATA_GET_CLASS(obj)  (G_TYPE_INSTANCE_GET_INTERFACE ((obj), SJ_TYPE_METADATA, SjMetadataClass))

typedef struct _SjMetadata SjMetadata; /* dummy object */
typedef struct _SjMetadataClass SjMetadataClass;

struct _SjMetadataClass
{
  GTypeInterface g_iface;

  /* Virtual Table */
  GList * (*list_albums) (SjMetadata *metadata, char **url, GCancellable *cancellable, GError **error);
};

GType sj_metadata_get_type (void);
void sj_metadata_set_cdrom (SjMetadata *metadata, const char* device);
GList * sj_metadata_list_albums (SjMetadata *metadata, char **url, GCancellable *cancellable, GError **error);

char * sj_metadata_helper_scan_disc_number (const char *album_title, int *disc_number);
gboolean sj_metadata_helper_check_media (const char *cdrom, GError **error);
char * sj_metadata_helper_lookup_country_code (const char *code);
void sj_metadata_helper_cleanup (void);

G_END_DECLS

#endif /* SJ_METADATA_H */
