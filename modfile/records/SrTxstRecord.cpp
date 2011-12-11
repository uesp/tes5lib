/*===========================================================================
 *
 * File:		SrTxstRecord.CPP
 * Author:		Dave Humphrey (dave@uesp.net)
 * Created On:	5 December 2011
 *
 * Description
 *
 *=========================================================================*/

	/* Include Files */
#include "srTxstrecord.h"


/*===========================================================================
 *
 * Begin Subrecord Creation Array
 *
 *=========================================================================*/
BEGIN_SRSUBRECCREATE(CSrTxstRecord, CSrRecord)
	DEFINE_SRSUBRECCREATE(SR_NAME_OBND, CSrDataSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_EDID, CSrDataSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_TX05, CSrDataSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_DNAM, CSrDataSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_TX00, CSrDataSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_TX01, CSrDataSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_DODT, CSrDataSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_TX03, CSrDataSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_TX07, CSrDataSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_TX02, CSrDataSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_TX04, CSrDataSubrecord::Create)

END_SRSUBRECCREATE()
/*===========================================================================
 *		End of Subrecord Creation Array
 *=========================================================================*/


/*===========================================================================
 *
 * Begin CSrRecord Field Map
 *
 *=========================================================================*/
BEGIN_SRFIELDMAP(CSrTxstRecord, CSrRecord)
END_SRFIELDMAP()
/*===========================================================================
 *		End of CObRecord Field Map
 *=========================================================================*/


/*===========================================================================
 *
 * Class CSrTxstRecord Constructor
 *
 *=========================================================================*/
CSrTxstRecord::CSrTxstRecord () 
{
}
/*===========================================================================
 *		End of Class CSrTxstRecord Constructor
 *=========================================================================*/


/*===========================================================================
 *
 * Class CSrTxstRecord Method - void Destroy (void);
 *
 *=========================================================================*/
void CSrTxstRecord::Destroy (void) 
{
	CSrRecord::Destroy();
}
/*===========================================================================
 *		End of Class Method CSrTxstRecord::Destroy()
 *=========================================================================*/


/*===========================================================================
 *
 * Class CSrTxstRecord Method - void InitializeNew (void);
 *
 *=========================================================================*/
void CSrTxstRecord::InitializeNew (void) 
{

	/* Call the base class method first */
	CSrRecord::InitializeNew();


}
/*===========================================================================
 *		End of Class Method CSrTxstRecord::InitializeNew()
 *=========================================================================*/


/*===========================================================================
 *
 * Class CSrTxstRecord Event - void OnAddSubrecord (pSubrecord);
 *
 *=========================================================================*/
void CSrTxstRecord::OnAddSubrecord (CSrSubrecord* pSubrecord) {

	if (pSubrecord->GetRecordType() == SR_NAME_OBND)
	{
		m_pObndData = SrCastClass(CSrDataSubrecord, pSubrecord);
	}
	else if (pSubrecord->GetRecordType() == SR_NAME_EDID)
	{
		m_pEdidData = SrCastClass(CSrDataSubrecord, pSubrecord);
	}
	else if (pSubrecord->GetRecordType() == SR_NAME_TX05)
	{
		m_pTx05Data = SrCastClass(CSrDataSubrecord, pSubrecord);
	}
	else if (pSubrecord->GetRecordType() == SR_NAME_DNAM)
	{
		m_pDnamData = SrCastClass(CSrDataSubrecord, pSubrecord);
	}
	else if (pSubrecord->GetRecordType() == SR_NAME_TX00)
	{
		m_pTx00Data = SrCastClass(CSrDataSubrecord, pSubrecord);
	}
	else if (pSubrecord->GetRecordType() == SR_NAME_TX01)
	{
		m_pTx01Data = SrCastClass(CSrDataSubrecord, pSubrecord);
	}
	else if (pSubrecord->GetRecordType() == SR_NAME_DODT)
	{
		m_pDodtData = SrCastClass(CSrDataSubrecord, pSubrecord);
	}
	else if (pSubrecord->GetRecordType() == SR_NAME_TX03)
	{
		m_pTx03Data = SrCastClass(CSrDataSubrecord, pSubrecord);
	}
	else if (pSubrecord->GetRecordType() == SR_NAME_TX07)
	{
		m_pTx07Data = SrCastClass(CSrDataSubrecord, pSubrecord);
	}
	else if (pSubrecord->GetRecordType() == SR_NAME_TX02)
	{
		m_pTx02Data = SrCastClass(CSrDataSubrecord, pSubrecord);
	}
	else if (pSubrecord->GetRecordType() == SR_NAME_TX04)
	{
		m_pTx04Data = SrCastClass(CSrDataSubrecord, pSubrecord);
	}

	else
	{
	CSrRecord::OnAddSubrecord(pSubrecord);
	}

}
/*===========================================================================
 *		End of Class Event CSrTxstRecord::OnAddSubRecord()
 *=========================================================================*/


/*===========================================================================
 *
 * Class CSrTxstRecord Event - void OnDeleteSubrecord (pSubrecord);
 *
 *=========================================================================*/
void CSrTxstRecord::OnDeleteSubrecord (CSrSubrecord* pSubrecord) {

	if (m_pObndData == pSubrecord)
		m_pObndData = NULL;
	else if (m_pEdidData == pSubrecord)
		m_pEdidData = NULL;
	else if (m_pTx05Data == pSubrecord)
		m_pTx05Data = NULL;
	else if (m_pDnamData == pSubrecord)
		m_pDnamData = NULL;
	else if (m_pTx00Data == pSubrecord)
		m_pTx00Data = NULL;
	else if (m_pTx01Data == pSubrecord)
		m_pTx01Data = NULL;
	else if (m_pDodtData == pSubrecord)
		m_pDodtData = NULL;
	else if (m_pTx03Data == pSubrecord)
		m_pTx03Data = NULL;
	else if (m_pTx07Data == pSubrecord)
		m_pTx07Data = NULL;
	else if (m_pTx02Data == pSubrecord)
		m_pTx02Data = NULL;
	else if (m_pTx04Data == pSubrecord)
		m_pTx04Data = NULL;

	else
		CSrRecord::OnDeleteSubrecord(pSubrecord);

}
/*===========================================================================
 *		End of Class Event CSrTxstRecord::OnDeleteSubrecord()
 *=========================================================================*/


/*===========================================================================
 *
 * Begin CSrTxstRecord Get Field Methods
 *
 *=========================================================================*/
/*===========================================================================
 *		End of CSrTxstRecord Get Field Methods
 *=========================================================================*/


/*===========================================================================
 *
 * Begin CSrTxstRecord Compare Field Methods
 *
 *=========================================================================*/
/*===========================================================================
 *		End of CSrTxstRecord Compare Field Methods
 *=========================================================================*/


/*===========================================================================
 *
 * Begin CSrTxstRecord Set Field Methods
 *
 *=========================================================================*/
/*===========================================================================
 *		End of CSrTxstRecord Set Field Methods
 *=========================================================================*/
