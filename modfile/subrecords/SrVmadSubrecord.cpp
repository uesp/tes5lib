/*===========================================================================
 *
 * File:		SrVmadSubrecord.cpp
 * Author:		Dave Humphrey (dave@uesp.net)
 * Created On:	25 January 2012
 *
 * Implements the CSrVmadSubrecord class for handling VMAD subrecords.
 *
 *=========================================================================*/

#include "srvmadsubrecord.h"



CSrVmadSubrecord::CSrVmadSubrecord() : m_pRawData(NULL), m_RawDataSize(0)
{
}


CSrVmadSubrecord::~CSrVmadSubrecord()
{
	delete[] m_pRawData;
	m_pRawData = NULL;
}


void CSrVmadSubrecord::Destroy()
{
	m_Data.Destroy();
	delete[] m_pRawData;
	m_pRawData    = NULL;
	m_RawDataSize = 0;
}


dword CSrVmadSubrecord::ComputeRawDataSize (void)
{
	return m_Data.ComputeSize();
}


bool CSrVmadSubrecord::Copy (CSrSubrecord* pSubrecord)
{
	CSrVmadSubrecord* pSource = SrCastClassNull(CSrVmadSubrecord, pSubrecord);
	if (pSource == NULL) return false;

	m_Data.Copy(pSource->m_Data);
	UpdateRawData();

	return true;
}


bool CSrVmadSubrecord::CreateRawData (void)
{
	dword Index = 0;

	m_RawDataSize = m_Data.ComputeSize();
	delete[] m_pRawData;
	m_pRawData = new byte[m_RawDataSize + 4];
	if (m_RawDataSize == 0) return true;

	return m_Data.CreateRawData(m_pRawData, Index, m_RawDataSize);
}


void CSrVmadSubrecord::InitializeNew (void) 
{ 
	CSrSubrecord::InitializeNew(); 
	m_Data.Destroy(); 
	m_RecordSize = 0; 
	UpdateRawData();
}


bool CSrVmadSubrecord::ReadData  (CSrFile& File)
{
	delete m_pRawData;
	m_RawDataSize = m_RecordSize;
	m_pRawData = new byte[m_RawDataSize + 4];

	if (m_RecordSize == 0) return true;

	if (!File.Read(m_pRawData, m_RecordSize)) return false;
	return ParseRawData();
}


bool CSrVmadSubrecord::ParseRawData (void)
{
	dword Index = 0;

	if (m_pRawData == NULL || m_RawDataSize == 0) return AddSrGeneralError("CSrVmadSubrecord::ParseRawData() - No raw data to parse!");

	return m_Data.ParseRawData(m_pRawData, Index, m_RawDataSize);
}


bool CSrVmadSubrecord::WriteData (CSrFile& File)
{
	if (!CreateRawData()) return false;
	return File.Write(m_pRawData, m_RawDataSize);
}