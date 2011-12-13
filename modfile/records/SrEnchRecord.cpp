/*===========================================================================
 *
 * File:		SrEnchRecord.CPP
 * Author:		Dave Humphrey (dave@uesp.net)
 * Created On:	5 December 2011
 *
 * Description
 *
 *=========================================================================*/

	/* Include Files */
#include "srEnchrecord.h"
#include "../srrecordhandler.h"


srenitdata_t CSrEnchRecord::s_NullEffectData = { 0 };


/*===========================================================================
 *
 * Begin Subrecord Creation Array
 *
 *=========================================================================*/
BEGIN_SRSUBRECCREATE(CSrEnchRecord, CSrIdRecord)
	DEFINE_SRSUBRECCREATE(SR_NAME_EFID, CSrFormidSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_OBND, CSrDataSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_CIS2, CSrStringSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_FULL, CSrLStringSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_CTDA, CSrCtdaSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_EFIT, CSrEfitSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_ENIT, CSrEnitSubrecord::Create)
END_SRSUBRECCREATE()
/*===========================================================================
 *		End of Subrecord Creation Array
 *=========================================================================*/


/*===========================================================================
 *
 * Begin CSrRecord Field Map
 *
 *=========================================================================*/
BEGIN_SRFIELDMAP(CSrEnchRecord, CSrIdRecord)
	ADD_SRFIELDALL("ItemName",			SR_FIELD_ITEMNAME,			0, CSrEnchRecord, FieldItemName)
	ADD_SRFIELDALL("ConditionCount",	SR_FIELD_CONDITIONCOUNT,	0, CSrEnchRecord, FieldConditionCount)
	ADD_SRFIELDALL("BaseEnchant",		SR_FIELD_BASEENCHANT,		0, CSrEnchRecord, FieldBaseEnchant)
	ADD_SRFIELDALL("EffectCount",		SR_FIELD_EFFECTCOUNT,		0, CSrEnchRecord, FieldEffectCount)
	ADD_SRFIELDALL("ItemTypes",			SR_FIELD_ITEMTYPES,			0, CSrEnchRecord, FieldItemTypes)
	ADD_SRFIELDALL("EnchantCost",		SR_FIELD_ENCHANTCOST,		0, CSrEnchRecord, FieldEnchantCost)
	ADD_SRFIELDALL("ChargeAmount",		SR_FIELD_CHARGE,			0, CSrEnchRecord, FieldCharge)
	//ADD_SRFIELDALL("UserData",			SR_FIELD_USERDATA,			0, CSrEnchRecord, FieldUserData)
END_SRFIELDMAP()
/*===========================================================================
 *		End of CObRecord Field Map
 *=========================================================================*/


/*===========================================================================
 *
 * Class CSrEnchRecord Constructor
 *
 *=========================================================================*/
CSrEnchRecord::CSrEnchRecord () 
{
	m_pItemName = NULL;
	m_pBounds = NULL;
	m_pEffectData = NULL;
}
/*===========================================================================
 *		End of Class CSrEnchRecord Constructor
 *=========================================================================*/


/*===========================================================================
 *
 * Class CSrEnchRecord Method - void Destroy (void);
 *
 *=========================================================================*/
void CSrEnchRecord::Destroy (void) 
{
	m_pItemName = NULL;
	m_pBounds = NULL;
	m_pEffectData = NULL;

	CSrIdRecord::Destroy();
}
/*===========================================================================
 *		End of Class Method CSrEnchRecord::Destroy()
 *=========================================================================*/


/*===========================================================================
 *
 * Class CSrEnchRecord Method - void InitializeNew (void);
 *
 *=========================================================================*/
void CSrEnchRecord::InitializeNew (void) 
{
	CSrIdRecord::InitializeNew();

	AddNewSubrecord(SR_NAME_FULL);
	if (m_pItemName != NULL) m_pItemName->InitializeNew();

	AddNewSubrecord(SR_NAME_ENIT);
	if (m_pEffectData != NULL) m_pEffectData->InitializeNew();

}
/*===========================================================================
 *		End of Class Method CSrEnchRecord::InitializeNew()
 *=========================================================================*/


/*===========================================================================
 *
 * Class CSrEnchRecord Event - void OnAddSubrecord (pSubrecord);
 *
 *=========================================================================*/
void CSrEnchRecord::OnAddSubrecord (CSrSubrecord* pSubrecord) {

	if (pSubrecord->GetRecordType() == SR_NAME_OBND)
	{
		m_pBounds = SrCastClass(CSrDataSubrecord, pSubrecord);
	}
	else if (pSubrecord->GetRecordType() == SR_NAME_FULL)
	{
		m_pItemName = SrCastClass(CSrLStringSubrecord, pSubrecord);
	}
	else if (pSubrecord->GetRecordType() == SR_NAME_ENIT)
	{
		m_pEffectData = SrCastClass(CSrEnitSubrecord, pSubrecord);
	}
	else
	{
		CSrIdRecord::OnAddSubrecord(pSubrecord);
	}

}
/*===========================================================================
 *		End of Class Event CSrEnchRecord::OnAddSubRecord()
 *=========================================================================*/


/*===========================================================================
 *
 * Class CSrEnchRecord Event - void OnDeleteSubrecord (pSubrecord);
 *
 *=========================================================================*/
