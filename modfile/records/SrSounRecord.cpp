/*===========================================================================
 *
 * File:		SrSounRecord.CPP
 * Author:		Dave Humphrey (dave@uesp.net)
 * Created On:	5 December 2011
 *
 * Description
 *
 *=========================================================================*/

	/* Include Files */
#include "srSounrecord.h"


/*===========================================================================
 *
 * Begin Subrecord Creation Array
 *
 *=========================================================================*/
BEGIN_SRSUBRECCREATE(CSrSounRecord, CSrIdRecord)
	DEFINE_SRSUBRECCREATE(SR_NAME_FNAM, CSrDataSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_SDSC, CSrDataSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_SNDD, CSrDataSubrecord::Create)
END_SRSUBRECCREATE()
/*===========================================================================
 *		End of Subrecord Creation Array
 *=========================================================================*/


/*===========================================================================
 *
 * Begin CSrIdRecord Field Map
 *
 *=========================================================================*/
BEGIN_SRFIELDMAP(CSrSounRecord, CSrIdRecord)
END_SRFIELDMAP()
/*===========================================================================
 *		End of CObRecord Field Map
 *=========================================================================*/


/*===========================================================================
 *
 * Class CSrSounRecord Constructor
 *
 *=========================================================================*/
CSrSounRecord::CSrSounRecord () 
{
}
/*===========================================================================
 *		End of Class CSrSounRecord Constructor
 *=========================================================================*/


/*===========================================================================
 *
 * Class CSrSounRecord Method - void Destroy (void);
 *
 *=========================================================================*/
void CSrSounRecord::Destroy (void) 
{
	CSrIdRecord::Destroy();
}
/*===========================================================================
 *		End of Class Method CSrSounRecord::Destroy()
 *=========================================================================*/


/*===========================================================================
 *
 * Class CSrSounRecord Method - void InitializeNew (void);
 *
 *=========================================================================*/
void CSrSounRecord::InitializeNew (void) 
{
	CSrIdRecord::InitializeNew();
}
/*===========================================================================
 *		End of Class Method CSrSounRecord::InitializeNew()
 *=========================================================================*/


/*===========================================================================
 *
 * Class CSrSounRecord Event - void OnAddSubrecord (pSubrecord);
 *
 *=========================================================================*/
void CSrSounRecord::OnAddSubrecord (CSrSubrecord* pSubrecord) {

	if (pSubrecord->GetRecordType() == SR_NAME_FNAM)
	{
		m_pFnamData = SrCastClass(CSrDataSubrecord, pSubrecord);
	}
	else if (pSubrecord->GetRecordType() == SR_NAME_SDSC)
	{
		m_pSdscData = SrCastClass(CSrDataSubrecord, pSubrecord);
	}
	else if (pSubrecord->GetRecordType() == SR_NAME_SNDD)
	{
		m_pSnddData = SrCastClass(CSrDataSubrecord, pSubrecord);
	}
	else
	{
		CSrIdRecord::OnAddSubrecord(pSubrecord);
	}

}
/*===========================================================================
 *		End of Class Event CSrSounRecord::OnAddSubRecord()
 *=========================================================================*/


/*===========================================================================
 *
 * Class CSrSounRecord Event - void OnDeleteSubrecord (pSubrecord);
 *
 *=========================================================================*/
void CSrSounRecord::OnDeleteSubrecord (CSrSubrecord* pSubrecord) {

	if (m_pFnamData == pSubrecord)
		m_pFnamData = NULL;
	else if (m_pSdscData == pSubrecord)
		m_pSdscData = NULL;
	else if (m_pSnddData == pSubrecord)
		m_pSnddData = NULL;
	else
		CSrIdRecord::OnDeleteSubrecord(pSubrecord);

}
/*===========================================================================
 *		End of Class Event CSrSounRecord::OnDeleteSubrecord()
 *=========================================================================*/


/*===========================================================================
 *
 * Begin CSrSounRecord Get Field Methods
 *
 *=========================================================================*/
/*===========================================================================
 *		End of CSrSounRecord Get Field Methods
 *=========================================================================*/


/*===========================================================================
 *
 * Begin CSrSounRecord Compare Field Methods
 *
 *=========================================================================*/
/*===========================================================================
 *		End of CSrSounRecord Compare Field Methods
 *=========================================================================*/


/*===========================================================================
 *
 * Begin CSrSounRecord Set Field Methods
 *
 *=========================================================================*/
/*===========================================================================
 *		End of CSrSounRecord Set Field Methods
 *=========================================================================*/
