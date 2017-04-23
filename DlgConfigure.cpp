// DlgConfigure.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "LXDeviceAPI_Sample1.h"
#include "DlgConfigure.h"
#include "afxdialogex.h"


// CDlgConfigure 대화 상자입니다.

IMPLEMENT_DYNAMIC(CDlgConfigure, CDialog)

CDlgConfigure::CDlgConfigure(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_DLGCONFIGURE, pParent)
	, m_MaxAmplitude(0)
{

}

CDlgConfigure::~CDlgConfigure()
{
}

void CDlgConfigure::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);

	DDX_Text(pDX, IDC_EDIT_MAXAMPLITUDE,m_MaxAmplitude); // 수동으로 추가해야함.

}


BEGIN_MESSAGE_MAP(CDlgConfigure, CDialog)
END_MESSAGE_MAP()


// CDlgConfigure 메시지 처리기입니다.


BOOL CDlgConfigure::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	
//	UpdateData(FALSE); // 변수값을 대화상자 컨트롤에 표현. 

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}
