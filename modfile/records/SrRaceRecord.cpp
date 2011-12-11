/*===========================================================================
 *
 * File:		SrRaceRecord.CPP
 * Author:		Dave Humphrey (dave@uesp.net)
 * Created On:	5 December 2011
 *
 * Description
 *
 *=========================================================================*/

	/* Include Files */
#include "srRacerecord.h"


/*===========================================================================
 *
 * Begin Subrecord Creation Array
 *
 *=========================================================================*/
BEGIN_SRSUBRECCREATE(CSrRaceRecord, CSrRecord)
	DEFINE_SRSUBRECCREATE(SR_NAME_EDID, CSrDataSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_TINT, CSrDataSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_FNAM, CSrDataSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_FTSF, CSrDataSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_TINP, CSrDataSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_KSIZ, CSrDataSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_DESC, CSrDataSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_INDX, CSrDataSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_FULL, CSrDataSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_WNAM, CSrDataSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_DATA, CSrDataSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_RPRM, CSrDataSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_KWDA, CSrDataSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_HCLF, CSrDataSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_ANAM, CSrDataSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_BODT, CSrDataSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_MNAM, CSrDataSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_LNAM, CSrDataSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_MODT, CSrDataSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_MTNM, CSrDataSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_VTCK, CSrDataSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_RPRF, CSrDataSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_PNAM, CSrDataSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_UNAM, CSrDataSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_ATKD, CSrDataSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_DFTF, CSrDataSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_MTYP, CSrDataSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_ATKE, CSrDataSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_NAM1, CSrDataSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_MODL, CSrDataSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_AHCF, CSrDataSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_GNAM, CSrDataSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_PHWT, CSrDataSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_NAM3, CSrDataSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_NAM4, CSrDataSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_MPAV, CSrDataSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_NAM5, CSrDataSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_SNMV, CSrDataSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_SWMV, CSrDataSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_NAM0, CSrDataSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_UNES, CSrDataSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_ONAM, CSrDataSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_FLMV, CSrDataSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_NAME, CSrDataSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_VNAM, CSrDataSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_QNAM, CSrDataSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_TINL, CSrDataSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_HEAD, CSrDataSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_MPAI, CSrDataSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_AHCM, CSrDataSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_TINI, CSrDataSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_TIND, CSrDataSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_SPLO, CSrDataSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_TINC, CSrDataSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_TINV, CSrDataSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_TIRS, CSrDataSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_NAM8, CSrDataSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_SPCT, CSrDataSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_DNAM, CSrDataSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_NAM7, CSrDataSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_PHTN, CSrDataSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_WKMV, CSrDataSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_RNMV, CSrDataSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_SPED, CSrDataSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_FTSM, CSrDataSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_DFTM, CSrDataSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_RNAM, CSrDataSubrecord::Create)

END_SRSUBRECCREATE()
/*===========================================================================
 *		End of Subrecord Creation Array
 *=========================================================================*/


/*===========================================================================
 *
 * Begin CSrRecord Field Map
 *
 *=========================================================================*/
BEGIN_SRFIELDMAP(CSrRaceRecord, CSrRecord)
END_SRFIELDMAP()
/*===========================================================================
 *		End of CObRecord Field Map
 *=========================================================================*/


/*===========================================================================
 *
 * Class CSrRaceRecord Constructor
 *
 *=========================================================================*/
CSrRaceRecord::CSrRaceRecord () 
{
}
/*===========================================================================
 *		End of Class CSrRaceRecord Constructor
 *=========================================================================*/


/*===========================================================================
 *
 * Class CSrRaceRecord Method - void Destroy (void);
 *
 *=========================================================================*/
void CSrRaceRecord::Destroy (void) 
{
	CSrRecord::Destroy();
}
/*===========================================================================
 *		End of Class Method CSrRaceRecord::Destroy()
 *=========================================================================*/


/*===========================================================================
 *
 * Class CSrRaceRecord Method - void InitializeNew (void);
 *
 *=========================================================================*/
