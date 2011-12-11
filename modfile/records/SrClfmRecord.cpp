/*===========================================================================
 *
 * File:		SrClfmRecord.CPP
 * Author:		Dave Humphrey (dave@uesp.net)
 * Created On:	5 December 2011
 *
 * Description
 *
 *=========================================================================*/

	/* Include Files */
#include "srClfmrecord.h"


/*===========================================================================
 *
 * Begin Subrecord Creation Array
 *
 *=========================================================================*/
BEGIN_SRSUBRECCREATE(CSrClfmRecord, CSrIdRecord)
	DEFINE_SRSUBRECCREATE(SR_NAME_FNAM, CSrDataSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_CNAM, CSrDataSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_FULL, CSrDataSubrecord::Create)
END_SRSUBRECCREATE()
/*===========================================================================
 *		End of Subrecord Creation Array
 *=========================================================================*/


/*===========================================================================
 *
 * Begin CSrRecord Field Map
 *
 *=========================================================================*/
BEGIN_SRFIELDMAP(CSrClfmRecord, CSrIdRecord)
END_SRFIELDMAP()
/*===========================================================================
 *		End of CObRecord Field Map
 *=========================================================================*/


/*===========================================================================
 *
 * Class CSrClfmRecord Constructor
 *
 *=========================================================================*/
CSrClfmRecord::CSrClfmRecord () 
{
}
/*===========================================================================
 *		End of Class CSrClfmRecord Constructor
 *=========================================================================*/


/*===========================================================================
 *
 * Class CSrClfmRecord Method - void Destroy (void);
 *
 *=========================================================================*/
void CSrClfmRecord::Destroy (void) 
{
	CSrIdRecord::Destroy();
}
/*===========================================================================
 *		End of Class Method CSrClfmRecord::Destroy()
 *=========================================================================*/


/*===========================================================================
 *
 * Class CSrClfmRecord Method - void InitializeNew (void);
 *
 *=========================================================================*/
void CSrClfmRecord::InitializeNew (void) 
{
	CSrIdRecord::InitializeNew();
}
/*===========================================================================
 *		End of Class Method CSrClfmRecord::InitializeNew()
 *=========================================================================*/


/*===========================================================================
 *
 * Class CSrClfmRecord Event - void OnAddSubrecord (pSubrecord);
 *
 *=========================================================================*/
void CSrClfmRecord::OnAddSubrecord (CSrSubrecord* pSubrecord) {

	if (pSubrecord->GetRecordType() == SR_NAME_FNAM)
	{
		m_pFnamData = SrCastClass(CSrDataSubrecord, pSubrecord);
	}
	else if (pSubrecord->GetRecordType() == SR_NAME_CNAM)
	{
		m_pCnamData = SrCastClass(CSrDataSubrecord, pSubrecord);
	}
	else if (pSubrecord->GetRecordType() == SR_NAME_FULL)
	{
		m_pFullData = SrCastClass(CSrDataSubrecord, pSubrecord);
	}
	else
	{
		CSrIdRecord::OnAddSubrecord(pSubrecord);
	}

}
/*===========================================================================
 *		End of Class Event CSrClfmRecord::OnAddSubRecord()
 *=========================================================================*/


/*===========================================================================
 *
 * Class CSrClfmRecord Event - void OnDeleteSubrecord (pSubrecord);
 *
 *=========================================================================*/
void CSrClfmRecord::OnDeleteSubrecord (CSrSubrecord* pSubrecord) {

	if (m_pFnamData == pSubrecord)
		m_pFnamData = NULL;
	else if (m_pCnamData == pSubrecord)
		m_pCnamData = NULL;
	else if (m_pFullData == pSubrecord)
		m_pFullData = NULL;
	else
		CSrIdRecord::OnDeleteSubrecord(pSubrecord);

}
/*===========================================================================
 *		End of Class Event CSrClfmRecord::OnDeleteSubrecord()
 *=========================================================================*/


/*===========================================================================
 *
 * Begin CSrClfmRecord Get Field Methods
 *
 *=========================================================================*/
/*===========================================================================
 *		End of CSrClfmRecord Get Field Methods
 *=========================================================================*/


/*===========================================================================
 *
 * Begin CSrClfmRecord Compare Field Methods
 *
 *=========================================================================*/
/*===========================================================================
 *		End of CSrClfmRecord Compare Field Methods
 *=========================================================================*/


/*===========================================================================
 *
 * Begin CSrClfmRecord Set Field Methods
 *
 *=========================================================================*/
/*===========================================================================
 *		End of CSrClfmRecord Set Field Methods
 *=========================================================================*/
