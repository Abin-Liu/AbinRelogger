#include "stdafx.h"
#include "..\Languages.h"

void CLanguage::Provider_Chinese_Simplified(CLangMap& aMap)
{
	// Menu
	aMap.SetAt(LANG_MENU_FILE, _T("文件"));
	aMap.SetAt(LANG_MENU_EXIT, _T("退出"));
	aMap.SetAt(LANG_MENU_TASK, _T("任务"));
	aMap.SetAt(LANG_MENU_START, _T("启动"));
	aMap.SetAt(LANG_MENU_STOP, _T("停止"));
	aMap.SetAt(LANG_MENU_STOP_DETACH, _T("停止（保留进程）"));
	aMap.SetAt(LANG_MENU_PAUSE_RESUME, _T("暂停/恢复"));
	aMap.SetAt(LANG_MENU_HIDE_GAME, _T("隐藏游戏"));
	aMap.SetAt(LANG_MENU_NEW, _T("新建"));
	aMap.SetAt(LANG_MENU_EDIT, _T("编辑"));
	aMap.SetAt(LANG_MENU_CLONE, _T("复制"));
	aMap.SetAt(LANG_MENU_DELETE, _T("删除"));
	aMap.SetAt(LANG_MENU_OPTIONS, _T("设置"));
	aMap.SetAt(LANG_MENU_LANGUAGES, _T("语言"));
	aMap.SetAt(LANG_MENU_CHANGE_PASSWORD, _T("更改密码"));
	aMap.SetAt(LANG_MENU_SETTINGS, _T("选项..."));
	aMap.SetAt(LANG_MENU_HELP, _T("帮助"));
	aMap.SetAt(LANG_MENU_ABOUT, _T("关于"));
	aMap.SetAt(LANG_MENU_TASK_LIST, _T("任务列表"));
	aMap.SetAt(LANG_MENU_HIDE_ALL, _T("全部隐藏"));
	aMap.SetAt(LANG_MENU_SHOW_ALL, _T("全部显示"));
	aMap.SetAt(LANG_MENU_STOP_ALL, _T("全部停止"));
	aMap.SetAt(LANG_MENU_OK, _T("确定"));
	aMap.SetAt(LANG_MENU_CANCEL, _T("取消"));

	// About window
	aMap.SetAt(LANG_ABOUT_TITLE, _T("关于ARelogger"));
	aMap.SetAt(LANG_ABOUT_COPYRIGHT, _T("版权所有(C) 2016, Abin"));

	// Main window
	aMap.SetAt(LANG_MAIN_LOG, _T("日志"));
	aMap.SetAt(LANG_MAIN_SUGGEST_CLEAN, _T("（建议清空）"));
	aMap.SetAt(LANG_MAIN_LIST_COLUMN_NAME, _T("名称"));
	aMap.SetAt(LANG_MAIN_LIST_COLUMN_AGE, _T("运行时间"));
	aMap.SetAt(LANG_MAIN_LIST_COLUMN_PROFILE, _T("脚本名称"));
	aMap.SetAt(LANG_MAIN_FRAME_BATCH_OPER, _T("批量操作"));
	aMap.SetAt(LANG_MAIN_FRAME_TASK_DATA, _T("任务数据"));
	aMap.SetAt(LANG_MAIN_OPEN_LOG, _T("打开日志"));
	aMap.SetAt(LANG_MAIN_CLEAN_LOG, _T("清空日志"));

	// Log
	aMap.SetAt(LANG_LOG_APP_STARTED, _T("ARelogger已启动"));
	aMap.SetAt(LANG_LOG_APP_EXIT, _T("ARelogger已退出"));
	aMap.SetAt(LANG_LOG_PASSWORD_CREATED, _T("访问密码创建成功"));
	aMap.SetAt(LANG_LOG_LOGIN_SUCCESSFUL, _T("登录成功"));
	aMap.SetAt(LANG_LOG_INVALID_PASSWORD, _T("无效的访问密码"));
	aMap.SetAt(LANG_LOG_DATA_DELETED, _T("已删除用户数据"));
	aMap.SetAt(LANG_LOG_DATA_NOT_FOUND, _T("未找到完整数据，以新用户身份运行"));
	aMap.SetAt(LANG_LOG_DATA_LOADED, _T("已读取%d个存储的任务"));
	aMap.SetAt(LANG_LOG_DATA_SAVED, _T("已保存%d个任务数据"));
	aMap.SetAt(LANG_LOG_KILLED_BLIZZARD_ERROR, _T("已发现并杀死进程[BlizzardError.exe]"));
	aMap.SetAt(LANG_LOG_TASK_CREATED, _T("任务创建成功"));
	aMap.SetAt(LANG_LOG_TASK_MODIFIED, _T("任务数据已更新"));
	aMap.SetAt(LANG_LOG_TASK_DELETED, _T("任务已删除"));
	aMap.SetAt(LANG_LOG_PASSWORD_CHANGED, _T("访问密码修改成功"));
	aMap.SetAt(LANG_LOG_MONITOR_TRIPWIRE, _T("监控异常：TripWire事件触发！"));
	aMap.SetAt(LANG_LOG_MONITOR_DIABLO_CLOSED, _T("监控异常：Diablo III已关闭"));
	aMap.SetAt(LANG_LOG_MONITOR_DEMONBUDDY_CLOSED, _T("监控异常：Demonbuddy已关闭"));
	aMap.SetAt(LANG_LOG_MONITOR_OUT_OF_GAME, _T("监控异常：角色离开游戏已超过时限"));
	aMap.SetAt(LANG_LOG_MONITOR_DIABLO_DISCONNECTED, _T("监控异常：游戏断开连接已超过时限"));
	aMap.SetAt(LANG_LOG_MONITOR_DIABLO_UNRESPONSIVE, _T("监控异常：Diablo III失去响应已超过时限"));
	aMap.SetAt(LANG_LOG_MONITOR_DEMONBUDDY_UNRESPONSIVE, _T("监控异常：Demonbuddy失去响应已超过时限"));
	aMap.SetAt(LANG_LOG_MONITOR_DIABLO_MINIMIZED, _T("监控异常：已阻止Diablo III窗口最小化"));
	aMap.SetAt(LANG_LOG_SET_HIDE_WINDOW_TRUE, _T("设置隐藏游戏窗口：TRUE"));
	aMap.SetAt(LANG_LOG_SET_HIDE_WINDOW_FALSE, _T("设置隐藏游戏窗口：FALSE"));
	aMap.SetAt(LANG_LOG_DIABLO_LOGIN_SCREEN, _T("已到达账号登录界面"));
	aMap.SetAt(LANG_LOG_DIABLO_LOGIN_SUCCESS, _T("Battle.net登录成功"));
	aMap.SetAt(LANG_LOG_DIABLO_LOGIN_FAILED, _T("Battle.net登录失败！任务终止，请重新设置"));
	aMap.SetAt(LANG_LOG_DIABLO_GAME_JOINED, _T("角色已进入游戏"));
	aMap.SetAt(LANG_LOG_DIABLO_GAME_LEFT, _T("角色已离开游戏"));
	aMap.SetAt(LANG_LOG_DIABLO_GAME_DISCONNECTED, _T("游戏已断开连接"));
	aMap.SetAt(LANG_LOG_LAUNCH_ERROR_RETRY, _T("5秒后重新启动任务……"));
	aMap.SetAt(LANG_LOG_LAUNCH_PREPARE, _T("准备启动任务"));
	aMap.SetAt(LANG_LOG_LAUNCH_CLEANUP, _T("等待残留进程结束"));
	aMap.SetAt(LANG_LOG_LAUNCH_PREPARE_DIABLO, _T("准备启动Diablo III"));
	aMap.SetAt(LANG_LOG_LAUNCH_START_DIABLO, _T("正在启动Diablo III"));
	aMap.SetAt(LANG_LOG_LAUNCH_START_DIABLO_FAILED, _T("Diablo III启动失败！"));
	aMap.SetAt(LANG_LOG_LAUNCH_DIABLO_REUSED, _T("Diablo III进程接管成功：PID=%d"));
	aMap.SetAt(LANG_LOG_LAUNCH_DIABLO_SUCCESS, _T("Diablo III启动成功：PID=%d"));
	aMap.SetAt(LANG_LOG_LAUNCH_WAIT_DIABLO, _T("等待Diablo III进程主窗口"));
	aMap.SetAt(LANG_LOG_LAUNCH_WAIT_BNET_LOGIN, _T("等待Battle.net登录验证"));
	aMap.SetAt(LANG_LOG_LAUNCH_BNET_LOGIN_TIMEOUT, _T("Battle.net登录验证超时"));
	aMap.SetAt(LANG_LOG_LAUNCH_WAIT_JOIN_GAME, _T("等待角色创建游戏"));
	aMap.SetAt(LANG_LOG_LAUNCH_JOIN_GAME_FAILED, _T("游戏创建失败！"));
	aMap.SetAt(LANG_LOG_LAUNCH_PREPARE_DEMONBUDDY, _T("准备启动Demonbuddy"));
	aMap.SetAt(LANG_LOG_LAUNCH_START_DEMONBUDDY, _T("正在启动Demonbuddy"));
	aMap.SetAt(LANG_LOG_LAUNCH_START_DEMONBUDDY_FAILED, _T("Demonbuddy启动失败！"));
	aMap.SetAt(LANG_LOG_LAUNCH_DEMONBUDDY_REUSED, _T("Demonbuddy进程接管成功：PID=%d"));
	aMap.SetAt(LANG_LOG_LAUNCH_WAIT_DEMONBUDDY, _T("等待Demonbuddy进程主窗口"));
	aMap.SetAt(LANG_LOG_LAUNCH_DEMONBUDDY_SUCCESS, _T("Demonbuddy启动成功：PID=%d"));
	aMap.SetAt(LANG_LOG_LAUNCH_CLOSE_DEMONBUDDY_ERROR, _T("关闭Demonbuddy错误窗口"));
	aMap.SetAt(LANG_LOG_LAUNCH_CLOSE_DEMONBUDDY, _T("关闭DemonBuddy"));
	aMap.SetAt(LANG_LOG_LAUNCH_CHECK_DEMONBUDDY_CLOSE, _T("等待DemonBuddy进程关闭"));
	aMap.SetAt(LANG_LOG_LAUNCH_DEMONBUDDY_CLOSED, _T("DemonBuddy进程关闭成功"));
	aMap.SetAt(LANG_LOG_LAUNCH_WAIT_GAME_STABLIZE, _T("等待游戏状态稳定化并重新启动DemonBuddy"));
	aMap.SetAt(LANG_LOG_LAUNCH_SUCCESSFUL, _T("任务启动成功，转入正常监控阶段"));
	aMap.SetAt(LANG_LOG_LAUNCH_HIDE_PROCESSES, _T("已根据设置隐藏被监控的进程窗口"));
	aMap.SetAt(LANG_LOG_STATE_LAUNCH, _T("准备启动任务"));
	aMap.SetAt(LANG_LOG_STATE_MONITOR, _T("任务监控开始"));
	aMap.SetAt(LANG_LOG_STATE_START, _T("任务线程创建"));
	aMap.SetAt(LANG_LOG_STATE_STOP, _T("任务线程停止"));
	aMap.SetAt(LANG_LOG_STATE_PAUSE, _T("任务暂停"));
	aMap.SetAt(LANG_LOG_STATE_RESUME, _T("任务恢复"));

	// Message box
	aMap.SetAt(LANG_MSG_INVALID_INPUT_TITLE, _T("无效输入"));
	aMap.SetAt(LANG_MSG_CREATE_PASSWORD_TITLE, _T("创建访问密码"));
	aMap.SetAt(LANG_MSG_CREATE_PASSWORD_TEXT, _T("在使用ARelogger之前您需要创建一个访问密码，它用来对您将要输入的战网登录信息等个人数据进行加密保护。访问密码不会被保存到磁盘上，因此您需要将其牢记于心，否则将无法解密登录数据。"));
	aMap.SetAt(LANG_MSG_DELETE_TASK_TITLE, _T("删除任务"));
	aMap.SetAt(LANG_MSG_DELETE_TASK_TEXT, _T("即将删除任务[%s]，此操作不可恢复，确定要删除吗？"));
	aMap.SetAt(LANG_MSG_CLEAN_LOG_TITLE, _T("清空日志"));
	aMap.SetAt(LANG_MSG_CLEAN_LOG_TEXT, _T("即将清空已储存的日志内容，确定吗？"));
	aMap.SetAt(LANG_MSG_STOP_ALL_TITLE, _T("全部停止"));
	aMap.SetAt(LANG_MSG_STOP_ALL_TEXT, _T("当前有%d个任务正在运行中，确定要全部停止并关闭由这些任务所管理的Diablo3与Demonbuddy进程吗？"));
	aMap.SetAt(LANG_MSG_EXIT_APP_TITLE, _T("退出ARelogger"));
	aMap.SetAt(LANG_MSG_TASK_RUNNING_TITLE, _T("任务运行中"));
	aMap.SetAt(LANG_MSG_TASK_RUNNING_TEXT, _T("任务[%s]正在运行中，请停止后再进行操作。"));
	aMap.SetAt(LANG_MSG_TASK_CONFLICT_TITLE, _T("任务属性冲突"));
	aMap.SetAt(LANG_MSG_TASK_CONFLICT_TEXT, _T("任务[%s]设置的Diablo游戏目录[%s]与正在运行中的任务[%s]相同，Diablo3不允许于同一路径下双开，请重新设置任务。"));
	aMap.SetAt(LANG_MSG_INPUT_CANNOT_BE_EMPTY, _T("[%s]不能为空。"));
	aMap.SetAt(LANG_MSG_INPUT_INVALID_PATH, _T("[%s]不是一个正确的%s路径。"));
	aMap.SetAt(LANG_MSG_DELETE_DATA_TITLE, _T("清空数据"));
	aMap.SetAt(LANG_MSG_DELERE_DATA_TEXT, _T("此操作将删除已保存的数据，当您再次运行ARelogger时将以新用户身份登录，删除的数据无法恢复。确定要清空吗？"));
	aMap.SetAt(LANG_MSG_PASSWORD_REPEAT_MISMATCH, _T("新密码与重复新密码必须相同。"));
	aMap.SetAt(LANG_MSG_ORIGINAL_PASSWORD_INCORRECT, _T("原访问密码不正确。"));

	// Password window
	aMap.SetAt(LANG_PASSWORD_TITLE, _T("请输入访问密码"));
	aMap.SetAt(LANG_PASSWORD_PASSWORD, _T("访问密码"));
	aMap.SetAt(LANG_PASSWORD_OLD_PASSWORD, _T("原访问密码"));
	aMap.SetAt(LANG_PASSWORD_INVALID_TITLE, _T("访问密码错误"));
	aMap.SetAt(LANG_PASSWORD_INVALID_TEXT, _T("你可以选择重试重新输入密码，或者清空所有数据并以新用户身份重新运行ARelogger。"));
	aMap.SetAt(LANG_PASSWORD_RETRY, _T("重试"));
	aMap.SetAt(LANG_PASSWORD_CLEAN_EXIT, _T("清空数据并退出"));
	aMap.SetAt(LANG_PASSWORD_CREATE_TITLE, _T("创建密码"));
	aMap.SetAt(LANG_PASSWORD_CREATE_NEW_PASSWORD, _T("输入新密码"));
	aMap.SetAt(LANG_PASSWORD_CREATE_REPEAT_PASSWORD, _T("重复新密码"));

	// Task window
	aMap.SetAt(LANG_TASK_TITLE, _T("任务设置"));
	aMap.SetAt(LANG_TASK_FRAME_TASK, _T("任务"));
	aMap.SetAt(LANG_TASK_TASK_NAME, _T("任务名称"));
	aMap.SetAt(LANG_TASK_DIABLO_PATH, _T("游戏目录"));
	aMap.SetAt(LANG_TASK_ACCOUNT, _T("战网账号"));
	aMap.SetAt(LANG_TASK_PASSWORD, _T("战网密码"));
	aMap.SetAt(LANG_TASK_I_USE_BNET_AUTHENTICATOR, _T("我使用战网安全令"));
	aMap.SetAt(LANG_TASK_SERIAL, _T("序列号"));
	aMap.SetAt(LANG_TASK_RESTORE_CODE, _T("还原密码"));
	aMap.SetAt(LANG_TASK_DEMONBUDDY_PATH, _T("程序目录"));
	aMap.SetAt(LANG_TASK_AUTHORIZE_CODE, _T("授权码"));
	aMap.SetAt(LANG_TASK_PROFILE_PATH, _T("脚本文件"));

	// Config window
	aMap.SetAt(LANG_CONFIG_TITLE, _T("设置选项"));
	aMap.SetAt(LANG_CONFIG_DBLCLK_TASK_LIST, _T("双击任务列表"));
	aMap.SetAt(LANG_CONFIG_NO_OPERATION, _T("无操作"));
	aMap.SetAt(LANG_CONFIG_OPEN_TASK_EDITING_WINDOW, _T("打开任务编辑窗口"));
	aMap.SetAt(LANG_CONFIG_CYCLE_START_STOP, _T("循环：启动 - 停止"));
	aMap.SetAt(LANG_CONFIG_CYCLE_START_STOP_NO_KILL, _T("循环：启动 - 停止（保留进程）"));
	aMap.SetAt(LANG_CONFIG_CYCLE_START_PAUSE_RESUME, _T("循环：启动 - 暂停 - 恢复"));
	aMap.SetAt(LANG_CONFIG_TASK_CONTROL, _T("运行控制"));
	aMap.SetAt(LANG_CONFIG_PREVENT_DIABLO_MINIMIZED, _T("阻止Diablo窗口最小化"));
	aMap.SetAt(LANG_CONFIG_MONITOR_TRIPWIRE_EVENT, _T("优先监控TripWire事件"));
	aMap.SetAt(LANG_CONFIG_DOUBLE_LAUNCH_DEMONBUDDY, _T("使用Demonbuddy二次启动模式以避免插件错误"));
	aMap.SetAt(LANG_CONFIG_ATTACH_EXISTING_PROCESSES, _T("接管已存在的Diablo/Demonbuddy进程"));
	aMap.SetAt(LANG_CONFIG_TIMEOUT, _T("等待时限"));
	aMap.SetAt(LANG_CONFIG_TIMEOUT_LAUNCH_DIABLO, _T("启动Diablo3游戏"));
	aMap.SetAt(LANG_CONFIG_TIMEOUT_BNET_LOGIN, _T("Battle.net登录"));
	aMap.SetAt(LANG_CONFIG_TIMEOUT_CREATE_GAME, _T("创建游戏"));
	aMap.SetAt(LANG_CONFIG_TIMEOUT_OUT_OF_GAME, _T("角色离开游戏"));
	aMap.SetAt(LANG_CONFIG_TIMEOUT_GAME_DISCONNECTED, _T("游戏断开连接"));
	aMap.SetAt(LANG_CONFIG_TIMEOUT_DIABLO_UNRESPONSIVE, _T("Diablo失去响应"));
	aMap.SetAt(LANG_CONFIG_TIMEOUT_DEMONBUDDY_UNRESPONSIVE, _T("Demonbuddy失去响应"));
	aMap.SetAt(LANG_CONFIG_FORCE_RESTART_IF_TIMEOUT, _T("等待时限到达后将强制重启Diablo与Demonbuddy"));
	aMap.SetAt(LANG_CONFIG_TOOLTIP_PREVENT_MIN, _T("Demonbuddy在Diablo游戏窗口被最小化后无法正常工作，勾选后ARelogger将自动阻止游戏窗口最小化。"));
	aMap.SetAt(LANG_CONFIG_TOOLTIP_DB_2X_LOGIN, _T("目前版本的Demonbuddy如果在角色进入游戏之前启动，将产生大量插件错误并严重影响后续运行的稳定性，勾选后ARelogger将在角色进入游戏后自动重启Demonbuddy以消除所有插件错误。"));
	aMap.SetAt(LANG_CONFIG_TOOLTIP_TAKEOVER_PROCESS, _T("启动任务时将搜索运行中的Diablo/Demonbuddy进程，如果符合接管条件，任务将优先接管现有进程而不是启动新进程。"));
	aMap.SetAt(LANG_CONFIG_RESTORE_DEFAULTS, _T("恢复默认值"));
	aMap.SetAt(LANG_CONFIG_SECONDS, _T("秒"));
}

