#include "StdAfx.h"
#include "SREngine.h"


CSREngine::CSREngine(void)
{
	mSpRecognizer = NULL;
}


CSREngine::~CSREngine(void)
{
}


HRESULT CSREngine::InitializeSAPI(HWND hWnd, UINT Msg)
{
	CoInitialize(NULL);
	HRESULT hr = mSpRecognizer.CoCreateInstance(CLSID_SpInprocRecognizer);
	if(FAILED(hr))
	{
		AfxMessageBox(TEXT("adf"));
		return hr;
	}

	mSpRecognizer->CreateRecoContext(&mSpRecoContext);
	mSpRecoContext->SetNotifyWindowMessage(hWnd, Msg, NULL, NULL);
	ULONGLONG interest = SPFEI(SPEI_RECOGNITION)|SPFEI(SPEI_FALSE_RECOGNITION);
	mSpRecoContext->SetInterest(interest, interest);

	SpCreateDefaultObjectFromCategoryId(SPCAT_AUDIOIN, &mSpAudio);

	mSpRecognizer->SetInput(mSpAudio, TRUE);

	mSpVoice.CoCreateInstance(CLSID_SpVoice);
	mSpVoice->SetRate(0);
	mSpVoice->SetVolume(100);
	hr = mSpVoice->Speak(L"��ӭʹ������ʶ��", SPF_DEFAULT, NULL);
	if(FAILED(hr))
	{
		AfxMessageBox(TEXT("sdfsfsd"));
	}
	return hr;
}


HRESULT CSREngine::LoadCmdFromFile(CString xmlPath)
{

	HRESULT hr = mSpRecoContext->CreateGrammar(123, &mSpRecoGrammar);
	hr = mSpRecoGrammar->LoadCmdFromFile(xmlPath, SPLO_DYNAMIC);
	if(S_OK == hr)
	{
		AfxMessageBox(TEXT("�ɹ�"));
	}
	mSpRecoGrammar->SetRuleState(NULL, NULL, SPRS_ACTIVE);
	return hr;
}
