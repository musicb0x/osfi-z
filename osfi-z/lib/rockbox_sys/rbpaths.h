/***************************************************************************
 *             __________               __   ___.
 *   Open      \______   \ ____   ____ |  | _\_ |__   _______  ___
 *   Source     |       _//  _ \_/ ___\|  |/ /| __ \ /  _ \  \/  /
 *   Jukebox    |    |   (  <_> )  \___|    < | \_\ (  <_> > <  <
 *   Firmware   |____|_  /\____/ \___  >__|_ \|___  /\____/__/\_ \
 *                     \/            \/     \/    \/            \/
 * $Id$
 *
 * Copyright (C) 2010 Thomas Martitz
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This software is distributed on an "AS IS" basis, WITHOUT WARRANTY OF ANY
 * KIND, either express or implied.
 *
 ****************************************************************************/

#ifndef __PATHS_H__
#define __PATHS_H__

#include <stdbool.h>
//#include "autoconf.h"
#include "config.h"
#include "string-extra.h"


/* name of directory where configuration, fonts and other data
 * files are stored */
/* #ifdef __PCTOOL__ */
/* #undef WPS_DIR */
/* #else */

/*  is now defined in autoconf.h for flexible build types */
/* #ifndef  */
/* #error  not defined (should be in autoconf.h) */
/* #endif */
/* #define ROCKBOX_DIR_LEN (sizeof()-1) */
/* #endif /\* def __PCTOOL__ *\/ */

#if !defined(APPLICATION) || defined(SAMSUNG_YPR0) || defined(SAMSUNG_YPR1) || defined(DX50) || defined(DX90)

#if defined(SAMSUNG_YPR0) || defined(SAMSUNG_YPR1)
#define HOME_DIR "/mnt/media0"
#elif defined(DX50) || defined(DX90)
/* Where to put save files like recordings, playlists, screen dumps ...*/
#define HOME_DIR "/mnt/sdcard"
#else
#define HOME_DIR "/"
#endif

/* make sure both are the same for native builds */
#undef ROCKBOX_LIBRARY_PATH
#define ROCKBOX_LIBRARY_PATH 

#define PLUGIN_DIR           "/rocks"
#define CODECS_DIR           "/codecs"

#else /* APPLICATION */

#define HOME_DIR "<HOME>" /* replaced at runtime */

#define PLUGIN_DIR          ROCKBOX_LIBRARY_PATH "/rockbox/rocks"
#if (CONFIG_PLATFORM & PLATFORM_ANDROID)
#define CODECS_DIR          ROCKBOX_BINARY_PATH
#else
#define CODECS_DIR          ROCKBOX_LIBRARY_PATH "/rockbox/codecs"
#endif

#endif /* !APPLICATION || SAMSUNG_YPR0 */

#define HOME_DIR_LEN (sizeof(HOME_DIR)-1)

#define REC_BASE_DIR        HOME_DIR
#define PLAYLIST_CATALOG_DEFAULT_DIR HOME_DIR "/Playlists"

#define LANG_DIR             "/langs"

#define PLUGIN_GAMES_DIR    PLUGIN_DIR "/games"
#define PLUGIN_APPS_DIR     PLUGIN_DIR "/apps"
#define PLUGIN_DEMOS_DIR    PLUGIN_DIR "/demos"
#define VIEWERS_DIR         PLUGIN_DIR "/viewers"

#if defined(APPLICATION) && !(defined(SAMSUNG_YPR0) || defined(SAMSUNG_YPR1) || defined(DX50) || defined(DX90))
#define PLUGIN_DATA_DIR           "/rocks.data"
#define PLUGIN_GAMES_DATA_DIR    PLUGIN_DATA_DIR
#define PLUGIN_APPS_DATA_DIR     PLUGIN_DATA_DIR
#define PLUGIN_DEMOS_DATA_DIR    PLUGIN_DATA_DIR
#define VIEWERS_DATA_DIR         PLUGIN_DATA_DIR
#else
#define PLUGIN_DATA_DIR          PLUGIN_DIR
#define PLUGIN_GAMES_DATA_DIR    PLUGIN_DIR "/games"
#define PLUGIN_APPS_DATA_DIR     PLUGIN_DIR "/apps"
#define PLUGIN_DEMOS_DATA_DIR    PLUGIN_DIR "/demos"
#define VIEWERS_DATA_DIR         PLUGIN_DIR "/viewers"
#endif

#define WPS_DIR              "/wps"
#define SBS_DIR             WPS_DIR
#define THEME_DIR            "/themes"
#define FONT_DIR             "/fonts"
#define ICON_DIR             "/icons"

#define BACKDROP_DIR         "/backdrops"
#define EQS_DIR              "/eqs"

/* need to fix this once the application gets record/radio abilities */
#define RECPRESETS_DIR       "/recpresets"
#define FMPRESET_PATH        "/fmpresets"

#define DIRCACHE_FILE        "/dircache.dat"
#define CODEPAGE_DIR         "/codepages"

#define VIEWERS_CONFIG       "/viewers.config"
#define CONFIGFILE           "/config.cfg"
#define FIXEDSETTINGSFILE    "/fixed.cfg"

#define PLAYLIST_CONTROL_FILE    "/.playlist_control"
#define NVRAM_FILE               "/nvram.bin"
#define GLYPH_CACHE_FILE         "/.glyphcache"

#endif /* __PATHS_H__ */