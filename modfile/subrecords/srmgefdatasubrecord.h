/*===========================================================================
 *
 * File:		Srmgefdatasubrecord.H
 * Author:		Dave Humphrey (dave@uesp.net)
 * Created On:	1 December 2011
 *
 * Description
 *
 *=========================================================================*/
#ifndef __SRMGEFDATASUBRECORD_H
#define __SRMGEFDATASUBRECORD_H


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

  #define SR_MGEFDATA_SUBRECORD_SIZE	152

/*===========================================================================
 *		End of Definitions
 *=========================================================================*/


/*===========================================================================
 *
 * Begin Type Definitions
 * 
 *=========================================================================*/
#pragma pack(push, 1)

  struct srmgefdata_t {
	  dword			Unknown1;
	  dword			Unknown2;
	  srformid_t	SecondSpellID;
	  dword			School;
	  dword			EffectType;
	  dword			Unknown3;
	  srformid_t	LightID;
	  dword			Unknown4;
	  srformid_t	ShaderID;
	  dword			Unknown5;
	  dword			Unknown6;
	  dword			Unknown7;
	  dword			Unknown8;
	  dword			Unknown9;
	  dword			Unknown10;
	  dword			Unknown11;
	  dword			Unknown12;
	  dword			Unknown13;
	  srformid_t	ProjectileID;
	  dword			Unknown14;
	  dword			Unknown15;
	  dword			Unknown16;
	  dword			Unknown17;
	  srformid_t	ArtID;
	  dword			Unknown18;
	  srformid_t	ImpactSetID;
	  dword			Unknown19[12];
  };

#pragma pack(pop)
/*===========================================================================
 *		End of Type Definitions
 *=========================================================================*/


/*===========================================================================
 *
 * Begin Class CSrMgefDataSubrecord Definition
 *
 * Description
 *
 *=========================================================================*/
class CSrMgefDataSubrecord : public CSrSubrecord {
  DECLARE_SRCLASS(CSrMgefDataSubrecord, CSrSubrecord)

  /*---------- Begin Protected Class Members --------------------*/
protected:
  srmgefdata_t	m_Data;


  /*---------- Begin Protected Class Methods --------------------*/
protected:

	/* Input/output the subrecord data */
  virtual bool ReadData  (CSrFile& File) { memset(&m_Data, 0, sizeof(m_Data)); return File.Read(&m_Data,  m_RecordSize); }
  virtual bool WriteData (CSrFile& File) { return File.Write(&m_Data, m_RecordSize); }


  /*---------- Begin Public Class Methods -----------------------*/
public:

	/* Class Constructors/Destructors */
  CSrMgefDataSubrecord() { }
  //virtual ~CSrMgefDataSubrecord() { Destroy(); }
  virtual void Destroy (void) { CSrSubrecord::Destroy(); }
  
  	/* Change any matching formid in the subrecord */
  virtual dword ChangeFormID (const srformid_t NewID, const srformid_t OldID) { 
       
	return (0);
  }

 	/* Copy the content from an existing subrecord */
  virtual bool Copy (CSrSubrecord* pSubrecord) {
	CSrMgefDataSubrecord* pSubrecord1 = SrCastClassNull(CSrMgefDataSubrecord, pSubrecord);
	m_RecordSize = SR_MGEFDATA_SUBRECORD_SIZE;

	if (pSubrecord1 != NULL) {
	  m_Data = pSubrecord1->GetEffectData();
	}
	else {
	  memset(&m_Data, 0, sizeof(m_Data));
	}
	return (true);
  }

  	/* Create a class instance */
  static CSrSubrecord* Create (void) { return (new CSrMgefDataSubrecord); }

  	/* Fixup the modindex of formids */
  virtual bool FixupFormID (CSrFormidFixupArray& FixupArray) {
	return true;
  }

	/* Get class members */
  srmgefdata_t& GetEffectData (void) { return (m_Data); }
  virtual byte*	GetData       (void) { return (byte *)(&m_Data); }
    
	/* Initialize a new record */
  void InitializeNew (void) { CSrSubrecord::InitializeNew(); memset(&m_Data, 0, sizeof(m_Data)); m_RecordSize = SR_MGEFDATA_SUBRECORD_SIZE; }

	/* Set class members */

};
/*===========================================================================
 *		End of Class CSrMgefDataSubrecord Definition
 *=========================================================================*/


#endif
/*===========================================================================
 *		End of File SrMgefDatasubrecord.H
 *=========================================================================*/
