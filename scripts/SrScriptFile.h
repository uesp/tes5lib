/*===========================================================================
 *
 * File:		SrScriptFile.H
 * Author:		Dave Humphrey (dave@uesp.net)
 * Created On:	28 January 2012
 *
 * Handles a single uncompiled PSC script file.
 *
 *=========================================================================*/
#ifndef __SRSCRIPTFILE_H
#define __SRSCRIPTFILE_H


/*===========================================================================
 *
 * Begin Required Includes
 *
 *=========================================================================*/
	#include "common/srfile.h"
	#include "common/srlogfile.h"
	#include "common/textutils.h"
	#include "common/srcallback.h"
	#include "common/srarray.h"
	#include "common/srptrarray.h"
	#include "common/csvfile.h"
	#include "modfile/srfields.h"
	#include "modfile/srrectype.h"
	#include "common/srtime.h"
	#include "modfile/srfunctions.h"
	#include "common/srblockallocator.h"
/*===========================================================================
 *		End of Required Includes
 *=========================================================================*/


/*===========================================================================
 *
 * Begin Type Definitions
 *
 *=========================================================================*/

	/* Basic error definition for now */
class CSrScriptError
{

protected:
	CSString	m_ErrorText;
	int			m_Line;
	int			m_Character;
	int			m_UserData;

public:

	const char* MakeErrorString (void) { return m_ErrorText; }

	void SetUserData (const int Value) { m_UserData = Value; }
};

typedef CSrPtrArray<CSrScriptError> CSrScriptErrorArray;
/*===========================================================================
 *		End of Type Definitions
 *=========================================================================*/


/*===========================================================================
 *
 * Begin CSrScriptFile Definitions
 *
 *=========================================================================*/
class CSrScriptFile
{
protected:
	CSString	m_Filename;
	CSString	m_ScriptName;
	bool		m_IsModified;

	CSString	m_ScriptText;

protected:
	void UpdateName (void);

public:
	CSrScriptFile();
	~CSrScriptFile();

	void Destroy (void);

	bool IsFilename (const char* pFilename) const { return stricmp(m_Filename, pFilename) == 0; }
	bool IsModified (void) const { return m_IsModified; }

	const char* GetFilename   (void) const { return m_Filename; }
	const char* GetScriptName (void) const { return m_ScriptName.c_str(); }
	const char* GetScriptText (void) const { return m_ScriptText; }
	bool HasScriptName (void) const { return !m_ScriptName.IsEmpty(); }

	dword GetScriptTextLength (void) const { return m_ScriptText.GetLength(); }
	
	bool Load (const char* pFilename);

	bool Save (const char* pFilename = NULL);

	void SetIsModified (const bool    Value) { m_IsModified = Value; }
	void SetScriptText (const char* pString) { m_ScriptText = pString; }

};
/*===========================================================================
 *		End of CSrScriptFile Definition
 *=========================================================================*/


typedef CSrPtrArray<CSrScriptFile> CSrScriptFileArray;


#endif
/*===========================================================================
 *		End of File SrScriptFile.h
 *=========================================================================*/
