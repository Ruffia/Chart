
// ChartTestDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include <ctime>
#include "ChartTest.h"
#include "ChartTestDlg.h"
#include "afxdialogex.h"
#include "ChartBarSerie.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CChartTestDlg �Ի���



CChartTestDlg::CChartTestDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CChartTestDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CChartTestDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_CUSTOM1, m_ChartCtrl);
}

BEGIN_MESSAGE_MAP(CChartTestDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_TIMER()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(ID_TimerStart, &CChartTestDlg::OnBnClickedTimerstart)
END_MESSAGE_MAP()


// CChartTestDlg ��Ϣ�������

BOOL CChartTestDlg::OnInitDialog()
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

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������


	CChartAxis* pAxis = NULL;
	pAxis = m_ChartCtrl.CreateStandardAxis(CChartCtrl::BottomAxis); //�ײ�������
	//pAxis->SetAutomatic(true);
	//���ݾ�����ֵ�Զ��������������꣬���Ҫ�̶���������Ҫ��������޸�Ϊfalse
	pAxis->SetAutomatic(false);
	pAxis->SetMinMax(0,20);       //�̶�x������Ϊ-20
	pAxis = m_ChartCtrl.CreateStandardAxis(CChartCtrl::LeftAxis);  //���������
	pAxis->SetAutomatic(false);
	pAxis->SetMinMax(0,100);   //�̶�y������Ϊ0 - 100
	
	TChartString str1;   //��ӱ���
	str1 =_T("High-speed Charting��ͼDemo");
	m_ChartCtrl.GetTitle()->AddString(str1);
	//������ɫ
	m_ChartCtrl.GetTitle()->SetColor(RGB(255,255,255));            //���������ɫ
	m_ChartCtrl.GetLeftAxis()->SetTextColor(RGB(255,255,255));     //���������ɫ
	m_ChartCtrl.GetBottomAxis()->SetTextColor(RGB(255,255,255));    //�ײ��������ɫ
	m_ChartCtrl.SetBorderColor(RGB(255,255,255));                   //�߿���ɫ��ɫ
	m_ChartCtrl.SetBackColor(RGB(85,85,85));                        //������ɫ���ɫ

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CChartTestDlg::OnSysCommand(UINT nID, LPARAM lParam)
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
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CChartTestDlg::OnPaint()
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
HCURSOR CChartTestDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CChartTestDlg::OnBnClickedTimerstart()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	SetTimer(1,3000,NULL);
}



void CChartTestDlg::OnTimer(UINT_PTR nIDEvent)
{
	srand((unsigned int)time(NULL));
	if (1 == nIDEvent)
	{
		//������������ӣ�����ͷ�ļ�
		double X1Values[15],Y1Values[15];
		for (int i = 0; i < 15; i++)
		{
			X1Values[i] = i;
		    Y1Values[i] = rand() % 100 + 1; //y�����������1~100
		}
     
		m_ChartCtrl.SetZoomEnabled(true);
		m_ChartCtrl.RemoveAllSeries();     //�����
		CChartBarSerie* pBarSerie3 = m_ChartCtrl.CreateBarSerie();   //������״ͼ���
		pBarSerie3->SetSeriesOrdering(poNoOrdering);  //�󶨻�ͼ����
		//����Ϊ����
		pBarSerie3->SetPoints(X1Values,Y1Values,15);
	}
	
	__super::OnTimer(nIDEvent);
}

