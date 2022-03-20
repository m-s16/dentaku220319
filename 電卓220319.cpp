#include <Windows.h>
#include <windowsx.h>
#include <tchar.h>
#include <string.h> //memset, strcat, strcpy
#include <stdio.h> //sprintf
#include <math.h> //atof
#include <stdlib.h>
#include "resource.h"

INT_PTR CALLBACK DialogProc
(HWND
    , UINT
    , WPARAM
    , LPARAM
);


int APIENTRY WinMain
(HINSTANCE hInstance
	, HINSTANCE
	, LPSTR lpCmdLine
	, int nCmdShow
)
{
	DialogBoxParamA(hInstance
		, MAKEINTRESOURCEA(IDD_DIALOG1)
		, nullptr
		, DialogProc
		, 0
	);
	return 0;
}

INT_PTR CALLBACK DialogProc(HWND hDlg, UINT msg, WPARAM wp, LPARAM lp)
{
    static TCHAR str[2][32], ans_str[32], tmp[32];

    static HWND hEWnd; //エジットボックスのウィンドウハンドル
    static double ans;
    enum { plus, minus, kake, wari };
    static int op, mode; //op:演算の種類　mode:演算子の前か後ろか

    switch (msg) {
    case WM_INITDIALOG:
        hEWnd = GetDlgItem(hDlg, IDC_EDIT1);

        Edit_SetText(hEWnd, TEXT("0"));
        return TRUE;
    case WM_COMMAND:
        switch (LOWORD(wp)) {
        case IDOK:
            EndDialog(hDlg, 0);
            return TRUE;
        case IDC_BUTTON17:
            memset(str[mode], '\0', sizeof(str[mode]));
            Edit_SetText(hEWnd, str[mode]);
            return TRUE;
        case IDC_BUTTON18:
            memset(str, '\0', sizeof(str));
            memset(ans_str, '\0', sizeof(ans_str));
            mode = 0;
            Edit_SetText(hEWnd, ans_str);
            return TRUE;
        case IDC_BUTTON12:

            lstrcat(str[mode],  TEXT("."));
            Edit_SetText(hEWnd, str[mode]);
            return TRUE;
        case IDC_BUTTON1:
            lstrcat(str[mode], TEXT("1"));
            Edit_SetText(hEWnd, str[mode]);
            return TRUE;
        case IDC_BUTTON2:
            lstrcat(str[mode], TEXT("2"));
            Edit_SetText(hEWnd, str[mode]);
            return TRUE;
        case IDC_BUTTON3:
            lstrcat(str[mode], TEXT("3"));
            Edit_SetText(hEWnd, str[mode]);
            return TRUE;
        case IDC_BUTTON4:
            lstrcat(str[mode], TEXT("4"));
            Edit_SetText(hEWnd, str[mode]);
            return TRUE;
        case IDC_BUTTON5:
            lstrcat(str[mode], TEXT("5"));
            Edit_SetText(hEWnd, str[mode]);
            return TRUE;
        case IDC_BUTTON6:
            lstrcat(str[mode], TEXT("6"));
            Edit_SetText(hEWnd, str[mode]);
            return TRUE;
        case IDC_BUTTON7:
            lstrcat(str[mode], TEXT("7"));
            Edit_SetText(hEWnd, str[mode]);
            return TRUE;
        case IDC_BUTTON8:
            lstrcat(str[mode], TEXT("8"));
            Edit_SetText(hEWnd, str[mode]);
            return TRUE;
        case IDC_BUTTON9:
            lstrcat(str[mode], TEXT("9"));
            Edit_SetText(hEWnd, str[mode]);
            return TRUE;
        case IDC_BUTTON11:
            lstrcat(str[mode], TEXT("0"));
            Edit_SetText(hEWnd, str[mode]);
            return TRUE;
        case IDC_BUTTON10:
            mode = 1;
            op = plus;
            Edit_SetText(hEWnd, TEXT("+"));
            return TRUE;
        case IDC_BUTTON13:
            mode = 1;
            op = minus;
            Edit_SetText(hEWnd, TEXT("-"));
            return TRUE;
        case IDC_BUTTON14:
            mode = 1;
            op = kake;
            Edit_SetText(hEWnd, TEXT("x"));
            return TRUE;
        case IDC_BUTTON15:
            mode = 1;
            op = wari;
            Edit_SetText(hEWnd, TEXT("÷"));
            return TRUE;
        case IDC_BUTTON19:
            lstrcpy(tmp,  TEXT("-"));
            lstrcpy(tmp,  str[mode]);
            lstrcpy(str[mode], tmp);
            Edit_SetText(hEWnd, str[mode]);
            return TRUE;
        case IDC_BUTTON16:
            switch (op) {
            case plus:
                ans = _tstof(str[0]) + _tstof(str[1]);
                break;
            case minus:
                ans = _tstof(str[0]) - _tstof(str[1]);
                break;
            case kake:
                ans = _tstof(str[0]) * _tstof(str[1]);
                break;
            case wari:
                ans = _tstof(str[0]) / _tstof(str[1]);
                break;
            }
            _stprintf_s(ans_str, sizeof(ans_str), TEXT("%.10f"), ans);
            Edit_SetText(hEWnd, ans_str);
            memset(str, '\0', sizeof(str));
            mode = 0;
            return TRUE;
        }
        break;
    }
    return FALSE;
}
