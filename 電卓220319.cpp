#include <Windows.h>
#include <windowsx.h>
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

        Edit_SetText(hEWnd, "0");
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

            strcat_s(str[mode], sizeof(str[mode]), ".");
            Edit_SetText(hEWnd, str[mode]);
            return TRUE;
        case IDC_BUTTON1:
            strcat_s(str[mode], sizeof(str[mode]), "1");
            Edit_SetText(hEWnd, str[mode]);
            return TRUE;
        case IDC_BUTTON2:
            strcat_s(str[mode], sizeof(str[mode]), "2");
            Edit_SetText(hEWnd, str[mode]);
            return TRUE;
        case IDC_BUTTON3:
            strcat_s(str[mode], sizeof(str[mode]), "3");
            Edit_SetText(hEWnd, str[mode]);
            return TRUE;
        case IDC_BUTTON4:
            strcat_s(str[mode], sizeof(str[mode]), "4");
            Edit_SetText(hEWnd, str[mode]);
            return TRUE;
        case IDC_BUTTON5:
            strcat_s(str[mode], sizeof(str[mode]), "5");
            Edit_SetText(hEWnd, str[mode]);
            return TRUE;
        case IDC_BUTTON6:
            strcat_s(str[mode], sizeof(str[mode]), "6");
            Edit_SetText(hEWnd, str[mode]);
            return TRUE;
        case IDC_BUTTON7:
            strcat_s(str[mode], sizeof(str[mode]), "7");
            Edit_SetText(hEWnd, str[mode]);
            return TRUE;
        case IDC_BUTTON8:
            strcat_s(str[mode], sizeof(str[mode]), "8");
            Edit_SetText(hEWnd, str[mode]);
            return TRUE;
        case IDC_BUTTON9:
            strcat_s(str[mode], sizeof(str[mode]), "9");
            Edit_SetText(hEWnd, str[mode]);
            return TRUE;
        case IDC_BUTTON11:
            strcat_s(str[mode], sizeof(str[mode]), "0");
            Edit_SetText(hEWnd, str[mode]);
            return TRUE;
        case IDC_BUTTON10:
            mode = 1;
            op = plus;
            return TRUE;
        case IDC_BUTTON13:
            mode = 1;
            op = minus;
            return TRUE;
        case IDC_BUTTON14:
            mode = 1;
            op = kake;
            return TRUE;
        case IDC_BUTTON15:
            mode = 1;
            op = wari;
            return TRUE;
        case IDC_BUTTON19:
            strcpy_s(tmp, sizeof(tmp), "-");
            strcpy_s(tmp, sizeof(tmp), str[mode]);
            strcpy_s(str[mode], sizeof(str[mode]), tmp);
            Edit_SetText(hEWnd, str[mode]);
            return TRUE;
        case IDC_BUTTON16:
            switch (op) {
            case plus:
                ans = atof(str[0]) + atof(str[1]);
                break;
            case minus:
                ans = atof(str[0]) - atof(str[1]);
                break;
            case kake:
                ans = atof(str[0]) * atof(str[1]);
                break;
            case wari:
                ans = atof(str[0]) / atof(str[1]);
                break;
            }
            sprintf_s(ans_str, sizeof(ans_str), "%.10f", ans);
            Edit_SetText(hEWnd, ans_str);
            memset(str, '\0', sizeof(str));
            mode = 0;
            return TRUE;
        }
        break;
    }
    return FALSE;
}
