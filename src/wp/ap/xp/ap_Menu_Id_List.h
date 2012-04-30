/* AbiWord
 * Copyright (C) 1998 AbiSource, Inc.
 *
 * This program is free software; you can redistribute it and/or
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
/*****************************************************************
******************************************************************
** IT IS IMPORTANT THAT THIS FILE ALLOW ITSELF TO BE INCLUDED
** MORE THAN ONE TIME.
*****************************************************************/


/*****************************************************************/
/*****************************************************************/
/** This file defines the set of Id's used for all menu-related **/
/** things.  Each Id defines a conceptual unit which may be     **/
/** used on one or more menus or not at all.                    **/
/*****************************************************************/
/*****************************************************************/

/*****************************************************************/
/*  Each menuitem(XXX) will create an ID  AP_MENU_ID_XXX         */
/*  You will have to add MENU_LABEL_XXX                          */
/*                   and MENU_STATUS_LINE_XXX                    */
/*  to the ap_Strings_Id.h file                                  */
/*****************************************************************/

menuitem(FILE)
menuitem(FILE_NEW)
menuitem(FILE_NEW_USING_TEMPLATE)
menuitem(FILE_OPEN)
menuitem(FILE_IMPORTSTYLES)
menuitem(FILE_SAVE)
menuitem(FILE_SAVEAS)
menuitem(FILE_SAVE_TEMPLATE)
menuitem(FILE_SAVEIMAGE)
menuitem(FILE_EXPORT)
menuitem(FILE_IMPORT)
menuitem(FILE_CLOSE)
menuitem(FILE_PROPERTIES)
menuitem(FILE_PAGESETUP)
menuitem(FILE_PRINT)
menuitem(FILE_PRINT_PREVIEW)
menuitem(FILE_PRINT_DIRECTLY)
menuitem(FILE_RECENT)
menuitem(FILE_RECENT_1)		// _recent_1 thru _recent_9 must be contiguous
menuitem(FILE_RECENT_2)
menuitem(FILE_RECENT_3)
menuitem(FILE_RECENT_4)
menuitem(FILE_RECENT_5)
menuitem(FILE_RECENT_6)
menuitem(FILE_RECENT_7)
menuitem(FILE_RECENT_8)
menuitem(FILE_RECENT_9)
menuitem(FILE_REVERT)
menuitem(FILE_EXIT)
menuitem(FILE_SAVEEMBED)

menuitem(OPEN_TEMPLATE)

menuitem(EDIT)
menuitem(EDIT_UNDO)
menuitem(EDIT_REDO)
menuitem(EDIT_CUT)
menuitem(EDIT_COPY)
menuitem(EDIT_PASTE)
menuitem(EDIT_PASTE_SPECIAL)
menuitem(EDIT_CLEAR)
menuitem(EDIT_SELECTALL)
menuitem(EDIT_FIND)
menuitem(EDIT_REPLACE)
menuitem(EDIT_GOTO)
menuitem(EDIT_EDITHEADER)
menuitem(EDIT_EDITFOOTER)
menuitem(EDIT_REMOVEHEADER)
menuitem(EDIT_REMOVEFOOTER)
menuitem(EDIT_DELETEFRAME)
menuitem(EDIT_CUT_FRAME)
menuitem(EDIT_COPY_FRAME)
menuitem(EDIT_SELECT_FRAME)
menuitem(EDIT_DELETEIMAGE)
menuitem(EDIT_CUTIMAGE)
menuitem(EDIT_COPYIMAGE)
menuitem(EDIT_CUTEMBED)
menuitem(EDIT_COPYEMBED)
menuitem(EDIT_DELETEEMBED)
menuitem(EDIT_LATEXEQUATION)

menuitem(VIEW)
menuitem(VIEW_TOOLBARS)
menuitem(VIEW_TB_1)
menuitem(VIEW_TB_2)
menuitem(VIEW_TB_3)
menuitem(VIEW_TB_4)
menuitem(VIEW_LOCK_TB_LAYOUT)
menuitem(VIEW_DEFAULT_TB_LAYOUT)
menuitem(VIEW_RULER)
menuitem(VIEW_STATUSBAR)
menuitem(VIEW_SHOWPARA)
menuitem(VIEW_LOCKSTYLES)
menuitem(VIEW_HEADFOOT) // This has been removed.

