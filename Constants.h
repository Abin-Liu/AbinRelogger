#ifndef __CONSTANTS_H__
#define __CONSTANTS_H__

///////////////////////////////////
// Windows messages
///////////////////////////////////

enum {  WM_REQ_PASSWORD = WM_APP + 100, // Request user password inputs
		WM_TRAY_NOTIFY, // Tray notification message
		WM_BOT_STATE, // Bot running states change
		WM_DIABLO_CONFLICT, // Diablo path conflicts with another running bot
		WM_LANGUAGE_CHANGED, // Language changed
};

///////////////////////////////////
// List double-click operations
///////////////////////////////////

enum {  LIST_OPER_NONE = 0, // NA
		LIST_OPER_EDIT, // Edit bot data
		LIST_OPER_START_STOP, // Start-stop
		LIST_OPER_START_DETACH, // Start-stop(without killing game processes)
		LIST_OPER_START_PAUSE_RESUME, // Start-pause-resume
 };

///////////////////////////////////
// Process launch results
///////////////////////////////////

enum {  PROCESS_FAILED = 0, // Failed to launch a process, error
		PROCESS_ATTACHED, // Reused an existing process
		PROCESS_CREATED }; // Launched a new process

///////////////////////////////////
// Diablo game states
///////////////////////////////////

enum {  GAME_UNKNOWN = 0, // NA
		GAME_LOGIN_SCREEN, // At the login screen, the game awaits user to input account name and password
		GAME_LOGIN_SUCCESS, // Login successfully, now canselect char or create/join games
		GAME_LOGIN_FAIL, // Login failed due to authentication failure, wrong password etc
		GAME_JOINED, // Player is now in a game, either created or joined
		GAME_LEFT, // Player just left a game
		GAME_DISCONNECTED, // Game disconnected from server, game dropped, error 3007 etc
 };

///////////////////////////////////
// Struct for storing diablo game state
///////////////////////////////////

struct DIABLO_STATE_ENTRY
{
	int nStateID; // State
	LPCTSTR lpszText; // Text to search in D3Debug.txt
};

///////////////////////////////////
// Game state entries
///////////////////////////////////

static const DIABLO_STATE_ENTRY DIABLO_STATE_ENTRIES[] = {
	{ GAME_LOGIN_SCREEN, _T("Initializing client world BattleNet_MainScreen...") },
	{ GAME_LOGIN_SUCCESS, _T("AuthenticationListener::OnFinish code=0  battleTag=") },
	{ GAME_LOGIN_FAIL, _T("AuthenticationListener::OnFinish code=3  battleTag=") },
	{ GAME_JOINED, _T("Server Version Information:") },
	{ GAME_LEFT, _T("ClientSocket Disconnect") },
	{ GAME_DISCONNECTED, _T("===== Battle.net Logged Out =====") },
};

static const int NUM_DIABLO_STATES = sizeof(DIABLO_STATE_ENTRIES) / sizeof(DIABLO_STATE_ENTRY);

///////////////////////////////////
// List fields
///////////////////////////////////

enum {  LIST_FLD_NONE = 0,
		LIST_FLD_NAME, // Bot name
		LIST_FLD_AGE, // Thread age
		LIST_FLD_DIABLO, // Diablo process id
		LIST_FLD_DEMONBUDDY, // Demonbuddy process id
		LIST_FLD_PROFILE, // Profile name
};

///////////////////////////////////
// List images for indication thread running states: stopped, launching, paused, monitoring, hiding game, etc
///////////////////////////////////

enum {  IMG_NONE = -1, // don't show any image
		IMG_LAUNCHING, // Launching game or demonbuddy, red triangel
		IMG_RUNNING, // Monitoring, blue triangel
		IMG_PAUSED, // Thread paused, 2 vertical bars
		IMG_HIDEGAME, // Hiding game, an eye simbol
};

///////////////////////////////////
// Update bot data in list fields
///////////////////////////////////

enum {  UPDATE_BOT_SETTINGS = 0x01, // Bot name & profile name
		UPDATE_BOT_RUN = 0x02, // Bot running states (images)
		UPDATE_BOT_AGE = 0x04, // Thread age
		UPDATE_BOT_PROCESS = 0x08, // Diablo & demonbuddy process id's
};

///////////////////////////////////
// Bot running states
///////////////////////////////////

enum {  BOT_UNKNOWN = 0,
		
		BOT_DEBUG,
	
		BOT_MONITOR_TRIPWIRE, // Tripwire event fired!
		BOT_MONITOR_DIABLO_CLOSED, // Diablo process closed
		BOT_MONITOR_DEMONBUDDY_CLOSED, // Demonbuddy process closed
		BOT_MONITOR_OUT_OF_GAME, // Player has been out of game for too long
		BOT_MONITOR_DIABLO_DISCONNECTED, // Diablo disconnected for too long
		BOT_MONITOR_DIABLO_UNRESPONSIVE, // Diablo window has been unresponsive for too long
		BOT_MONITOR_DEMONBUDDY_UNRESPONSIVE, // Demonbuddy window has been unresponsive for too long
		BOT_MONITOR_DIABLO_MINIMIZED, // Diablo window minimized

