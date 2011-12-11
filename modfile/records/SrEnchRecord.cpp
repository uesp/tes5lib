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


/*===========================================================================
 *
 * Begin Subrecord Creation Array
 *
 *=========================================================================*/
BEGIN_SRSUBRECCREATE(CSrEnchRecord, CSrIdRecord)
	DEFINE_SRSUBRECCREATE(SR_NAME_EFID, CSrDataSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_OBND, CSrDataSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_CIS2, CSrDataSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_FULL, CSrDataSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_CTDA, CSrDataSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_EFIT, CSrDataSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_ENIT, CSrDataSubrecord::Create)
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

	if (pSubrecord->GetRecordType() == SR_NAME_EFID)
	{
		m_pEfidData = SrCastClass(CSrDataSubrecord, pSubrecord);
	}
	else if (pSubrecord->GetRecordType() == SR_NAME_OBND)
	{
		m_pObndData = SrCastClass(CSrDataSubrecord, pSubrecord);
	}
	else if (pSubrecord->GetRecordType() == SR_NAME_CIS2)
	{
		m_pCis2Data = SrCastClass(CSrDataSubrecord, pSubrecord);
	}
	else if (pSubrecord->GetRecordType() == SR_NAME_FULL)
	{
		m_pFullData = SrCastClass(CSrDataSubrecord, pSubrecord);
	}
	else if (pSubrecord->GetRecordType() == SR_NAME_CTDA)
	{
		m_pCtdaData = SrCastClass(CSrDataSubrecord, pSubrecord);
	}
	else if (pSubrecord->GetRecordType() == SR_NAME_EFIT)
	{
		m_pEfitData = SrCastClass(CSrDataSubrecord, pSubrecord);
	}
	else if (pSubrecord->GetRecordType() == SR_NAME_ENIT)
	{
		m_pEnitData = SrCastClass(CSrDataSubrecord, pSubrecord);
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

	if (m_pEfidData == pSubrecord)
		m_pEfidData = NULL;
	else if (m_pObndData == pSubrecord)
		m_pObndData = NULL;
	else if (m_pCis2Data == pSubrecord)
		m_pCis2Data = NULL;
	else if (m_pFullData == pSubrecord)
		m_pFullData = NULL;
	else if (m_pCtdaData == pSubrecord)
		m_pCtdaData = NULL;
	else if (m_pEfitData == pSubrecord)
		m_pEfitData = NULL;
	else if (m_pEnitData == pSubrecord)
		m_pEnitData = NULL;
	else
		CSrIdRecord::OnDeleteSubrecord(pSubrecord);

}
/*===========================================================================
 *		End of Class Event CSrEnchRecord::OnDeleteSubrecord()
 *=========================================================================*/


/*===========================================================================
 *
 * Begin CSrEnchRecord Get Field Methods
 *
 *=========================================================================*/
/*===========================================================================
 *		End of CSrEnchRecord Get Field Methods
 *=========================================================================*/


/*===========================================================================
 *
 * Begin CSrEnchRecord Compare Field Methods
 *
 *=========================================================================*/
/*===========================================================================
 *		End of CSrEnchRecord Compare Field Methods
 *=========================================================================*/


/*===========================================================================
 *
 * Begin CSrEnchRecord Set Field Methods
 *
 *=========================================================================*/
/*===========================================================================
 *		End of CSrEnchRecord Set Field Methods
 *=========================================================================*/
