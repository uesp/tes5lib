/*===========================================================================
 *
 * File:		SrArmaRecord.CPP
 * Author:		Dave Humphrey (dave@uesp.net)
 * Created On:	5 December 2011
 *
 * Description
 *
 *=========================================================================*/

	/* Include Files */
#include "srArmarecord.h"


/*===========================================================================
 *
 * Begin Subrecord Creation Array
 *
 *=========================================================================*/
BEGIN_SRSUBRECCREATE(CSrArmaRecord, CSrIdRecord)
	DEFINE_SRSUBRECCREATE(SR_NAME_MODL, CSrDataSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_MOD4, CSrDataSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_BODT, CSrDataSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_MOD3, CSrDataSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_RNAM, CSrDataSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_MOD2, CSrDataSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_DNAM, CSrDataSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_MO2T, CSrDataSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_MO3T, CSrDataSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_MO3S, CSrDataSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_MO2S, CSrDataSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_NAM0, CSrDataSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_MO4S, CSrDataSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_SNDD, CSrDataSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_NAM1, CSrDataSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_MO5T, CSrDataSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_MO4T, CSrDataSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_MOD5, CSrDataSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_NAM2, CSrDataSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_NAM3, CSrDataSubrecord::Create)
END_SRSUBRECCREATE()
/*===========================================================================
 *		End of Subrecord Creation Array
 *=========================================================================*/


/*===========================================================================
 *
 * Begin CSrRecord Field Map
 *
 *=========================================================================*/
BEGIN_SRFIELDMAP(CSrArmaRecord, CSrIdRecord)
END_SRFIELDMAP()
/*===========================================================================
 *		End of CObRecord Field Map
 *=========================================================================*/


/*===========================================================================
 *
 * Class CSrArmaRecord Constructor
 *
 *=========================================================================*/
CSrArmaRecord::CSrArmaRecord () 
{
}
/*===========================================================================
 *		End of Class CSrArmaRecord Constructor
 *=========================================================================*/


/*===========================================================================
 *
 * Class CSrArmaRecord Method - void Destroy (void);
 *
 *=========================================================================*/
void CSrArmaRecord::Destroy (void) 
{
	CSrIdRecord::Destroy();
}
/*===========================================================================
 *		End of Class Method CSrArmaRecord::Destroy()
 *=========================================================================*/


/*===========================================================================
 *
 * Class CSrArmaRecord Method - void InitializeNew (void);
 *
 *=========================================================================*/
void CSrArmaRecord::InitializeNew (void) 
{
	CSrIdRecord::InitializeNew();
}
/*===========================================================================
 *		End of Class Method CSrArmaRecord::InitializeNew()
 *=========================================================================*/


/*===========================================================================
 *
 * Class CSrArmaRecord Event - void OnAddSubrecord (pSubrecord);
 *
 *=========================================================================*/
void CSrArmaRecord::OnAddSubrecord (CSrSubrecord* pSubrecord) {

	if (pSubrecord->GetRecordType() == SR_NAME_MODL)
	{
		m_pModlData = SrCastClass(CSrDataSubrecord, pSubrecord);
	}
	else if (pSubrecord->GetRecordType() == SR_NAME_MOD4)
	{
		m_pMod4Data = SrCastClass(CSrDataSubrecord, pSubrecord);
	}
	else if (pSubrecord->GetRecordType() == SR_NAME_BODT)
	{
		m_pBodtData = SrCastClass(CSrDataSubrecord, pSubrecord);
	}
	else if (pSubrecord->GetRecordType() == SR_NAME_MOD3)
	{
		m_pMod3Data = SrCastClass(CSrDataSubrecord, pSubrecord);
	}
	else if (pSubrecord->GetRecordType() == SR_NAME_RNAM)
	{
		m_pRnamData = SrCastClass(CSrDataSubrecord, pSubrecord);
	}
	else if (pSubrecord->GetRecordType() == SR_NAME_MOD2)
	{
		m_pMod2Data = SrCastClass(CSrDataSubrecord, pSubrecord);
	}
	else if (pSubrecord->GetRecordType() == SR_NAME_DNAM)
	{
		m_pDnamData = SrCastClass(CSrDataSubrecord, pSubrecord);
	}
	else if (pSubrecord->GetRecordType() == SR_NAME_MO2T)
	{
		m_pMo2tData = SrCastClass(CSrDataSubrecord, pSubrecord);
	}
	else if (pSubrecord->GetRecordType() == SR_NAME_MO3T)
	{
		m_pMo3tData = SrCastClass(CSrDataSubrecord, pSubrecord);
	}
	else if (pSubrecord->GetRecordType() == SR_NAME_MO3S)
	{
		m_pMo3sData = SrCastClass(CSrDataSubrecord, pSubrecord);
	}
	else if (pSubrecord->GetRecordType() == SR_NAME_MO2S)
	{
		m_pMo2sData = SrCastClass(CSrDataSubrecord, pSubrecord);
	}
	else if (pSubrecord->GetRecordType() == SR_NAME_NAM0)
	{
		m_pNam0Data = SrCastClass(CSrDataSubrecord, pSubrecord);
	}
	else if (pSubrecord->GetRecordType() == SR_NAME_MO4S)
	{
		m_pMo4sData = SrCastClass(CSrDataSubrecord, pSubrecord);
	}
	else if (pSubrecord->GetRecordType() == SR_NAME_SNDD)
	{
		m_pSnddData = SrCastClass(CSrDataSubrecord, pSubrecord);
	}
	else if (pSubrecord->GetRecordType() == SR_NAME_NAM1)
	{
		m_pNam1Data = SrCastClass(CSrDataSubrecord, pSubrecord);
	}
	else if (pSubrecord->GetRecordType() == SR_NAME_MO5T)
	{
		m_pMo5tData = SrCastClass(CSrDataSubrecord, pSubrecord);
	}
	else if (pSubrecord->GetRecordType() == SR_NAME_MO4T)
	{
		m_pMo4tData = SrCastClass(CSrDataSubrecord, pSubrecord);
	}
	else if (pSubrecord->GetRecordType() == SR_NAME_MOD5)
	{
		m_pMod5Data = SrCastClass(CSrDataSubrecord, pSubrecord);
	}
	else if (pSubrecord->GetRecordType() == SR_NAME_NAM2)
	{
		m_pNam2Data = SrCastClass(CSrDataSubrecord, pSubrecord);
	}
	else if (pSubrecord->GetRecordType() == SR_NAME_NAM3)
	{
		m_pNam3Data = SrCastClass(CSrDataSubrecord, pSubrecord);
	}
	else
	{
		CSrIdRecord::OnAddSubrecord(pSubrecord);
	}

}
/*===========================================================================
 *		End of Class Event CSrArmaRecord::OnAddSubRecord()
 *=========================================================================*/


