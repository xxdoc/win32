// Wnd.cpp: implementation of the CWnd class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Wnd.h"

namespace WinObj
{
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CWnd::CWnd(HWND hWnd) : CHandle<HWND>(hWnd)
{
}

CWnd::~CWnd()
{
}

void CWnd::Show()
{
	::ShowWindow(GetHandle(), SW_SHOWNORMAL);
}

bool CWnd::IsDialogMessage(LPMSG msg)
{
	return ::IsDialogMessage(GetHandle(), msg) != 0;
}

bool CWnd::MoveDlgItem(int dlgItem, int x, int y, int width, int height, bool repaint)
{
	HWND hChildWnd = ::GetDlgItem(GetHandle(), dlgItem);
	if (hChildWnd)
	{
		return ::MoveWindow(hChildWnd, x, y, width, height, repaint) != 0;
	}
	else
	{
		return false;
	}
}

bool CWnd::GetClientRect(LPRECT rect)
{
	return ::GetClientRect(GetHandle(), rect) != 0;
}

bool CWnd::InvalidateRect(LPRECT rect, bool repaint)
{
	return ::InvalidateRect(GetHandle(), rect, repaint) != 0;
}

bool CWnd::DestroyWindow()
{
	return ::DestroyWindow(GetHandle()) != 0;
}

HDC CWnd::BeginPaint(LPPAINTSTRUCT ps)
{
	return ::BeginPaint(GetHandle(), ps);
}

bool CWnd::EndPaint(LPPAINTSTRUCT ps)
{
	return ::EndPaint(GetHandle(), ps) != 0;
}

UINT CWnd::GetDlgItemText(int id, LPTSTR buffer, int maxCharacters)
{
	return ::GetDlgItemText(GetHandle(), id, buffer, maxCharacters);
}

UINT CWnd::GetDlgItemInt(int id, bool* translated, bool bSigned)
{
	BOOL bTranslated;
	UINT result = ::GetDlgItemInt(GetHandle(), id, &bTranslated, bSigned);
	*translated = bTranslated != 0;
	return result;
}

bool CWnd::SetDlgItemInt(int id, int value, bool bSigned)
{
	return ::SetDlgItemInt(GetHandle(), id, value, bSigned) != 0;
}

int CWnd::GetDlgItemTextLength(int id)
{
	HWND hChild = ::GetDlgItem(GetHandle(), id);
	if (hChild != NULL)
	{
		return ::GetWindowTextLength(hChild);
	}
	else
	{
		return 0;
	}
}

LRESULT CWnd::SendDlgItemMessage(int id, UINT msg, WPARAM wParam, LPARAM lParam)
{
	return ::SendDlgItemMessage(GetHandle(), id, msg, wParam, lParam);
}

bool CWnd::GetDlgItemClientRect(int id, LPRECT rect)
{
	HWND hChild = ::GetDlgItem(GetHandle(), id);
	if (hChild != NULL)
	{
		return ::GetClientRect(hChild, rect) != 0;
	}
	else
	{
		return false;
	}
}

UINT CWnd::IsDlgButtonChecked(int dlgItem)
{
	return ::IsDlgButtonChecked(GetHandle(), dlgItem);
}

bool CWnd::CheckDlgButton(int dlgItem, UINT flags)
{
	return ::CheckDlgButton(GetHandle(), dlgItem, flags) != 0;
}

bool CWnd::CheckRadioButton(int first, int last, int checked)
{
	return ::CheckRadioButton(GetHandle(), first, last, checked) != 0;
}

bool CWnd::EnableDlgItem(int dlgItem, bool enable)
{
	HWND hChild = ::GetDlgItem(GetHandle(), dlgItem);
	if (hChild != NULL)
	{
		return ::EnableWindow(hChild, enable) != 0;
	}
	else
	{
		return false;
	}
}

bool CWnd::ShowDlgItem(int dlgItem, int flags)
{
	HWND hChild = ::GetDlgItem(GetHandle(), dlgItem);
	if (hChild != NULL)
	{
		return ::ShowWindow(hChild, flags) != 0;
	}
	else
	{
		return false;
	}
}

int CWnd::MsgBox(LPCTSTR text, LPCTSTR caption, UINT flags)
{
	return ::MessageBox(GetHandle(), text, caption, flags);
}

} // namespace WinObj
