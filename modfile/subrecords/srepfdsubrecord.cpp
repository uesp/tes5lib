/*===========================================================================
 *
 * File:		SrEpfdSubrecord.CPP
 * Author:		Dave Humphrey (dave@uesp.net)
 * Created On:	3 January 2012
 *
 * Description
 *
 *=========================================================================*/

	/* Include Files */
#include "srepfdsubrecord.h"
#include "../srrecordhandler.h"
#include "strings/srstringfile.h"


CSrEpfdSubrecord::CSrEpfdSubrecord() : m_DataType(SP_EPFDTYPE_UNKNOWN)
{
}


void CSrEpfdSubrecord::Destroy()
{
	m_DataType = SP_EPFDTYPE_UNKNOWN;
}


bool CSrEpfdSubrecord::Copy (CSrSubrecord* pSubrecord) 
{
	CSrEpfdSubrecord* pSubrecord1 = SrCastClassNull(CSrEpfdSubrecord, pSubrecord);
	m_RecordSize = pSubrecord->GetRecordSize();

	if (pSubrecord1 != NULL) 
	{
		m_DataType = pSubrecord1->m_DataType;
		m_Data01   = pSubrecord1->m_Data01;
		m_Data02   = pSubrecord1->m_Data02;
		m_Data04   = pSubrecord1->m_Data04;
		m_Data05   = pSubrecord1->m_Data05;
		m_Data06   = pSubrecord1->m_Data06;
		m_Data07   = pSubrecord1->m_Data07;

		m_Data07.IsLocalString = false;	//TODO: Properly inherit parent file local string setting
	}
	else 
	{
		memset(&m_Data01, 0, sizeof(m_Data01)); 
		memset(&m_Data02, 0, sizeof(m_Data02)); 
		memset(&m_Data04, 0, sizeof(m_Data04)); 
		memset(&m_Data05, 0, sizeof(m_Data05)); 
	}

	return true;
}


dword CSrEpfdSubrecord::ChangeFormID (const srformid_t NewID, const srformid_t OldID) 
{ 
	switch (m_DataType)
	{
		case SP_EPFDTYPE_OTHER:
			if (m_Data04.FormID == OldID)
			{
				m_Data04.FormID = NewID;
				return 1;
			}
			break;
		case SP_EPFDTYPE_FORMID:
			if (m_Data05.FormID == OldID)
			{
				m_Data05.FormID = NewID;
				return 1;
			}
			break;
	}
	
	return 0; 
}


dword CSrEpfdSubrecord::CountUses (const srformid_t FormID) 
{
	switch (m_DataType)
	{
		case SP_EPFDTYPE_OTHER:
			if (m_Data04.FormID == FormID) return 1;
			break;
		case SP_EPFDTYPE_FORMID:
			if (m_Data05.FormID == FormID) return 1;
			break;
	}

	return 0;
}


bool CSrEpfdSubrecord::FixupFormID (CSrFormidFixupArray& FixupArray) 
{
	switch (m_DataType)
	{
		case SP_EPFDTYPE_OTHER:  return SrFixupFormid(m_Data04.FormID, m_Data04.FormID, FixupArray);
		case SP_EPFDTYPE_FORMID: return SrFixupFormid(m_Data05.FormID, m_Data05.FormID, FixupArray);
	}

	return true;
}


byte* CSrEpfdSubrecord::GetData (void) 
{ 
	switch (m_DataType)
	{
		case SP_EPFDTYPE_FLOAT      : return (byte *)(&m_Data01); 
		case SP_EPFDTYPE_ACTORVALUE	: return (byte *)(&m_Data02); 
		case SP_EPFDTYPE_OTHER	    : return (byte *)(&m_Data04); 
		case SP_EPFDTYPE_FORMID     : return (byte *)(&m_Data05); 
		case SP_EPFDTYPE_ZSTRING    : return (byte *)(m_Data06.String.c_str()); 
		case SP_EPFDTYPE_LSTRING    : 

			if (m_Data07.IsLocalString)	
			{
				if (m_Data07.IsLoaded) return (byte *)(m_Data07.String.c_str()); 
				return (byte *)(&m_Data07.StringID); 			
			}
			
			return (byte *)(m_Data07.String.c_str()); 
	}

	return (byte *)(&m_Data01); 
}


dword CSrEpfdSubrecord::GetRecordSize (void) const
{ 
	switch (m_DataType)
	{
		case SP_EPFDTYPE_FLOAT      : return SR_EPFDFLOAT_SUBRECORD_SIZE; 
		case SP_EPFDTYPE_ACTORVALUE	: return SR_EPFDACTORVALUE_SUBRECORD_SIZE;
		case SP_EPFDTYPE_OTHER	    : return SR_EPFDOTHER_SUBRECORD_SIZE;
		case SP_EPFDTYPE_FORMID     : return SR_EPFDFORMID_SUBRECORD_SIZE;
		case SP_EPFDTYPE_ZSTRING    : return m_Data06.String.GetLength() + 1;
		case SP_EPFDTYPE_LSTRING    : 

			if (m_Data07.IsLocalString) 
			{
				if (m_Data07.IsLoaded) return m_Data07.String.GetLength() + 1;
				return 4;
			}

			return m_Data07.String.GetLength() + 1;
	}

	return m_RecordSize;
}


