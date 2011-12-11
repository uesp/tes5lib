/*===========================================================================
 *
 * File:		SrArmoRecord.CPP
 * Author:		Dave Humphrey (dave@uesp.net)
 * Created On:	5 December 2011
 *
 * Description
 *
 *=========================================================================*/

	/* Include Files */
#include "srArmorecord.h"


/*===========================================================================
 *
 * Begin Subrecord Creation Array
 *
 *=========================================================================*/
BEGIN_SRSUBRECCREATE(CSrArmoRecord, CSrIdKeyRecord)
	DEFINE_SRSUBRECCREATE(SR_NAME_FULL, CSrLStringSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_MOD4, CSrDataSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_OBND, CSrDataSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_TNAM, CSrDataSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_MO4T, CSrDataSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_BIDS, CSrDataSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_MOD2, CSrDataSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_MODL, CSrDataSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_MO2T, CSrDataSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_YNAM, CSrDataSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_BODT, CSrDataSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_ZNAM, CSrDataSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_RNAM, CSrDataSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_DESC, CSrDataSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_DATA, CSrDataSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_DNAM, CSrDataSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_EITM, CSrDataSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_ETYP, CSrDataSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_BAMT, CSrDataSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_MO2S, CSrDataSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_MO4S, CSrDataSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_VMAD, CSrDataSubrecord::Create)
END_SRSUBRECCREATE()
/*===========================================================================
 *		End of Subrecord Creation Array
 *=========================================================================*/


/*===========================================================================
 *
 * Begin CSrRecord Field Map
 *
 *=========================================================================*/
BEGIN_SRFIELDMAP(CSrArmoRecord, CSrIdKeyRecord)
	ADD_SRFIELDALL("Item Name", SR_FIELD_ITEMNAME, 0, CSrArmoRecord, FieldItemName)
END_SRFIELDMAP()
/*===========================================================================
 *		End of CObRecord Field Map
 *=========================================================================*/


/*===========================================================================
 *
 * Class CSrArmoRecord Constructor
 *
 *=========================================================================*/
CSrArmoRecord::CSrArmoRecord () 
{
	 m_pItemName   = NULL;
}
/*===========================================================================
 *		End of Class CSrArmoRecord Constructor
 *=========================================================================*/


/*===========================================================================
 *
 * Class CSrArmoRecord Method - void Destroy (void);
 *
 *=========================================================================*/
void CSrArmoRecord::Destroy (void) 
{
	m_pItemName   = NULL;
	CSrIdKeyRecord::Destroy();
}
/*===========================================================================
 *		End of Class Method CSrArmoRecord::Destroy()
 *=========================================================================*/


/*===========================================================================
 *
 * Class CSrArmoRecord Method - void InitializeNew (void);
 *
 *=========================================================================*/
void CSrArmoRecord::InitializeNew (void) 
{
	CSrIdKeyRecord::InitializeNew();

	AddNewSubrecord(SR_NAME_FULL);
	if (m_pItemName != NULL) m_pItemName->InitializeNew();

}
/*===========================================================================
 *		End of Class Method CSrArmoRecord::InitializeNew()
 *=========================================================================*/


/*===========================================================================
 *
 * Class CSrArmoRecord Event - void OnAddSubrecord (pSubrecord);
 *
 *=========================================================================*/
