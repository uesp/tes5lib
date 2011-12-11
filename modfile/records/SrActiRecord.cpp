/*===========================================================================
 *
 * File:		SrActiRecord.CPP
 * Author:		Dave Humphrey (dave@uesp.net)
 * Created On:	5 December 2011
 *
 * Description
 *
 *=========================================================================*/

	/* Include Files */
#include "srActirecord.h"


/*===========================================================================
 *
 * Begin Subrecord Creation Array
 *
 *=========================================================================*/
BEGIN_SRSUBRECCREATE(CSrActiRecord, CSrItem1Record)
	DEFINE_SRSUBRECCREATE(SR_NAME_FNAM, CSrDataSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_DMDS, CSrDataSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_OBND, CSrDataSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_PNAM, CSrDataSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_KNAM, CSrDataSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_DEST, CSrDataSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_VMAD, CSrDataSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_MODT, CSrDataSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_MODS, CSrDataSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_DSTD, CSrDataSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_DMDL, CSrDataSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_DMDT, CSrDataSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_DSTF, CSrDataSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_RNAM, CSrDataSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_VNAM, CSrDataSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_WNAM, CSrDataSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_SNAM, CSrDataSubrecord::Create)
END_SRSUBRECCREATE()
/*===========================================================================
 *		End of Subrecord Creation Array
 *=========================================================================*/


/*===========================================================================
 *
 * Begin CSrRecord Field Map
 *
 *=========================================================================*/
BEGIN_SRFIELDMAP(CSrActiRecord, CSrItem1Record)
END_SRFIELDMAP()
/*===========================================================================
 *		End of CObRecord Field Map
 *=========================================================================*/


/*===========================================================================
 *
 * Class CSrActiRecord Constructor
 *
 *=========================================================================*/
CSrActiRecord::CSrActiRecord () 
{
}
/*===========================================================================
 *		End of Class CSrActiRecord Constructor
 *=========================================================================*/


/*===========================================================================
 *
 * Class CSrActiRecord Method - void Destroy (void);
 *
 *=========================================================================*/
void CSrActiRecord::Destroy (void) 
{
	CSrItem1Record::Destroy();
}
/*===========================================================================
 *		End of Class Method CSrActiRecord::Destroy()
 *=========================================================================*/


/*===========================================================================
 *
 * Class CSrActiRecord Method - void InitializeNew (void);
 *
 *=========================================================================*/
void CSrActiRecord::InitializeNew (void) 
{
	CSrItem1Record::InitializeNew();
}
/*===========================================================================
 *		End of Class Method CSrActiRecord::InitializeNew()
 *=========================================================================*/


/*===========================================================================
 *
 * Class CSrActiRecord Event - void OnAddSubrecord (pSubrecord);
 *
 *=========================================================================*/
