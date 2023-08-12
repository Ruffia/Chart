
// Chart_DynamicCreateDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "Chart_DynamicCreate.h"
#include "Chart_DynamicCreateDlg.h"
#include "afxdialogex.h"
#include "ChartBarSerie.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
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


// CChart_DynamicCreateDlg 对话框



CChart_DynamicCreateDlg::CChart_DynamicCreateDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CChart_DynamicCreateDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CChart_DynamicCreateDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CChart_DynamicCreateDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_TIMER()
	ON_BN_CLICKED(ID_TimerStart, &CChart_DynamicCreateDlg::OnBnClickedTimerstart)
END_MESSAGE_MAP()


// CChart_DynamicCreateDlg 消息处理程序

BOOL CChart_DynamicCreateDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
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

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	CRect rc;
	GetClientRect(rc);
	CRect rcChart(rc.left + 10, rc.top + 10,rc.Width() - 20,rc.Height() - 50);
	m_pChartCtrl = new CChartCtrl();
	m_pChartCtrl->Create(this,rcChart,3000,WS_CLIPCHILDREN | WS_TABSTOP);
	m_pChartCtrl->ShowWindow(SW_SHOW);


	CChartAxis* pAxis = NULL;
	pAxis = m_pChartCtrl->CreateStandardAxis(CChartCtrl::BottomAxis); //底部坐标轴
	//pAxis->SetAutomatic(true);
	//根据具体数值自动调节坐标轴坐标，如果要固定坐标轴需要将其参数修改为false
	pAxis->SetAutomatic(false);
	pAxis->SetMinMax(0,20);       //固定x轴坐标为-20
	pAxis = m_pChartCtrl->CreateStandardAxis(CChartCtrl::LeftAxis);  //左边坐标轴
	pAxis->SetAutomatic(false);
	pAxis->SetMinMax(0,100);   //固定y轴坐标为0 - 100

	TChartString str1;   //添加标题
	str1 =_T("High-speed Charting画图Demo");
	m_pChartCtrl->GetTitle()->AddString(str1);
	//设置颜色
	m_pChartCtrl->GetTitle()->SetColor(RGB(255,255,255));            //标题字体白色
	m_pChartCtrl->GetLeftAxis()->SetTextColor(RGB(255,255,255));     //左坐标轴白色
	m_pChartCtrl->GetBottomAxis()->SetTextColor(RGB(255,255,255));    //底部坐标轴白色
	m_pChartCtrl->SetBorderColor(RGB(255,255,255));                   //边框颜色白色
	m_pChartCtrl->SetBackColor(RGB(85,85,85));                        //背景颜色深灰色

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CChart_DynamicCreateDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CChart_DynamicCreateDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CChart_DynamicCreateDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CChart_DynamicCreateDlg::OnBnClickedTimerstart()
{
	// TODO: 在此添加控件通知处理程序代码
	SetTimer(1,3000,NULL);
}



void CChart_DynamicCreateDlg::OnTimer(UINT_PTR nIDEvent)
{
	srand((unsigned int)time(NULL));
	if (1 == nIDEvent)
	{
		//产生随机数种子，包含头文件
		double X1Values[15],Y1Values[15];
		for (int i = 0; i < 15; i++)
		{
			X1Values[i] = i;
			Y1Values[i] = rand() % 100 + 1; //y坐标随机产生1~100
		}

		m_pChartCtrl->SetZoomEnabled(true);
		m_pChartCtrl->RemoveAllSeries();     //先清空
		CChartBarSerie* pBarSerie3 = m_pChartCtrl->CreateBarSerie();   //定义柱状图向柄
		pBarSerie3->SetSeriesOrdering(poNoOrdering);  //绑定绘图变量
		//设置为无序
		pBarSerie3->SetPoints(X1Values,Y1Values,15);
	}

	__super::OnTimer(nIDEvent);
}
