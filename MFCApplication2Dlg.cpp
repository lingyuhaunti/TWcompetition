
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

	//��ʼ�����ʡ����������
	m_pen[0].CreatePen(PS_SOLID, 5, RGB(0, 0, 255));     //��ɫʵ�ߣ�1���ؿ�---��������ʽ����ȡ���ɫ
	m_pen[1].CreatePen(PS_SOLID, 6, RGB(0, 255, 0));     //��ɫʵ�ߣ�6���ؿ�
	m_pen[2].CreatePen(PS_DASH, 1, RGB(255, 0, 0));      //��ɫ���ߣ�����Ϊһ�����ؿ�
	m_pen[3].CreatePen(PS_DOT, 1, RGB(0, 0, 255));       //��ɫ���ߣ�����Ϊһ�����ؿ�
	m_pen[4].CreatePen(PS_DASHDOTDOT, 1, RGB(255, 0, 0));//��ɫ˫�����ߣ�����Ϊһ�����ؿ�

														 //���ƶ���εĵ�����
	m_point[0].x = 10;
	m_point[0].y = 100;
	m_point[1].x = 10;
	m_point[1].y = 120;
	m_point[2].x = 100;
	m_point[2].y = 105;
	m_point[3].x = 170;
	m_point[3].y = 120;
	m_point[4].x = 170;
	m_point[4].y = 100;

	// �������ݳ�ʼ��Ϊ0   
}

void CMFCApplication2Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO1, m_combo);
	DDX_Control(pDX, IDC_COMBO2, m_comborow);
	DDX_Control(pDX, IDC_COMBO3, m_combocol);
}

BEGIN_MESSAGE_MAP(CMFCApplication2Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_TIMER()
	ON_CBN_SELCHANGE(IDC_COMBO1, &CMFCApplication2Dlg::OnCbnSelchangeCombo1)
	ON_CBN_SETFOCUS(IDC_COMBO1, &CMFCApplication2Dlg::OnCbnSetfocusCombo1)
	ON_CBN_SETFOCUS(IDC_COMBO2, &CMFCApplication2Dlg::OnCbnSetfocusCombo2)
	ON_CBN_SELCHANGE(IDC_COMBO2, &CMFCApplication2Dlg::OnCbnSelchangeCombo2)
	ON_WM_MOUSELEAVE()
	ON_WM_LBUTTONDOWN()
	ON_BN_CLICKED(IDOK, &CMFCApplication2Dlg::OnBnClickedOk)
	ON_BN_CLICKED(IDC_BUTTON1, &CMFCApplication2Dlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CMFCApplication2Dlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CMFCApplication2Dlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CMFCApplication2Dlg::OnBnClickedButton4)
	ON_CBN_SELCHANGE(IDC_COMBO3, &CMFCApplication2Dlg::OnCbnSelchangeCombo3)
	ON_CBN_SETFOCUS(IDC_COMBO3, &CMFCApplication2Dlg::OnCbnSetfocusCombo3)
END_MESSAGE_MAP()


// CMFCApplication2Dlg ��Ϣ�������

BOOL CMFCApplication2Dlg::OnInitDialog()
{
	m_row = 20;
	m_col = 20;
	auto temp = vector<vector<int>> (m_row, vector<int> (m_col,0));
	maps = temp;
	maps[0][1] = 1;
	maps[1][2] = 1;
	maps[2][0] = 1;
	maps[2][1] = 1;
	maps[2][2] = 1;

	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);
	SetTimer(1, 1000, NULL);

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
	
	CPaintDC dc(this); // ���ڻ��Ƶ��豸������
	CBrush brush(RGB(190, 190, 190));//��ˢ
	dc.SelectObject(&brush);//����ˢѡ��DC

	DrawRect(&dc, m_row, m_col);
	TRACE0("\n");
	TRACE1("%d", m_row);
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

//����ֱ�ߺ���
void CMFCApplication2Dlg::DrawLine(CDC *pDC)
{
	CPen *oldPen = pDC->SelectObject(&m_pen[0]);//����DCԭʼ����
	for (int i = 0; i<5; i++)
	{
		pDC->SelectObject(&m_pen[i]);        //������ѡ��DC
		pDC->MoveTo(20, 20 + i * 15);         //����DC��ǰ��
		pDC->LineTo(170, 20 + i * 15);            //����ֱ��
	}
	pDC->SelectObject(oldPen);       //�ظ�DCԭ����
}

void CMFCApplication2Dlg::DrawRect(CDC *pDC, int row, int col)
{
	CRect rect(20, 20, 40, 40);
	CPen *oldPen = pDC->SelectObject(&m_pen[0]);

	for (int i = 0; i < row; ++i) {
		for (int j = 0; j < col; ++j) {
			rect.OffsetRect(20, 0);
			pDC->Rectangle(&rect);
			if (maps[i][j] == 1) {
				pDC->FillSolidRect(&rect, RGB(0, 255, 0));
			}
			else {
				pDC->FillSolidRect(&rect, RGB(255, 0, 0));
			}
			pDC->SelectObject(&m_pen[0]);
			
		}
		rect.OffsetRect(-20*col, 20);
	}
	/*pDC->SelectObject(&m_pen[0]);
	pDC->Rectangle(&rect);*/
}



void CMFCApplication2Dlg::OnEnChangeEdit1()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}


