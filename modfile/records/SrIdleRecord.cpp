/*===========================================================================
 *
 * File:		SrIdleRecord.CPP
 * Author:		Dave Humphrey (dave@uesp.net)
 * Created On:	5 December 2011
 *
 * Description
 *
 *=========================================================================*/

	/* Include Files */
#include "srIdlerecord.h"


/*===========================================================================
 *
 * Begin Subrecord Creation Array
 *
 *=========================================================================*/
BEGIN_SRSUBRECCREATE(CSrIdleRecord, CSrRecord)
	DEFINE_SRSUBRECCREATE(SR_NAME_CIS1, CSrDataSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_EDID, CSrDataSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_DATA, CSrDataSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_ANAM, CSrDataSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_CTDA, CSrDataSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_DNAM, CSrDataSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_ENAM, CSrDataSubrecord::Create)

END_SRSUBRECCREATE()
/*===========================================================================
 *		End of Subrecord Creation Array
 *=========================================================================*/


/*===========================================================================
 *
 * Begin CSrRecord Field Map
 *
 *=========================================================================*/
BEGIN_SRFIELDMAP(CSrIdleRecord, CSrRecord)
END_SRFIELDMAP()
/*===========================================================================
 *		End of CObRecord Field Map
 *=========================================================================*/


/*===========================================================================
 *
 * Class CSrIdleRecord Constructor
 *
 *=========================================================================*/
CSrIdleRecord::CSrIdleRecord () 
{
}
/*===========================================================================
 *		End of Class CSrIdleRecord Constructor
 *=========================================================================*/


/*===========================================================================
 *
 * Class CSrIdleRecord Method - void Destroy (void);
 *
 *=========================================================================*/
void CSrIdleRecord::Destroy (void) 
{
	CSrRecord::Destroy();
}
/*===========================================================================
 *		End of Class Method CSrIdleRecord::Destroy()
 *=========================================================================*/


/*===========================================================================
 *
 * Class CSrIdleRecord Method - void InitializeNew (void);
 *
 *=========================================================================*/
void CSrIdleRecord::InitializeNew (void) 
{

	/* Call the base class method first */
	CSrRecord::InitializeNew();


}
/*===========================================================================
 *		End of Class Method CSrIdleRecord::InitializeNew()
 *=========================================================================*/


/*===========================================================================
 *
 * Class CSrIdleRecord Event - void OnAddSubrecord (pSubrecord);
 *
 *=========================================================================*/
void CSrIdleRecord::OnAddSubrecord (CSrSubrecord* pSubrecord) {

	if (pSubrecord->GetRecordType() == SR_NAME_CIS1)
	{
		m_pCis1Data = SrCastClass(CSrDataSubrecord, pSubrecord);
	}
	else if (pSubrecord->GetRecordType() == SR_NAME_EDID)
	{
		m_pEdidData = SrCastClass(CSrDataSubrecord, pSubrecord);
	}
	else if (pSubrecord->GetRecordType() == SR_NAME_DATA)
	{
		m_pDataData = SrCastClass(CSrDataSubrecord, pSubrecord);
	}
	else if (pSubrecord->GetRecordType() == SR_NAME_ANAM)
	{
		m_pAnamData = SrCastClass(CSrDataSubrecord, pSubrecord);
	}
	else if (pSubrecord->GetRecordType() == SR_NAME_CTDA)
	{
		m_pCtdaData = SrCastClass(CSrDataSubrecord, pSubrecord);
	}
	else if (pSubrecord->GetRecordType() == SR_NAME_DNAM)
	{
		m_pDnamData = SrCastClass(CSrDataSubrecord, pSubrecord);
	}
	else if (pSubrecord->GetRecordType() == SR_NAME_ENAM)
	{
		m_pEnamData = SrCastClass(CSrDataSubrecord, pSubrecord);
	}

	else
	{
	CSrRecord::OnAddSubrecord(pSubrecord);
	}

}
/*===========================================================================
 *		End of Class Event CSrIdleRecord::OnAddSubRecord()
 *=========================================================================*/


/*===========================================================================
 *
 * Class CSrIdleRecord Event - void OnDeleteSubrecord (pSubrecord);
 *
 *=========================================================================*/
void CSrIdleRecord::OnDeleteSubrecord (CSrSubrecord* pSubrecord) {

	if (m_pCis1Data == pSubrecord)
		m_pCis1Data = NULL;
	else if (m_pEdidData == pSubrecord)
		m_pEdidData = NULL;
	else if (m_pDataData == pSubrecord)
		m_pDataData = NULL;
	else if (m_pAnamData == pSubrecord)
		m_pAnamData = NULL;
	else if (m_pCtdaData == pSubrecord)
		m_pCtdaData = NULL;
	else if (m_pDnamData == pSubrecord)
		m_pDnamData = NULL;
	else if (m_pEnamData == pSubrecord)
		m_pEnamData = NULL;

	else
		CSrRecord::OnDeleteSubrecord(pSubrecord);

}
/*===========================================================================
 *		End of Class Event CSrIdleRecord::OnDeleteSubrecord()
 *=========================================================================*/


/*===========================================================================
 *
 * Begin CSrIdleRecord Get Field Methods
 *
 *=========================================================================*/
/*===========================================================================
 *		End of CSrIdleRecord Get Field Methods
 *=========================================================================*/


/*===========================================================================
 *
 * Begin CSrIdleRecord Compare Field Methods
 *
 *=========================================================================*/
/*===========================================================================
 *		End of CSrIdleRecord Compare Field Methods
 *=========================================================================*/


/*===========================================================================
 *
 * Begin CSrIdleRecord Set Field Methods
 *
 *=========================================================================*/
/*===========================================================================
 *		End of CSrIdleRecord Set Field Methods
 *=========================================================================*/
