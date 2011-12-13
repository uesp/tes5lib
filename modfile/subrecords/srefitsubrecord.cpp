/*===========================================================================
 *
 * File:		Srefitsubrecord.CPP
 * Author:		Dave Humphrey (dave@uesp.net)
 * Created On:	12 December 2011
 *
 * Description
 *
 *=========================================================================*/

	/* Include Files */
#include "srefitsubrecord.h"


/*===========================================================================
 *
 * Class CSrEfitSubrecord Constructor
 *
 *=========================================================================*/
CSrEfitSubrecord::CSrEfitSubrecord () 
{
}
/*===========================================================================
 *		End of Class CSrEfitSubrecord Constructor
 *=========================================================================*/


/*===========================================================================
 *
 * Class CSrEfitSubrecord Method - void Destroy (void);
 *
 *=========================================================================*/
void CSrEfitSubrecord::Destroy (void) 
{
	CSrSubrecord::Destroy();
}
/*===========================================================================
 *		End of Class Method CSrEfitSubrecord::Destroy()
 *=========================================================================*/


/*===========================================================================
 *
 * Class CSrEfitSubrecord Method - void InitializeNew (void);
 *
 *=========================================================================*/
void CSrEfitSubrecord::InitializeNew (void) 
{
  CSrSubrecord::InitializeNew();

  m_Data.Magnitude  = 0;
  m_Data.Area       = 0;
  m_Data.Duration   = 0;

  m_RecordSize = SREFIT_SUBRECORD_SIZE;
}
/*===========================================================================
 *		End of Class Method CSrEfitSubrecord::InitializeNew()
 *=========================================================================*/

