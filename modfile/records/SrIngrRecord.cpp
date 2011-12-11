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


/*===========================================================================
 *
 * Begin Subrecord Creation Array
 *
 *=========================================================================*/
BEGIN_SRSUBRECCREATE(CSrIngrRecord, CSrItem1Record)
	DEFINE_SRSUBRECCREATE(SR_NAME_OBND, CSrDataSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_EFID, CSrDataSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_EFIT, CSrDataSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_ENIT, CSrDataSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_DATA, CSrDataSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_MODT, CSrDataSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_YNAM, CSrDataSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_ZNAM, CSrDataSubrecord::Create)
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
		m_pObndData = SrCastClass(CSrDataSubrecord, pSubrecord);
	}
	else if (pSubrecord->GetRecordType() == SR_NAME_EFID)
	{
		m_pEfidData = SrCastClass(CSrDataSubrecord, pSubrecord);
	}
	else if (pSubrecord->GetRecordType() == SR_NAME_EFIT)
	{
		m_pEfitData = SrCastClass(CSrDataSubrecord, pSubrecord);
	}
	else if (pSubrecord->GetRecordType() == SR_NAME_ENIT)
	{
		m_pEnitData = SrCastClass(CSrDataSubrecord, pSubrecord);
	}
	else if (pSubrecord->GetRecordType() == SR_NAME_DATA)
	{
		m_pDataData = SrCastClass(CSrDataSubrecord, pSubrecord);
	}
	else if (pSubrecord->GetRecordType() == SR_NAME_MODT)
	{
		m_pModtData = SrCastClass(CSrDataSubrecord, pSubrecord);
	}
	else if (pSubrecord->GetRecordType() == SR_NAME_YNAM)
	{
		m_pYnamData = SrCastClass(CSrDataSubrecord, pSubrecord);
	}
	else if (pSubrecord->GetRecordType() == SR_NAME_ZNAM)
	{
		m_pZnamData = SrCastClass(CSrDataSubrecord, pSubrecord);
	}
	else if (pSubrecord->GetRecordType() == SR_NAME_VMAD)
	{
		m_pVmadData = SrCastClass(CSrDataSubrecord, pSubrecord);
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

	if (m_pObndData == pSubrecord)
		m_pObndData = NULL;
	else if (m_pEfidData == pSubrecord)
		m_pEfidData = NULL;
	else if (m_pEfitData == pSubrecord)
		m_pEfitData = NULL;
	else if (m_pEnitData == pSubrecord)
		m_pEnitData = NULL;
	else if (m_pDataData == pSubrecord)
		m_pDataData = NULL;
	else if (m_pModtData == pSubrecord)
		m_pModtData = NULL;
	else if (m_pYnamData == pSubrecord)
		m_pYnamData = NULL;
	else if (m_pZnamData == pSubrecord)
		m_pZnamData = NULL;
	else if (m_pVmadData == pSubrecord)
		m_pVmadData = NULL;
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
