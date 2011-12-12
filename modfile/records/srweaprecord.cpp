/*===========================================================================
 *
 * File:		Srweaprecord.CPP
 * Author:		Dave Humphrey (dave@uesp.net)
 * Created On:	26 November 2011
 *
 * Description
 *
 *=========================================================================*/

	/* Include Files */
#include "srweaprecord.h"
#include "../srrecordhandler.h"


/*===========================================================================
 *
 * Begin Subrecord Creation Array
 *
 *=========================================================================*/
BEGIN_SRSUBRECCREATE(CSrWeapRecord, CSrItem2Record)
	DEFINE_SRSUBRECCREATE(SR_NAME_DATA, CSrWeapDataSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_VNAM, CSrDwordSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_ETYP, CSrFormidSubrecord::Create)
END_SRSUBRECCREATE()
/*===========================================================================
 *		End of Subrecord Creation Array
 *=========================================================================*/


/*===========================================================================
 *
 * Begin CSrRecord Field Map
 *
 *=========================================================================*/
BEGIN_SRFIELDMAP(CSrWeapRecord, CSrItem2Record)
	ADD_SRFIELDALL("Weight",		SR_FIELD_WEIGHT,		0, CSrWeapRecord, FieldWeight)
	ADD_SRFIELDALL("Value",			SR_FIELD_VALUE,			0, CSrWeapRecord, FieldValue)
	ADD_SRFIELDALL("Damage",		SR_FIELD_DAMAGE,		0, CSrWeapRecord, FieldDamage)
	ADD_SRFIELDALL("Type",			SR_FIELD_TYPE,			0, CSrWeapRecord, FieldType)
	ADD_SRFIELDALL("Material",		SR_FIELD_MATERIAL,		0, CSrWeapRecord, FieldMaterial)
	ADD_SRFIELDALL("VNAM",			SR_FIELD_VNAM,			0, CSrWeapRecord, FieldVNAM)
	ADD_SRFIELDALL("EquipSlot",		SR_FIELD_EQUIPSLOT,		0, CSrWeapRecord, FieldEquipSlot)
END_SRFIELDMAP()
/*===========================================================================
 *		End of CObRecord Field Map
 *=========================================================================*/


/*===========================================================================
 *
 * Class CSrWeapRecord Constructor
 *
 *=========================================================================*/
CSrWeapRecord::CSrWeapRecord () 
{
	m_pEquipSlot	= NULL;
	m_pWeaponData   = NULL;
	m_pVNAM         = NULL;
}
/*===========================================================================
 *		End of Class CSrWeapRecord Constructor
 *=========================================================================*/


/*===========================================================================
 *
 * Class CSrWeapRecord Method - void Destroy (void);
 *
 *=========================================================================*/
void CSrWeapRecord::Destroy (void) 
{
	m_pEquipSlot	= NULL;
	m_pWeaponData   = NULL;
	m_pVNAM         = NULL;

	CSrItem2Record::Destroy();
}
/*===========================================================================
 *		End of Class Method CSrWeapRecord::Destroy()
 *=========================================================================*/


/*===========================================================================
 *
 * Class CSrWeapRecord Method - const SSCHAR* GetWeaponMaterial (void);
 *
 *=========================================================================*/
const SSCHAR* CSrWeapRecord::GetWeaponMaterial (void)
{
	CSrKywdRecord* pKeyword;

	if (m_pParent == NULL || m_pKeywords == NULL) return "";

	pKeyword = m_pParent->FindKeyword(m_pKeywords->GetFormIDArray(), "WeapMaterial");
	if (pKeyword == NULL) return "";
	return pKeyword->GetEditorID() + 12;
}
/*===========================================================================
 *		End of Class Method CSrWeapRecord::GetWeaponMaterial()
 *=========================================================================*/


/*===========================================================================
 *
 * Class CSrWeapRecord Method - const SSCHAR* GetWeaponType (void);
 *
 *=========================================================================*/
const SSCHAR* CSrWeapRecord::GetWeaponType (void)
{
	CSrKywdRecord* pKeyword;

	if (m_pParent == NULL || m_pKeywords == NULL) return "";

	pKeyword = m_pParent->FindKeyword(m_pKeywords->GetFormIDArray(), "WeapType");
	if (pKeyword == NULL) return "";
	return pKeyword->GetEditorID() + 8;
}
/*===========================================================================
 *		End of Class Method CSrWeapRecord::GetWeaponType()
 *=========================================================================*/


