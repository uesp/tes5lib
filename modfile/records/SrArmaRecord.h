/*===========================================================================
 *
 * File:		SrArmarecord.H
 * Author:		Dave Humphrey (dave@uesp.net)
 * Created On:	5 December 2011
 *
 * Defines the CSrArmaRecord class.
 *
 *=========================================================================*/
#ifndef __SRARMARECORD_H
#define __SRARMARECORD_H


/*===========================================================================
 *
 * Begin Required Includes
 *
 *=========================================================================*/
  #include "sridrecord.h"
/*===========================================================================
 *		End of Required Includes
 *=========================================================================*/


/*===========================================================================
 *
 * Begin Class CSrArmaRecord Definition
 *
 *=========================================================================*/
class CSrArmaRecord : public CSrIdRecord 
{
  DECLARE_SRSUBRECCREATE()
  DECLARE_SRFIELDMAP()
  DECLARE_SRCLASS(CSrArmaRecord, CSrIdRecord)

  /*---------- Begin Protected Class Members --------------------*/
protected:
  	CSrSubrecord*		m_pModlData;
	CSrSubrecord*		m_pMod4Data;
	CSrSubrecord*		m_pBodtData;
	CSrSubrecord*		m_pMod3Data;
	CSrSubrecord*		m_pRnamData;
	CSrSubrecord*		m_pMod2Data;
	CSrSubrecord*		m_pDnamData;
	CSrSubrecord*		m_pMo2tData;
	CSrSubrecord*		m_pMo3tData;
	CSrSubrecord*		m_pMo3sData;
	CSrSubrecord*		m_pMo2sData;
	CSrSubrecord*		m_pNam0Data;
	CSrSubrecord*		m_pMo4sData;
	CSrSubrecord*		m_pSnddData;
	CSrSubrecord*		m_pNam1Data;
	CSrSubrecord*		m_pMo5tData;
	CSrSubrecord*		m_pMo4tData;
	CSrSubrecord*		m_pMod5Data;
	CSrSubrecord*		m_pNam2Data;
	CSrSubrecord*		m_pNam3Data;


  /*---------- Begin Protected Class Methods --------------------*/
protected:


  /*---------- Begin Public Class Methods -----------------------*/
public:

	/* Class Constructors/Destructors */
  CSrArmaRecord();
  virtual void Destroy (void);

    	/* Return a new instance of the class */
  static CSrRecord* Create (void) { return new CSrArmaRecord; }

	/* Get class members */
  

	/* Initialize a new record */
  void InitializeNew (void);

	/* Called to alert record of a new subrecord being added */
  virtual void OnAddSubrecord    (CSrSubrecord* pSubrecord);
  virtual void OnDeleteSubrecord (CSrSubrecord* pSubrecord);


  /* Begin field method definitions */


};
/*===========================================================================
 *		End of Class CSrArmaRecord Definition
 *=========================================================================*/


#endif
/*===========================================================================
 *		End of File SrArmaRecord.H
 *=========================================================================*/
