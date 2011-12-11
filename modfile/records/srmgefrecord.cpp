/*===========================================================================
 *
 * File:		SrMgefRecord.CPP
 * Author:		Dave Humphrey (dave@uesp.net)
 * Created On:	1 December 2011
 *
 * Implements the CSrMgefRecord class for land texture records.
 *
 *=========================================================================*/

	/* Include Files */
#include "srmgefrecord.h"


	/* Static class members */
srmgefdata_t CSrMgefRecord::s_SrNullEffectData = { 0 };


/*===========================================================================
 *
 * Begin Subrecord Creation Array
 *
 *=========================================================================*/
BEGIN_SRSUBRECCREATE(CSrMgefRecord, CSrIdKeyRecord)
	DEFINE_SRSUBRECCREATE(SR_NAME_DATA, CSrMgefDataSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_FULL, CSrLStringSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_DNAM, CSrLStringSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_CTDA, CSrCtdaSubrecord::Create)
END_SRSUBRECCREATE()
/*===========================================================================
 *		End of Subrecord Creation Array
 *=========================================================================*/


/*===========================================================================
 *
 * Begin CSrMgefRecord Field Map
 *
 *=========================================================================*/
BEGIN_SRFIELDMAP(CSrMgefRecord, CSrIdKeyRecord)
	ADD_SRFIELDALL("FullName",			SR_FIELD_FULLNAME,			0, CSrMgefRecord, FieldFullName)
	ADD_SRFIELDALL("Description",		SR_FIELD_DESCRIPTION,		0, CSrMgefRecord, FieldDescription)
	ADD_SRFIELDALL("School",			SR_FIELD_SCHOOL,			0, CSrMgefRecord, FieldSchool)
	ADD_SRFIELDALL("EffectType",		SR_FIELD_EFFECTTYPE,		0, CSrMgefRecord, FieldEffectType)
	ADD_SRFIELDALL("ConditionCount",	SR_FIELD_CONDITIONCOUNT,	0, CSrMgefRecord, FieldConditionCount)
END_SRFIELDMAP()
/*===========================================================================
 *		End of CSrMgefRecord Field Map
 *=========================================================================*/


/*===========================================================================
 *
 * Class CSrMgefRecord Constructor
 *
 *=========================================================================*/
CSrMgefRecord::CSrMgefRecord () 
{
  m_pData			= NULL;
  m_pFullName		= NULL;
  m_pDescription	= NULL;
}
/*===========================================================================
 *		End of Class CSrMgefRecord Constructor
 *=========================================================================*/


/*===========================================================================
 *
 * Class CSrMgefRecord Method - void Destroy (void);
 *
 *=========================================================================*/
void CSrMgefRecord::Destroy (void) 
{
  m_pData        = NULL;
  m_pFullName    = NULL;
  m_pDescription = NULL;

  CSrIdKeyRecord::Destroy();
}
/*===========================================================================
 *		End of Class Method CSrMgefRecord::Destroy()
 *=========================================================================*/


/*===========================================================================
 *
 * Class CSrMgefRecord Method - void InitializeNew (void);
 *
 *=========================================================================*/
void CSrMgefRecord::InitializeNew (void) 
{

	/* Call the base class method first */
  CSrIdKeyRecord::InitializeNew();

  AddNewSubrecord(SR_NAME_FULL);
  if (m_pFullName != NULL) m_pFullName->InitializeNew();

  AddNewSubrecord(SR_NAME_DATA);
  if (m_pData != NULL) m_pData->InitializeNew();

  AddNewSubrecord(SR_NAME_DNAM);
  if (m_pDescription != NULL) m_pDescription->InitializeNew();

}
/*===========================================================================
 *		End of Class Method CSrMgefRecord::InitializeNew()
 *=========================================================================*/


/*===========================================================================
 *
 * Class CSrMgefRecord Event - void OnAddSubrecord (pSubrecord);
 *
 *=========================================================================*/
