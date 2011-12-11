/*===========================================================================
 *
 * File:		SrLvspRecord.CPP
 * Author:		Dave Humphrey (dave@uesp.net)
 * Created On:	5 December 2011
 *
 * Description
 *
 *=========================================================================*/

	/* Include Files */
#include "srLvsprecord.h"


/*===========================================================================
 *
 * Begin Subrecord Creation Array
 *
 *=========================================================================*/
BEGIN_SRSUBRECCREATE(CSrLvspRecord, CSrRecord)
	DEFINE_SRSUBRECCREATE(SR_NAME_OBND, CSrDataSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_EDID, CSrDataSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_LVLD, CSrDataSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_LVLF, CSrDataSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_LLCT, CSrDataSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_LVLO, CSrDataSubrecord::Create)

END_SRSUBRECCREATE()
/*===========================================================================
 *		End of Subrecord Creation Array
 *=========================================================================*/


/*===========================================================================
 *
 * Begin CSrRecord Field Map
 *
 *=========================================================================*/
BEGIN_SRFIELDMAP(CSrLvspRecord, CSrRecord)
END_SRFIELDMAP()
/*===========================================================================
 *		End of CObRecord Field Map
 *=========================================================================*/


/*===========================================================================
 *
 * Class CSrLvspRecord Constructor
 *
 *=========================================================================*/
CSrLvspRecord::CSrLvspRecord () 
{
}
/*===========================================================================
 *		End of Class CSrLvspRecord Constructor
 *=========================================================================*/


/*===========================================================================
 *
 * Class CSrLvspRecord Method - void Destroy (void);
 *
 *=========================================================================*/
void CSrLvspRecord::Destroy (void) 
{
	CSrRecord::Destroy();
}
/*===========================================================================
 *		End of Class Method CSrLvspRecord::Destroy()
 *=========================================================================*/


/*===========================================================================
 *
 * Class CSrLvspRecord Method - void InitializeNew (void);
 *
 *=========================================================================*/
void CSrLvspRecord::InitializeNew (void) 
{

	/* Call the base class method first */
	CSrRecord::InitializeNew();


}
/*===========================================================================
 *		End of Class Method CSrLvspRecord::InitializeNew()
 *=========================================================================*/


/*===========================================================================
 *
 * Class CSrLvspRecord Event - void OnAddSubrecord (pSubrecord);
 *
 *=========================================================================*/
void CSrLvspRecord::OnAddSubrecord (CSrSubrecord* pSubrecord) {

	if (pSubrecord->GetRecordType() == SR_NAME_OBND)
	{
		m_pObndData = SrCastClass(CSrDataSubrecord, pSubrecord);
	}
	else if (pSubrecord->GetRecordType() == SR_NAME_EDID)
	{
		m_pEdidData = SrCastClass(CSrDataSubrecord, pSubrecord);
	}
	else if (pSubrecord->GetRecordType() == SR_NAME_LVLD)
	{
		m_pLvldData = SrCastClass(CSrDataSubrecord, pSubrecord);
	}
	else if (pSubrecord->GetRecordType() == SR_NAME_LVLF)
	{
		m_pLvlfData = SrCastClass(CSrDataSubrecord, pSubrecord);
	}
	else if (pSubrecord->GetRecordType() == SR_NAME_LLCT)
	{
		m_pLlctData = SrCastClass(CSrDataSubrecord, pSubrecord);
	}
	else if (pSubrecord->GetRecordType() == SR_NAME_LVLO)
	{
		m_pLvloData = SrCastClass(CSrDataSubrecord, pSubrecord);
	}

	else
	{
	CSrRecord::OnAddSubrecord(pSubrecord);
	}

}
/*===========================================================================
 *		End of Class Event CSrLvspRecord::OnAddSubRecord()
 *=========================================================================*/


/*===========================================================================
 *
 * Class CSrLvspRecord Event - void OnDeleteSubrecord (pSubrecord);
 *
 *=========================================================================*/
void CSrLvspRecord::OnDeleteSubrecord (CSrSubrecord* pSubrecord) {

	if (m_pObndData == pSubrecord)
		m_pObndData = NULL;
	else if (m_pEdidData == pSubrecord)
		m_pEdidData = NULL;
	else if (m_pLvldData == pSubrecord)
		m_pLvldData = NULL;
	else if (m_pLvlfData == pSubrecord)
		m_pLvlfData = NULL;
	else if (m_pLlctData == pSubrecord)
		m_pLlctData = NULL;
	else if (m_pLvloData == pSubrecord)
		m_pLvloData = NULL;

	else
		CSrRecord::OnDeleteSubrecord(pSubrecord);

}
/*===========================================================================
 *		End of Class Event CSrLvspRecord::OnDeleteSubrecord()
 *=========================================================================*/


/*===========================================================================
 *
 * Begin CSrLvspRecord Get Field Methods
 *
 *=========================================================================*/
/*===========================================================================
 *		End of CSrLvspRecord Get Field Methods
 *=========================================================================*/


/*===========================================================================
 *
 * Begin CSrLvspRecord Compare Field Methods
 *
 *=========================================================================*/
/*===========================================================================
 *		End of CSrLvspRecord Compare Field Methods
 *=========================================================================*/


/*===========================================================================
 *
 * Begin CSrLvspRecord Set Field Methods
 *
 *=========================================================================*/
/*===========================================================================
 *		End of CSrLvspRecord Set Field Methods
 *=========================================================================*/
