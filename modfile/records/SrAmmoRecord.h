/*===========================================================================
 *
 * File:		SrAmmorecord.H
 * Author:		Dave Humphrey (dave@uesp.net)
 * Created On:	5 December 2011
 *
 * Defines the CSrAmmoRecord class.
 *
 *=========================================================================*/
#ifndef __SRAMMORECORD_H
#define __SRAMMORECORD_H


/*===========================================================================
 *
 * Begin Required Includes
 *
 *=========================================================================*/
  #include "sritem1record.h"
/*===========================================================================
 *		End of Required Includes
 *=========================================================================*/


/*===========================================================================
 *
 * Begin Class CSrAmmoRecord Definition
 *
 *=========================================================================*/
class CSrAmmoRecord : public CSrItem1Record 
{
  DECLARE_SRSUBRECCREATE()
  DECLARE_SRFIELDMAP()
  DECLARE_SRCLASS(CSrAmmoRecord, CSrItem1Record)

  /*---------- Begin Protected Class Members --------------------*/
protected:
  	CSrSubrecord*		m_pObndData;
	CSrSubrecord*		m_pDescData;
	CSrSubrecord*		m_pDataData;
	CSrSubrecord*		m_pYnamData;
	CSrSubrecord*		m_pZnamData;
	CSrSubrecord*		m_pModtData;


  /*---------- Begin Protected Class Methods --------------------*/
protected:


  /*---------- Begin Public Class Methods -----------------------*/
public:

	/* Class Constructors/Destructors */
  CSrAmmoRecord();
  virtual void Destroy (void);

    	/* Return a new instance of the class */
  static CSrRecord* Create (void) { return new CSrAmmoRecord; }

	/* Get class members */
  

	/* Initialize a new record */
  void InitializeNew (void);

	/* Called to alert record of a new subrecord being added */
  virtual void OnAddSubrecord    (CSrSubrecord* pSubrecord);
  virtual void OnDeleteSubrecord (CSrSubrecord* pSubrecord);


  /* Begin field method definitions */


};
/*===========================================================================
 *		End of Class CSrAmmoRecord Definition
 *=========================================================================*/


#endif
/*===========================================================================
 *		End of File SrAmmoRecord.H
 *=========================================================================*/
