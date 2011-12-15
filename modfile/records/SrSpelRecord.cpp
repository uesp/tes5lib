/*===========================================================================
 *
 * File:		SrSpelRecord.CPP
 * Author:		Dave Humphrey (dave@uesp.net)
 * Created On:	5 December 2011
 *
 * Description
 *
 *=========================================================================*/

	/* Include Files */
#include "srSpelrecord.h"
#include "../srrecordhandler.h"


srspitdata_t	CSrSpelRecord::s_NullSpellData = { 0 };


/*===========================================================================
 *
 * Begin Subrecord Creation Array
 *
 *=========================================================================*/
BEGIN_SRSUBRECCREATE(CSrSpelRecord, CSrIdRecord)
	DEFINE_SRSUBRECCREATE(SR_NAME_EFID, CSrFormidSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_EFIT, CSrEfitSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_ETYP, CSrFormidSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_OBND, CSrDataSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_FULL, CSrLStringSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_DESC, CSrLStringSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_SPIT, CSrSpitSubrecord::Create)	
	DEFINE_SRSUBRECCREATE(SR_NAME_MDOB, CSrDataSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_CTDA, CSrCtdaSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_CIS2, CSrDataSubrecord::Create)
END_SRSUBRECCREATE()
/*===========================================================================
 *		End of Subrecord Creation Array
 *=========================================================================*/


/*===========================================================================
 *
 * Begin CSrIdRecord Field Map
 *
 *=========================================================================*/
BEGIN_SRFIELDMAP(CSrSpelRecord, CSrIdRecord)
	ADD_SRFIELDALL("ItemName",		SR_FIELD_ITEMNAME,		0, CSrSpelRecord, FieldItemName)
	ADD_SRFIELDALL("Description",	SR_FIELD_DESCRIPTION,	0, CSrSpelRecord, FieldDescription)
	ADD_SRFIELDALL("EffectCount",	SR_FIELD_EFFECTCOUNT,	0, CSrSpelRecord, FieldEffectCount)
	ADD_SRFIELDALL("Perk",			SR_FIELD_PERK,			0, CSrSpelRecord, FieldPerk)
	ADD_SRFIELDALL("PerkID",		SR_FIELD_PERKID,		0, CSrSpelRecord, FieldPerkID)
	ADD_SRFIELDALL("EquipSlot",		SR_FIELD_EQUIPSLOT,		0, CSrSpelRecord, FieldEquipSlot)
	ADD_SRFIELDALL("EquipSlotID",	SR_FIELD_EQUIPSLOTID,	0, CSrSpelRecord, FieldEquipSlotID)
	ADD_SRFIELDALL("Perk",			SR_FIELD_PERK,			0, CSrSpelRecord, FieldPerk)
	ADD_SRFIELDALL("SpellFlags",	SR_FIELD_SPELLFLAGS,	0, CSrSpelRecord, FieldSpellFlags)
	ADD_SRFIELDALL("SpellType",		SR_FIELD_SPELLTYPE,		0, CSrSpelRecord, FieldSpellType)
	ADD_SRFIELDALL("CastTime",		SR_FIELD_CASTTIME,		0, CSrSpelRecord, FieldCastTime)
	ADD_SRFIELDALL("CastAnim",		SR_FIELD_CASTANIM,		0, CSrSpelRecord, FieldCastAnim)
	ADD_SRFIELDALL("CastType",		SR_FIELD_CASTTYPE,		0, CSrSpelRecord, FieldCastType)
	ADD_SRFIELDALL("AutoCalc",		SR_FIELD_AUTOCALC,		0, CSrSpelRecord, FieldAutoCalc)
	ADD_SRFIELDALL("Cost",			SR_FIELD_COST,			0, CSrSpelRecord, FieldCost)
	ADD_SRFIELDALL("UserData",		SR_FIELD_USERDATA,		0, CSrSpelRecord, FieldUserData)

END_SRFIELDMAP()
/*===========================================================================
 *		End of CObRecord Field Map
 *=========================================================================*/


/*===========================================================================
 *
 * Class CSrSpelRecord Constructor
 *
 *=========================================================================*/
