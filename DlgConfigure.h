#pragma once


// CDlgConfigure ��ȭ �����Դϴ�.

class CDlgConfigure : public CDialog
{
	DECLARE_DYNAMIC(CDlgConfigure)

public:
	CDlgConfigure(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CDlgConfigure();

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DLGCONFIGURE };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	float m_MaxAmplitude;
	virtual BOOL OnInitDialog();
};
