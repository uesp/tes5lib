/*===========================================================================
 *
 * File:		SrRacerecord.H
 * Author:		Dave Humphrey (dave@uesp.net)
 * Created On:	5 December 2011
 *
 * Defines the CSrRaceRecord class.
 *
 *=========================================================================*/
#ifndef __SRRACERECORD_H
#define __SRRACERECORD_H


/*===========================================================================
 *
 * Begin Required Includes
 *
 *=========================================================================*/
	#include "sridkeyrecord.h"
	#include "../subrecords/srlstringsubrecord.h"
/*===========================================================================
 *		End of Required Includes
 *=========================================================================*/


/*===========================================================================
 *
 * Begin Class CSrRaceRecord Definition
 *
 *=========================================================================*/
class CSrRaceRecord : public CSrIdKeyRecord 
{
  DECLARE_SRSUBRECCREATE()
  DECLARE_SRFIELDMAP()
  DECLARE_SRCLASS(CSrRaceRecord, CSrIdKeyRecord)

  /*---------- Begin Protected Class Members --------------------*/
protected:
	CSrSubrecord*		m_pTintData;
	CSrSubrecord*		m_pFnamData;
	CSrSubrecord*		m_pFtsfData;
	CSrSubrecord*		m_pTinpData;
	CSrLStringSubrecord*	m_pDescription;
	CSrLStringSubrecord*	m_pItemName;
	CSrSubrecord*		m_pIndxData;
	CSrSubrecord*		m_pFullData;
	CSrSubrecord*		m_pWnamData;
	CSrSubrecord*		m_pDataData;
	CSrSubrecord*		m_pRprmData;
	CSrSubrecord*		m_pHclfData;
	CSrSubrecord*		m_pAnamData;
	CSrSubrecord*		m_pBodtData;
	CSrSubrecord*		m_pMnamData;
	CSrSubrecord*		m_pLnamData;
	CSrSubrecord*		m_pModtData;
	CSrSubrecord*		m_pMtnmData;
	CSrSubrecord*		m_pVtckData;
	CSrSubrecord*		m_pRprfData;
	CSrSubrecord*		m_pPnamData;
	CSrSubrecord*		m_pUnamData;
	CSrSubrecord*		m_pAtkdData;
	CSrSubrecord*		m_pDftfData;
	CSrSubrecord*		m_pMtypData;
	CSrSubrecord*		m_pAtkeData;
	CSrSubrecord*		m_pNam1Data;
	CSrSubrecord*		m_pModlData;
	CSrSubrecord*		m_pAhcfData;
	CSrSubrecord*		m_pGnamData;
	CSrSubrecord*		m_pPhwtData;
	CSrSubrecord*		m_pNam3Data;
	CSrSubrecord*		m_pNam4Data;
	CSrSubrecord*		m_pMpavData;
	CSrSubrecord*		m_pNam5Data;
	CSrSubrecord*		m_pSnmvData;
	CSrSubrecord*		m_pSwmvData;
	CSrSubrecord*		m_pNam0Data;
	CSrSubrecord*		m_pUnesData;
	CSrSubrecord*		m_pOnamData;
	CSrSubrecord*		m_pFlmvData;
	CSrSubrecord*		m_pNameData;
	CSrSubrecord*		m_pVnamData;
	CSrSubrecord*		m_pQnamData;
	CSrSubrecord*		m_pTinlData;
	CSrSubrecord*		m_pHeadData;
	CSrSubrecord*		m_pMpaiData;
	CSrSubrecord*		m_pAhcmData;
	CSrSubrecord*		m_pTiniData;
	CSrSubrecord*		m_pTindData;
	CSrSubrecord*		m_pSploData;
	CSrSubrecord*		m_pTincData;
	CSrSubrecord*		m_pTinvData;
	CSrSubrecord*		m_pTirsData;
	CSrSubrecord*		m_pNam8Data;
	CSrSubrecord*		m_pSpctData;
	CSrSubrecord*		m_pDnamData;
	CSrSubrecord*		m_pNam7Data;
	CSrSubrecord*		m_pPhtnData;
	CSrSubrecord*		m_pWkmvData;
	CSrSubrecord*		m_pRnmvData;
	CSrSubrecord*		m_pSpedData;
	CSrSubrecord*		m_pFtsmData;
	CSrSubrecord*		m_pDftmData;
	CSrSubrecord*		m_pRnamData;



  /*---------- Begin Protected Class Methods --------------------*/
protected:


  /*---------- Begin Public Class Methods -----------------------*/
public:

	/* Class Constructors/Destructors */
  CSrRaceRecord();
  virtual void Destroy (void);

    	/* Return a new instance of the class */
  static CSrRecord* Create (void) { return new CSrRaceRecord; }

	/* Get class members */
  

	/* Initialize a new record */
  void InitializeNew (void);

	/* Called to alert record of a new subrecord being added */
  virtual void OnAddSubrecord    (CSrSubrecord* pSubrecord);
  virtual void OnDeleteSubrecord (CSrSubrecord* pSubrecord);


		/* Begin field method definitions */

	DECLARE_SRFIELD_DESCRIPTION(CSrRaceRecord, SR_NAME_DESC)
	DECLARE_SRFIELD_ITEMNAME(CSrRaceRecord)
};
/*===========================================================================
 *		End of Class CSrRaceRecord Definition
 *=========================================================================*/


#endif
/*===========================================================================
 *		End of File SrRaceRecord.H
 *=========================================================================*/
