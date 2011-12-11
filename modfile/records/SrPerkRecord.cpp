/*===========================================================================
 *
 * File:		SrPerkRecord.CPP
 * Author:		Dave Humphrey (dave@uesp.net)
 * Created On:	5 December 2011
 *
 * Description
 *
 *=========================================================================*/

	/* Include Files */
#include "srPerkrecord.h"


/*===========================================================================
 *
 * Begin Subrecord Creation Array
 *
 *=========================================================================*/
BEGIN_SRSUBRECCREATE(CSrPerkRecord, CSrRecord)
	DEFINE_SRSUBRECCREATE(SR_NAME_EDID, CSrDataSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_EPFT, CSrDataSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_PRKC, CSrDataSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_DESC, CSrDataSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_EPF2, CSrDataSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_FULL, CSrDataSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_CTDA, CSrDataSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_DATA, CSrDataSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_PRKE, CSrDataSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_PRKF, CSrDataSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_EPFD, CSrDataSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_CIS2, CSrDataSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_NNAM, CSrDataSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_VMAD, CSrDataSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_EPF3, CSrDataSubrecord::Create)

END_SRSUBRECCREATE()
/*===========================================================================
 *		End of Subrecord Creation Array
 *=========================================================================*/


/*===========================================================================
 *
 * Begin CSrRecord Field Map
 *
 *=========================================================================*/
BEGIN_SRFIELDMAP(CSrPerkRecord, CSrRecord)
END_SRFIELDMAP()
/*===========================================================================
 *		End of CObRecord Field Map
 *=========================================================================*/


/*===========================================================================
 *
 * Class CSrPerkRecord Constructor
 *
 *=========================================================================*/
CSrPerkRecord::CSrPerkRecord () 
{
}
/*===========================================================================
 *		End of Class CSrPerkRecord Constructor
 *=========================================================================*/


/*===========================================================================
 *
 * Class CSrPerkRecord Method - void Destroy (void);
 *
 *=========================================================================*/
void CSrPerkRecord::Destroy (void) 
{
	CSrRecord::Destroy();
}
/*===========================================================================
 *		End of Class Method CSrPerkRecord::Destroy()
 *=========================================================================*/


/*===========================================================================
 *
 * Class CSrPerkRecord Method - void InitializeNew (void);
 *
 *=========================================================================*/
void CSrPerkRecord::InitializeNew (void) 
{

	/* Call the base class method first */
	CSrRecord::InitializeNew();


}
/*===========================================================================
 *		End of Class Method CSrPerkRecord::InitializeNew()
 *=========================================================================*/


/*===========================================================================
 *
 * Class CSrPerkRecord Event - void OnAddSubrecord (pSubrecord);
 *
 *=========================================================================*/
