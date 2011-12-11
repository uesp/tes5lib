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


/*===========================================================================
 *
 * Begin Subrecord Creation Array
 *
 *=========================================================================*/
BEGIN_SRSUBRECCREATE(CSrSpelRecord, CSrRecord)
	DEFINE_SRSUBRECCREATE(SR_NAME_EDID, CSrDataSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_EFID, CSrDataSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_ETYP, CSrDataSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_OBND, CSrDataSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_FULL, CSrDataSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_DESC, CSrDataSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_SPIT, CSrDataSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_EFIT, CSrDataSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_MDOB, CSrDataSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_CTDA, CSrDataSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_CIS2, CSrDataSubrecord::Create)

END_SRSUBRECCREATE()
/*===========================================================================
 *		End of Subrecord Creation Array
 *=========================================================================*/


/*===========================================================================
 *
 * Begin CSrRecord Field Map
 *
 *=========================================================================*/
BEGIN_SRFIELDMAP(CSrSpelRecord, CSrRecord)
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
	CSrRecord::Destroy();
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

	/* Call the base class method first */
	CSrRecord::InitializeNew();


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

	if (pSubrecord->GetRecordType() == SR_NAME_EDID)
	{
		m_pEdidData = SrCastClass(CSrDataSubrecord, pSubrecord);
	}
	else if (pSubrecord->GetRecordType() == SR_NAME_EFID)
	{
		m_pEfidData = SrCastClass(CSrDataSubrecord, pSubrecord);
	}
	else if (pSubrecord->GetRecordType() == SR_NAME_ETYP)
	{
		m_pEtypData = SrCastClass(CSrDataSubrecord, pSubrecord);
	}
	else if (pSubrecord->GetRecordType() == SR_NAME_OBND)
	{
		m_pObndData = SrCastClass(CSrDataSubrecord, pSubrecord);
	}
	else if (pSubrecord->GetRecordType() == SR_NAME_FULL)
	{
		m_pFullData = SrCastClass(CSrDataSubrecord, pSubrecord);
	}
	else if (pSubrecord->GetRecordType() == SR_NAME_DESC)
	{
		m_pDescData = SrCastClass(CSrDataSubrecord, pSubrecord);
	}
	else if (pSubrecord->GetRecordType() == SR_NAME_SPIT)
	{
		m_pSpitData = SrCastClass(CSrDataSubrecord, pSubrecord);
	}
	else if (pSubrecord->GetRecordType() == SR_NAME_EFIT)
	{
		m_pEfitData = SrCastClass(CSrDataSubrecord, pSubrecord);
	}
	else if (pSubrecord->GetRecordType() == SR_NAME_MDOB)
	{
		m_pMdobData = SrCastClass(CSrDataSubrecord, pSubrecord);
	}
	else if (pSubrecord->GetRecordType() == SR_NAME_CTDA)
	{
		m_pCtdaData = SrCastClass(CSrDataSubrecord, pSubrecord);
	}
	else if (pSubrecord->GetRecordType() == SR_NAME_CIS2)
	{
		m_pCis2Data = SrCastClass(CSrDataSubrecord, pSubrecord);
	}

	else
	{
	CSrRecord::OnAddSubrecord(pSubrecord);
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

	if (m_pEdidData == pSubrecord)
		m_pEdidData = NULL;
	else if (m_pEfidData == pSubrecord)
		m_pEfidData = NULL;
	else if (m_pEtypData == pSubrecord)
		m_pEtypData = NULL;
	else if (m_pObndData == pSubrecord)
		m_pObndData = NULL;
	else if (m_pFullData == pSubrecord)
		m_pFullData = NULL;
	else if (m_pDescData == pSubrecord)
		m_pDescData = NULL;
	else if (m_pSpitData == pSubrecord)
		m_pSpitData = NULL;
	else if (m_pEfitData == pSubrecord)
		m_pEfitData = NULL;
	else if (m_pMdobData == pSubrecord)
		m_pMdobData = NULL;
	else if (m_pCtdaData == pSubrecord)
		m_pCtdaData = NULL;
	else if (m_pCis2Data == pSubrecord)
		m_pCis2Data = NULL;

	else
		CSrRecord::OnDeleteSubrecord(pSubrecord);

}
/*===========================================================================
 *		End of Class Event CSrSpelRecord::OnDeleteSubrecord()
 *=========================================================================*/


/*===========================================================================
 *
 * Begin CSrSpelRecord Get Field Methods
 *
 *=========================================================================*/
/*===========================================================================
 *		End of CSrSpelRecord Get Field Methods
 *=========================================================================*/


/*===========================================================================
 *
 * Begin CSrSpelRecord Compare Field Methods
 *
 *=========================================================================*/
/*===========================================================================
 *		End of CSrSpelRecord Compare Field Methods
 *=========================================================================*/


/*===========================================================================
 *
 * Begin CSrSpelRecord Set Field Methods
 *
 *=========================================================================*/
/*===========================================================================
 *		End of CSrSpelRecord Set Field Methods
 *=========================================================================*/