void CMFCApplication2Dlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	//TRACE0("test timer 0\n");
	//maps[0][0] = 1;
	//maps[1][2] = 1;

	playgame(m_row, m_col);
	Invalidate(false);
	UpdateWindow();
	//OnPaint();
	CDialogEx::OnTimer(nIDEvent);
}

void CMFCApplication2Dlg::OnCbnSetfocusCombo1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	m_combo.ResetContent();
	m_combo.AddString(_T("10"));
	m_combo.AddString(_T("11"));
	m_combo.AddString(_T("12"));
	m_combo.AddString(_T("13"));
	m_combo.AddString(_T("14"));
	m_combo.AddString(_T("15"));
	m_combo.AddString(_T("16"));
	m_combo.AddString(_T("17"));
	m_combo.AddString(_T("18"));
	m_combo.AddString(_T("19"));
	m_combo.AddString(_T("20"));
}


void CMFCApplication2Dlg::OnCbnSetfocusCombo2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	m_comborow.ResetContent();
	m_comborow.AddString(_T("20"));
	m_comborow.AddString(_T("21"));
	m_comborow.AddString(_T("22"));
	m_comborow.AddString(_T("23"));
	m_comborow.AddString(_T("24"));
	m_comborow.AddString(_T("25"));
	m_comborow.AddString(_T("26"));
	m_comborow.AddString(_T("27"));
	m_comborow.AddString(_T("28"));
	m_comborow.AddString(_T("29"));
	m_comborow.AddString(_T("30"));
	m_comborow.AddString(_T("31"));
	m_comborow.AddString(_T("32"));
	m_comborow.AddString(_T("33"));
	m_comborow.AddString(_T("34"));
	m_comborow.AddString(_T("35"));
	m_comborow.AddString(_T("36"));
	m_comborow.AddString(_T("37"));
	m_comborow.AddString(_T("38"));
	m_comborow.AddString(_T("39"));
	m_comborow.AddString(_T("40"));
}


void CMFCApplication2Dlg::OnCbnSelchangeCombo2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	int nSel;
	// ��ȡ��Ͽ�ؼ����б����ѡ���������   
	nSel = m_comborow.GetCurSel();
	nSel += 20;
	m_row = nSel;
	vector<vector<int>> tmp(m_row, vector<int>(m_col, 0));
	maps = tmp;

	KillTimer(1);
	Invalidate(false);
	UpdateWindow();
	OnPaint();
	
	SetTimer(1, 1000, NULL);
}


void CMFCApplication2Dlg::OnCbnSelchangeCombo3()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	int nSel;
	// ��ȡ��Ͽ�ؼ����б����ѡ���������   
	nSel = m_comborow.GetCurSel();
	nSel += 20;
	m_col = nSel;
	vector<vector<int>> tmp(m_row, vector<int>(m_col, 0));
	maps = tmp;

	KillTimer(1);
	Invalidate(false);
	UpdateWindow();
	OnPaint();

	SetTimer(1, 1000, NULL);
}


void CMFCApplication2Dlg::OnCbnSetfocusCombo3()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	m_combocol.ResetContent();
	m_combocol.AddString(_T("20"));
	m_combocol.AddString(_T("21"));
	m_combocol.AddString(_T("22"));
	m_combocol.AddString(_T("23"));
	m_combocol.AddString(_T("24"));
	m_combocol.AddString(_T("25"));
	m_combocol.AddString(_T("26"));
	m_combocol.AddString(_T("27"));
	m_combocol.AddString(_T("28"));
	m_combocol.AddString(_T("29"));
	m_combocol.AddString(_T("30"));
	m_combocol.AddString(_T("31"));
	m_combocol.AddString(_T("32"));
	m_combocol.AddString(_T("33"));
	m_combocol.AddString(_T("34"));
	m_combocol.AddString(_T("35"));
	m_combocol.AddString(_T("36"));
	m_combocol.AddString(_T("37"));
	m_combocol.AddString(_T("38"));
	m_combocol.AddString(_T("39"));
	m_combocol.AddString(_T("40"));
}





