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

		/* All flags not yet confirmed (some taken from Oblivion) */
	#define SR_MGEFFLAG_HOSTILE			0x00000001
    #define SR_MGEFFLAG_RECOVER			0x00000002
    #define SR_MGEFFLAG_DETRIMENTAL		0x00000004
    #define SR_MGEFFLAG_PERCENTMAG		0x00000008
    #define SR_MGEFFLAG_SELF			0x00000010
    #define SR_MGEFFLAG_00000100		0x00000100
    #define SR_MGEFFLAG_NOAREA			0x00000200
    #define SR_MGEFFLAG_FXPERSIST		0x00000400
    #define SR_MGEFFLAG_00000800		0x00000800
    #define SR_MGEFFLAG_00001000		0x00001000
	#define SR_MGEFFLAG_00004000		0x00004000
	#define SR_MGEFFLAG_00008000		0x00008000
    #define SR_MGEFFLAG_00020000		0x00020000
	#define SR_MGEFFLAG_BOUND			0x00040000
    #define SR_MGEFFLAG_04000000		0x04000000
    #define SR_MGEFFLAG_08000000		0x08000000
	#define SR_MGEFFLAG_10000000		0x10000000
	#define SR_MGEFFLAG_WARD			0x40000000

/*===========================================================================
 *		End of Definitions
 *=========================================================================*/


/*===========================================================================
 *
 * Begin Type Definitions
 * 
 *=========================================================================*/
