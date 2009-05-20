/* -*- mode: C++; tab-width: 4; c-basic-offset: 4; -*- */

/* AbiSource
 * 
 * Copyright (C) 2007 Philippe Milot <PhilMilot@gmail.com>
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

// Class definition include
#include <OXML_Section.h>

// Internal includes
#include <OXML_Types.h>
#include <OXML_Element.h>
#include <OXML_Document.h>

// AbiWord includes
#include <ut_types.h>
#include <pd_Document.h>
#include <pt_Types.h>
#include <ut_exception.h>

// External includes
#include <string>

OXML_Section::OXML_Section() : 
	OXML_ObjectWithAttrProp(), 
	m_id(""), 
	m_breakType(NEXTPAGE_BREAK),
	TARGET(0)
{
	m_headerIds[0] = NULL; m_headerIds[1] = NULL; m_headerIds[2] = NULL;
	m_footerIds[0] = NULL; m_footerIds[1] = NULL; m_footerIds[2] = NULL;
	m_children.clear();
}

OXML_Section::OXML_Section(const std::string & id) : 
	OXML_ObjectWithAttrProp(), 
	m_id(id), 
	m_breakType(NEXTPAGE_BREAK),
	TARGET(0)
{
	m_headerIds[0] = NULL; m_headerIds[1] = NULL; m_headerIds[2] = NULL;
	m_footerIds[0] = NULL; m_footerIds[1] = NULL; m_footerIds[2] = NULL;
	m_children.clear();
}

OXML_Section::~OXML_Section()
{
	g_free(m_headerIds[0]); g_free(m_headerIds[1]); g_free(m_headerIds[2]);
	g_free(m_footerIds[0]); g_free(m_footerIds[1]); g_free(m_footerIds[2]);
	clearChildren();
}

bool OXML_Section::operator ==(const std::string & id)
{
	return this->m_id.compare(id) == 0;
}

OXML_SharedElement OXML_Section::getElement(const std::string & id)
{
	OXML_ElementVector::iterator it;
	it = std::find(m_children.begin(), m_children.end(), id);
	return ( it != m_children.end() ) ? (*it) : OXML_SharedElement() ;
}

UT_Error OXML_Section::appendElement(OXML_SharedElement obj)
{
	UT_return_val_if_fail(obj.get() != NULL, UT_ERROR);

	UT_TRY {
		m_children.push_back(obj);
	} UT_CATCH (UT_CATCH_ANY) {
		UT_DEBUGMSG(("Bad alloc!\n"));
		return UT_OUTOFMEM;
	} UT_END_CATCH

	obj->setTarget(TARGET);

	return UT_OK;
}

UT_Error OXML_Section::clearChildren()
{
	m_children.clear();
	return m_children.size() == 0 ? UT_OK : UT_ERROR;
}

UT_Error OXML_Section::serialize(IE_Exp_OpenXML* exporter)
{
	UT_Error ret = UT_OK;
	
	ret = exporter->startSection();
	if(ret != UT_OK)
		return ret;

	ret = this->serializeProperties(exporter);
	if(ret != UT_OK)
		return ret;

	OXML_ElementVector::size_type i;
	for (i = 0; i < m_children.size(); i++)
	{
		ret = m_children[i]->serialize(exporter);
		if(ret != UT_OK)
			return ret;
	}
	
	return exporter->finishSection();
}

UT_Error OXML_Section::serializeProperties(IE_Exp_OpenXML* exporter)
{
	//TODO: Add all the property serializations here
	UT_Error err = UT_OK;
	const gchar* num = NULL;
	const gchar* sep = "off";

	if(getProperty("columns", num) != UT_OK)
		return UT_OK;

	if((getProperty("column-line", sep) != UT_OK) || (strcmp(sep, "on") != 0))
		sep = "off";

	err = exporter->startSectionProperties();
	if(err != UT_OK)
		return err;

	err = exporter->setColumns(TARGET, num, sep);
	if(err != UT_OK)
		return err;

	return exporter->finishSectionProperties();
}

bool OXML_Section::hasFirstPageHdrFtr()
{
	UT_Error ret = UT_OK;

	const gchar* headerType;

	ret = getAttribute("type", headerType);
	if(ret != UT_OK)
		return false;

	return strstr(headerType, "first");
}

bool OXML_Section::hasEvenPageHdrFtr()
{
	UT_Error ret = UT_OK;

	const gchar* headerType;

	ret = getAttribute("type", headerType);
	if(ret != UT_OK)
		return false;

	return strstr(headerType, "even");
}

/**
 * Serialize the section as a header
 */
