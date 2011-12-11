/*===========================================================================
 *
 * File:		SrOtftRecord.CPP
 * Author:		Dave Humphrey (dave@uesp.net)
 * Created On:	5 December 2011
 *
 * Description
 *
 *=========================================================================*/

	/* Include Files */
#include "srOtftrecord.h"


/*===========================================================================
 *
 * Begin Subrecord Creation Array
 *
 *=========================================================================*/
BEGIN_SRSUBRECCREATE(CSrOtftRecord, CSrRecord)
	DEFINE_SRSUBRECCREATE(SR_NAME_EDID, CSrDataSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_INAM, CSrDataSubrecord::Create)

END_SRSUBRECCREATE()
/*===========================================================================
 *		End of Subrecord Creation Array
 *=========================================================================*/


/*===========================================================================
 *
 * Begin CSrRecord Field Map
 *
 *=========================================================================*/
BEGIN_SRFIELDMAP(CSrOtftRecord, CSrRecord)
END_SRFIELDMAP()
/*===========================================================================
 *		End of CObRecord Field Map
 *=========================================================================*/


/*===========================================================================
 *
 * Class CSrOtftRecord Constructor
 *
 *=========================================================================*/
CSrOtftRecord::CSrOtftRecord () 
{
}
/*===========================================================================
 *		End of Class CSrOtftRecord Constructor
 *=========================================================================*/


/*===========================================================================
 *
 * Class CSrOtftRecord Method - void Destroy (void);
 *
 *=========================================================================*/
void CSrOtftRecord::Destroy (void) 
{
	CSrRecord::Destroy();
}
/*===========================================================================
 *		End of Class Method CSrOtftRecord::Destroy()
 *=========================================================================*/


/*===========================================================================
 *
 * Class CSrOtftRecord Method - void InitializeNew (void);
 *
 *=========================================================================*/
void CSrOtftRecord::InitializeNew (void) 
{

	/* Call the base class method first */
	CSrRecord::InitializeNew();


}
/*===========================================================================
 *		End of Class Method CSrOtftRecord::InitializeNew()
 *=========================================================================*/


/*===========================================================================
 *
 * Class CSrOtftRecord Event - void OnAddSubrecord (pSubrecord);
 *
 *=========================================================================*/
void CSrOtftRecord::OnAddSubrecord (CSrSubrecord* pSubrecord) {

	if (pSubrecord->GetRecordType() == SR_NAME_EDID)
	{
		m_pEdidData = SrCastClass(CSrDataSubrecord, pSubrecord);
	}
	else if (pSubrecord->GetRecordType() == SR_NAME_INAM)
	{
		m_pInamData = SrCastClass(CSrDataSubrecord, pSubrecord);
	}

	else
	{
	CSrRecord::OnAddSubrecord(pSubrecord);
	}

}
/*===========================================================================
 *		End of Class Event CSrOtftRecord::OnAddSubRecord()
 *=========================================================================*/


/*===========================================================================
 *
 * Class CSrOtftRecord Event - void OnDeleteSubrecord (pSubrecord);
 *
 *=========================================================================*/
void CSrOtftRecord::OnDeleteSubrecord (CSrSubrecord* pSubrecord) {

	if (m_pEdidData == pSubrecord)
		m_pEdidData = NULL;
	else if (m_pInamData == pSubrecord)
		m_pInamData = NULL;

	else
		CSrRecord::OnDeleteSubrecord(pSubrecord);

}
/*===========================================================================
 *		End of Class Event CSrOtftRecord::OnDeleteSubrecord()
 *=========================================================================*/


/*===========================================================================
 *
 * Begin CSrOtftRecord Get Field Methods
 *
 *=========================================================================*/
/*===========================================================================
 *		End of CSrOtftRecord Get Field Methods
 *=========================================================================*/


/*===========================================================================
 *
 * Begin CSrOtftRecord Compare Field Methods
 *
 *=========================================================================*/
/*===========================================================================
 *		End of CSrOtftRecord Compare Field Methods
 *=========================================================================*/


/*===========================================================================
 *
 * Begin CSrOtftRecord Set Field Methods
 *
 *=========================================================================*/
/*===========================================================================
 *		End of CSrOtftRecord Set Field Methods
 *=========================================================================*/
