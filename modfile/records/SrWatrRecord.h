/*===========================================================================
 *
 * File:		SrWatrrecord.H
 * Author:		Dave Humphrey (dave@uesp.net)
 * Created On:	5 December 2011
 *
 * Defines the CSrWatrRecord class.
 *
 *=========================================================================*/
#ifndef __SRWATRRECORD_H
#define __SRWATRRECORD_H


/*===========================================================================
 *
 * Begin Required Includes
 *
 *=========================================================================*/
  #include "srrecord.h"
/*===========================================================================
 *		End of Required Includes
 *=========================================================================*/


/*===========================================================================
 *
 * Begin Class CSrWatrRecord Definition
 *
 *=========================================================================*/
class CSrWatrRecord : public CSrRecord 
{
  DECLARE_SRSUBRECCREATE()
  DECLARE_SRFIELDMAP()
  DECLARE_SRCLASS(CSrWatrRecord, CSrRecord)

  /*---------- Begin Protected Class Members --------------------*/
protected:
  	CSrSubrecord*		m_pEdidData;
	CSrSubrecord*		m_pFnamData;
	CSrSubrecord*		m_pNnamData;
	CSrSubrecord*		m_pDataData;
	CSrSubrecord*		m_pAnamData;
	CSrSubrecord*		m_pTnamData;
	CSrSubrecord*		m_pNam1Data;
	CSrSubrecord*		m_pDnamData;
	CSrSubrecord*		m_pNam0Data;
	CSrSubrecord*		m_pGnamData;
	CSrSubrecord*		m_pMnamData;
	CSrSubrecord*		m_pSnamData;
	CSrSubrecord*		m_pFullData;



  /*---------- Begin Protected Class Methods --------------------*/
protected:


  /*---------- Begin Public Class Methods -----------------------*/
public:

	/* Class Constructors/Destructors */
  CSrWatrRecord();
  virtual void Destroy (void);

    	/* Return a new instance of the class */
  static CSrRecord* Create (void) { return new CSrWatrRecord; }

	/* Get class members */
  

	/* Initialize a new record */
  void InitializeNew (void);

	/* Called to alert record of a new subrecord being added */
  virtual void OnAddSubrecord    (CSrSubrecord* pSubrecord);
  virtual void OnDeleteSubrecord (CSrSubrecord* pSubrecord);


  /* Begin field method definitions */


};
/*===========================================================================
 *		End of Class CSrWatrRecord Definition
 *=========================================================================*/


#endif
/*===========================================================================
 *		End of File SrWatrRecord.H
 *=========================================================================*/
