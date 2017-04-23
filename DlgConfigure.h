#pragma once


// CDlgConfigure 대화 상자입니다.

class CDlgConfigure : public CDialog
{
	DECLARE_DYNAMIC(CDlgConfigure)

public:
	CDlgConfigure(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CDlgConfigure();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DLGCONFIGURE };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	float m_MaxAmplitude;
	virtual BOOL OnInitDialog();
};
