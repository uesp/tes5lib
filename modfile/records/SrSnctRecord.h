/*===========================================================================
 *
 * File:		SrSnctrecord.H
 * Author:		Dave Humphrey (dave@uesp.net)
 * Created On:	5 December 2011
 *
 * Defines the CSrSnctRecord class.
 *
 *=========================================================================*/
#ifndef __SRSNCTRECORD_H
#define __SRSNCTRECORD_H


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
 * Begin Class CSrSnctRecord Definition
 *
 *=========================================================================*/
class CSrSnctRecord : public CSrRecord 
{
  DECLARE_SRSUBRECCREATE()
  DECLARE_SRFIELDMAP()
  DECLARE_SRCLASS(CSrSnctRecord, CSrRecord)

  /*---------- Begin Protected Class Members --------------------*/
protected:
  	CSrSubrecord*		m_pVnamData;
	CSrSubrecord*		m_pFnamData;
	CSrSubrecord*		m_pEdidData;
	CSrSubrecord*		m_pFullData;
	CSrSubrecord*		m_pPnamData;
	CSrSubrecord*		m_pUnamData;



  /*---------- Begin Protected Class Methods --------------------*/
protected:


  /*---------- Begin Public Class Methods -----------------------*/
public:

	/* Class Constructors/Destructors */
  CSrSnctRecord();
  virtual void Destroy (void);

    	/* Return a new instance of the class */
  static CSrRecord* Create (void) { return new CSrSnctRecord; }

	/* Get class members */
  

	/* Initialize a new record */
  void InitializeNew (void);

	/* Called to alert record of a new subrecord being added */
  virtual void OnAddSubrecord    (CSrSubrecord* pSubrecord);
  virtual void OnDeleteSubrecord (CSrSubrecord* pSubrecord);


  /* Begin field method definitions */


};
/*===========================================================================
 *		End of Class CSrSnctRecord Definition
 *=========================================================================*/


#endif
/*===========================================================================
 *		End of File SrSnctRecord.H
 *=========================================================================*/
