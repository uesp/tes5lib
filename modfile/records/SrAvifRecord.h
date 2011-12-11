/*===========================================================================
 *
 * File:		SrAvifrecord.H
 * Author:		Dave Humphrey (dave@uesp.net)
 * Created On:	5 December 2011
 *
 * Defines the CSrAvifRecord class.
 *
 *=========================================================================*/
#ifndef __SRAVIFRECORD_H
#define __SRAVIFRECORD_H


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
 * Begin Class CSrAvifRecord Definition
 *
 *=========================================================================*/
class CSrAvifRecord : public CSrIdRecord 
{
  DECLARE_SRSUBRECCREATE()
  DECLARE_SRFIELDMAP()
  DECLARE_SRCLASS(CSrAvifRecord, CSrIdRecord)

  /*---------- Begin Protected Class Members --------------------*/
protected:
	CSrSubrecord*		m_pAvskData;
	CSrSubrecord*		m_pFnamData;
	CSrSubrecord*		m_pFullData;
	CSrSubrecord*		m_pCnamData;
	CSrSubrecord*		m_pDescData;
	CSrSubrecord*		m_pXnamData;
	CSrSubrecord*		m_pPnamData;
	CSrSubrecord*		m_pYnamData;
	CSrSubrecord*		m_pHnamData;
	CSrSubrecord*		m_pVnamData;
	CSrSubrecord*		m_pSnamData;
	CSrSubrecord*		m_pInamData;
	CSrSubrecord*		m_pAnamData;



  /*---------- Begin Protected Class Methods --------------------*/
protected:


  /*---------- Begin Public Class Methods -----------------------*/
public:

	/* Class Constructors/Destructors */
  CSrAvifRecord();
  virtual void Destroy (void);

    	/* Return a new instance of the class */
  static CSrRecord* Create (void) { return new CSrAvifRecord; }

	/* Get class members */
  

	/* Initialize a new record */
  void InitializeNew (void);

	/* Called to alert record of a new subrecord being added */
  virtual void OnAddSubrecord    (CSrSubrecord* pSubrecord);
  virtual void OnDeleteSubrecord (CSrSubrecord* pSubrecord);


  /* Begin field method definitions */


};
/*===========================================================================
 *		End of Class CSrAvifRecord Definition
 *=========================================================================*/


#endif
/*===========================================================================
 *		End of File SrAvifRecord.H
 *=========================================================================*/