CSrSpelRecord::CSrSpelRecord () 
{
	m_pItemName = NULL;
	m_pDescription = NULL;
	m_pBoundsData = NULL;
	m_pSpellData = NULL;
	m_pEquipmentSlot = NULL;
}
/*===========================================================================
 *		End of Class CSrSpelRecord Constructor
 *=========================================================================*/


/*===========================================================================
 *
 * Class CSrSpelRecord Method - void Destroy (void);
 *
 *=========================================================================*/
void CSrSpelRecord::Destroy (void) 
{
	m_pItemName = NULL;
	m_pDescription = NULL;
	m_pBoundsData = NULL;
	m_pSpellData = NULL;
	m_pEquipmentSlot = NULL;

	CSrIdRecord::Destroy();
}
/*===========================================================================
 *		End of Class Method CSrSpelRecord::Destroy()
 *=========================================================================*/


/*===========================================================================
 *
 * Class CSrSpelRecord Method - void InitializeNew (void);
 *
 *=========================================================================*/
void CSrSpelRecord::InitializeNew (void) 
{
	CSrIdRecord::InitializeNew();

	AddNewSubrecord(SR_NAME_FULL);
	if (m_pItemName != NULL) m_pItemName->InitializeNew();

	AddNewSubrecord(SR_NAME_ETYP);
	if (m_pEquipmentSlot != NULL) m_pEquipmentSlot->InitializeNew();

	AddNewSubrecord(SR_NAME_DESC);
	if (m_pDescription != NULL) m_pDescription->InitializeNew();

	AddNewSubrecord(SR_NAME_SPIT);
	if (m_pSpellData != NULL) m_pSpellData->InitializeNew();
}
/*===========================================================================
 *		End of Class Method CSrSpelRecord::InitializeNew()
 *=========================================================================*/


/*===========================================================================
 *
 * Class CSrSpelRecord Event - void OnAddSubrecord (pSubrecord);
 *
 *=========================================================================*/
void CSrSpelRecord::OnAddSubrecord (CSrSubrecord* pSubrecord) {

	if (pSubrecord->GetRecordType() == SR_NAME_ETYP)
	{
		m_pEquipmentSlot = SrCastClass(CSrFormidSubrecord, pSubrecord);
	}
	else if (pSubrecord->GetRecordType() == SR_NAME_OBND)
	{
		m_pBoundsData = SrCastClass(CSrDataSubrecord, pSubrecord);
	}
	else if (pSubrecord->GetRecordType() == SR_NAME_FULL)
	{
		m_pItemName = SrCastClass(CSrLStringSubrecord, pSubrecord);
	}
	else if (pSubrecord->GetRecordType() == SR_NAME_DESC)
	{
		m_pDescription = SrCastClass(CSrLStringSubrecord, pSubrecord);
	}
	else if (pSubrecord->GetRecordType() == SR_NAME_SPIT)
	{
		m_pSpellData = SrCastClass(CSrSpitSubrecord, pSubrecord);
	}
	else
	{
		CSrIdRecord::OnAddSubrecord(pSubrecord);
	}

}
/*===========================================================================
 *		End of Class Event CSrSpelRecord::OnAddSubRecord()
 *=========================================================================*/


/*===========================================================================
 *
 * Class CSrSpelRecord Event - void OnDeleteSubrecord (pSubrecord);
 *
 *=========================================================================*/
void CSrSpelRecord::OnDeleteSubrecord (CSrSubrecord* pSubrecord) {

	if (m_pEquipmentSlot == pSubrecord)
		m_pEquipmentSlot = NULL;
	else if (m_pBoundsData == pSubrecord)
		m_pBoundsData = NULL;
	else if (m_pItemName == pSubrecord)
		m_pItemName = NULL;
	else if (m_pDescription == pSubrecord)
		m_pDescription = NULL;
	else if (m_pSpellData == pSubrecord)
		m_pSpellData = NULL;
	else
		CSrIdRecord::OnDeleteSubrecord(pSubrecord);

}
/*===========================================================================
 *		End of Class Event CSrSpelRecord::OnDeleteSubrecord()
 *=========================================================================*/


const char* CSrSpelRecord::GetPerk (void)
{
	if (m_pParent == NULL || m_pSpellData == NULL) return NULL;
	return m_pParent->GetEditorID(m_pSpellData->GetSpellData().PerkID);
}