/*===========================================================================
 *
 * Class CSrWeapRecord Method - void InitializeNew (void);
 *
 *=========================================================================*/
void CSrWeapRecord::InitializeNew (void) 
{

	/* Call the base class method first */
  CSrItem2Record::InitializeNew();

  AddNewSubrecord(SR_NAME_VNAM);
  if (m_pVNAM != NULL) m_pVNAM->InitializeNew();   

  AddNewSubrecord(SR_NAME_DATA);
  if (m_pWeaponData != NULL) m_pWeaponData->InitializeNew();

  AddNewSubrecord(SR_NAME_ETYP);
  if (m_pEquipSlot != NULL) m_pEquipSlot->InitializeNew();
    
}
/*===========================================================================
 *		End of Class Method CSrWeapRecord::InitializeNew()
 *=========================================================================*/


/*===========================================================================
 *
 * Class CSrWeapRecord Event - void OnAddSubrecord (pSubrecord);
 *
 *=========================================================================*/
void CSrWeapRecord::OnAddSubrecord (CSrSubrecord* pSubrecord) {

  if (pSubrecord->GetRecordType() == SR_NAME_DATA) 
  {
    m_pWeaponData = SrCastClass(CSrWeapDataSubrecord, pSubrecord);
    //TEST_INTVALUE1(m_pWeaponData->GetRecordSize(), 10, SR_NAME_DATA);
  }
  else if (pSubrecord->GetRecordType() == SR_NAME_VNAM) 
  {
    m_pVNAM = SrCastClass(CSrDwordSubrecord, pSubrecord);
  }
  else if (pSubrecord->GetRecordType() == SR_NAME_ETYP) 
  {
    m_pEquipSlot = SrCastClass(CSrFormidSubrecord, pSubrecord);
  }
  else
    CSrItem2Record::OnAddSubrecord(pSubrecord);

 }
/*===========================================================================
 *		End of Class Event CSrWeapRecord::OnAddSubRecord()
 *=========================================================================*/


/*===========================================================================
 *
 * Class CSrWeapRecord Event - void OnDeleteSubrecord (pSubrecord);
 *
 *=========================================================================*/
void CSrWeapRecord::OnDeleteSubrecord (CSrSubrecord* pSubrecord) 
{

  if (m_pWeaponData == pSubrecord)
    m_pWeaponData = NULL;
  else if (m_pVNAM == pSubrecord)
    m_pVNAM = NULL;
  else if (m_pEquipSlot == pSubrecord)
    m_pEquipSlot = NULL;
  else
    CSrItem2Record::OnDeleteSubrecord(pSubrecord);

}
/*===========================================================================
 *		End of Class Event CSrWeapRecord::OnDeleteSubrecord()
 *=========================================================================*/


void CSrWeapRecord::SetEquipSlotID (const srformid_t FormID)
{
	if (m_pEquipSlot == NULL)
	{
		AddNewSubrecord(SR_NAME_ETYP);
		if (m_pEquipSlot == NULL) return;
		m_pEquipSlot->InitializeNew();
	}

	m_pEquipSlot->SetValue(FormID);

}


void CSrWeapRecord::SetEquipSlot (const char* pEditorID)
{
	if (pEditorID == NULL || *pEditorID == 0)
	{
		SetEquipSlotID(0);
	}
	else if (m_pParent)
	{
		CSrIdRecord* pRecord = m_pParent->FindEditorID(pEditorID);

		if (pRecord == NULL)
			SetEquipSlotID(0);
		else
			SetEquipSlotID(pRecord->GetFormID());
	}
}


const SSCHAR* CSrWeapRecord::GetEquipSlot (void) 
{ 
	return m_pEquipSlot && m_pParent ? m_pParent->GetEditorID(m_pEquipSlot->GetValue()) : ""; 
}


/*===========================================================================
 *
 * Begin CSrWeapRecord Get Field Methods
 *
 *=========================================================================*/