menuitem(VIEW_ZOOM_MENU)
menuitem(VIEW_ZOOM)
menuitem(VIEW_ZOOM_200)
menuitem(VIEW_ZOOM_100)
menuitem(VIEW_ZOOM_75)
menuitem(VIEW_ZOOM_50)
menuitem(VIEW_ZOOM_WIDTH)
menuitem(VIEW_ZOOM_WHOLE)
menuitem(VIEW_FULLSCREEN)
menuitem(VIEW_NORMAL)
menuitem(VIEW_WEB)
menuitem(VIEW_PRINT)
menuitem(INSERT)
menuitem(INSERT_BREAK)
menuitem(INSERT_PAGENO)
menuitem(INSERT_DATETIME)
menuitem(INSERT_FIELD)
menuitem(INSERT_TEXTBOX)
menuitem(INSERT_MAILMERGE)
menuitem(INSERT_FILE)
menuitem(INSERT_SYMBOL)
menuitem(INSERT_FOOTNOTE)
menuitem(INSERT_ENDNOTE)
menuitem(INSERT_CLIPART)
menuitem(INSERT_GRAPHIC)
menuitem(INSERT_BOOKMARK)
menuitem(INSERT_XMLID)
menuitem(INSERT_TABLEOFCONTENTS)
menuitem(INSERT_HYPERLINK)
menuitem(INSERT_GOTO_HYPERLINK)
menuitem(INSERT_EDIT_HYPERLINK)
menuitem(INSERT_DELETE_HYPERLINK)
menuitem(EDIT_COPY_HYPERLINK_LOCATION)
menuitem(INSERT_HEADER)
menuitem(INSERT_FOOTER)
menuitem(INSERT_DIRECTIONMARKER)	
menuitem(INSERT_DIRECTIONMARKER_LRM)	
menuitem(INSERT_DIRECTIONMARKER_RLM)	

menuitem(FORMAT)
menuitem(FMT_FONT)
menuitem(FMT_PARAGRAPH)
menuitem(FMT_BULLETS)
menuitem(FMT_TABLE)
menuitem(FMT_DOCUMENT)
menuitem(FMT_BORDERS)
menuitem(FMT_COLUMNS)
menuitem(FMT_TOGGLECASE)
menuitem(FMT_BACKGROUND)
menuitem(FMT_BACKGROUND_PAGE_IMAGE)
menuitem(FMT_BACKGROUND_PAGE_COLOR)
menuitem(FMT_HDRFTR)
menuitem(FMT_FOOTNOTES)
menuitem(FMT_TABLEOFCONTENTS)
menuitem(FMT_TABS)
menuitem(FMT_LANGUAGE)
menuitem(FMT_IMAGE)
menuitem(FMT_POSIMAGE)
menuitem(FMT_SETPOSIMAGE)
menuitem(FMT_STYLE)
menuitem(FMT_STYLE_DEFINE)
menuitem(FMT_STYLIST)
menuitem(FMT_FRAME)
menuitem(FMT)
menuitem(FMT_BOLD)
menuitem(FMT_ITALIC)
menuitem(FMT_UNDERLINE)
menuitem(FMT_OVERLINE)
menuitem(FMT_STRIKE)
menuitem(FMT_TOPLINE)
menuitem(FMT_BOTTOMLINE)
menuitem(FMT_SUPERSCRIPT)
menuitem(FMT_SUBSCRIPT)
menuitem(FMT_DIRECTION)
menuitem(FMT_DIRECTION_DOCD_RTL)
menuitem(FMT_DIRECTION_SD_RTL)
menuitem(FMT_DIRECTION_DD_RTL)
menuitem(FMT_DIRECTION_DO_LTR)
menuitem(FMT_DIRECTION_DO_RTL)
menuitem(FMT_EMBED)

