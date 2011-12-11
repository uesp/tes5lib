/*===========================================================================
 *
 * File:		SrLvliRecord.CPP
 * Author:		Dave Humphrey (dave@uesp.net)
 * Created On:	5 December 2011
 *
 * Description
 *
 *=========================================================================*/

	/* Include Files */
#include "srLvlirecord.h"


/*===========================================================================
 *
 * Begin Subrecord Creation Array
 *
 *=========================================================================*/
BEGIN_SRSUBRECCREATE(CSrLvliRecord, CSrRecord)
	DEFINE_SRSUBRECCREATE(SR_NAME_OBND, CSrDataSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_EDID, CSrDataSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_LVLD, CSrDataSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_LVLF, CSrDataSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_LLCT, CSrDataSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_LVLO, CSrDataSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_LVLG, CSrDataSubrecord::Create)

END_SRSUBRECCREATE()
/*===========================================================================
 *		End of Subrecord Creation Array
 *=========================================================================*/


/*===========================================================================
 *
 * Begin CSrRecord Field Map
 *
 *=========================================================================*/
BEGIN_SRFIELDMAP(CSrLvliRecord, CSrRecord)
END_SRFIELDMAP()
/*===========================================================================
 *		End of CObRecord Field Map
 *=========================================================================*/


/*===========================================================================
 *
 * Class CSrLvliRecord Constructor
 *
 *=========================================================================*/
CSrLvliRecord::CSrLvliRecord () 
{
}
/*===========================================================================
 *		End of Class CSrLvliRecord Constructor
 *=========================================================================*/


/*===========================================================================
 *
 * Class CSrLvliRecord Method - void Destroy (void);
 *
 *=========================================================================*/
void CSrLvliRecord::Destroy (void) 
{
	CSrRecord::Destroy();
}
/*===========================================================================
 *		End of Class Method CSrLvliRecord::Destroy()
 *=========================================================================*/


/*===========================================================================
 *
 * Class CSrLvliRecord Method - void InitializeNew (void);
 *
 *=========================================================================*/
void CSrLvliRecord::InitializeNew (void) 
{

	/* Call the base class method first */
	CSrRecord::InitializeNew();


}
/*===========================================================================
 *		End of Class Method CSrLvliRecord::InitializeNew()
 *=========================================================================*/


/*===========================================================================
 *
 * Class CSrLvliRecord Event - void OnAddSubrecord (pSubrecord);
 *
 *=========================================================================*/
void CSrLvliRecord::OnAddSubrecord (CSrSubrecord* pSubrecord) {

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
	else if (pSubrecord->GetRecordType() == SR_NAME_LVLG)
	{
		m_pLvlgData = SrCastClass(CSrDataSubrecord, pSubrecord);
	}

	else
	{
	CSrRecord::OnAddSubrecord(pSubrecord);
	}

}
/*===========================================================================
 *		End of Class Event CSrLvliRecord::OnAddSubRecord()
 *=========================================================================*/


/*===========================================================================
 *
 * Class CSrLvliRecord Event - void OnDeleteSubrecord (pSubrecord);
 *
 *=========================================================================*/
void CSrLvliRecord::OnDeleteSubrecord (CSrSubrecord* pSubrecord) {

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
	else if (m_pLvlgData == pSubrecord)
		m_pLvlgData = NULL;

	else
		CSrRecord::OnDeleteSubrecord(pSubrecord);

}
/*===========================================================================
 *		End of Class Event CSrLvliRecord::OnDeleteSubrecord()
 *=========================================================================*/


/*===========================================================================
 *
 * Begin CSrLvliRecord Get Field Methods
 *
 *=========================================================================*/
/*===========================================================================
 *		End of CSrLvliRecord Get Field Methods
 *=========================================================================*/


/*===========================================================================
 *
 * Begin CSrLvliRecord Compare Field Methods
 *
 *=========================================================================*/
/*===========================================================================
 *		End of CSrLvliRecord Compare Field Methods
 *=========================================================================*/


/*===========================================================================
 *
 * Begin CSrLvliRecord Set Field Methods
 *
 *=========================================================================*/
/*===========================================================================
 *		End of CSrLvliRecord Set Field Methods
 *=========================================================================*/
