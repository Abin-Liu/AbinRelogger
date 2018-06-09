#include "stdafx.h"
#include "..\Languages.h"

void CLanguage::Provider_Chinese_Traditional(CLangMap& aMap)
{
	// Menu
	aMap.SetAt(LANG_MENU_FILE, _T("文件"));
	aMap.SetAt(LANG_MENU_EXIT, _T("退出"));
	aMap.SetAt(LANG_MENU_TASK, _T("任務"));
	aMap.SetAt(LANG_MENU_START, _T("啟動"));
	aMap.SetAt(LANG_MENU_STOP, _T("停止"));
	aMap.SetAt(LANG_MENU_STOP_DETACH, _T("停止（保留進程）"));
	aMap.SetAt(LANG_MENU_PAUSE_RESUME, _T("暫停/恢復"));
	aMap.SetAt(LANG_MENU_HIDE_GAME, _T("隱藏遊戲"));
	aMap.SetAt(LANG_MENU_NEW, _T("新建"));
	aMap.SetAt(LANG_MENU_EDIT, _T("編輯"));
	aMap.SetAt(LANG_MENU_CLONE, _T("複製"));
	aMap.SetAt(LANG_MENU_DELETE, _T("刪除"));
	aMap.SetAt(LANG_MENU_OPTIONS, _T("設置"));
	aMap.SetAt(LANG_MENU_LANGUAGES, _T("語言"));
	aMap.SetAt(LANG_MENU_CHANGE_PASSWORD, _T("更改密碼"));
	aMap.SetAt(LANG_MENU_SETTINGS, _T("選項..."));
	aMap.SetAt(LANG_MENU_HELP, _T("幫助"));
	aMap.SetAt(LANG_MENU_ABOUT, _T("關於"));
	aMap.SetAt(LANG_MENU_TASK_LIST, _T("任務列表"));
	aMap.SetAt(LANG_MENU_HIDE_ALL, _T("全部隱藏"));
	aMap.SetAt(LANG_MENU_SHOW_ALL, _T("全部顯示"));
	aMap.SetAt(LANG_MENU_STOP_ALL, _T("全部停止"));
	aMap.SetAt(LANG_MENU_OK, _T("確定"));
	aMap.SetAt(LANG_MENU_CANCEL, _T("取消"));

	// About window
	aMap.SetAt(LANG_ABOUT_TITLE, _T("關於ARelogger"));
	aMap.SetAt(LANG_ABOUT_COPYRIGHT, _T("版權所有(C) 2016, Abin"));

	// Main window
	aMap.SetAt(LANG_MAIN_LOG, _T("日誌"));
	aMap.SetAt(LANG_MAIN_SUGGEST_CLEAN, _T("（建議清空）"));
	aMap.SetAt(LANG_MAIN_LIST_COLUMN_NAME, _T("名稱"));
	aMap.SetAt(LANG_MAIN_LIST_COLUMN_AGE, _T("運行時間"));
	aMap.SetAt(LANG_MAIN_LIST_COLUMN_PROFILE, _T("腳本名稱"));
	aMap.SetAt(LANG_MAIN_FRAME_BATCH_OPER, _T("批量操作"));
	aMap.SetAt(LANG_MAIN_FRAME_TASK_DATA, _T("任務數據"));
	aMap.SetAt(LANG_MAIN_OPEN_LOG, _T("打開日誌"));
	aMap.SetAt(LANG_MAIN_CLEAN_LOG, _T("清空日誌"));

	// Log
	aMap.SetAt(LANG_LOG_APP_STARTED, _T("ARelogger已啟動"));
	aMap.SetAt(LANG_LOG_APP_EXIT, _T("ARelogger已退出"));
	aMap.SetAt(LANG_LOG_PASSWORD_CREATED, _T("訪問密碼創建成功"));
	aMap.SetAt(LANG_LOG_LOGIN_SUCCESSFUL, _T("登錄成功"));
	aMap.SetAt(LANG_LOG_INVALID_PASSWORD, _T("無效的訪問密碼"));
	aMap.SetAt(LANG_LOG_DATA_DELETED, _T("已刪除用戶數據"));
	aMap.SetAt(LANG_LOG_DATA_NOT_FOUND, _T("未找到完整數據，以新用戶身份運行"));
	aMap.SetAt(LANG_LOG_DATA_LOADED, _T("已載入%d個儲存的任務"));
	aMap.SetAt(LANG_LOG_DATA_SAVED, _T("已保存%d個任務數據"));
	aMap.SetAt(LANG_LOG_KILLED_BLIZZARD_ERROR, _T("已發現并殺死進程[BlizzardError.exe]"));
	aMap.SetAt(LANG_LOG_TASK_CREATED, _T("任務創建成功"));
	aMap.SetAt(LANG_LOG_TASK_MODIFIED, _T("任務數據已更新"));
	aMap.SetAt(LANG_LOG_TASK_DELETED, _T("任務已刪除"));
	aMap.SetAt(LANG_LOG_PASSWORD_CHANGED, _T("訪問密碼修改成功"));
	aMap.SetAt(LANG_LOG_MONITOR_TRIPWIRE, _T("監控異常：TripWire事件觸發"));
	aMap.SetAt(LANG_LOG_MONITOR_DIABLO_CLOSED, _T("監控異常：Diablo III已關閉"));
	aMap.SetAt(LANG_LOG_MONITOR_DEMONBUDDY_CLOSED, _T("監控異常：Demonbuddy已關閉"));
	aMap.SetAt(LANG_LOG_MONITOR_OUT_OF_GAME, _T("監控異常：角色離開遊戲已超過時限"));
	aMap.SetAt(LANG_LOG_MONITOR_DIABLO_DISCONNECTED, _T("監控異常：遊戲斷開連接已超過時限"));
	aMap.SetAt(LANG_LOG_MONITOR_DIABLO_UNRESPONSIVE, _T("監控異常：Diablo III失去響應已超過時限"));
	aMap.SetAt(LANG_LOG_MONITOR_DEMONBUDDY_UNRESPONSIVE, _T("監控異常：Demonbuddy失去響應已超過時限"));
	aMap.SetAt(LANG_LOG_MONITOR_DIABLO_MINIMIZED, _T("監控異常：已阻止Diablo III視窗最小化"));
	aMap.SetAt(LANG_LOG_SET_HIDE_WINDOW_TRUE, _T("設置隱藏遊戲視窗：TRUE"));
	aMap.SetAt(LANG_LOG_SET_HIDE_WINDOW_FALSE, _T("設置隱藏遊戲視窗：FALSE"));
	aMap.SetAt(LANG_LOG_DIABLO_LOGIN_SCREEN, _T("已到達賬號登錄界面"));
	aMap.SetAt(LANG_LOG_DIABLO_LOGIN_SUCCESS, _T("Battle.net登錄成功"));
	aMap.SetAt(LANG_LOG_DIABLO_LOGIN_FAILED, _T("Battle.net登錄失敗！任務終止，請重新設置"));
	aMap.SetAt(LANG_LOG_DIABLO_GAME_JOINED, _T("角色已進入遊戲"));
	aMap.SetAt(LANG_LOG_DIABLO_GAME_LEFT, _T("角色已離開遊戲"));
	aMap.SetAt(LANG_LOG_DIABLO_GAME_DISCONNECTED, _T("遊戲已斷開連接"));
	aMap.SetAt(LANG_LOG_LAUNCH_ERROR_RETRY, _T("5秒後重新啟動任務……"));
	aMap.SetAt(LANG_LOG_LAUNCH_PREPARE, _T("準備啟動任務"));
	aMap.SetAt(LANG_LOG_LAUNCH_CLEANUP, _T("等待殘留進程結束"));
	aMap.SetAt(LANG_LOG_LAUNCH_PREPARE_DIABLO, _T("準備啟動Diablo III"));
	aMap.SetAt(LANG_LOG_LAUNCH_START_DIABLO, _T("正在啟動Diablo III"));
	aMap.SetAt(LANG_LOG_LAUNCH_START_DIABLO_FAILED, _T("Diablo III啟動失敗！"));
	aMap.SetAt(LANG_LOG_LAUNCH_DIABLO_REUSED, _T("Diablo III進程接管成功：PID=%d"));
	aMap.SetAt(LANG_LOG_LAUNCH_DIABLO_SUCCESS, _T("Diablo III啟動成功：PID=%d"));
	aMap.SetAt(LANG_LOG_LAUNCH_WAIT_DIABLO, _T("等待Diablo III進城主視窗"));
	aMap.SetAt(LANG_LOG_LAUNCH_WAIT_BNET_LOGIN, _T("等待Battle.net登錄驗證"));
	aMap.SetAt(LANG_LOG_LAUNCH_BNET_LOGIN_TIMEOUT, _T("Battle.net登錄驗證超時"));
	aMap.SetAt(LANG_LOG_LAUNCH_WAIT_JOIN_GAME, _T("等待角色創建遊戲"));
	aMap.SetAt(LANG_LOG_LAUNCH_JOIN_GAME_FAILED, _T("遊戲創建失敗！"));
	aMap.SetAt(LANG_LOG_LAUNCH_PREPARE_DEMONBUDDY, _T("準備啟動Demonbuddy"));
	aMap.SetAt(LANG_LOG_LAUNCH_START_DEMONBUDDY, _T("正在啟動Demonbuddy"));
	aMap.SetAt(LANG_LOG_LAUNCH_START_DEMONBUDDY_FAILED, _T("Demonbuddy啟動失敗！"));
	aMap.SetAt(LANG_LOG_LAUNCH_DEMONBUDDY_REUSED, _T("Demonbuddy進程接管成功：PID=%d"));
	aMap.SetAt(LANG_LOG_LAUNCH_WAIT_DEMONBUDDY, _T("等待Demonbuddy進程主視窗"));
	aMap.SetAt(LANG_LOG_LAUNCH_DEMONBUDDY_SUCCESS, _T("Demonbuddy啟動成功：PID=%d"));
	aMap.SetAt(LANG_LOG_LAUNCH_CLOSE_DEMONBUDDY_ERROR, _T("關閉Demonbuddy錯誤視窗"));
	aMap.SetAt(LANG_LOG_LAUNCH_CLOSE_DEMONBUDDY, _T("關閉DemonBuddy"));
	aMap.SetAt(LANG_LOG_LAUNCH_CHECK_DEMONBUDDY_CLOSE, _T("等待DemonBuddy進程關閉"));
	aMap.SetAt(LANG_LOG_LAUNCH_DEMONBUDDY_CLOSED, _T("DemonBuddy進程關閉成功"));
	aMap.SetAt(LANG_LOG_LAUNCH_WAIT_GAME_STABLIZE, _T("等待遊戲狀態穩定化并重新啟動DemonBuddy"));
	aMap.SetAt(LANG_LOG_LAUNCH_SUCCESSFUL, _T("任務啟動成功，轉入正常監控階段"));
	aMap.SetAt(LANG_LOG_LAUNCH_HIDE_PROCESSES, _T("已根據設置隱藏被監控的進程窗口"));
	aMap.SetAt(LANG_LOG_STATE_LAUNCH, _T("準備啟動任務"));
	aMap.SetAt(LANG_LOG_STATE_MONITOR, _T("任務監控開始"));
	aMap.SetAt(LANG_LOG_STATE_START, _T("任務線程創建"));
	aMap.SetAt(LANG_LOG_STATE_STOP, _T("任務線程停止"));
	aMap.SetAt(LANG_LOG_STATE_PAUSE, _T("任務暫停"));
	aMap.SetAt(LANG_LOG_STATE_RESUME, _T("任務恢復"));

	// Message box
	aMap.SetAt(LANG_MSG_INVALID_INPUT_TITLE, _T("無效輸入"));
	aMap.SetAt(LANG_MSG_CREATE_PASSWORD_TITLE, _T("創建訪問密碼"));
	aMap.SetAt(LANG_MSG_CREATE_PASSWORD_TEXT, _T("在使用ARelogger之前您需要創建一個訪問密碼，它用來對您將要輸入的戰網登錄信息等敏感數據進行加密保護。訪問密碼不會被保存到磁碟上，因此您需要將其牢記於心，否則將無法解密登錄數據。"));
	aMap.SetAt(LANG_MSG_DELETE_TASK_TITLE, _T("刪除任務"));
	aMap.SetAt(LANG_MSG_DELETE_TASK_TEXT, _T("即將刪除任務[%s]，此操作不可恢復，確定要刪除嗎？"));
	aMap.SetAt(LANG_MSG_CLEAN_LOG_TITLE, _T("清空日誌"));
	aMap.SetAt(LANG_MSG_CLEAN_LOG_TEXT, _T("即將清空已儲存的日誌內容，確定嗎？"));
	aMap.SetAt(LANG_MSG_STOP_ALL_TITLE, _T("全部停止"));
	aMap.SetAt(LANG_MSG_STOP_ALL_TEXT, _T("當前有%d個任務正在運行中，確定要全部停止并關閉由這些任務所管理的Diablo3與Demonbuddy進程嗎？"));
	aMap.SetAt(LANG_MSG_EXIT_APP_TITLE, _T("退出Relogger"));
	aMap.SetAt(LANG_MSG_TASK_RUNNING_TITLE, _T("任務運行中"));
	aMap.SetAt(LANG_MSG_TASK_RUNNING_TEXT, _T("任務[%s]正在運行中，請停止後再操作。"));
	aMap.SetAt(LANG_MSG_TASK_CONFLICT_TITLE, _T("任務屬性衝突"));
	aMap.SetAt(LANG_MSG_TASK_CONFLICT_TEXT, _T("任務[%s]設置的Diablo遊戲目錄[%s]與正在運行中的任務务[%s]相同，Diablo3不允許于同一路徑下雙開，請重新設置任務。"));
	aMap.SetAt(LANG_MSG_INPUT_CANNOT_BE_EMPTY, _T("[%s]不能為空。"));
	aMap.SetAt(LANG_MSG_INPUT_INVALID_PATH, _T("[%s]不是一個正確的%s路徑。"));
	aMap.SetAt(LANG_MSG_DELETE_DATA_TITLE, _T("清空數據"));
	aMap.SetAt(LANG_MSG_DELERE_DATA_TEXT, _T("此操作將刪除已保存的數據，當您再次運行ARelogger時將以新用戶身份登錄，刪除的數據無法恢復。確定要清空嗎？"));
	aMap.SetAt(LANG_MSG_PASSWORD_REPEAT_MISMATCH, _T("新密碼與重複新密碼必須相同。"));
	aMap.SetAt(LANG_MSG_ORIGINAL_PASSWORD_INCORRECT, _T("原訪問密碼不正確。"));

	// Password window
	aMap.SetAt(LANG_PASSWORD_TITLE, _T("請輸入訪問密碼"));
	aMap.SetAt(LANG_PASSWORD_PASSWORD, _T("訪問密碼"));
	aMap.SetAt(LANG_PASSWORD_OLD_PASSWORD, _T("原訪問密碼"));
	aMap.SetAt(LANG_PASSWORD_INVALID_TITLE, _T("訪問密碼錯誤"));
	aMap.SetAt(LANG_PASSWORD_INVALID_TEXT, _T("你可以選擇重試重新輸入密碼，或者清空所有數據以新用戶身份重新運行ARelogger。"));
	aMap.SetAt(LANG_PASSWORD_RETRY, _T("重試"));
	aMap.SetAt(LANG_PASSWORD_CLEAN_EXIT, _T("清空數據并退出"));
	aMap.SetAt(LANG_PASSWORD_CREATE_TITLE, _T("創建密碼"));
	aMap.SetAt(LANG_PASSWORD_CREATE_NEW_PASSWORD, _T("輸入新密碼"));
	aMap.SetAt(LANG_PASSWORD_CREATE_REPEAT_PASSWORD, _T("重複新密碼"));

	// Task window
	aMap.SetAt(LANG_TASK_TITLE, _T("任務設置"));
	aMap.SetAt(LANG_TASK_FRAME_TASK, _T("任務"));
	aMap.SetAt(LANG_TASK_TASK_NAME, _T("任務名稱"));
	aMap.SetAt(LANG_TASK_DIABLO_PATH, _T("遊戲目錄"));
	aMap.SetAt(LANG_TASK_ACCOUNT, _T("戰網賬號"));
	aMap.SetAt(LANG_TASK_PASSWORD, _T("戰網密碼"));
	aMap.SetAt(LANG_TASK_I_USE_BNET_AUTHENTICATOR, _T("我使用戰網安全令"));
	aMap.SetAt(LANG_TASK_SERIAL, _T("序列號"));
	aMap.SetAt(LANG_TASK_RESTORE_CODE, _T("還原密碼"));
	aMap.SetAt(LANG_TASK_DEMONBUDDY_PATH, _T("程序目錄"));
	aMap.SetAt(LANG_TASK_AUTHORIZE_CODE, _T("授權碼"));
	aMap.SetAt(LANG_TASK_PROFILE_PATH, _T("腳本文件"));

	// Config window
	aMap.SetAt(LANG_CONFIG_TITLE, _T("設置選項"));
	aMap.SetAt(LANG_CONFIG_DBLCLK_TASK_LIST, _T("雙擊任務列表"));
	aMap.SetAt(LANG_CONFIG_NO_OPERATION, _T("無操作"));
	aMap.SetAt(LANG_CONFIG_OPEN_TASK_EDITING_WINDOW, _T("打開任務編輯視窗"));
	aMap.SetAt(LANG_CONFIG_CYCLE_START_STOP, _T("循環：啟動 - 停止"));
	aMap.SetAt(LANG_CONFIG_CYCLE_START_STOP_NO_KILL, _T("循環：啟動 - 停止（保留進程）"));
	aMap.SetAt(LANG_CONFIG_CYCLE_START_PAUSE_RESUME, _T("循環：啟動 - 暫停 - 恢復"));
	aMap.SetAt(LANG_CONFIG_TASK_CONTROL, _T("運行控制"));
	aMap.SetAt(LANG_CONFIG_PREVENT_DIABLO_MINIMIZED, _T("阻止Diablo視窗最小化"));
	aMap.SetAt(LANG_CONFIG_MONITOR_TRIPWIRE_EVENT, _T("優先監控TripWire事件"));
	aMap.SetAt(LANG_CONFIG_DOUBLE_LAUNCH_DEMONBUDDY, _T("使用Demonbuddy二次啟動模式以避免插件錯誤"));
	aMap.SetAt(LANG_CONFIG_ATTACH_EXISTING_PROCESSES, _T("接管已存在的Diablo/Demonbuddy進程"));
	aMap.SetAt(LANG_CONFIG_TIMEOUT, _T("等待時限"));
	aMap.SetAt(LANG_CONFIG_TIMEOUT_LAUNCH_DIABLO, _T("啟動Diablo3遊戲"));
	aMap.SetAt(LANG_CONFIG_TIMEOUT_BNET_LOGIN, _T("Battle.net登錄"));
	aMap.SetAt(LANG_CONFIG_TIMEOUT_CREATE_GAME, _T("創建遊戲"));
	aMap.SetAt(LANG_CONFIG_TIMEOUT_OUT_OF_GAME, _T("角色離開遊戲"));
	aMap.SetAt(LANG_CONFIG_TIMEOUT_GAME_DISCONNECTED, _T("遊戲斷開連接"));
	aMap.SetAt(LANG_CONFIG_TIMEOUT_DIABLO_UNRESPONSIVE, _T("Diablo失去響應"));
	aMap.SetAt(LANG_CONFIG_TIMEOUT_DEMONBUDDY_UNRESPONSIVE, _T("Demonbuddy失去響應"));
	aMap.SetAt(LANG_CONFIG_FORCE_RESTART_IF_TIMEOUT, _T("等待時限到達後將強制重啟Diablo與Demonbuddy"));
	aMap.SetAt(LANG_CONFIG_TOOLTIP_PREVENT_MIN, _T("Demonbuddy在Diablo遊戲視窗被最小化後無法正常工作，勾選後ARelogger將自動阻止遊戲視窗最小化。"));
	aMap.SetAt(LANG_CONFIG_TOOLTIP_DB_2X_LOGIN, _T("目前版本的Demonbuddy如果在角色加入遊戲之前啟動，將產生大量插件錯誤并嚴重影響後續運行的穩定性，勾選後ARelogger將在角色加入遊戲后自動重啟Demonbuddy以消除所有插件錯誤。"));
	aMap.SetAt(LANG_CONFIG_TOOLTIP_TAKEOVER_PROCESS, _T("啟動任務時將搜索運行中的Diablo/Demonbuddy進程，如果符合接管條件，任務將優先接管現有進程而不是啟動新進程。"));
	aMap.SetAt(LANG_CONFIG_RESTORE_DEFAULTS, _T("恢復默認值"));
	aMap.SetAt(LANG_CONFIG_SECONDS, _T("秒"));
}