void CSrPerkRecord::OnAddSubrecord (CSrSubrecord* pSubrecord) {

	if (pSubrecord->GetRecordType() == SR_NAME_EDID)
	{
		m_pEdidData = SrCastClass(CSrDataSubrecord, pSubrecord);
	}
	else if (pSubrecord->GetRecordType() == SR_NAME_EPFT)
	{
		m_pEpftData = SrCastClass(CSrDataSubrecord, pSubrecord);
	}
	else if (pSubrecord->GetRecordType() == SR_NAME_PRKC)
	{
		m_pPrkcData = SrCastClass(CSrDataSubrecord, pSubrecord);
	}
	else if (pSubrecord->GetRecordType() == SR_NAME_DESC)
	{
		m_pDescData = SrCastClass(CSrDataSubrecord, pSubrecord);
	}
	else if (pSubrecord->GetRecordType() == SR_NAME_EPF2)
	{
		m_pEpf2Data = SrCastClass(CSrDataSubrecord, pSubrecord);
	}
	else if (pSubrecord->GetRecordType() == SR_NAME_FULL)
	{
		m_pFullData = SrCastClass(CSrDataSubrecord, pSubrecord);
	}
	else if (pSubrecord->GetRecordType() == SR_NAME_CTDA)
	{
		m_pCtdaData = SrCastClass(CSrDataSubrecord, pSubrecord);
	}
	else if (pSubrecord->GetRecordType() == SR_NAME_DATA)
	{
		m_pDataData = SrCastClass(CSrDataSubrecord, pSubrecord);
	}
	else if (pSubrecord->GetRecordType() == SR_NAME_PRKE)
	{
		m_pPrkeData = SrCastClass(CSrDataSubrecord, pSubrecord);
	}
	else if (pSubrecord->GetRecordType() == SR_NAME_PRKF)
	{
		m_pPrkfData = SrCastClass(CSrDataSubrecord, pSubrecord);
	}
	else if (pSubrecord->GetRecordType() == SR_NAME_EPFD)
	{
		m_pEpfdData = SrCastClass(CSrDataSubrecord, pSubrecord);
	}
	else if (pSubrecord->GetRecordType() == SR_NAME_CIS2)
	{
		m_pCis2Data = SrCastClass(CSrDataSubrecord, pSubrecord);
	}
	else if (pSubrecord->GetRecordType() == SR_NAME_NNAM)
	{
		m_pNnamData = SrCastClass(CSrDataSubrecord, pSubrecord);
	}
	else if (pSubrecord->GetRecordType() == SR_NAME_VMAD)
	{
		m_pVmadData = SrCastClass(CSrDataSubrecord, pSubrecord);
	}
	else if (pSubrecord->GetRecordType() == SR_NAME_EPF3)
	{
		m_pEpf3Data = SrCastClass(CSrDataSubrecord, pSubrecord);
	}

	else
	{
	CSrRecord::OnAddSubrecord(pSubrecord);
	}

}
/*===========================================================================
 *		End of Class Event CSrPerkRecord::OnAddSubRecord()
 *=========================================================================*/


/*===========================================================================
 *
 * Class CSrPerkRecord Event - void OnDeleteSubrecord (pSubrecord);
 *
 *=========================================================================*/
void CSrPerkRecord::OnDeleteSubrecord (CSrSubrecord* pSubrecord) {

	if (m_pEdidData == pSubrecord)
		m_pEdidData = NULL;
	else if (m_pEpftData == pSubrecord)
		m_pEpftData = NULL;
	else if (m_pPrkcData == pSubrecord)
		m_pPrkcData = NULL;
	else if (m_pDescData == pSubrecord)
		m_pDescData = NULL;
	else if (m_pEpf2Data == pSubrecord)
		m_pEpf2Data = NULL;
	else if (m_pFullData == pSubrecord)
		m_pFullData = NULL;
	else if (m_pCtdaData == pSubrecord)
		m_pCtdaData = NULL;
	else if (m_pDataData == pSubrecord)
		m_pDataData = NULL;
	else if (m_pPrkeData == pSubrecord)
		m_pPrkeData = NULL;
	else if (m_pPrkfData == pSubrecord)
		m_pPrkfData = NULL;
	else if (m_pEpfdData == pSubrecord)
		m_pEpfdData = NULL;
	else if (m_pCis2Data == pSubrecord)
		m_pCis2Data = NULL;
	else if (m_pNnamData == pSubrecord)
		m_pNnamData = NULL;
	else if (m_pVmadData == pSubrecord)
		m_pVmadData = NULL;
	else if (m_pEpf3Data == pSubrecord)
		m_pEpf3Data = NULL;

	else
		CSrRecord::OnDeleteSubrecord(pSubrecord);

}
/*===========================================================================
 *		End of Class Event CSrPerkRecord::OnDeleteSubrecord()
 *=========================================================================*/


/*===========================================================================
 *
 * Begin CSrPerkRecord Get Field Methods
 *
 *=========================================================================*/
/*===========================================================================
 *		End of CSrPerkRecord Get Field Methods
 *=========================================================================*/


/*===========================================================================
 *
 * Begin CSrPerkRecord Compare Field Methods
 *
 *=========================================================================*/
/*===========================================================================
 *		End of CSrPerkRecord Compare Field Methods
 *=========================================================================*/


/*===========================================================================
 *
 * Begin CSrPerkRecord Set Field Methods
 *
 *=========================================================================*/
/*===========================================================================
 *		End of CSrPerkRecord Set Field Methods
 *=========================================================================*/
