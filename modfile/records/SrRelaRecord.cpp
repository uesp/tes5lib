/*===========================================================================
 *
 * File:		SrRelaRecord.CPP
 * Author:		Dave Humphrey (dave@uesp.net)
 * Created On:	5 December 2011
 *
 * Description
 *
 *=========================================================================*/

	/* Include Files */
#include "srRelarecord.h"


/*===========================================================================
 *
 * Begin Subrecord Creation Array
 *
 *=========================================================================*/
BEGIN_SRSUBRECCREATE(CSrRelaRecord, CSrRecord)
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
BEGIN_SRFIELDMAP(CSrRelaRecord, CSrRecord)
END_SRFIELDMAP()
/*===========================================================================
 *		End of CObRecord Field Map
 *=========================================================================*/


/*===========================================================================
 *
 * Class CSrRelaRecord Constructor
 *
 *=========================================================================*/
CSrRelaRecord::CSrRelaRecord () 
{
}
/*===========================================================================
 *		End of Class CSrRelaRecord Constructor
 *=========================================================================*/


/*===========================================================================
 *
 * Class CSrRelaRecord Method - void Destroy (void);
 *
 *=========================================================================*/
void CSrRelaRecord::Destroy (void) 
{
	CSrRecord::Destroy();
}
/*===========================================================================
 *		End of Class Method CSrRelaRecord::Destroy()
 *=========================================================================*/


/*===========================================================================
 *
 * Class CSrRelaRecord Method - void InitializeNew (void);
 *
 *=========================================================================*/
void CSrRelaRecord::InitializeNew (void) 
{

	/* Call the base class method first */
	CSrRecord::InitializeNew();


}
/*===========================================================================
 *		End of Class Method CSrRelaRecord::InitializeNew()
 *=========================================================================*/


/*===========================================================================
 *
 * Class CSrRelaRecord Event - void OnAddSubrecord (pSubrecord);
 *
 *=========================================================================*/
void CSrRelaRecord::OnAddSubrecord (CSrSubrecord* pSubrecord) {

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
 *		End of Class Event CSrRelaRecord::OnAddSubRecord()
 *=========================================================================*/


/*===========================================================================
 *
 * Class CSrRelaRecord Event - void OnDeleteSubrecord (pSubrecord);
 *
 *=========================================================================*/
void CSrRelaRecord::OnDeleteSubrecord (CSrSubrecord* pSubrecord) {

	if (m_pEdidData == pSubrecord)
		m_pEdidData = NULL;
	else if (m_pDataData == pSubrecord)
		m_pDataData = NULL;

	else
		CSrRecord::OnDeleteSubrecord(pSubrecord);

}
/*===========================================================================
 *		End of Class Event CSrRelaRecord::OnDeleteSubrecord()
 *=========================================================================*/


/*===========================================================================
 *
 * Begin CSrRelaRecord Get Field Methods
 *
 *=========================================================================*/
/*===========================================================================
 *		End of CSrRelaRecord Get Field Methods
 *=========================================================================*/


/*===========================================================================
 *
 * Begin CSrRelaRecord Compare Field Methods
 *
 *=========================================================================*/
/*===========================================================================
 *		End of CSrRelaRecord Compare Field Methods
 *=========================================================================*/


/*===========================================================================
 *
 * Begin CSrRelaRecord Set Field Methods
 *
 *=========================================================================*/
/*===========================================================================
 *		End of CSrRelaRecord Set Field Methods
 *=========================================================================*/
