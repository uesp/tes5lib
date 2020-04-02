/*===========================================================================
 *
 * File:		SrRefrdatasubrecord.H
 * Author:		Dave Humphrey (dave@uesp.net)
 * Created On:	15 February 2012
 *
 * Description
 *
 *=========================================================================*/
#ifndef __SRREFRDATASUBRECORD_H
#define __SRREFRDATASUBRECORD_H


/*===========================================================================
 *
 * Begin Required Includes
 *
 *=========================================================================*/
	#include "srsubrecord.h"
/*===========================================================================
 *		End of Required Includes
 *=========================================================================*/


/*===========================================================================
 *
 * Begin Definitions
 *
 *=========================================================================*/

  #define SR_REFRDATA_SUBRECORD_SIZE	24

/*===========================================================================
 *		End of Definitions
 *=========================================================================*/


/*===========================================================================
 *
 * Begin Type Definitions
 *
 *=========================================================================*/
#pragma pack(push, 1)

	struct srrefrdata_t 
	{
		float		X;
		float		Y;
		float		Z;
		float		rX;
		float		rY;
		float		rZ;

	};

#pragma pack(pop)
/*===========================================================================
 *		End of Type Definitions
 *=========================================================================*/


/*===========================================================================
 *
 * Begin Class CSrRefrDataSubrecord Definition
 *
 * Description
 *
 *=========================================================================*/
class CSrRefrDataSubrecord : public CSrSubrecord 
{
	DECLARE_SRCLASS(CSrRefrDataSubrecord, CSrSubrecord)

  /*---------- Begin Protected Class Members --------------------*/
protected:
	srrefrdata_t	m_Data;


  /*---------- Begin Protected Class Methods --------------------*/
protected:

		/* Input/output the subrecord data */
	virtual bool ReadData  (CSrFile& File) { SR_VERIFY_SUBRECORDSIZE(SR_REFRDATA_SUBRECORD_SIZE) return File.Read(&m_Data, SR_REFRDATA_SUBRECORD_SIZE); }
	virtual bool WriteData (CSrFile& File) { SR_VERIFY_SUBRECORDSIZE(SR_REFRDATA_SUBRECORD_SIZE) return File.Write(&m_Data, SR_REFRDATA_SUBRECORD_SIZE); }


  /*---------- Begin Public Class Methods -----------------------*/
public:

		/* Class Constructors/Destructors */
	CSrRefrDataSubrecord() { }
	virtual void Destroy (void) { CSrSubrecord::Destroy(); }

 		/* Copy the content from an existing subrecord */
	virtual bool Copy (CSrSubrecord* pSubrecord) 
	{
		CSrRefrDataSubrecord* pSubrecord1 = SrCastClassNull(CSrRefrDataSubrecord, pSubrecord);
		m_RecordSize = SR_REFRDATA_SUBRECORD_SIZE;

		if (pSubrecord1 != NULL)
			m_Data = pSubrecord1->m_Data;
		else
			memset(&m_Data, 0, sizeof(m_Data));
	
		return (true);
	}

  		/* Create a class instance */
	static  CSrSubrecord* Create (void) { return new CSrRefrDataSubrecord; }
	virtual CSrSubrecord* CreateV (void) { return new CSrRefrDataSubrecord; }

		/* Get class members */
	srrefrdata_t&  GetRefrData (void) { return (m_Data); }
	virtual byte*  GetData     (void) { return (byte *)(&m_Data); }
  
		/* Initialize a new record */
	void InitializeNew (void) { CSrSubrecord::InitializeNew(); memset(&m_Data, 0, sizeof(m_Data)); m_RecordSize = SR_REFRDATA_SUBRECORD_SIZE; }
   
};
/*===========================================================================
 *		End of Class CSrRefrDataSubrecord Definition
 *=========================================================================*/


#endif
/*===========================================================================
 *		End of File SrAlchdatasubrecord.H
 *=========================================================================*/
