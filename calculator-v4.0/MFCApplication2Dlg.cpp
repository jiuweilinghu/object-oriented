
// MFCApplication2Dlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MFCApplication2.h"
#include "MFCApplication2Dlg.h"
#include "afxdialogex.h"



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


// CMFCApplication2Dlg �Ի���



CMFCApplication2Dlg::CMFCApplication2Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_MFCAPPLICATION2_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCApplication2Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CMFCApplication2Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON32, &CMFCApplication2Dlg::OnBnClickedButton32)
	ON_BN_CLICKED(IDC_BUTTON3, &CMFCApplication2Dlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON29, &CMFCApplication2Dlg::OnBnClickedButton29)
	ON_BN_CLICKED(IDC_BUTTON6, &CMFCApplication2Dlg::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON30, &CMFCApplication2Dlg::OnBnClickedButton30)
	ON_BN_CLICKED(IDC_BUTTON31, &CMFCApplication2Dlg::OnBnClickedButton31)
	ON_BN_CLICKED(IDC_BUTTON10, &CMFCApplication2Dlg::OnBnClickedButton10)
	ON_BN_CLICKED(IDC_BUTTON33, &CMFCApplication2Dlg::OnBnClickedButton33)
	ON_BN_CLICKED(IDC_BUTTON12, &CMFCApplication2Dlg::OnBnClickedButton12)
	ON_BN_CLICKED(IDC_BUTTON14, &CMFCApplication2Dlg::OnBnClickedButton14)
	ON_BN_CLICKED(IDC_BUTTON15, &CMFCApplication2Dlg::OnBnClickedButton15)
	ON_BN_CLICKED(IDC_BUTTON39, &CMFCApplication2Dlg::OnBnClickedButton39)
	ON_BN_CLICKED(IDC_BUTTON18, &CMFCApplication2Dlg::OnBnClickedButton18)
	ON_BN_CLICKED(IDC_BUTTON5, &CMFCApplication2Dlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON9, &CMFCApplication2Dlg::OnBnClickedButton9)
	ON_BN_CLICKED(IDC_BUTTON13, &CMFCApplication2Dlg::OnBnClickedButton13)
	ON_BN_CLICKED(IDC_BUTTON17, &CMFCApplication2Dlg::OnBnClickedButton17)
	ON_BN_CLICKED(IDC_BUTTON21, &CMFCApplication2Dlg::OnBnClickedButton21)
	ON_BN_CLICKED(IDC_BUTTON20, &CMFCApplication2Dlg::OnBnClickedButton20)
	ON_BN_CLICKED(IDC_BUTTON16, &CMFCApplication2Dlg::OnBnClickedButton16)
END_MESSAGE_MAP()


// CMFCApplication2Dlg ��Ϣ�������

BOOL CMFCApplication2Dlg::OnInitDialog()
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

void CMFCApplication2Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMFCApplication2Dlg::OnPaint()
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
HCURSOR CMFCApplication2Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFCApplication2Dlg::OnBnClickedButton32()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString str;
	GetDlgItem(IDC_EDIT2)->GetWindowText(str);
	if (str == "ERROR")
	{
		str = "";
	}
	else {
		for (int i = 0; i < str.GetLength(); i++)
		{
			if (str[i] == '=')
			{
				str = "";
				break;
			}
		}
	}
	str += '1';
	GetDlgItem(IDC_EDIT2)->SetWindowText(str);
}


void CMFCApplication2Dlg::OnBnClickedButton3()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString str;
	GetDlgItem(IDC_EDIT2)->GetWindowText(str);
	if (str == "ERROR")
	{
		str = "";
	}
	else {
		for (int i = 0; i < str.GetLength(); i++)
		{
			if (str[i] == '=')
			{
				str = "";
				break;
			}
		}
	}
	str += '2';
	GetDlgItem(IDC_EDIT2)->SetWindowText(str);
}


void CMFCApplication2Dlg::OnBnClickedButton29()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString str;
	GetDlgItem(IDC_EDIT2)->GetWindowText(str);
	if (str == "ERROR")
	{
		str = "";
	}
	else {
		for (int i = 0; i < str.GetLength(); i++)
		{
			if (str[i] == '=')
			{
				str = "";
				break;
			}
		}
	}
	str += '3';
	GetDlgItem(IDC_EDIT2)->SetWindowText(str);
}


