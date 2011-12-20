/*===========================================================================
 *
 * File:		SrMgefRecord.H
 * Author:		Dave Humphrey (dave@uesp.net)
 * Created On:	1 December 2011
 *
 * Defines the CSrMgefRecord class for magic effect records.
 *
 *=========================================================================*/
#ifndef __SRMGEFRECORD_H
#define __SRMGEFRECORD_H


/*===========================================================================
 *
 * Begin Required Includes
 *
 *=========================================================================*/
  #include "sridkeyrecord.h"
  #include "../subrecords/srmgefdatasubrecord.h"
  #include "../subrecords/srlstringsubrecord.h"
  #include "../subrecords/srctdasubrecord.h"
/*===========================================================================
 *		End of Required Includes
 *=========================================================================*/


/*===========================================================================
 *
 * Begin Type Definitions
 *
 *=========================================================================*/

/*===========================================================================
 *		End of Type Definitions
 *=========================================================================*/


/*===========================================================================
 *
 * Begin Class CSrMgefRecord Definition
 *
 * Holds magic effect data.
 *
 *=========================================================================*/
class CSrMgefRecord : public CSrIdKeyRecord {
  DECLARE_SRSUBRECCREATE()
  DECLARE_SRFIELDMAP()
  DECLARE_SRCLASS(CSrMgefRecord, CSrIdKeyRecord)
  
  /*---------- Begin Protected Class Members --------------------*/
protected:
  CSrMgefDataSubrecord*	m_pData;
  CSrLStringSubrecord*	m_pFullName;
  CSrLStringSubrecord*	m_pDescription;

  static srmgefdata_t s_SrNullEffectData;


  /*---------- Begin Protected Class Methods --------------------*/
protected:


  /*---------- Begin Public Class Methods -----------------------*/
public:

		/* Class Constructors/Destructors */
  CSrMgefRecord();
  virtual void Destroy (void);

  		/* Return a new instance of the class */
  static CSrRecord* Create (void) { return new CSrMgefRecord; }

		/* Get class members */
  srmgefdata_t& GetEffectData  (void) { return m_pData ? m_pData->GetEffectData() : s_SrNullEffectData; }
  const char*   GetFullName    (void) { return m_pFullName ? m_pFullName->GetString().c_str() : ""; }
  const char*   GetDescription (void) { return m_pDescription ? m_pDescription->GetString().c_str() : ""; }
  dword			GetSchool	   (void) { return GetEffectData().School; }
  dword			GetEffectType  (void) { return GetEffectData().EffectType; }
  dword			GetConditionCount (void) { return CountSubrecords(SR_NAME_CTDA); }

		/* Initialize a new record */
  void InitializeNew (void);

		/* Called to alert record of a new subrecord being added */
  virtual void OnAddSubrecord    (CSrSubrecord* pSubrecord);
  virtual void OnDeleteSubrecord (CSrSubrecord* pSubrecord);

		/* Set class members */
  void SetFullName    (const char* pString) { if (m_pFullName) m_pFullName->SetString(pString); }
  void SetDescription (const char* pString) { if (m_pDescription) m_pDescription->SetString(pString); }

		/* Begin field method definitions */
	DECLARE_SRFIELD(FieldFullName)
	DECLARE_SRFIELD(FieldDescription)
	DECLARE_SRFIELD(FieldSchool)
	DECLARE_SRFIELD(FieldEffectType)
	DECLARE_SRFIELD(FieldConditionCount)
	DECLARE_SRFIELD(FieldSkillLevel)
	DECLARE_SRFIELD(FieldCastingDelay)
	DECLARE_SRFIELD(FieldUserData)
	DECLARE_SRFIELD(FieldMagicFlags)
	DECLARE_SRFIELD(FieldBaseCost)

	DECLARE_SRFIELD_EDITORID(CSrMgefRecord, SecondSpell, GetSecondSpell, SetSecondSpell)
	DECLARE_SRMETHOD_FORMID1(SecondSpell, GetEffectData().SecondSpellID)

	DECLARE_SRFIELD_EDITORID(CSrMgefRecord, Light, GetLight, SetLight)
	DECLARE_SRMETHOD_FORMID1(Light, GetEffectData().LightID)

	DECLARE_SRFIELD_EDITORID(CSrMgefRecord, Shader1, GetShader1, SetShader1)
	DECLARE_SRMETHOD_FORMID1(Shader1, GetEffectData().ShaderID1)