menuitem(TOOLS)
menuitem(TOOLS_SPELLING)
menuitem(TOOLS_SPELL)
menuitem(TOOLS_AUTOSPELL)
menuitem(TOOLS_SPELLPREFS)
menuitem(TOOLS_WORDCOUNT)
menuitem(TOOLS_MAILMERGE)
menuitem(TOOLS_PLUGINS)
menuitem(TOOLS_SCRIPTS)
menuitem(TOOLS_OPTIONS)
menuitem(TOOLS_LANGUAGE)
menuitem(TOOLS_REVISIONS)
menuitem(TOOLS_REVISIONS_MARK)
menuitem(TOOLS_REVISIONS_NEW_REVISION)
menuitem(TOOLS_REVISIONS_SHOW)
menuitem(TOOLS_REVISIONS_SHOW_AFTER)
menuitem(TOOLS_REVISIONS_SHOW_AFTERPREV)
menuitem(TOOLS_REVISIONS_SHOW_BEFORE)
menuitem(TOOLS_REVISIONS_SET_VIEW_LEVEL)
menuitem(TOOLS_REVISIONS_ACCEPT_REVISION)
menuitem(TOOLS_REVISIONS_REJECT_REVISION)
menuitem(TOOLS_REVISIONS_PURGE)
menuitem(TOOLS_REVISIONS_COMPARE_DOCUMENTS)
menuitem(TOOLS_REVISIONS_FIND_NEXT)
menuitem(TOOLS_REVISIONS_FIND_PREV)
menuitem(TOOLS_REVISIONS_AUTO)
menuitem(TOOLS_HISTORY)
menuitem(TOOLS_HISTORY_SHOW)
menuitem(TOOLS_HISTORY_PURGE)
// RIVERA
menuitem(TOOLS_ANNOTATIONS)
menuitem(TOOLS_ANNOTATIONS_INSERT)
menuitem(TOOLS_ANNOTATIONS_INSERT_FROMSEL)
menuitem(TOOLS_ANNOTATIONS_TOGGLE_DISPLAY)
menuitem(GOTO_ANNOTATION)
menuitem(EDIT_ANNOTATION)
menuitem(DELETE_ANNOTATION)
menuitem(RDFANCHOR_EDIT_TRIPLES)
menuitem(RDFANCHOR_QUERY)
menuitem(RDFANCHOR_EDITSEMITEM)
menuitem(RDFANCHOR_EXPORTSEMITEM)
menuitem(RDFANCHOR_SELECTNEXTREFTOSEMITEM)
menuitem(RDFANCHOR_SELECTPREVREFTOSEMITEM)
menuitem(RDFANCHOR_SELECTTHISREFTOSEMITEM)
menuitem(CONTEXT_REVISIONS_ACCEPT_REVISION)
menuitem(CONTEXT_REVISIONS_REJECT_REVISION)
menuitem(CONTEXT_REVISIONS_FIND_NEXT)
menuitem(CONTEXT_REVISIONS_FIND_PREV)
menuitem(ALIGN)
menuitem(ALIGN_LEFT)
menuitem(ALIGN_CENTER)
menuitem(ALIGN_RIGHT)
menuitem(ALIGN_JUSTIFY)


menuitem(TABLE)
menuitem(TABLE_INSERT)
menuitem(TABLE_INSERT_TABLE)
menuitem(TABLE_INSERTTABLE)
menuitem(TABLE_INSERT_COLUMNS_BEFORE)
menuitem(TABLE_INSERT_COLUMNS_AFTER)
menuitem(TABLE_INSERTCOLUMN)
menuitem(TABLE_INSERT_ROWS_BEFORE)
menuitem(TABLE_INSERT_ROWS_AFTER)
menuitem(TABLE_INSERTROW)
menuitem(TABLE_INSERT_CELLS)
menuitem(TABLE_INSERT_SUMCOLS)
menuitem(TABLE_INSERT_SUMROWS)

menuitem(TABLE_DELETE)
menuitem(TABLE_DELETE_TABLE)
menuitem(TABLE_DELETETABLE)
menuitem(TABLE_DELETE_COLUMNS)
menuitem(TABLE_DELETECOLUMN)
menuitem(TABLE_DELETE_ROWS)
menuitem(TABLE_DELETEROW)
menuitem(TABLE_DELETE_CELLS)

menuitem(TABLE_SELECT)
menuitem(TABLE_SELECT_TABLE)
menuitem(TABLE_SELECT_COLUMN)
menuitem(TABLE_SELECT_ROW)
menuitem(TABLE_SELECT_CELL)

menuitem(TABLE_MERGE_CELLS)
menuitem(TABLE_SPLIT_CELLS)
menuitem(TABLE_SPLIT_TABLE)
menuitem(TABLE_FORMAT)
menuitem(TABLE_TEXTTOTABLE)
menuitem(TABLE_TEXTTOTABLE_ALL)
menuitem(TABLE_TEXTTOTABLE_NOSPACES)
menuitem(TABLE_TABLETOTEXT)
menuitem(TABLE_TABLETOTEXTCOMMAS)
menuitem(TABLE_TABLETOTEXTTABS)
menuitem(TABLE_TABLETOTEXTCOMMASTABS)
menuitem(TABLE_SORTROWSASCEND)
menuitem(TABLE_SORTROWSDESCEND)
menuitem(TABLE_SORTCOLSASCEND)
menuitem(TABLE_SORTCOLSDESCEND)
menuitem(TABLE_AUTOFIT)
menuitem(TABLE_HEADING_ROWS_REPEAT)
menuitem(TABLE_HEADING_ROWS_REPEAT_THIS)
menuitem(TABLE_HEADING_ROWS_REPEAT_REMOVE)
menuitem(TABLE_SORT)

