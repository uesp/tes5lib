/*===========================================================================
 *
 * File:		SrAlchRecord.CPP
 * Author:		Dave Humphrey (dave@uesp.net)
 * Created On:	5 December 2011
 *
 * Description
 *
 *=========================================================================*/

	/* Include Files */
#include "srAlchrecord.h"
#include "../srrecordhandler.h"


sralchdata_t     CSrAlchRecord::s_NullAlchData;
srenitalchdata_t CSrAlchRecord::s_NullAlchEnitData;


/*===========================================================================
 *
 * Begin Subrecord Creation Array
 *
 *=========================================================================*/
BEGIN_SRSUBRECCREATE(CSrAlchRecord, CSrItem1Record)
	DEFINE_SRSUBRECCREATE(SR_NAME_EFID, CSrFormidSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_OBND, CSrDataSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_MODT, CSrDataSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_ENIT, CSrEnitAlchSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_EFIT, CSrEfitSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_DATA, CSrAlchDataSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_CTDA, CSrCtdaSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_YNAM, CSrFormidSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_ZNAM, CSrFormidSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_MODS, CSrDataSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_CIS1, CSrStringSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_CIS2, CSrStringSubrecord::Create)
END_SRSUBRECCREATE()
/*===========================================================================
 *		End of Subrecord Creation Array
 *=========================================================================*/


/*===========================================================================
 *
 * Begin CSrRecord Field Map
 *
 *=========================================================================*/
BEGIN_SRFIELDMAP(CSrAlchRecord, CSrItem1Record)
	ADD_SRFIELDALL("Weight",			SR_FIELD_WEIGHT,			0, CSrAlchRecord, FieldWeight)
	ADD_SRFIELDALL("PickupSound",		SR_FIELD_PICKUPSOUND,		0, CSrAlchRecord, FieldPickupSound)
	ADD_SRFIELDALL("DropSound",			SR_FIELD_DROPSOUND,			0, CSrAlchRecord, FieldDropSound)
	ADD_SRFIELDALL("EffectCount",		SR_FIELD_EFFECTCOUNT,		0, CSrAlchRecord, FieldEffectCount)
	ADD_SRFIELDALL("Value",				SR_FIELD_VALUE,				0, CSrAlchRecord, FieldValue)
	ADD_SRFIELDALL("Type",				SR_FIELD_TYPE,				0, CSrAlchRecord, FieldType)
	ADD_SRFIELDALL("UseSound",			SR_FIELD_USESOUND,			0, CSrAlchRecord, FieldUseSound)
END_SRFIELDMAP()
/*===========================================================================
 *		End of CObRecord Field Map
 *=========================================================================*/


/*===========================================================================
 *
 * Class CSrAlchRecord Constructor
 *
 *=========================================================================*/
CSrAlchRecord::CSrAlchRecord () 
{
	m_pBoundsData = NULL;
	m_pModtData = NULL;
	m_pEnitData = NULL;
	m_pAlchData = NULL;
	m_pPickupSound = NULL;
	m_pDropSound = NULL;
	m_pModsData = NULL;
}
/*===========================================================================
 *		End of Class CSrAlchRecord Constructor
 *=========================================================================*/


/*===========================================================================
 *
 * Class CSrAlchRecord Method - void Destroy (void);
 *
 *=========================================================================*/
void CSrAlchRecord::Destroy (void) 
{
	m_pBoundsData = NULL;
	m_pModtData = NULL;
	m_pEnitData = NULL;
	m_pAlchData = NULL;
	m_pPickupSound = NULL;
	m_pDropSound = NULL;
	m_pModsData = NULL;

	CSrItem1Record::Destroy();
}
/*===========================================================================
 *		End of Class Method CSrAlchRecord::Destroy()
 *=========================================================================*/


/*===========================================================================
 *
 * Class CSrAlchRecord Method - void InitializeNew (void);
 *
 *=========================================================================*/
