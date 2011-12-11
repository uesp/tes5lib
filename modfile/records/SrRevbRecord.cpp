/*===========================================================================
 *
 * File:		SrRevbRecord.CPP
 * Author:		Dave Humphrey (dave@uesp.net)
 * Created On:	5 December 2011
 *
 * Description
 *
 *=========================================================================*/

	/* Include Files */
#include "srRevbrecord.h"


/*===========================================================================
 *
 * Begin Subrecord Creation Array
 *
 *=========================================================================*/
BEGIN_SRSUBRECCREATE(CSrRevbRecord, CSrRecord)
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
BEGIN_SRFIELDMAP(CSrRevbRecord, CSrRecord)
END_SRFIELDMAP()
/*===========================================================================
 *		End of CObRecord Field Map
 *=========================================================================*/


/*===========================================================================
 *
 * Class CSrRevbRecord Constructor
 *
 *=========================================================================*/
CSrRevbRecord::CSrRevbRecord () 
{
}
/*===========================================================================
 *		End of Class CSrRevbRecord Constructor
 *=========================================================================*/


/*===========================================================================
 *
 * Class CSrRevbRecord Method - void Destroy (void);
 *
 *=========================================================================*/
void CSrRevbRecord::Destroy (void) 
{
	CSrRecord::Destroy();
}
/*===========================================================================
 *		End of Class Method CSrRevbRecord::Destroy()
 *=========================================================================*/


/*===========================================================================
 *
 * Class CSrRevbRecord Method - void InitializeNew (void);
 *
 *=========================================================================*/
void CSrRevbRecord::InitializeNew (void) 
{

	/* Call the base class method first */
	CSrRecord::InitializeNew();


}
/*===========================================================================
 *		End of Class Method CSrRevbRecord::InitializeNew()
 *=========================================================================*/


/*===========================================================================
 *
 * Class CSrRevbRecord Event - void OnAddSubrecord (pSubrecord);
 *
 *=========================================================================*/
void CSrRevbRecord::OnAddSubrecord (CSrSubrecord* pSubrecord) {

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
 *		End of Class Event CSrRevbRecord::OnAddSubRecord()
 *=========================================================================*/


/*===========================================================================
 *
 * Class CSrRevbRecord Event - void OnDeleteSubrecord (pSubrecord);
 *
 *=========================================================================*/
void CSrRevbRecord::OnDeleteSubrecord (CSrSubrecord* pSubrecord) {

	if (m_pEdidData == pSubrecord)
		m_pEdidData = NULL;
	else if (m_pDataData == pSubrecord)
		m_pDataData = NULL;

	else
		CSrRecord::OnDeleteSubrecord(pSubrecord);

}
/*===========================================================================
 *		End of Class Event CSrRevbRecord::OnDeleteSubrecord()
 *=========================================================================*/


/*===========================================================================
 *
 * Begin CSrRevbRecord Get Field Methods
 *
 *=========================================================================*/
/*===========================================================================
 *		End of CSrRevbRecord Get Field Methods
 *=========================================================================*/


/*===========================================================================
 *
 * Begin CSrRevbRecord Compare Field Methods
 *
 *=========================================================================*/
/*===========================================================================
 *		End of CSrRevbRecord Compare Field Methods
 *=========================================================================*/


/*===========================================================================
 *
 * Begin CSrRevbRecord Set Field Methods
 *
 *=========================================================================*/
/*===========================================================================
 *		End of CSrRevbRecord Set Field Methods
 *=========================================================================*/
