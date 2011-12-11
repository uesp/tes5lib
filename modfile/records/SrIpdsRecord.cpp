/*===========================================================================
 *
 * File:		SrIpdsRecord.CPP
 * Author:		Dave Humphrey (dave@uesp.net)
 * Created On:	5 December 2011
 *
 * Description
 *
 *=========================================================================*/

	/* Include Files */
#include "srIpdsrecord.h"


/*===========================================================================
 *
 * Begin Subrecord Creation Array
 *
 *=========================================================================*/
BEGIN_SRSUBRECCREATE(CSrIpdsRecord, CSrRecord)
	DEFINE_SRSUBRECCREATE(SR_NAME_EDID, CSrDataSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_PNAM, CSrDataSubrecord::Create)

END_SRSUBRECCREATE()
/*===========================================================================
 *		End of Subrecord Creation Array
 *=========================================================================*/


/*===========================================================================
 *
 * Begin CSrRecord Field Map
 *
 *=========================================================================*/
BEGIN_SRFIELDMAP(CSrIpdsRecord, CSrRecord)
END_SRFIELDMAP()
/*===========================================================================
 *		End of CObRecord Field Map
 *=========================================================================*/


/*===========================================================================
 *
 * Class CSrIpdsRecord Constructor
 *
 *=========================================================================*/
CSrIpdsRecord::CSrIpdsRecord () 
{
}
/*===========================================================================
 *		End of Class CSrIpdsRecord Constructor
 *=========================================================================*/


/*===========================================================================
 *
 * Class CSrIpdsRecord Method - void Destroy (void);
 *
 *=========================================================================*/
void CSrIpdsRecord::Destroy (void) 
{
	CSrRecord::Destroy();
}
/*===========================================================================
 *		End of Class Method CSrIpdsRecord::Destroy()
 *=========================================================================*/


/*===========================================================================
 *
 * Class CSrIpdsRecord Method - void InitializeNew (void);
 *
 *=========================================================================*/
void CSrIpdsRecord::InitializeNew (void) 
{

	/* Call the base class method first */
	CSrRecord::InitializeNew();


}
/*===========================================================================
 *		End of Class Method CSrIpdsRecord::InitializeNew()
 *=========================================================================*/


/*===========================================================================
 *
 * Class CSrIpdsRecord Event - void OnAddSubrecord (pSubrecord);
 *
 *=========================================================================*/
void CSrIpdsRecord::OnAddSubrecord (CSrSubrecord* pSubrecord) {

	if (pSubrecord->GetRecordType() == SR_NAME_EDID)
	{
		m_pEdidData = SrCastClass(CSrDataSubrecord, pSubrecord);
	}
	else if (pSubrecord->GetRecordType() == SR_NAME_PNAM)
	{
		m_pPnamData = SrCastClass(CSrDataSubrecord, pSubrecord);
	}

	else
	{
	CSrRecord::OnAddSubrecord(pSubrecord);
	}

}
/*===========================================================================
 *		End of Class Event CSrIpdsRecord::OnAddSubRecord()
 *=========================================================================*/


/*===========================================================================
 *
 * Class CSrIpdsRecord Event - void OnDeleteSubrecord (pSubrecord);
 *
 *=========================================================================*/
void CSrIpdsRecord::OnDeleteSubrecord (CSrSubrecord* pSubrecord) {

	if (m_pEdidData == pSubrecord)
		m_pEdidData = NULL;
	else if (m_pPnamData == pSubrecord)
		m_pPnamData = NULL;

	else
		CSrRecord::OnDeleteSubrecord(pSubrecord);

}
/*===========================================================================
 *		End of Class Event CSrIpdsRecord::OnDeleteSubrecord()
 *=========================================================================*/


/*===========================================================================
 *
 * Begin CSrIpdsRecord Get Field Methods
 *
 *=========================================================================*/
/*===========================================================================
 *		End of CSrIpdsRecord Get Field Methods
 *=========================================================================*/


/*===========================================================================
 *
 * Begin CSrIpdsRecord Compare Field Methods
 *
 *=========================================================================*/
/*===========================================================================
 *		End of CSrIpdsRecord Compare Field Methods
 *=========================================================================*/


/*===========================================================================
 *
 * Begin CSrIpdsRecord Set Field Methods
 *
 *=========================================================================*/
/*===========================================================================
 *		End of CSrIpdsRecord Set Field Methods
 *=========================================================================*/
