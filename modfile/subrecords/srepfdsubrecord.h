/*===========================================================================
 *
 * File:		SrEpfdSubrecord.H
 * Author:		Dave Humphrey (dave@uesp.net)
 * Created On:	3 January 2012
 *
 * Description
 *
 *=========================================================================*/
#ifndef __SREPFDSUBRECORD_H
#define __SREPFDSUBRECORD_H


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

		/* Fixed subrecord sizes */
	#define SR_EPFD01_SUBRECORD_SIZE	4
	#define SR_EPFD02_SUBRECORD_SIZE	8
	#define SR_EPFD04_SUBRECORD_SIZE	4
	#define SR_EPFD05_SUBRECORD_SIZE	4
		/* Types 06/07 are variable sized */
	#define SR_EPFDFLOAT_SUBRECORD_SIZE      SR_EPFD01_SUBRECORD_SIZE
	#define SR_EPFDACTORVALUE_SUBRECORD_SIZE SR_EPFD02_SUBRECORD_SIZE
	#define SR_EPFDOTHER_SUBRECORD_SIZE      SR_EPFD04_SUBRECORD_SIZE
	#define SR_EPFDFORMID_SUBRECORD_SIZE     SR_EPFD05_SUBRECORD_SIZE

		/* EPFD data types. This should be the same value as in the prior EPFT byte subrecord */
	#define SP_EPFDTYPE_UNKNOWN		0
	#define SP_EPFDTYPE_FLOAT		1
	#define SP_EPFDTYPE_ACTORVALUE	2
	#define SP_EPFDTYPE_OTHER		4
	#define SP_EPFDTYPE_FORMID		5	
	#define SP_EPFDTYPE_ZSTRING		6
	#define SP_EPFDTYPE_LSTRING		7

/*===========================================================================
 *		End of Definitions
 *=========================================================================*/


/*===========================================================================
 *
 * Begin Type Definitions
 *
 *=========================================================================*/
#pragma pack(push, 1)

	struct srepfddata01_t 
	{
		float	Value;
	};

	struct srepfddata02_t 
	{
		float	ActorValue;
		float	Factor;
	};

	struct srepfddata04_t 
	{
		srformid_t	FormID;
	};

	struct srepfddata05_t 
	{
		srformid_t FormID;
	};

#pragma pack(pop)

	struct srepfddata06_t 
	{
		CSString	String;
	};

	struct srepfddata07_t 
	{
		int			StringID;
		CSString	String;
		bool		IsLoaded;
		bool		IsLocalString;

		srepfddata07_t() : StringID(-1), IsLoaded(false), IsLocalString(false)
		{
		}
	};

/*===========================================================================
 *		End of Type Definitions
 *=========================================================================*/


/*===========================================================================
 *
 * Begin Class CSrEpfdSubrecord Definition
 *
 * Description
 *
 *=========================================================================*/
class CSrEpfdSubrecord : public CSrSubrecord {
	DECLARE_SRCLASS(CSrEpfdSubrecord, CSrSubrecord)

  /*---------- Begin Protected Class Members --------------------*/
protected:
	srepfddata01_t	m_Data01;
	srepfddata02_t	m_Data02;
	srepfddata04_t	m_Data04;
	srepfddata05_t	m_Data05;
	srepfddata06_t	m_Data06;
	srepfddata07_t	m_Data07;

	byte			m_DataType;


  /*---------- Begin Protected Class Methods --------------------*/
protected:

	virtual bool ReadData  (CSrFile& File);
	virtual bool WriteData (CSrFile& File);


  /*---------- Begin Public Class Methods -----------------------*/
public:

	CSrEpfdSubrecord();
	virtual void Destroy (void);

	virtual bool Copy (CSrSubrecord* pSubrecord);

	virtual dword ChangeFormID (const srformid_t NewID, const srformid_t OldID);
	virtual dword CountUses (const srformid_t FormID);
  	virtual bool FixupFormID (CSrFormidFixupArray& FixupArray);
	
	static  CSrSubrecord* Create  (void) { return new CSrEpfdSubrecord; }
	virtual CSrSubrecord* CreateV (void) { return new CSrEpfdSubrecord; }

	srepfddata01_t&  GetEpfdData01 (void) { return m_Data01; }
	srepfddata02_t&  GetEpfdData02 (void) { return m_Data02; }
	srepfddata04_t&  GetEpfdData04 (void) { return m_Data04; }
	srepfddata05_t&  GetEpfdData05 (void) { return m_Data05; }
	srepfddata06_t&  GetEpfdData06 (void) { return m_Data06; }
	srepfddata07_t&  GetEpfdData07 (void) { return m_Data07; }

	byte GetDataType (void) { return m_DataType; }

	virtual byte*  GetData       (void);
	virtual dword  GetRecordSize (void) const;
  
	void InitializeNew (void);

	void LoadLocalStrings (CSrRecordHandler* pHandler);

	void SetDataType        (const byte Value) { m_DataType = Value; }
	void SetLoadLocalString (const bool Value) { m_Data07.IsLocalString = Value; }
  
};
/*===========================================================================
 *		End of Class CSrEpfdSubrecord Definition
 *=========================================================================*/


#endif
/*===========================================================================
 *		End of File SrEpfdSubrecord.H
 *=========================================================================*/
