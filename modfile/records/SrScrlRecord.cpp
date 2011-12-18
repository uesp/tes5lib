/*===========================================================================
 *
 * File:		SrScrlRecord.CPP
 * Author:		Dave Humphrey (dave@uesp.net)
 * Created On:	5 December 2011
 *
 * Description
 *
 *=========================================================================*/

	/* Include Files */
#include "srScrlrecord.h"
#include "../srrecordhandler.h"


srscrldata_t CSrScrlRecord::s_NullScrollData;
srspitdata_t CSrScrlRecord::s_NullSpitData;


/*===========================================================================
 *
 * Begin Subrecord Creation Array
 *
 *=========================================================================*/
BEGIN_SRSUBRECCREATE(CSrScrlRecord, CSrItem1Record)
	DEFINE_SRSUBRECCREATE(SR_NAME_ETYP, CSrFormidSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_OBND, CSrDataSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_EFID, CSrFormidSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_DESC, CSrLStringSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_MDOB, CSrDataSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_MODT, CSrDataSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_DATA, CSrScrlDataSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_SPIT, CSrSpitSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_EFIT, CSrEfitSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_CTDA, CSrCtdaSubrecord::Create)
END_SRSUBRECCREATE()
/*===========================================================================
 *		End of Subrecord Creation Array
 *=========================================================================*/


/*===========================================================================
 *
 * Begin CSrItem1Record Field Map
 *
 *=========================================================================*/
BEGIN_SRFIELDMAP(CSrScrlRecord, CSrItem1Record)
	ADD_SRFIELDALL("ItemName",		SR_FIELD_ITEMNAME,		0, CSrScrlRecord, FieldItemName)
	ADD_SRFIELDALL("Description",	SR_FIELD_DESCRIPTION,	0, CSrScrlRecord, FieldDescription)
	ADD_SRFIELDALL("EffectCount",	SR_FIELD_EFFECTCOUNT,	0, CSrScrlRecord, FieldEffectCount)
	ADD_SRFIELDALL("EquipSlot",		SR_FIELD_EQUIPSLOT,		0, CSrScrlRecord, FieldEquipSlot)
	ADD_SRFIELDALL("Weight",		SR_FIELD_WEIGHT,		0, CSrScrlRecord, FieldWeight)
	ADD_SRFIELDALL("Value",			SR_FIELD_VALUE,			0, CSrScrlRecord, FieldValue)
	ADD_SRFIELDALL("CastTime",		SR_FIELD_CASTTIME,		0, CSrScrlRecord, FieldCastTime)
	ADD_SRFIELDALL("CastAnim",		SR_FIELD_CASTANIM,		0, CSrScrlRecord, FieldCastAnim)
	ADD_SRFIELDALL("CastType",		SR_FIELD_CASTTYPE,		0, CSrScrlRecord, FieldCastType)
	ADD_SRFIELDALL("Cost",			SR_FIELD_COST,			0, CSrScrlRecord, FieldCost)
END_SRFIELDMAP()
/*===========================================================================
 *		End of CObRecord Field Map
 *=========================================================================*/


/*===========================================================================
 *
 * Class CSrScrlRecord Constructor
 *
 *=========================================================================*/
CSrScrlRecord::CSrScrlRecord () 
{
	m_pEquipmentSlot = NULL;
	m_pBoundsData = NULL;
	m_pDescription = NULL;
	m_pMdobData = NULL;
	m_pModtData = NULL;
	m_pScrlData = NULL;
	m_pSpitData = NULL;
}
/*===========================================================================
 *		End of Class CSrScrlRecord Constructor
 *=========================================================================*/


/*===========================================================================
 *
 * Class CSrScrlRecord Method - void Destroy (void);
 *
 *=========================================================================*/
void CSrScrlRecord::Destroy (void) 
{
	m_pEquipmentSlot = NULL;
	m_pBoundsData = NULL;
	m_pDescription = NULL;
	m_pMdobData = NULL;
	m_pModtData = NULL;
	m_pScrlData = NULL;
	m_pSpitData = NULL;

	CSrItem1Record::Destroy();
}
/*===========================================================================
 *		End of Class Method CSrScrlRecord::Destroy()
 *=========================================================================*/


/*===========================================================================
 *
 * Class CSrScrlRecord Method - void InitializeNew (void);
 *
 *=========================================================================*/
