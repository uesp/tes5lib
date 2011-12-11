/*===========================================================================
 *
 * File:		SrCamsRecord.CPP
 * Author:		Dave Humphrey (dave@uesp.net)
 * Created On:	5 December 2011
 *
 * Description
 *
 *=========================================================================*/

	/* Include Files */
#include "srCamsrecord.h"


/*===========================================================================
 *
 * Begin Subrecord Creation Array
 *
 *=========================================================================*/
BEGIN_SRSUBRECCREATE(CSrCamsRecord, CSrIdRecord)
	DEFINE_SRSUBRECCREATE(SR_NAME_MODL, CSrDataSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_MODT, CSrDataSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_DATA, CSrDataSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_MNAM, CSrDataSubrecord::Create)
END_SRSUBRECCREATE()
/*===========================================================================
 *		End of Subrecord Creation Array
 *=========================================================================*/


/*===========================================================================
 *
 * Begin CSrRecord Field Map
 *
 *=========================================================================*/
BEGIN_SRFIELDMAP(CSrCamsRecord, CSrIdRecord)
END_SRFIELDMAP()
/*===========================================================================
 *		End of CObRecord Field Map
 *=========================================================================*/


/*===========================================================================
 *
 * Class CSrCamsRecord Constructor
 *
 *=========================================================================*/
CSrCamsRecord::CSrCamsRecord () 
{
}
/*===========================================================================
 *		End of Class CSrCamsRecord Constructor
 *=========================================================================*/


/*===========================================================================
 *
 * Class CSrCamsRecord Method - void Destroy (void);
 *
 *=========================================================================*/
void CSrCamsRecord::Destroy (void) 
{
	CSrIdRecord::Destroy();
}
/*===========================================================================
 *		End of Class Method CSrCamsRecord::Destroy()
 *=========================================================================*/


/*===========================================================================
 *
 * Class CSrCamsRecord Method - void InitializeNew (void);
 *
 *=========================================================================*/
void CSrCamsRecord::InitializeNew (void) 
{
	CSrIdRecord::InitializeNew();
}
/*===========================================================================
 *		End of Class Method CSrCamsRecord::InitializeNew()
 *=========================================================================*/


/*===========================================================================
 *
 * Class CSrCamsRecord Event - void OnAddSubrecord (pSubrecord);
 *
 *=========================================================================*/
void CSrCamsRecord::OnAddSubrecord (CSrSubrecord* pSubrecord) {

	if (pSubrecord->GetRecordType() == SR_NAME_MODL)
	{
		m_pModlData = SrCastClass(CSrDataSubrecord, pSubrecord);
	}
	else if (pSubrecord->GetRecordType() == SR_NAME_MODT)
	{
		m_pModtData = SrCastClass(CSrDataSubrecord, pSubrecord);
	}
	else if (pSubrecord->GetRecordType() == SR_NAME_DATA)
	{
		m_pDataData = SrCastClass(CSrDataSubrecord, pSubrecord);
	}
	else if (pSubrecord->GetRecordType() == SR_NAME_MNAM)
	{
		m_pMnamData = SrCastClass(CSrDataSubrecord, pSubrecord);
	}
	else
	{
		CSrIdRecord::OnAddSubrecord(pSubrecord);
	}

}
/*===========================================================================
 *		End of Class Event CSrCamsRecord::OnAddSubRecord()
 *=========================================================================*/


/*===========================================================================
 *
 * Class CSrCamsRecord Event - void OnDeleteSubrecord (pSubrecord);
 *
 *=========================================================================*/
void CSrCamsRecord::OnDeleteSubrecord (CSrSubrecord* pSubrecord) {

	if (m_pModlData == pSubrecord)
		m_pModlData = NULL;
	else if (m_pModtData == pSubrecord)
		m_pModtData = NULL;
	else if (m_pDataData == pSubrecord)
		m_pDataData = NULL;
	else if (m_pMnamData == pSubrecord)
		m_pMnamData = NULL;
	else
		CSrIdRecord::OnDeleteSubrecord(pSubrecord);

}
/*===========================================================================
 *		End of Class Event CSrCamsRecord::OnDeleteSubrecord()
 *=========================================================================*/


/*===========================================================================
 *
 * Begin CSrCamsRecord Get Field Methods
 *
 *=========================================================================*/
/*===========================================================================
 *		End of CSrCamsRecord Get Field Methods
 *=========================================================================*/


/*===========================================================================
 *
 * Begin CSrCamsRecord Compare Field Methods
 *
 *=========================================================================*/
/*===========================================================================
 *		End of CSrCamsRecord Compare Field Methods
 *=========================================================================*/


/*===========================================================================
 *
 * Begin CSrCamsRecord Set Field Methods
 *
 *=========================================================================*/
/*===========================================================================
 *		End of CSrCamsRecord Set Field Methods
 *=========================================================================*/