void CSrEpfdSubrecord::InitializeNew (void) 
{ 
	CSrSubrecord::InitializeNew(); 

	m_DataType   = SP_EPFDTYPE_FLOAT;
	m_RecordSize = SR_EPFDFLOAT_SUBRECORD_SIZE; 

	memset(&m_Data01, 0, sizeof(m_Data01)); 
	memset(&m_Data02, 0, sizeof(m_Data02)); 
	memset(&m_Data04, 0, sizeof(m_Data04)); 
	memset(&m_Data05, 0, sizeof(m_Data05)); 

	m_Data06.String.Empty();
	m_Data07.String.Empty();
	m_Data07.StringID = -1;
	m_Data07.IsLoaded = false;
	m_Data07.IsLocalString = false;
}


void CSrEpfdSubrecord::LoadLocalStrings (CSrRecordHandler* pHandler)
{
	if (m_DataType != SP_EPFDTYPE_LSTRING) return;

	if (m_Data07.StringID == 0)
	{
		m_Data07.IsLoaded = true;
		m_Data07.String.Empty();
		return;
	}

	CSString* pString = pHandler->FindLocalString(m_Data07.StringID);

	if (pString != NULL) 
	{
		//SystemLog.Printf("Found string '%s' for ID %d", *pString, m_StringID);
		m_Data07.String = *pString;
		m_Data07.IsLoaded = true;
	}
	else
	{
		SystemLog.Printf("Failed to find localized string id %d!", m_Data07.StringID);
	}
}
   

bool CSrEpfdSubrecord::ReadData  (CSrFile& File) 
{ 
	bool Result;

	switch (m_DataType)
	{
		case SP_EPFDTYPE_FLOAT      : SR_VERIFY_SUBRECORDSIZE(SR_EPFD01_SUBRECORD_SIZE) return File.Read(&m_Data01, SR_EPFD01_SUBRECORD_SIZE); 
		case SP_EPFDTYPE_ACTORVALUE	: SR_VERIFY_SUBRECORDSIZE(SR_EPFD02_SUBRECORD_SIZE) return File.Read(&m_Data02, SR_EPFD02_SUBRECORD_SIZE); 
		case SP_EPFDTYPE_OTHER	    : SR_VERIFY_SUBRECORDSIZE(SR_EPFD04_SUBRECORD_SIZE) return File.Read(&m_Data04, SR_EPFD04_SUBRECORD_SIZE); 
		case SP_EPFDTYPE_FORMID     : SR_VERIFY_SUBRECORDSIZE(SR_EPFD05_SUBRECORD_SIZE) return File.Read(&m_Data05, SR_EPFD05_SUBRECORD_SIZE); 
		case SP_EPFDTYPE_ZSTRING    :
			m_Data06.String.SetSize(m_RecordSize + 2);
			m_Data06.String.SetSize(m_RecordSize);
			if (m_RecordSize == 0) return (true);

			Result = File.Read((void *)(const SSCHAR *)m_Data06.String, m_RecordSize);
			if (m_Data06.String.GetAt(m_RecordSize - 1) == NULL_CHAR) m_Data06.String.Truncate(m_RecordSize - 1);

			return Result;

		case SP_EPFDTYPE_LSTRING    :

			if (m_Data07.IsLocalString)
			{
				m_Data07.IsLoaded = false;
				SR_VERIFY_SUBRECORDSIZE(4)
				return File.Read(&m_Data07.StringID, 4); 
			}
			else
			{
				m_Data07.StringID = -1;
				m_Data07.String.SetSize(m_RecordSize + 2);
				m_Data07.String.SetSize(m_RecordSize);
				if (m_RecordSize == 0) return (true);

				Result = File.Read((void *)(const SSCHAR *)m_Data07.String, m_RecordSize);
				if (m_Data07.String.GetAt(m_RecordSize - 1) == NULL_CHAR) m_Data07.String.Truncate(m_RecordSize - 1);

				return Result;
			}

			break;
	}

	return AddSrGeneralError("%08X: Unknown EPFD data type  %d!", File.Tell(), m_DataType);
}

bool CSrEpfdSubrecord::WriteData (CSrFile& File) 
{ 

	switch (m_DataType)
	{
		case SP_EPFDTYPE_FLOAT      : return File.Write(&m_Data01, SR_EPFD01_SUBRECORD_SIZE); 
		case SP_EPFDTYPE_ACTORVALUE	: return File.Write(&m_Data02, SR_EPFD02_SUBRECORD_SIZE); 
		case SP_EPFDTYPE_OTHER	    : return File.Write(&m_Data04, SR_EPFD04_SUBRECORD_SIZE); 
		case SP_EPFDTYPE_FORMID     : return File.Write(&m_Data05, SR_EPFD05_SUBRECORD_SIZE); 
		case SP_EPFDTYPE_ZSTRING    : return File.Write(m_Data06.String.c_str(), m_Data06.String.GetLength() + 1); 
		case SP_EPFDTYPE_LSTRING    :
			if (m_Data07.IsLocalString)
				return File.Write(&m_Data07.StringID, 4);
			else
				return File.Write(m_Data07.String.c_str(), m_Data07.String.GetLength() + 1); 
	}

	return AddSrGeneralError("Unknown EPFD data type %d!", m_DataType);
}


void CSrEpfdSubrecord::UpdateLocalStrings(CSrStringFile& StringFile, srlstringid_t& NextStringID)
{
	if (m_DataType != SP_EPFDTYPE_LSTRING) return;

	if (m_Data07.String.IsEmpty())
	{
		m_Data07.StringID = 0;
		return;
	}

	m_Data07.StringID = NextStringID++;
	StringFile.Add(m_Data07.StringID, m_Data07.String);
}