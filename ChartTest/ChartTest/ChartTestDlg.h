
// ChartTestDlg.h : 头文件
//

#pragma once
#include "ChartCtrl.h"
#include "ChartTitle.h"
#include "ChartSerie.h"


// CChartTestDlg 对话框
class CChartTestDlg : public CDialogEx
{
// 构造
public:
	CChartTestDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_CHARTTEST_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;
	CChartCtrl m_ChartCtrl;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnBnClickedTimerstart();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	DECLARE_MESSAGE_MAP()
};