void CMFCApplication2Dlg::OnMouseLeave()
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ

	CDialogEx::OnMouseLeave();
}


void CMFCApplication2Dlg::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	m_pointx = point.x;
	m_pointy = point.y;
	

	//safety
	int x = (m_pointy - 20) / 20;
	int y = (m_pointx - 20) / 20 - 1;

	if (x >= 0 && x < m_row  && y >= 0 && y < m_col ) {
		KillTimer(1);
		maps[x][y] = maps[x][y] == 1 ? 0 : 1;
	}
	Invalidate(false);
	UpdateWindow();
	OnPaint();
	CDialogEx::OnLButtonDown(nFlags, point);
}


void CMFCApplication2Dlg::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������

	CDialogEx::OnOK();
}


void CMFCApplication2Dlg::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	SetTimer(1, 1000, NULL);
}


void CMFCApplication2Dlg::OnBnClickedButton2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	KillTimer(1);
}




void CMFCApplication2Dlg::OnBnClickedButton3()
{
	KillTimer(1);
	vector<vector<int>> tmp ( m_row, vector<int>(m_col, 0));
	maps = tmp;
	int x = rand() % 4;
	switch (x)
	{
	case 0:
		maps[7][10] = 1;
		maps[8][9] = 1;
		maps[8][10] = 1;
		maps[8][11] = 1;
		maps[9][9] = 1;
		maps[9][11] = 1;
		maps[10][10] = 1;
		SetTimer(1, 1000, NULL);
		break;
	case 1:
		for (int i = 0; i < 10; ++i) {
			maps[10][3 + i] = 1;
		}
		SetTimer(1, 1000, NULL);
		break;

	case 2:
		maps[5][5] = 1;
		maps[5][6] = 1;
		maps[5][8] = 1;
		maps[5][9] = 1;
		maps[6][5] = 1;
		maps[6][6] = 1;
		maps[6][8] = 1;
		maps[6][9] = 1;
		maps[7][6] = 1;
		maps[7][8] = 1;
		maps[8][4] = 1;
		maps[8][6] = 1;
		maps[8][8] = 1;
		maps[8][10] = 1;
		maps[9][4] = 1;
		maps[9][6] = 1;
		maps[9][8] = 1;
		maps[9][10] = 1;
		SetTimer(1, 1000, NULL);
		break;
	case 3:
		for (int i = 0; i < 5; ++i) {
			maps[i+7][6] = 1;
			maps[i+7][10] = 1;
		}
		maps[12][8] = 1;
		maps[12][8] = 1;
		SetTimer(1, 1000, NULL);
		break;
	default:
		break;
	}
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void CMFCApplication2Dlg::OnBnClickedButton4()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	vector<vector<int>> tmp(m_row, vector<int>(m_col, 0));
	maps = tmp;
	
}


void CMFCApplication2Dlg::playgame(int row, int col) {
	vector<vector<int>> tmp = maps;
	for (int i = 0; i<row; i++) {
		for (int j = 0; j<col; ++j) {
			int numcells = getCells(tmp, i, j, row, col);
			LifeorDead(i, j, numcells);
		}
	}
}

int CMFCApplication2Dlg::getCells(vector<vector<int>>& map, int x, int y, int row, int col) {
	if (x >= row || y >= col) {
		return 0;
	}
	vector<int> dre1 = { -1, -1, -1, 0, 0, 1, 1, 1 };
	vector<int> dre2 = { -1, 0, 1, -1, 1, -1, 0, 1 };
	int res = 0;
	for (int i = 0; i<8; ++i) {
		int xx = x + dre1[i], yy = y + dre2[i];
		if (xx >= 0 && xx < row && yy >= 0 && yy < col && map[xx][yy] == 1) {
			++res;
		}
	}
	return res;
}

void CMFCApplication2Dlg::LifeorDead(int x, int y, int num) {
	if (num == 3) {
		maps[x][y] = 1;
	}
	else if (num != 2) {
		maps[x][y] = 0;
	}
}


void CMFCApplication2Dlg::OnCbnSelchangeCombo1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	int nSel;
	// ��ȡ��Ͽ�ؼ����б����ѡ���������   
	nSel = m_combo.GetCurSel();
	nSel += 1;

	KillTimer(1);
	SetTimer(1, nSel*nSel * 100, NULL);
}