DEFINE_SRGETFIELD(CSrWeapRecord::GetFieldWeight,       String.Format(SR_FORMATSTR_WEIGHT, GetWeight()))
DEFINE_SRGETFIELD(CSrWeapRecord::GetFieldValue,        String.Format("%u", GetValue()))
DEFINE_SRGETFIELD(CSrWeapRecord::GetFieldDamage,       String.Format("%d", (int)GetDamage()))
DEFINE_SRGETFIELD(CSrWeapRecord::GetFieldType,         String = GetWeaponType())
DEFINE_SRGETFIELD(CSrWeapRecord::GetFieldMaterial,     String = GetWeaponMaterial())
DEFINE_SRGETFIELD(CSrWeapRecord::GetFieldVNAM,         String.Format("%u", GetVNAM()))
DEFINE_SRGETFIELD(CSrWeapRecord::GetFieldEquipSlot,    String = GetEquipSlot())
/*===========================================================================
 *		End of CSrWeapRecord Get Field Methods
 *=========================================================================*/


/*===========================================================================
 *
 * Begin CSrWeapRecord Compare Field Methods
 *
 *=========================================================================*/
DEFINE_SRCOMPFIELDFLOAT(CSrWeapRecord,  CompareFieldWeight,		  GetWeight, 100.0f)
DEFINE_SRCOMPFIELDDWORD(CSrWeapRecord,  CompareFieldValue,		  GetValue)
DEFINE_SRCOMPFIELDDWORD(CSrWeapRecord,  CompareFieldVNAM,		  GetVNAM)
DEFINE_SRCOMPFIELDINT(CSrWeapRecord,    CompareFieldDamage,		  GetDamage)
DEFINE_SRCOMPFIELDSTRING(CSrWeapRecord, CompareFieldType,		  GetWeaponType)
DEFINE_SRCOMPFIELDSTRING(CSrWeapRecord, CompareFieldMaterial,	  GetWeaponMaterial)
DEFINE_SRCOMPFIELDSTRING(CSrWeapRecord, CompareFieldEquipSlot,	  GetEquipSlot)
/*===========================================================================
 *		End of CSrWeapRecord Compare Field Methods
 *=========================================================================*/


/*===========================================================================
 *
 * Begin CSrWeapRecord Set Field Methods
 *
 *=========================================================================*/
BEGIN_SRSETFIELD(CSrWeapRecord::SetFieldWeight)
  float Value;

  if (!SrFieldConvertFloat(pString, Value)) return (false);
  SetWeight(Value);
END_SRSETFIELD()


BEGIN_SRSETFIELD(CSrWeapRecord::SetFieldValue)
  dword Value;

  if (!SrFieldConvertDword(pString, Value)) return (false);
  SetValue(Value);
END_SRSETFIELD()


BEGIN_SRSETFIELD(CSrWeapRecord::SetFieldVNAM)
  dword Value;

  if (!SrFieldConvertDword(pString, Value)) return (false);
  SetVNAM(Value);
END_SRSETFIELD()
	

BEGIN_SRSETFIELD(CSrWeapRecord::SetFieldDamage)
  word Value;

  if (!SrFieldConvertWord(pString, Value)) return (false);
  SetDamage(Value);
END_SRSETFIELD()
	

BEGIN_SRSETFIELD(CSrWeapRecord::SetFieldType)
  CSrIdRecord* pIdRecord = NULL;
  CSString Buffer("WeapType");

  if (m_pParent != NULL) 
  {
   
    if (pString == NULL || *pString == NULL_CHAR) 
	{
      SetWeaponType(SR_FORMID_NULL);
      return (true);
    }

	Buffer += pString;
    pIdRecord = m_pParent->FindEditorID(Buffer);
    if (pIdRecord == NULL) return AddSrGeneralError("The keyword '%s' does not exist!", Buffer);
    if (pIdRecord->GetRecordType() != SR_NAME_KYWD) return AddSrGeneralError("The record '%s' is not a keyword (%4.4s)!", Buffer, pIdRecord->GetRecordType().Name);
	//if (strnicmp(pIdRecord->GetEditorID(), "WeapType", 8) != 0) return AddSrGeneralError("The keyword '%s' is not a weapon type!", Buffer);

    SetWeaponType(pIdRecord->GetFormID());
  }
  else
  {
    return AddSrGeneralError("Unable to find the formID for the keyword 'WeapType%s'!", Buffer);
  }