void CMFCApplication2Dlg::OnBnClickedButton6()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString str;
	GetDlgItem(IDC_EDIT2)->GetWindowText(str);
	if (str == "ERROR")
	{
		str = "";
	}
	else {
		for (int i = 0; i < str.GetLength(); i++)
		{
			if (str[i] == '=')
			{
				str = "";
				break;
			}
		}
	}
	str += '4';
	GetDlgItem(IDC_EDIT2)->SetWindowText(str);
}


void CMFCApplication2Dlg::OnBnClickedButton30()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString str;
	GetDlgItem(IDC_EDIT2)->GetWindowText(str);
	if (str == "ERROR")
	{
		str = "";
	}
	else {
		for (int i = 0; i < str.GetLength(); i++)
		{
			if (str[i] == '=')
			{
				str = "";
				break;
			}
		}
	}
	str += '5';
	GetDlgItem(IDC_EDIT2)->SetWindowText(str);
}


void CMFCApplication2Dlg::OnBnClickedButton31()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString str;
	GetDlgItem(IDC_EDIT2)->GetWindowText(str);
	if (str == "ERROR")
	{
		str = "";
	}
	else {
		for (int i = 0; i < str.GetLength(); i++)
		{
			if (str[i] == '=')
			{
				str = "";
				break;
			}
		}
	}
	str += '6';
	GetDlgItem(IDC_EDIT2)->SetWindowText(str);
}


void CMFCApplication2Dlg::OnBnClickedButton10()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString str;
	GetDlgItem(IDC_EDIT2)->GetWindowText(str);
	if (str == "ERROR")
	{
		str = "";
	}
	else {
		for (int i = 0; i < str.GetLength(); i++)
		{
			if (str[i] == '=')
			{
				str = "";
				break;
			}
		}
	}
	str += '7';
	GetDlgItem(IDC_EDIT2)->SetWindowText(str);
}


void CMFCApplication2Dlg::OnBnClickedButton33()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString str;
	GetDlgItem(IDC_EDIT2)->GetWindowText(str);
	if (str == "ERROR")
	{
		str = "";
	}
	else {
		for (int i = 0; i < str.GetLength(); i++)
		{
			if (str[i] == '=')
			{
				str = "";
				break;
			}
		}
	}
	str += '8';
	GetDlgItem(IDC_EDIT2)->SetWindowText(str);
}


void CMFCApplication2Dlg::OnBnClickedButton12()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString str;
	GetDlgItem(IDC_EDIT2)->GetWindowText(str);
	if (str == "ERROR")
	{
		str = "";
	}
	else {
		for (int i = 0; i < str.GetLength(); i++)
		{
			if (str[i] == '=')
			{
				str = "";
				break;
			}
		}
	}
	str += '9';
	GetDlgItem(IDC_EDIT2)->SetWindowText(str);
}


void CMFCApplication2Dlg::OnBnClickedButton14()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString str;
	GetDlgItem(IDC_EDIT2)->GetWindowText(str);
	if (str == "ERROR")
	{
		str = "";
	}
	else {
		for (int i = 0; i < str.GetLength(); i++)
		{
			if (str[i] == '=')
			{
				str = "";
				break;
			}
		}
	}
	if (str != "0")
	{
		str += '0';
	}
	GetDlgItem(IDC_EDIT2)->SetWindowText(str);
}


void CMFCApplication2Dlg::OnBnClickedButton15()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString str;
	GetDlgItem(IDC_EDIT2)->GetWindowText(str);
	if (str == "ERROR")
	{
		str = "";
	}
	else {
		for (int i = 0; i < str.GetLength(); i++)
		{
			if (str[i] == '=')
			{
				str = "";
				break;
			}
		}
	}
	str += '(';
	GetDlgItem(IDC_EDIT2)->SetWindowText(str);
}


