/*===========================================================================
 *
 * File:		SrWoopRecord.CPP
 * Author:		Dave Humphrey (dave@uesp.net)
 * Created On:	5 December 2011
 *
 * Description
 *
 *=========================================================================*/

	/* Include Files */
#include "srWooprecord.h"


/*===========================================================================
 *
 * Begin Subrecord Creation Array
 *
 *=========================================================================*/
BEGIN_SRSUBRECCREATE(CSrWoopRecord, CSrIdRecord)
	DEFINE_SRSUBRECCREATE(SR_NAME_TNAM, CSrDataSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_FULL, CSrDataSubrecord::Create)
END_SRSUBRECCREATE()
/*===========================================================================
 *		End of Subrecord Creation Array
 *=========================================================================*/


/*===========================================================================
 *
 * Begin CSrIdRecord Field Map
 *
 *=========================================================================*/
BEGIN_SRFIELDMAP(CSrWoopRecord, CSrIdRecord)
END_SRFIELDMAP()
/*===========================================================================
 *		End of CObRecord Field Map
 *=========================================================================*/


/*===========================================================================
 *
 * Class CSrWoopRecord Constructor
 *
 *=========================================================================*/
CSrWoopRecord::CSrWoopRecord () 
{
}
/*===========================================================================
 *		End of Class CSrWoopRecord Constructor
 *=========================================================================*/


/*===========================================================================
 *
 * Class CSrWoopRecord Method - void Destroy (void);
 *
 *=========================================================================*/
void CSrWoopRecord::Destroy (void) 
{
	CSrIdRecord::Destroy();
}
/*===========================================================================
 *		End of Class Method CSrWoopRecord::Destroy()
 *=========================================================================*/


/*===========================================================================
 *
 * Class CSrWoopRecord Method - void InitializeNew (void);
 *
 *=========================================================================*/
void CSrWoopRecord::InitializeNew (void) 
{
	CSrIdRecord::InitializeNew();
}
/*===========================================================================
 *		End of Class Method CSrWoopRecord::InitializeNew()
 *=========================================================================*/


/*===========================================================================
 *
 * Class CSrWoopRecord Event - void OnAddSubrecord (pSubrecord);
 *
 *=========================================================================*/
void CSrWoopRecord::OnAddSubrecord (CSrSubrecord* pSubrecord) {

	if (pSubrecord->GetRecordType() == SR_NAME_TNAM)
	{
		m_pTnamData = SrCastClass(CSrDataSubrecord, pSubrecord);
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
 *		End of Class Event CSrWoopRecord::OnAddSubRecord()
 *=========================================================================*/


/*===========================================================================
 *
 * Class CSrWoopRecord Event - void OnDeleteSubrecord (pSubrecord);
 *
 *=========================================================================*/
void CSrWoopRecord::OnDeleteSubrecord (CSrSubrecord* pSubrecord) {

	if (m_pTnamData == pSubrecord)
		m_pTnamData = NULL;
	else if (m_pFullData == pSubrecord)
		m_pFullData = NULL;
	else
		CSrIdRecord::OnDeleteSubrecord(pSubrecord);

}
/*===========================================================================
 *		End of Class Event CSrWoopRecord::OnDeleteSubrecord()
 *=========================================================================*/


/*===========================================================================
 *
 * Begin CSrWoopRecord Get Field Methods
 *
 *=========================================================================*/
/*===========================================================================
 *		End of CSrWoopRecord Get Field Methods
 *=========================================================================*/


/*===========================================================================
 *
 * Begin CSrWoopRecord Compare Field Methods
 *
 *=========================================================================*/
/*===========================================================================
 *		End of CSrWoopRecord Compare Field Methods
 *=========================================================================*/


/*===========================================================================
 *
 * Begin CSrWoopRecord Set Field Methods
 *
 *=========================================================================*/
/*===========================================================================
 *		End of CSrWoopRecord Set Field Methods
 *=========================================================================*/