END_SRSETFIELD()


BEGIN_SRSETFIELD(CSrWeapRecord::SetFieldMaterial)
  CSrIdRecord* pIdRecord = NULL;
  CSString Buffer("WeapMaterial");

  if (m_pParent != NULL) 
  {
   
    if (pString == NULL || *pString == NULL_CHAR) 
	{
      SetWeaponMaterial(SR_FORMID_NULL);
      return (true);
    }

	Buffer += pString;

    pIdRecord = m_pParent->FindEditorID(Buffer);
    if (pIdRecord == NULL) return AddSrGeneralError("The keyword '%s' does not exist!", Buffer);
    if (pIdRecord->GetRecordType() != SR_NAME_KYWD) return AddSrGeneralError("The record '%s' is not a keyword (%4.4s)!", Buffer, pIdRecord->GetRecordType().Name);
	//if (strnicmp(pIdRecord->GetEditorID(), "WeapMaterial", 12) != 0) return AddSrGeneralError("The keyword '%s' is not a weapon material!", Buffer);

    SetWeaponMaterial(pIdRecord->GetFormID());
  }
  else
  {
    return AddSrGeneralError("Unable to find the formID for the keyword 'WeapMaterial%s'!", pString);
  }

END_SRSETFIELD()


BEGIN_SRSETFIELD(CSrWeapRecord::SetFieldEquipSlot)
	SetEquipSlot(pString);
END_SRSETFIELD()
/*===========================================================================
 *		End of CSrWeapRecord Set Field Methods
 *=========================================================================*/



void CSrWeapRecord::SetWeaponType (const srformid_t FormID)
{
	CSrRecord*    pRecord;
	CSrIdRecord*  pIdRecord;
	const SSCHAR* pEditorID;

	if (m_pParent == NULL || m_pKeywords == NULL) return;

		/* Delete all existing weapon type keywords */
	for (int i = (int) m_pKeywords->GetFormIDArray().GetSize() - 1; i >= 0 ; --i)
	{
		pRecord = m_pParent->FindFormID(m_pKeywords->GetFormIDArray()[i]);
		pIdRecord = SrCastClassNull(CSrIdRecord, pRecord);
		if (pIdRecord == NULL) continue;
		if (pIdRecord->GetRecordType() != SR_NAME_KYWD) continue;

		pEditorID = pIdRecord->GetEditorID();
		if (pEditorID == NULL) continue;

		if (strnicmp(pEditorID, "WeapType", 8) != 0) continue;
		m_pKeywords->GetFormIDArray().Delete(i);
	}

		/* Add the new keyword weapon type */
	m_pKeywords->GetFormIDArray().Add(FormID);

	if (m_pKeywordCount != NULL) m_pKeywordCount->SetValue(m_pKeywords->GetFormIDArray().GetSize());
}


void CSrWeapRecord::SetWeaponMaterial (const srformid_t FormID)
{
	CSrRecord*    pRecord;
	CSrIdRecord*  pIdRecord;
	const SSCHAR* pEditorID;

	if (m_pParent == NULL || m_pKeywords == NULL) return;

		/* Delete all existing weapon material keywords */
	for (int i = (int) m_pKeywords->GetFormIDArray().GetSize() - 1; i >= 0 ; --i)
	{
		pRecord = m_pParent->FindFormID(m_pKeywords->GetFormIDArray()[i]);
		pIdRecord = SrCastClassNull(CSrIdRecord, pRecord);
		if (pIdRecord == NULL) continue;
		if (pIdRecord->GetRecordType() != SR_NAME_KYWD) continue;

		pEditorID = pIdRecord->GetEditorID();
		if (pEditorID == NULL) continue;

		if (strnicmp(pEditorID, "WeapMaterial", 12) != 0) continue;
		m_pKeywords->GetFormIDArray().Delete(i);
	}

		/* Add the new keyword material type */
	m_pKeywords->GetFormIDArray().Add(FormID);

	if (m_pKeywordCount != NULL) m_pKeywordCount->SetValue(m_pKeywords->GetFormIDArray().GetSize());
}