/*===========================================================================
 *
 * File:		SrHazdRecord.CPP
 * Author:		Dave Humphrey (dave@uesp.net)
 * Created On:	5 December 2011
 *
 * Description
 *
 *=========================================================================*/

	/* Include Files */
#include "srHazdrecord.h"


/*===========================================================================
 *
 * Begin Subrecord Creation Array
 *
 *=========================================================================*/
BEGIN_SRSUBRECCREATE(CSrHazdRecord, CSrRecord)
	DEFINE_SRSUBRECCREATE(SR_NAME_MODL, CSrDataSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_OBND, CSrDataSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_EDID, CSrDataSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_FULL, CSrDataSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_MODT, CSrDataSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_DATA, CSrDataSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_MNAM, CSrDataSubrecord::Create)

END_SRSUBRECCREATE()
/*===========================================================================
 *		End of Subrecord Creation Array
 *=========================================================================*/


/*===========================================================================
 *
 * Begin CSrRecord Field Map
 *
 *=========================================================================*/
BEGIN_SRFIELDMAP(CSrHazdRecord, CSrRecord)
END_SRFIELDMAP()
/*===========================================================================
 *		End of CObRecord Field Map
 *=========================================================================*/


/*===========================================================================
 *
 * Class CSrHazdRecord Constructor
 *
 *=========================================================================*/
CSrHazdRecord::CSrHazdRecord () 
{
}
/*===========================================================================
 *		End of Class CSrHazdRecord Constructor
 *=========================================================================*/


/*===========================================================================
 *
 * Class CSrHazdRecord Method - void Destroy (void);
 *
 *=========================================================================*/
void CSrHazdRecord::Destroy (void) 
{
	CSrRecord::Destroy();
}
/*===========================================================================
 *		End of Class Method CSrHazdRecord::Destroy()
 *=========================================================================*/


/*===========================================================================
 *
 * Class CSrHazdRecord Method - void InitializeNew (void);
 *
 *=========================================================================*/
void CSrHazdRecord::InitializeNew (void) 
{

	/* Call the base class method first */
	CSrRecord::InitializeNew();


}
/*===========================================================================
 *		End of Class Method CSrHazdRecord::InitializeNew()
 *=========================================================================*/


/*===========================================================================
 *
 * Class CSrHazdRecord Event - void OnAddSubrecord (pSubrecord);
 *
 *=========================================================================*/
void CSrHazdRecord::OnAddSubrecord (CSrSubrecord* pSubrecord) {

	if (pSubrecord->GetRecordType() == SR_NAME_MODL)
	{
		m_pModlData = SrCastClass(CSrDataSubrecord, pSubrecord);
	}
	else if (pSubrecord->GetRecordType() == SR_NAME_OBND)
	{
		m_pObndData = SrCastClass(CSrDataSubrecord, pSubrecord);
	}
	else if (pSubrecord->GetRecordType() == SR_NAME_EDID)
	{
		m_pEdidData = SrCastClass(CSrDataSubrecord, pSubrecord);
	}
	else if (pSubrecord->GetRecordType() == SR_NAME_FULL)
	{
		m_pFullData = SrCastClass(CSrDataSubrecord, pSubrecord);
	}
	else if (pSubrecord->GetRecordType() == SR_NAME_MODT)
	{
		m_pModtData = SrCastClass(CSrDataSubrecord, pSubrecord);
	}
	else if (pSubrecord->GetRecordType() == SR_NAME_DATA)
	{
		m_pDataData = SrCastClass(CSrDataSubrecord, pSubrecord);
	}
	else if (pSubrecord->GetRecordType() == SR_NAME_MNAM)
	{
		m_pMnamData = SrCastClass(CSrDataSubrecord, pSubrecord);
	}

	else
	{
	CSrRecord::OnAddSubrecord(pSubrecord);
	}

}
/*===========================================================================
 *		End of Class Event CSrHazdRecord::OnAddSubRecord()
 *=========================================================================*/


/*===========================================================================
 *
 * Class CSrHazdRecord Event - void OnDeleteSubrecord (pSubrecord);
 *
 *=========================================================================*/
void CSrHazdRecord::OnDeleteSubrecord (CSrSubrecord* pSubrecord) {

	if (m_pModlData == pSubrecord)
		m_pModlData = NULL;
	else if (m_pObndData == pSubrecord)
		m_pObndData = NULL;
	else if (m_pEdidData == pSubrecord)
		m_pEdidData = NULL;
	else if (m_pFullData == pSubrecord)
		m_pFullData = NULL;
	else if (m_pModtData == pSubrecord)
		m_pModtData = NULL;
	else if (m_pDataData == pSubrecord)
		m_pDataData = NULL;
	else if (m_pMnamData == pSubrecord)
		m_pMnamData = NULL;

	else
		CSrRecord::OnDeleteSubrecord(pSubrecord);

}
/*===========================================================================
 *		End of Class Event CSrHazdRecord::OnDeleteSubrecord()
 *=========================================================================*/


/*===========================================================================
 *
 * Begin CSrHazdRecord Get Field Methods
 *
 *=========================================================================*/
/*===========================================================================
 *		End of CSrHazdRecord Get Field Methods
 *=========================================================================*/


/*===========================================================================
 *
 * Begin CSrHazdRecord Compare Field Methods
 *
 *=========================================================================*/
/*===========================================================================
 *		End of CSrHazdRecord Compare Field Methods
 *=========================================================================*/


/*===========================================================================
 *
 * Begin CSrHazdRecord Set Field Methods
 *
 *=========================================================================*/
/*===========================================================================
 *		End of CSrHazdRecord Set Field Methods
 *=========================================================================*/
