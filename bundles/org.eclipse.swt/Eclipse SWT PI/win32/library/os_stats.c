/*******************************************************************************
* Copyright (c) 2000, 2004 IBM Corporation and others.
* All rights reserved. This program and the accompanying materials
* are made available under the terms of the Common Public License v1.0
* which accompanies this distribution, and is available at
* http://www.eclipse.org/legal/cpl-v10.html
* 
* Contributors:
*     IBM Corporation - initial API and implementation
*******************************************************************************/

#include "swt.h"
#include "os_stats.h"

#ifdef NATIVE_STATS

int OS_nativeFunctionCount = 589;
int OS_nativeFunctionCallCount[589];
char * OS_nativeFunctionNames[] = {
	"AbortDoc",
	"ActivateKeyboardLayout",
	"AdjustWindowRectEx",
	"Arc",
	"BeginDeferWindowPos",
	"BeginPaint",
	"BitBlt",
	"BringWindowToTop",
	"Call",
	"CallNextHookEx",
	"CallWindowProcA",
	"CallWindowProcW",
	"CharLowerA",
	"CharLowerW",
	"CharUpperA",
	"CharUpperW",
	"CheckMenuItem",
	"ChooseColorA",
	"ChooseColorW",
	"ChooseFontA",
	"ChooseFontW",
	"ClientToScreen",
	"CloseClipboard",
	"CoCreateInstance",
	"CombineRgn",
	"CommDlgExtendedError",
	"CommandBar_1AddAdornments",
	"CommandBar_1Create",
	"CommandBar_1Destroy",
	"CommandBar_1DrawMenuBar",
	"CommandBar_1Height",
	"CommandBar_1InsertMenubarEx",
	"CommandBar_1Show",
	"CopyImage",
	"CreateAcceleratorTableA",
	"CreateAcceleratorTableW",
	"CreateBitmap",
	"CreateCaret",
	"CreateCompatibleBitmap",
	"CreateCompatibleDC",
	"CreateCursor",
	"CreateDCA",
	"CreateDCW",
	"CreateDIBSection",
	"CreateFontIndirectA__I",
	"CreateFontIndirectA__Lorg_eclipse_swt_internal_win32_LOGFONTA_2",
	"CreateFontIndirectW__I",
	"CreateFontIndirectW__Lorg_eclipse_swt_internal_win32_LOGFONTW_2",
	"CreateIconIndirect",
	"CreateMenu",
	"CreatePalette",
	"CreatePatternBrush",
	"CreatePen",
	"CreatePolygonRgn",
	"CreatePopupMenu",
	"CreateRectRgn",
	"CreateSolidBrush",
	"CreateStreamOnHGlobal",
	"CreateWindowExA",
	"CreateWindowExW",
	"DefFrameProcA",
	"DefFrameProcW",
	"DefMDIChildProcA",
	"DefMDIChildProcW",
	"DefWindowProcA",
	"DefWindowProcW",
	"DeferWindowPos",
	"DeleteDC",
	"DeleteMenu",
	"DeleteObject",
	"DestroyAcceleratorTable",
	"DestroyCaret",
	"DestroyCursor",
	"DestroyIcon",
	"DestroyMenu",
	"DestroyWindow",
	"DispatchMessageA",
	"DispatchMessageW",
	"DragDetect",
	"DragFinish",
	"DragQueryFileA",
	"DragQueryFileW",
	"DrawEdge",
	"DrawFocusRect",
	"DrawFrameControl",
	"DrawIconEx",
	"DrawMenuBar",
	"DrawStateA",
	"DrawStateW",
	"DrawTextA",
	"DrawTextW",
	"Ellipse",
	"EnableMenuItem",
	"EnableScrollBar",
	"EnableWindow",
	"EndDeferWindowPos",
	"EndDoc",
	"EndPage",
	"EndPaint",
	"EnumDisplayMonitors",
	"EnumFontFamiliesA",
	"EnumFontFamiliesExA",
	"EnumFontFamiliesExW",
	"EnumFontFamiliesW",
	"EnumSystemLanguageGroupsA",
	"EnumSystemLanguageGroupsW",
	"EnumSystemLocalesA",
	"EnumSystemLocalesW",
	"EqualRect",
	"EqualRgn",
	"ExpandEnvironmentStringsA",
	"ExpandEnvironmentStringsW",
	"ExtCreatePen",
	"ExtTextOutA",
	"ExtTextOutW",
	"ExtractIconExA",
	"ExtractIconExW",
	"FillRect",
	"FindWindowA",
	"FindWindowW",
	"FormatMessageA",
	"FormatMessageW",
	"FreeLibrary",
	"GdiSetBatchLimit",
	"GetACP",
	"GetActiveWindow",
	"GetBkColor",
	"GetCapture",
	"GetCaretPos",
	"GetCharABCWidthsA",
	"GetCharABCWidthsW",
	"GetCharWidthA",
	"GetCharWidthW",
	"GetCharacterPlacementA",
	"GetCharacterPlacementW",
	"GetClassInfoA",
	"GetClassInfoW",
	"GetClientRect",
	"GetClipBox",
	"GetClipRgn",
	"GetClipboardData",
	"GetClipboardFormatNameA",
	"GetClipboardFormatNameW",
	"GetComboBoxInfo",
	"GetCurrentObject",
	"GetCurrentProcessId",
	"GetCurrentThreadId",
	"GetCursor",
	"GetCursorPos",
	"GetDC",
	"GetDCEx",
	"GetDIBColorTable",
	"GetDIBits",
	"GetDesktopWindow",
	"GetDeviceCaps",
	"GetDialogBaseUnits",
	"GetDlgItem",
	"GetDoubleClickTime",
	"GetFocus",
	"GetFontLanguageInfo",
	"GetGUIThreadInfo",
	"GetIconInfo",
	"GetKeyNameTextA",
	"GetKeyNameTextW",
	"GetKeyState",
	"GetKeyboardLayout",
	"GetKeyboardLayoutList",
	"GetKeyboardState",
	"GetLastActivePopup",
	"GetLastError",
	"GetLayout",
	"GetLibraryHandle",
	"GetLocaleInfoA",
	"GetLocaleInfoW",
	"GetMenu",
	"GetMenuBarInfo",
	"GetMenuDefaultItem",
	"GetMenuInfo",
	"GetMenuItemCount",
	"GetMenuItemInfoA",
	"GetMenuItemInfoW",
	"GetMenuItemRect",
	"GetMessageA",
	"GetMessagePos",
	"GetMessageTime",
	"GetMessageW",
	"GetModuleHandleA",
	"GetModuleHandleW",
	"GetMonitorInfoA",
	"GetMonitorInfoW",
	"GetNearestPaletteIndex",
	"GetObjectA__IILorg_eclipse_swt_internal_win32_BITMAP_2",
	"GetObjectA__IILorg_eclipse_swt_internal_win32_DIBSECTION_2",
	"GetObjectA__IILorg_eclipse_swt_internal_win32_EXTLOGPEN_2",
	"GetObjectA__IILorg_eclipse_swt_internal_win32_LOGBRUSH_2",
	"GetObjectA__IILorg_eclipse_swt_internal_win32_LOGFONTA_2",
	"GetObjectA__IILorg_eclipse_swt_internal_win32_LOGPEN_2",
	"GetObjectW__IILorg_eclipse_swt_internal_win32_BITMAP_2",
	"GetObjectW__IILorg_eclipse_swt_internal_win32_DIBSECTION_2",
	"GetObjectW__IILorg_eclipse_swt_internal_win32_EXTLOGPEN_2",
	"GetObjectW__IILorg_eclipse_swt_internal_win32_LOGBRUSH_2",
	"GetObjectW__IILorg_eclipse_swt_internal_win32_LOGFONTW_2",
	"GetObjectW__IILorg_eclipse_swt_internal_win32_LOGPEN_2",
	"GetOpenFileNameA",
	"GetOpenFileNameW",
	"GetPaletteEntries",
	"GetParent",
	"GetPixel",
	"GetProcAddress",
	"GetProcessHeap",
	"GetProfileStringA",
	"GetProfileStringW",
	"GetROP2",
	"GetRandomRgn",
	"GetRegionData",
	"GetRgnBox",
	"GetSaveFileNameA",
	"GetSaveFileNameW",
	"GetScrollInfo",
	"GetStockObject",
	"GetSysColor",
	"GetSysColorBrush",
	"GetSystemMenu",
	"GetSystemMetrics",
	"GetSystemPaletteEntries",
	"GetTextCharset",
	"GetTextColor",
	"GetTextExtentPoint32A",
	"GetTextExtentPoint32W",
	"GetTextMetricsA",
	"GetTextMetricsW",
	"GetTickCount",
	"GetUpdateRect",
	"GetUpdateRgn",
	"GetVersionExA",
	"GetVersionExW",
	"GetWindow",
	"GetWindowLongA",
	"GetWindowLongW",
	"GetWindowPlacement",
	"GetWindowRect",
	"GetWindowRgn",
	"GetWindowTextA",
	"GetWindowTextLengthA",
	"GetWindowTextLengthW",
	"GetWindowTextW",
	"GetWindowThreadProcessId",
	"GlobalAlloc",
	"GlobalFree",
	"GlobalLock",
	"GlobalSize",
	"GlobalUnlock",
	"GradientFill",
	"HeapAlloc",
	"HeapFree",
	"HideCaret",
	"IIDFromString",
	"ImageList_1Add",
	"ImageList_1AddMasked",
	"ImageList_1Create",
	"ImageList_1Destroy",
	"ImageList_1GetIcon",
	"ImageList_1GetIconSize",
	"ImageList_1GetImageCount",
	"ImageList_1Remove",
	"ImageList_1Replace",
	"ImageList_1ReplaceIcon",
	"ImageList_1SetIconSize",
	"ImmAssociateContext",
	"ImmCreateContext",
	"ImmDestroyContext",
	"ImmGetCompositionFontA",
	"ImmGetCompositionFontW",
	"ImmGetCompositionStringA",
	"ImmGetCompositionStringW",
	"ImmGetContext",
	"ImmGetConversionStatus",
	"ImmGetDefaultIMEWnd",
	"ImmGetOpenStatus",
	"ImmReleaseContext",
	"ImmSetCompositionFontA",
	"ImmSetCompositionFontW",
	"ImmSetCompositionWindow",
	"ImmSetConversionStatus",
	"ImmSetOpenStatus",
	"InitCommonControls",
	"InitCommonControlsEx",
	"InsertMenuA",
	"InsertMenuItemA",
	"InsertMenuItemW",
	"InsertMenuW",
	"IntersectRect",
	"InvalidateRect",
	"InvalidateRgn",
	"IsDBCSLeadByte",
	"IsIconic",
	"IsPPC",
	"IsSP",
	"IsWindowEnabled",
	"IsWindowVisible",
	"IsZoomed",
	"KillTimer",
	"LineTo",
	"LoadBitmapA",
	"LoadBitmapW",
	"LoadCursorA",
	"LoadCursorW",
	"LoadIconA",
	"LoadIconW",
	"LoadImageA__IIIIII",
	"LoadImageA__I_3BIIII",
	"LoadImageW__IIIIII",
	"LoadImageW__I_3CIIII",
	"LoadLibraryA",
	"LoadLibraryW",
	"LoadStringA",
	"LoadStringW",
	"LocalFree",
	"MapVirtualKeyA",
	"MapVirtualKeyW",
	"MapWindowPoints__IILorg_eclipse_swt_internal_win32_POINT_2I",
	"MapWindowPoints__IILorg_eclipse_swt_internal_win32_RECT_2I",
	"MessageBeep",
	"MessageBoxA",
	"MessageBoxW",
	"MonitorFromWindow",
	"MoveMemory__ILorg_eclipse_swt_internal_win32_DROPFILES_2I",
	"MoveMemory__ILorg_eclipse_swt_internal_win32_GRADIENT_1RECT_2I",
	"MoveMemory__ILorg_eclipse_swt_internal_win32_KEYBDINPUT_2I",
	"MoveMemory__ILorg_eclipse_swt_internal_win32_LOGFONTA_2I",
	"MoveMemory__ILorg_eclipse_swt_internal_win32_LOGFONTW_2I",
	"MoveMemory__ILorg_eclipse_swt_internal_win32_MEASUREITEMSTRUCT_2I",
	"MoveMemory__ILorg_eclipse_swt_internal_win32_MINMAXINFO_2I",
	"MoveMemory__ILorg_eclipse_swt_internal_win32_MOUSEINPUT_2I",
	"MoveMemory__ILorg_eclipse_swt_internal_win32_MSG_2I",
	"MoveMemory__ILorg_eclipse_swt_internal_win32_NMLVCUSTOMDRAW_2I",
	"MoveMemory__ILorg_eclipse_swt_internal_win32_NMLVDISPINFO_2I",
	"MoveMemory__ILorg_eclipse_swt_internal_win32_NMTTDISPINFOA_2I",
	"MoveMemory__ILorg_eclipse_swt_internal_win32_NMTTDISPINFOW_2I",
	"MoveMemory__ILorg_eclipse_swt_internal_win32_NMTVCUSTOMDRAW_2I",
	"MoveMemory__ILorg_eclipse_swt_internal_win32_RECT_2I",
	"MoveMemory__ILorg_eclipse_swt_internal_win32_TRIVERTEX_2I",
	"MoveMemory__ILorg_eclipse_swt_internal_win32_WINDOWPOS_2I",
	"MoveMemory__I_3BI",
	"MoveMemory__I_3CI",
	"MoveMemory__I_3DI",
	"MoveMemory__I_3FI",
	"MoveMemory__I_3II",
	"MoveMemory__I_3SI",
	"MoveMemory__Lorg_eclipse_swt_internal_win32_BITMAPINFOHEADER_2_3BI",
	"MoveMemory__Lorg_eclipse_swt_internal_win32_DRAWITEMSTRUCT_2II",
	"MoveMemory__Lorg_eclipse_swt_internal_win32_HDITEM_2II",
	"MoveMemory__Lorg_eclipse_swt_internal_win32_HELPINFO_2II",
	"MoveMemory__Lorg_eclipse_swt_internal_win32_LOGFONTA_2II",
	"MoveMemory__Lorg_eclipse_swt_internal_win32_LOGFONTW_2II",
	"MoveMemory__Lorg_eclipse_swt_internal_win32_MEASUREITEMSTRUCT_2II",
	"MoveMemory__Lorg_eclipse_swt_internal_win32_MINMAXINFO_2II",
	"MoveMemory__Lorg_eclipse_swt_internal_win32_MSG_2II",
	"MoveMemory__Lorg_eclipse_swt_internal_win32_NMCUSTOMDRAW_2II",
	"MoveMemory__Lorg_eclipse_swt_internal_win32_NMHDR_2II",
	"MoveMemory__Lorg_eclipse_swt_internal_win32_NMHEADER_2II",
	"MoveMemory__Lorg_eclipse_swt_internal_win32_NMLISTVIEW_2II",
	"MoveMemory__Lorg_eclipse_swt_internal_win32_NMLVCUSTOMDRAW_2II",
	"MoveMemory__Lorg_eclipse_swt_internal_win32_NMLVDISPINFO_2II",
	"MoveMemory__Lorg_eclipse_swt_internal_win32_NMLVFINDITEM_2II",
	"MoveMemory__Lorg_eclipse_swt_internal_win32_NMREBARCHEVRON_2II",
	"MoveMemory__Lorg_eclipse_swt_internal_win32_NMRGINFO_2II",
	"MoveMemory__Lorg_eclipse_swt_internal_win32_NMTBHOTITEM_2II",
	"MoveMemory__Lorg_eclipse_swt_internal_win32_NMTOOLBAR_2II",
	"MoveMemory__Lorg_eclipse_swt_internal_win32_NMTTDISPINFOA_2II",
	"MoveMemory__Lorg_eclipse_swt_internal_win32_NMTTDISPINFOW_2II",
	"MoveMemory__Lorg_eclipse_swt_internal_win32_NMTVCUSTOMDRAW_2II",
	"MoveMemory__Lorg_eclipse_swt_internal_win32_POINT_2II",
	"MoveMemory__Lorg_eclipse_swt_internal_win32_SCRIPT_1ITEM_2II",
	"MoveMemory__Lorg_eclipse_swt_internal_win32_SCRIPT_1LOGATTR_2II",
	"MoveMemory__Lorg_eclipse_swt_internal_win32_SCRIPT_1PROPERTIES_2II",
	"MoveMemory__Lorg_eclipse_swt_internal_win32_TVITEM_2II",
	"MoveMemory__Lorg_eclipse_swt_internal_win32_WINDOWPOS_2II",
	"MoveMemory___3BII",
	"MoveMemory___3BLorg_eclipse_swt_internal_win32_ACCEL_2I",
	"MoveMemory___3BLorg_eclipse_swt_internal_win32_BITMAPINFOHEADER_2I",
	"MoveMemory___3CII",
	"MoveMemory___3DII",
	"MoveMemory___3FII",
	"MoveMemory___3III",
	"MoveMemory___3SII",
	"MoveToEx",
	"MsgWaitForMultipleObjectsEx",
	"MultiByteToWideChar__IIII_3CI",
	"MultiByteToWideChar__II_3BI_3CI",
	"NotifyWinEvent",
	"OffsetRgn",
	"OleInitialize",
	"OleUninitialize",
	"OpenClipboard",
	"PatBlt",
	"PeekMessageA",
	"PeekMessageW",
	"Pie",
	"Polygon",
	"Polyline",
	"PostMessageA",
	"PostMessageW",
	"PostThreadMessageA",
	"PostThreadMessageW",
	"PrintDlgA",
	"PrintDlgW",
	"PtInRect",
	"PtInRegion",
	"RealizePalette",
	"RectInRegion",
	"Rectangle",
	"RedrawWindow",
	"RegCloseKey",
	"RegEnumKeyExA",
	"RegEnumKeyExW",
	"RegOpenKeyExA",
	"RegOpenKeyExW",
	"RegQueryInfoKeyA",
	"RegQueryInfoKeyW",
	"RegQueryValueExA",
	"RegQueryValueExW",
	"RegisterClassA",
	"RegisterClassW",
	"RegisterClipboardFormatA",
	"RegisterClipboardFormatW",
	"RegisterWindowMessageA",
	"RegisterWindowMessageW",
	"ReleaseCapture",
	"ReleaseDC",
	"RemoveMenu",
	"RestoreDC",
	"RoundRect",
	"SHBrowseForFolderA",
	"SHBrowseForFolderW",
	"SHCreateMenuBar",
	"SHGetMalloc",
	"SHGetPathFromIDListA",
	"SHGetPathFromIDListW",
	"SHHandleWMSettingChange",
	"SHRecognizeGesture",
	"SHSendBackToFocusWindow",
	"SHSetAppKeyWndAssoc",
	"SHSipPreference",
	"SaveDC",
	"ScreenToClient",
	"ScriptBreak",
	"ScriptCPtoX",
	"ScriptCacheGetHeight",
	"ScriptFreeCache",
	"ScriptGetFontProperties",
	"ScriptGetLogicalWidths",
	"ScriptGetProperties",
	"ScriptItemize",
	"ScriptLayout",
	"ScriptPlace",
	"ScriptShape",
	"ScriptTextOut",
	"ScriptXtoCP",
	"ScrollWindowEx",
	"SelectClipRgn",
	"SelectObject",
	"SelectPalette",
	"SendInput",
	"SendMessageA__IIII",
	"SendMessageA__IIILorg_eclipse_swt_internal_win32_LVCOLUMN_2",
	"SendMessageA__IIILorg_eclipse_swt_internal_win32_LVHITTESTINFO_2",
	"SendMessageA__IIILorg_eclipse_swt_internal_win32_LVITEM_2",
	"SendMessageA__IIILorg_eclipse_swt_internal_win32_MARGINS_2",
	"SendMessageA__IIILorg_eclipse_swt_internal_win32_REBARBANDINFO_2",
	"SendMessageA__IIILorg_eclipse_swt_internal_win32_RECT_2",
	"SendMessageA__IIILorg_eclipse_swt_internal_win32_TBBUTTONINFO_2",
	"SendMessageA__IIILorg_eclipse_swt_internal_win32_TBBUTTON_2",
	"SendMessageA__IIILorg_eclipse_swt_internal_win32_TCITEM_2",
	"SendMessageA__IIILorg_eclipse_swt_internal_win32_TOOLINFO_2",
	"SendMessageA__IIILorg_eclipse_swt_internal_win32_TVHITTESTINFO_2",
	"SendMessageA__IIILorg_eclipse_swt_internal_win32_TVINSERTSTRUCT_2",
	"SendMessageA__IIILorg_eclipse_swt_internal_win32_TVITEM_2",
	"SendMessageA__III_3B",
	"SendMessageA__III_3I",
	"SendMessageA__III_3S",
	"SendMessageA__II_3II",
	"SendMessageA__II_3I_3I",
	"SendMessageW__IIII",
	"SendMessageW__IIILorg_eclipse_swt_internal_win32_LVCOLUMN_2",
	"SendMessageW__IIILorg_eclipse_swt_internal_win32_LVHITTESTINFO_2",
	"SendMessageW__IIILorg_eclipse_swt_internal_win32_LVITEM_2",
	"SendMessageW__IIILorg_eclipse_swt_internal_win32_MARGINS_2",
	"SendMessageW__IIILorg_eclipse_swt_internal_win32_REBARBANDINFO_2",
	"SendMessageW__IIILorg_eclipse_swt_internal_win32_RECT_2",
	"SendMessageW__IIILorg_eclipse_swt_internal_win32_TBBUTTONINFO_2",
	"SendMessageW__IIILorg_eclipse_swt_internal_win32_TBBUTTON_2",
	"SendMessageW__IIILorg_eclipse_swt_internal_win32_TCITEM_2",
	"SendMessageW__IIILorg_eclipse_swt_internal_win32_TOOLINFO_2",
	"SendMessageW__IIILorg_eclipse_swt_internal_win32_TVHITTESTINFO_2",
	"SendMessageW__IIILorg_eclipse_swt_internal_win32_TVINSERTSTRUCT_2",
	"SendMessageW__IIILorg_eclipse_swt_internal_win32_TVITEM_2",
	"SendMessageW__III_3C",
	"SendMessageW__III_3I",
	"SendMessageW__III_3S",
	"SendMessageW__II_3II",
	"SendMessageW__II_3I_3I",
	"SetActiveWindow",
	"SetBkColor",
	"SetBkMode",
	"SetCapture",
	"SetCaretPos",
	"SetClipboardData",
	"SetCursor",
	"SetCursorPos",
	"SetDIBColorTable",
	"SetErrorMode",
	"SetFocus",
	"SetForegroundWindow",
	"SetLayout",
	"SetMenu",
	"SetMenuDefaultItem",
	"SetMenuInfo",
	"SetMenuItemInfoA",
	"SetMenuItemInfoW",
	"SetPaletteEntries",
	"SetParent",
	"SetPixel",
	"SetROP2",
	"SetRect",
	"SetRectRgn",
	"SetScrollInfo",
	"SetStretchBltMode",
	"SetTextAlign",
	"SetTextColor",
	"SetTimer",
	"SetWindowLongA",
	"SetWindowLongW",
	"SetWindowPlacement",
	"SetWindowPos",
	"SetWindowRgn",
	"SetWindowTextA",
	"SetWindowTextW",
	"SetWindowsHookExA",
	"SetWindowsHookExW",
	"ShellExecuteExA",
	"ShellExecuteExW",
	"Shell_1NotifyIconA",
	"Shell_1NotifyIconW",
	"ShowCaret",
	"ShowOwnedPopups",
	"ShowScrollBar",
	"ShowWindow",
	"SipGetInfo",
	"StartDocA",
	"StartDocW",
	"StartPage",
	"StretchBlt",
	"SystemParametersInfoA__IILorg_eclipse_swt_internal_win32_HIGHCONTRAST_2I",
	"SystemParametersInfoA__IILorg_eclipse_swt_internal_win32_NONCLIENTMETRICSA_2I",
	"SystemParametersInfoA__IILorg_eclipse_swt_internal_win32_RECT_2I",
	"SystemParametersInfoA__II_3II",
	"SystemParametersInfoW__IILorg_eclipse_swt_internal_win32_HIGHCONTRAST_2I",
	"SystemParametersInfoW__IILorg_eclipse_swt_internal_win32_NONCLIENTMETRICSW_2I",
	"SystemParametersInfoW__IILorg_eclipse_swt_internal_win32_RECT_2I",
	"SystemParametersInfoW__II_3II",
	"ToAscii",
	"ToUnicode",
	"TrackMouseEvent",
	"TrackPopupMenu",
	"TranslateAcceleratorA",
	"TranslateAcceleratorW",
	"TranslateCharsetInfo",
	"TranslateMDISysAccel",
	"TranslateMessage",
	"TransparentImage",
	"UnhookWindowsHookEx",
	"UnregisterClassA",
	"UnregisterClassW",
	"UpdateWindow",
	"ValidateRect",
	"VkKeyScanA",
	"VkKeyScanW",
	"VtblCall__II",
	"VtblCall__III",
	"VtblCall__IIIII_3I",
	"VtblCall__II_3CII_3I_3I",
	"WaitMessage",
	"WideCharToMultiByte__II_3CIII_3B_3Z",
	"WideCharToMultiByte__II_3CI_3BI_3B_3Z",
	"WindowFromDC",
	"WindowFromPoint",
	"strlen",
	"wcslen",
};

#define STATS_NATIVE(func) Java_org_eclipse_swt_tools_internal_NativeStats_##func

JNIEXPORT jint JNICALL STATS_NATIVE(OS_1GetFunctionCount)
	(JNIEnv *env, jclass that)
{
	return OS_nativeFunctionCount;
}

JNIEXPORT jstring JNICALL STATS_NATIVE(OS_1GetFunctionName)
	(JNIEnv *env, jclass that, jint index)
{
	return (*env)->NewStringUTF(env, OS_nativeFunctionNames[index]);
}

JNIEXPORT jint JNICALL STATS_NATIVE(OS_1GetFunctionCallCount)
	(JNIEnv *env, jclass that, jint index)
{
	return OS_nativeFunctionCallCount[index];
}

#endif