void CSrArmoRecord::OnAddSubrecord (CSrSubrecord* pSubrecord) {

	if (pSubrecord->GetRecordType() == SR_NAME_MOD4)
	{
		m_pMod4Data = SrCastClass(CSrDataSubrecord, pSubrecord);
	}
	else if (pSubrecord->GetRecordType() == SR_NAME_FULL)
	{
		m_pItemName = SrCastClass(CSrLStringSubrecord, pSubrecord);
	}
	else if (pSubrecord->GetRecordType() == SR_NAME_OBND)
	{
		m_pObndData = SrCastClass(CSrDataSubrecord, pSubrecord);
	}
	else if (pSubrecord->GetRecordType() == SR_NAME_TNAM)
	{
		m_pTnamData = SrCastClass(CSrDataSubrecord, pSubrecord);
	}
	else if (pSubrecord->GetRecordType() == SR_NAME_MO4T)
	{
		m_pMo4tData = SrCastClass(CSrDataSubrecord, pSubrecord);
	}
	else if (pSubrecord->GetRecordType() == SR_NAME_BIDS)
	{
		m_pBidsData = SrCastClass(CSrDataSubrecord, pSubrecord);
	}
	else if (pSubrecord->GetRecordType() == SR_NAME_MOD2)
	{
		m_pMod2Data = SrCastClass(CSrDataSubrecord, pSubrecord);
	}
	else if (pSubrecord->GetRecordType() == SR_NAME_MODL)
	{
		m_pModlData = SrCastClass(CSrDataSubrecord, pSubrecord);
	}
	else if (pSubrecord->GetRecordType() == SR_NAME_MO2T)
	{
		m_pMo2tData = SrCastClass(CSrDataSubrecord, pSubrecord);
	}
	else if (pSubrecord->GetRecordType() == SR_NAME_YNAM)
	{
		m_pYnamData = SrCastClass(CSrDataSubrecord, pSubrecord);
	}
	else if (pSubrecord->GetRecordType() == SR_NAME_BODT)
	{
		m_pBodtData = SrCastClass(CSrDataSubrecord, pSubrecord);
	}
	else if (pSubrecord->GetRecordType() == SR_NAME_ZNAM)
	{
		m_pZnamData = SrCastClass(CSrDataSubrecord, pSubrecord);
	}
	else if (pSubrecord->GetRecordType() == SR_NAME_RNAM)
	{
		m_pRnamData = SrCastClass(CSrDataSubrecord, pSubrecord);
	}
	else if (pSubrecord->GetRecordType() == SR_NAME_DESC)
	{
		m_pDescData = SrCastClass(CSrDataSubrecord, pSubrecord);
	}
	else if (pSubrecord->GetRecordType() == SR_NAME_DATA)
	{
		m_pDataData = SrCastClass(CSrDataSubrecord, pSubrecord);
	}
	else if (pSubrecord->GetRecordType() == SR_NAME_DNAM)
	{
		m_pDnamData = SrCastClass(CSrDataSubrecord, pSubrecord);
	}
	else if (pSubrecord->GetRecordType() == SR_NAME_EITM)
	{
		m_pEitmData = SrCastClass(CSrDataSubrecord, pSubrecord);
	}
	else if (pSubrecord->GetRecordType() == SR_NAME_ETYP)
	{
		m_pEtypData = SrCastClass(CSrDataSubrecord, pSubrecord);
	}
	else if (pSubrecord->GetRecordType() == SR_NAME_BAMT)
	{
		m_pBamtData = SrCastClass(CSrDataSubrecord, pSubrecord);
	}
	else if (pSubrecord->GetRecordType() == SR_NAME_MO2S)
	{
		m_pMo2sData = SrCastClass(CSrDataSubrecord, pSubrecord);
	}
	else if (pSubrecord->GetRecordType() == SR_NAME_MO4S)
	{
		m_pMo4sData = SrCastClass(CSrDataSubrecord, pSubrecord);
	}
	else if (pSubrecord->GetRecordType() == SR_NAME_VMAD)
	{
		m_pVmadData = SrCastClass(CSrDataSubrecord, pSubrecord);
	}
	else
	{
		CSrIdKeyRecord::OnAddSubrecord(pSubrecord);
	}

}
/*===========================================================================
 *		End of Class Event CSrArmoRecord::OnAddSubRecord()
 *=========================================================================*/


/*===========================================================================
 *
 * Class CSrArmoRecord Event - void OnDeleteSubrecord (pSubrecord);
 *
 *=========================================================================*/