const char* CSrSpelRecord::GetEquipSlot (void)
{
	if (m_pParent == NULL || m_pEquipmentSlot == NULL) return NULL;
	return m_pParent->GetEditorID(m_pEquipmentSlot->GetValue());
}


void CSrSpelRecord::SetPerk (const char* pEditorID)
{
	if (m_pParent == NULL) return;
	CSrRecord* pRecord = m_pParent->FindEditorID(pEditorID);

	if (pRecord == NULL) 
		GetSpellData().PerkID = 0;
	else
		GetSpellData().PerkID = pRecord->GetFormID();

}


void CSrSpelRecord::SetEquipSlot (const char* pEditorID)
{
	if (m_pParent == NULL) return;
	CSrRecord* pRecord = m_pParent->FindEditorID(pEditorID);

	if (pRecord == NULL)
		SetEquipSlot((srformid_t) 0);
	else
		SetEquipSlot(pRecord->GetFormID());

}

void CSrSpelRecord::SetEquipSlot (const srformid_t FormID)
{

	if (m_pEquipmentSlot == NULL)
	{
		AddNewSubrecord(SR_NAME_ETYP);
		if (m_pEquipmentSlot == NULL) return;
		m_pEquipmentSlot->InitializeNew();
	}

	m_pEquipmentSlot->SetValue(FormID);
}


/*===========================================================================
 *
 * Begin CSrSpelRecord Get Field Methods
 *
 *=========================================================================*/
DEFINE_SRGETFIELD(CSrSpelRecord::GetFieldPerkID,		String.Format("0x%08X", GetSpellData().PerkID))
DEFINE_SRGETFIELD(CSrSpelRecord::GetFieldPerk,			String = GetPerk())
DEFINE_SRGETFIELD(CSrSpelRecord::GetFieldEquipSlotID,	String.Format("0x%08X", GetEquipSlotID()))
DEFINE_SRGETFIELD(CSrSpelRecord::GetFieldEquipSlot,		String = GetEquipSlot())
DEFINE_SRGETFIELD(CSrSpelRecord::GetFieldSpellType,		String.Format("%d", GetSpellData().SpellType))
DEFINE_SRGETFIELD(CSrSpelRecord::GetFieldSpellFlags,	String.Format("%04X", GetSpellData().Flags))
DEFINE_SRGETFIELD(CSrSpelRecord::GetFieldCastAnim,		String.Format("%d", GetSpellData().CastAnim))
DEFINE_SRGETFIELD(CSrSpelRecord::GetFieldCastTime,		String.Format("%g", GetSpellData().CastTime))
DEFINE_SRGETFIELD(CSrSpelRecord::GetFieldCastType,		String.Format("%d", GetSpellData().CastType))
DEFINE_SRGETFIELD(CSrSpelRecord::GetFieldCost,			String.Format("%d", GetSpellData().BaseCost))
DEFINE_SRGETFIELD(CSrSpelRecord::GetFieldAutoCalc,		String.Format("%d", IsAutoCalc()))
DEFINE_SRGETFIELD(CSrSpelRecord::GetFieldEffectCount,	String.Format("%u", GetEffectCount()))
DEFINE_SRGETFIELD(CSrSpelRecord::GetFieldUserData,		String.Format("%g", GetSpellData().Unknown2))
/*===========================================================================
 *		End of CSrSpelRecord Get Field Methods
 *=========================================================================*/
   

/*===========================================================================
 *
 * Begin CSrSpelRecord Compare Field Methods
 *
 *=========================================================================*/
