/*===========================================================================
 *
 * File:		SrRfctRecord.CPP
 * Author:		Dave Humphrey (dave@uesp.net)
 * Created On:	5 December 2011
 *
 * Description
 *
 *=========================================================================*/

	/* Include Files */
#include "srRfctrecord.h"


/*===========================================================================
 *
 * Begin Subrecord Creation Array
 *
 *=========================================================================*/
BEGIN_SRSUBRECCREATE(CSrRfctRecord, CSrRecord)
	DEFINE_SRSUBRECCREATE(SR_NAME_EDID, CSrDataSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_DATA, CSrDataSubrecord::Create)

END_SRSUBRECCREATE()
/*===========================================================================
 *		End of Subrecord Creation Array
 *=========================================================================*/


/*===========================================================================
 *
 * Begin CSrRecord Field Map
 *
 *=========================================================================*/
BEGIN_SRFIELDMAP(CSrRfctRecord, CSrRecord)
END_SRFIELDMAP()
/*===========================================================================
 *		End of CObRecord Field Map
 *=========================================================================*/


/*===========================================================================
 *
 * Class CSrRfctRecord Constructor
 *
 *=========================================================================*/
CSrRfctRecord::CSrRfctRecord () 
{
}
/*===========================================================================
 *		End of Class CSrRfctRecord Constructor
 *=========================================================================*/


/*===========================================================================
 *
 * Class CSrRfctRecord Method - void Destroy (void);
 *
 *=========================================================================*/
void CSrRfctRecord::Destroy (void) 
{
	CSrRecord::Destroy();
}
/*===========================================================================
 *		End of Class Method CSrRfctRecord::Destroy()
 *=========================================================================*/


/*===========================================================================
 *
 * Class CSrRfctRecord Method - void InitializeNew (void);
 *
 *=========================================================================*/
void CSrRfctRecord::InitializeNew (void) 
{

	/* Call the base class method first */
	CSrRecord::InitializeNew();


}
/*===========================================================================
 *		End of Class Method CSrRfctRecord::InitializeNew()
 *=========================================================================*/


/*===========================================================================
 *
 * Class CSrRfctRecord Event - void OnAddSubrecord (pSubrecord);
 *
 *=========================================================================*/
void CSrRfctRecord::OnAddSubrecord (CSrSubrecord* pSubrecord) {

	if (pSubrecord->GetRecordType() == SR_NAME_EDID)
	{
		m_pEdidData = SrCastClass(CSrDataSubrecord, pSubrecord);
	}
	else if (pSubrecord->GetRecordType() == SR_NAME_DATA)
	{
		m_pDataData = SrCastClass(CSrDataSubrecord, pSubrecord);
	}

	else
	{
	CSrRecord::OnAddSubrecord(pSubrecord);
	}

}
/*===========================================================================
 *		End of Class Event CSrRfctRecord::OnAddSubRecord()
 *=========================================================================*/


/*===========================================================================
 *
 * Class CSrRfctRecord Event - void OnDeleteSubrecord (pSubrecord);
 *
 *=========================================================================*/
void CSrRfctRecord::OnDeleteSubrecord (CSrSubrecord* pSubrecord) {

	if (m_pEdidData == pSubrecord)
		m_pEdidData = NULL;
	else if (m_pDataData == pSubrecord)
		m_pDataData = NULL;

	else
		CSrRecord::OnDeleteSubrecord(pSubrecord);

}
/*===========================================================================
 *		End of Class Event CSrRfctRecord::OnDeleteSubrecord()
 *=========================================================================*/


/*===========================================================================
 *
 * Begin CSrRfctRecord Get Field Methods
 *
 *=========================================================================*/
/*===========================================================================
 *		End of CSrRfctRecord Get Field Methods
 *=========================================================================*/


/*===========================================================================
 *
 * Begin CSrRfctRecord Compare Field Methods
 *
 *=========================================================================*/
/*===========================================================================
 *		End of CSrRfctRecord Compare Field Methods
 *=========================================================================*/


/*===========================================================================
 *
 * Begin CSrRfctRecord Set Field Methods
 *
 *=========================================================================*/
/*===========================================================================
 *		End of CSrRfctRecord Set Field Methods
 *=========================================================================*/