void CSrArmoRecord::OnDeleteSubrecord (CSrSubrecord* pSubrecord) {

	if (m_pMod4Data == pSubrecord)
		m_pMod4Data = NULL;
	else if (m_pItemName == pSubrecord)
		m_pItemName = NULL;
	else if (m_pObndData == pSubrecord)
		m_pObndData = NULL;
	else if (m_pTnamData == pSubrecord)
		m_pTnamData = NULL;
	else if (m_pMo4tData == pSubrecord)
		m_pMo4tData = NULL;
	else if (m_pBidsData == pSubrecord)
		m_pBidsData = NULL;
	else if (m_pMod2Data == pSubrecord)
		m_pMod2Data = NULL;
	else if (m_pMo2tData == pSubrecord)
		m_pMo2tData = NULL;
	else if (m_pModlData == pSubrecord)
		m_pModlData = NULL;
	else if (m_pYnamData == pSubrecord)
		m_pYnamData = NULL;
	else if (m_pBodtData == pSubrecord)
		m_pBodtData = NULL;
	else if (m_pZnamData == pSubrecord)
		m_pZnamData = NULL;
	else if (m_pRnamData == pSubrecord)
		m_pRnamData = NULL;
	else if (m_pDescData == pSubrecord)
		m_pDescData = NULL;
	else if (m_pDataData == pSubrecord)
		m_pDataData = NULL;
	else if (m_pDnamData == pSubrecord)
		m_pDnamData = NULL;
	else if (m_pEitmData == pSubrecord)
		m_pEitmData = NULL;
	else if (m_pEtypData == pSubrecord)
		m_pEtypData = NULL;
	else if (m_pBamtData == pSubrecord)
		m_pBamtData = NULL;
	else if (m_pMo2sData == pSubrecord)
		m_pMo2sData = NULL;
	else if (m_pMo4sData == pSubrecord)
		m_pMo4sData = NULL;
	else if (m_pVmadData == pSubrecord)
		m_pVmadData = NULL;
	else
		CSrIdKeyRecord::OnDeleteSubrecord(pSubrecord);

}
/*===========================================================================
 *		End of Class Event CSrArmoRecord::OnDeleteSubrecord()
 *=========================================================================*/


/*===========================================================================
 *
 * Class CSrArmoRecord Method - void SetItemName (pString);
 *
 *=========================================================================*/
void CSrArmoRecord::SetItemName (const SSCHAR* pString) 
{

  if (m_pItemName == NULL) 
  {
     AddNewSubrecord(SR_NAME_FULL);
     if (m_pItemName == NULL) return;
     m_pItemName->InitializeNew();
  }

  m_pItemName->SetString(pString);
}
/*===========================================================================
 *		End of Class Method CSrArmoRecord::SetItemName()
 *=========================================================================*/


/*===========================================================================
 *
 * Begin CSrArmoRecord Get Field Methods
 *
 *=========================================================================*/
DEFINE_SRGETFIELD(CSrArmoRecord::GetFieldItemName, String.Format("%s", GetItemName()))
/*===========================================================================
 *		End of CSrArmoRecord Get Field Methods
 *=========================================================================*/


/*===========================================================================
 *
 * Begin CSrArmoRecord Compare Field Methods
 *
 *=========================================================================*/
DEFINE_SRCOMPFIELDSTRING(CSrArmoRecord, CompareFieldItemName, GetItemName)
/*===========================================================================
 *		End of CSrArmoRecord Compare Field Methods
 *=========================================================================*/


/*===========================================================================
 *
 * Begin CSrArmoRecord Set Field Methods
 *
 *=========================================================================*/
BEGIN_SRSETFIELD(CSrArmoRecord::SetFieldItemName)
  SetItemName(pString);
END_SRSETFIELD()
/*===========================================================================
 *		End of CSrArmoRecord Set Field Methods
 *=========================================================================*/