void CSrAlchRecord::InitializeNew (void) 
{
	CSrItem1Record::InitializeNew();

	AddNewSubrecord(SR_NAME_DATA);
	if (m_pAlchData != NULL) m_pAlchData->InitializeNew();

	AddNewSubrecord(SR_NAME_ENIT);
	if (m_pEnitData != NULL) m_pEnitData->InitializeNew();
}
/*===========================================================================
 *		End of Class Method CSrAlchRecord::InitializeNew()
 *=========================================================================*/


/*===========================================================================
 *
 * Class CSrAlchRecord Event - void OnAddSubrecord (pSubrecord);
 *
 *=========================================================================*/
void CSrAlchRecord::OnAddSubrecord (CSrSubrecord* pSubrecord) {

	if (pSubrecord->GetRecordType() == SR_NAME_OBND)
	{
		m_pBoundsData = SrCastClass(CSrDataSubrecord, pSubrecord);
	}
	else if (pSubrecord->GetRecordType() == SR_NAME_MODT)
	{
		m_pModtData = SrCastClass(CSrDataSubrecord, pSubrecord);
	}
	else if (pSubrecord->GetRecordType() == SR_NAME_ENIT)
	{
		m_pEnitData = SrCastClass(CSrEnitAlchSubrecord, pSubrecord);
	}
	else if (pSubrecord->GetRecordType() == SR_NAME_DATA)
	{
		m_pAlchData = SrCastClass(CSrAlchDataSubrecord, pSubrecord);
	}
	else if (pSubrecord->GetRecordType() == SR_NAME_YNAM)
	{
		m_pPickupSound = SrCastClass(CSrFormidSubrecord, pSubrecord);
	}
	else if (pSubrecord->GetRecordType() == SR_NAME_ZNAM)
	{
		m_pDropSound = SrCastClass(CSrFormidSubrecord, pSubrecord);
	}
	else if (pSubrecord->GetRecordType() == SR_NAME_MODS)
	{
		m_pModsData = SrCastClass(CSrDataSubrecord, pSubrecord);
	}
	else
	{
		CSrItem1Record::OnAddSubrecord(pSubrecord);
	}

}
/*===========================================================================
 *		End of Class Event CSrAlchRecord::OnAddSubRecord()
 *=========================================================================*/


/*===========================================================================
 *
 * Class CSrAlchRecord Event - void OnDeleteSubrecord (pSubrecord);
 *
 *=========================================================================*/
void CSrAlchRecord::OnDeleteSubrecord (CSrSubrecord* pSubrecord) {

	if (m_pBoundsData == pSubrecord)
		m_pBoundsData = NULL;
	else if (m_pModtData == pSubrecord)
		m_pModtData = NULL;
	else if (m_pEnitData == pSubrecord)
		m_pEnitData = NULL;
	else if (m_pAlchData == pSubrecord)
		m_pAlchData = NULL;
	else if (m_pPickupSound == pSubrecord)
		m_pPickupSound = NULL;
	else if (m_pDropSound == pSubrecord)
		m_pDropSound = NULL;
	else if (m_pModsData == pSubrecord)
		m_pModsData = NULL;
	else
		CSrItem1Record::OnDeleteSubrecord(pSubrecord);

}
/*===========================================================================
 *		End of Class Event CSrAlchRecord::OnDeleteSubrecord()
 *=========================================================================*/


void CSrAlchRecord::SetUseSound (const char* pString)
{
	if (m_pParent == NULL) return;

	CSrIdRecord* pRecord = m_pParent->FindEditorID(pString);
	if (pRecord == NULL) return;

	GetEnitData().UseSoundID = pRecord->GetFormID();
}

/*===========================================================================
 *
 * Begin CSrAlchRecord Get Field Methods
 *
 *=========================================================================*/
/*===========================================================================
 *		End of CSrAlchRecord Get Field Methods
 *=========================================================================*/


/*===========================================================================
 *
 * Begin CSrAlchRecord Compare Field Methods
 *
 *=========================================================================*/
/*===========================================================================
 *		End of CSrAlchRecord Compare Field Methods
 *=========================================================================*/


/*===========================================================================
 *
 * Begin CSrAlchRecord Set Field Methods
 *
 *=========================================================================*/
/*===========================================================================
 *		End of CSrAlchRecord Set Field Methods
 *=========================================================================*/