	DECLARE_SRFIELD_EDITORID(CSrMgefRecord, Shader2, GetShader2, SetShader2)
	DECLARE_SRMETHOD_FORMID1(Shader2, GetEffectData().ShaderID2)

	DECLARE_SRFIELD_EDITORID(CSrMgefRecord, Projectile, GetProjectile, SetProjectile)
	DECLARE_SRMETHOD_FORMID1(Projectile, GetEffectData().ProjectileID)

	DECLARE_SRFIELD_EDITORID(CSrMgefRecord, Explosion, GetExplosion, SetExplosion)
	DECLARE_SRMETHOD_FORMID1(Explosion, GetEffectData().ExplosionID)

	DECLARE_SRFIELD_EDITORID(CSrMgefRecord, Dual, GetDual, SetDual)
	DECLARE_SRMETHOD_FORMID1(Dual, GetEffectData().DualID)

	DECLARE_SRFIELD_EDITORID(CSrMgefRecord, ImpactSet1, GetImpactSet1, SetImpactSet1)
	DECLARE_SRMETHOD_FORMID1(ImpactSet1, GetEffectData().ImpactSetID1)

	DECLARE_SRFIELD_EDITORID(CSrMgefRecord, ImpactSet2, GetImpactSet2, SetImpactSet2)
	DECLARE_SRMETHOD_FORMID1(ImpactSet2, GetEffectData().ImpactSetID2)

	DECLARE_SRFIELD_EDITORID(CSrMgefRecord, Art1, GetArt1, SetArt1)
	DECLARE_SRMETHOD_FORMID1(Art1, GetEffectData().ArtID1)

	DECLARE_SRFIELD_EDITORID(CSrMgefRecord, Art2, GetArt2, SetArt2)
	DECLARE_SRMETHOD_FORMID1(Art2, GetEffectData().ArtID2)

	DECLARE_SRFIELD_EDITORID(CSrMgefRecord, Art3, GetArt3, SetArt3)
	DECLARE_SRMETHOD_FORMID1(Art3, GetEffectData().ArtID3)

	DECLARE_SRFIELD_EDITORID(CSrMgefRecord, Art4, GetArt4, SetArt4)
	DECLARE_SRMETHOD_FORMID1(Art4, GetEffectData().ArtID4)

	DECLARE_SRFIELD_EDITORID(CSrMgefRecord, Perk, GetPerk, SetPerk)
	DECLARE_SRMETHOD_FORMID1(Perk, GetEffectData().PerkID)

	DECLARE_SRFIELD_DWORDFLAG1(CSrMgefRecord, Unknown1,  GetEffectData().Unknown1,  GetEffectData().Unknown1)
	DECLARE_SRFIELD_FLOAT1(CSrMgefRecord, Unknown2,  GetEffectData().Unknown2,  GetEffectData().Unknown2)
	DECLARE_SRFIELD_DWORD1(CSrMgefRecord, Unknown3,  GetEffectData().Unknown3,  GetEffectData().Unknown3)
	DECLARE_SRFIELD_FLOAT1(CSrMgefRecord, Unknown4,  GetEffectData().Unknown4,  GetEffectData().Unknown4)
	DECLARE_SRFIELD_FLOAT1(CSrMgefRecord, Unknown5,  GetEffectData().Unknown5,  GetEffectData().Unknown5)
	DECLARE_SRFIELD_FLOAT1(CSrMgefRecord, Unknown6,  GetEffectData().Unknown6,  GetEffectData().Unknown6)
	DECLARE_SRFIELD_DWORD1(CSrMgefRecord, Unknown7,  GetEffectData().Unknown7,  GetEffectData().Unknown7)
	DECLARE_SRFIELD_DWORD1(CSrMgefRecord, Unknown8,  GetEffectData().Unknown8,  GetEffectData().Unknown8)
	DECLARE_SRFIELD_INT1(CSrMgefRecord, Unknown9,  GetEffectData().Unknown9,  GetEffectData().Unknown9)
	DECLARE_SRFIELD_FLOAT1(CSrMgefRecord, Unknown10, GetEffectData().Unknown10, GetEffectData().Unknown10)
	DECLARE_SRFIELD_DWORD1(CSrMgefRecord, Unknown11, GetEffectData().Unknown11, GetEffectData().Unknown11)
	DECLARE_SRFIELD_DWORD1(CSrMgefRecord, Unknown12, GetEffectData().Unknown12, GetEffectData().Unknown12)
	DECLARE_SRFIELD_DWORD1(CSrMgefRecord, Unknown13, GetEffectData().Unknown13, GetEffectData().Unknown13)
	DECLARE_SRFIELD_FLOAT1(CSrMgefRecord, Unknown14, GetEffectData().Unknown14, GetEffectData().Unknown14)
	DECLARE_SRFIELD_FLOAT1(CSrMgefRecord, Unknown15, GetEffectData().Unknown15, GetEffectData().Unknown15)
	
