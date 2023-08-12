
// Chart_DynamicCreateDlg.h : ͷ�ļ�
//

#pragma once
#include "ChartCtrl.h"
#include "ChartTitle.h"
#include "ChartSerie.h"

// CChart_DynamicCreateDlg �Ի���
class CChart_DynamicCreateDlg : public CDialogEx
{
// ����
public:
	CChart_DynamicCreateDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_CHART_DYNAMICCREATE_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��

// ʵ��
protected:
	HICON m_hIcon;
	CChartCtrl* m_pChartCtrl;
	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg void OnBnClickedTimerstart();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
};
