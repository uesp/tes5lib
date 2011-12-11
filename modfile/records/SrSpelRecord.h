/*===========================================================================
 *
 * File:		SrSpelrecord.H
 * Author:		Dave Humphrey (dave@uesp.net)
 * Created On:	5 December 2011
 *
 * Defines the CSrSpelRecord class.
 *
 *=========================================================================*/
#ifndef __SRSPELRECORD_H
#define __SRSPELRECORD_H


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
 * Begin Class CSrSpelRecord Definition
 *
 *=========================================================================*/
class CSrSpelRecord : public CSrRecord 
{
  DECLARE_SRSUBRECCREATE()
  DECLARE_SRFIELDMAP()
  DECLARE_SRCLASS(CSrSpelRecord, CSrRecord)

  /*---------- Begin Protected Class Members --------------------*/
protected:
  	CSrSubrecord*		m_pEdidData;
	CSrSubrecord*		m_pEfidData;
	CSrSubrecord*		m_pEtypData;
	CSrSubrecord*		m_pObndData;
	CSrSubrecord*		m_pFullData;
	CSrSubrecord*		m_pDescData;
	CSrSubrecord*		m_pSpitData;
	CSrSubrecord*		m_pEfitData;
	CSrSubrecord*		m_pMdobData;
	CSrSubrecord*		m_pCtdaData;
	CSrSubrecord*		m_pCis2Data;



  /*---------- Begin Protected Class Methods --------------------*/
protected:


  /*---------- Begin Public Class Methods -----------------------*/
public:

	/* Class Constructors/Destructors */
  CSrSpelRecord();
  virtual void Destroy (void);

    	/* Return a new instance of the class */
  static CSrRecord* Create (void) { return new CSrSpelRecord; }

	/* Get class members */
  

	/* Initialize a new record */
  void InitializeNew (void);

	/* Called to alert record of a new subrecord being added */
  virtual void OnAddSubrecord    (CSrSubrecord* pSubrecord);
  virtual void OnDeleteSubrecord (CSrSubrecord* pSubrecord);


  /* Begin field method definitions */


};
/*===========================================================================
 *		End of Class CSrSpelRecord Definition
 *=========================================================================*/


#endif
/*===========================================================================
 *		End of File SrSpelRecord.H
 *=========================================================================*/
