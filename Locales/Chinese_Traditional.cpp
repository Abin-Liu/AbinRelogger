#include "stdafx.h"
#include "..\Languages.h"

void CLanguage::Provider_Chinese_Traditional(CLangMap& aMap)
{
	// Menu
	aMap.SetAt(LANG_MENU_FILE, _T("�ļ�"));
	aMap.SetAt(LANG_MENU_EXIT, _T("�˳�"));
	aMap.SetAt(LANG_MENU_TASK, _T("�΄�"));
	aMap.SetAt(LANG_MENU_START, _T("����"));
	aMap.SetAt(LANG_MENU_STOP, _T("ֹͣ"));
	aMap.SetAt(LANG_MENU_STOP_DETACH, _T("ֹͣ�������M�̣�"));
	aMap.SetAt(LANG_MENU_PAUSE_RESUME, _T("��ͣ/�֏�"));
	aMap.SetAt(LANG_MENU_HIDE_GAME, _T("�[���[��"));
	aMap.SetAt(LANG_MENU_NEW, _T("�½�"));
	aMap.SetAt(LANG_MENU_EDIT, _T("��݋"));
	aMap.SetAt(LANG_MENU_CLONE, _T("�}�u"));
	aMap.SetAt(LANG_MENU_DELETE, _T("�h��"));
	aMap.SetAt(LANG_MENU_OPTIONS, _T("�O��"));
	aMap.SetAt(LANG_MENU_LANGUAGES, _T("�Z��"));
	aMap.SetAt(LANG_MENU_CHANGE_PASSWORD, _T("�����ܴa"));
	aMap.SetAt(LANG_MENU_SETTINGS, _T("�x�..."));
	aMap.SetAt(LANG_MENU_HELP, _T("����"));
	aMap.SetAt(LANG_MENU_ABOUT, _T("�P�"));
	aMap.SetAt(LANG_MENU_TASK_LIST, _T("�΄��б�"));
	aMap.SetAt(LANG_MENU_HIDE_ALL, _T("ȫ���[��"));
	aMap.SetAt(LANG_MENU_SHOW_ALL, _T("ȫ���@ʾ"));
	aMap.SetAt(LANG_MENU_STOP_ALL, _T("ȫ��ֹͣ"));
	aMap.SetAt(LANG_MENU_OK, _T("�_��"));
	aMap.SetAt(LANG_MENU_CANCEL, _T("ȡ��"));

	// About window
	aMap.SetAt(LANG_ABOUT_TITLE, _T("�P�ARelogger"));
	aMap.SetAt(LANG_ABOUT_COPYRIGHT, _T("�������(C) 2016, Abin"));

	// Main window
	aMap.SetAt(LANG_MAIN_LOG, _T("���I"));
	aMap.SetAt(LANG_MAIN_SUGGEST_CLEAN, _T("�����h��գ�"));
	aMap.SetAt(LANG_MAIN_LIST_COLUMN_NAME, _T("���Q"));
	aMap.SetAt(LANG_MAIN_LIST_COLUMN_AGE, _T("�\�Еr�g"));
	aMap.SetAt(LANG_MAIN_LIST_COLUMN_PROFILE, _T("�_�����Q"));
	aMap.SetAt(LANG_MAIN_FRAME_BATCH_OPER, _T("��������"));
	aMap.SetAt(LANG_MAIN_FRAME_TASK_DATA, _T("�΄Ք���"));
	aMap.SetAt(LANG_MAIN_OPEN_LOG, _T("���_���I"));
	aMap.SetAt(LANG_MAIN_CLEAN_LOG, _T("������I"));

	// Log
	aMap.SetAt(LANG_LOG_APP_STARTED, _T("ARelogger�ц���"));
	aMap.SetAt(LANG_LOG_APP_EXIT, _T("ARelogger���˳�"));
	aMap.SetAt(LANG_LOG_PASSWORD_CREATED, _T("�L���ܴa�����ɹ�"));
	aMap.SetAt(LANG_LOG_LOGIN_SUCCESSFUL, _T("��䛳ɹ�"));
	aMap.SetAt(LANG_LOG_INVALID_PASSWORD, _T("�oЧ���L���ܴa"));
	aMap.SetAt(LANG_LOG_DATA_DELETED, _T("�фh���Ñ�����"));
	aMap.SetAt(LANG_LOG_DATA_NOT_FOUND, _T("δ�ҵ����������������Ñ�����\��"));
	aMap.SetAt(LANG_LOG_DATA_LOADED, _T("���d��%d��������΄�"));
	aMap.SetAt(LANG_LOG_DATA_SAVED, _T("�ѱ���%d���΄Ք���"));
	aMap.SetAt(LANG_LOG_KILLED_BLIZZARD_ERROR, _T("�Ѱl�F�������M��[BlizzardError.exe]"));
	aMap.SetAt(LANG_LOG_TASK_CREATED, _T("�΄Մ����ɹ�"));
	aMap.SetAt(LANG_LOG_TASK_MODIFIED, _T("�΄Ք����Ѹ���"));
	aMap.SetAt(LANG_LOG_TASK_DELETED, _T("�΄��фh��"));
	aMap.SetAt(LANG_LOG_PASSWORD_CHANGED, _T("�L���ܴa�޸ĳɹ�"));
	aMap.SetAt(LANG_LOG_MONITOR_TRIPWIRE, _T("�O�خ�����TripWire�¼��|�l"));
	aMap.SetAt(LANG_LOG_MONITOR_DIABLO_CLOSED, _T("�O�خ�����Diablo III���P�]"));
	aMap.SetAt(LANG_LOG_MONITOR_DEMONBUDDY_CLOSED, _T("�O�خ�����Demonbuddy���P�]"));
	aMap.SetAt(LANG_LOG_MONITOR_OUT_OF_GAME, _T("�O�خ�������ɫ�x�_�[���ѳ��^�r��"));
	aMap.SetAt(LANG_LOG_MONITOR_DIABLO_DISCONNECTED, _T("�O�خ������[����_�B���ѳ��^�r��"));
	aMap.SetAt(LANG_LOG_MONITOR_DIABLO_UNRESPONSIVE, _T("�O�خ�����Diablo IIIʧȥ푑��ѳ��^�r��"));
	aMap.SetAt(LANG_LOG_MONITOR_DEMONBUDDY_UNRESPONSIVE, _T("�O�خ�����Demonbuddyʧȥ푑��ѳ��^�r��"));
	aMap.SetAt(LANG_LOG_MONITOR_DIABLO_MINIMIZED, _T("�O�خ���������ֹDiablo IIIҕ����С��"));
	aMap.SetAt(LANG_LOG_SET_HIDE_WINDOW_TRUE, _T("�O���[���[��ҕ����TRUE"));
	aMap.SetAt(LANG_LOG_SET_HIDE_WINDOW_FALSE, _T("�O���[���[��ҕ����FALSE"));
	aMap.SetAt(LANG_LOG_DIABLO_LOGIN_SCREEN, _T("�ѵ��_�~̖��䛽���"));
	aMap.SetAt(LANG_LOG_DIABLO_LOGIN_SUCCESS, _T("Battle.net��䛳ɹ�"));
	aMap.SetAt(LANG_LOG_DIABLO_LOGIN_FAILED, _T("Battle.net���ʧ�����΄սKֹ��Ո�����O��"));
	aMap.SetAt(LANG_LOG_DIABLO_GAME_JOINED, _T("��ɫ���M���[��"));
	aMap.SetAt(LANG_LOG_DIABLO_GAME_LEFT, _T("��ɫ���x�_�[��"));
	aMap.SetAt(LANG_LOG_DIABLO_GAME_DISCONNECTED, _T("�[���є��_�B��"));
	aMap.SetAt(LANG_LOG_LAUNCH_ERROR_RETRY, _T("5�����������΄ա���"));
	aMap.SetAt(LANG_LOG_LAUNCH_PREPARE, _T("�ʂ䆢���΄�"));
	aMap.SetAt(LANG_LOG_LAUNCH_CLEANUP, _T("�ȴ������M�̽Y��"));
	aMap.SetAt(LANG_LOG_LAUNCH_PREPARE_DIABLO, _T("�ʂ䆢��Diablo III"));
	aMap.SetAt(LANG_LOG_LAUNCH_START_DIABLO, _T("���چ���Diablo III"));
	aMap.SetAt(LANG_LOG_LAUNCH_START_DIABLO_FAILED, _T("Diablo III����ʧ����"));
	aMap.SetAt(LANG_LOG_LAUNCH_DIABLO_REUSED, _T("Diablo III�M�̽ӹܳɹ���PID=%d"));
	aMap.SetAt(LANG_LOG_LAUNCH_DIABLO_SUCCESS, _T("Diablo III���ӳɹ���PID=%d"));
	aMap.SetAt(LANG_LOG_LAUNCH_WAIT_DIABLO, _T("�ȴ�Diablo III�M����ҕ��"));
	aMap.SetAt(LANG_LOG_LAUNCH_WAIT_BNET_LOGIN, _T("�ȴ�Battle.net�����C"));
	aMap.SetAt(LANG_LOG_LAUNCH_BNET_LOGIN_TIMEOUT, _T("Battle.net�����C���r"));
	aMap.SetAt(LANG_LOG_LAUNCH_WAIT_JOIN_GAME, _T("�ȴ���ɫ�����[��"));
	aMap.SetAt(LANG_LOG_LAUNCH_JOIN_GAME_FAILED, _T("�[�򄓽�ʧ����"));
	aMap.SetAt(LANG_LOG_LAUNCH_PREPARE_DEMONBUDDY, _T("�ʂ䆢��Demonbuddy"));
	aMap.SetAt(LANG_LOG_LAUNCH_START_DEMONBUDDY, _T("���چ���Demonbuddy"));
	aMap.SetAt(LANG_LOG_LAUNCH_START_DEMONBUDDY_FAILED, _T("Demonbuddy����ʧ����"));
	aMap.SetAt(LANG_LOG_LAUNCH_DEMONBUDDY_REUSED, _T("Demonbuddy�M�̽ӹܳɹ���PID=%d"));
	aMap.SetAt(LANG_LOG_LAUNCH_WAIT_DEMONBUDDY, _T("�ȴ�Demonbuddy�M����ҕ��"));
	aMap.SetAt(LANG_LOG_LAUNCH_DEMONBUDDY_SUCCESS, _T("Demonbuddy���ӳɹ���PID=%d"));
	aMap.SetAt(LANG_LOG_LAUNCH_CLOSE_DEMONBUDDY_ERROR, _T("�P�]Demonbuddy�e�`ҕ��"));
	aMap.SetAt(LANG_LOG_LAUNCH_CLOSE_DEMONBUDDY, _T("�P�]DemonBuddy"));
	aMap.SetAt(LANG_LOG_LAUNCH_CHECK_DEMONBUDDY_CLOSE, _T("�ȴ�DemonBuddy�M���P�]"));
	aMap.SetAt(LANG_LOG_LAUNCH_DEMONBUDDY_CLOSED, _T("DemonBuddy�M���P�]�ɹ�"));
	aMap.SetAt(LANG_LOG_LAUNCH_WAIT_GAME_STABLIZE, _T("�ȴ��[���B��������������DemonBuddy"));
	aMap.SetAt(LANG_LOG_LAUNCH_SUCCESSFUL, _T("�΄Ն��ӳɹ����D�������O���A��"));
	aMap.SetAt(LANG_LOG_LAUNCH_HIDE_PROCESSES, _T("�Ѹ����O���[�ر��O�ص��M�̴���"));
	aMap.SetAt(LANG_LOG_STATE_LAUNCH, _T("�ʂ䆢���΄�"));
	aMap.SetAt(LANG_LOG_STATE_MONITOR, _T("�΄ձO���_ʼ"));
	aMap.SetAt(LANG_LOG_STATE_START, _T("�΄վ��̄���"));
	aMap.SetAt(LANG_LOG_STATE_STOP, _T("�΄վ���ֹͣ"));
	aMap.SetAt(LANG_LOG_STATE_PAUSE, _T("�΄Օ�ͣ"));
	aMap.SetAt(LANG_LOG_STATE_RESUME, _T("�΄ջ֏�"));

	// Message box
	aMap.SetAt(LANG_MSG_INVALID_INPUT_TITLE, _T("�oЧݔ��"));
	aMap.SetAt(LANG_MSG_CREATE_PASSWORD_TITLE, _T("�����L���ܴa"));
	aMap.SetAt(LANG_MSG_CREATE_PASSWORD_TEXT, _T("��ʹ��ARelogger֮ǰ����Ҫ����һ���L���ܴa�����Á팦����Ҫݔ��đ�W�����Ϣ�����Д����M�м��ܱ��o���L���ܴa���������浽�ŵ��ϣ��������Ҫ������ӛ��ģ���t���o�����ܵ�䛔�����"));
	aMap.SetAt(LANG_MSG_DELETE_TASK_TITLE, _T("�h���΄�"));
	aMap.SetAt(LANG_MSG_DELETE_TASK_TEXT, _T("�����h���΄�[%s]���˲������ɻ֏ͣ��_��Ҫ�h���᣿"));
	aMap.SetAt(LANG_MSG_CLEAN_LOG_TITLE, _T("������I"));
	aMap.SetAt(LANG_MSG_CLEAN_LOG_TEXT, _T("��������у�������I���ݣ��_���᣿"));
	aMap.SetAt(LANG_MSG_STOP_ALL_TITLE, _T("ȫ��ֹͣ"));
	aMap.SetAt(LANG_MSG_STOP_ALL_TEXT, _T("��ǰ��%d���΄������\���У��_��Ҫȫ��ֹͣ���P�]���@Щ�΄��������Diablo3�cDemonbuddy�M�̆᣿"));
	aMap.SetAt(LANG_MSG_EXIT_APP_TITLE, _T("�˳�Relogger"));
	aMap.SetAt(LANG_MSG_TASK_RUNNING_TITLE, _T("�΄��\����"));
	aMap.SetAt(LANG_MSG_TASK_RUNNING_TEXT, _T("�΄�[%s]�����\���У�Ոֹͣ���ٲ�����"));
	aMap.SetAt(LANG_MSG_TASK_CONFLICT_TITLE, _T("�΄Ռ����nͻ"));
	aMap.SetAt(LANG_MSG_TASK_CONFLICT_TEXT, _T("�΄�[%s]�O�õ�Diablo�[��Ŀ�[%s]�c�����\���е��΄���[%s]��ͬ��Diablo3�����S��ͬһ·�����p�_��Ո�����O���΄ա�"));
	aMap.SetAt(LANG_MSG_INPUT_CANNOT_BE_EMPTY, _T("[%s]���ܞ�ա�"));
	aMap.SetAt(LANG_MSG_INPUT_INVALID_PATH, _T("[%s]����һ�����_��%s·����"));
	aMap.SetAt(LANG_MSG_DELETE_DATA_TITLE, _T("��Ք���"));
	aMap.SetAt(LANG_MSG_DELERE_DATA_TEXT, _T("�˲������h���ѱ���Ĕ����������ٴ��\��ARelogger�r�������Ñ���ݵ�䛣��h���Ĕ����o���֏͡��_��Ҫ��Ն᣿"));
	aMap.SetAt(LANG_MSG_PASSWORD_REPEAT_MISMATCH, _T("���ܴa�c���}���ܴa�����ͬ��"));
	aMap.SetAt(LANG_MSG_ORIGINAL_PASSWORD_INCORRECT, _T("ԭ�L���ܴa�����_��"));

	// Password window
	aMap.SetAt(LANG_PASSWORD_TITLE, _T("Ոݔ���L���ܴa"));
	aMap.SetAt(LANG_PASSWORD_PASSWORD, _T("�L���ܴa"));
	aMap.SetAt(LANG_PASSWORD_OLD_PASSWORD, _T("ԭ�L���ܴa"));
	aMap.SetAt(LANG_PASSWORD_INVALID_TITLE, _T("�L���ܴa�e�`"));
	aMap.SetAt(LANG_PASSWORD_INVALID_TEXT, _T("������x����ԇ����ݔ���ܴa������������Д��������Ñ���������\��ARelogger��"));
	aMap.SetAt(LANG_PASSWORD_RETRY, _T("��ԇ"));
	aMap.SetAt(LANG_PASSWORD_CLEAN_EXIT, _T("��Ք������˳�"));
	aMap.SetAt(LANG_PASSWORD_CREATE_TITLE, _T("�����ܴa"));
	aMap.SetAt(LANG_PASSWORD_CREATE_NEW_PASSWORD, _T("ݔ�����ܴa"));
	aMap.SetAt(LANG_PASSWORD_CREATE_REPEAT_PASSWORD, _T("���}���ܴa"));

	// Task window
	aMap.SetAt(LANG_TASK_TITLE, _T("�΄��O��"));
	aMap.SetAt(LANG_TASK_FRAME_TASK, _T("�΄�"));
	aMap.SetAt(LANG_TASK_TASK_NAME, _T("�΄����Q"));
	aMap.SetAt(LANG_TASK_DIABLO_PATH, _T("�[��Ŀ�"));
	aMap.SetAt(LANG_TASK_ACCOUNT, _T("��W�~̖"));
	aMap.SetAt(LANG_TASK_PASSWORD, _T("��W�ܴa"));
	aMap.SetAt(LANG_TASK_I_USE_BNET_AUTHENTICATOR, _T("��ʹ�Ñ�W��ȫ��"));
	aMap.SetAt(LANG_TASK_SERIAL, _T("����̖"));
	aMap.SetAt(LANG_TASK_RESTORE_CODE, _T("߀ԭ�ܴa"));
	aMap.SetAt(LANG_TASK_DEMONBUDDY_PATH, _T("����Ŀ�"));
	aMap.SetAt(LANG_TASK_AUTHORIZE_CODE, _T("�ڙ�a"));
	aMap.SetAt(LANG_TASK_PROFILE_PATH, _T("�_���ļ�"));

	// Config window
	aMap.SetAt(LANG_CONFIG_TITLE, _T("�O���x�"));
	aMap.SetAt(LANG_CONFIG_DBLCLK_TASK_LIST, _T("�p���΄��б�"));
	aMap.SetAt(LANG_CONFIG_NO_OPERATION, _T("�o����"));
	aMap.SetAt(LANG_CONFIG_OPEN_TASK_EDITING_WINDOW, _T("���_�΄վ�݋ҕ��"));
	aMap.SetAt(LANG_CONFIG_CYCLE_START_STOP, _T("ѭ�h������ - ֹͣ"));
	aMap.SetAt(LANG_CONFIG_CYCLE_START_STOP_NO_KILL, _T("ѭ�h������ - ֹͣ�������M�̣�"));
	aMap.SetAt(LANG_CONFIG_CYCLE_START_PAUSE_RESUME, _T("ѭ�h������ - ��ͣ - �֏�"));
	aMap.SetAt(LANG_CONFIG_TASK_CONTROL, _T("�\�п���"));
	aMap.SetAt(LANG_CONFIG_PREVENT_DIABLO_MINIMIZED, _T("��ֹDiabloҕ����С��"));
	aMap.SetAt(LANG_CONFIG_MONITOR_TRIPWIRE_EVENT, _T("���ȱO��TripWire�¼�"));
	aMap.SetAt(LANG_CONFIG_DOUBLE_LAUNCH_DEMONBUDDY, _T("ʹ��Demonbuddy���Ά���ģʽ�Ա������e�`"));
	aMap.SetAt(LANG_CONFIG_ATTACH_EXISTING_PROCESSES, _T("�ӹ��Ѵ��ڵ�Diablo/Demonbuddy�M��"));
	aMap.SetAt(LANG_CONFIG_TIMEOUT, _T("�ȴ��r��"));
	aMap.SetAt(LANG_CONFIG_TIMEOUT_LAUNCH_DIABLO, _T("����Diablo3�[��"));
	aMap.SetAt(LANG_CONFIG_TIMEOUT_BNET_LOGIN, _T("Battle.net���"));
	aMap.SetAt(LANG_CONFIG_TIMEOUT_CREATE_GAME, _T("�����[��"));
	aMap.SetAt(LANG_CONFIG_TIMEOUT_OUT_OF_GAME, _T("��ɫ�x�_�[��"));
	aMap.SetAt(LANG_CONFIG_TIMEOUT_GAME_DISCONNECTED, _T("�[����_�B��"));
	aMap.SetAt(LANG_CONFIG_TIMEOUT_DIABLO_UNRESPONSIVE, _T("Diabloʧȥ푑�"));
	aMap.SetAt(LANG_CONFIG_TIMEOUT_DEMONBUDDY_UNRESPONSIVE, _T("Demonbuddyʧȥ푑�"));
	aMap.SetAt(LANG_CONFIG_FORCE_RESTART_IF_TIMEOUT, _T("�ȴ��r�޵��_�ጢ�����؆�Diablo�cDemonbuddy"));
	aMap.SetAt(LANG_CONFIG_TOOLTIP_PREVENT_MIN, _T("Demonbuddy��Diablo�[��ҕ������С����o���������������x��ARelogger���Ԅ���ֹ�[��ҕ����С����"));
	aMap.SetAt(LANG_CONFIG_TOOLTIP_DB_2X_LOGIN, _T("Ŀǰ�汾��Demonbuddy����ڽ�ɫ�����[��֮ǰ���ӣ����a����������e�`������Ӱ����m�\�еķ����ԣ����x��ARelogger���ڽ�ɫ�����[����Ԅ��؆�Demonbuddy���������в���e�`��"));
	aMap.SetAt(LANG_CONFIG_TOOLTIP_TAKEOVER_PROCESS, _T("�����΄Օr�������\���е�Diablo/Demonbuddy�M�̣�������Ͻӹܗl�����΄Ռ����ȽӹܬF���M�̶����ǆ������M�̡�"));
	aMap.SetAt(LANG_CONFIG_RESTORE_DEFAULTS, _T("�֏�Ĭ�Jֵ"));
	aMap.SetAt(LANG_CONFIG_SECONDS, _T("��"));
}

