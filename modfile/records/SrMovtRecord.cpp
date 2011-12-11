/*===========================================================================
 *
 * File:		SrMovtRecord.CPP
 * Author:		Dave Humphrey (dave@uesp.net)
 * Created On:	5 December 2011
 *
 * Description
 *
 *=========================================================================*/

	/* Include Files */
#include "srMovtrecord.h"


/*===========================================================================
 *
 * Begin Subrecord Creation Array
 *
 *=========================================================================*/
BEGIN_SRSUBRECCREATE(CSrMovtRecord, CSrRecord)
	DEFINE_SRSUBRECCREATE(SR_NAME_SPED, CSrDataSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_EDID, CSrDataSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_MNAM, CSrDataSubrecord::Create)
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
BEGIN_SRFIELDMAP(CSrMovtRecord, CSrRecord)
END_SRFIELDMAP()
/*===========================================================================
 *		End of CObRecord Field Map
 *=========================================================================*/


/*===========================================================================
 *
 * Class CSrMovtRecord Constructor
 *
 *=========================================================================*/
CSrMovtRecord::CSrMovtRecord () 
{
}
/*===========================================================================
 *		End of Class CSrMovtRecord Constructor
 *=========================================================================*/


/*===========================================================================
 *
 * Class CSrMovtRecord Method - void Destroy (void);
 *
 *=========================================================================*/
void CSrMovtRecord::Destroy (void) 
{
	CSrRecord::Destroy();
}
/*===========================================================================
 *		End of Class Method CSrMovtRecord::Destroy()
 *=========================================================================*/


/*===========================================================================
 *
 * Class CSrMovtRecord Method - void InitializeNew (void);
 *
 *=========================================================================*/
void CSrMovtRecord::InitializeNew (void) 
{

	/* Call the base class method first */
	CSrRecord::InitializeNew();


}
/*===========================================================================
 *		End of Class Method CSrMovtRecord::InitializeNew()
 *=========================================================================*/


/*===========================================================================
 *
 * Class CSrMovtRecord Event - void OnAddSubrecord (pSubrecord);
 *
 *=========================================================================*/
void CSrMovtRecord::OnAddSubrecord (CSrSubrecord* pSubrecord) {

	if (pSubrecord->GetRecordType() == SR_NAME_SPED)
	{
		m_pSpedData = SrCastClass(CSrDataSubrecord, pSubrecord);
	}
	else if (pSubrecord->GetRecordType() == SR_NAME_EDID)
	{
		m_pEdidData = SrCastClass(CSrDataSubrecord, pSubrecord);
	}
	else if (pSubrecord->GetRecordType() == SR_NAME_MNAM)
	{
		m_pMnamData = SrCastClass(CSrDataSubrecord, pSubrecord);
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
 *		End of Class Event CSrMovtRecord::OnAddSubRecord()
 *=========================================================================*/


/*===========================================================================
 *
 * Class CSrMovtRecord Event - void OnDeleteSubrecord (pSubrecord);
 *
 *=========================================================================*/
void CSrMovtRecord::OnDeleteSubrecord (CSrSubrecord* pSubrecord) {

	if (m_pSpedData == pSubrecord)
		m_pSpedData = NULL;
	else if (m_pEdidData == pSubrecord)
		m_pEdidData = NULL;
	else if (m_pMnamData == pSubrecord)
		m_pMnamData = NULL;
	else if (m_pInamData == pSubrecord)
		m_pInamData = NULL;

	else
		CSrRecord::OnDeleteSubrecord(pSubrecord);

}
/*===========================================================================
 *		End of Class Event CSrMovtRecord::OnDeleteSubrecord()
 *=========================================================================*/


/*===========================================================================
 *
 * Begin CSrMovtRecord Get Field Methods
 *
 *=========================================================================*/
/*===========================================================================
 *		End of CSrMovtRecord Get Field Methods
 *=========================================================================*/


/*===========================================================================
 *
 * Begin CSrMovtRecord Compare Field Methods
 *
 *=========================================================================*/
/*===========================================================================
 *		End of CSrMovtRecord Compare Field Methods
 *=========================================================================*/


/*===========================================================================
 *
 * Begin CSrMovtRecord Set Field Methods
 *
 *=========================================================================*/
/*===========================================================================
 *		End of CSrMovtRecord Set Field Methods
 *=========================================================================*/
