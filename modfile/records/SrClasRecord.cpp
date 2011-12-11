/*===========================================================================
 *
 * File:		SrClasRecord.CPP
 * Author:		Dave Humphrey (dave@uesp.net)
 * Created On:	5 December 2011
 *
 * Description
 *
 *=========================================================================*/

	/* Include Files */
#include "srClasrecord.h"


/*===========================================================================
 *
 * Begin Subrecord Creation Array
 *
 *=========================================================================*/
BEGIN_SRSUBRECCREATE(CSrClasRecord, CSrIdRecord)
	DEFINE_SRSUBRECCREATE(SR_NAME_DESC, CSrDataSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_FULL, CSrDataSubrecord::Create)
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
BEGIN_SRFIELDMAP(CSrClasRecord, CSrIdRecord)
END_SRFIELDMAP()
/*===========================================================================
 *		End of CObRecord Field Map
 *=========================================================================*/


/*===========================================================================
 *
 * Class CSrClasRecord Constructor
 *
 *=========================================================================*/
CSrClasRecord::CSrClasRecord () 
{
}
/*===========================================================================
 *		End of Class CSrClasRecord Constructor
 *=========================================================================*/


/*===========================================================================
 *
 * Class CSrClasRecord Method - void Destroy (void);
 *
 *=========================================================================*/
void CSrClasRecord::Destroy (void) 
{
	CSrIdRecord::Destroy();
}
/*===========================================================================
 *		End of Class Method CSrClasRecord::Destroy()
 *=========================================================================*/


/*===========================================================================
 *
 * Class CSrClasRecord Method - void InitializeNew (void);
 *
 *=========================================================================*/
void CSrClasRecord::InitializeNew (void) 
{
	CSrIdRecord::InitializeNew();
}
/*===========================================================================
 *		End of Class Method CSrClasRecord::InitializeNew()
 *=========================================================================*/


/*===========================================================================
 *
 * Class CSrClasRecord Event - void OnAddSubrecord (pSubrecord);
 *
 *=========================================================================*/
void CSrClasRecord::OnAddSubrecord (CSrSubrecord* pSubrecord) {

	if (pSubrecord->GetRecordType() == SR_NAME_DESC)
	{
		m_pDescData = SrCastClass(CSrDataSubrecord, pSubrecord);
	}
	else if (pSubrecord->GetRecordType() == SR_NAME_FULL)
	{
		m_pFullData = SrCastClass(CSrDataSubrecord, pSubrecord);
	}
	else if (pSubrecord->GetRecordType() == SR_NAME_DATA)
	{
		m_pDataData = SrCastClass(CSrDataSubrecord, pSubrecord);
	}
	else
	{
		CSrIdRecord::OnAddSubrecord(pSubrecord);
	}

}
/*===========================================================================
 *		End of Class Event CSrClasRecord::OnAddSubRecord()
 *=========================================================================*/


/*===========================================================================
 *
 * Class CSrClasRecord Event - void OnDeleteSubrecord (pSubrecord);
 *
 *=========================================================================*/
void CSrClasRecord::OnDeleteSubrecord (CSrSubrecord* pSubrecord) {

	if (m_pDescData == pSubrecord)
		m_pDescData = NULL;
	else if (m_pFullData == pSubrecord)
		m_pFullData = NULL;
	else if (m_pDataData == pSubrecord)
		m_pDataData = NULL;
	else
		CSrIdRecord::OnDeleteSubrecord(pSubrecord);

}
/*===========================================================================
 *		End of Class Event CSrClasRecord::OnDeleteSubrecord()
 *=========================================================================*/


/*===========================================================================
 *
 * Begin CSrClasRecord Get Field Methods
 *
 *=========================================================================*/
/*===========================================================================
 *		End of CSrClasRecord Get Field Methods
 *=========================================================================*/


/*===========================================================================
 *
 * Begin CSrClasRecord Compare Field Methods
 *
 *=========================================================================*/
/*===========================================================================
 *		End of CSrClasRecord Compare Field Methods
 *=========================================================================*/


/*===========================================================================
 *
 * Begin CSrClasRecord Set Field Methods
 *
 *=========================================================================*/
/*===========================================================================
 *		End of CSrClasRecord Set Field Methods
 *=========================================================================*/