void CMFCApplication2Dlg::OnBnClickedButton39()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString str;
	GetDlgItem(IDC_EDIT2)->GetWindowText(str);
	if (str == "ERROR")
	{
		str = "";
	}
	else {
		for (int i = 0; i < str.GetLength(); i++)
		{
			if (str[i] == '=')
			{
				str = "";
				break;
			}
		}
	}
	str += ')';
	GetDlgItem(IDC_EDIT2)->SetWindowText(str);
}


void CMFCApplication2Dlg::OnBnClickedButton18()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString str;
	GetDlgItem(IDC_EDIT2)->GetWindowText(str);
	if (str == "ERROR")
	{
		str = "";
	}
	else {
		for (int i = 0; i < str.GetLength(); i++)
		{
			if (str[i] == '=')
			{
				str = "";
				break;
			}
		}
	}
	str += '.';
	GetDlgItem(IDC_EDIT2)->SetWindowText(str);
}


void CMFCApplication2Dlg::OnBnClickedButton5()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString str;
	GetDlgItem(IDC_EDIT2)->GetWindowText(str);
	if (str == "ERROR")
	{
		str = "";
	}
	else {
		for (int i = 0; i < str.GetLength(); i++)
		{
			if (str[i] == '=')
			{
				str = "";
				break;
			}
		}
	}
	str += '+';
	GetDlgItem(IDC_EDIT2)->SetWindowText(str);
}


void CMFCApplication2Dlg::OnBnClickedButton9()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString str;
	GetDlgItem(IDC_EDIT2)->GetWindowText(str);
	if (str == "ERROR")
	{
		str = "";
	}
	else {
		for (int i = 0; i < str.GetLength(); i++)
		{
			if (str[i] == '=')
			{
				str = "";
				break;
			}
		}
	}
	str += '-';
	GetDlgItem(IDC_EDIT2)->SetWindowText(str);
}


void CMFCApplication2Dlg::OnBnClickedButton13()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString str;
	GetDlgItem(IDC_EDIT2)->GetWindowText(str);
	if (str == "ERROR")
	{
		str = "";
	}
	else {
		for (int i = 0; i < str.GetLength(); i++)
		{
			if (str[i] == '=')
			{
				str = "";
				break;
			}
		}
	}
	str += "��";
	GetDlgItem(IDC_EDIT2)->SetWindowText(str);
}


void CMFCApplication2Dlg::OnBnClickedButton17()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString str;
	GetDlgItem(IDC_EDIT2)->GetWindowText(str);
	if (str == "ERROR")
	{
		str = "";
	}
	else {
		for (int i = 0; i < str.GetLength(); i++)
		{
			if (str[i] == '=')
			{
				str = "";
				break;
			}
		}
	}
	str += "��";
	GetDlgItem(IDC_EDIT2)->SetWindowText(str);
}


void CMFCApplication2Dlg::OnBnClickedButton21()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString str;
	GetDlgItem(IDC_EDIT2)->GetWindowText(str);
	if (str == "ERROR")
	{
		str = "";
	}
	else {
		for (int i = 0; i < str.GetLength(); i++)
		{
			if (str[i] == '=')
			{
				str = "";
				break;
			}
		}
	}
	str += '=';
	GetDlgItem(IDC_EDIT2)->SetWindowText(str);
}



	void CMFCApplication2Dlg::OnBnClickedButton20()
	{
		// TODO: �ڴ���ӿؼ�֪ͨ����������
		CString str;
		GetDlgItem(IDC_EDIT2)->GetWindowText(str);
		if (str == "ERROR")
		{
			str = "";
		}
		else {
			for (int i = 0; i < str.GetLength(); i++)
			{
				if (str[i] == '=')
				{
					str = "";
					break;
				}
			}
		}
		str.Delete(str.GetLength() - 1, 1);
		GetDlgItem(IDC_EDIT2)->SetWindowText(str);
	}


	void CMFCApplication2Dlg::OnBnClickedButton16()
	{
		// TODO: �ڴ���ӿؼ�֪ͨ����������
		CString str;
		GetDlgItem(IDC_EDIT2)->GetWindowText(str);
		str = "";
		GetDlgItem(IDC_EDIT2)->SetWindowText(str);
	}
