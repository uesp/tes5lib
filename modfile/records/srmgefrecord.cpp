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
	//ADD_SRFIELDALL("",			SR_FIELD_,			0, CSrMgefRecord, Field)
	ADD_SRFIELDALL("Unknown1",			SR_FIELD_UNKNOWN1,			0, CSrMgefRecord, FieldUnknown1)
	ADD_SRFIELDALL("Unknown2",			SR_FIELD_UNKNOWN2,			0, CSrMgefRecord, FieldUnknown2)
	ADD_SRFIELDALL("Unknown3",			SR_FIELD_UNKNOWN3,			0, CSrMgefRecord, FieldUnknown3)
	ADD_SRFIELDALL("Unknown4",			SR_FIELD_UNKNOWN4,			0, CSrMgefRecord, FieldUnknown4)
	ADD_SRFIELDALL("Unknown5",			SR_FIELD_UNKNOWN5,			0, CSrMgefRecord, FieldUnknown5)
	ADD_SRFIELDALL("Unknown6",			SR_FIELD_UNKNOWN6,			0, CSrMgefRecord, FieldUnknown6)
	ADD_SRFIELDALL("Unknown7",			SR_FIELD_UNKNOWN7,			0, CSrMgefRecord, FieldUnknown7)
	ADD_SRFIELDALL("Unknown8",			SR_FIELD_UNKNOWN8,			0, CSrMgefRecord, FieldUnknown8)
	ADD_SRFIELDALL("Unknown9",			SR_FIELD_UNKNOWN9,			0, CSrMgefRecord, FieldUnknown9)
	ADD_SRFIELDALL("Unknown10",			SR_FIELD_UNKNOWN10,			0, CSrMgefRecord, FieldUnknown10)
	ADD_SRFIELDALL("Unknown11",			SR_FIELD_UNKNOWN11,			0, CSrMgefRecord, FieldUnknown11)
	ADD_SRFIELDALL("Unknown12",			SR_FIELD_UNKNOWN12,			0, CSrMgefRecord, FieldUnknown12)
	ADD_SRFIELDALL("Unknown13",			SR_FIELD_UNKNOWN13,			0, CSrMgefRecord, FieldUnknown13)
	ADD_SRFIELDALL("Unknown14",			SR_FIELD_UNKNOWN14,			0, CSrMgefRecord, FieldUnknown14)
	ADD_SRFIELDALL("Unknown15",			SR_FIELD_UNKNOWN15,			0, CSrMgefRecord, FieldUnknown15)
	ADD_SRFIELDALL("Light",				SR_FIELD_LIGHT,				0, CSrMgefRecord, FieldLight)
	ADD_SRFIELDALL("Shader1",			SR_FIELD_SHADER1,			0, CSrMgefRecord, FieldShader1)
	ADD_SRFIELDALL("Shader2",			SR_FIELD_SHADER2,			0, CSrMgefRecord, FieldShader2)
	ADD_SRFIELDALL("Art1",				SR_FIELD_ART1,				0, CSrMgefRecord, FieldArt1)
	ADD_SRFIELDALL("Art2",				SR_FIELD_ART2,				0, CSrMgefRecord, FieldArt2)	
	ADD_SRFIELDALL("Art3",				SR_FIELD_ART3,				0, CSrMgefRecord, FieldArt3)	
	ADD_SRFIELDALL("Art4",				SR_FIELD_ART4,				0, CSrMgefRecord, FieldArt4)	
	ADD_SRFIELDALL("ImpactSet1",		SR_FIELD_IMPACTSET1,		0, CSrMgefRecord, FieldImpactSet1)
	ADD_SRFIELDALL("ImpactSet2",		SR_FIELD_IMPACTSET2,		0, CSrMgefRecord, FieldImpactSet2)
	ADD_SRFIELDALL("Perk",				SR_FIELD_PERK,				0, CSrMgefRecord, FieldPerk)
	ADD_SRFIELDALL("Explosion",			SR_FIELD_EXPLOSION,			0, CSrMgefRecord, FieldExplosion)
	ADD_SRFIELDALL("DualCast",			SR_FIELD_DUALCAST,			0, CSrMgefRecord, FieldDual)
	ADD_SRFIELDALL("SecondSpell",		SR_FIELD_SECONDSPELL,		0, CSrMgefRecord, FieldSecondSpell)
	ADD_SRFIELDALL("EffectPlayRate",	SR_FIELD_EFFECTPLAYRATE,	0, CSrMgefRecord, FieldEffectPlayRate)
	ADD_SRFIELDALL("Projectile",		SR_FIELD_PROJECTILE,		0, CSrMgefRecord, FieldProjectile)
	ADD_SRFIELDALL("ActorValue",		SR_FIELD_ACTORVALUE,		0, CSrMgefRecord, FieldActorValue)
	ADD_SRFIELDALL("CastType",			SR_FIELD_CASTTYPE,			0, CSrMgefRecord, FieldCastType)
	ADD_SRFIELDALL("Hostile",			SR_FIELD_HOSTILE,			0, CSrMgefRecord, FieldHostile)
	ADD_SRFIELDALL("Recover",			SR_FIELD_RECOVER,			0, CSrMgefRecord, FieldRecover)
	ADD_SRFIELDALL("Detrimental",		SR_FIELD_DETRIMENTAL,		0, CSrMgefRecord, FieldDetrimental)
	ADD_SRFIELDALL("PercentMag",		SR_FIELD_PERCENTMAG,		0, CSrMgefRecord, FieldPercentMag)
	ADD_SRFIELDALL("SelfOnly",			SR_FIELD_SELFONLY,			0, CSrMgefRecord, FieldSelfOnly)
	ADD_SRFIELDALL("NoArea",			SR_FIELD_NOAREA,			0, CSrMgefRecord, FieldNoArea)
	ADD_SRFIELDALL("FXPersist",			SR_FIELD_FXPERSIST,			0, CSrMgefRecord, FieldFXPersist)
	ADD_SRFIELDALL("Bound",				SR_FIELD_BOUND,				0, CSrMgefRecord, FieldBound)
	ADD_SRFIELDALL("Ward",				SR_FIELD_WARD,				0, CSrMgefRecord, FieldWard)
	ADD_SRFIELDALL("UnknownFlag1",		SR_FIELD_UNKNOWNFLAG1,		0, CSrMgefRecord, FieldUnknownFlag1)
	ADD_SRFIELDALL("UnknownFlag2",		SR_FIELD_UNKNOWNFLAG2,		0, CSrMgefRecord, FieldUnknownFlag2)
	ADD_SRFIELDALL("UnknownFlag3",		SR_FIELD_UNKNOWNFLAG3,		0, CSrMgefRecord, FieldUnknownFlag3)
	ADD_SRFIELDALL("UnknownFlag4",		SR_FIELD_UNKNOWNFLAG4,		0, CSrMgefRecord, FieldUnknownFlag4)
	ADD_SRFIELDALL("UnknownFlag5",		SR_FIELD_UNKNOWNFLAG5,		0, CSrMgefRecord, FieldUnknownFlag5)
	ADD_SRFIELDALL("UnknownFlag6",		SR_FIELD_UNKNOWNFLAG6,		0, CSrMgefRecord, FieldUnknownFlag6)
	ADD_SRFIELDALL("UnknownFlag7",		SR_FIELD_UNKNOWNFLAG7,		0, CSrMgefRecord, FieldUnknownFlag7)
	ADD_SRFIELDALL("UnknownFlag8",		SR_FIELD_UNKNOWNFLAG8,		0, CSrMgefRecord, FieldUnknownFlag8)
	ADD_SRFIELDALL("UnknownFlag9",		SR_FIELD_UNKNOWNFLAG9,		0, CSrMgefRecord, FieldUnknownFlag9)
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

