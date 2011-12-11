/*===========================================================================
 *
 * File:		SrAvifRecord.CPP
 * Author:		Dave Humphrey (dave@uesp.net)
 * Created On:	5 December 2011
 *
 * Description
 *
 *=========================================================================*/

	/* Include Files */
#include "srAvifrecord.h"


/*===========================================================================
 *
 * Begin Subrecord Creation Array
 *
 *=========================================================================*/
BEGIN_SRSUBRECCREATE(CSrAvifRecord, CSrIdRecord)
	DEFINE_SRSUBRECCREATE(SR_NAME_AVSK, CSrDataSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_FNAM, CSrDataSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_FULL, CSrDataSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_CNAM, CSrDataSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_DESC, CSrDataSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_XNAM, CSrDataSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_PNAM, CSrDataSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_YNAM, CSrDataSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_HNAM, CSrDataSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_VNAM, CSrDataSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_SNAM, CSrDataSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_INAM, CSrDataSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_ANAM, CSrDataSubrecord::Create)
END_SRSUBRECCREATE()
/*===========================================================================
 *		End of Subrecord Creation Array
 *=========================================================================*/


/*===========================================================================
 *
 * Begin CSrRecord Field Map
 *
 *=========================================================================*/
BEGIN_SRFIELDMAP(CSrAvifRecord, CSrIdRecord)
END_SRFIELDMAP()
/*===========================================================================
 *		End of CObRecord Field Map
 *=========================================================================*/


/*===========================================================================
 *
 * Class CSrAvifRecord Constructor
 *
 *=========================================================================*/
CSrAvifRecord::CSrAvifRecord () 
{
}
/*===========================================================================
 *		End of Class CSrAvifRecord Constructor
 *=========================================================================*/


/*===========================================================================
 *
 * Class CSrAvifRecord Method - void Destroy (void);
 *
 *=========================================================================*/
void CSrAvifRecord::Destroy (void) 
{
	CSrIdRecord::Destroy();
}
/*===========================================================================
 *		End of Class Method CSrAvifRecord::Destroy()
 *=========================================================================*/


/*===========================================================================
 *
 * Class CSrAvifRecord Method - void InitializeNew (void);
 *
 *=========================================================================*/
void CSrAvifRecord::InitializeNew (void) 
{
	CSrIdRecord::InitializeNew();
}
/*===========================================================================
 *		End of Class Method CSrAvifRecord::InitializeNew()
 *=========================================================================*/


/*===========================================================================
 *
 * Class CSrAvifRecord Event - void OnAddSubrecord (pSubrecord);
 *
 *=========================================================================*/
void CSrAvifRecord::OnAddSubrecord (CSrSubrecord* pSubrecord) {

	if (pSubrecord->GetRecordType() == SR_NAME_AVSK)
	{
		m_pAvskData = SrCastClass(CSrDataSubrecord, pSubrecord);
	}
	else if (pSubrecord->GetRecordType() == SR_NAME_FNAM)
	{
		m_pFnamData = SrCastClass(CSrDataSubrecord, pSubrecord);
	}
	else if (pSubrecord->GetRecordType() == SR_NAME_FULL)
	{
		m_pFullData = SrCastClass(CSrDataSubrecord, pSubrecord);
	}
	else if (pSubrecord->GetRecordType() == SR_NAME_CNAM)
	{
		m_pCnamData = SrCastClass(CSrDataSubrecord, pSubrecord);
	}
	else if (pSubrecord->GetRecordType() == SR_NAME_DESC)
	{
		m_pDescData = SrCastClass(CSrDataSubrecord, pSubrecord);
	}
	else if (pSubrecord->GetRecordType() == SR_NAME_XNAM)
	{
		m_pXnamData = SrCastClass(CSrDataSubrecord, pSubrecord);
	}
	else if (pSubrecord->GetRecordType() == SR_NAME_PNAM)
	{
		m_pPnamData = SrCastClass(CSrDataSubrecord, pSubrecord);
	}
	else if (pSubrecord->GetRecordType() == SR_NAME_YNAM)
	{
		m_pYnamData = SrCastClass(CSrDataSubrecord, pSubrecord);
	}
	else if (pSubrecord->GetRecordType() == SR_NAME_HNAM)
	{
		m_pHnamData = SrCastClass(CSrDataSubrecord, pSubrecord);
	}
	else if (pSubrecord->GetRecordType() == SR_NAME_VNAM)
	{
		m_pVnamData = SrCastClass(CSrDataSubrecord, pSubrecord);
	}
	else if (pSubrecord->GetRecordType() == SR_NAME_SNAM)
	{
		m_pSnamData = SrCastClass(CSrDataSubrecord, pSubrecord);
	}
	else if (pSubrecord->GetRecordType() == SR_NAME_INAM)
	{
		m_pInamData = SrCastClass(CSrDataSubrecord, pSubrecord);
	}
	else if (pSubrecord->GetRecordType() == SR_NAME_ANAM)
	{
		m_pAnamData = SrCastClass(CSrDataSubrecord, pSubrecord);
	}
	else
	{
		CSrIdRecord::OnAddSubrecord(pSubrecord);
	}

}
/*===========================================================================
 *		End of Class Event CSrAvifRecord::OnAddSubRecord()
 *=========================================================================*/


/*===========================================================================
 *
 * Class CSrAvifRecord Event - void OnDeleteSubrecord (pSubrecord);
 *
 *=========================================================================*/
void CSrAvifRecord::OnDeleteSubrecord (CSrSubrecord* pSubrecord) {

	if (m_pAvskData == pSubrecord)
		m_pAvskData = NULL;
	else if (m_pFnamData == pSubrecord)
		m_pFnamData = NULL;
	else if (m_pFullData == pSubrecord)
		m_pFullData = NULL;
	else if (m_pCnamData == pSubrecord)
		m_pCnamData = NULL;
	else if (m_pDescData == pSubrecord)
		m_pDescData = NULL;
	else if (m_pXnamData == pSubrecord)
		m_pXnamData = NULL;
	else if (m_pPnamData == pSubrecord)
		m_pPnamData = NULL;
	else if (m_pYnamData == pSubrecord)
		m_pYnamData = NULL;
	else if (m_pHnamData == pSubrecord)
		m_pHnamData = NULL;
	else if (m_pVnamData == pSubrecord)
		m_pVnamData = NULL;
	else if (m_pSnamData == pSubrecord)
		m_pSnamData = NULL;
	else if (m_pInamData == pSubrecord)
		m_pInamData = NULL;
	else if (m_pAnamData == pSubrecord)
		m_pAnamData = NULL;
	else
		CSrIdRecord::OnDeleteSubrecord(pSubrecord);

}
/*===========================================================================
 *		End of Class Event CSrAvifRecord::OnDeleteSubrecord()
 *=========================================================================*/


/*===========================================================================
 *
 * Begin CSrAvifRecord Get Field Methods
 *
 *=========================================================================*/
/*===========================================================================
 *		End of CSrAvifRecord Get Field Methods
 *=========================================================================*/


/*===========================================================================
 *
 * Begin CSrAvifRecord Compare Field Methods
 *
 *=========================================================================*/
/*===========================================================================
 *		End of CSrAvifRecord Compare Field Methods
 *=========================================================================*/


/*===========================================================================
 *
 * Begin CSrAvifRecord Set Field Methods
 *
 *=========================================================================*/
/*===========================================================================
 *		End of CSrAvifRecord Set Field Methods
 *=========================================================================*/
