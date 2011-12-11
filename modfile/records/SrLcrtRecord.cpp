/*===========================================================================
 *
 * File:		SrLcrtRecord.CPP
 * Author:		Dave Humphrey (dave@uesp.net)
 * Created On:	5 December 2011
 *
 * Description
 *
 *=========================================================================*/

	/* Include Files */
#include "srLcrtrecord.h"


/*===========================================================================
 *
 * Begin Subrecord Creation Array
 *
 *=========================================================================*/
BEGIN_SRSUBRECCREATE(CSrLcrtRecord, CSrRecord)
	DEFINE_SRSUBRECCREATE(SR_NAME_EDID, CSrDataSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_CNAM, CSrDataSubrecord::Create)

END_SRSUBRECCREATE()
/*===========================================================================
 *		End of Subrecord Creation Array
 *=========================================================================*/


/*===========================================================================
 *
 * Begin CSrRecord Field Map
 *
 *=========================================================================*/
BEGIN_SRFIELDMAP(CSrLcrtRecord, CSrRecord)
END_SRFIELDMAP()
/*===========================================================================
 *		End of CObRecord Field Map
 *=========================================================================*/


/*===========================================================================
 *
 * Class CSrLcrtRecord Constructor
 *
 *=========================================================================*/
CSrLcrtRecord::CSrLcrtRecord () 
{
}
/*===========================================================================
 *		End of Class CSrLcrtRecord Constructor
 *=========================================================================*/


/*===========================================================================
 *
 * Class CSrLcrtRecord Method - void Destroy (void);
 *
 *=========================================================================*/
void CSrLcrtRecord::Destroy (void) 
{
	CSrRecord::Destroy();
}
/*===========================================================================
 *		End of Class Method CSrLcrtRecord::Destroy()
 *=========================================================================*/


/*===========================================================================
 *
 * Class CSrLcrtRecord Method - void InitializeNew (void);
 *
 *=========================================================================*/
void CSrLcrtRecord::InitializeNew (void) 
{

	/* Call the base class method first */
	CSrRecord::InitializeNew();


}
/*===========================================================================
 *		End of Class Method CSrLcrtRecord::InitializeNew()
 *=========================================================================*/


/*===========================================================================
 *
 * Class CSrLcrtRecord Event - void OnAddSubrecord (pSubrecord);
 *
 *=========================================================================*/
void CSrLcrtRecord::OnAddSubrecord (CSrSubrecord* pSubrecord) {

	if (pSubrecord->GetRecordType() == SR_NAME_EDID)
	{
		m_pEdidData = SrCastClass(CSrDataSubrecord, pSubrecord);
	}
	else if (pSubrecord->GetRecordType() == SR_NAME_CNAM)
	{
		m_pCnamData = SrCastClass(CSrDataSubrecord, pSubrecord);
	}

	else
	{
	CSrRecord::OnAddSubrecord(pSubrecord);
	}

}
/*===========================================================================
 *		End of Class Event CSrLcrtRecord::OnAddSubRecord()
 *=========================================================================*/


/*===========================================================================
 *
 * Class CSrLcrtRecord Event - void OnDeleteSubrecord (pSubrecord);
 *
 *=========================================================================*/
void CSrLcrtRecord::OnDeleteSubrecord (CSrSubrecord* pSubrecord) {

	if (m_pEdidData == pSubrecord)
		m_pEdidData = NULL;
	else if (m_pCnamData == pSubrecord)
		m_pCnamData = NULL;

	else
		CSrRecord::OnDeleteSubrecord(pSubrecord);

}
/*===========================================================================
 *		End of Class Event CSrLcrtRecord::OnDeleteSubrecord()
 *=========================================================================*/


/*===========================================================================
 *
 * Begin CSrLcrtRecord Get Field Methods
 *
 *=========================================================================*/
/*===========================================================================
 *		End of CSrLcrtRecord Get Field Methods
 *=========================================================================*/


/*===========================================================================
 *
 * Begin CSrLcrtRecord Compare Field Methods
 *
 *=========================================================================*/
/*===========================================================================
 *		End of CSrLcrtRecord Compare Field Methods
 *=========================================================================*/


/*===========================================================================
 *
 * Begin CSrLcrtRecord Set Field Methods
 *
 *=========================================================================*/
/*===========================================================================
 *		End of CSrLcrtRecord Set Field Methods
 *=========================================================================*/