		BOT_SET_HIDE_WINDOW_TRUE, // Config hide game: on
		BOT_SET_HIDE_WINDOW_FALSE, // Config hide game: off

		BOT_DIABLO_LOGIN_SCREEN, // Reached login screen
		BOT_DIABLO_LOGIN_SUCCESS, // Login succeeded
		BOT_DIABLO_LOGIN_FAILED, // Login failed
		BOT_DIABLO_GAME_JOINED, // Player joined game
		BOT_DIABLO_GAME_LEFT, // Player left game
		BOT_DIABLO_GAME_DISCONNECTED, // Game disconnected

		BOT_LAUNCH_PREPARE, // Prepare to launch
		BOT_LAUNCH_CLEANUP,	// Cleanup existing processes
		BOT_LAUNCH_PREPARE_DIABLO, // Prepare to launch diablo
		BOT_LAUNCH_START_DIABLO, // Starting diablo
		BOT_LAUNCH_START_DIABLO_FAILED, // Diablo launch failed
		BOT_LAUNCH_DIABLO_REUSED, // An existing diablo process has been taken over
		BOT_LAUNCH_DIABLO_SUCCESS, // Diablo launch succeeded
		BOT_LAUNCH_WAIT_DIABLO, // Waiting for diablo window
		BOT_LAUNCH_WAIT_BNET_LOGIN, // Waiting for bnet login authentication
		BOT_LAUNCH_BNET_LOGIN_TIMEOUT, // Bnet login timeout
		BOT_LAUNCH_WAIT_JOIN_GAME, // Waiting to join game
		BOT_LAUNCH_JOIN_GAME_FAILED, // Failed to join game
		BOT_LAUNCH_PREPARE_DEMONBUDDY, // Prepare to launch demonbuddy
		BOT_LAUNCH_START_DEMONBUDDY1, // Start demonbuddy stage-1
		BOT_LAUNCH_START_DEMONBUDDY2, // Start demonbuddy stage-2
		BOT_LAUNCH_START_DEMONBUDDY_FAILED, // Failed to launch demonbuddy
		BOT_LAUNCH_DEMONBUDDY_REUSED, // An existing demonbuddy process has been taken over
		BOT_LAUNCH_WAIT_DEMONBUDDY1, // Waiting for demonbuddy window stage-1
		BOT_LAUNCH_WAIT_DEMONBUDDY2, // Waiting for demonbuddy window stage-2
		BOT_LAUNCH_DEMONBUDDY_SUCCESS, // Demonbuddy launch succeeded
		BOT_LAUNCH_CLOSE_DEMONBUDDY_ERROR, // Closing demonbuddy error message box
		BOT_LAUNCH_CLOSE_DEMONBUDDY, // Close demonbuddy window
		BOT_LAUNCH_CHECK_DEMONBUDDY_CLOSE, // Check if demonbuddy is closed
		BOT_LAUNCH_DEMONBUDDY_CLOSED, // Demonbuddy closed successfully
		BOT_LAUNCH_WAIT_GAME_STABLIZE, // Wait a long time before launch demonbuddy stage-2
		BOT_LAUNCH_SUCCESSFUL, // Task launch succeeded
		BOT_LAUNCH_HIDE_WINDOWS, // Hide windows upon success
		BOT_LAUNCH_ERROR_RETRY, // Launch failed, will retry shortly

		BOT_STATE_LAUNCH, // Launching
		BOT_STATE_MONITOR, // Monitoring
		BOT_STATE_START, // Started
		BOT_STATE_STOP, // Stopped
		BOT_STATE_PAUSE, // Paused
		BOT_STATE_RESUME, // Resumed
};

///////////////////////////////////
// State id requires process id
///////////////////////////////////

enum {  REQ_PID_NONE = 0,
		REQ_PID_DIABLO, // Diablo pid
		REQ_PID_DEMONBUDDY, // Demonbuddy pid
};

///////////////////////////////////
// Bot configuration data struct
///////////////////////////////////

typedef struct tagConfigData
{
	BOOL bDB2x; // Double-launch demonbuddy
	BOOL bNoMin; // Stop diablo from being minimized
	BOOL bReuseWnd; // Reuse processes
	BOOL bTripWire; // Monitor Tripwire events
	UINT nDemonbuddyHung; // Maximum time demonbuddy can be unresponsive
	UINT nDisconnect; // Maximum time diablo can stay disconnected
	UINT nDiabloHung; // Maximum time demonbuddy can be unresponsive
	UINT nJoin; // Maximum time player should join a game
	UINT nDiabloLaunch; // Maximum time for diablo/demonbuddy to start
	UINT nBNetLogin; //  Maximum time for bnet authentication
	UINT nLeave; // Maximum time player can stay out of game
} CONFIGDATA, *LPCONFIGDATA;

typedef const CONFIGDATA* LPCCONFIGDATA;

#endif // __CONSTANTS_H__