/*===========================================================================
 *
 * File:		SrCtdtsubrecord.H
 * Author:		Dave Humphrey (dave@uesp.net)
 * Created On:	2 December 2011
 *
 * Description
 *
 *=========================================================================*/
#ifndef __SRCTDTSUBRECORD_H
#define __SRCTDTSUBRECORD_H


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

	#define SR_CTDA_SUBRECORD_SIZE	32

	#define SR_CTDA_FUNCOFFSET 4096	

	#define SR_CTDA_FLAG_OR				0x01
	#define SR_CTDA_FLAG_RUNONTARGET	0x02
	#define SR_CTDA_FLAG_USEGLOBAL		0x04

/*===========================================================================
 *		End of Definitions
 *=========================================================================*/


/*===========================================================================
 *
 * Begin Type Definitions
 *
 *=========================================================================*/
#pragma pack(push, 1)

  struct srctdtdata_t 
  {
	byte		Flags		: 4;
	byte		CompareType : 4;
	byte		Unknown1[3] ;
	float		Value;
	word		Function;
	word		Unknown2;
	long		Parameter1;
	long		Parameter2;
	dword		Unknown3;
	srformid_t	RefID;
	dword		Unknown4;
  };

#pragma pack(pop)
/*===========================================================================
 *		End of Type Definitions
 *=========================================================================*/


/*===========================================================================
 *
 * Begin Class CSrCtdaSubrecord Definition
 *
 * Description
 *
 *=========================================================================*/
class CSrCtdaSubrecord : public CSrSubrecord {
  DECLARE_SRCLASS(CSrCtdaSubrecord, CSrSubrecord)

  /*---------- Begin Protected Class Members --------------------*/
protected:
  srctdtdata_t	m_Data;


  /*---------- Begin Protected Class Methods --------------------*/
protected:

  bool IsRefParam1 (const int FunctionCode);
  bool IsRefParam2 (const int FunctionCode);

	/* Input/output the subrecord data */
  virtual bool ReadData  (CSrFile& File) { SR_VERIFY_SUBRECORDSIZE(SR_CTDA_SUBRECORD_SIZE) return File.Read(&m_Data,  SR_CTDA_SUBRECORD_SIZE); }
  virtual bool WriteData (CSrFile& File) { SR_VERIFY_SUBRECORDSIZE(SR_CTDA_SUBRECORD_SIZE) return File.Write(&m_Data, SR_CTDA_SUBRECORD_SIZE); }

  /*---------- Begin Public Class Methods -----------------------*/
public:

	/* Class Constructors/Destructors */
  CSrCtdaSubrecord() { }
  //virtual ~CSrCtdaSubrecord() { Destroy(); }
  virtual void Destroy (void) { CSrSubrecord::Destroy(); }

  	/* Change any matching formid in the subrecord */
  virtual dword ChangeFormID (const srformid_t NewID, const srformid_t OldID);
  virtual dword CountUses (const srformid_t FormID);

	/* Field functions */
  bool CompareFields (int& Result, const int FieldID, CSrSubrecord* pSubrecord);
  bool GetField      (CSString& Buffer, const int FieldID);
  
	/* Copy the content from an existing subrecord */
  virtual bool Copy (CSrSubrecord* pSubrecord) {
	CSrCtdaSubrecord* pSubrecord1 = SrCastClassNull(CSrCtdaSubrecord, pSubrecord);
	m_RecordSize = SR_CTDA_SUBRECORD_SIZE;

	if (pSubrecord1 != NULL) {
	  m_Data = pSubrecord1->GetCtdtData();
	}
	else {
	  memset(&m_Data, 0, sizeof(m_Data));
	}
	return (true);
  }

  	/* Create a class instance */
  static CSrSubrecord* Create (void) { return (new CSrCtdaSubrecord); }
  virtual CSrSubrecord* CreateV (void) { return new CSrCtdaSubrecord; }

    	/* Fixup the modindex of formids */
  virtual bool FixupFormID (CSrFormidFixupArray& FixupArray);

	/* Get class members */
  srctdtdata_t& GetCtdtData (void) { return (m_Data); }
  virtual byte*	GetData     (void) { return (byte *)(&m_Data); }
   
	/* Initialize a new record */
  void InitializeNew (void) { CSrSubrecord::InitializeNew(); memset(&m_Data, 0, sizeof(m_Data)); m_RecordSize = SR_CTDA_SUBRECORD_SIZE; }

	/* Set class members */

};
/*===========================================================================
 *		End of Class CSrCtdaSubrecord Definition
 *=========================================================================*/


#endif
/*===========================================================================
 *		End of File SrCtdasubrecord.H
 *=========================================================================*/
