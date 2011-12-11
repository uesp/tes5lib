/*===========================================================================
 *
 * File:		SrEnchrecord.H
 * Author:		Dave Humphrey (dave@uesp.net)
 * Created On:	5 December 2011
 *
 * Defines the CSrEnchRecord class.
 *
 *=========================================================================*/
#ifndef __SRENCHRECORD_H
#define __SRENCHRECORD_H


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
 * Begin Class CSrEnchRecord Definition
 *
 *=========================================================================*/
class CSrEnchRecord : public CSrIdRecord 
{
  DECLARE_SRSUBRECCREATE()
  DECLARE_SRFIELDMAP()
  DECLARE_SRCLASS(CSrEnchRecord, CSrIdRecord)

  /*---------- Begin Protected Class Members --------------------*/
protected:
  	CSrSubrecord*		m_pEfidData;
	CSrSubrecord*		m_pObndData;
	CSrSubrecord*		m_pCis2Data;
	CSrSubrecord*		m_pFullData;
	CSrSubrecord*		m_pCtdaData;
	CSrSubrecord*		m_pEfitData;
	CSrSubrecord*		m_pEnitData;


  /*---------- Begin Protected Class Methods --------------------*/
protected:


  /*---------- Begin Public Class Methods -----------------------*/
public:

	/* Class Constructors/Destructors */
  CSrEnchRecord();
  virtual void Destroy (void);

    	/* Return a new instance of the class */
  static CSrRecord* Create (void) { return new CSrEnchRecord; }

	/* Get class members */
  

	/* Initialize a new record */
  void InitializeNew (void);

	/* Called to alert record of a new subrecord being added */
  virtual void OnAddSubrecord    (CSrSubrecord* pSubrecord);
  virtual void OnDeleteSubrecord (CSrSubrecord* pSubrecord);


  /* Begin field method definitions */


};
/*===========================================================================
 *		End of Class CSrEnchRecord Definition
 *=========================================================================*/


#endif
/*===========================================================================
 *		End of File SrEnchRecord.H
 *=========================================================================*/
