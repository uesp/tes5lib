/*===========================================================================
 *
 * File:		SrIngrRecord.CPP
 * Author:		Dave Humphrey (dave@uesp.net)
 * Created On:	5 December 2011
 *
 * Description
 *
 *=========================================================================*/

	/* Include Files */
#include "srIngrrecord.h"


sringrdata_t     CSrIngrRecord::s_NullIngrData;
sringrenitdata_t CSrIngrRecord::s_NullIngrEnitData;


/*===========================================================================
 *
 * Begin Subrecord Creation Array
 *
 *=========================================================================*/
BEGIN_SRSUBRECCREATE(CSrIngrRecord, CSrItem1Record)
	DEFINE_SRSUBRECCREATE(SR_NAME_EFID, CSrFormidSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_EFIT, CSrEfitSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_ENIT, CSrIngrEnitSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_DATA, CSrIngrDataSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_CTDA, CSrCtdaSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_CIS1, CSrStringSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_CIS2, CSrStringSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_MODT, CSrDataSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_YNAM, CSrFormidSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_ZNAM, CSrFormidSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_VMAD, CSrDataSubrecord::Create)
END_SRSUBRECCREATE()
/*===========================================================================
 *		End of Subrecord Creation Array
 *=========================================================================*/


/*===========================================================================
 *
 * Begin CSrItem1Record Field Map
 *
 *=========================================================================*/
BEGIN_SRFIELDMAP(CSrIngrRecord, CSrItem1Record)
	ADD_SRFIELDALL("Weight",			SR_FIELD_WEIGHT,			0, CSrIngrRecord, FieldWeight)
	ADD_SRFIELDALL("Value",				SR_FIELD_VALUE,				0, CSrIngrRecord, FieldValue)
	ADD_SRFIELDALL("PickupSound",		SR_FIELD_PICKUPSOUND,		0, CSrIngrRecord, FieldPickupSound)
	ADD_SRFIELDALL("DropSound",			SR_FIELD_DROPSOUND,			0, CSrIngrRecord, FieldDropSound)
	ADD_SRFIELDALL("EffectCount",		SR_FIELD_EFFECTCOUNT,		0, CSrIngrRecord, FieldEffectCount)
	ADD_SRFIELDALL("Unknown",			SR_FIELD_UNKNOWN1,			0, CSrIngrRecord, FieldUnknown)
END_SRFIELDMAP()
/*===========================================================================
 *		End of CObRecord Field Map
 *=========================================================================*/


/*===========================================================================
 *
 * Class CSrIngrRecord Constructor
 *
 *=========================================================================*/
CSrIngrRecord::CSrIngrRecord () 
{
	m_pBoundsData = NULL;
	m_pEnitData = NULL;
	m_pIngrData = NULL;
	m_pModtData = NULL;
	m_pPickupSound = NULL;
	m_pDropSound = NULL;
}
/*===========================================================================
 *		End of Class CSrIngrRecord Constructor
 *=========================================================================*/


/*===========================================================================
 *
 * Class CSrIngrRecord Method - void Destroy (void);
 *
 *=========================================================================*/
void CSrIngrRecord::Destroy (void) 
{
	m_pBoundsData = NULL;
	m_pEnitData = NULL;
	m_pIngrData = NULL;
	m_pModtData = NULL;
	m_pPickupSound = NULL;
	m_pDropSound = NULL;

	CSrItem1Record::Destroy();
}
/*===========================================================================
 *		End of Class Method CSrIngrRecord::Destroy()
 *=========================================================================*/


/*===========================================================================
 *
 * Class CSrIngrRecord Method - void InitializeNew (void);
 *
 *=========================================================================*/
void CSrIngrRecord::InitializeNew (void) 
{
	CSrItem1Record::InitializeNew();

	AddNewSubrecord(SR_NAME_DATA);
	if (m_pIngrData != NULL) m_pIngrData->InitializeNew();

	AddNewSubrecord(SR_NAME_ENIT);
	if (m_pEnitData != NULL) m_pEnitData->InitializeNew();
}
/*===========================================================================
 *		End of Class Method CSrIngrRecord::InitializeNew()
 *=========================================================================*/


/*===========================================================================
 *
 * Class CSrIngrRecord Event - void OnAddSubrecord (pSubrecord);
 *
 *=========================================================================*/
void CSrIngrRecord::OnAddSubrecord (CSrSubrecord* pSubrecord) {

	if (pSubrecord->GetRecordType() == SR_NAME_OBND)
	{
		m_pBoundsData = SrCastClass(CSrDataSubrecord, pSubrecord);
	}
	else if (pSubrecord->GetRecordType() == SR_NAME_ENIT)
	{
		m_pEnitData = SrCastClass(CSrIngrEnitSubrecord, pSubrecord);
	}
	else if (pSubrecord->GetRecordType() == SR_NAME_DATA)
	{
		m_pIngrData = SrCastClass(CSrIngrDataSubrecord, pSubrecord);
	}
	else if (pSubrecord->GetRecordType() == SR_NAME_MODT)
	{
		m_pModtData = SrCastClass(CSrDataSubrecord, pSubrecord);
	}
	else if (pSubrecord->GetRecordType() == SR_NAME_YNAM)
	{
		m_pPickupSound = SrCastClass(CSrFormidSubrecord, pSubrecord);
	}
	else if (pSubrecord->GetRecordType() == SR_NAME_ZNAM)
	{
		m_pDropSound = SrCastClass(CSrFormidSubrecord, pSubrecord);
	}
	else
	{
		CSrItem1Record::OnAddSubrecord(pSubrecord);
	}

}
/*===========================================================================
 *		End of Class Event CSrIngrRecord::OnAddSubRecord()
 *=========================================================================*/


/*===========================================================================
 *
 * Class CSrIngrRecord Event - void OnDeleteSubrecord (pSubrecord);
 *
 *=========================================================================*/
void CSrIngrRecord::OnDeleteSubrecord (CSrSubrecord* pSubrecord) {

	if (m_pBoundsData == pSubrecord)
		m_pBoundsData = NULL;
	else if (m_pEnitData == pSubrecord)
		m_pEnitData = NULL;
	else if (m_pIngrData == pSubrecord)
		m_pIngrData = NULL;
	else if (m_pModtData == pSubrecord)
		m_pModtData = NULL;
	else if (m_pPickupSound == pSubrecord)
		m_pPickupSound = NULL;
	else if (m_pDropSound == pSubrecord)
		m_pDropSound = NULL;
	else
		CSrItem1Record::OnDeleteSubrecord(pSubrecord);

}
/*===========================================================================
 *		End of Class Event CSrIngrRecord::OnDeleteSubrecord()
 *=========================================================================*/


/*===========================================================================
 *
 * Begin CSrIngrRecord Get Field Methods
 *
 *=========================================================================*/
/*===========================================================================
 *		End of CSrIngrRecord Get Field Methods
 *=========================================================================*/


/*===========================================================================
 *
 * Begin CSrIngrRecord Compare Field Methods
 *
 *=========================================================================*/
/*===========================================================================
 *		End of CSrIngrRecord Compare Field Methods
 *=========================================================================*/


/*===========================================================================
 *
 * Begin CSrIngrRecord Set Field Methods
 *
 *=========================================================================*/
/*===========================================================================
 *		End of CSrIngrRecord Set Field Methods
 *=========================================================================*/
