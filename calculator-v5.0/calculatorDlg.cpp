
// calculatorDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "calculator.h"
#include "calculatorDlg.h"
#include "afxdialogex.h"
#include "Scan.h"
#include "Calculation.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CcalculatorDlg �Ի���



CcalculatorDlg::CcalculatorDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_CALCULATOR_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CcalculatorDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CcalculatorDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CcalculatorDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CcalculatorDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CcalculatorDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CcalculatorDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &CcalculatorDlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON6, &CcalculatorDlg::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON7, &CcalculatorDlg::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON8, &CcalculatorDlg::OnBnClickedButton8)
	ON_BN_CLICKED(IDC_BUTTON9, &CcalculatorDlg::OnBnClickedButton9)
	ON_BN_CLICKED(IDC_BUTTON10, &CcalculatorDlg::OnBnClickedButton10)
	ON_BN_CLICKED(IDC_BUTTON11, &CcalculatorDlg::OnBnClickedButton11)
	ON_BN_CLICKED(IDC_BUTTON12, &CcalculatorDlg::OnBnClickedButton12)
	ON_BN_CLICKED(IDC_BUTTON13, &CcalculatorDlg::OnBnClickedButton13)
	ON_BN_CLICKED(IDC_BUTTON14, &CcalculatorDlg::OnBnClickedButton14)
	ON_BN_CLICKED(IDC_BUTTON17, &CcalculatorDlg::OnBnClickedButton17)
	ON_BN_CLICKED(IDC_BUTTON18, &CcalculatorDlg::OnBnClickedButton18)
	ON_BN_CLICKED(IDC_BUTTON16, &CcalculatorDlg::OnBnClickedButton16)
	ON_BN_CLICKED(IDC_BUTTON15, &CcalculatorDlg::OnBnClickedButton15)
	ON_BN_CLICKED(IDC_BUTTON19, &CcalculatorDlg::OnBnClickedButton19)
	ON_BN_CLICKED(IDC_BUTTON20, &CcalculatorDlg::OnBnClickedButton20)
END_MESSAGE_MAP()


// CcalculatorDlg ��Ϣ�������

BOOL CcalculatorDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CcalculatorDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CcalculatorDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CcalculatorDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CcalculatorDlg::OnBnClickedButton1()
{
	CString str;
	GetDlgItem(IDC_EDIT2)->GetWindowText(str);
	if (str == "ERROR")
	{
		str = "";
	}
	
	str += '1';
	GetDlgItem(IDC_EDIT2)->SetWindowText(str);
}


void CcalculatorDlg::OnBnClickedButton2()
{
	CString str;
	GetDlgItem(IDC_EDIT2)->GetWindowText(str);
	if (str == "ERROR")
	{
		str = "";
	}
	
	str += '2';
	GetDlgItem(IDC_EDIT2)->SetWindowText(str);
}


void CcalculatorDlg::OnBnClickedButton3()
{
	CString str;
	GetDlgItem(IDC_EDIT2)->GetWindowText(str);
	if (str == "ERROR")
	{
		str = "";
	}
	
	str += '3';
	GetDlgItem(IDC_EDIT2)->SetWindowText(str);
}


void CcalculatorDlg::OnBnClickedButton4()
{
	CString str;
	GetDlgItem(IDC_EDIT2)->GetWindowText(str);
	if (str == "ERROR")
	{
		str = "";
	}
	
	str += '+';
	GetDlgItem(IDC_EDIT2)->SetWindowText(str);
}


void CcalculatorDlg::OnBnClickedButton5()
{
	CString str;
	GetDlgItem(IDC_EDIT2)->GetWindowText(str);
	if (str == "ERROR")
	{
		str = "";
	}
	
	str += '4';
	GetDlgItem(IDC_EDIT2)->SetWindowText(str);
}


void CcalculatorDlg::OnBnClickedButton6()
{
	CString str;
	GetDlgItem(IDC_EDIT2)->GetWindowText(str);
	if (str == "ERROR")
	{
		str = "";
	}
	
	str += '5';
	GetDlgItem(IDC_EDIT2)->SetWindowText(str);
}


void CcalculatorDlg::OnBnClickedButton7()
{
	CString str;
	GetDlgItem(IDC_EDIT2)->GetWindowText(str);
	if (str == "ERROR")
	{
		str = "";
	}
	
	str += '6';
	GetDlgItem(IDC_EDIT2)->SetWindowText(str);
}


