/*===========================================================================
 *
 * File:		Srmoddefs.H
 * Author:		Dave Humphrey (dave@uesp.net)
 * Created On:	26 November 2011
 *
 * Common definitions used for mod files.
 *
 *=========================================================================*/
#ifndef __SRMODDEFS_H
#define __SRMODDEFS_H


/*===========================================================================
 *
 * Begin Required Includes
 *
 *=========================================================================*/
  #include "../common/srfile.h"
  #include "../common/srlogfile.h"
  #include "../common/textutils.h"
  #include "../common/srcallback.h"
  #include "../common/srarray.h"
  #include "../common/srptrarray.h"
  #include "../common/csvfile.h"
  #include "srfields.h"
  #include "srrectype.h"
  #include "../common/srtime.h"
  #include "srfunctions.h"
  #include "../common/srblockallocator.h"
/*===========================================================================
 *		End of Required Includes
 *=========================================================================*/


/*===========================================================================
 *
 * Begin FormID Definitions
 *
 *=========================================================================*/

	/* Invalid/NULL form ID definition */
  #define SR_FORMID_NULL ((srformid_t) 0)

  	/* Maximum allowed form id */
  #define MAX_SRFORMID	((srformid_t) 0x00ffffff)
  #define SR_FORMID_MAX MAX_SRFORMID

	/* Get a modindex from a formid */
  #define SR_GETMODINDEX(FormID) ((((dword)FormID) >> 24) & 0xff) 

	/* Make a new formid from a formid and new modindex */
  #define SR_MAKEFORMID(FormID, ModIndex) (( ((dword)(FormID)) & 0x00ffffff) | (((dword)(ModIndex)) << 24) )

  #define SR_MODINDEX_MAX 255
  #define SR_MODINDEX_MIN 0

	/* Special formids */
  //#define SR_PLAYERREF_FORMID 0x14
  //#define SR_PLAYER_FORMID    0x7

/*===========================================================================
 *		End of FormID Definitions
 *=========================================================================*/