	DECLARE_SRFIELD_INT1(CSrMgefRecord, ActorValue, GetEffectData().ActorValue, GetEffectData().ActorValue)
	DECLARE_SRFIELD_DWORD1(CSrMgefRecord, CastType, GetEffectData().CastType, GetEffectData().CastType)
	DECLARE_SRFIELD_FLOAT1(CSrMgefRecord, EffectPlayRate, GetEffectData().EffectPlayRate, GetEffectData().EffectPlayRate)

	DECLARE_SRFIELD_BOOL1(CSrMgefRecord, Hostile, GetEffectData().Flags, SR_MGEFFLAG_HOSTILE)
	DECLARE_SRFIELD_BOOL1(CSrMgefRecord, Recover, GetEffectData().Flags, SR_MGEFFLAG_RECOVER)
	DECLARE_SRFIELD_BOOL1(CSrMgefRecord, Detrimental, GetEffectData().Flags, SR_MGEFFLAG_DETRIMENTAL)
	DECLARE_SRFIELD_BOOL1(CSrMgefRecord, PercentMag, GetEffectData().Flags, SR_MGEFFLAG_PERCENTMAG)
	DECLARE_SRFIELD_BOOL1(CSrMgefRecord, SelfOnly, GetEffectData().Flags, SR_MGEFFLAG_SELF)
	DECLARE_SRFIELD_BOOL1(CSrMgefRecord, NoArea, GetEffectData().Flags, SR_MGEFFLAG_NOAREA)
	DECLARE_SRFIELD_BOOL1(CSrMgefRecord, FXPersist, GetEffectData().Flags, SR_MGEFFLAG_FXPERSIST)
	DECLARE_SRFIELD_BOOL1(CSrMgefRecord, Bound, GetEffectData().Flags, SR_MGEFFLAG_BOUND)
	DECLARE_SRFIELD_BOOL1(CSrMgefRecord, Ward, GetEffectData().Flags, SR_MGEFFLAG_WARD)

	DECLARE_SRFIELD_BOOL1(CSrMgefRecord, UnknownFlag1, GetEffectData().Flags, SR_MGEFFLAG_00000100)
	DECLARE_SRFIELD_BOOL1(CSrMgefRecord, UnknownFlag2, GetEffectData().Flags, SR_MGEFFLAG_00001000)
	DECLARE_SRFIELD_BOOL1(CSrMgefRecord, UnknownFlag3, GetEffectData().Flags, SR_MGEFFLAG_00004000)
	DECLARE_SRFIELD_BOOL1(CSrMgefRecord, UnknownFlag4, GetEffectData().Flags, SR_MGEFFLAG_00008000)
	DECLARE_SRFIELD_BOOL1(CSrMgefRecord, UnknownFlag5, GetEffectData().Flags, SR_MGEFFLAG_00020000)
	DECLARE_SRFIELD_BOOL1(CSrMgefRecord, UnknownFlag6, GetEffectData().Flags, SR_MGEFFLAG_04000000)
	DECLARE_SRFIELD_BOOL1(CSrMgefRecord, UnknownFlag7, GetEffectData().Flags, SR_MGEFFLAG_08000000)
	DECLARE_SRFIELD_BOOL1(CSrMgefRecord, UnknownFlag8, GetEffectData().Flags, SR_MGEFFLAG_00000100)
	DECLARE_SRFIELD_BOOL1(CSrMgefRecord, UnknownFlag9, GetEffectData().Flags, SR_MGEFFLAG_10000000)
  
};
/*===========================================================================
 *		End of Class CSrMgefRecord Definition
 *=========================================================================*/


#endif
/*===========================================================================
 *		End of File SrMgefRecord.H
 *=========================================================================*/