#pragma pack(push, 1)

  struct srmgefdata_t 
  {
	  dword			Flags;
	  float			BaseCost;
	  srformid_t	SecondSpellID;
	  dword			School;
	  dword			EffectType;
	  dword			Unknown1;		//0xffff0000 flags?
	  srformid_t	LightID;
	  float			Unknown2;		//0-1
	  srformid_t	ShaderID1;		
	  srformid_t	ShaderID2;		
	  dword			SkillLevel;
	  dword			Unknown3;		//0-6000
	  float			CastingDelay;
	  float			Unknown4;		//0-2
	  float			Unknown5;		//0-5
	  float			Unknown6;		//0-2
	  int			Unknown7;		//0-43
	  int			ActorValue;		//-1-163
	  srformid_t	ProjectileID;
	  srformid_t	ExplosionID;	//Unknown8
	  int			CastType;		//0-2
	  dword			Unknown8;		//0-4
	  int			Unknown9;		//-1, 25-132
	  srformid_t	ArtID1;
	  srformid_t	ArtID2;
	  srformid_t	ImpactSetID1;
	  float			EffectPlayRate;	//0-10
	  srformid_t	DualID;			//Unknown11
	  float			Unknown10;		//0-3
	  srformid_t	ArtID3;			//Unknown13
	  dword			Unknown11;		//Zero
	  dword			Unknown12;		//Zero
	  srformid_t	ArtID4;			//Unknown16
	  srformid_t	ImpactSetID2;	//Unknown17
	  srformid_t	PerkID;			//Unknown18
	  dword			Unknown13;		//0-3
	  float			Unknown14;		//0, 50, 9999, 100000, 1000000
	  float			Unknown15;		//0, 60, 10000, 600000
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
  virtual bool ReadData  (CSrFile& File) { memset(&m_Data, 0, sizeof(m_Data)); SR_VERIFY_SUBRECORDSIZE_MAX(SR_MGEFDATA_SUBRECORD_SIZE) return File.Read(&m_Data,  m_RecordSize); }
  virtual bool WriteData (CSrFile& File) { SR_VERIFY_SUBRECORDSIZE_MAX(SR_MGEFDATA_SUBRECORD_SIZE) return File.Write(&m_Data, m_RecordSize); }


  /*---------- Begin Public Class Methods -----------------------*/
public:

	/* Class Constructors/Destructors */
  CSrMgefDataSubrecord() { }
  //virtual ~CSrMgefDataSubrecord() { Destroy(); }
  virtual void Destroy (void) { CSrSubrecord::Destroy(); }
  
   			/* Change any matching formid in the subrecord */
  virtual dword ChangeFormID (const srformid_t NewID, const srformid_t OldID) 
  {
	dword Count = 0;

	if (m_Data.SecondSpellID == OldID) 
	{
	  m_Data.SecondSpellID = NewID;
	  ++Count;
	}

	if (m_Data.ShaderID1 == OldID) 
	{
	  m_Data.ShaderID1 = NewID;
	  ++Count;
	}

	if (m_Data.ShaderID2 == OldID) 
	{
	  m_Data.ShaderID2 = NewID;
	  ++Count;
	}

	if (m_Data.ProjectileID == OldID) 
	{
	  m_Data.ProjectileID = NewID;
	  ++Count;
	}

	if (m_Data.ArtID1 == OldID) 
	{
	  m_Data.ArtID1 = NewID;
	  ++Count;
	}

	if (m_Data.ArtID2 == OldID) 
	{
	  m_Data.ArtID2 = NewID;
	  ++Count;
	}

	if (m_Data.ArtID3 == OldID) 
	{
	  m_Data.ArtID3 = NewID;
	  ++Count;
	}

	if (m_Data.ArtID4 == OldID) 
	{
	  m_Data.ArtID4 = NewID;
	  ++Count;
	}

	if (m_Data.PerkID == OldID) 
	{
	  m_Data.PerkID = NewID;
	  ++Count;
	}

	if (m_Data.ExplosionID == OldID) 
	{
	  m_Data.ExplosionID = NewID;
	  ++Count;
	}

	if (m_Data.DualID == OldID) 
	{
	  m_Data.DualID = NewID;
	  ++Count;
	}

	if (m_Data.ImpactSetID1 == OldID) 
	{
	  m_Data.ImpactSetID1 = NewID;
	  ++Count;
	}

	if (m_Data.ImpactSetID2 == OldID) 
	{
	  m_Data.ImpactSetID2 = NewID;
	  ++Count;
	}

	return Count; 
  }

  virtual dword CountUses (const srformid_t FormID) 
  {
	  return (FormID == m_Data.ImpactSetID1) + (FormID == m_Data.ArtID2) + (FormID == m_Data.ArtID1)
		   + (FormID == m_Data.ProjectileID) + (FormID == m_Data.ShaderID1) + (FormID == m_Data.SecondSpellID)
		   + (FormID == m_Data.ShaderID2) + (FormID == m_Data.ArtID3) + (FormID == m_Data.ArtID4)
		   + (FormID == m_Data.ImpactSetID2) + (FormID == m_Data.PerkID) + (FormID == m_Data.DualID)
		   + (FormID == m_Data.ExplosionID);
  }

		/* Fixup the modindex of formids */
  virtual bool FixupFormID (CSrFormidFixupArray& FixupArray) 
  {
	bool Result = SrFixupFormid(m_Data.SecondSpellID, m_Data.SecondSpellID, FixupArray);
	Result &= SrFixupFormid(m_Data.ShaderID1, m_Data.ShaderID1, FixupArray);
	Result &= SrFixupFormid(m_Data.ShaderID2, m_Data.ShaderID2, FixupArray);
	Result &= SrFixupFormid(m_Data.ProjectileID, m_Data.ProjectileID, FixupArray);
	Result &= SrFixupFormid(m_Data.ArtID1, m_Data.ArtID1, FixupArray);
	Result &= SrFixupFormid(m_Data.ArtID2, m_Data.ArtID2, FixupArray);
	Result &= SrFixupFormid(m_Data.ArtID3, m_Data.ArtID3, FixupArray);
	Result &= SrFixupFormid(m_Data.ArtID4, m_Data.ArtID4, FixupArray);
	Result &= SrFixupFormid(m_Data.ImpactSetID1, m_Data.ImpactSetID1, FixupArray);
	Result &= SrFixupFormid(m_Data.ImpactSetID2, m_Data.ImpactSetID2, FixupArray);
	Result &= SrFixupFormid(m_Data.PerkID, m_Data.PerkID, FixupArray);
	Result &= SrFixupFormid(m_Data.ExplosionID, m_Data.ExplosionID, FixupArray);
	Result &= SrFixupFormid(m_Data.DualID, m_Data.DualID, FixupArray);
	return Result;
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
  virtual CSrSubrecord* CreateV (void) { return new CSrMgefDataSubrecord; }

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
