/*===========================================================================
 *
 * File:		SrShouRecord.CPP
 * Author:		Dave Humphrey (dave@uesp.net)
 * Created On:	5 December 2011
 *
 * Description
 *
 *=========================================================================*/

	/* Include Files */
#include "srShourecord.h"


/*===========================================================================
 *
 * Begin Subrecord Creation Array
 *
 *=========================================================================*/
BEGIN_SRSUBRECCREATE(CSrShouRecord, CSrRecord)
	DEFINE_SRSUBRECCREATE(SR_NAME_EDID, CSrDataSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_SNAM, CSrDataSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_DESC, CSrDataSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_FULL, CSrDataSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_MDOB, CSrDataSubrecord::Create)

END_SRSUBRECCREATE()
/*===========================================================================
 *		End of Subrecord Creation Array
 *=========================================================================*/


/*===========================================================================
 *
 * Begin CSrRecord Field Map
 *
 *=========================================================================*/
BEGIN_SRFIELDMAP(CSrShouRecord, CSrRecord)
END_SRFIELDMAP()
/*===========================================================================
 *		End of CObRecord Field Map
 *=========================================================================*/


/*===========================================================================
 *
 * Class CSrShouRecord Constructor
 *
 *=========================================================================*/
CSrShouRecord::CSrShouRecord () 
{
}
/*===========================================================================
 *		End of Class CSrShouRecord Constructor
 *=========================================================================*/


/*===========================================================================
 *
 * Class CSrShouRecord Method - void Destroy (void);
 *
 *=========================================================================*/
void CSrShouRecord::Destroy (void) 
{
	CSrRecord::Destroy();
}
/*===========================================================================
 *		End of Class Method CSrShouRecord::Destroy()
 *=========================================================================*/


/*===========================================================================
 *
 * Class CSrShouRecord Method - void InitializeNew (void);
 *
 *=========================================================================*/
void CSrShouRecord::InitializeNew (void) 
{

	/* Call the base class method first */
	CSrRecord::InitializeNew();


}
/*===========================================================================
 *		End of Class Method CSrShouRecord::InitializeNew()
 *=========================================================================*/


/*===========================================================================
 *
 * Class CSrShouRecord Event - void OnAddSubrecord (pSubrecord);
 *
 *=========================================================================*/
void CSrShouRecord::OnAddSubrecord (CSrSubrecord* pSubrecord) {

	if (pSubrecord->GetRecordType() == SR_NAME_EDID)
	{
		m_pEdidData = SrCastClass(CSrDataSubrecord, pSubrecord);
	}
	else if (pSubrecord->GetRecordType() == SR_NAME_SNAM)
	{
		m_pSnamData = SrCastClass(CSrDataSubrecord, pSubrecord);
	}
	else if (pSubrecord->GetRecordType() == SR_NAME_DESC)
	{
		m_pDescData = SrCastClass(CSrDataSubrecord, pSubrecord);
	}
	else if (pSubrecord->GetRecordType() == SR_NAME_FULL)
	{
		m_pFullData = SrCastClass(CSrDataSubrecord, pSubrecord);
	}
	else if (pSubrecord->GetRecordType() == SR_NAME_MDOB)
	{
		m_pMdobData = SrCastClass(CSrDataSubrecord, pSubrecord);
	}

	else
	{
	CSrRecord::OnAddSubrecord(pSubrecord);
	}

}
/*===========================================================================
 *		End of Class Event CSrShouRecord::OnAddSubRecord()
 *=========================================================================*/


/*===========================================================================
 *
 * Class CSrShouRecord Event - void OnDeleteSubrecord (pSubrecord);
 *
 *=========================================================================*/
void CSrShouRecord::OnDeleteSubrecord (CSrSubrecord* pSubrecord) {

	if (m_pEdidData == pSubrecord)
		m_pEdidData = NULL;
	else if (m_pSnamData == pSubrecord)
		m_pSnamData = NULL;
	else if (m_pDescData == pSubrecord)
		m_pDescData = NULL;
	else if (m_pFullData == pSubrecord)
		m_pFullData = NULL;
	else if (m_pMdobData == pSubrecord)
		m_pMdobData = NULL;

	else
		CSrRecord::OnDeleteSubrecord(pSubrecord);

}
/*===========================================================================
 *		End of Class Event CSrShouRecord::OnDeleteSubrecord()
 *=========================================================================*/


/*===========================================================================
 *
 * Begin CSrShouRecord Get Field Methods
 *
 *=========================================================================*/
/*===========================================================================
 *		End of CSrShouRecord Get Field Methods
 *=========================================================================*/


/*===========================================================================
 *
 * Begin CSrShouRecord Compare Field Methods
 *
 *=========================================================================*/
/*===========================================================================
 *		End of CSrShouRecord Compare Field Methods
 *=========================================================================*/


/*===========================================================================
 *
 * Begin CSrShouRecord Set Field Methods
 *
 *=========================================================================*/
/*===========================================================================
 *		End of CSrShouRecord Set Field Methods
 *=========================================================================*/