void CcalculatorDlg::OnBnClickedButton8()
{
	CString str;
	GetDlgItem(IDC_EDIT2)->GetWindowText(str);
	if (str == "ERROR")
	{
		str = "";
	}
	
	str += '-';
	GetDlgItem(IDC_EDIT2)->SetWindowText(str);
}


void CcalculatorDlg::OnBnClickedButton9()
{
	CString str;
	GetDlgItem(IDC_EDIT2)->GetWindowText(str);
	if (str == "ERROR")
	{
		str = "";
	}
	
	str += '7';
	GetDlgItem(IDC_EDIT2)->SetWindowText(str);
}


void CcalculatorDlg::OnBnClickedButton10()
{
	CString str;
	GetDlgItem(IDC_EDIT2)->GetWindowText(str);
	if (str == "ERROR")
	{
		str = "";
	}
	
	str += '8';
	GetDlgItem(IDC_EDIT2)->SetWindowText(str);
}


void CcalculatorDlg::OnBnClickedButton11()
{
	CString str;
	GetDlgItem(IDC_EDIT2)->GetWindowText(str);
	if (str == "ERROR")
	{
		str = "";
	}
	
	str += '9';
	GetDlgItem(IDC_EDIT2)->SetWindowText(str);
}


void CcalculatorDlg::OnBnClickedButton12()
{
	CString str;
	GetDlgItem(IDC_EDIT2)->GetWindowText(str);
	if (str == "ERROR")
	{
		str = "";
	}
	
	str += '*';
	GetDlgItem(IDC_EDIT2)->SetWindowText(str);
}


void CcalculatorDlg::OnBnClickedButton13()
{
	CString str;
	GetDlgItem(IDC_EDIT2)->GetWindowText(str);
	if (str == "ERROR")
	{
		str = "";
	}
	
	str += '0';
	GetDlgItem(IDC_EDIT2)->SetWindowText(str);
}


void CcalculatorDlg::OnBnClickedButton14()
{
	CString str;
	GetDlgItem(IDC_EDIT2)->GetWindowText(str);
	if (str == "ERROR")
	{
		str = "";
	}
	
	str += '(';
	GetDlgItem(IDC_EDIT2)->SetWindowText(str);
}


void CcalculatorDlg::OnBnClickedButton17()
{
	CString str;
	GetDlgItem(IDC_EDIT2)->GetWindowText(str);
	if (str == "ERROR")
	{
		str = "";
	}
	
	str += '.';
	GetDlgItem(IDC_EDIT2)->SetWindowText(str);
}


void CcalculatorDlg::OnBnClickedButton18()
{
	CString str;
	GetDlgItem(IDC_EDIT2)->GetWindowText(str);
	if (str == "ERROR")
	{
		str = "";
	}
	
	str += ')';
	GetDlgItem(IDC_EDIT2)->SetWindowText(str);
}


void CcalculatorDlg::OnBnClickedButton16()
{
	CString str;
	GetDlgItem(IDC_EDIT2)->GetWindowText(str);
	if (str == "ERROR")
	{
		str = "";
	}
	
	str += '/';
	GetDlgItem(IDC_EDIT2)->SetWindowText(str);
}


void CcalculatorDlg::OnBnClickedButton15()
{
	CString str;
	GetDlgItem(IDC_EDIT2)->GetWindowText(str);
	str = "";
	GetDlgItem(IDC_EDIT2)->SetWindowText(str);
}


void CcalculatorDlg::OnBnClickedButton19()
{
	CString str;
	GetDlgItem(IDC_EDIT2)->GetWindowText(str);
	if (str == "ERROR")
	{
		str = "";
	}
	
	str.Delete(str.GetLength() - 1, 1);
	GetDlgItem(IDC_EDIT2)->SetWindowText(str);
}


void CcalculatorDlg::OnBnClickedButton20()
{
	CString str;
	GetDlgItem(IDC_EDIT2)->GetWindowText(str);
	if (str == "ERROR")
	{
		str = "";
		GetDlgItem(IDC_EDIT2)->SetWindowText(str);
	}
	else {
		Scan scan;
		queue<string>queue;
		Calculation cal;
		string res;
		string s;
		str += "=";
		s = (LPCSTR)(CStringA)(str);
		queue=scan.tostringqueue(s);
		res=cal.calculate(queue);
		CString cstr(res.c_str());
		GetDlgItem(IDC_EDIT2)->SetWindowText(cstr);
	}
}