void CSrActiRecord::OnAddSubrecord (CSrSubrecord* pSubrecord) {

	if (pSubrecord->GetRecordType() == SR_NAME_FNAM)
	{
		m_pFnamData = SrCastClass(CSrDataSubrecord, pSubrecord);
	}
	else if (pSubrecord->GetRecordType() == SR_NAME_DMDS)
	{
		m_pDmdsData = SrCastClass(CSrDataSubrecord, pSubrecord);
	}
	else if (pSubrecord->GetRecordType() == SR_NAME_OBND)
	{
		m_pObndData = SrCastClass(CSrDataSubrecord, pSubrecord);
	}
	else if (pSubrecord->GetRecordType() == SR_NAME_PNAM)
	{
		m_pPnamData = SrCastClass(CSrDataSubrecord, pSubrecord);
	}
	else if (pSubrecord->GetRecordType() == SR_NAME_KNAM)
	{
		m_pKnamData = SrCastClass(CSrDataSubrecord, pSubrecord);
	}
	else if (pSubrecord->GetRecordType() == SR_NAME_DEST)
	{
		m_pDestData = SrCastClass(CSrDataSubrecord, pSubrecord);
	}
	else if (pSubrecord->GetRecordType() == SR_NAME_VMAD)
	{
		m_pVmadData = SrCastClass(CSrDataSubrecord, pSubrecord);
	}
	else if (pSubrecord->GetRecordType() == SR_NAME_MODT)
	{
		m_pModtData = SrCastClass(CSrDataSubrecord, pSubrecord);
	}
	else if (pSubrecord->GetRecordType() == SR_NAME_MODS)
	{
		m_pModsData = SrCastClass(CSrDataSubrecord, pSubrecord);
	}
	else if (pSubrecord->GetRecordType() == SR_NAME_DSTD)
	{
		m_pDstdData = SrCastClass(CSrDataSubrecord, pSubrecord);
	}
	else if (pSubrecord->GetRecordType() == SR_NAME_DMDL)
	{
		m_pDmdlData = SrCastClass(CSrDataSubrecord, pSubrecord);
	}
	else if (pSubrecord->GetRecordType() == SR_NAME_DMDT)
	{
		m_pDmdtData = SrCastClass(CSrDataSubrecord, pSubrecord);
	}
	else if (pSubrecord->GetRecordType() == SR_NAME_DSTF)
	{
		m_pDstfData = SrCastClass(CSrDataSubrecord, pSubrecord);
	}
	else if (pSubrecord->GetRecordType() == SR_NAME_RNAM)
	{
		m_pRnamData = SrCastClass(CSrDataSubrecord, pSubrecord);
	}
	else if (pSubrecord->GetRecordType() == SR_NAME_VNAM)
	{
		m_pVnamData = SrCastClass(CSrDataSubrecord, pSubrecord);
	}
	else if (pSubrecord->GetRecordType() == SR_NAME_WNAM)
	{
		m_pWnamData = SrCastClass(CSrDataSubrecord, pSubrecord);
	}
	else if (pSubrecord->GetRecordType() == SR_NAME_SNAM)
	{
		m_pSnamData = SrCastClass(CSrDataSubrecord, pSubrecord);
	}
	else
	{
		CSrItem1Record::OnAddSubrecord(pSubrecord);
	}

}
/*===========================================================================
 *		End of Class Event CSrActiRecord::OnAddSubRecord()
 *=========================================================================*/


/*===========================================================================
 *
 * Class CSrActiRecord Event - void OnDeleteSubrecord (pSubrecord);
 *
 *=========================================================================*/
void CSrActiRecord::OnDeleteSubrecord (CSrSubrecord* pSubrecord) {

	if (m_pFnamData == pSubrecord)
		m_pFnamData = NULL;
	else if (m_pDmdsData == pSubrecord)
		m_pDmdsData = NULL;
	else if (m_pObndData == pSubrecord)
		m_pObndData = NULL;
	else if (m_pPnamData == pSubrecord)
		m_pPnamData = NULL;
	else if (m_pKnamData == pSubrecord)
		m_pKnamData = NULL;
	else if (m_pDestData == pSubrecord)
		m_pDestData = NULL;
	else if (m_pVmadData == pSubrecord)
		m_pVmadData = NULL;
	else if (m_pModtData == pSubrecord)
		m_pModtData = NULL;
	else if (m_pModsData == pSubrecord)
		m_pModsData = NULL;
	else if (m_pDstdData == pSubrecord)
		m_pDstdData = NULL;
	else if (m_pDmdlData == pSubrecord)
		m_pDmdlData = NULL;
	else if (m_pDmdtData == pSubrecord)
		m_pDmdtData = NULL;
	else if (m_pDstfData == pSubrecord)
		m_pDstfData = NULL;
	else if (m_pRnamData == pSubrecord)
		m_pRnamData = NULL;
	else if (m_pVnamData == pSubrecord)
		m_pVnamData = NULL;
	else if (m_pWnamData == pSubrecord)
		m_pWnamData = NULL;
	else if (m_pSnamData == pSubrecord)
		m_pSnamData = NULL;
	else
		CSrItem1Record::OnDeleteSubrecord(pSubrecord);

}
/*===========================================================================
 *		End of Class Event CSrActiRecord::OnDeleteSubrecord()
 *=========================================================================*/


/*===========================================================================
 *
 * Begin CSrActiRecord Get Field Methods
 *
 *=========================================================================*/
/*===========================================================================
 *		End of CSrActiRecord Get Field Methods
 *=========================================================================*/


/*===========================================================================
 *
 * Begin CSrActiRecord Compare Field Methods
 *
 *=========================================================================*/
/*===========================================================================
 *		End of CSrActiRecord Compare Field Methods
 *=========================================================================*/


/*===========================================================================
 *
 * Begin CSrActiRecord Set Field Methods
 *
 *=========================================================================*/
/*===========================================================================
 *		End of CSrActiRecord Set Field Methods
 *=========================================================================*/
