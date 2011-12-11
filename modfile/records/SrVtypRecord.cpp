/*===========================================================================
 *
 * File:		SrVtypRecord.CPP
 * Author:		Dave Humphrey (dave@uesp.net)
 * Created On:	5 December 2011
 *
 * Description
 *
 *=========================================================================*/

	/* Include Files */
#include "srVtyprecord.h"


/*===========================================================================
 *
 * Begin Subrecord Creation Array
 *
 *=========================================================================*/
BEGIN_SRSUBRECCREATE(CSrVtypRecord, CSrRecord)
	DEFINE_SRSUBRECCREATE(SR_NAME_EDID, CSrDataSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_DNAM, CSrDataSubrecord::Create)

END_SRSUBRECCREATE()
/*===========================================================================
 *		End of Subrecord Creation Array
 *=========================================================================*/


/*===========================================================================
 *
 * Begin CSrRecord Field Map
 *
 *=========================================================================*/
BEGIN_SRFIELDMAP(CSrVtypRecord, CSrRecord)
END_SRFIELDMAP()
/*===========================================================================
 *		End of CObRecord Field Map
 *=========================================================================*/


/*===========================================================================
 *
 * Class CSrVtypRecord Constructor
 *
 *=========================================================================*/
CSrVtypRecord::CSrVtypRecord () 
{
}
/*===========================================================================
 *		End of Class CSrVtypRecord Constructor
 *=========================================================================*/


/*===========================================================================
 *
 * Class CSrVtypRecord Method - void Destroy (void);
 *
 *=========================================================================*/
void CSrVtypRecord::Destroy (void) 
{
	CSrRecord::Destroy();
}
/*===========================================================================
 *		End of Class Method CSrVtypRecord::Destroy()
 *=========================================================================*/


/*===========================================================================
 *
 * Class CSrVtypRecord Method - void InitializeNew (void);
 *
 *=========================================================================*/
void CSrVtypRecord::InitializeNew (void) 
{

	/* Call the base class method first */
	CSrRecord::InitializeNew();


}
/*===========================================================================
 *		End of Class Method CSrVtypRecord::InitializeNew()
 *=========================================================================*/


/*===========================================================================
 *
 * Class CSrVtypRecord Event - void OnAddSubrecord (pSubrecord);
 *
 *=========================================================================*/
void CSrVtypRecord::OnAddSubrecord (CSrSubrecord* pSubrecord) {

	if (pSubrecord->GetRecordType() == SR_NAME_EDID)
	{
		m_pEdidData = SrCastClass(CSrDataSubrecord, pSubrecord);
	}
	else if (pSubrecord->GetRecordType() == SR_NAME_DNAM)
	{
		m_pDnamData = SrCastClass(CSrDataSubrecord, pSubrecord);
	}

	else
	{
	CSrRecord::OnAddSubrecord(pSubrecord);
	}

}
/*===========================================================================
 *		End of Class Event CSrVtypRecord::OnAddSubRecord()
 *=========================================================================*/


/*===========================================================================
 *
 * Class CSrVtypRecord Event - void OnDeleteSubrecord (pSubrecord);
 *
 *=========================================================================*/
void CSrVtypRecord::OnDeleteSubrecord (CSrSubrecord* pSubrecord) {

	if (m_pEdidData == pSubrecord)
		m_pEdidData = NULL;
	else if (m_pDnamData == pSubrecord)
		m_pDnamData = NULL;

	else
		CSrRecord::OnDeleteSubrecord(pSubrecord);

}
/*===========================================================================
 *		End of Class Event CSrVtypRecord::OnDeleteSubrecord()
 *=========================================================================*/


/*===========================================================================
 *
 * Begin CSrVtypRecord Get Field Methods
 *
 *=========================================================================*/
/*===========================================================================
 *		End of CSrVtypRecord Get Field Methods
 *=========================================================================*/


/*===========================================================================
 *
 * Begin CSrVtypRecord Compare Field Methods
 *
 *=========================================================================*/
/*===========================================================================
 *		End of CSrVtypRecord Compare Field Methods
 *=========================================================================*/


/*===========================================================================
 *
 * Begin CSrVtypRecord Set Field Methods
 *
 *=========================================================================*/
/*===========================================================================
 *		End of CSrVtypRecord Set Field Methods
 *=========================================================================*/