void CSrRaceRecord::InitializeNew (void) 
{

	/* Call the base class method first */
	CSrRecord::InitializeNew();


}
/*===========================================================================
 *		End of Class Method CSrRaceRecord::InitializeNew()
 *=========================================================================*/


/*===========================================================================
 *
 * Class CSrRaceRecord Event - void OnAddSubrecord (pSubrecord);
 *
 *=========================================================================*/
void CSrRaceRecord::OnAddSubrecord (CSrSubrecord* pSubrecord) {

	if (pSubrecord->GetRecordType() == SR_NAME_EDID)
	{
		m_pEdidData = SrCastClass(CSrDataSubrecord, pSubrecord);
	}
	else if (pSubrecord->GetRecordType() == SR_NAME_TINT)
	{
		m_pTintData = SrCastClass(CSrDataSubrecord, pSubrecord);
	}
	else if (pSubrecord->GetRecordType() == SR_NAME_FNAM)
	{
		m_pFnamData = SrCastClass(CSrDataSubrecord, pSubrecord);
	}
	else if (pSubrecord->GetRecordType() == SR_NAME_FTSF)
	{
		m_pFtsfData = SrCastClass(CSrDataSubrecord, pSubrecord);
	}
	else if (pSubrecord->GetRecordType() == SR_NAME_TINP)
	{
		m_pTinpData = SrCastClass(CSrDataSubrecord, pSubrecord);
	}
	else if (pSubrecord->GetRecordType() == SR_NAME_KSIZ)
	{
		m_pKsizData = SrCastClass(CSrDataSubrecord, pSubrecord);
	}
	else if (pSubrecord->GetRecordType() == SR_NAME_DESC)
	{
		m_pDescData = SrCastClass(CSrDataSubrecord, pSubrecord);
	}
	else if (pSubrecord->GetRecordType() == SR_NAME_INDX)
	{
		m_pIndxData = SrCastClass(CSrDataSubrecord, pSubrecord);
	}
	else if (pSubrecord->GetRecordType() == SR_NAME_FULL)
	{
		m_pFullData = SrCastClass(CSrDataSubrecord, pSubrecord);
	}
	else if (pSubrecord->GetRecordType() == SR_NAME_WNAM)
	{
		m_pWnamData = SrCastClass(CSrDataSubrecord, pSubrecord);
	}
	else if (pSubrecord->GetRecordType() == SR_NAME_DATA)
	{
		m_pDataData = SrCastClass(CSrDataSubrecord, pSubrecord);
	}
	else if (pSubrecord->GetRecordType() == SR_NAME_RPRM)
	{
		m_pRprmData = SrCastClass(CSrDataSubrecord, pSubrecord);
	}
	else if (pSubrecord->GetRecordType() == SR_NAME_KWDA)
	{
		m_pKwdaData = SrCastClass(CSrDataSubrecord, pSubrecord);
	}
	else if (pSubrecord->GetRecordType() == SR_NAME_HCLF)
	{
		m_pHclfData = SrCastClass(CSrDataSubrecord, pSubrecord);
	}
	else if (pSubrecord->GetRecordType() == SR_NAME_ANAM)
	{
		m_pAnamData = SrCastClass(CSrDataSubrecord, pSubrecord);
	}
	else if (pSubrecord->GetRecordType() == SR_NAME_BODT)
	{
		m_pBodtData = SrCastClass(CSrDataSubrecord, pSubrecord);
	}
	else if (pSubrecord->GetRecordType() == SR_NAME_MNAM)
	{
		m_pMnamData = SrCastClass(CSrDataSubrecord, pSubrecord);
	}
	else if (pSubrecord->GetRecordType() == SR_NAME_LNAM)
	{
		m_pLnamData = SrCastClass(CSrDataSubrecord, pSubrecord);
	}
	else if (pSubrecord->GetRecordType() == SR_NAME_MODT)
	{
		m_pModtData = SrCastClass(CSrDataSubrecord, pSubrecord);
	}
	else if (pSubrecord->GetRecordType() == SR_NAME_MTNM)
	{
		m_pMtnmData = SrCastClass(CSrDataSubrecord, pSubrecord);
	}
	else if (pSubrecord->GetRecordType() == SR_NAME_VTCK)
	{
		m_pVtckData = SrCastClass(CSrDataSubrecord, pSubrecord);
	}
	else if (pSubrecord->GetRecordType() == SR_NAME_RPRF)
	{
		m_pRprfData = SrCastClass(CSrDataSubrecord, pSubrecord);
	}
	else if (pSubrecord->GetRecordType() == SR_NAME_PNAM)
	{
		m_pPnamData = SrCastClass(CSrDataSubrecord, pSubrecord);
	}
	else if (pSubrecord->GetRecordType() == SR_NAME_UNAM)
	{
		m_pUnamData = SrCastClass(CSrDataSubrecord, pSubrecord);
	}
	else if (pSubrecord->GetRecordType() == SR_NAME_ATKD)
	{
		m_pAtkdData = SrCastClass(CSrDataSubrecord, pSubrecord);
	}
	else if (pSubrecord->GetRecordType() == SR_NAME_DFTF)
	{
		m_pDftfData = SrCastClass(CSrDataSubrecord, pSubrecord);
	}
	else if (pSubrecord->GetRecordType() == SR_NAME_MTYP)
	{
		m_pMtypData = SrCastClass(CSrDataSubrecord, pSubrecord);
	}
	else if (pSubrecord->GetRecordType() == SR_NAME_ATKE)
	{
		m_pAtkeData = SrCastClass(CSrDataSubrecord, pSubrecord);
	}
	else if (pSubrecord->GetRecordType() == SR_NAME_NAM1)
	{
		m_pNam1Data = SrCastClass(CSrDataSubrecord, pSubrecord);
	}
	else if (pSubrecord->GetRecordType() == SR_NAME_MODL)
	{
		m_pModlData = SrCastClass(CSrDataSubrecord, pSubrecord);
	}
	else if (pSubrecord->GetRecordType() == SR_NAME_AHCF)
	{
		m_pAhcfData = SrCastClass(CSrDataSubrecord, pSubrecord);
	}
	else if (pSubrecord->GetRecordType() == SR_NAME_GNAM)
	{
		m_pGnamData = SrCastClass(CSrDataSubrecord, pSubrecord);
	}
	else if (pSubrecord->GetRecordType() == SR_NAME_PHWT)
	{
		m_pPhwtData = SrCastClass(CSrDataSubrecord, pSubrecord);
	}
	else if (pSubrecord->GetRecordType() == SR_NAME_NAM3)
	{
		m_pNam3Data = SrCastClass(CSrDataSubrecord, pSubrecord);
	}
	else if (pSubrecord->GetRecordType() == SR_NAME_NAM4)
	{
		m_pNam4Data = SrCastClass(CSrDataSubrecord, pSubrecord);
	}
	else if (pSubrecord->GetRecordType() == SR_NAME_MPAV)
	{
		m_pMpavData = SrCastClass(CSrDataSubrecord, pSubrecord);
	}
	else if (pSubrecord->GetRecordType() == SR_NAME_NAM5)
	{
		m_pNam5Data = SrCastClass(CSrDataSubrecord, pSubrecord);
	}
	else if (pSubrecord->GetRecordType() == SR_NAME_SNMV)
	{
		m_pSnmvData = SrCastClass(CSrDataSubrecord, pSubrecord);
	}
	else if (pSubrecord->GetRecordType() == SR_NAME_SWMV)
	{
		m_pSwmvData = SrCastClass(CSrDataSubrecord, pSubrecord);
	}
	else if (pSubrecord->GetRecordType() == SR_NAME_NAM0)
	{
		m_pNam0Data = SrCastClass(CSrDataSubrecord, pSubrecord);
	}
	else if (pSubrecord->GetRecordType() == SR_NAME_UNES)
	{
		m_pUnesData = SrCastClass(CSrDataSubrecord, pSubrecord);
	}
	else if (pSubrecord->GetRecordType() == SR_NAME_ONAM)
	{
		m_pOnamData = SrCastClass(CSrDataSubrecord, pSubrecord);
	}
	else if (pSubrecord->GetRecordType() == SR_NAME_FLMV)
	{
		m_pFlmvData = SrCastClass(CSrDataSubrecord, pSubrecord);
	}
	else if (pSubrecord->GetRecordType() == SR_NAME_NAME)
	{
		m_pNameData = SrCastClass(CSrDataSubrecord, pSubrecord);
	}
	else if (pSubrecord->GetRecordType() == SR_NAME_VNAM)
	{
		m_pVnamData = SrCastClass(CSrDataSubrecord, pSubrecord);
	}
	else if (pSubrecord->GetRecordType() == SR_NAME_QNAM)
	{
		m_pQnamData = SrCastClass(CSrDataSubrecord, pSubrecord);
	}
	else if (pSubrecord->GetRecordType() == SR_NAME_TINL)
	{
		m_pTinlData = SrCastClass(CSrDataSubrecord, pSubrecord);
	}
	else if (pSubrecord->GetRecordType() == SR_NAME_HEAD)
	{
		m_pHeadData = SrCastClass(CSrDataSubrecord, pSubrecord);
	}
	else if (pSubrecord->GetRecordType() == SR_NAME_MPAI)
	{
		m_pMpaiData = SrCastClass(CSrDataSubrecord, pSubrecord);
	}
	else if (pSubrecord->GetRecordType() == SR_NAME_AHCM)
	{
		m_pAhcmData = SrCastClass(CSrDataSubrecord, pSubrecord);
	}
	else if (pSubrecord->GetRecordType() == SR_NAME_TINI)
	{
		m_pTiniData = SrCastClass(CSrDataSubrecord, pSubrecord);
	}
	else if (pSubrecord->GetRecordType() == SR_NAME_TIND)
	{
		m_pTindData = SrCastClass(CSrDataSubrecord, pSubrecord);
	}
	else if (pSubrecord->GetRecordType() == SR_NAME_SPLO)
	{
		m_pSploData = SrCastClass(CSrDataSubrecord, pSubrecord);
	}
	else if (pSubrecord->GetRecordType() == SR_NAME_TINC)
	{
		m_pTincData = SrCastClass(CSrDataSubrecord, pSubrecord);
	}
	else if (pSubrecord->GetRecordType() == SR_NAME_TINV)
	{
		m_pTinvData = SrCastClass(CSrDataSubrecord, pSubrecord);
	}
	else if (pSubrecord->GetRecordType() == SR_NAME_TIRS)
	{
		m_pTirsData = SrCastClass(CSrDataSubrecord, pSubrecord);
	}
	else if (pSubrecord->GetRecordType() == SR_NAME_NAM8)
	{
		m_pNam8Data = SrCastClass(CSrDataSubrecord, pSubrecord);
	}
	else if (pSubrecord->GetRecordType() == SR_NAME_SPCT)
	{
		m_pSpctData = SrCastClass(CSrDataSubrecord, pSubrecord);
	}
	else if (pSubrecord->GetRecordType() == SR_NAME_DNAM)
	{
		m_pDnamData = SrCastClass(CSrDataSubrecord, pSubrecord);
	}
	else if (pSubrecord->GetRecordType() == SR_NAME_NAM7)
	{
		m_pNam7Data = SrCastClass(CSrDataSubrecord, pSubrecord);
	}
	else if (pSubrecord->GetRecordType() == SR_NAME_PHTN)
	{
		m_pPhtnData = SrCastClass(CSrDataSubrecord, pSubrecord);
	}
	else if (pSubrecord->GetRecordType() == SR_NAME_WKMV)
	{
		m_pWkmvData = SrCastClass(CSrDataSubrecord, pSubrecord);
	}
	else if (pSubrecord->GetRecordType() == SR_NAME_RNMV)
	{
		m_pRnmvData = SrCastClass(CSrDataSubrecord, pSubrecord);
	}
	else if (pSubrecord->GetRecordType() == SR_NAME_SPED)
	{
		m_pSpedData = SrCastClass(CSrDataSubrecord, pSubrecord);
	}
	else if (pSubrecord->GetRecordType() == SR_NAME_FTSM)
	{
		m_pFtsmData = SrCastClass(CSrDataSubrecord, pSubrecord);
	}
	else if (pSubrecord->GetRecordType() == SR_NAME_DFTM)
	{
		m_pDftmData = SrCastClass(CSrDataSubrecord, pSubrecord);
	}
	else if (pSubrecord->GetRecordType() == SR_NAME_RNAM)
	{
		m_pRnamData = SrCastClass(CSrDataSubrecord, pSubrecord);
	}

	else
	{
	CSrRecord::OnAddSubrecord(pSubrecord);
	}

}
/*===========================================================================
 *		End of Class Event CSrRaceRecord::OnAddSubRecord()
 *=========================================================================*/


