#pragma once

#include "atlbase.h"
#include "sapi.h"
#include "sphelper.h"

class CSREngine
{
public:
	CSREngine(void);
	~CSREngine(void);

	CComPtr<ISpRecognizer> mSpRecognizer;
	CComPtr<ISpRecoContext> mSpRecoContext;
	CComPtr<ISpAudio> mSpAudio;

	CComPtr<ISpVoice> mSpVoice;

	CComPtr<ISpRecoGrammar> mSpRecoGrammar;

	HRESULT InitializeSAPI(HWND hWnd, UINT Msg);
	HRESULT LoadCmdFromFile(CString xmlPath);
};

