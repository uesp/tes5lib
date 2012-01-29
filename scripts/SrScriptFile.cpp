#include "SrScriptFile.h"


CSrScriptFile::CSrScriptFile()
{
	m_IsModified = false;
}


CSrScriptFile::~CSrScriptFile()
{
}


void CSrScriptFile::Destroy (void)
{
	m_ScriptText.Destroy();
	m_Filename.Destroy();
	m_ScriptName.Destroy();
	m_IsModified = false;
}


bool CSrScriptFile::Load (const char* pFilename)
{
	CSrFile File;
	bool    Result;
	dword   InputBytes;

	Destroy();

	Result = File.Open(pFilename, "rb");
	if (!Result) return AddSrGeneralError("Failed to open script file '%s'!", pFilename);

	m_Filename = pFilename;
	UpdateName();

	if (File.GetFileSize() > 10000000) return AddSrGeneralError("Exceeded maximum size of script file (10000000 bytes)!");

	m_ScriptText.SetSizeEmpty(File.GetFileSize());

	Result = File.Read((char *)m_ScriptText.c_str(), File.GetFileSize(), InputBytes);
	m_ScriptText.UpdateLength();
	if (!Result) return false;	

	return true;
}


bool CSrScriptFile::Save (const char* pFilename)
{
	CSrFile File;
	bool    Result;

	if (pFilename == NULL)
		Result = File.Open(m_Filename, "wb");
	else
		Result = File.Open(pFilename, "wb");

	if (!Result) return false;

	Result = File.Write(m_ScriptText, m_ScriptText.GetLength());
	if (!Result) return false;

	if (pFilename != NULL)
	{
		m_Filename = pFilename;
		UpdateName();
	}

	return true;
}


void CSrScriptFile::UpdateName (void)
{
	int Index = m_Filename.FindCharR('\\');
	m_ScriptName.Empty();

	if (Index < 0)
		m_ScriptName = m_Filename;
	else 
		m_ScriptName.Copy(m_Filename.c_str() + Index + 1, m_Filename.GetLength() - Index - 1);

	m_ScriptName.TruncateAt('.');
}
