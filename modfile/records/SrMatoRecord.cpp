/*===========================================================================
 *
 * File:		SrMatoRecord.CPP
 * Author:		Dave Humphrey (dave@uesp.net)
 * Created On:	5 December 2011
 *
 * Description
 *
 *=========================================================================*/

	/* Include Files */
#include "srMatorecord.h"


/*===========================================================================
 *
 * Begin Subrecord Creation Array
 *
 *=========================================================================*/
BEGIN_SRSUBRECCREATE(CSrMatoRecord, CSrRecord)
	DEFINE_SRSUBRECCREATE(SR_NAME_MODL, CSrDataSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_EDID, CSrDataSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_DATA, CSrDataSubrecord::Create)
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
BEGIN_SRFIELDMAP(CSrMatoRecord, CSrRecord)
END_SRFIELDMAP()
/*===========================================================================
 *		End of CObRecord Field Map
 *=========================================================================*/


/*===========================================================================
 *
 * Class CSrMatoRecord Constructor
 *
 *=========================================================================*/
CSrMatoRecord::CSrMatoRecord () 
{
}
/*===========================================================================
 *		End of Class CSrMatoRecord Constructor
 *=========================================================================*/


/*===========================================================================
 *
 * Class CSrMatoRecord Method - void Destroy (void);
 *
 *=========================================================================*/
void CSrMatoRecord::Destroy (void) 
{
	CSrRecord::Destroy();
}
/*===========================================================================
 *		End of Class Method CSrMatoRecord::Destroy()
 *=========================================================================*/


/*===========================================================================
 *
 * Class CSrMatoRecord Method - void InitializeNew (void);
 *
 *=========================================================================*/
void CSrMatoRecord::InitializeNew (void) 
{

	/* Call the base class method first */
	CSrRecord::InitializeNew();


}
/*===========================================================================
 *		End of Class Method CSrMatoRecord::InitializeNew()
 *=========================================================================*/


/*===========================================================================
 *
 * Class CSrMatoRecord Event - void OnAddSubrecord (pSubrecord);
 *
 *=========================================================================*/
void CSrMatoRecord::OnAddSubrecord (CSrSubrecord* pSubrecord) {

	if (pSubrecord->GetRecordType() == SR_NAME_MODL)
	{
		m_pModlData = SrCastClass(CSrDataSubrecord, pSubrecord);
	}
	else if (pSubrecord->GetRecordType() == SR_NAME_EDID)
	{
		m_pEdidData = SrCastClass(CSrDataSubrecord, pSubrecord);
	}
	else if (pSubrecord->GetRecordType() == SR_NAME_DATA)
	{
		m_pDataData = SrCastClass(CSrDataSubrecord, pSubrecord);
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
 *		End of Class Event CSrMatoRecord::OnAddSubRecord()
 *=========================================================================*/


/*===========================================================================
 *
 * Class CSrMatoRecord Event - void OnDeleteSubrecord (pSubrecord);
 *
 *=========================================================================*/
void CSrMatoRecord::OnDeleteSubrecord (CSrSubrecord* pSubrecord) {

	if (m_pModlData == pSubrecord)
		m_pModlData = NULL;
	else if (m_pEdidData == pSubrecord)
		m_pEdidData = NULL;
	else if (m_pDataData == pSubrecord)
		m_pDataData = NULL;
	else if (m_pDnamData == pSubrecord)
		m_pDnamData = NULL;

	else
		CSrRecord::OnDeleteSubrecord(pSubrecord);

}
/*===========================================================================
 *		End of Class Event CSrMatoRecord::OnDeleteSubrecord()
 *=========================================================================*/


/*===========================================================================
 *
 * Begin CSrMatoRecord Get Field Methods
 *
 *=========================================================================*/
/*===========================================================================
 *		End of CSrMatoRecord Get Field Methods
 *=========================================================================*/


/*===========================================================================
 *
 * Begin CSrMatoRecord Compare Field Methods
 *
 *=========================================================================*/
/*===========================================================================
 *		End of CSrMatoRecord Compare Field Methods
 *=========================================================================*/


/*===========================================================================
 *
 * Begin CSrMatoRecord Set Field Methods
 *
 *=========================================================================*/
/*===========================================================================
 *		End of CSrMatoRecord Set Field Methods
 *=========================================================================*/
