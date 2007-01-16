/* -*- mode: C++; tab-width: 4; c-basic-offset: 4; -*- */

/* AbiWord
 * Copyright (C) 2002 Francis James Franklin <fjf@alinameridon.com>
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

#ifndef AP_COCOASPLASH_H
#define AP_COCOASPLASH_H

#import <Cocoa/Cocoa.h>

#include "xap_CocoaWindow.h"
#include "xap_StatusBar.h"

class AP_CocoaSplash : public XAP_CocoaWindow, XAP_StatusBar
{
private:
	AP_CocoaSplash (const NSSize & size, NSImage * image);
public:
	~AP_CocoaSplash ();

	static AP_CocoaSplash * instance (bool instantiate = true);

	/* write text to the splash window's statusbar; in red if urgent
	 */
	void statusMessage (const char * utf8str, bool urgent = false);

private:
	NSText *	m_statusbar;
};

#endif /* AP_COCOASPLASH_H */