DEFINE_SRCOMPFIELDDWORD1(CSrSpelRecord,  CompareFieldPerkID,		GetSpellData().PerkID)
DEFINE_SRCOMPFIELDSTRING(CSrSpelRecord,  CompareFieldPerk,			GetPerk)
DEFINE_SRCOMPFIELDDWORD(CSrSpelRecord,   CompareFieldEquipSlotID,	GetEquipSlotID)
DEFINE_SRCOMPFIELDSTRING(CSrSpelRecord,  CompareFieldEquipSlot,		GetEquipSlot)
DEFINE_SRCOMPFIELDDWORD1(CSrSpelRecord,  CompareFieldSpellType,		GetSpellData().SpellType)
DEFINE_SRCOMPFIELDDWORD1(CSrSpelRecord,  CompareFieldSpellFlags,	GetSpellData().Flags)
DEFINE_SRCOMPFIELDDWORD1(CSrSpelRecord,  CompareFieldCastAnim,		GetSpellData().CastAnim)
DEFINE_SRCOMPFIELDFLOAT1(CSrSpelRecord,  CompareFieldCastTime,		GetSpellData().CastTime, 100.0f)
DEFINE_SRCOMPFIELDDWORD1(CSrSpelRecord,  CompareFieldCastType,		GetSpellData().CastType)
DEFINE_SRCOMPFIELDDWORD1(CSrSpelRecord,  CompareFieldCost,			GetSpellData().BaseCost)
DEFINE_SRCOMPFIELDDWORD1(CSrSpelRecord,  CompareFieldAutoCalc,		IsAutoCalc())
DEFINE_SRCOMPFIELDDWORD1(CSrSpelRecord,  CompareFieldEffectCount,	GetEffectCount())
DEFINE_SRCOMPFIELDFLOAT1(CSrSpelRecord,  CompareFieldUserData,		GetSpellData().Unknown2, 100.0f)
/*===========================================================================
 *		End of CSrSpelRecord Compare Field Methods
 *=========================================================================*/


/*===========================================================================
 *
 * Begin CSrSpelRecord Set Field Methods
 *
 *=========================================================================*/
BEGIN_SRSETFIELD(CSrSpelRecord::SetFieldCastTime)
  float Value;

  if (!SrFieldConvertFloat(pString, Value)) return (false);
  GetSpellData().CastTime = Value;
END_SRSETFIELD()


BEGIN_SRSETFIELD(CSrSpelRecord::SetFieldCastType)
  dword Value;

  if (!SrFieldConvertDword(pString, Value)) return (false);
  GetSpellData().CastType = Value;
END_SRSETFIELD()


BEGIN_SRSETFIELD(CSrSpelRecord::SetFieldCastAnim)
  dword Value;

  if (!SrFieldConvertDword(pString, Value)) return (false);
  GetSpellData().CastAnim = Value;
END_SRSETFIELD()


BEGIN_SRSETFIELD(CSrSpelRecord::SetFieldCost)
  dword Value;

  if (!SrFieldConvertDword(pString, Value)) return (false);
  GetSpellData().BaseCost = Value;
END_SRSETFIELD()


BEGIN_SRSETFIELD(CSrSpelRecord::SetFieldSpellFlags)
  dword Value;

  if (!SrFieldConvertDword(pString, Value)) return (false);
  GetSpellData().Flags = Value;
END_SRSETFIELD()


BEGIN_SRSETFIELD(CSrSpelRecord::SetFieldSpellType)
  dword Value;

  if (!SrFieldConvertDword(pString, Value)) return (false);
  GetSpellData().SpellType = Value;
END_SRSETFIELD()


BEGIN_SRSETFIELD(CSrSpelRecord::SetFieldAutoCalc)
  bool Value;

  if (!SrFieldConvertBoolean(pString, Value)) return (false);
  if (m_pSpellData) m_pSpellData->SetAutoCalc(Value);
END_SRSETFIELD()

	
BEGIN_SRSETFIELD(CSrSpelRecord::SetFieldPerkID)
  dword Value;

  if (!SrFieldConvertDword(pString, Value)) return (false);
  GetSpellData().PerkID = Value;
END_SRSETFIELD()


BEGIN_SRSETFIELD(CSrSpelRecord::SetFieldPerk)
	SetPerk(pString);
END_SRSETFIELD()


BEGIN_SRSETFIELD(CSrSpelRecord::SetFieldEquipSlotID)
  dword Value;

  if (!SrFieldConvertDword(pString, Value)) return (false);
  SetEquipSlot(Value);
END_SRSETFIELD()


BEGIN_SRSETFIELD(CSrSpelRecord::SetFieldEquipSlot)
	SetEquipSlot(pString);
END_SRSETFIELD()


BEGIN_SRSETFIELD(CSrSpelRecord::SetFieldUserData)
END_SRSETFIELD()

BEGIN_SRSETFIELD(CSrSpelRecord::SetFieldEffectCount)
END_SRSETFIELD()
/*===========================================================================
 *		End of CSrSpelRecord Set Field Methods
 *=========================================================================*/

