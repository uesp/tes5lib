/*===========================================================================
 *
 * File:		SrSnctRecord.CPP
 * Author:		Dave Humphrey (dave@uesp.net)
 * Created On:	5 December 2011
 *
 * Description
 *
 *=========================================================================*/

	/* Include Files */
#include "srSnctrecord.h"


/*===========================================================================
 *
 * Begin Subrecord Creation Array
 *
 *=========================================================================*/
BEGIN_SRSUBRECCREATE(CSrSnctRecord, CSrIdRecord)
	DEFINE_SRSUBRECCREATE(SR_NAME_VNAM, CSrDataSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_FNAM, CSrDataSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_FULL, CSrDataSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_PNAM, CSrDataSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_UNAM, CSrDataSubrecord::Create)
END_SRSUBRECCREATE()
/*===========================================================================
 *		End of Subrecord Creation Array
 *=========================================================================*/


/*===========================================================================
 *
 * Begin CSrIdRecord Field Map
 *
 *=========================================================================*/
BEGIN_SRFIELDMAP(CSrSnctRecord, CSrIdRecord)
END_SRFIELDMAP()
/*===========================================================================
 *		End of CObRecord Field Map
 *=========================================================================*/


/*===========================================================================
 *
 * Class CSrSnctRecord Constructor
 *
 *=========================================================================*/
CSrSnctRecord::CSrSnctRecord () 
{
}
/*===========================================================================
 *		End of Class CSrSnctRecord Constructor
 *=========================================================================*/


/*===========================================================================
 *
 * Class CSrSnctRecord Method - void Destroy (void);
 *
 *=========================================================================*/
void CSrSnctRecord::Destroy (void) 
{
	CSrIdRecord::Destroy();
}
/*===========================================================================
 *		End of Class Method CSrSnctRecord::Destroy()
 *=========================================================================*/


/*===========================================================================
 *
 * Class CSrSnctRecord Method - void InitializeNew (void);
 *
 *=========================================================================*/
void CSrSnctRecord::InitializeNew (void) 
{

	/* Call the base class method first */
	CSrIdRecord::InitializeNew();


}
/*===========================================================================
 *		End of Class Method CSrSnctRecord::InitializeNew()
 *=========================================================================*/


/*===========================================================================
 *
 * Class CSrSnctRecord Event - void OnAddSubrecord (pSubrecord);
 *
 *=========================================================================*/
void CSrSnctRecord::OnAddSubrecord (CSrSubrecord* pSubrecord) {

	if (pSubrecord->GetRecordType() == SR_NAME_VNAM)
	{
		m_pVnamData = SrCastClass(CSrDataSubrecord, pSubrecord);
	}
	else if (pSubrecord->GetRecordType() == SR_NAME_FNAM)
	{
		m_pFnamData = SrCastClass(CSrDataSubrecord, pSubrecord);
	}
	else if (pSubrecord->GetRecordType() == SR_NAME_FULL)
	{
		m_pFullData = SrCastClass(CSrDataSubrecord, pSubrecord);
	}
	else if (pSubrecord->GetRecordType() == SR_NAME_PNAM)
	{
		m_pPnamData = SrCastClass(CSrDataSubrecord, pSubrecord);
	}
	else if (pSubrecord->GetRecordType() == SR_NAME_UNAM)
	{
		m_pUnamData = SrCastClass(CSrDataSubrecord, pSubrecord);
	}

	else
	{
	CSrIdRecord::OnAddSubrecord(pSubrecord);
	}

}
/*===========================================================================
 *		End of Class Event CSrSnctRecord::OnAddSubRecord()
 *=========================================================================*/


/*===========================================================================
 *
 * Class CSrSnctRecord Event - void OnDeleteSubrecord (pSubrecord);
 *
 *=========================================================================*/
void CSrSnctRecord::OnDeleteSubrecord (CSrSubrecord* pSubrecord) {

	if (m_pVnamData == pSubrecord)
		m_pVnamData = NULL;
	else if (m_pFnamData == pSubrecord)
		m_pFnamData = NULL;
	else if (m_pFullData == pSubrecord)
		m_pFullData = NULL;
	else if (m_pPnamData == pSubrecord)
		m_pPnamData = NULL;
	else if (m_pUnamData == pSubrecord)
		m_pUnamData = NULL;

	else
		CSrIdRecord::OnDeleteSubrecord(pSubrecord);

}
/*===========================================================================
 *		End of Class Event CSrSnctRecord::OnDeleteSubrecord()
 *=========================================================================*/


/*===========================================================================
 *
 * Begin CSrSnctRecord Get Field Methods
 *
 *=========================================================================*/
/*===========================================================================
 *		End of CSrSnctRecord Get Field Methods
 *=========================================================================*/


/*===========================================================================
 *
 * Begin CSrSnctRecord Compare Field Methods
 *
 *=========================================================================*/
/*===========================================================================
 *		End of CSrSnctRecord Compare Field Methods
 *=========================================================================*/


/*===========================================================================
 *
 * Begin CSrSnctRecord Set Field Methods
 *
 *=========================================================================*/
/*===========================================================================
 *		End of CSrSnctRecord Set Field Methods
 *=========================================================================*/
