/* AbiHello
 * Copyright (C) 1999 AbiSource, Inc.
 * 
 * This program is g_free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  
 * 02111-1307, USA.
 */

#include <stdlib.h>
#include <string.h>

#include "ut_path.h"
#include "ap_UnixPrefs.h"

AP_UnixPrefs::AP_UnixPrefs(XAP_App* pApp)
	: AP_Prefs(pApp)
{
}

const char* AP_UnixPrefs::getPrefsPathname(void) const
{
	/* return a pointer to a static buffer */

	const char * szDirectory = m_pApp->getUserPrivateDirectory();
	char * szFile = "AbiHello.Profile";
	
	static char buf[PATH_MAX];
	memset(buf,0,sizeof(buf));
	
	if (strlen(szDirectory) + strlen(szFile) + 2 >= PATH_MAX)
		return NULL;
	
	strcpy(buf,szDirectory);
	int len = strlen(buf);
	if ( (len == 0) || (buf[len-1] != '/') )
		strcat(buf,"/");
	strcat(buf,szFile);
	
	return buf;
}

	
	