/*===========================================================================
 *
 * Class CSrArmaRecord Event - void OnDeleteSubrecord (pSubrecord);
 *
 *=========================================================================*/
void CSrArmaRecord::OnDeleteSubrecord (CSrSubrecord* pSubrecord) {

	if (m_pModlData == pSubrecord)
		m_pModlData = NULL;
	else if (m_pMod4Data == pSubrecord)
		m_pMod4Data = NULL;
	else if (m_pBodtData == pSubrecord)
		m_pBodtData = NULL;
	else if (m_pMod3Data == pSubrecord)
		m_pMod3Data = NULL;
	else if (m_pRnamData == pSubrecord)
		m_pRnamData = NULL;
	else if (m_pMod2Data == pSubrecord)
		m_pMod2Data = NULL;
	else if (m_pDnamData == pSubrecord)
		m_pDnamData = NULL;
	else if (m_pMo2tData == pSubrecord)
		m_pMo2tData = NULL;
	else if (m_pMo3tData == pSubrecord)
		m_pMo3tData = NULL;
	else if (m_pMo3sData == pSubrecord)
		m_pMo3sData = NULL;
	else if (m_pMo2sData == pSubrecord)
		m_pMo2sData = NULL;
	else if (m_pNam0Data == pSubrecord)
		m_pNam0Data = NULL;
	else if (m_pMo4sData == pSubrecord)
		m_pMo4sData = NULL;
	else if (m_pSnddData == pSubrecord)
		m_pSnddData = NULL;
	else if (m_pNam1Data == pSubrecord)
		m_pNam1Data = NULL;
	else if (m_pMo5tData == pSubrecord)
		m_pMo5tData = NULL;
	else if (m_pMo4tData == pSubrecord)
		m_pMo4tData = NULL;
	else if (m_pMod5Data == pSubrecord)
		m_pMod5Data = NULL;
	else if (m_pNam2Data == pSubrecord)
		m_pNam2Data = NULL;
	else if (m_pNam3Data == pSubrecord)
		m_pNam3Data = NULL;
	else
		CSrIdRecord::OnDeleteSubrecord(pSubrecord);

}
/*===========================================================================
 *		End of Class Event CSrArmaRecord::OnDeleteSubrecord()
 *=========================================================================*/


/*===========================================================================
 *
 * Begin CSrArmaRecord Get Field Methods
 *
 *=========================================================================*/
/*===========================================================================
 *		End of CSrArmaRecord Get Field Methods
 *=========================================================================*/


/*===========================================================================
 *
 * Begin CSrArmaRecord Compare Field Methods
 *
 *=========================================================================*/
/*===========================================================================
 *		End of CSrArmaRecord Compare Field Methods
 *=========================================================================*/


/*===========================================================================
 *
 * Begin CSrArmaRecord Set Field Methods
 *
 *=========================================================================*/
/*===========================================================================
 *		End of CSrArmaRecord Set Field Methods
 *=========================================================================*/
