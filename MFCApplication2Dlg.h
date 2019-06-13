
// MFCApplication2Dlg.h : ͷ�ļ�
//

#pragma once
#include <vector>
#include "afxwin.h"

using namespace std;

// CMFCApplication2Dlg �Ի���
class CMFCApplication2Dlg : public CDialogEx
{
// ����
public:
	CMFCApplication2Dlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCAPPLICATION2_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��

public:
	vector<vector<int>> maps;
	CPen m_pen[5];
	CPoint m_point[5];
	int m_row;
	int m_col;
	int m_pointx;
	int m_pointy;
public:
	void DrawLine(CDC *pDC);
	void DrawPolyline(CDC *pDC);
	void DrawPolygon(CDC *pDC);
	void DrawRect(CDC *pDC, int row, int col);
	void DrawRoundRect(CDC *pDC);
	void DrawEllipse(CDC *pDC);
	void DrawArc(CDC *pDC);
	void DrawAngleArc(CDC *pDC);

	//game logic
	void playgame (int row, int col);
	int getCells(vector<vector<int>>& tmp, int x, int y, int row, int col);
	void LifeorDead(int x, int y, int num);


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnEnChangeEdit1();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	CComboBox m_combo;
	afx_msg void OnCbnSelchangeCombo1();
	afx_msg void OnCbnSetfocusCombo1();
	CComboBox m_comborow;
	afx_msg void OnCbnSetfocusCombo2();
	afx_msg void OnCbnSelchangeCombo2();
	afx_msg void OnMouseLeave();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton4();
};