void CSrMgefRecord::OnAddSubrecord (CSrSubrecord* pSubrecord) 
{

  if (pSubrecord->GetRecordType() == SR_NAME_DATA) 
  {
    m_pData = SrCastClass(CSrMgefDataSubrecord, pSubrecord);
  }
  else if (pSubrecord->GetRecordType() == SR_NAME_FULL) 
  {
    m_pFullName = SrCastClass(CSrLStringSubrecord, pSubrecord);
  }
  else if (pSubrecord->GetRecordType() == SR_NAME_DNAM) 
  {
    m_pDescription = SrCastClass(CSrLStringSubrecord, pSubrecord);
  }
  else 
  {
    CSrIdKeyRecord::OnAddSubrecord(pSubrecord);
  }

}
/*===========================================================================
 *		End of Class Event CSrMgefRecord::OnAddSubRecord()
 *=========================================================================*/


/*===========================================================================
 *
 * Class CSrMgefRecord Event - void OnDeleteSubrecord (pSubrecord);
 *
 *=========================================================================*/
void CSrMgefRecord::OnDeleteSubrecord (CSrSubrecord* pSubrecord) 
{

  if (m_pData == pSubrecord) 
    m_pData = NULL;
  else if (m_pFullName == pSubrecord) 
    m_pFullName = NULL;
  else if (m_pDescription == pSubrecord) 
    m_pDescription = NULL;
  else 
    CSrIdKeyRecord::OnDeleteSubrecord(pSubrecord);  

}
/*===========================================================================
 *		End of Class Event CSrMgefRecord::OnDeleteSubrecord()
 *=========================================================================*/


/*===========================================================================
 *
 * Begin CSrMgefRecord Get Field Methods
 *
 *=========================================================================*/
DEFINE_SRGETFIELD(CSrMgefRecord::GetFieldDescription,		String = GetDescription())
DEFINE_SRGETFIELD(CSrMgefRecord::GetFieldFullName,			String = GetFullName())
DEFINE_SRGETFIELD(CSrMgefRecord::GetFieldSchool,			String = GetSrMagicSchoolString(GetEffectData().School) )
DEFINE_SRGETFIELD(CSrMgefRecord::GetFieldConditionCount,    String.Format("%d", GetConditionCount()) )
DEFINE_SRGETFIELD(CSrMgefRecord::GetFieldEffectType,		String = GetSrMagicTypeString(GetEffectData().EffectType) )
/*===========================================================================
 *		End of CSrMgefRecord Get Field Methods
 *=========================================================================*/

  
/*===========================================================================
 *
 * Begin CSrMgefRecord Compare Field Methods
 *
 *=========================================================================*/
DEFINE_SRCOMPFIELDSTRING(CSrMgefRecord, CompareFieldDescription,	GetDescription)
DEFINE_SRCOMPFIELDSTRING(CSrMgefRecord, CompareFieldFullName,		GetFullName)
DEFINE_SRCOMPFIELDDWORD(CSrMgefRecord,  CompareFieldSchool,			GetSchool)
DEFINE_SRCOMPFIELDDWORD(CSrMgefRecord,  CompareFieldEffectType,		GetEffectType)
DEFINE_SRCOMPFIELDDWORD(CSrMgefRecord,  CompareFieldConditionCount, GetConditionCount)
/*===========================================================================
 *		End of CSrMgefRecord Compare Field Methods
 *=========================================================================*/

 
/*===========================================================================
 *
 * Begin CSrMgefRecord Set Field Methods
 *
 *=========================================================================*/
BEGIN_SRSETFIELD(CSrMgefRecord::SetFieldDescription)
  SetDescription(pString);
END_SRSETFIELD()


BEGIN_SRSETFIELD(CSrMgefRecord::SetFieldFullName)
  SetFullName(pString);
END_SRSETFIELD()


BEGIN_SRSETFIELD(CSrMgefRecord::SetFieldSchool)
	int School;
	bool Result = GetSrMagicSchoolValue(School, pString);
	if (!Result) return false;

	GetEffectData().School = School;
END_SRSETFIELD()


BEGIN_SRSETFIELD(CSrMgefRecord::SetFieldEffectType)
	int EffectType;
	bool Result = GetSrMagicTypeValue(EffectType, pString);
	if (!Result) return false;

	GetEffectData().EffectType = EffectType;
END_SRSETFIELD()


BEGIN_SRSETFIELD(CSrMgefRecord::SetFieldConditionCount)
  AddSrGeneralError("Cannot set the condition count directly!");
END_SRSETFIELD()
/*===========================================================================
 *		End of CSrMgefRecord Set Field Methods
 *=========================================================================*/