menuitem(WINDOW)
menuitem(WINDOW_NEW)
menuitem(WINDOW_1)		// _window_1 thru _window_9 must be contiguous
menuitem(WINDOW_2)
menuitem(WINDOW_3)
menuitem(WINDOW_4)
menuitem(WINDOW_5)
menuitem(WINDOW_6)
menuitem(WINDOW_7)
menuitem(WINDOW_8)
menuitem(WINDOW_9)
menuitem(WINDOW_MORE)

menuitem(WEB_WEBPREVIEW)
menuitem(WEB_SAVEASWEB)

menuitem(RDF)
menuitem(RDF_HIGHLIGHT)
menuitem(RDF_QUERY)
menuitem(RDF_EDITOR)
menuitem(RDF_QUERY_XMLIDS)
menuitem(RDF_SEMITEM)
menuitem(RDF_SEMITEM_CREATE)
menuitem(RDF_SEMITEM_CREATEREF)
menuitem(RDF_SEMITEM_NEW)
menuitem(RDF_SEMITEM_NEW_CONTACT)
menuitem(RDF_SEMITEM_NEW_CONTACT_FROM_FILE)
menuitem(RDF_SEMITEM_RELATION)
menuitem(RDF_SEMITEM_SET_AS_SOURCE)
menuitem(RDF_SEMITEM_RELATED_TO_SOURCE)
menuitem(RDF_SEMITEM_RELATED_TO_SOURCE_FOAFKNOWS)
menuitem(RDF_SEMITEM_FIND_RELATED)
menuitem(RDF_SEMITEM_FIND_RELATED_FOAFKNOWS)
menuitem(RDF_SEMITEM_STYLESHEET)
menuitem(RDF_SEMITEM_STYLESHEET_APPLY)
menuitem(RDF_SEMITEM_STYLESHEET_DISASSOCIATE)
menuitem(RDF_SEMITEM_STYLESHEET_SETTINGS)
menuitem(RDF_SEMITEM_STYLESHEET_CONTACT)
menuitem(RDF_SEMITEM_STYLESHEET_CONTACT_NAME)
menuitem(RDF_SEMITEM_STYLESHEET_CONTACT_NICK)
menuitem(RDF_SEMITEM_STYLESHEET_CONTACT_NAME_PHONE)
menuitem(RDF_SEMITEM_STYLESHEET_CONTACT_NICK_PHONE)
menuitem(RDF_SEMITEM_STYLESHEET_CONTACT_NAME_HOMEPAGE_PHONE)
menuitem(RDF_SEMITEM_STYLESHEET_EVENT)
menuitem(RDF_SEMITEM_STYLESHEET_EVENT_NAME)
menuitem(RDF_SEMITEM_STYLESHEET_EVENT_SUMMARY)
menuitem(RDF_SEMITEM_STYLESHEET_EVENT_SUMMARY_LOCATION)
menuitem(RDF_SEMITEM_STYLESHEET_EVENT_SUMMARY_LOCATION_TIMES)
menuitem(RDF_SEMITEM_STYLESHEET_EVENT_SUMMARY_TIMES)
menuitem(RDF_SEMITEM_STYLESHEET_LOCATION)
menuitem(RDF_SEMITEM_STYLESHEET_LOCATION_NAME)
menuitem(RDF_SEMITEM_STYLESHEET_LOCATION_NAME_LATLONG)
menuitem(RDF_ADV)
menuitem(RDF_ADV_TEST)
menuitem(RDF_ADV_DUMP_OBJECTS)
menuitem(RDF_ADV_DUMP_FOR_POINT)
menuitem(RDF_ADV_PLAY)

menuitem(HELP)
menuitem(HELP_CREDITS)
menuitem(HELP_CONTENTS)
menuitem(HELP_INTRO)
menuitem(HELP_CHECKVER)
menuitem(HELP_SEARCH)
menuitem(HELP_ABOUT)
menuitem(HELP_ABOUT_GNOMEOFFICE)
menuitem(HELP_REPORT_BUG)

menuitem(SPELL_SUGGEST_1)		// _suggest_1 thru _suggest_9 must be contiguous
menuitem(SPELL_SUGGEST_2)
menuitem(SPELL_SUGGEST_3)
menuitem(SPELL_SUGGEST_4)
menuitem(SPELL_SUGGEST_5)
menuitem(SPELL_SUGGEST_6)
menuitem(SPELL_SUGGEST_7)
menuitem(SPELL_SUGGEST_8)
menuitem(SPELL_SUGGEST_9)
menuitem(SPELL_IGNOREALL)
menuitem(SPELL_ADD)

/**** Add Menu Items here ****/