UT_Error OXML_Section::serializeHeader(IE_Exp_OpenXML* exporter)
{
	UT_Error ret = UT_OK;

	const gchar* headerId;
	const gchar* headerType;

	ret = getAttribute("id", headerId);
	if(ret != UT_OK)
		return UT_OK;

	ret = getAttribute("type", headerType);
	if(ret != UT_OK)
		return UT_OK;

	const gchar* type = "default";
	//OOXML includes default, first and even.  
	if(strstr(headerType, "first"))
	{
		type = "first";
	}
	else if(strstr(headerType, "even"))
	{
		type = "even";
	}
	else if(strstr(headerType, "last"))
	{
		//last not implemented in OOXML
		return UT_OK;
	}
			
	std::string header("hId");
	header += headerId;

	ret = exporter->setHeaderReference(header.c_str(), type);
	if(ret != UT_OK)
		return ret;

	ret = exporter->setHeaderRelation(header.c_str(), headerId);
	if(ret != UT_OK)
		return ret;	

	ret = exporter->startHeaderStream(headerId);
	if(ret != UT_OK)
		return ret;	

	OXML_ElementVector::size_type i;
	for (i = 0; i < m_children.size(); i++)
	{
		ret = m_children[i]->serialize(exporter);
		if(ret != UT_OK)
			return ret;
	}

	return exporter->finishHeaderStream();
}

/**
 * Serialize the section as a footer
 */
UT_Error OXML_Section::serializeFooter(IE_Exp_OpenXML* exporter)
{
	UT_Error ret = UT_OK;

	const gchar* footerId;
	const gchar* footerType;

	ret = getAttribute("id", footerId);
	if(ret != UT_OK)
		return UT_OK;
		
	std::string footer("fId");
	footer += footerId;

	ret = getAttribute("type", footerType);
	if(ret != UT_OK)
		return UT_OK;

	const gchar* type = "default";
	//OOXML includes default, first and even.  
	if(strstr(footerType, "first"))
	{
		type = "first";
	}
	else if(strstr(footerType, "even"))
	{
		type = "even";
	}
	else if(strstr(footerType, "last"))
	{
		//last not implemented in OOXML
		return UT_OK;
	}


	ret = exporter->setFooterReference(footer.c_str(), type);
	if(ret != UT_OK)
		return ret;

	ret = exporter->setFooterRelation(footer.c_str(), footerId);
	if(ret != UT_OK)
		return ret;	

	ret = exporter->startFooterStream(footerId);
	if(ret != UT_OK)
		return ret;	

	OXML_ElementVector::size_type i;
	for (i = 0; i < m_children.size(); i++)
	{
		ret = m_children[i]->serialize(exporter);
		if(ret != UT_OK)
			return ret;
	}

	return exporter->finishFooterStream();
}

/**
 * Serialize the section as a footnote
 */
UT_Error OXML_Section::serializeFootnote(IE_Exp_OpenXML* exporter)
{
	UT_Error ret = UT_OK;

	const gchar* footnoteId;

	ret = getAttribute("footnote-id", footnoteId);
	if(ret != UT_OK)
		return UT_OK;

	ret = exporter->startFootnote(footnoteId);
	if(ret != UT_OK)
		return ret;	

	OXML_ElementVector::size_type i;
	for (i = 0; i < m_children.size(); i++)
	{
		ret = m_children[i]->serialize(exporter);
		if(ret != UT_OK)
			return ret;
	}

	return exporter->finishFootnote();
}

/**
 * Serialize the section as a endnote
 */
UT_Error OXML_Section::serializeEndnote(IE_Exp_OpenXML* exporter)
{
	UT_Error ret = UT_OK;

	const gchar* endnoteId;

	ret = getAttribute("endnote-id", endnoteId);
	if(ret != UT_OK)
		return UT_OK;

	ret = exporter->startEndnote(endnoteId);
	if(ret != UT_OK)
		return ret;	

	OXML_ElementVector::size_type i;
	for (i = 0; i < m_children.size(); i++)
	{
		ret = m_children[i]->serialize(exporter);
		if(ret != UT_OK)
			return ret;
	}

	return exporter->finishEndnote();
}