/*===========================================================================
 *
 * Begin Class Type Definitions
 *
 *=========================================================================*/

	/* Used to create simple runtime type checking for class casts */
  #define DECLARE_SRBASE(Class) \
	public: \
	static int GetClassType (void) { return (SRCLASS_##Class); } \
	virtual bool IsClassType (const int ClassType) { return (GetClassType() == ClassType); } \
	virtual int GetMyClassType (void) {  return (SRCLASS_##Class);  } 

  #define DECLARE_SRCLASS(Class, BaseClass) \
	public: \
	static int GetClassType (void) { return (SRCLASS_##Class); } \
	virtual bool IsClassType (const int ClassType) { return (GetClassType() == ClassType ? true : BaseClass::IsClassType(ClassType)); } \
	virtual int GetMyClassType (void) { return (SRCLASS_##Class);  } 

#if 1
  #define DECLARE_SRALLOCATOR(Class, BaseClass) \
    public: \
		static BaseClass* Create (void) { return new Class; } 
  #define DEFINE_SRALLOCATOR(Class) 
#else
  #define DECLARE_SRALLOCATOR(Class, BaseClass) \
    public: \
		static TSrBlockAllocator<Class> s_BlockAllocator; \
		static BaseClass* Create (void) { return s_BlockAllocator.CreateObject(); } 
  #define DEFINE_SRALLOCATOR(Class) TSrBlockAllocator<Class> Class::s_BlockAllocator;
#endif

	/* Cast a class pointer checking to ensure the cast is valid (checks the class
	   heirarchy). If invalid NULL is returned. Do not call with NULL pointer. */
  #define SrCastClass(Class, Ptr) \
  	(Class *) ((Ptr)->IsClassType(Class::GetClassType()) ? (Ptr) : NULL)

	/* Allows NULL input */
  #define SrCastClassNull(Class, Ptr) \
	(Class *) (Ptr ? ((Ptr)->IsClassType(Class::GetClassType()) ? (Ptr) : NULL) : NULL)

	/* Special case for casting a base record */
  #define SrCastRecord(BaseRecord) \
	(CSrRecord *) (((BaseRecord)->IsRecord()) ? ((BaseRecord)->IsClassType(CSrRecord::GetClassType()) ? (BaseRecord) : NULL) : NULL)
  #define SrCastGroup(BaseRecord) \
	(CSrGroup *) (((BaseRecord)->IsGroup()) ? ((BaseRecord)->IsClassType(CSrGroup::GetClassType()) ? (BaseRecord) : NULL) : NULL)
	

/*===========================================================================
 *		End of Class Type Definitions
 *=========================================================================*/


/*===========================================================================
 *
 * Begin Definitions
 *
 *=========================================================================*/
	
	/* Used to define the effect data array */
  #define START_EFFECTVALUE(Array) const sreffectdata_t Array[] = {
  #define ADD_EFFECTVALUE(Name, String, Flags) { &Name, String, Flags }, 
  #define END_EFFECTVALUE() { NULL, NULL } };

	/* Find data flags */
  #define SR_FIND_COMPARETEXT		0x0001	/* Case insensitive text search, default is binary */
  #define SR_FIND_OUTPUTLOG			0x0002	/* Output results to system log */
  #define SR_FIND_GROUPHEADER		0x0004	/* Search group headers as well */
  #define SR_FIND_RECORDHEADER		0x0008	/* Search record headers as well */
  #define SR_FIND_SUBRECORDHEADER	0x0010	/* Search subrecord headers as well */
  #define SR_FIND_ALLHEADERS		0x001C	
  #define SR_FIND_COUNTONLY			0x0020	/* Only count results */
  #define SR_FIND_CASESENSITIVE		0x0040	
  #define SR_FIND_FINDALL			0x0080	
  #define SR_FIND_ADDRECORDS		0x0100	
  #define SR_FIND_NOHEADER			0x0200

	/* Main game master file */
  #define SR_GAME_MASTER "skyrim.esm"

  	/* Check validation codes used in various places */
  #define SR_CHECKRESULT_OK			 0
  #define SR_CHECKRESULT_NOCHANGE	 1
  #define SR_CHECKRESULT_ERROR		-1

	/* Cache flags */
  #define SR_CACHE_DEFERLOAD	1

/*===========================================================================
 *		End of Definitions
 *=========================================================================*/


/*===========================================================================
 *
 * Begin Type Definitions
 *
 *=========================================================================*/

	/* Forward class definitions */
  class CSrRecord;

	/* Array of string objects */
  typedef CSrPtrArray<CSString> CSStringArray;

	/* Holds effect data */
  struct sreffectdata_t {
	const srrectype_t* pName;
	const SSCHAR*	   pDescription;
	dword			   DefaultFlags;
   };

	/* Used to fixup the modindex of formIDs */
  typedef TSrArray<byte> CSrFormidFixupArray;

	/* FormID used everywhere in mod files to identify objects */
  typedef dword srformid_t;
  typedef TSrArray<srformid_t> CSrFormidArray;

	/* Used to find information in record and subrecord data */
  struct srfinddata_t
  {
	const byte*		pData;			/* Data to match */
	dword			DataSize;		/* Size of data in bytes */
	dword			Flags;			/* Find options */
	dword			FileCount;
	dword			GroupCount;
	dword			RecordCount;
	dword			SubrecordCount;

	dword			FoundSubrecords;
	dword			FoundRecords;

	srrectype_t*	pExcludeRecords;	/* Optional list of record types to exclude from the search */

	CSrRefPtrArray<CSrRecord>*	pFindRecords;

	srfinddata_t()
	{
		pData		 = NULL;
		DataSize	 = 0;
		Flags		 = 0;
		FileCount	 = 0;
		GroupCount	 = 0;
		RecordCount	 = 0;
		SubrecordCount	 = 0;
		FoundSubrecords  = 0;
		FoundRecords     = 0;
		pExcludeRecords	 = NULL;
		pFindRecords     = NULL;
	}
  };

	/* Used to find and collect use information */
  struct srrecorduse_t {
	dword	   Count;
	CSrRecord* pRecord;
  };

	/* Array of use information for multiple records */
  typedef CSrPtrArray<srrecorduse_t> CSrRecordUseArray;

	/* Use information on a single record */
  struct sruseinfo_t
  {
	srformid_t			FormID;		/* Formid being looked for */
	CSrRecord*			pRecord;	/* Record being looked for if available */
	CSrRecordUseArray	Uses;

	sruseinfo_t()
	{
		FormID  = SR_FORMID_NULL;
		pRecord = NULL;
	}
  };

  typedef dword srlstringid_t;
  #define SR_NULL_STRINGID 0

/*===========================================================================
 *		End of Type Definitions
 *=========================================================================*/


/*===========================================================================
 *
 * Begin Import/Export Definitions
 *
 *=========================================================================*/

	/* Forward structure definitions */
  struct srrecfield_t;

	/* Holds information on a single column in a CVS file */
  struct srcsvcolinfo_t {
    CSString*			pValue;
	dword				ColIndex;	/* Column index in the CSV file */
	srfieldid_t			FieldID;	/* Field ID of the column */
	const srrecfield_t*	pField;
	bool				Process;	/* Process this field or not */
	int					UserData;
  };

	/* Array of CSV column objects */
  typedef CSrPtrArray<srcsvcolinfo_t> CSrCsvColInfos;

	/* Used when importing/exporting a CSV file */
  struct srcsvinfo_t
  {
	CCsvFile*       pCsvFile;
	CSrCsvColInfos  ColInfos;

	srcsvcolinfo_t*	pEditorID;
	srcsvcolinfo_t* pRecordName;

	dword		CurrentLine;
  };

/*===========================================================================
 *		End of Import/Export Definitions
 *=========================================================================*/


/*===========================================================================
 *
 * Begin Class Type Definitions
 *
 * Define unique integers to known classes. Integers are used merely for
 * simplicity and speed. These values could be defined in their respective
 * classes but it is easily to define them all in the same place to ensure
 * no duplicates.
 *
 *=========================================================================*/
	#define SRCLASS_CSrBaseRecord	10
	#define SRCLASS_CSrRecord		100
	#define SRCLASS_CSrIdRecord		101
    #define SRCLASS_CSrIdKeyRecord	102
	#define SRCLASS_CSrItem1Record	104
	#define SRCLASS_CSrItem2Record	105
    
	#define SRCLASS_CSrAactRecord    200
	#define SRCLASS_CSrAchrRecord    201
	#define SRCLASS_CSrActiRecord    202
	#define SRCLASS_CSrAddnRecord    203
	#define SRCLASS_CSrAlchRecord    204
	#define SRCLASS_CSrAmmoRecord    205
	#define SRCLASS_CSrAnioRecord    206
	#define SRCLASS_CSrAppaRecord    207
	#define SRCLASS_CSrArmaRecord    208
	#define SRCLASS_CSrArmoRecord    209
	#define SRCLASS_CSrArtoRecord    210
	#define SRCLASS_CSrAspcRecord    211
	#define SRCLASS_CSrAstpRecord    212
	#define SRCLASS_CSrAvifRecord    213
	#define SRCLASS_CSrBookRecord    214
	#define SRCLASS_CSrBptdRecord    215
	#define SRCLASS_CSrCamsRecord    216
	#define SRCLASS_CSrCellRecord    217
	#define SRCLASS_CSrClasRecord    218
	#define SRCLASS_CSrClfmRecord    219
	#define SRCLASS_CSrClmtRecord    220
	#define SRCLASS_CSrCobjRecord    221
	#define SRCLASS_CSrCollRecord    222
	#define SRCLASS_CSrContRecord    223
	#define SRCLASS_CSrCpthRecord    224
	#define SRCLASS_CSrCstyRecord    225
	#define SRCLASS_CSrDebrRecord    226
	#define SRCLASS_CSrDialRecord    227
	#define SRCLASS_CSrDlbrRecord    228
	#define SRCLASS_CSrDlvwRecord    229
	#define SRCLASS_CSrDobjRecord    230
	#define SRCLASS_CSrDoorRecord    231
	#define SRCLASS_CSrDualRecord    232
	#define SRCLASS_CSrEcznRecord    233
	#define SRCLASS_CSrEfshRecord    234
	#define SRCLASS_CSrEnchRecord    235
	#define SRCLASS_CSrEqupRecord    236
	#define SRCLASS_CSrExplRecord    237
	#define SRCLASS_CSrEyesRecord    238
	#define SRCLASS_CSrFactRecord    239
	#define SRCLASS_CSrFlorRecord    240
	#define SRCLASS_CSrFlstRecord    241
	#define SRCLASS_CSrFstpRecord    242
	#define SRCLASS_CSrFstsRecord    243
	#define SRCLASS_CSrFurnRecord    244
	#define SRCLASS_CSrGlobRecord    245
	#define SRCLASS_CSrGmstRecord    246
	#define SRCLASS_CSrGrasRecord    247
	#define SRCLASS_CSrHazdRecord    248
	#define SRCLASS_CSrHdptRecord    249
		//IAD?
	#define SRCLASS_CSrIdleRecord    251
	#define SRCLASS_CSrIdlmRecord    252
	#define SRCLASS_CSrImadRecord    253
	#define SRCLASS_CSrImgsRecord    254
	#define SRCLASS_CSrInfoRecord    255
	#define SRCLASS_CSrIngrRecord    256
	#define SRCLASS_CSrIpctRecord    257
	#define SRCLASS_CSrIpdsRecord    258
	#define SRCLASS_CSrKeymRecord    259
	#define SRCLASS_CSrKywdRecord    260
	#define SRCLASS_CSrLandRecord    261
	#define SRCLASS_CSrLcrtRecord    262
	#define SRCLASS_CSrLctnRecord    263
	#define SRCLASS_CSrLgtmRecord    264
	#define SRCLASS_CSrLighRecord    265
	#define SRCLASS_CSrLscrRecord    266
	#define SRCLASS_CSrLtexRecord    267
	#define SRCLASS_CSrLvliRecord    268
	#define SRCLASS_CSrLvlnRecord    269
	#define SRCLASS_CSrLvspRecord    270
	#define SRCLASS_CSrMatoRecord    271
	#define SRCLASS_CSrMattRecord    272
	#define SRCLASS_CSrMesgRecord    273
	#define SRCLASS_CSrMgefRecord    274
	#define SRCLASS_CSrMiscRecord    275
	#define SRCLASS_CSrMovtRecord    276
	#define SRCLASS_CSrMsttRecord    277
	#define SRCLASS_CSrMuscRecord    278
	#define SRCLASS_CSrMustRecord    279
	#define SRCLASS_CSrNaviRecord    280
	#define SRCLASS_CSrNavmRecord    281
	#define SRCLASS_CSrNpc_Record    282
	#define SRCLASS_CSrOtftRecord    283
	#define SRCLASS_CSrPackRecord    284
	#define SRCLASS_CSrPerkRecord    285
	#define SRCLASS_CSrPgreRecord    286
	#define SRCLASS_CSrPhzdRecord    287
	#define SRCLASS_CSrProjRecord    288
	#define SRCLASS_CSrQustRecord    289
	#define SRCLASS_CSrRaceRecord    290
	#define SRCLASS_CSrRefrRecord    291
	#define SRCLASS_CSrRegnRecord    292
	#define SRCLASS_CSrRelaRecord    293
	#define SRCLASS_CSrRevbRecord    294
	#define SRCLASS_CSrRfctRecord    295
	#define SRCLASS_CSrScenRecord    296
	#define SRCLASS_CSrScrlRecord    297
	#define SRCLASS_CSrShouRecord    298
	#define SRCLASS_CSrSlgmRecord    299
	#define SRCLASS_CSrSmbnRecord    300
	#define SRCLASS_CSrSmenRecord    301
	#define SRCLASS_CSrSmqnRecord    302
	#define SRCLASS_CSrSnctRecord    303
	#define SRCLASS_CSrSndrRecord    304
	#define SRCLASS_CSrSopmRecord    305
	#define SRCLASS_CSrSounRecord    306
	#define SRCLASS_CSrSpelRecord    307
	#define SRCLASS_CSrSpgdRecord    308
	#define SRCLASS_CSrStatRecord    309
	#define SRCLASS_CSrTactRecord    310
	#define SRCLASS_CSrTes4Record    311
	#define SRCLASS_CSrTreeRecord    312
	#define SRCLASS_CSrTxstRecord    313
	#define SRCLASS_CSrVtypRecord    314
	#define SRCLASS_CSrWatrRecord    315
	#define SRCLASS_CSrWeapRecord    316
	#define SRCLASS_CSrWoopRecord    317
	#define SRCLASS_CSrWrldRecord    318
	#define SRCLASS_CSrWthrRecord    319

  
	#define SRCLASS_CSrGroup			501
	#define SRCLASS_CSrTypeGroup		502
	#define SRCLASS_CSrFormIDGroup		503
	#define SRCLASS_CSrBlockGroup		504
	#define SRCLASS_CSrGridGroup		505

	#define SRCLASS_CSrSubrecord				1000
	#define SRCLASS_CSrDataSubrecord			1001
	#define SRCLASS_CSrDwordSubrecord			1002
	#define SRCLASS_CSrFloatSubrecord			1003
	#define SRCLASS_CSrInt64Subrecord			1004
	#define SRCLASS_CSrLongSubrecord			1005
	#define SRCLASS_CSrWordSubrecord			1006
	#define SRCLASS_CSrFormidSubrecord			1007
	#define SRCLASS_CSrStringSubrecord			1008
	#define SRCLASS_CSrHedrSubrecord			1009
	#define SRCLASS_CSrWeapDataSubrecord		1010
	#define SRCLASS_CSrFormidArraySubrecord		1011
	#define SRCLASS_CSrLStringSubrecord			1012
	#define SRCLASS_CSrMgefDataSubrecord		1013
	#define SRCLASS_CSrCtdaSubrecord			1014
	#define SRCLASS_CSrByteSubrecord			1015
	#define SRCLASS_CSrGmstDataSubrecord		1016
	#define SRCLASS_CSrCntoSubrecord			1017
	#define SRCLASS_CSrEnitSubrecord			1018
	#define SRCLASS_CSrEfitSubrecord			1019
	#define SRCLASS_CSrSpitSubrecord			1020
	#define SRCLASS_CSrAmmoDataSubrecord		1021
	#define SRCLASS_CSrArmoDataSubrecord		1022
	#define SRCLASS_CSrBodtSubrecord			1023
	#define SRCLASS_CSrAlchDataSubrecord		1024
	#define SRCLASS_CSrEnitAlchSubrecord		1025
	#define SRCLASS_CSrIngrEnitSubrecord		1026
	#define SRCLASS_CSrIngrDataSubrecord		1027
	#define SRCLASS_CSrScrlDataSubrecord		1028
	#define SRCLASS_CSrBookDataSubrecord		1029
	#define SRCLASS_CSrDnamSubrecord			1030
  
/*===========================================================================
 *		End of Class Type Definitions
 *=========================================================================*/


/*===========================================================================
 *
 * Begin Function Definitions
 *
 *=========================================================================*/

	/* Fixup a formID modindex */
  bool SrFixupFormid (srformid_t& OutputFormID, const srformid_t OrigFormID, CSrFormidFixupArray& FixupArray);
  
	/* Basic find in binary or text data */
  dword SrFindData           (const byte* pData, const dword Size, srfinddata_t& FindData);
  dword SrFindTextData       (const byte* pData, const dword Size, srfinddata_t& FindData);
  dword SrFindDataNoCase     (const byte* pData, const dword Size, srfinddata_t& FindData);
  dword SrFindTextDataNoCase (const byte* pData, const dword Size, srfinddata_t& FindData);
  dword SrFindDataCase       (const byte* pData, const dword Size, srfinddata_t& FindData);
  dword SrFindTextDataCase   (const byte* pData, const dword Size, srfinddata_t& FindData);

	/* Check if a record name occurs in a list */
  bool SrContainsRecordType (const srrectype_t Name, const srrectype_t* pArray);

	/* Prepares an editor id by removing invalid characters */
  bool SrPrepareEditorID (CSString& EditorID);

	/* Check record types */
  bool SrIsObjectRecord    (const srrectype_t RecordType);

/*===========================================================================
 *		End of Function Definitions
 *=========================================================================*/


/*===========================================================================
 *
 * Begin Type Definitions
 *
 *=========================================================================*/

		/* Magic Schools */
  #define SR_MAGIC_SCHOOL_ALTERATION	0x12
  #define SR_MAGIC_SCHOOL_CONJURATION	0x13
  #define SR_MAGIC_SCHOOL_DESTRUCTION	0x14
  #define SR_MAGIC_SCHOOL_ILLUSION		0x15
  #define SR_MAGIC_SCHOOL_RESTORATION	0x16
  #define SR_MAGIC_SCHOOL_NONE			-1

		/* Magic Effect Types */
  #define SR_MAGIC_TYPE_EXTRADMG		0x27
  #define SR_MAGIC_TYPE_POISON			0x28
  #define SR_MAGIC_TYPE_FIRE			0x29
  #define SR_MAGIC_TYPE_SHOCK			0x2A
  #define SR_MAGIC_TYPE_FROST			0x2B
  #define SR_MAGIC_TYPE_DRAIN			0x2C
  #define SR_MAGIC_TYPE_NONE			-1

		/* Condition operators */
  #define SR_CONDOP_EQUAL			0x00
  #define SR_CONDOP_NOTEQUAL		0x02
  #define SR_CONDOP_GREATER			0x04
  #define SR_CONDOP_GREATEREQUAL	0x06
  #define SR_CONDOP_LESS			0x08
  #define SR_CONDOP_LESSEQUAL		0x0A

		/* Condition flags */
  #define SR_CONDFLAG_OR			0x01
  #define SR_CONDFLAG_RUNONTARGET	0x02
  #define SR_CONDFLAG_USEGLOBAL		0x04

  extern const stringvalue_t s_SrMagicSchools[];
  extern const stringvalue_t s_SrMagicTypes[];
  extern const stringvalue_t s_SrConditionOperators[];

			/* Spell Types */
	#define SR_SPELL_TYPE_SPELL			0
	#define SR_SPELL_TYPE_DISEASE		1
    #define SR_SPELL_TYPE_POWER			2
    #define SR_SPELL_TYPE_LESSERPOWER	3
    #define SR_SPELL_TYPE_ABILITY		4
    #define SR_SPELL_TYPE_POISON		5
    #define SR_SPELL_TYPE_VOICE			11

			/* Spell Casting Animations */
	#define SR_SPELL_CASTANIM_NONE			0
	#define SR_SPELL_CASTANIM_PROJECTILE	1
	#define SR_SPELL_CASTANIM_SUSTAINED		2
    #define SR_SPELL_CASTANIM_3				3

			/* Spell Casting Types */
	#define SR_SPELL_CASTTYPE_0		0
	#define SR_SPELL_CASTTYPE_1		1
	#define SR_SPELL_CASTTYPE_2		2
	#define SR_SPELL_CASTTYPE_3		3
	#define SR_SPELL_CASTTYPE_4		4
    
			/* Body parts flags (not all values confirmed) */
	#define SR_BODYPARTS_SKIN				0x00000001
	#define SR_BODYPARTS_HEAD				0x00000002
	#define SR_BODYPARTS_CHEST				0x00000004
	#define SR_BODYPARTS_HANDS				0x00000008
	#define SR_BODYPARTS_BEARD				0x00000010
	#define SR_BODYPARTS_AMULET				0x00000020
	#define SR_BODYPARTS_RING				0x00000040
	#define SR_BODYPARTS_FEET				0x00000080
	#define SR_BODYPARTS_UNKNOWN1			0x00000100
	#define SR_BODYPARTS_SHIELD				0x00000200
	#define SR_BODYPARTS_ANIMALSKIN			0x00000400
	#define SR_BODYPARTS_UNDERSKIN			0x00000800
	#define SR_BODYPARTS_CROWN				0x00001000
	#define SR_BODYPARTS_FACE				0x00002000
	#define SR_BODYPARTS_DRAGONHEAD			0x00004000
	#define SR_BODYPARTS_DRAGONLWING		0x00008000
	#define SR_BODYPARTS_DRAGONRWING		0x00010000
	#define SR_BODYPARTS_DRAGONBODY			0x00020000
	#define SR_BODYPARTS_UNKNOWN3			0x00100000
	#define SR_BODYPARTS_UNKNOWN4			0x00300000
	#define SR_BODYPARTS_UNKNOWN2			0x80000000

    #define SR_ARMORTYPE_NONE  0
    #define SR_ARMORTYPE_LIGHT 1
    #define SR_ARMORTYPE_HEAVY 2

    #define SR_POTIONTYPE_0			0x00000000
    #define SR_POTIONTYPE_1			0x00000001
    #define SR_POTIONTYPE_2			0x00000002
    #define SR_POTIONTYPE_FOOD		0x00000003
	#define SR_POTIONTYPE_HARMFUL	0x00020000

	#define SR_SKILL_ONEHAND 		6 
	#define SR_SKILL_TWOHAND 		7 
	#define SR_SKILL_MARKSMAN 		8 
	#define SR_SKILL_BLOCK 			9 
	#define SR_SKILL_SMITHING 		10
	#define SR_SKILL_HEAVYARMOR 	11
	#define SR_SKILL_LIGHTARMOR 	12
	#define SR_SKILL_PICKPOCKET 	13
	#define SR_SKILL_LOCKPICKING	14
	#define SR_SKILL_SNEAK 			15
	#define SR_SKILL_ALCHEMY 		16
	#define SR_SKILL_SPEECHCRAFT 	17
	#define SR_SKILL_ALTERATION 	18
	#define SR_SKILL_CONJURATION 	19
	#define SR_SKILL_DESTRUCTION 	20
	#define SR_SKILL_ILLUSION 		21
	#define SR_SKILL_RESTORATION	22
	#define SR_SKILL_ENCHANTING 	23
	
    extern const stringvalue_t s_SrSpellTypes[];
	extern const stringvalue_t s_SrSpellCastAnims[];
	extern const stringvalue_t s_SrSpellCastTypes[];

	extern const stringvalue_t s_SrEnchantTypeA[];
	extern const stringvalue_t s_SrEnchantTypeB[];
	extern const stringvalue_t s_SrEnchantTypeC[];
	extern const stringvalue_t s_SrEnchantTypeD[];

	extern const stringvalue_t s_SrBodyParts[];
	extern const stringvalue_t s_SrArmorTypes[];

	extern const stringvalue_t s_SrPotionTypes[];
	
	extern const stringvalue_t s_SrSkillTypes[];

/*===========================================================================
 *		End of Type Definitions
 *=========================================================================*/


/*===========================================================================
 *
 * Begin Type Lookup Function Definitions
 *
 *=========================================================================*/
  	const SSCHAR* GetSrMagicSchoolString		(const int Value);
	const SSCHAR* GetSrMagicTypeString			(const int Value);
	const SSCHAR* GetSrConditionOperatorString	(const int Value);

	const SSCHAR* GetSrSpellTypeString		(const int Value);
	const SSCHAR* GetSrSpellCastTypeString	(const int Value);
	const SSCHAR* GetSrSpellCastAnimString	(const int Value);

	bool GetSrMagicSchoolValue			(int& Value, const SSCHAR* pString);
	bool GetSrMagicTypeValue			(int& Value, const SSCHAR* pString);
	bool GetSrConditionOperatorValue	(int& Value, const SSCHAR* pString);

	bool GetSrSpellTypeValue		(int& Value, const SSCHAR* pString);
	bool GetSrSpellCastTypeValue	(int& Value, const SSCHAR* pString);
	bool GetSrSpellCastAnimValue	(int& Value, const SSCHAR* pString);

	const SSCHAR* GetSrEnchantTypeAString	(const int Value);
	const SSCHAR* GetSrEnchantTypeBString	(const int Value);
	const SSCHAR* GetSrEnchantTypeCString	(const int Value);
	const SSCHAR* GetSrEnchantTypeDString	(const int Value);

	bool GetSrEnchantTypeAValue	(int& Value, const SSCHAR* pString);
	bool GetSrEnchantTypeBValue	(int& Value, const SSCHAR* pString);
	bool GetSrEnchantTypeCValue	(int& Value, const SSCHAR* pString);
	bool GetSrEnchantTypeDValue	(int& Value, const SSCHAR* pString);

	const SSCHAR* GetSrBodyPartString		(const int Value);
	bool GetSrBodyPartValue	(int& Value, const SSCHAR* pString);
	CSString GetSrBodyPartFlagString	(const dword Value);
	bool GetSrBodyPartFlagValue	(dword& Value, const SSCHAR* pString);
	const SSCHAR* GetSrArmorTypeString		(const int Value);
	bool GetSrArmorTypeValue (int& Value, const SSCHAR* pString);
	const SSCHAR* GetSrPotionTypeString		(const int Value);
	bool GetSrPotionTypeValue (int& Value, const SSCHAR* pString);
	const SSCHAR* GetSrSkillTypeString		(const int Value);
	bool GetSrSkillTypeValue (int& Value, const SSCHAR* pString);

/*===========================================================================
 *		End of Type Lookup Function Definitions
 *=========================================================================*/


	bool SrIsRecipeResult    (const srrectype_t Type);
	bool SrIsRecipeComponent (const srrectype_t Type);
	

/*===========================================================================
 *
 * Begin External Definitions
 *
 *=========================================================================*/
  
  extern CSString g_SrLanguage;

/*===========================================================================
 *		End of External Definitions
 *=========================================================================*/


#endif
/*===========================================================================
 *		End of File Srmoddefs.H
 *=========================================================================*/