/*===========================================================================
 *
 * Class CSrRaceRecord Event - void OnDeleteSubrecord (pSubrecord);
 *
 *=========================================================================*/
void CSrRaceRecord::OnDeleteSubrecord (CSrSubrecord* pSubrecord) {

	if (m_pEdidData == pSubrecord)
		m_pEdidData = NULL;
	else if (m_pTintData == pSubrecord)
		m_pTintData = NULL;
	else if (m_pFnamData == pSubrecord)
		m_pFnamData = NULL;
	else if (m_pFtsfData == pSubrecord)
		m_pFtsfData = NULL;
	else if (m_pTinpData == pSubrecord)
		m_pTinpData = NULL;
	else if (m_pKsizData == pSubrecord)
		m_pKsizData = NULL;
	else if (m_pDescData == pSubrecord)
		m_pDescData = NULL;
	else if (m_pIndxData == pSubrecord)
		m_pIndxData = NULL;
	else if (m_pFullData == pSubrecord)
		m_pFullData = NULL;
	else if (m_pWnamData == pSubrecord)
		m_pWnamData = NULL;
	else if (m_pDataData == pSubrecord)
		m_pDataData = NULL;
	else if (m_pRprmData == pSubrecord)
		m_pRprmData = NULL;
	else if (m_pKwdaData == pSubrecord)
		m_pKwdaData = NULL;
	else if (m_pHclfData == pSubrecord)
		m_pHclfData = NULL;
	else if (m_pAnamData == pSubrecord)
		m_pAnamData = NULL;
	else if (m_pBodtData == pSubrecord)
		m_pBodtData = NULL;
	else if (m_pMnamData == pSubrecord)
		m_pMnamData = NULL;
	else if (m_pLnamData == pSubrecord)
		m_pLnamData = NULL;
	else if (m_pModtData == pSubrecord)
		m_pModtData = NULL;
	else if (m_pMtnmData == pSubrecord)
		m_pMtnmData = NULL;
	else if (m_pVtckData == pSubrecord)
		m_pVtckData = NULL;
	else if (m_pRprfData == pSubrecord)
		m_pRprfData = NULL;
	else if (m_pPnamData == pSubrecord)
		m_pPnamData = NULL;
	else if (m_pUnamData == pSubrecord)
		m_pUnamData = NULL;
	else if (m_pAtkdData == pSubrecord)
		m_pAtkdData = NULL;
	else if (m_pDftfData == pSubrecord)
		m_pDftfData = NULL;
	else if (m_pMtypData == pSubrecord)
		m_pMtypData = NULL;
	else if (m_pAtkeData == pSubrecord)
		m_pAtkeData = NULL;
	else if (m_pNam1Data == pSubrecord)
		m_pNam1Data = NULL;
	else if (m_pModlData == pSubrecord)
		m_pModlData = NULL;
	else if (m_pAhcfData == pSubrecord)
		m_pAhcfData = NULL;
	else if (m_pGnamData == pSubrecord)
		m_pGnamData = NULL;
	else if (m_pPhwtData == pSubrecord)
		m_pPhwtData = NULL;
	else if (m_pNam3Data == pSubrecord)
		m_pNam3Data = NULL;
	else if (m_pNam4Data == pSubrecord)
		m_pNam4Data = NULL;
	else if (m_pMpavData == pSubrecord)
		m_pMpavData = NULL;
	else if (m_pNam5Data == pSubrecord)
		m_pNam5Data = NULL;
	else if (m_pSnmvData == pSubrecord)
		m_pSnmvData = NULL;
	else if (m_pSwmvData == pSubrecord)
		m_pSwmvData = NULL;
	else if (m_pNam0Data == pSubrecord)
		m_pNam0Data = NULL;
	else if (m_pUnesData == pSubrecord)
		m_pUnesData = NULL;
	else if (m_pOnamData == pSubrecord)
		m_pOnamData = NULL;
	else if (m_pFlmvData == pSubrecord)
		m_pFlmvData = NULL;
	else if (m_pNameData == pSubrecord)
		m_pNameData = NULL;
	else if (m_pVnamData == pSubrecord)
		m_pVnamData = NULL;
	else if (m_pQnamData == pSubrecord)
		m_pQnamData = NULL;
	else if (m_pTinlData == pSubrecord)
		m_pTinlData = NULL;
	else if (m_pHeadData == pSubrecord)
		m_pHeadData = NULL;
	else if (m_pMpaiData == pSubrecord)
		m_pMpaiData = NULL;
	else if (m_pAhcmData == pSubrecord)
		m_pAhcmData = NULL;
	else if (m_pTiniData == pSubrecord)
		m_pTiniData = NULL;
	else if (m_pTindData == pSubrecord)
		m_pTindData = NULL;
	else if (m_pSploData == pSubrecord)
		m_pSploData = NULL;
	else if (m_pTincData == pSubrecord)
		m_pTincData = NULL;
	else if (m_pTinvData == pSubrecord)
		m_pTinvData = NULL;
	else if (m_pTirsData == pSubrecord)
		m_pTirsData = NULL;
	else if (m_pNam8Data == pSubrecord)
		m_pNam8Data = NULL;
	else if (m_pSpctData == pSubrecord)
		m_pSpctData = NULL;
	else if (m_pDnamData == pSubrecord)
		m_pDnamData = NULL;
	else if (m_pNam7Data == pSubrecord)
		m_pNam7Data = NULL;
	else if (m_pPhtnData == pSubrecord)
		m_pPhtnData = NULL;
	else if (m_pWkmvData == pSubrecord)
		m_pWkmvData = NULL;
	else if (m_pRnmvData == pSubrecord)
		m_pRnmvData = NULL;
	else if (m_pSpedData == pSubrecord)
		m_pSpedData = NULL;
	else if (m_pFtsmData == pSubrecord)
		m_pFtsmData = NULL;
	else if (m_pDftmData == pSubrecord)
		m_pDftmData = NULL;
	else if (m_pRnamData == pSubrecord)
		m_pRnamData = NULL;

	else
		CSrRecord::OnDeleteSubrecord(pSubrecord);

}
/*===========================================================================
 *		End of Class Event CSrRaceRecord::OnDeleteSubrecord()
 *=========================================================================*/


/*===========================================================================
 *
 * Begin CSrRaceRecord Get Field Methods
 *
 *=========================================================================*/
/*===========================================================================
 *		End of CSrRaceRecord Get Field Methods
 *=========================================================================*/


/*===========================================================================
 *
 * Begin CSrRaceRecord Compare Field Methods
 *
 *=========================================================================*/
/*===========================================================================
 *		End of CSrRaceRecord Compare Field Methods
 *=========================================================================*/


/*===========================================================================
 *
 * Begin CSrRaceRecord Set Field Methods
 *
 *=========================================================================*/
/*===========================================================================
 *		End of CSrRaceRecord Set Field Methods
 *=========================================================================*/