UT_Error OXML_Section::addToPT(PD_Document * pDocument)
{
	UT_Error ret = UT_OK;
	const gchar ** attr = NULL;

	if (pDocument == NULL)
		return UT_ERROR;

	ret = _setReferenceIds();
	UT_return_val_if_fail(ret == UT_OK, ret);

	//Appending page break to current section if necessary
	if (m_breakType == ODDPAGE_BREAK || m_breakType == EVENPAGE_BREAK) {
		UT_UCSChar ucs = UCS_FF;
		ret = pDocument->appendSpan(&ucs, 1) ? UT_OK : UT_ERROR;
		UT_return_val_if_fail(ret == UT_OK, ret);
	}

	//Appending new section
	attr = this->getAttributes();
	ret = pDocument->appendStrux(PTX_Section, attr) ? UT_OK : UT_ERROR;
	UT_return_val_if_fail(ret == UT_OK, ret);

	//Appending new page break to the new section if necessary
	if (m_breakType == NEXTPAGE_BREAK || m_breakType == EVENPAGE_BREAK) {
		UT_UCSChar ucs = UCS_FF;
		ret = pDocument->appendSpan(&ucs, 1) ? UT_OK : UT_ERROR;
		UT_return_val_if_fail(ret == UT_OK, ret);
	}


	OXML_ElementVector::size_type i;
	for (i = 0; i < m_children.size(); i++)
	{
		ret = m_children[i]->addToPT(pDocument);
		UT_return_val_if_fail(ret == UT_OK, ret);
	}
	return ret;
}

UT_Error OXML_Section::addToPTAsHdrFtr(PD_Document * pDocument)
{
	UT_Error ret = UT_OK;
	const gchar ** attr = this->getAttributes();
	ret = pDocument->appendStrux(PTX_SectionHdrFtr, attr) ? UT_OK : UT_ERROR;
	UT_return_val_if_fail(ret == UT_OK, ret);

	OXML_ElementVector::size_type i;
	for (i = 0; i < m_children.size(); i++)
	{
		ret = m_children[i]->addToPT(pDocument);
		UT_return_val_if_fail(ret == UT_OK, ret);
	}
	return ret;
}

UT_Error OXML_Section::_setReferenceIds()
{
	OXML_Document * doc = OXML_Document::getInstance(); UT_ASSERT(NULL != doc);
	OXML_SharedSection corresp_sect;
	const char * ooxml_id(NULL), * abw_id(NULL);

	//Headers...
	for (UT_uint32 i = 0; i <= 2; i++) {
		ooxml_id = m_headerIds[i]; abw_id = NULL;
		if (NULL != ooxml_id) {
			corresp_sect = doc->getHeader(ooxml_id);
			UT_return_val_if_fail( NULL != corresp_sect.get(), UT_ERROR );
			corresp_sect->getAttribute("id", abw_id);
			UT_return_val_if_fail( NULL != abw_id, UT_ERROR );
			if (i == DEFAULT_HDRFTR) {
				this->setAttribute("header", abw_id );
			} else if (i == FIRSTPAGE_HDRFTR) {
				this->setAttribute("header-first", abw_id );
			} else if (i == EVENPAGE_HDRFTR) {
				this->setAttribute("header-even", abw_id );
			}	
		}
	}

	//Footers...
	for (UT_uint32 i = 0; i <= 2; i++) {
		ooxml_id = m_footerIds[i]; abw_id = NULL;
		if (NULL != ooxml_id) {
			corresp_sect = doc->getFooter(ooxml_id);
			UT_return_val_if_fail( NULL != corresp_sect.get(), UT_ERROR );
			corresp_sect->getAttribute("id", abw_id);
			UT_return_val_if_fail( NULL != abw_id, UT_ERROR );
			if (i == DEFAULT_HDRFTR) {
				this->setAttribute("footer", abw_id );
			} else if (i == FIRSTPAGE_HDRFTR) {
				this->setAttribute("footer-first", abw_id );
			} else if (i == EVENPAGE_HDRFTR) {
				this->setAttribute("footer-even", abw_id );
			}	
		}
	}
	return UT_OK;
}

void OXML_Section::setTarget(int target)
{
	TARGET = target;
}