void CSrEnchRecord::OnDeleteSubrecord (CSrSubrecord* pSubrecord) {

	if (m_pBounds == pSubrecord)
		m_pBounds = NULL;
	else if (m_pItemName == pSubrecord)
		m_pItemName = NULL;
	else if (m_pEffectData == pSubrecord)
		m_pEffectData = NULL;
	else
		CSrIdRecord::OnDeleteSubrecord(pSubrecord);

}
/*===========================================================================
 *		End of Class Event CSrEnchRecord::OnDeleteSubrecord()
 *=========================================================================*/


const char* CSrEnchRecord::GetBaseEnchant (void)
{
	if (m_pEffectData == NULL || m_pParent == NULL) return NULL;
	if (m_pEffectData->GetEnchantData().BaseEnchID == 0) return "";
	return m_pParent->GetEditorID(m_pEffectData->GetEnchantData().BaseEnchID);
}


const char* CSrEnchRecord::GetItemTypes (void)
{
	if (m_pEffectData == NULL || m_pParent == NULL) return NULL;
	if (m_pEffectData->GetEnchantData().ItemTypesID == 0) return "";
	return m_pParent->GetEditorID(m_pEffectData->GetEnchantData().ItemTypesID);
}


void CSrEnchRecord::SetBaseEnchant (const char* pString)
{
	if (m_pEffectData == NULL || m_pParent == NULL) return;

	if (pString == NULL || *pString == 0)
	{
		m_pEffectData->GetEnchantData().BaseEnchID = 0;
		return;
	}

	CSrIdRecord* pRecord = m_pParent->FindEditorID(pString);
	if (pRecord == NULL) return;
	m_pEffectData->GetEnchantData().BaseEnchID = pRecord->GetFormID();
}



void CSrEnchRecord::SetItemTypes (const char* pString)
{
	if (m_pEffectData == NULL || m_pParent == NULL) return;

	if (pString == NULL || *pString == 0)
	{
		m_pEffectData->GetEnchantData().ItemTypesID = 0;
		return;
	}

	CSrIdRecord* pRecord = m_pParent->FindEditorID(pString);
	if (pRecord == NULL) return;
	m_pEffectData->GetEnchantData().ItemTypesID = pRecord->GetFormID();
}


/*===========================================================================
 *
 * Begin CSrEnchRecord Get Field Methods
 *
 *=========================================================================*/
DEFINE_SRGETFIELD(CSrEnchRecord::GetFieldBaseEnchant,        String = GetBaseEnchant())
DEFINE_SRGETFIELD(CSrEnchRecord::GetFieldItemTypes,          String = GetItemTypes())
DEFINE_SRGETFIELD(CSrEnchRecord::GetFieldEffectCount,        String.Format("%u", GetEffectCount()))
DEFINE_SRGETFIELD(CSrEnchRecord::GetFieldUserData,           String.Format("%d", GetEnchantData().Type3))
DEFINE_SRGETFIELD(CSrEnchRecord::GetFieldEnchantCost,        String.Format("%u", GetEnchantData().EnchantCost))
DEFINE_SRGETFIELD(CSrEnchRecord::GetFieldCharge,             String.Format("%u", GetEnchantData().ChargeAmount))
/*===========================================================================
 *		End of CSrEnchRecord Get Field Methods
 *=========================================================================*/


/*===========================================================================
 *
 * Begin CSrEnchRecord Compare Field Methods
 *
 *=========================================================================*/
DEFINE_SRCOMPFIELDSTRING(CSrEnchRecord, CompareFieldBaseEnchant,	 GetBaseEnchant)
DEFINE_SRCOMPFIELDSTRING(CSrEnchRecord, CompareFieldItemTypes,		GetItemTypes)
DEFINE_SRCOMPFIELDDWORD(CSrEnchRecord,  CompareFieldEffectCount,	GetEffectCount)
DEFINE_SRCOMPFIELDDWORD1(CSrEnchRecord, CompareFieldUserData,		GetEnchantData().Type3)
DEFINE_SRCOMPFIELDDWORD1(CSrEnchRecord, CompareFieldEnchantCost,	GetEnchantData().EnchantCost)
DEFINE_SRCOMPFIELDDWORD1(CSrEnchRecord, CompareFieldCharge,			GetEnchantData().ChargeAmount)
/*===========================================================================
 *		End of CSrEnchRecord Compare Field Methods
 *=========================================================================*/


/*===========================================================================
 *
 * Begin CSrEnchRecord Set Field Methods
 *
 *=========================================================================*/
BEGIN_SRSETFIELD(CSrEnchRecord::SetFieldBaseEnchant)
	SetBaseEnchant(pString);
END_SRSETFIELD()


BEGIN_SRSETFIELD(CSrEnchRecord::SetFieldItemTypes)
	SetItemTypes(pString);
END_SRSETFIELD()


BEGIN_SRSETFIELD(CSrEnchRecord::SetFieldEffectCount)
END_SRSETFIELD()


BEGIN_SRSETFIELD(CSrEnchRecord::SetFieldUserData)
END_SRSETFIELD()


BEGIN_SRSETFIELD(CSrEnchRecord::SetFieldEnchantCost)
	dword Value;

	if (!SrFieldConvertDword(pString, Value)) return false;
	GetEnchantData().EnchantCost = Value;
END_SRSETFIELD()


BEGIN_SRSETFIELD(CSrEnchRecord::SetFieldCharge)
	dword Value;

	if (!SrFieldConvertDword(pString, Value)) return false;
	GetEnchantData().ChargeAmount = Value;
END_SRSETFIELD()
/*===========================================================================
 *		End of CSrEnchRecord Set Field Methods
 *=========================================================================*/
