#include "stdafx.h"
#include "..\Languages.h"

void CLanguage::Provider_English(CLangMap& aMap)
{
	// Menu
	aMap.SetAt(LANG_MENU_FILE, _T("File"));
	aMap.SetAt(LANG_MENU_EXIT, _T("Exit"));
	aMap.SetAt(LANG_MENU_TASK, _T("Task"));
	aMap.SetAt(LANG_MENU_START, _T("Start"));
	aMap.SetAt(LANG_MENU_STOP, _T("Stop"));
	aMap.SetAt(LANG_MENU_STOP_DETACH, _T("Stop (Detach)"));
	aMap.SetAt(LANG_MENU_PAUSE_RESUME, _T("Pause / Resume"));
	aMap.SetAt(LANG_MENU_HIDE_GAME, _T("Hide game"));
	aMap.SetAt(LANG_MENU_NEW, _T("New"));
	aMap.SetAt(LANG_MENU_EDIT, _T("Edit"));
	aMap.SetAt(LANG_MENU_CLONE, _T("Clone"));
	aMap.SetAt(LANG_MENU_DELETE, _T("Delete"));
	aMap.SetAt(LANG_MENU_OPTIONS, _T("Options"));
	aMap.SetAt(LANG_MENU_LANGUAGES, _T("Language"));
	aMap.SetAt(LANG_MENU_CHANGE_PASSWORD, _T("Password"));
	aMap.SetAt(LANG_MENU_SETTINGS, _T("Settings..."));
	aMap.SetAt(LANG_MENU_HELP, _T("Help"));
	aMap.SetAt(LANG_MENU_ABOUT, _T("About"));
	aMap.SetAt(LANG_MENU_TASK_LIST, _T("Task list"));
	aMap.SetAt(LANG_MENU_HIDE_ALL, _T("Hide all"));
	aMap.SetAt(LANG_MENU_SHOW_ALL, _T("Show all"));
	aMap.SetAt(LANG_MENU_STOP_ALL, _T("Stop all"));
	aMap.SetAt(LANG_MENU_OK, _T("OK"));
	aMap.SetAt(LANG_MENU_CANCEL, _T("Cancel"));

	// About window
	aMap.SetAt(LANG_ABOUT_TITLE, _T("About ARelogger"));
	aMap.SetAt(LANG_ABOUT_COPYRIGHT, _T("Copyright (C) 2016, Abin"));

	// Main window
	aMap.SetAt(LANG_MAIN_LOG, _T("Log"));
	aMap.SetAt(LANG_MAIN_SUGGEST_CLEAN, _T("(Clean suggested)"));
	aMap.SetAt(LANG_MAIN_LIST_COLUMN_NAME, _T("Name"));
	aMap.SetAt(LANG_MAIN_LIST_COLUMN_AGE, _T("Uptime"));
	aMap.SetAt(LANG_MAIN_LIST_COLUMN_PROFILE, _T("Profile Name"));
	aMap.SetAt(LANG_MAIN_FRAME_BATCH_OPER, _T("Batch operations"));
	aMap.SetAt(LANG_MAIN_FRAME_TASK_DATA, _T("Tasks"));
	aMap.SetAt(LANG_MAIN_OPEN_LOG, _T("Open Log"));
	aMap.SetAt(LANG_MAIN_CLEAN_LOG, _T("Clean Log"));

	// Log
	aMap.SetAt(LANG_LOG_APP_STARTED, _T("ARelogger launched"));
	aMap.SetAt(LANG_LOG_APP_EXIT, _T("ARelogger exit"));
	aMap.SetAt(LANG_LOG_PASSWORD_CREATED, _T("Password created"));
	aMap.SetAt(LANG_LOG_LOGIN_SUCCESSFUL, _T("Login successful"));
	aMap.SetAt(LANG_LOG_INVALID_PASSWORD, _T("Invalid password"));
	aMap.SetAt(LANG_LOG_DATA_DELETED, _T("Data deleted"));
	aMap.SetAt(LANG_LOG_DATA_NOT_FOUND, _T("No data found, run as new user"));
	aMap.SetAt(LANG_LOG_DATA_LOADED, _T("%d tasks loaded"));
	aMap.SetAt(LANG_LOG_DATA_SAVED, _T("%d tasks saved"));
	aMap.SetAt(LANG_LOG_KILLED_BLIZZARD_ERROR, _T("Found and killed process [BlizzardError.exe]"));
	aMap.SetAt(LANG_LOG_TASK_CREATED, _T("Task created"));
	aMap.SetAt(LANG_LOG_TASK_MODIFIED, _T("Task updated"));
	aMap.SetAt(LANG_LOG_TASK_DELETED, _T("Task deleted"));
	aMap.SetAt(LANG_LOG_PASSWORD_CHANGED, _T("Password changed"));
	aMap.SetAt(LANG_LOG_MONITOR_TRIPWIRE, _T("Monitor abnormal: TripWire event fired"));
	aMap.SetAt(LANG_LOG_MONITOR_DIABLO_CLOSED, _T("Monitor abnormal: Diablo III closed"));
	aMap.SetAt(LANG_LOG_MONITOR_DEMONBUDDY_CLOSED, _T("Monitor abnormal: Demonbuddy closed"));
	aMap.SetAt(LANG_LOG_MONITOR_OUT_OF_GAME, _T("Monitor abnormal: Player out of game timed out"));
	aMap.SetAt(LANG_LOG_MONITOR_DIABLO_DISCONNECTED, _T("Monitor abnormal: Game disconnected timed out"));
	aMap.SetAt(LANG_LOG_MONITOR_DIABLO_UNRESPONSIVE, _T("Monitor abnormal: Diablo III unresponsive timed out"));
	aMap.SetAt(LANG_LOG_MONITOR_DEMONBUDDY_UNRESPONSIVE, _T("Monitor abnormal: Demonbuddy unresponsive timed out"));
	aMap.SetAt(LANG_LOG_MONITOR_DIABLO_MINIMIZED, _T("Monitor abnormal: Stopped Diablo III window minimize"));
	aMap.SetAt(LANG_LOG_SET_HIDE_WINDOW_TRUE, _T("Hide game set to: TRUE"));
	aMap.SetAt(LANG_LOG_SET_HIDE_WINDOW_FALSE, _T("Hide game set to: FALSE"));
	aMap.SetAt(LANG_LOG_DIABLO_LOGIN_SCREEN, _T("Reached login screen"));
	aMap.SetAt(LANG_LOG_DIABLO_LOGIN_SUCCESS, _T("Battle.net login successful"));
	aMap.SetAt(LANG_LOG_DIABLO_LOGIN_FAILED, _T("Battle.net login failed! Task aborted, please re-config"));
	aMap.SetAt(LANG_LOG_DIABLO_GAME_JOINED, _T("Player joined game"));
	aMap.SetAt(LANG_LOG_DIABLO_GAME_LEFT, _T("Player left game"));
	aMap.SetAt(LANG_LOG_DIABLO_GAME_DISCONNECTED, _T("Game disconnected from server"));
	aMap.SetAt(LANG_LOG_LAUNCH_ERROR_RETRY, _T("Relaunch task in 5 seconds..."));
	aMap.SetAt(LANG_LOG_LAUNCH_PREPARE, _T("Prepare to launch task"));
	aMap.SetAt(LANG_LOG_LAUNCH_CLEANUP, _T("Wait for processes to cleanup"));
	aMap.SetAt(LANG_LOG_LAUNCH_PREPARE_DIABLO, _T("Prepare to launch Diablo III"));
	aMap.SetAt(LANG_LOG_LAUNCH_START_DIABLO, _T("Launching Diablo III"));
	aMap.SetAt(LANG_LOG_LAUNCH_START_DIABLO_FAILED, _T("Diablo III launch failed!"));
	aMap.SetAt(LANG_LOG_LAUNCH_DIABLO_REUSED, _T("Diablo III process taken over: PID=%d"));
	aMap.SetAt(LANG_LOG_LAUNCH_DIABLO_SUCCESS, _T("Diablo III process launched: PID=%d"));
	aMap.SetAt(LANG_LOG_LAUNCH_WAIT_DIABLO, _T("Waiting for Diablo III main window"));
	aMap.SetAt(LANG_LOG_LAUNCH_WAIT_BNET_LOGIN, _T("Waiting for Battle.net authentication"));
	aMap.SetAt(LANG_LOG_LAUNCH_BNET_LOGIN_TIMEOUT, _T("Battle.net authentication timed out"));
	aMap.SetAt(LANG_LOG_LAUNCH_WAIT_JOIN_GAME, _T("Waiting for player to create game"));
	aMap.SetAt(LANG_LOG_LAUNCH_JOIN_GAME_FAILED, _T("Game create failed!"));
	aMap.SetAt(LANG_LOG_LAUNCH_PREPARE_DEMONBUDDY, _T("Prepare to launch Demonbuddy"));
	aMap.SetAt(LANG_LOG_LAUNCH_START_DEMONBUDDY, _T("Launching Demonbuddy"));
	aMap.SetAt(LANG_LOG_LAUNCH_START_DEMONBUDDY_FAILED, _T("Demonbuddy launch failed!"));
	aMap.SetAt(LANG_LOG_LAUNCH_DEMONBUDDY_REUSED, _T("Demonbuddy process taken over: PID=%d"));
	aMap.SetAt(LANG_LOG_LAUNCH_WAIT_DEMONBUDDY, _T("Waiting for Demonbuddy main window"));
	aMap.SetAt(LANG_LOG_LAUNCH_DEMONBUDDY_SUCCESS, _T("Demonbuddy launched: PID=%d"));
	aMap.SetAt(LANG_LOG_LAUNCH_CLOSE_DEMONBUDDY_ERROR, _T("Close Demonbuddy error window"));
	aMap.SetAt(LANG_LOG_LAUNCH_CLOSE_DEMONBUDDY, _T("Close DemonBuddy"));
	aMap.SetAt(LANG_LOG_LAUNCH_CHECK_DEMONBUDDY_CLOSE, _T("Waiting for DemonBuddy process to exit"));
	aMap.SetAt(LANG_LOG_LAUNCH_DEMONBUDDY_CLOSED, _T("DemonBuddy process closed"));
	aMap.SetAt(LANG_LOG_LAUNCH_WAIT_GAME_STABLIZE, _T("Waiting for the game stablizing before restarting DemonBuddy"));
	aMap.SetAt(LANG_LOG_LAUNCH_SUCCESSFUL, _T("Task launched successfully, entering monitor stage"));
	aMap.SetAt(LANG_LOG_LAUNCH_HIDE_PROCESSES, _T("Hiding monitored windows according to your settings"));
	aMap.SetAt(LANG_LOG_STATE_LAUNCH, _T("Prepare to launch task"));
	aMap.SetAt(LANG_LOG_STATE_MONITOR, _T("Start to monitor task"));
	aMap.SetAt(LANG_LOG_STATE_START, _T("Task thread started"));
	aMap.SetAt(LANG_LOG_STATE_STOP, _T("Task thread ended"));
	aMap.SetAt(LANG_LOG_STATE_PAUSE, _T("Task paused"));
	aMap.SetAt(LANG_LOG_STATE_RESUME, _T("Task resumed"));

	// Message box
	aMap.SetAt(LANG_MSG_INVALID_INPUT_TITLE, _T("Invalid Input"));
	aMap.SetAt(LANG_MSG_CREATE_PASSWORD_TITLE, _T("Create Password"));
	aMap.SetAt(LANG_MSG_CREATE_PASSWORD_TEXT, _T("You need to create a password before using ARelogger, it encrypts and protects your personal data such as Battle.net login info. You need to remember your password."));
	aMap.SetAt(LANG_MSG_DELETE_TASK_TITLE, _T("Delete Task"));
	aMap.SetAt(LANG_MSG_DELETE_TASK_TEXT, _T("About to delete task [%s] permanently, are you sure?"));
	aMap.SetAt(LANG_MSG_CLEAN_LOG_TITLE, _T("Clean Log"));
	aMap.SetAt(LANG_MSG_CLEAN_LOG_TEXT, _T("About to clean existing log contents, are you sure?"));
	aMap.SetAt(LANG_MSG_STOP_ALL_TITLE, _T("Stop All"));
	aMap.SetAt(LANG_MSG_STOP_ALL_TEXT, _T("%d tasks are running, do you want to stop them and kill all Diablo & Demonbuddy processes controlled by these tasks?"));
	aMap.SetAt(LANG_MSG_EXIT_APP_TITLE, _T("Exit ARelogger"));
	aMap.SetAt(LANG_MSG_TASK_RUNNING_TITLE, _T("Task Running"));
	aMap.SetAt(LANG_MSG_TASK_RUNNING_TEXT, _T("Task [%s] is running, you need to stop it before operating."));
	aMap.SetAt(LANG_MSG_TASK_CONFLICT_TITLE, _T("Task Conflicts"));
	aMap.SetAt(LANG_MSG_TASK_CONFLICT_TEXT, _T("Task [%s] has the same Diablo game path [%s] with another running task [%s], Diablo3 does not allow multi-instances from same path."));
	aMap.SetAt(LANG_MSG_INPUT_CANNOT_BE_EMPTY, _T("[%s] cannot be empty."));
	aMap.SetAt(LANG_MSG_INPUT_INVALID_PATH, _T("[%s] is not a correct %s path."));
	aMap.SetAt(LANG_MSG_DELETE_DATA_TITLE, _T("Clean Data"));
	aMap.SetAt(LANG_MSG_DELERE_DATA_TEXT, _T("This will delete all existing data permanently, and you will be loging back as new user. Do you want to continue?"));
	aMap.SetAt(LANG_MSG_PASSWORD_REPEAT_MISMATCH, _T("New password must be same as repeating password."));
	aMap.SetAt(LANG_MSG_ORIGINAL_PASSWORD_INCORRECT, _T("Incorrect password."));

	// Password window
	aMap.SetAt(LANG_PASSWORD_TITLE, _T("Type Password"));
	aMap.SetAt(LANG_PASSWORD_PASSWORD, _T("Password"));
	aMap.SetAt(LANG_PASSWORD_OLD_PASSWORD, _T("Old password"));
	aMap.SetAt(LANG_PASSWORD_INVALID_TITLE, _T("Invalid Password"));
	aMap.SetAt(LANG_PASSWORD_INVALID_TEXT, _T("You may chose Retry to enter password again, or clean all data and relogin as new user."));
	aMap.SetAt(LANG_PASSWORD_RETRY, _T("Retry"));
	aMap.SetAt(LANG_PASSWORD_CLEAN_EXIT, _T("Clean && Exit"));
	aMap.SetAt(LANG_PASSWORD_CREATE_TITLE, _T("Create Password"));
	aMap.SetAt(LANG_PASSWORD_CREATE_NEW_PASSWORD, _T("New password"));
	aMap.SetAt(LANG_PASSWORD_CREATE_REPEAT_PASSWORD, _T("Repeat password"));

	// Task window
	aMap.SetAt(LANG_TASK_TITLE, _T("Task Settings"));
	aMap.SetAt(LANG_TASK_FRAME_TASK, _T("Task"));
	aMap.SetAt(LANG_TASK_TASK_NAME, _T("Task name"));
	aMap.SetAt(LANG_TASK_DIABLO_PATH, _T("Game folder"));
	aMap.SetAt(LANG_TASK_ACCOUNT, _T("BNet account"));
	aMap.SetAt(LANG_TASK_PASSWORD, _T("BNet password"));
	aMap.SetAt(LANG_TASK_I_USE_BNET_AUTHENTICATOR, _T("I use Battle.net authenticator"));
	aMap.SetAt(LANG_TASK_SERIAL, _T("Seraial code"));
	aMap.SetAt(LANG_TASK_RESTORE_CODE, _T("Restore code"));
	aMap.SetAt(LANG_TASK_DEMONBUDDY_PATH, _T("App folder"));
	aMap.SetAt(LANG_TASK_AUTHORIZE_CODE, _T("Authorize code"));
	aMap.SetAt(LANG_TASK_PROFILE_PATH, _T("Profile path"));

	// Config window
	aMap.SetAt(LANG_CONFIG_TITLE, _T("Options"));
	aMap.SetAt(LANG_CONFIG_DBLCLK_TASK_LIST, _T("Dbl-click task list"));
	aMap.SetAt(LANG_CONFIG_NO_OPERATION, _T("No operation"));
	aMap.SetAt(LANG_CONFIG_OPEN_TASK_EDITING_WINDOW, _T("Open task editing window"));
	aMap.SetAt(LANG_CONFIG_CYCLE_START_STOP, _T("Cycles: Start - Stop"));
	aMap.SetAt(LANG_CONFIG_CYCLE_START_STOP_NO_KILL, _T("Cycles: Start - Stop (detach)"));
	aMap.SetAt(LANG_CONFIG_CYCLE_START_PAUSE_RESUME, _T("Cycles: Start - Pause - Resume"));
	aMap.SetAt(LANG_CONFIG_TASK_CONTROL, _T("Task control"));
	aMap.SetAt(LANG_CONFIG_PREVENT_DIABLO_MINIMIZED, _T("Stop Diablo window minimize"));
	aMap.SetAt(LANG_CONFIG_MONITOR_TRIPWIRE_EVENT, _T("Monitor TripWire event"));
	aMap.SetAt(LANG_CONFIG_DOUBLE_LAUNCH_DEMONBUDDY, _T("Double launch Demonbuddy to avoid errors"));
	aMap.SetAt(LANG_CONFIG_ATTACH_EXISTING_PROCESSES, _T("Takeover existing Diablo/Demonbuddy processes"));
	aMap.SetAt(LANG_CONFIG_TIMEOUT, _T("Timeout"));
	aMap.SetAt(LANG_CONFIG_TIMEOUT_LAUNCH_DIABLO, _T("Launch Diablo3 game"));
	aMap.SetAt(LANG_CONFIG_TIMEOUT_BNET_LOGIN, _T("Battle.net login"));
	aMap.SetAt(LANG_CONFIG_TIMEOUT_CREATE_GAME, _T("Create game"));
	aMap.SetAt(LANG_CONFIG_TIMEOUT_OUT_OF_GAME, _T("Player left game"));
	aMap.SetAt(LANG_CONFIG_TIMEOUT_GAME_DISCONNECTED, _T("Game disconnects from server"));
	aMap.SetAt(LANG_CONFIG_TIMEOUT_DIABLO_UNRESPONSIVE, _T("Diablo unresponsive"));
	aMap.SetAt(LANG_CONFIG_TIMEOUT_DEMONBUDDY_UNRESPONSIVE, _T("Demonbuddy unresponsive"));
	aMap.SetAt(LANG_CONFIG_FORCE_RESTART_IF_TIMEOUT, _T("Force restart Diablo/Demonbuddy when timeout"));
	aMap.SetAt(LANG_CONFIG_TOOLTIP_PREVENT_MIN, _T("Demonbuddy cannot work after Diablo window minimizes, check to prevent Diablo window from minimizing."));
	aMap.SetAt(LANG_CONFIG_TOOLTIP_DB_2X_LOGIN, _T("Demonbuddy generates bulk load of errors if it gets started before the player joins a game, check to restart Demonbuddy again after game joined."));
	aMap.SetAt(LANG_CONFIG_TOOLTIP_TAKEOVER_PROCESS, _T("Let the tasks take over existing Diablo/Demonbuddy processes instead of launching new ones, if available."));
	aMap.SetAt(LANG_CONFIG_RESTORE_DEFAULTS, _T("Restore Defaults"));
	aMap.SetAt(LANG_CONFIG_SECONDS, _T("sec"));
}

