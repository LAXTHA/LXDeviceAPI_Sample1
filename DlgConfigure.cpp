// DlgConfigure.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "LXDeviceAPI_Sample1.h"
#include "DlgConfigure.h"
#include "afxdialogex.h"


// CDlgConfigure ��ȭ �����Դϴ�.

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

	DDX_Text(pDX, IDC_EDIT_MAXAMPLITUDE,m_MaxAmplitude); // �������� �߰��ؾ���.

}


BEGIN_MESSAGE_MAP(CDlgConfigure, CDialog)
END_MESSAGE_MAP()


// CDlgConfigure �޽��� ó�����Դϴ�.


BOOL CDlgConfigure::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
	
//	UpdateData(FALSE); // �������� ��ȭ���� ��Ʈ�ѿ� ǥ��. 

	return TRUE;  // return TRUE unless you set the focus to a control
				  // ����: OCX �Ӽ� �������� FALSE�� ��ȯ�ؾ� �մϴ�.
}
