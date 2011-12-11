/*===========================================================================
 *
 * File:		SrStringFile.CPP
 * Author:		Dave Humphrey (dave@uesp.net)
 * Created On:	27 November 2011
 *
 *
 *=========================================================================*/

	/* Include Files */
#include "srstringfile.h"
#include "common/srtime.h"



/*===========================================================================
 *
 * Class CSrStringFile Constructor
 *
 *=========================================================================*/
CSrStringFile::CSrStringFile () :
	m_IsBStringFile(false)
{

}
/*===========================================================================
 *		End of Class CSrStringFile Constructor
 *=========================================================================*/


/*===========================================================================
 *
 * Class CSrStringFile Method - void Destroy (void);
 *
 *=========================================================================*/
void CSrStringFile::Destroy (void) 
{
	m_Strings.Empty();
	m_IsBStringFile = false;
}
/*===========================================================================
 *		End of Class Method CSrStringFile::Destroy()
 *=========================================================================*/


/*===========================================================================
 *
 * Class CSrStringFile Method - void Dump (void);
 *
 *=========================================================================*/
void CSrStringFile::Dump (void)
{
	SystemLog.Printf("Dumping strings file '%s': %u strings, %d file type", m_Filename, m_Strings.GetSize(), m_IsBStringFile);

	for (dword i = 0; i < m_Strings.GetSize(); ++i)
	{
		srstringrecord_h& Record = m_Strings[i];

		SystemLog.Printf("       %d) ID=0x%08X, Offset=0x%08X, Length=%u", i+1, Record.ID, Record.Offset, Record.String.GetLength());

		if (i % 100 == 0) SystemLog.Printf("\t\tString=\"%s\"", Record.String);
	}
}
/*===========================================================================
 *		End of Class Method CSrStringFile::Dump()
 *=========================================================================*/


/*===========================================================================
 *
 * Class CSrStringFile Method - bool Load (pFilename);
 *
 *=========================================================================*/
bool CSrStringFile::Load (const SSCHAR* pFilename) 
{
	srtimer_t Timer;
	CSrFile	  File;
	CSString  TempFile(pFilename);
	bool	  Result;
	dword	  Size;
	dword 	  DataSize;

	SrStartTimer(Timer);

	Result = File.Open(pFilename, "rb");
	if (!Result) return false;
	m_Filename = pFilename;

	int Index = TempFile.FindCharR('.');

	if (Index >= 0) 
	{
		TempFile.Delete(0, Index);
		if (stricmp(TempFile, ".ILSTRINGS") == 0) m_IsBStringFile = true;
		if (stricmp(TempFile, ".DLSTRINGS") == 0) m_IsBStringFile = true;
	}

	Result  = File.ReadDWord(Size);
	Result &= File.ReadDWord(DataSize);
	if (!Result) return AddSrGeneralError("Error reading sizes from strings file '%s'!", pFilename);

	m_Strings.SetSize(Size);

	Result = ReadDirectory(File);
	if (!Result) return false;

	if (File.GetFileSize64() < 10000000)
	{
		if (m_IsBStringFile)
			Result = ReadBStringsFast(File);
		else
			Result = ReadStringsFast(File);
	}
	else 
	{
		if (m_IsBStringFile)
			Result = ReadBStrings(File);
		else
			Result = ReadStrings(File);
	}
	
	if (!Result) return false;

	SrEndTimer(Timer, "Loaded strings file");
	return true;	
}
/*===========================================================================
 *		End of Class Method CSrStringFile::Load()
 *=========================================================================*/


/*===========================================================================
 *
 * Class CSrStringFile Method - bool ReadDirectory (File);
 *
 *=========================================================================*/
bool CSrStringFile::ReadDirectory (CSrFile& File) 
{
	bool Result;

	for (dword i = 0; i < m_Strings.GetSize(); ++i)
	{
		Result = File.ReadDWord(m_Strings[i].ID);
		if (!Result) return false;

		Result = File.ReadDWord(m_Strings[i].Offset);
		if (!Result) return false;
	}

	return true;
}
/*===========================================================================
 *		End of Class Method CSrStringFile::ReadDirectory()
 *=========================================================================*/


