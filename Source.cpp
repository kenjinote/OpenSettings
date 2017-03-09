#pragma comment(linker,"\"/manifestdependency:type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='*' publicKeyToken='6595b64144ccf1df' language='*'\"")

#include <windows.h>

TCHAR szClassName[] = TEXT("Window");

typedef struct
{
	LPCTSTR lpszDistract;
	LPCTSTR lpszCommand;
} DATA;

DATA data[] =
{
	{ TEXT("設定のランディング ページ"),TEXT("ms-settings:") },
	{ TEXT("ディスプレイ"),TEXT("ms-settings:screenrotation") },
	{ TEXT("通知とアクション"),TEXT("ms-settings:notifications") },
	{ TEXT("電話"),TEXT("ms-settings:phone") },
	{ TEXT("メッセージング"),TEXT("ms-settings:messaging") },
	{ TEXT("バッテリー節約機能"),TEXT("ms-settings:batterysaver") },
	{ TEXT("バッテリーの使用状況"),TEXT("ms-settings:batterysaver-usagedetails") },
	{ TEXT("電源とスリープ"),TEXT("ms-settings:powersleep") },
	{ TEXT("バージョン情報"),TEXT("ms-settings:about") },
	{ TEXT("暗号化"),TEXT("ms-settings:deviceencryption") },
	{ TEXT("オフライン マップ"),TEXT("ms-settings:maps") },
	{ TEXT("既定のカメラ"),TEXT("ms-settings:camera") },
	{ TEXT("Bluetooth"),TEXT("ms-settings:bluetooth") },
	{ TEXT("接続されたデバイス"),TEXT("ms-settings:connecteddevices") },
	{ TEXT("マウスとタッチパッド"),TEXT("ms-settings:mousetouchpad") },
	{ TEXT("NFC"),TEXT("ms-settings:nfctransactions") },
	{ TEXT("Wi-Fi"),TEXT("ms-settings:network-wifi") },
	{ TEXT("機内モード"),TEXT("ms-settings:network-airplanemode") },
	{ TEXT("データ使用状況"),TEXT("ms-settings:datausage") },
	{ TEXT("携帯ネットワーク & SIM"),TEXT("ms-settings:network-cellular") },
	{ TEXT("モバイルホットスポット"),TEXT("ms-settings:network-mobilehotspot") },
	{ TEXT("プロキシ"),TEXT("ms-settings:network-proxy") },
	{ TEXT("状態"),TEXT("ms-settings:network-status") },
	{ TEXT("個人用設定 (カテゴリ)"),TEXT("ms-settings:personalization") },
	{ TEXT("背景"),TEXT("ms-settings:personalization-background") },
	{ TEXT("カラー"),TEXT("ms-settings:personalization-colors") },
	{ TEXT("サウンド"),TEXT("ms-settings:sounds") },
	{ TEXT("ロック画面"),TEXT("ms-settings:lockscreen") },
	{ TEXT("職場または学校にアクセスする"),TEXT("ms-settings:workplace") },
	{ TEXT("メール & アプリのアカウント"),TEXT("ms-settings:emailandaccounts") },
	{ TEXT("家族とその他のユーザー"),TEXT("ms-settings:otherusers") },
	{ TEXT("サインイン オプション"),TEXT("ms-settings:signinoptions") },
	{ TEXT("設定の同期"),TEXT("ms-settings:sync") },
	{ TEXT("他のユーザー"),TEXT("ms-settings:otherusers") },
	{ TEXT("ユーザーの情報"),TEXT("ms-settings:yourinfo") },
	{ TEXT("日付と時刻"),TEXT("ms-settings:dateandtime") },
	{ TEXT("地域と言語"),TEXT("ms-settings:regionlanguage") },
	{ TEXT("ナレーター"),TEXT("ms-settings:easeofaccess-narrator") },
	{ TEXT("拡大鏡"),TEXT("ms-settings:easeofaccess-magnifier") },
	{ TEXT("ハイ コントラスト"),TEXT("ms-settings:easeofaccess-highcontrast") },
	{ TEXT("字幕"),TEXT("ms-settings:easeofaccess-closedcaptioning") },
	{ TEXT("キーボード"),TEXT("ms-settings:easeofaccess-keyboard") },
	{ TEXT("マウス"),TEXT("ms-settings:easeofaccess-mouse") },
	{ TEXT("その他のオプション"),TEXT("ms-settings:easeofaccess-otheroptions") },
	{ TEXT("位置情報"),TEXT("ms-settings:privacy-location") },
	{ TEXT("カメラ"),TEXT("ms-settings:privacy-webcam") },
	{ TEXT("マイク"),TEXT("ms-settings:privacy-microphone") },
	{ TEXT("アニメーション"),TEXT("ms-settings:privacy-motion") },
	{ TEXT("音声認識、手書き入力、タイピング"),TEXT("ms-settings:privacy-speechtyping") },
	{ TEXT("アカウント情報"),TEXT("ms-settings:privacy-accountinfo") },
	{ TEXT("連絡先"),TEXT("ms-settings:privacy-contacts") },
	{ TEXT("カレンダー"),TEXT("ms-settings:privacy-calendar") },
	{ TEXT("通話履歴"),TEXT("ms-settings:privacy-callhistory") },
	{ TEXT("メール"),TEXT("ms-settings:privacy-email") },
	{ TEXT("メッセージング"),TEXT("ms-settings:privacy-messaging") },
	{ TEXT("無線"),TEXT("ms-settings:privacy-radios") },
	{ TEXT("バックグラウンド アプリ"),TEXT("ms-settings:privacy-backgroundapps") },
	{ TEXT("他のデバイス"),TEXT("ms-settings:privacy-customdevices") },
	{ TEXT("フィードバックと診断"),TEXT("ms-settings:privacy-feedback") },
	{ TEXT("開発者向け"),TEXT("ms-settings:developers") }
};

LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	static HWND hComboBox;
	static HWND hButton;
	switch (msg)
	{
	case WM_CREATE:
		hComboBox = CreateWindow(TEXT("COMBOBOX"), 0, WS_VISIBLE | WS_CHILD | WS_VSCROLL | CBS_DROPDOWNLIST, 0, 0, 0, 0, hWnd, 0, ((LPCREATESTRUCT)lParam)->hInstance, 0);
		{
			for (auto item : data)
			{
				SendMessage(hComboBox, CB_ADDSTRING, 0, (LPARAM)item.lpszDistract);
			}
			SendMessage(hComboBox, CB_SETCURSEL, 0, 0);
		}
		hButton = CreateWindow(TEXT("BUTTON"), TEXT("開く"), WS_VISIBLE | WS_CHILD, 0, 0, 0, 0, hWnd, (HMENU)IDOK, ((LPCREATESTRUCT)lParam)->hInstance, 0);
		break;
	case WM_SIZE:
		MoveWindow(hComboBox, 10, 10, 256, 9999, TRUE);
		MoveWindow(hButton, 10, 50, 256, 32, TRUE);
		break;
	case WM_COMMAND:
		if (LOWORD(wParam) == IDOK)
		{
			const int nIndex = (int)SendMessage(hComboBox, CB_GETCURSEL, 0, 0);
			if (nIndex != CB_ERR && nIndex >= 0 && nIndex < _countof(data))
			{
				ShellExecute(hWnd, 0, data[nIndex].lpszCommand, 0, 0, 0);
			}
		}
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, msg, wParam, lParam);
	}
	return 0;
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPreInst, LPSTR pCmdLine, int nCmdShow)
{
	MSG msg;
	WNDCLASS wndclass = {
		CS_HREDRAW | CS_VREDRAW,
		WndProc,
		0,
		0,
		hInstance,
		0,
		LoadCursor(0,IDC_ARROW),
		(HBRUSH)(COLOR_WINDOW + 1),
		0,
		szClassName
	};
	RegisterClass(&wndclass);
	HWND hWnd = CreateWindow(
		szClassName,
		TEXT("Window 10の設定画面を開く"),
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT,
		0,
		CW_USEDEFAULT,
		0,
		0,
		0,
		hInstance,
		0
	);
	ShowWindow(hWnd, SW_SHOWDEFAULT);
	UpdateWindow(hWnd);
	while (GetMessage(&msg, 0, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return (int)msg.wParam;
}