void CSrScrlRecord::InitializeNew (void) 
{
	CSrItem1Record::InitializeNew();

	AddNewSubrecord(SR_NAME_DATA);
	if (m_pScrlData != NULL) m_pScrlData->InitializeNew();

	AddNewSubrecord(SR_NAME_SPIT);
	if (m_pSpitData != NULL) m_pSpitData->InitializeNew();

	AddNewSubrecord(SR_NAME_DESC);
	if (m_pDescription != NULL) m_pDescription->InitializeNew();

	AddNewSubrecord(SR_NAME_ETYP);
	if (m_pEquipmentSlot != NULL) m_pEquipmentSlot->InitializeNew();

}
/*===========================================================================
 *		End of Class Method CSrScrlRecord::InitializeNew()
 *=========================================================================*/


/*===========================================================================
 *
 * Class CSrScrlRecord Event - void OnAddSubrecord (pSubrecord);
 *
 *=========================================================================*/
void CSrScrlRecord::OnAddSubrecord (CSrSubrecord* pSubrecord) {

	if (pSubrecord->GetRecordType() == SR_NAME_ETYP)
	{
		m_pEquipmentSlot = SrCastClass(CSrFormidSubrecord, pSubrecord);
	}
	else if (pSubrecord->GetRecordType() == SR_NAME_OBND)
	{
		m_pBoundsData = SrCastClass(CSrDataSubrecord, pSubrecord);
	}
	else if (pSubrecord->GetRecordType() == SR_NAME_DESC)
	{
		m_pDescription = SrCastClass(CSrLStringSubrecord, pSubrecord);
	}
	else if (pSubrecord->GetRecordType() == SR_NAME_MDOB)
	{
		m_pMdobData = SrCastClass(CSrDataSubrecord, pSubrecord);
	}
	else if (pSubrecord->GetRecordType() == SR_NAME_MODT)
	{
		m_pModtData = SrCastClass(CSrDataSubrecord, pSubrecord);
	}
	else if (pSubrecord->GetRecordType() == SR_NAME_DATA)
	{
		m_pScrlData = SrCastClass(CSrScrlDataSubrecord, pSubrecord);
	}
	else if (pSubrecord->GetRecordType() == SR_NAME_SPIT)
	{
		m_pSpitData = SrCastClass(CSrSpitSubrecord, pSubrecord);
	}
	else
	{
		CSrItem1Record::OnAddSubrecord(pSubrecord);
	}

}
/*===========================================================================
 *		End of Class Event CSrScrlRecord::OnAddSubRecord()
 *=========================================================================*/


/*===========================================================================
 *
 * Class CSrScrlRecord Event - void OnDeleteSubrecord (pSubrecord);
 *
 *=========================================================================*/
void CSrScrlRecord::OnDeleteSubrecord (CSrSubrecord* pSubrecord) {

	if (m_pEquipmentSlot == pSubrecord)
		m_pEquipmentSlot = NULL;
	else if (m_pBoundsData == pSubrecord)
		m_pBoundsData = NULL;
	else if (m_pDescription == pSubrecord)
		m_pDescription = NULL;
	else if (m_pMdobData == pSubrecord)
		m_pMdobData = NULL;
	else if (m_pModtData == pSubrecord)
		m_pModtData = NULL;
	else if (m_pScrlData == pSubrecord)
		m_pScrlData = NULL;
	else if (m_pSpitData == pSubrecord)
		m_pSpitData = NULL;
	else
		CSrItem1Record::OnDeleteSubrecord(pSubrecord);

}
/*===========================================================================
 *		End of Class Event CSrScrlRecord::OnDeleteSubrecord()
 *=========================================================================*/


/*===========================================================================
 *
 * Begin CSrScrlRecord Get Field Methods
 *
 *=========================================================================*/
/*===========================================================================
 *		End of CSrScrlRecord Get Field Methods
 *=========================================================================*/


/*===========================================================================
 *
 * Begin CSrScrlRecord Compare Field Methods
 *
 *=========================================================================*/
/*===========================================================================
 *		End of CSrScrlRecord Compare Field Methods
 *=========================================================================*/


/*===========================================================================
 *
 * Begin CSrScrlRecord Set Field Methods
 *
 *=========================================================================*/
/*===========================================================================
 *		End of CSrScrlRecord Set Field Methods
 *=========================================================================*/
