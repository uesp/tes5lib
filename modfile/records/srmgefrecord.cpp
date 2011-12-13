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
	DEFINE_SRSUBRECCREATE(SR_NAME_SNDD, CSrDataSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_OBND, CSrDataSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_VMAD, CSrDataSubrecord::Create)
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
	ADD_SRFIELDALL("SkillLevel",		SR_FIELD_SKILLLEVEL,		0, CSrMgefRecord, FieldSkillLevel)
	ADD_SRFIELDALL("CastingDelay",		SR_FIELD_CASTINGDELAY,		0, CSrMgefRecord, FieldCastingDelay)
	ADD_SRFIELDALL("BaseCost",			SR_FIELD_BASECOST,			0, CSrMgefRecord, FieldBaseCost)
	ADD_SRFIELDALL("MagicFlags",		SR_FIELD_MAGICFLAGS,		0, CSrMgefRecord, FieldMagicFlags)
	//ADD_SRFIELDALL("UserData",			SR_FIELD_USERDATA,			0, CSrMgefRecord, FieldUserData)
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
DEFINE_SRGETFIELD(CSrMgefRecord::GetFieldCastingDelay,      String.Format("%g", GetEffectData().CastingDelay) )
DEFINE_SRGETFIELD(CSrMgefRecord::GetFieldSkillLevel,        String.Format("%d", GetEffectData().SkillLevel) )
DEFINE_SRGETFIELD(CSrMgefRecord::GetFieldMagicFlags,        String.Format("0x%08X", GetEffectData().Flags) )
DEFINE_SRGETFIELD(CSrMgefRecord::GetFieldBaseCost,          String.Format("%g", GetEffectData().BaseCost) )
DEFINE_SRGETFIELD(CSrMgefRecord::GetFieldUserData,          String.Format("0x%08X", GetEffectData().Flags & 0xf0000000) )
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
DEFINE_SRCOMPFIELDFLOAT1(CSrMgefRecord, CompareFieldCastingDelay,   GetEffectData().CastingDelay, 1)
DEFINE_SRCOMPFIELDDWORD1(CSrMgefRecord, CompareFieldSkillLevel,     GetEffectData().SkillLevel)
DEFINE_SRCOMPFIELDDWORD1(CSrMgefRecord, CompareFieldMagicFlags,     GetEffectData().Flags)
DEFINE_SRCOMPFIELDFLOAT1(CSrMgefRecord, CompareFieldBaseCost,       GetEffectData().BaseCost, 1)
DEFINE_SRCOMPFIELDDWORD1(CSrMgefRecord, CompareFieldUserData,       GetEffectData().Flags & 0xf0000000)
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


BEGIN_SRSETFIELD(CSrMgefRecord::SetFieldCastingDelay)
  float Value;

  if (!SrFieldConvertFloat(pString, Value)) return (false);
  GetEffectData().CastingDelay = Value;
END_SRSETFIELD()

		
BEGIN_SRSETFIELD(CSrMgefRecord::SetFieldSkillLevel)
  dword Value;

  if (!SrFieldConvertDword(pString, Value)) return (false);
  GetEffectData().SkillLevel = Value;
END_SRSETFIELD()	


BEGIN_SRSETFIELD(CSrMgefRecord::SetFieldMagicFlags)
  dword Value;

  if (!SrFieldConvertDword(pString, Value)) return (false);
  GetEffectData().Flags = Value;
END_SRSETFIELD()


BEGIN_SRSETFIELD(CSrMgefRecord::SetFieldBaseCost)
  float Value;

  if (!SrFieldConvertFloat(pString, Value)) return (false);
  GetEffectData().BaseCost = Value;
END_SRSETFIELD()


BEGIN_SRSETFIELD(CSrMgefRecord::SetFieldUserData)
END_SRSETFIELD()
/*===========================================================================
 *		End of CSrMgefRecord Set Field Methods
 *=========================================================================*/

