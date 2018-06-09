#include "stdafx.h"
#include "..\Languages.h"

void CLanguage::Provider_Chinese_Simplified(CLangMap& aMap)
{
	// Menu
	aMap.SetAt(LANG_MENU_FILE, _T("�ļ�"));
	aMap.SetAt(LANG_MENU_EXIT, _T("�˳�"));
	aMap.SetAt(LANG_MENU_TASK, _T("����"));
	aMap.SetAt(LANG_MENU_START, _T("����"));
	aMap.SetAt(LANG_MENU_STOP, _T("ֹͣ"));
	aMap.SetAt(LANG_MENU_STOP_DETACH, _T("ֹͣ���������̣�"));
	aMap.SetAt(LANG_MENU_PAUSE_RESUME, _T("��ͣ/�ָ�"));
	aMap.SetAt(LANG_MENU_HIDE_GAME, _T("������Ϸ"));
	aMap.SetAt(LANG_MENU_NEW, _T("�½�"));
	aMap.SetAt(LANG_MENU_EDIT, _T("�༭"));
	aMap.SetAt(LANG_MENU_CLONE, _T("����"));
	aMap.SetAt(LANG_MENU_DELETE, _T("ɾ��"));
	aMap.SetAt(LANG_MENU_OPTIONS, _T("����"));
	aMap.SetAt(LANG_MENU_LANGUAGES, _T("����"));
	aMap.SetAt(LANG_MENU_CHANGE_PASSWORD, _T("��������"));
	aMap.SetAt(LANG_MENU_SETTINGS, _T("ѡ��..."));
	aMap.SetAt(LANG_MENU_HELP, _T("����"));
	aMap.SetAt(LANG_MENU_ABOUT, _T("����"));
	aMap.SetAt(LANG_MENU_TASK_LIST, _T("�����б�"));
	aMap.SetAt(LANG_MENU_HIDE_ALL, _T("ȫ������"));
	aMap.SetAt(LANG_MENU_SHOW_ALL, _T("ȫ����ʾ"));
	aMap.SetAt(LANG_MENU_STOP_ALL, _T("ȫ��ֹͣ"));
	aMap.SetAt(LANG_MENU_OK, _T("ȷ��"));
	aMap.SetAt(LANG_MENU_CANCEL, _T("ȡ��"));

	// About window
	aMap.SetAt(LANG_ABOUT_TITLE, _T("����ARelogger"));
	aMap.SetAt(LANG_ABOUT_COPYRIGHT, _T("��Ȩ����(C) 2016, Abin"));

	// Main window
	aMap.SetAt(LANG_MAIN_LOG, _T("��־"));
	aMap.SetAt(LANG_MAIN_SUGGEST_CLEAN, _T("��������գ�"));
	aMap.SetAt(LANG_MAIN_LIST_COLUMN_NAME, _T("����"));
	aMap.SetAt(LANG_MAIN_LIST_COLUMN_AGE, _T("����ʱ��"));
	aMap.SetAt(LANG_MAIN_LIST_COLUMN_PROFILE, _T("�ű�����"));
	aMap.SetAt(LANG_MAIN_FRAME_BATCH_OPER, _T("��������"));
	aMap.SetAt(LANG_MAIN_FRAME_TASK_DATA, _T("��������"));
	aMap.SetAt(LANG_MAIN_OPEN_LOG, _T("����־"));
	aMap.SetAt(LANG_MAIN_CLEAN_LOG, _T("�����־"));

	// Log
	aMap.SetAt(LANG_LOG_APP_STARTED, _T("ARelogger������"));
	aMap.SetAt(LANG_LOG_APP_EXIT, _T("ARelogger���˳�"));
	aMap.SetAt(LANG_LOG_PASSWORD_CREATED, _T("�������봴���ɹ�"));
	aMap.SetAt(LANG_LOG_LOGIN_SUCCESSFUL, _T("��¼�ɹ�"));
	aMap.SetAt(LANG_LOG_INVALID_PASSWORD, _T("��Ч�ķ�������"));
	aMap.SetAt(LANG_LOG_DATA_DELETED, _T("��ɾ���û�����"));
	aMap.SetAt(LANG_LOG_DATA_NOT_FOUND, _T("δ�ҵ��������ݣ������û��������"));
	aMap.SetAt(LANG_LOG_DATA_LOADED, _T("�Ѷ�ȡ%d���洢������"));
	aMap.SetAt(LANG_LOG_DATA_SAVED, _T("�ѱ���%d����������"));
	aMap.SetAt(LANG_LOG_KILLED_BLIZZARD_ERROR, _T("�ѷ��ֲ�ɱ������[BlizzardError.exe]"));
	aMap.SetAt(LANG_LOG_TASK_CREATED, _T("���񴴽��ɹ�"));
	aMap.SetAt(LANG_LOG_TASK_MODIFIED, _T("���������Ѹ���"));
	aMap.SetAt(LANG_LOG_TASK_DELETED, _T("������ɾ��"));
	aMap.SetAt(LANG_LOG_PASSWORD_CHANGED, _T("���������޸ĳɹ�"));
	aMap.SetAt(LANG_LOG_MONITOR_TRIPWIRE, _T("����쳣��TripWire�¼�������"));
	aMap.SetAt(LANG_LOG_MONITOR_DIABLO_CLOSED, _T("����쳣��Diablo III�ѹر�"));
	aMap.SetAt(LANG_LOG_MONITOR_DEMONBUDDY_CLOSED, _T("����쳣��Demonbuddy�ѹر�"));
	aMap.SetAt(LANG_LOG_MONITOR_OUT_OF_GAME, _T("����쳣����ɫ�뿪��Ϸ�ѳ���ʱ��"));
	aMap.SetAt(LANG_LOG_MONITOR_DIABLO_DISCONNECTED, _T("����쳣����Ϸ�Ͽ������ѳ���ʱ��"));
	aMap.SetAt(LANG_LOG_MONITOR_DIABLO_UNRESPONSIVE, _T("����쳣��Diablo IIIʧȥ��Ӧ�ѳ���ʱ��"));
	aMap.SetAt(LANG_LOG_MONITOR_DEMONBUDDY_UNRESPONSIVE, _T("����쳣��Demonbuddyʧȥ��Ӧ�ѳ���ʱ��"));
	aMap.SetAt(LANG_LOG_MONITOR_DIABLO_MINIMIZED, _T("����쳣������ֹDiablo III������С��"));
	aMap.SetAt(LANG_LOG_SET_HIDE_WINDOW_TRUE, _T("����������Ϸ���ڣ�TRUE"));
	aMap.SetAt(LANG_LOG_SET_HIDE_WINDOW_FALSE, _T("����������Ϸ���ڣ�FALSE"));
	aMap.SetAt(LANG_LOG_DIABLO_LOGIN_SCREEN, _T("�ѵ����˺ŵ�¼����"));
	aMap.SetAt(LANG_LOG_DIABLO_LOGIN_SUCCESS, _T("Battle.net��¼�ɹ�"));
	aMap.SetAt(LANG_LOG_DIABLO_LOGIN_FAILED, _T("Battle.net��¼ʧ�ܣ�������ֹ������������"));
	aMap.SetAt(LANG_LOG_DIABLO_GAME_JOINED, _T("��ɫ�ѽ�����Ϸ"));
	aMap.SetAt(LANG_LOG_DIABLO_GAME_LEFT, _T("��ɫ���뿪��Ϸ"));
	aMap.SetAt(LANG_LOG_DIABLO_GAME_DISCONNECTED, _T("��Ϸ�ѶϿ�����"));
	aMap.SetAt(LANG_LOG_LAUNCH_ERROR_RETRY, _T("5��������������񡭡�"));
	aMap.SetAt(LANG_LOG_LAUNCH_PREPARE, _T("׼����������"));
	aMap.SetAt(LANG_LOG_LAUNCH_CLEANUP, _T("�ȴ��������̽���"));
	aMap.SetAt(LANG_LOG_LAUNCH_PREPARE_DIABLO, _T("׼������Diablo III"));
	aMap.SetAt(LANG_LOG_LAUNCH_START_DIABLO, _T("��������Diablo III"));
	aMap.SetAt(LANG_LOG_LAUNCH_START_DIABLO_FAILED, _T("Diablo III����ʧ�ܣ�"));
	aMap.SetAt(LANG_LOG_LAUNCH_DIABLO_REUSED, _T("Diablo III���̽ӹܳɹ���PID=%d"));
	aMap.SetAt(LANG_LOG_LAUNCH_DIABLO_SUCCESS, _T("Diablo III�����ɹ���PID=%d"));
	aMap.SetAt(LANG_LOG_LAUNCH_WAIT_DIABLO, _T("�ȴ�Diablo III����������"));
	aMap.SetAt(LANG_LOG_LAUNCH_WAIT_BNET_LOGIN, _T("�ȴ�Battle.net��¼��֤"));
	aMap.SetAt(LANG_LOG_LAUNCH_BNET_LOGIN_TIMEOUT, _T("Battle.net��¼��֤��ʱ"));
	aMap.SetAt(LANG_LOG_LAUNCH_WAIT_JOIN_GAME, _T("�ȴ���ɫ������Ϸ"));
	aMap.SetAt(LANG_LOG_LAUNCH_JOIN_GAME_FAILED, _T("��Ϸ����ʧ�ܣ�"));
	aMap.SetAt(LANG_LOG_LAUNCH_PREPARE_DEMONBUDDY, _T("׼������Demonbuddy"));
	aMap.SetAt(LANG_LOG_LAUNCH_START_DEMONBUDDY, _T("��������Demonbuddy"));
	aMap.SetAt(LANG_LOG_LAUNCH_START_DEMONBUDDY_FAILED, _T("Demonbuddy����ʧ�ܣ�"));
	aMap.SetAt(LANG_LOG_LAUNCH_DEMONBUDDY_REUSED, _T("Demonbuddy���̽ӹܳɹ���PID=%d"));
	aMap.SetAt(LANG_LOG_LAUNCH_WAIT_DEMONBUDDY, _T("�ȴ�Demonbuddy����������"));
	aMap.SetAt(LANG_LOG_LAUNCH_DEMONBUDDY_SUCCESS, _T("Demonbuddy�����ɹ���PID=%d"));
	aMap.SetAt(LANG_LOG_LAUNCH_CLOSE_DEMONBUDDY_ERROR, _T("�ر�Demonbuddy���󴰿�"));
	aMap.SetAt(LANG_LOG_LAUNCH_CLOSE_DEMONBUDDY, _T("�ر�DemonBuddy"));
	aMap.SetAt(LANG_LOG_LAUNCH_CHECK_DEMONBUDDY_CLOSE, _T("�ȴ�DemonBuddy���̹ر�"));
	aMap.SetAt(LANG_LOG_LAUNCH_DEMONBUDDY_CLOSED, _T("DemonBuddy���̹رճɹ�"));
	aMap.SetAt(LANG_LOG_LAUNCH_WAIT_GAME_STABLIZE, _T("�ȴ���Ϸ״̬�ȶ�������������DemonBuddy"));
	aMap.SetAt(LANG_LOG_LAUNCH_SUCCESSFUL, _T("���������ɹ���ת��������ؽ׶�"));
	aMap.SetAt(LANG_LOG_LAUNCH_HIDE_PROCESSES, _T("�Ѹ����������ر���صĽ��̴���"));
	aMap.SetAt(LANG_LOG_STATE_LAUNCH, _T("׼����������"));
	aMap.SetAt(LANG_LOG_STATE_MONITOR, _T("�����ؿ�ʼ"));
	aMap.SetAt(LANG_LOG_STATE_START, _T("�����̴߳���"));
	aMap.SetAt(LANG_LOG_STATE_STOP, _T("�����߳�ֹͣ"));
	aMap.SetAt(LANG_LOG_STATE_PAUSE, _T("������ͣ"));
	aMap.SetAt(LANG_LOG_STATE_RESUME, _T("����ָ�"));

	// Message box
	aMap.SetAt(LANG_MSG_INVALID_INPUT_TITLE, _T("��Ч����"));
	aMap.SetAt(LANG_MSG_CREATE_PASSWORD_TITLE, _T("������������"));
	aMap.SetAt(LANG_MSG_CREATE_PASSWORD_TEXT, _T("��ʹ��ARelogger֮ǰ����Ҫ����һ���������룬������������Ҫ�����ս����¼��Ϣ�ȸ������ݽ��м��ܱ������������벻�ᱻ���浽�����ϣ��������Ҫ�����μ����ģ������޷����ܵ�¼���ݡ�"));
	aMap.SetAt(LANG_MSG_DELETE_TASK_TITLE, _T("ɾ������"));
	aMap.SetAt(LANG_MSG_DELETE_TASK_TEXT, _T("����ɾ������[%s]���˲������ɻָ���ȷ��Ҫɾ����"));
	aMap.SetAt(LANG_MSG_CLEAN_LOG_TITLE, _T("�����־"));
	aMap.SetAt(LANG_MSG_CLEAN_LOG_TEXT, _T("��������Ѵ������־���ݣ�ȷ����"));
	aMap.SetAt(LANG_MSG_STOP_ALL_TITLE, _T("ȫ��ֹͣ"));
	aMap.SetAt(LANG_MSG_STOP_ALL_TEXT, _T("��ǰ��%d���������������У�ȷ��Ҫȫ��ֹͣ���ر�����Щ�����������Diablo3��Demonbuddy������"));
	aMap.SetAt(LANG_MSG_EXIT_APP_TITLE, _T("�˳�ARelogger"));
	aMap.SetAt(LANG_MSG_TASK_RUNNING_TITLE, _T("����������"));
	aMap.SetAt(LANG_MSG_TASK_RUNNING_TEXT, _T("����[%s]���������У���ֹͣ���ٽ��в�����"));
	aMap.SetAt(LANG_MSG_TASK_CONFLICT_TITLE, _T("�������Գ�ͻ"));
	aMap.SetAt(LANG_MSG_TASK_CONFLICT_TEXT, _T("����[%s]���õ�Diablo��ϷĿ¼[%s]�����������е�����[%s]��ͬ��Diablo3��������ͬһ·����˫������������������"));
	aMap.SetAt(LANG_MSG_INPUT_CANNOT_BE_EMPTY, _T("[%s]����Ϊ�ա�"));
	aMap.SetAt(LANG_MSG_INPUT_INVALID_PATH, _T("[%s]����һ����ȷ��%s·����"));
	aMap.SetAt(LANG_MSG_DELETE_DATA_TITLE, _T("�������"));
	aMap.SetAt(LANG_MSG_DELERE_DATA_TEXT, _T("�˲�����ɾ���ѱ�������ݣ������ٴ�����AReloggerʱ�������û���ݵ�¼��ɾ���������޷��ָ���ȷ��Ҫ�����"));
	aMap.SetAt(LANG_MSG_PASSWORD_REPEAT_MISMATCH, _T("���������ظ������������ͬ��"));
	aMap.SetAt(LANG_MSG_ORIGINAL_PASSWORD_INCORRECT, _T("ԭ�������벻��ȷ��"));

	// Password window
	aMap.SetAt(LANG_PASSWORD_TITLE, _T("�������������"));
	aMap.SetAt(LANG_PASSWORD_PASSWORD, _T("��������"));
	aMap.SetAt(LANG_PASSWORD_OLD_PASSWORD, _T("ԭ��������"));
	aMap.SetAt(LANG_PASSWORD_INVALID_TITLE, _T("�����������"));
	aMap.SetAt(LANG_PASSWORD_INVALID_TEXT, _T("�����ѡ�����������������룬��������������ݲ������û������������ARelogger��"));
	aMap.SetAt(LANG_PASSWORD_RETRY, _T("����"));
	aMap.SetAt(LANG_PASSWORD_CLEAN_EXIT, _T("������ݲ��˳�"));
	aMap.SetAt(LANG_PASSWORD_CREATE_TITLE, _T("��������"));
	aMap.SetAt(LANG_PASSWORD_CREATE_NEW_PASSWORD, _T("����������"));
	aMap.SetAt(LANG_PASSWORD_CREATE_REPEAT_PASSWORD, _T("�ظ�������"));

	// Task window
	aMap.SetAt(LANG_TASK_TITLE, _T("��������"));
	aMap.SetAt(LANG_TASK_FRAME_TASK, _T("����"));
	aMap.SetAt(LANG_TASK_TASK_NAME, _T("��������"));
	aMap.SetAt(LANG_TASK_DIABLO_PATH, _T("��ϷĿ¼"));
	aMap.SetAt(LANG_TASK_ACCOUNT, _T("ս���˺�"));
	aMap.SetAt(LANG_TASK_PASSWORD, _T("ս������"));
	aMap.SetAt(LANG_TASK_I_USE_BNET_AUTHENTICATOR, _T("��ʹ��ս����ȫ��"));
	aMap.SetAt(LANG_TASK_SERIAL, _T("���к�"));
	aMap.SetAt(LANG_TASK_RESTORE_CODE, _T("��ԭ����"));
	aMap.SetAt(LANG_TASK_DEMONBUDDY_PATH, _T("����Ŀ¼"));
	aMap.SetAt(LANG_TASK_AUTHORIZE_CODE, _T("��Ȩ��"));
	aMap.SetAt(LANG_TASK_PROFILE_PATH, _T("�ű��ļ�"));

	// Config window
	aMap.SetAt(LANG_CONFIG_TITLE, _T("����ѡ��"));
	aMap.SetAt(LANG_CONFIG_DBLCLK_TASK_LIST, _T("˫�������б�"));
	aMap.SetAt(LANG_CONFIG_NO_OPERATION, _T("�޲���"));
	aMap.SetAt(LANG_CONFIG_OPEN_TASK_EDITING_WINDOW, _T("������༭����"));
	aMap.SetAt(LANG_CONFIG_CYCLE_START_STOP, _T("ѭ�������� - ֹͣ"));
	aMap.SetAt(LANG_CONFIG_CYCLE_START_STOP_NO_KILL, _T("ѭ�������� - ֹͣ���������̣�"));
	aMap.SetAt(LANG_CONFIG_CYCLE_START_PAUSE_RESUME, _T("ѭ�������� - ��ͣ - �ָ�"));
	aMap.SetAt(LANG_CONFIG_TASK_CONTROL, _T("���п���"));
	aMap.SetAt(LANG_CONFIG_PREVENT_DIABLO_MINIMIZED, _T("��ֹDiablo������С��"));
	aMap.SetAt(LANG_CONFIG_MONITOR_TRIPWIRE_EVENT, _T("���ȼ��TripWire�¼�"));
	aMap.SetAt(LANG_CONFIG_DOUBLE_LAUNCH_DEMONBUDDY, _T("ʹ��Demonbuddy��������ģʽ�Ա���������"));
	aMap.SetAt(LANG_CONFIG_ATTACH_EXISTING_PROCESSES, _T("�ӹ��Ѵ��ڵ�Diablo/Demonbuddy����"));
	aMap.SetAt(LANG_CONFIG_TIMEOUT, _T("�ȴ�ʱ��"));
	aMap.SetAt(LANG_CONFIG_TIMEOUT_LAUNCH_DIABLO, _T("����Diablo3��Ϸ"));
	aMap.SetAt(LANG_CONFIG_TIMEOUT_BNET_LOGIN, _T("Battle.net��¼"));
	aMap.SetAt(LANG_CONFIG_TIMEOUT_CREATE_GAME, _T("������Ϸ"));
	aMap.SetAt(LANG_CONFIG_TIMEOUT_OUT_OF_GAME, _T("��ɫ�뿪��Ϸ"));
	aMap.SetAt(LANG_CONFIG_TIMEOUT_GAME_DISCONNECTED, _T("��Ϸ�Ͽ�����"));
	aMap.SetAt(LANG_CONFIG_TIMEOUT_DIABLO_UNRESPONSIVE, _T("Diabloʧȥ��Ӧ"));
	aMap.SetAt(LANG_CONFIG_TIMEOUT_DEMONBUDDY_UNRESPONSIVE, _T("Demonbuddyʧȥ��Ӧ"));
	aMap.SetAt(LANG_CONFIG_FORCE_RESTART_IF_TIMEOUT, _T("�ȴ�ʱ�޵����ǿ������Diablo��Demonbuddy"));
	aMap.SetAt(LANG_CONFIG_TOOLTIP_PREVENT_MIN, _T("Demonbuddy��Diablo��Ϸ���ڱ���С�����޷�������������ѡ��ARelogger���Զ���ֹ��Ϸ������С����"));
	aMap.SetAt(LANG_CONFIG_TOOLTIP_DB_2X_LOGIN, _T("Ŀǰ�汾��Demonbuddy����ڽ�ɫ������Ϸ֮ǰ���������������������������Ӱ��������е��ȶ��ԣ���ѡ��ARelogger���ڽ�ɫ������Ϸ���Զ�����Demonbuddy���������в������"));
	aMap.SetAt(LANG_CONFIG_TOOLTIP_TAKEOVER_PROCESS, _T("��������ʱ�����������е�Diablo/Demonbuddy���̣�������Ͻӹ��������������Ƚӹ����н��̶����������½��̡�"));
	aMap.SetAt(LANG_CONFIG_RESTORE_DEFAULTS, _T("�ָ�Ĭ��ֵ"));
	aMap.SetAt(LANG_CONFIG_SECONDS, _T("��"));
}