/*===========================================================================
 *
 * Class CSrStringFile Method - bool ReadStrings (File);
 *
 *=========================================================================*/
bool CSrStringFile::ReadStrings (CSrFile& File) 
{
	bool Result;
	byte InputChar;
	dword BaseOffset = SR_STRING_HEADERSIZE + SR_STRING_DIRENTRYSIZE * m_Strings.GetSize();

	for (dword i = 0; i < m_Strings.GetSize(); ++i)
	{
		Result = File.Seek(BaseOffset + m_Strings[i].Offset);
		if (!Result) return false;

		CSString& ThisString = m_Strings[i].String;
				
		do {
			Result = File.ReadByte(InputChar);
			if (!Result) return false;
			ThisString += InputChar;
		} while (InputChar != 0 && !File.IsEOF());
	}

	return true;
}
/*===========================================================================
 *		End of Class Method CSrStringFile::ReadStrings()
 *=========================================================================*/


/*===========================================================================
 *
 * Class CSrStringFile Method - bool ReadStringsFast (File);
 *
 *=========================================================================*/
bool CSrStringFile::ReadStringsFast (CSrFile& File) 
{
	bool Result;
	dword BaseOffset = SR_STRING_HEADERSIZE + SR_STRING_DIRENTRYSIZE * m_Strings.GetSize();
	dword DataSize = File.GetFileSize() - BaseOffset;;
	
	if (!File.Seek(BaseOffset)) return false;

	char* pFileData = new char[DataSize + 256];

	Result = File.Read(pFileData, DataSize);

	if (!Result) 
	{
		delete[] pFileData;
		return false;
	}

	pFileData[DataSize] = 0;

	for (dword i = 0; i < m_Strings.GetSize(); ++i)
	{
		dword Offset = m_Strings[i].Offset;
		m_Strings[i].String = pFileData + Offset;
	}

	return true;
}
/*===========================================================================
 *		End of Class Method CSrStringFile::ReadStringsFast()
 *=========================================================================*/


/*===========================================================================
 *
 * Class CSrStringFile Method - bool ReadBStrings (File);
 *
 *=========================================================================*/
bool CSrStringFile::ReadBStrings (CSrFile& File) 
{
	CSString* pString;
	bool Result;
	dword Length;
	dword BaseOffset = SR_STRING_HEADERSIZE + SR_STRING_DIRENTRYSIZE * m_Strings.GetSize();

	for (dword i = 0; i < m_Strings.GetSize(); ++i)
	{
		Result = File.Seek(BaseOffset + m_Strings[i].Offset);
		if (!Result) return false;

		Result = File.ReadDWord(Length);
		if (!Result) return false;

		pString = &m_Strings[i].String;
		pString->SetSizeEmpty(Length + 2);
		
		if (Length > 0)
		{
			Result = File.Read((void *)pString->c_str(), Length);
			if (!Result) return false;
			pString->UpdateLength();
		}
	}

	return true;
}
/*===========================================================================
 *		End of Class Method CSrStringFile::ReadBStrings()
 *=========================================================================*/


/*===========================================================================
 *
 * Class CSrStringFile Method - bool ReadBStringsFast (File);
 *
 *=========================================================================*/
bool CSrStringFile::ReadBStringsFast (CSrFile& File) 
{
	bool Result;
	dword Length;
	dword BaseOffset = SR_STRING_HEADERSIZE + SR_STRING_DIRENTRYSIZE * m_Strings.GetSize();
	dword DataSize = File.GetFileSize() - BaseOffset;;
	
	if (!File.Seek(BaseOffset)) return false;

	char* pFileData = new char[DataSize + 256];

	Result = File.Read(pFileData, DataSize);

	if (!Result) 
	{
		delete[] pFileData;
		return false;
	}

	pFileData[DataSize] = 0;

	for (dword i = 0; i < m_Strings.GetSize(); ++i)
	{
		dword Offset = m_Strings[i].Offset;
		Length = *((dword *) (pFileData + Offset));
		m_Strings[i].String.Copy(pFileData + Offset + 4, Length);
		//pString->UpdateLength();
	}

	return true;
}
/*===========================================================================
 *		End of Class Method CSrStringFile::ReadBStringsFast()
 *=========================================================================*/