
// ChartTestDlg.h : ͷ�ļ�
//

#pragma once
#include "ChartCtrl.h"
#include "ChartTitle.h"
#include "ChartSerie.h"


// CChartTestDlg �Ի���
class CChartTestDlg : public CDialogEx
{
// ����
public:
	CChartTestDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_CHARTTEST_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;
	CChartCtrl m_ChartCtrl;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnBnClickedTimerstart();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	DECLARE_MESSAGE_MAP()
};
